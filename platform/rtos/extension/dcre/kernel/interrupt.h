/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2010 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 * 
 *  �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
 *  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
 *  �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
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
 *      �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
 *      ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
 *      ���դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
 *  ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
 *  �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
 *  ����Ǥ�����ʤ���
 * 
 *  @(#) $Id: interrupt.h 1966 2010-11-20 07:23:56Z ertl-hiro $
 */

/*
 *		����ߴ�����ǽ
 */

#ifndef TOPPERS_INTERRUPT_H
#define TOPPERS_INTERRUPT_H

/*
 *  ����ߥ����ӥ��롼���������֥�å�
 */
typedef struct isr_initialization_block {
	ATR			isratr;			/* ����ߥ����ӥ��롼����°�� */
	intptr_t	exinf;			/* ����ߥ����ӥ��롼����γ�ĥ���� */
	INTNO		intno;			/* ����ߥ����ӥ��롼�������Ͽ���������ֹ� */
	QUEUE		*p_isr_queue;	/* ��Ͽ�����ߥ����ӥ��롼���󥭥塼������ */
	ISR			isr;			/* ����ߥ����ӥ��롼�������Ƭ���� */
	PRI			isrpri;			/* ����ߥ����ӥ��롼����ͥ���� */
} ISRINIB;

/*
 *  ����ߥ����ӥ��롼��������֥�å�
 */
typedef struct isr_control_block {
	QUEUE		isr_queue;		/* ����ߥ����ӥ��롼����ƽФ����塼 */
	const ISRINIB *p_isrinib;	/* ������֥�å��ؤΥݥ��� */
} ISRCB;

/*
 *  ����ߥ����ӥ��롼����ƽФ����塼�򸡺����뤿��Υǡ�����¤
 */
typedef struct {
	INTNO		intno;			/* ������ֹ� */
	QUEUE		*p_isr_queue;	/* ����ߥ����ӥ��롼����ƽФ����塼 */
} ISR_ENTRY;

/*
 *  ����ߥ����ӥ��롼���󥭥塼�Υ���ȥ����kernel_cfg.c��
 */
extern const uint_t tnum_isr_queue;

/*
 *  ����ߥ����ӥ��롼���󥭥塼�ꥹ�ȡ�kernel_cfg.c��
 */
extern const ISR_ENTRY isr_queue_list[];

/*
 *  ����ߥ����ӥ��롼���󥭥塼�Υ��ꥢ��kernel_cfg.c��
 */
extern QUEUE isr_queue_table[];

/*
 *  ���Ѥ��Ƥ��ʤ�����ߥ����ӥ��롼��������֥�å��Υꥹ��
 */
extern QUEUE	free_isrcb;

/*
 *  ����ߥ����ӥ��롼����ID�κ����͡�kernel_cfg.c��
 *
 *  ��Ū��������������ߥ����ӥ��롼�����ID�ֹ������ʤ����ᡤ
 *  tmax_isrid��ưŪ��������������ߥ����ӥ��롼�����ID�ֹ�κ�����
 *  �Ǥ��롥��Ū��������������ߥ����ӥ��롼����ο��ϡ�tnum_sisr����
 *  �����롥
 */
extern const ID		tmax_isrid;
extern const uint_t	tnum_sisr;

/*
 *  ����ߥ����ӥ��롼���������֥�å��Υ��ꥢ��kernel_cfg.c��
 */
extern const ISRINIB	sisrinib_table[];
extern ISRINIB			aisrinib_table[];

/*
 *  ����ߥ����ӥ��롼��������֥�å��Υ��ꥢ��kernel_cfg.c��
 */
extern ISRCB	isrcb_table[];

/*
 *  ����ߥ����ӥ��롼��������֥�å��������ߥ����ӥ��롼����ID���
 *  ��Ф�����Υޥ���
 */
#define	ISRID(p_isrcb)	((ID)(((p_isrcb) - isrcb_table) \
										- tnum_sisr + TMIN_ISRID))

/*
 *  ����ߥ����ӥ��롼����ǽ�ν����
 */
extern void initialize_isr(void);

/*
 *  ����ߥ����ӥ��롼����θƽФ�
 */
extern void call_isr(QUEUE *p_isr_queue);

#ifndef OMIT_INITIALIZE_INTERRUPT

/*
 *  ����ߥϥ�ɥ������֥�å�
 */
typedef struct interrupt_handler_initialization_block {
	INHNO		inhno;			/* ����ߥϥ�ɥ��ֹ� */
	ATR			inhatr;			/* ����ߥϥ�ɥ�°�� */
	FP			int_entry;		/* ����ߥϥ�ɥ�ν��������������� */
} INHINIB;

/*
 *  ������׵�饤�������֥�å�
 */
typedef struct interrupt_request_initialization_block {
	INTNO		intno;			/* ������ֹ� */
	ATR			intatr;			/* �����°�� */
	PRI			intpri;			/* �����ͥ���� */
} INTINIB;

/*
 *  ����ߥϥ�ɥ��ֹ�ο���kernel_cfg.c��
 */
extern const uint_t	tnum_inhno;

/*
 *  ����ߥϥ�ɥ������֥�å��Υ��ꥢ��kernel_cfg.c��
 */
extern const INHINIB	inhinib_table[];

/*
 *  ������׵�饤��ο���kernel_cfg.c��
 */
extern const uint_t	tnum_intno;

/*
 *  ������׵�饤�������֥�å��Υ��ꥢ��kernel_cfg.c��
 */
extern const INTINIB	intinib_table[];

#endif /* OMIT_INITIALIZE_INTERRUPT */

/*
 *  ����ߴ�����ǽ�ν����
 */
extern void	initialize_interrupt(void);

#endif /* TOPPERS_INTERRUPT_H */
