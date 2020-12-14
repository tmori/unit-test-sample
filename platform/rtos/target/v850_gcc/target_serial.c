/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel  
 * 
 *  Copyright (C) 2000-2002 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 * 
 *  Copyright (C) 2005 by Freelines CO.,Ltd
 *
 *  Copyright (C) 2010,2013 by Meika Sugimoto
 * 
 *  �嵭����Ԥϡ��ʲ��� (1)��(4) �ξ�狼��Free Software Foundation 
 *  �ˤ�äƸ�ɽ����Ƥ��� GNU General Public License �� Version 2 �˵�
 *  �Ҥ���Ƥ���������������˸¤ꡤ�ܥ��եȥ��������ܥ��եȥ�����
 *  ����Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ������ۡʰʲ���
 *  ���ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
 *      �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
 *      ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
 *      �ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
 *        �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
 *        ��𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����Ŭ�Ѳ�ǽ����
 *  �ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ����������Ѥˤ��ľ
 *  ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤������Ǥ�����ʤ���
 * 
 */

#include "kernel_impl.h"
#include "target_serial.h"

#define TNUM_SIOP	(8)

/*
 *  ���ꥢ��ݡ��Ȥν�����֥�å�
 */
typedef struct sio_port_initialization_block {
	uint8_t		tx_intno;	/* ��������ߤγ�����ֹ� */
	uint8_t		rx_intno;	/* ��������ߤγ�����ֹ� */
} SIOPINIB;

/*
 *  ���ꥢ��ݡ��Ȥ�����֥�å�
 */
struct sio_port_control_block {
	const SIOPINIB	*p_siopinib;	/* ������֥�å� */
	intptr_t	exinf;				/* ��ĥ���� */
	bool_t		openflag;			/* �����ץ�Ѥߥե饰 */
	int_t		port_id;			/* �ݡ����ֹ�(0��) */
	bool_t		received;			/* ����̵ͭ�ե饰 */
};

SIOPCB siopcb_table[TNUM_SIOP];

/*
 *  SIO ID ��������֥�å��ؤ��Ѵ��ޥ���
 */

#define INDEX_SIO(sioid)	((uint_t)((sioid) - 1))
#define get_siopcb(sioid)	(&(siopcb_table[INDEX_SIO(sioid)]))

/*
 *  ���ꥢ��ݡ��ȤΥϡ��ɥ�������¸��������
 */

#define SERIAL_CLKDIV			(0x01)
#define SERIAL_COMPAREVALUE		(0x82)

/* ���ꥢ���Ϣ�쥸���� */
#define UAnCTL0(x)  (UA0CTL0 + ((x) * 0x10))
#define UAnCTL1(x)  (UA0CTL1 + ((x) * 0x10))
#define UAnCTL2(x)  (UA0CTL2 + ((x) * 0x10))
#define UAnOPT0(x)  (UA0OPT0 + ((x) * 0x10))
#define UAnSTR(x)   (UA0STR  + ((x) * 0x10))
#define UAnRX(x)    (UA0RX   + ((x) * 0x10))
#define UAnTX(x)    (UA0TX   + ((x) * 0x10))
#define UAnRIC(x)	(UA0RIC  + ((x) * 0x10))
#define UAnTIC(x)	(UA0TIC  + ((x) * 0x10))

/*
 *	���ꥢ�������֥�å�
 */
const SIOPINIB siopinib_table[TNUM_SIOP] =
{
	{ 45u , 44u },		/* UARTD0 */
	{ 47u , 48u },		/* UARTD1 */
	{ 74u , 73u },		/* UARTD2 */
	{ 85u , 84u },		/* UARTD3 */
	{ 87u , 86u },		/* UARTD4 */
	{ 95u , 94u },		/* UARTD5 */
	{ 116u , 115u },	/* UARTD6 */
	{ 119u , 118u },	/* UARTD7 */
};


/*
 *  sio_initialize -- ���ꥢ��ݡ��ȥɥ饤�Фν����
 */
void
sio_initialize(intptr_t exinf)
{
	uint_t	i;

	/*
	 *  ���ꥢ��I/O�ݡ��ȴ����֥�å��ν����
	 */
	for (i = 0; i < TNUM_SIOP; i++)
	{
		siopcb_table[i].p_siopinib = &(siopinib_table[i]);
		siopcb_table[i].openflag = false;
		siopcb_table[i].received = false;
	}
}

