/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel  
 * 
 *  Copyright (C) 2010 by Meika Sugimoto
 * 
 *  �嵭����Ԥϡ��ʲ��� (1)���(4) �ξ�狼��Free Software Foundation 
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

#ifndef TOPPERS_V850JG2_H
#define TOPPERS_V850JG2_H

#define DEFAULT_STK_TOP		((STK_T *const)0xFFFF0000)
//#define STACKTOP			0x03FFEFFF

/*
 *  �����㥹�Ȥ�Ԥ��ޥ�������
 */
#ifndef CAST
#define CAST(type, val)		((type)(val))
#endif /* CAST */

/* I/O���ɥ쥹(ɬ�פʤ�ΤΤ�) */

/* �ݡ��� */
#define PCT			(0xFFFFF00A)
#define PCMT		(0xFFFFF02A)
#define PMC3L		(0xFFFFF446)
#define PFC3		(0xFFFFF466)

/* UART */
#define UA0CTL0		(0xFFFFFA00)
#define UA0CTL1		(0xFFFFFA01)
#define UA0CTL2		(0xFFFFFA02)
#define UA0STR		(0xFFFFFA04)

#define UA0TX		(0xFFFFFA07)
#define UA1TX		(0xFFFFFA17)
#define UA2TX		(0xFFFFFA27)

#define UA0RX		(0xFFFFFA06)
#define UA1RX		(0xFFFFFA16)
#define UA2RX		(0xFFFFFA26)

#define UA0STR		(0xFFFFFA04)
#define UA1STR		(0xFFFFFA14)
#define UA2STR		(0xFFFFFA24)

/* ����å� */
#define PRCMD		(0xFFFFF1FC)
#define CKC			(0xFFFFF822)
#define LOCKR 		(0xFFFFF824)
#define VSWC		(0xFFFFF06E)
#define PLLCTL		(0xFFFFF82C)

/* �����å��ɥå� */
#define WDTM2		(0xFFFFF6D0)
#define RCM			(0xFFFFF80C)

/* ������ */
#define TM0CMP0		(0xFFFFF694)
#define TM0CTL0		(0xFFFFF690)

/* ����� */
#define INTF0		(0xFFFFFC00)
#define INTR0		(0xFFFFFC20)
#define INTF3		(0xFFFFFC00)
#define INTR3		(0xFFFFFC20)
#define INTF9H		(0xFFFFFC13)
#define INTR9H		(0xFFFFFC33)

#define IMR_SIZE	(8)
#define IMR0		(0xFFFFF100)
#define IMR1		(0xFFFFF102)
#define IMR2		(0xFFFFF104)
#define IMR3		(0xFFFFF106)
#define IMR4		(0xFFFFF108)
#define IMR5		(0xFFFFF10A)
#define IMR6		(0xFFFFF10C)
#define IMR7		(0xFFFFF10E)


/*
 *	���������쥸���������Ϥ򻻽Ф��뤿��Υޥ���
 *
 *	���������쥸�����ϳ�����ֹ����¤�Ǥ��뤿�ᡤ
 *	�١������ɥ쥹����Υ��ե��åȤǥ��ɥ쥹����뤳�Ȥ��Ǥ��롥
 */

#define INTREG_BASE				(0xFFFFF110)
#define INTREG_ADDRESS(intno)	(INTREG_BASE + ((intno) * 2U))

/*
 *	��������߶�������쥸�����ơ��֥�
 */

#define INT_POLREG_TABLE											\
	{ 0 , 0 , 0 } , 			/* �ꥻ�å����ϤʤΤ�̵�� */		\
	{ INTF0 , INTR0 , 2 } ,		/* NMI */							\
	{ 0, 0 , 0 } , 				/* ��������ߤǽФʤ��Τ�̵�� */	\
	{ 0 , 0 , 0 } , 			/* ��������ߤǽФʤ��Τ�̵�� */	\
	{ 0 , 0 , 0 } , 			/* ��������ߤǽФʤ��Τ�̵�� */	\
	{ 0 , 0 , 0 } , 			/* ��������ߤǽФʤ��Τ�̵�� */	\
	{ 0 , 0 , 0 } , 			/* ��������ߤǽФʤ��Τ�̵�� */	\
	{ 0 , 0 , 0 } , 			/* ��������ߤǽФʤ��Τ�̵�� */	\
	{ INTF0 , INTR0 , 3 } , 	/* INT0 */							\
	{ INTF0 , INTR0 , 4 } , 	/* INT1 */							\
	{ INTF0 , INTR0 , 5 } , 	/* INT2 */							\
	{ INTF0 , INTR0 , 6 } ,		/* INT3 */							\
	{ INTF9H , INTR9H , 5 } , 	/* INT4 */							\
	{ INTF9H , INTR9H , 6 } , 	/* INT5 */							\
	{ INTF9H , INTR9H , 7 } , 	/* INT6 */							\
	{ INTF3 , INTR3 , 1 } 		/* INT7 */

#define SCIF2_BASE			0xe8008000


#define INTNO_SCIF0_BRI		10		/* SCIF0 �֥졼������� */
#define INTNO_SCIF0_ERI		11		/* SCIF0 ���顼����� */
#define INTNO_SCIF0_RXI		12		/* SCIF0 ��������� */
#define INTNO_SCIF0_TXI		13		/* SCIF0 ��������� */
#define INTNO_SCIF1_BRI		14		/* SCIF1 �֥졼������� */
#define INTNO_SCIF1_ERI		15		/* SCIF1 ���顼����� */
#define INTNO_SCIF1_RXI		16		/* SCIF1 ��������� */
#define INTNO_SCIF1_TXI		17		/* SCIF1 ��������� */
#define INTNO_SCIF2_BRI		18		/* SCIF2 �֥졼������� */
#define INTNO_SCIF2_ERI		19		/* SCIF2 ���顼����� */
#define INTNO_SCIF2_RXI		20		/* SCIF2 ��������� */
#define INTNO_SCIF2_TXI		21		/* SCIF2 ��������� */
#define INTNO_SCIF3_BRI		22		/* SCIF3 �֥졼������� */
#define INTNO_SCIF3_ERI		23		/* SCIF3 ���顼����� */
#define INTNO_SCIF3_RXI		24		/* SCIF3 ��������� */
#define INTNO_SCIF3_TXI		25		/* SCIF3 ��������� */
#define INTNO_SCIF4_BRI		26		/* SCIF4 �֥졼������� */
#define INTNO_SCIF4_ERI		27		/* SCIF4 ���顼����� */
#define INTNO_SCIF4_RXI		28		/* SCIF4 ��������� */
#define INTNO_SCIF4_TXI		29		/* SCIF4 ��������� */


#define TNUM_INT			117U
#define TMIN_INTNO			0U
#define TMAX_INTNO			116U

/*************************************************
 * 16�ӥåȥ����ޡ����٥�ȥ�����AA(TAA)
 *************************************************/

#define TAAnChannelNum			UINT_C(8)
#define TAAnCH0					UINT_C(0)
#define TAAnCH1					UINT_C(1)
#define TAAnCH2					UINT_C(2)
#define TAAnCH3					UINT_C(3)
#define TAAnCH4					UINT_C(4)
#define TAAnCH5					UINT_C(5)
#define TAAnCH6					UINT_C(6)
#define TAAnCH7					UINT_C(7)
#endif	/* TOPPERS_V850JG2_H */
