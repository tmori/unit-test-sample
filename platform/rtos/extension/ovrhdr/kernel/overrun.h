/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
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
 *  @(#) $Id: overrun.h 1717 2010-01-31 11:41:03Z ertl-hiro $
 */

/*
 *		�����Х��ϥ�ɥ鵡ǽ
 */

#ifndef TOPPERS_OVERRUN_H
#define TOPPERS_OVERRUN_H

#ifdef TOPPERS_SUPPORT_OVRHDR
#include "target_timer.h"

/*
 *  �����Х��ϥ�ɥ������֥�å�
 */
typedef struct overrun_handler_initialization_block {
	ATR			ovratr;			/* �����Х��ϥ�ɥ�°�� */
	OVRHDR		ovrhdr;			/* �����Х��ϥ�ɥ�ε�ư���� */
} OVRINIB;

/*
 *  �����Х��ϥ�ɥ������֥�å��Υ��ꥢ��kernel_cfg.c��
 */
extern const OVRINIB	ovrinib;

/*
 *  �����Х�󥿥��ޤ�ư���椫�򼨤��ե饰
 */
extern bool_t	ovrtimer_flag;

/*
 *  �����Х��ϥ�ɥ鵡ǽ�ν����
 */
extern void	initialize_overrun(void);

/*
 *  �����Х��ϥ�ɥ��ѥ����ޤ�ư���
 */
extern void	ovrtimer_start(void);

/*
 *  �����Х��ϥ�ɥ��ѥ����ޤ����
 */
#ifndef OMIT_OVRTIMER_STOP

extern void	ovrtimer_stop(void);

#else /* OMIT_OVRTIMER_STOP */

Inline void
ovrtimer_stop(void)
{
	if (p_runtsk->leftotm > 0U) {
		p_runtsk->leftotm = target_ovrtimer_stop();
		ovrtimer_flag = false;
	}
}

#endif /* OMIT_OVRTIMER_STOP */

/*
 *  �����Х��ϥ�ɥ鵯ư�롼����
 */
extern void	call_ovrhdr(void);

#endif /* TOPPERS_SUPPORT_OVRHDR */
#endif /* TOPPERS_OVERRUN_H */
