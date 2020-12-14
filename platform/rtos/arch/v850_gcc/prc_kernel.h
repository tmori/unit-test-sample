/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2010-2011 by Meika Sugimoto
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
 */

/*
 *		kernel.h�Υץ��å���¸����V850�ѡ�
 *
 *  ���Υ��󥯥롼�ɥե�����ϡ�target_kernel.h�ʤޤ��ϡ��������饤��
 *  �롼�ɤ����ե�����ˤΤߤ��饤�󥯥롼�ɤ���롥¾�Υե����뤫��
 *  ľ�ܥ��󥯥롼�ɤ��ƤϤʤ�ʤ���
 */

#ifndef TOPPERS_PRC_KERNEL_H
#define TOPPERS_PRC_KERNEL_H

/*
 *  �ץ��å�����ǥ��ݡ��Ȥ��뵡ǽ
 */
#define TOPPERS_TARGET_SUPPORT_DIS_INT		/* dis_int�򥵥ݡ��Ȥ��� */
#define TOPPERS_TARGET_SUPPORT_ENA_INT		/* ena_int�򥵥ݡ��Ȥ��� */


/*
 *  �����ͥ�����γ����ͥ���٤��ϰ�
 *
 *  TMIN_INTPRI��������ѹ����뤳�Ȥǡ��ɤΥ�٥����⤤�����ͥ����
 *  ����Ĥ�Τ򥫡��ͥ�������γ���ߤȤ��뤫���ѹ��Ǥ��롥
 *
 */
#ifndef TMIN_INTPRI
#define TMIN_INTPRI		(-7)		/* �����ͥ���٤κǾ��͡ʺǹ��͡�*/
#endif /* TMIN_INTPRI */

#define TMAX_INTPRI		(0)		/* �����ͥ���٤κ����͡ʺ����͡�*/

/*
 *	��������ߤ�°��
 */
#define TA_POSEDGE		(TA_EDGE)
#define TA_NEGEDGE		UINT_C(0x00000004)
#define TA_BOTHEDGE		UINT_C(0x00000008)

/*
 *  ���ݡ��Ȥ��뵡ǽ�����
 */
#define TOPPERS_SUPPORT_DIS_INT			/* dis_int�򥵥ݡ��Ȥ��� */
#define TOPPERS_SUPPORT_ENA_INT			/* ena_int�򥵥ݡ��Ȥ��� */

/*
 *  ���ݡ��Ȥ��륪�֥�������°�����
 */

#define TARGET_INTATR       ((TA_POSEDGE | TA_NEGEDGE | TA_BOTHEDGE) | TA_NONKERNEL)
#define TARGET_INHATR       (TA_NONKERNEL)
#define TARGET_TSKATR       (0)
#define TARGET_ISRATR       (TA_NONKERNEL)
#define TARGET_EXCATR       (0)
#define TARGET_MIN_STKSZ    (64)
#define CHECK_STKSZ_ALIGN   (4)

/* �����å����Ƥλ��� */
#define CHECK_FUNC_NONNULL  (true)
#define CHECK_STACK_NONNULL (true)
#define CHECK_MPF_NONNULL   (true)

#define CHECK_FUNC_ALIGN    (2)
#define CHECK_STACK_ALIGN   (4)
#define CHECK_MPF_ALIGN     (4)
#define CHECK_MB_ALIGN      (4)

#endif /* TOPPERS_PRC_KERNEL_H */
