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
 *  @(#) $Id: overrun.c 1902 2010-08-17 22:38:52Z ertl-hiro $
 */

/*
 *		�����Х��ϥ�ɥ鵡ǽ
 */

#include "kernel_impl.h"
#include "check.h"
#include "task.h"
#include "overrun.h"

#ifdef TOPPERS_SUPPORT_OVRHDR
#include "target_timer.h"

/*
 *  �ȥ졼�����ޥ���Υǥե�������
 */
#ifndef LOG_OVR_ENTER
#define LOG_OVR_ENTER(p_runtsk)
#endif /* LOG_OVR_ENTER */

#ifndef LOG_OVR_LEAVE
#define LOG_OVR_LEAVE(p_runtsk)
#endif /* LOG_OVR_LEAVE */

#ifndef LOG_STA_OVR_ENTER
#define LOG_STA_OVR_ENTER(tskid, ovrtim)
#endif /* LOG_STA_OVR_ENTER */

#ifndef LOG_STA_OVR_LEAVE
#define LOG_STA_OVR_LEAVE(ercd)
#endif /* LOG_STA_OVR_LEAVE */

#ifndef LOG_ISTA_OVR_ENTER
#define LOG_ISTA_OVR_ENTER(tskid, ovrtim)
#endif /* LOG_ISTA_OVR_ENTER */

#ifndef LOG_ISTA_OVR_LEAVE
#define LOG_ISTA_OVR_LEAVE(ercd)
#endif /* LOG_ISTA_OVR_LEAVE */

#ifndef LOG_ISTP_OVR_ENTER
#define LOG_ISTP_OVR_ENTER(tskid)
#endif /* LOG_ISTP_OVR_ENTER */

#ifndef LOG_ISTP_OVR_LEAVE
#define LOG_ISTP_OVR_LEAVE(ercd)
#endif /* LOG_ISTP_OVR_LEAVE */

#ifndef LOG_STP_OVR_ENTER
#define LOG_STP_OVR_ENTER(tskid)
#endif /* LOG_STP_OVR_ENTER */

#ifndef LOG_STP_OVR_LEAVE
#define LOG_STP_OVR_LEAVE(ercd)
#endif /* LOG_STP_OVR_LEAVE */

#ifndef LOG_REF_OVR_ENTER
#define LOG_REF_OVR_ENTER(tskid, pk_rovr)
#endif /* LOG_REF_OVR_ENTER */

#ifndef LOG_REF_OVR_LEAVE
#define LOG_REF_OVR_LEAVE(ercd, pk_rovr)
#endif /* LOG_REF_OVR_LEAVE */

#ifdef TOPPERS_ovrini

/*
 *  �����Х�󥿥��ޤ�ư���椫�򼨤��ե饰
 */
bool_t	ovrtimer_flag;

/*
 *  �����Х��ϥ�ɥ鵡ǽ�ν����
 */
void
initialize_overrun(void)
{
	ovrtimer_flag = false;
}

#endif /* TOPPERS_ovrini */

/*
 *  �����Х��ϥ�ɥ��ѥ����ޤ�ư���
 */
#ifdef TOPPERS_ovrsta
#ifndef OMIT_OVRTIMER_START

void
ovrtimer_start(void)
{
	if (p_runtsk->leftotm > 0U) {
		target_ovrtimer_start(p_runtsk->leftotm);
		ovrtimer_flag = true;
	}
}

#endif /* OMIT_OVRTIMER_START */
#endif /* TOPPERS_ovrsta */

/*
 *  �����Х��ϥ�ɥ��ѥ����ޤ����
 */
#ifdef TOPPERS_ovrstp
#ifndef OMIT_OVRTIMER_STOP

void
ovrtimer_stop(void)
{
	if (ovrtimer_flag) {
		assert(p_runtsk->leftotm > 0U);
		p_runtsk->leftotm = target_ovrtimer_stop();
		ovrtimer_flag = false;
	}
}

#endif /* OMIT_OVRTIMER_STOP */
#endif /* TOPPERS_ovrstp */

/*
 *  �����Х��ϥ�ɥ��ư���
 */
#ifdef TOPPERS_sta_ovr

ER
sta_ovr(ID tskid, OVRTIM ovrtim)
{
	TCB		*p_tcb;
	ER		ercd;

	LOG_STA_OVR_ENTER(tskid, ovrtim);
	CHECK_TSKCTX_UNL();
	CHECK_OBJ(ovrinib.ovrhdr != NULL);
	CHECK_TSKID_SELF(tskid);
	CHECK_PAR(0U < ovrtim && ovrtim <= TMAX_OVRTIM);
	p_tcb = get_tcb_self(tskid);

	t_lock_cpu();
	if (p_tcb == p_runtsk) {
		if (p_tcb->leftotm > 0U) {
			(void) target_ovrtimer_stop();
		}
		target_ovrtimer_start(ovrtim);
		ovrtimer_flag = true;
	}
	p_tcb->leftotm = ovrtim;
	ercd = E_OK;
	t_unlock_cpu();

  error_exit:
	LOG_STA_OVR_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_sta_ovr */

/*
 *  �����Х��ϥ�ɥ��ư��ϡ��󥿥�������ƥ������ѡ�
 */
#ifdef TOPPERS_ista_ovr

ER
ista_ovr(ID tskid, OVRTIM ovrtim)
{
	TCB		*p_tcb;
	ER		ercd;

	LOG_ISTA_OVR_ENTER(tskid, ovrtim);
	CHECK_INTCTX_UNL();
	CHECK_OBJ(ovrinib.ovrhdr != NULL);
	CHECK_TSKID(tskid);
	CHECK_PAR(0U < ovrtim && ovrtim <= TMAX_OVRTIM);
	p_tcb = get_tcb(tskid);

	i_lock_cpu();
	p_tcb->leftotm = ovrtim;
	ercd = E_OK;
	i_unlock_cpu();

  error_exit:
	LOG_ISTA_OVR_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_ista_ovr */

/*
 *  �����Х��ϥ�ɥ��ư�����
 */
#ifdef TOPPERS_stp_ovr

ER
stp_ovr(ID tskid)
{
	TCB		*p_tcb;
	ER		ercd;

	LOG_STP_OVR_ENTER(tskid);
	CHECK_TSKCTX_UNL();
	CHECK_OBJ(ovrinib.ovrhdr != NULL);
	CHECK_TSKID_SELF(tskid);
	p_tcb = get_tcb_self(tskid);

	t_lock_cpu();
	if (p_tcb->leftotm > 0U) {
		if (p_tcb == p_runtsk) {
			(void) target_ovrtimer_stop();
			ovrtimer_flag = false;
		}
		p_tcb->leftotm = 0U;
	}
	ercd = E_OK;
	t_unlock_cpu();

  error_exit:
	LOG_STP_OVR_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_stp_ovr */

/*
 *  �����Х��ϥ�ɥ��ư����ߡ��󥿥�������ƥ������ѡ�
 */
#ifdef TOPPERS_istp_ovr

ER
istp_ovr(ID tskid)
{
	TCB		*p_tcb;
	ER		ercd;

	LOG_ISTP_OVR_ENTER(tskid);
	CHECK_INTCTX_UNL();
	CHECK_OBJ(ovrinib.ovrhdr != NULL);
	CHECK_TSKID(tskid);
	p_tcb = get_tcb(tskid);

	i_lock_cpu();
	p_tcb->leftotm = 0U;
	ercd = E_OK;
	i_unlock_cpu();

  error_exit:
	LOG_ISTP_OVR_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_istp_ovr */

/*
 *  �����Х��ϥ�ɥ�ξ��ֻ���
 */
#ifdef TOPPERS_ref_ovr

ER
ref_ovr(ID tskid, T_ROVR *pk_rovr)
{
	TCB		*p_tcb;
	ER		ercd;
    
	LOG_REF_OVR_ENTER(tskid, pk_rovr);
	CHECK_TSKCTX_UNL();
	CHECK_OBJ(ovrinib.ovrhdr != NULL);
	CHECK_TSKID_SELF(tskid);
	p_tcb = get_tcb_self(tskid);

	t_lock_cpu();
	if (p_tcb->leftotm > 0U) {
		pk_rovr->ovrstat = TOVR_STA;
		if (p_tcb == p_runtsk) {
			pk_rovr->leftotm = target_ovrtimer_get_current();
		}
		else {
			pk_rovr->leftotm = p_tcb->leftotm;
		}
	}
	else {
		pk_rovr->ovrstat = TOVR_STP;
	}
	ercd = E_OK;
	t_unlock_cpu();

  error_exit:
	LOG_REF_OVR_LEAVE(ercd, pk_rovr);
	return(ercd);
}

#endif /* TOPPERS_ref_ovr */

/*
 *  �����Х��ϥ�ɥ鵯ư�롼����
 */
#ifdef TOPPERS_ovrcal

void
call_ovrhdr(void)
{
	PRI		saved_ipm;

	assert(sense_context());
	assert(!i_sense_lock());
	assert(ovrinib.ovrhdr != NULL);

	p_runtsk->leftotm = 0U;
	saved_ipm = i_get_ipm();

	LOG_OVR_ENTER(p_runtsk);
	(*((OVRHDR)(ovrinib.ovrhdr)))(TSKID(p_runtsk), p_runtsk->p_tinib->exinf);
	LOG_OVR_LEAVE(p_runtsk);

	if (i_sense_lock()) {
		i_unlock_cpu();
	}
	i_set_ipm(saved_ipm);
}

#endif /* TOPPERS_ovrcal */
#endif /* TOPPERS_SUPPORT_OVRHDR */