/*
 *  sio_opn_por -- �ݡ��ȤΥ����ץ�
 */
SIOPCB *
sio_opn_por(ID siopid, intptr_t exinf)
{
	SIOPCB	*siopcb = get_siopcb(siopid);

	if(siopcb->openflag == false)
	{
		siopcb->exinf = exinf;
		siopcb->openflag = true;
		siopcb->port_id = siopid - 1;

		/* UART��ͭ���ˤ��� */
		sil_wrb_mem((void *)UAnCTL0(siopcb->port_id), 0x80);	/* UART enable */

		/* �ܡ��졼��ȯ����ν���� */
		sil_wrb_mem((void *)UAnCTL1(siopcb->port_id), SERIAL_CLKDIV);
		sil_wrb_mem((void *)UAnCTL2(siopcb->port_id), SERIAL_COMPAREVALUE);

		/* �⡼������ */
		sil_wrb_mem((void *)UAnCTL0(siopcb->port_id),
			sil_reb_mem((void *)UAnCTL0(siopcb->port_id)) | 0x12);

		/* ���������� */
		sil_wrb_mem((void *)UAnCTL0(siopcb->port_id),
			sil_reb_mem((void *)UAnCTL0(siopcb->port_id)) | 0x60);

		/* �����������ͭ�� */
		(void)ena_int(siopcb->p_siopinib->tx_intno);
		(void)ena_int(siopcb->p_siopinib->rx_intno);
	}

	return siopcb;
}

/*
 *  sio_snd_chr -- ʸ������
 */
bool_t
sio_snd_chr(SIOPCB *siopcb, char chr)
{
	bool_t	result = false;

	/* ������ǽ�������å� */
	if((sil_reb_mem((void *)UAnSTR(siopcb->port_id)) & 0x80) == 0)
	{
		sil_wrb_mem((void *)UAnTX(siopcb->port_id), chr);
		result = true;
	}

	return result;
}

/*
 *  sio_rcv_chr -- ʸ������
 */
int_t sio_rcv_chr(SIOPCB *siopcb)
{
	int_t chr = -1;

	if(siopcb->received == true)
	{
		chr = (int_t)sil_reb_mem((void *)UAnRX(siopcb->port_id));
		siopcb->port_id = false;
	}

	return chr;
}

/*
 *  sio_ena_cbr -- ���ꥢ�� I/O ����Υ�����Хå��ε���
 */
void
sio_ena_cbr(SIOPCB *siopcb, uint_t cbrtn)
{
	switch (cbrtn) {
		case SIO_RDY_SND:
			ena_int(siopcb->p_siopinib->tx_intno);
			break;
		case SIO_RDY_RCV:
			ena_int(siopcb->p_siopinib->rx_intno);
			break;
		default:
			assert(1);
			break;
	}
}

/*
 *  sio_dis_cbr -- ���ꥢ�� I/O ����Υ�����Хå��ζػ�
 */
void
sio_dis_cbr(SIOPCB *siopcb, uint_t cbrtn)
{
	switch (cbrtn) {
		case SIO_RDY_SND:
			dis_int(siopcb->p_siopinib->tx_intno);
			break;
		case SIO_RDY_RCV:
			dis_int(siopcb->p_siopinib->rx_intno);
			break;
		default:
			assert(1);
			break;
	}
}

/*
 *  sio_cls_por -- �ݡ��ȤΥ�����
 */
void
sio_cls_por(SIOPCB *siopcb)
{
	/* UART����� */
	sil_wrb_mem((void *)UAnCTL0(siopcb->port_id) ,
		(sil_reb_mem((void *)UAnCTL0(siopcb->port_id)) & ~0x80));

	/* ����ߤζػ� */
	dis_int(siopcb->p_siopinib->tx_intno);
	dis_int(siopcb->p_siopinib->rx_intno);

	/* �ե饰������ */
	siopcb->openflag = false;
	siopcb->received = false;
}

void
sio_tx_isr(intptr_t exinf)
{
	SIOPCB	*siopcb = get_siopcb(exinf);

	/* ������Хå���ƤӽФ� */
	sio_irdy_snd(siopcb->exinf);
}

void
sio_rx_isr(intptr_t exinf)
{
	SIOPCB	*siopcb = get_siopcb(exinf);

	/* �����Ѥߥե饰�򥻥å� */
	siopcb->received = true;
	/* ������Хå���ƤӽФ� */
	sio_irdy_rcv(siopcb->exinf);
}

