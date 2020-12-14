/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2005-2011 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: mutex.c 2136 2011-06-26 03:35:48Z ertl-hiro $
 */

/*
 *		�ߥ塼�ƥå�����ǽ
 */

#include "kernel_impl.h"
#include "check.h"
#include "task.h"
#include "wait.h"
#include "mutex.h"

/*
 *  �ȥ졼�����ޥ���Υǥե�������
 */
#ifndef LOG_LOC_MTX_ENTER
#define LOG_LOC_MTX_ENTER(mtxid)
#endif /* LOG_LOC_MTX_ENTER */

#ifndef LOG_LOC_MTX_LEAVE
#define LOG_LOC_MTX_LEAVE(ercd)
#endif /* LOG_LOC_MTX_LEAVE */

#ifndef LOG_PLOC_MTX_ENTER
#define LOG_PLOC_MTX_ENTER(mtxid)
#endif /* LOG_PLOC_MTX_ENTER */

#ifndef LOG_PLOC_MTX_LEAVE
#define LOG_PLOC_MTX_LEAVE(ercd)
#endif /* LOG_PLOC_MTX_LEAVE */

#ifndef LOG_TLOC_MTX_ENTER
#define LOG_TLOC_MTX_ENTER(mtxid, tmout)
#endif /* LOG_TLOC_MTX_ENTER */

#ifndef LOG_TLOC_MTX_LEAVE
#define LOG_TLOC_MTX_LEAVE(ercd)
#endif /* LOG_TLOC_MTX_LEAVE */

#ifndef LOG_UNL_MTX_ENTER
#define LOG_UNL_MTX_ENTER(mtxid)
#endif /* LOG_UNL_MTX_ENTER */

#ifndef LOG_UNL_MTX_LEAVE
#define LOG_UNL_MTX_LEAVE(ercd)
#endif /* LOG_UNL_MTX_LEAVE */

#ifndef LOG_INI_MTX_ENTER
#define LOG_INI_MTX_ENTER(mtxid)
#endif /* LOG_INI_MTX_ENTER */

#ifndef LOG_INI_MTX_LEAVE
#define LOG_INI_MTX_LEAVE(ercd)
#endif /* LOG_INI_MTX_LEAVE */

#ifndef LOG_REF_MTX_ENTER
#define LOG_REF_MTX_ENTER(mtxid, pk_rmtx)
#endif /* LOG_REF_MTX_ENTER */

#ifndef LOG_REF_MTX_LEAVE
#define LOG_REF_MTX_LEAVE(ercd, pk_rmtx)
#endif /* LOG_REF_MTX_LEAVE */

/*
 *  �ߥ塼�ƥå����ο�
 */
#define tnum_mtx	((uint_t)(tmax_mtxid - TMIN_MTXID + 1))

/*
 *  �ߥ塼�ƥå���ID����ߥ塼�ƥå��������֥�å�����Ф�����Υޥ���
 */
#define INDEX_MTX(mtxid)	((uint_t)((mtxid) - TMIN_MTXID))
#define get_mtxcb(mtxid)	(&(mtxcb_table[INDEX_MTX(mtxid)]))

/*
 *  �ߥ塼�ƥå��������֥�å����mutex_queue�ؤΥݥ��󥿤��顤�ߥ塼�ƥ�
 *  ���������֥�å��ؤΥݥ��󥿤���Ф�����Υޥ���
 */
#define MTXCB_QUEUE(p_queue) \
			((MTXCB *)(((char *) p_queue) - offsetof(MTXCB, mutex_queue)))

/*
 *  �ߥ塼�ƥå����Υץ�ȥ����Ƚ�Ǥ���ޥ���
 */
#define MTXPROTO_MASK			0x03U
#define MTXPROTO(p_mtxcb)		((p_mtxcb)->p_mtxinib->mtxatr & MTXPROTO_MASK)
#define MTX_CEILING(p_mtxcb)	(MTXPROTO(p_mtxcb) == TA_CEILING)

/*
 *  �եå��롼����ƽФ��Ѥ��ѿ�
 */
#ifdef TOPPERS_mtxhook

bool_t	(*mtxhook_check_ceilpri)(TCB *p_tcb, uint_t bpriority) = NULL;
bool_t	(*mtxhook_scan_ceilmtx)(TCB *p_tcb) = NULL;
bool_t	(*mtxhook_release_all)(TCB *p_tcb) = NULL;

#endif /* TOPPERS_mtxhook */

/* 
 *  �ߥ塼�ƥå�����ǽ�ν����
 */
#ifdef TOPPERS_mtxini

void
initialize_mutex(void)
{
	uint_t	i;
	MTXCB	*p_mtxcb;

	mtxhook_check_ceilpri = mutex_check_ceilpri;
	mtxhook_scan_ceilmtx = mutex_scan_ceilmtx;
	mtxhook_release_all = mutex_release_all;

	for (i = 0; i < tnum_mtx; i++) {
		p_mtxcb = &(mtxcb_table[i]);
		queue_initialize(&(p_mtxcb->wait_queue));
		p_mtxcb->p_mtxinib = &(mtxinib_table[i]);
		p_mtxcb->p_loctsk = NULL;
	}
}

#endif /* TOPPERS_mtxini */

/* 
 *  ���ͥ���ٰ�ȿ�Υ����å�
 */
#ifdef TOPPERS_mtxchk

bool_t
mutex_check_ceilpri(TCB *p_tcb, uint_t bpriority)
{
	QUEUE	*p_queue;
	MTXCB	*p_mtxcb;

	/*
	 *  ����������å����Ƥ���ͥ���پ�¥ߥ塼�ƥå�������ǡ����ͥ��
	 *  �٤�bpriority�����㤤��Τ�����С�false���֤���
	 */
	p_queue = p_tcb->mutex_queue.p_next;
	while (p_queue != &(p_tcb->mutex_queue)) {
		p_mtxcb = MTXCB_QUEUE(p_queue);
		if (MTX_CEILING(p_mtxcb) && bpriority < p_mtxcb->p_mtxinib->ceilpri) {
			return(false);
		}
		p_queue = p_queue->p_next;
	}

	/*
	 *  ��������ͥ���پ�¥ߥ塼�ƥå����Υ�å����ԤäƤ�����ˡ���
	 *  �ξ��ͥ���٤�bpriority�����㤯����С�false���֤���
	 */
	if (TSTAT_WAIT_MTX(p_tcb->tstat)) {
		p_mtxcb = ((WINFO_MTX *)(p_tcb->p_winfo))->p_mtxcb;
		if (MTX_CEILING(p_mtxcb) && bpriority < p_mtxcb->p_mtxinib->ceilpri) {
			return(false);
		}
	}

	/*
	 *  ������ξ��ˤ����ƤϤޤ�ʤ����true���֤���
	 */
	return(true);
}

#endif /* TOPPERS_mtxchk */

/* 
 *  ͥ���پ�¥ߥ塼�ƥå������å����Ƥ��뤫�Υ����å�
 */
#ifdef TOPPERS_mtxscan

bool_t
mutex_scan_ceilmtx(TCB *p_tcb)
{
	QUEUE	*p_queue;
	MTXCB	*p_mtxcb;

	p_queue = p_tcb->mutex_queue.p_next;
	while (p_queue != &(p_tcb->mutex_queue)) {
		p_mtxcb = MTXCB_QUEUE(p_queue);
		if (MTX_CEILING(p_mtxcb)) {
			return(true);
		}
		p_queue = p_queue->p_next;
	}
	return(false);
}

#endif /* TOPPERS_mtxscan */

/* 
 *  �������θ���ͥ���٤η׻�
 */
#ifdef TOPPERS_mtxcalc

uint_t
mutex_calc_priority(TCB *p_tcb)
{
	uint_t	priority;
	QUEUE	*p_queue;
	MTXCB	*p_mtxcb;

	priority = p_tcb->bpriority;
	p_queue = p_tcb->mutex_queue.p_next;
	while (p_queue != &(p_tcb->mutex_queue)) {
		p_mtxcb = MTXCB_QUEUE(p_queue);
		if (MTX_CEILING(p_mtxcb) && p_mtxcb->p_mtxinib->ceilpri < priority) {
			priority = p_mtxcb->p_mtxinib->ceilpri;
		}
		p_queue = p_queue->p_next;
	}
	return(priority);
}

#endif /* TOPPERS_mtxcalc */

/*
 *  ����ͥ���٤��夬��ʤޤ���������˾��θ���ͥ�����ѹ�����
 */
Inline bool_t
mutex_raise_priority(TCB *p_tcb, uint_t newpri)
{
	if (newpri < p_tcb->priority) {
		return(change_priority(p_tcb, newpri, true));
	}
	return(false);
}

/*
 *  ����ͥ���٤�������ʤޤ��ϸ���˾��θ���ͥ�����ѹ�����
 */
Inline bool_t
mutex_drop_priority(TCB *p_tcb, uint_t oldpri)
{
	uint_t	newpri;

	if (oldpri == p_tcb->priority) {
		newpri = mutex_calc_priority(p_tcb);
		if (newpri != p_tcb->priority) {
			return(change_priority(p_tcb, newpri, true));
		}
	}
	return(false);
}

/*
 *  �ߥ塼�ƥå������å��������ν���
 */
Inline bool_t
mutex_acquire(TCB *p_loctsk, MTXCB *p_mtxcb)
{
	p_mtxcb->p_loctsk = p_loctsk;
	queue_insert_prev(&(p_loctsk->mutex_queue), &(p_mtxcb->mutex_queue));
	if (MTX_CEILING(p_mtxcb)) {
		return(mutex_raise_priority(p_loctsk, p_mtxcb->p_mtxinib->ceilpri));
	}
	return(false);
}

/*
 *  �ߥ塼�ƥå����Υ�å����
 */
#ifdef TOPPERS_mtxrel

bool_t
mutex_release(MTXCB *p_mtxcb)
{
	TCB		*p_tcb;

	if (queue_empty(&(p_mtxcb->wait_queue))) {
		p_mtxcb->p_loctsk = NULL;
		return(false);
	}
	else {
		/*
		 *  �ߥ塼�ƥå����Ԥ����塼����Ƭ��������p_tcb�ˤˡ��ߥ塼�ƥ�
		 *  �������å������롥
		 */
		p_tcb = (TCB *) queue_delete_next(&(p_mtxcb->wait_queue));
		wait_dequeue_tmevtb(p_tcb);
		p_tcb->p_winfo->wercd = E_OK;

		p_mtxcb->p_loctsk = p_tcb;
		queue_insert_prev(&(p_tcb->mutex_queue), &(p_mtxcb->mutex_queue));
		if (MTX_CEILING(p_mtxcb)) {
			if (p_mtxcb->p_mtxinib->ceilpri < p_tcb->priority) {
				p_tcb->priority = p_mtxcb->p_mtxinib->ceilpri;
			}
		}
		return(make_non_wait(p_tcb));
	}
}

#endif /* TOPPERS_mtxrel */

/*
 *  ����������å����Ƥ��뤹�٤ƤΥߥ塼�ƥå����Υ�å����
 */
#ifdef TOPPERS_mtxrela

bool_t
mutex_release_all(TCB *p_tcb)
{
	MTXCB	*p_mtxcb;
	bool_t	dspreq = false;

	while (!queue_empty(&(p_tcb->mutex_queue))) {
		p_mtxcb = MTXCB_QUEUE(p_tcb->mutex_queue.p_next);
		queue_delete(&(p_mtxcb->mutex_queue));
		if (mutex_release(p_mtxcb)) {
			dspreq = true;
		}
	}
	return(dspreq);
}

#endif /* TOPPERS_mtxrela */

/*
 *  �ߥ塼�ƥå����Υ�å�
 */
#ifdef TOPPERS_loc_mtx

ER
loc_mtx(ID mtxid)
{
	MTXCB	*p_mtxcb;
	WINFO_MTX winfo_mtx;
	ER		ercd;

	LOG_LOC_MTX_ENTER(mtxid);
	CHECK_DISPATCH();
	CHECK_MTXID(mtxid);
	p_mtxcb = get_mtxcb(mtxid);

	t_lock_cpu();
	if (MTX_CEILING(p_mtxcb)
				&& p_runtsk->bpriority < p_mtxcb->p_mtxinib->ceilpri) {
		ercd = E_ILUSE;
	}
	else if (p_mtxcb->p_loctsk == NULL) {
		(void) mutex_acquire(p_runtsk, p_mtxcb);
		/*
		 *  ͥ���پ�¥ߥ塼�ƥå������å�������硤p_runtsk��ͥ����
		 *  ���夬���ǽ�������뤬���ǥ����ѥå���ɬ�פˤʤ뤳�ȤϤʤ���
		 */
		assert(!(p_runtsk != p_schedtsk && dspflg));
		ercd = E_OK;
	}
	else if (p_mtxcb->p_loctsk == p_runtsk) {
		ercd = E_ILUSE;
	}
	else {
		p_runtsk->tstat = (TS_WAITING | TS_WAIT_MTX);
		wobj_make_wait((WOBJCB *) p_mtxcb, (WINFO_WOBJ *) &winfo_mtx);
		dispatch();
		ercd = winfo_mtx.winfo.wercd;
	}
	t_unlock_cpu();

  error_exit:
	LOG_LOC_MTX_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_loc_mtx */

/*
 *  �ߥ塼�ƥå����Υ�å��ʥݡ���󥰡�
 */
#ifdef TOPPERS_ploc_mtx

ER
ploc_mtx(ID mtxid)
{
	MTXCB	*p_mtxcb;
	ER		ercd;

	LOG_PLOC_MTX_ENTER(mtxid);
	CHECK_TSKCTX_UNL();
	CHECK_MTXID(mtxid);
	p_mtxcb = get_mtxcb(mtxid);

	t_lock_cpu();
	if (MTX_CEILING(p_mtxcb)
				&& p_runtsk->bpriority < p_mtxcb->p_mtxinib->ceilpri) {
		ercd = E_ILUSE;
	}
	else if (p_mtxcb->p_loctsk == NULL) {
		(void) mutex_acquire(p_runtsk, p_mtxcb);
		/*
		 *  ͥ���پ�¥ߥ塼�ƥå������å�������硤p_runtsk��ͥ����
		 *  ���夬���ǽ�������뤬���ǥ����ѥå���ɬ�פˤʤ뤳�ȤϤʤ���
		 */
		assert(!(p_runtsk != p_schedtsk && dspflg));
		ercd = E_OK;
	}
	else if (p_mtxcb->p_loctsk == p_runtsk) {
		ercd = E_ILUSE;
	}
	else {
		ercd = E_TMOUT;
	}
	t_unlock_cpu();

  error_exit:
	LOG_PLOC_MTX_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_ploc_mtx */

/*
 *  �ߥ塼�ƥå����Υ�å��ʥ����ॢ���Ȥ����
 */
#ifdef TOPPERS_tloc_mtx

ER
tloc_mtx(ID mtxid, TMO tmout)
{
	MTXCB	*p_mtxcb;
	WINFO_MTX winfo_mtx;
	TMEVTB	tmevtb;
	ER		ercd;

	LOG_TLOC_MTX_ENTER(mtxid, tmout);
	CHECK_DISPATCH();
	CHECK_MTXID(mtxid);
	CHECK_TMOUT(tmout);
	p_mtxcb = get_mtxcb(mtxid);

	t_lock_cpu();
	if (MTX_CEILING(p_mtxcb)
				&& p_runtsk->bpriority < p_mtxcb->p_mtxinib->ceilpri) {
		ercd = E_ILUSE;
	}
	else if (p_mtxcb->p_loctsk == NULL) {
		(void) mutex_acquire(p_runtsk, p_mtxcb);
		/*
		 *  ͥ���پ�¥ߥ塼�ƥå������å�������硤p_runtsk��ͥ����
		 *  ���夬���ǽ�������뤬���ǥ����ѥå���ɬ�פˤʤ뤳�ȤϤʤ���
		 */
		assert(!(p_runtsk != p_schedtsk && dspflg));
		ercd = E_OK;
	}
	else if (p_mtxcb->p_loctsk == p_runtsk) {
		ercd = E_ILUSE;
	}
	else if (tmout == TMO_POL) {
		ercd = E_TMOUT;
	}
	else {
		p_runtsk->tstat = (TS_WAITING | TS_WAIT_MTX);
		wobj_make_wait_tmout((WOBJCB *) p_mtxcb, (WINFO_WOBJ *) &winfo_mtx,
														&tmevtb, tmout);
		dispatch();
		ercd = winfo_mtx.winfo.wercd;
	}
	t_unlock_cpu();

  error_exit:
	LOG_TLOC_MTX_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_tloc_mtx */

/*
 *  �ߥ塼�ƥå����Υ�å����
 */
#ifdef TOPPERS_unl_mtx

ER
unl_mtx(ID mtxid)
{
	MTXCB	*p_mtxcb;
	bool_t	dspreq = false;
	ER		ercd;
    
	LOG_UNL_MTX_ENTER(mtxid);
	CHECK_TSKCTX_UNL();
	CHECK_MTXID(mtxid);
	p_mtxcb = get_mtxcb(mtxid);

	t_lock_cpu();
	if (p_mtxcb->p_loctsk != p_runtsk) {
		ercd = E_ILUSE;
	}
	else {
		queue_delete(&(p_mtxcb->mutex_queue));
		if (MTX_CEILING(p_mtxcb)) {
			if (mutex_drop_priority(p_runtsk, p_mtxcb->p_mtxinib->ceilpri)) {
				dspreq = true;
			}
		}
		if (mutex_release(p_mtxcb)) {
			dspreq = true;
		}
		if (dspreq) {
			dispatch();
		}
		ercd = E_OK;
	}
	t_unlock_cpu();

  error_exit:
	LOG_UNL_MTX_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_unl_mtx */

/*
 *  �ߥ塼�ƥå����ν����
 */
#ifdef TOPPERS_ini_mtx

ER
ini_mtx(ID mtxid)
{
	MTXCB	*p_mtxcb;
	TCB		*p_loctsk;
	bool_t	dspreq;
	ER		ercd;
    
	LOG_INI_MTX_ENTER(mtxid);
	CHECK_TSKCTX_UNL();
	CHECK_MTXID(mtxid);
	p_mtxcb = get_mtxcb(mtxid);

	t_lock_cpu();
	dspreq = init_wait_queue(&(p_mtxcb->wait_queue));
	p_loctsk = p_mtxcb->p_loctsk;
	if (p_loctsk != NULL) {
		queue_delete(&(p_mtxcb->mutex_queue));
		p_mtxcb->p_loctsk = NULL;
		if (MTX_CEILING(p_mtxcb)) {
			if (mutex_drop_priority(p_loctsk, p_mtxcb->p_mtxinib->ceilpri)) {
				dspreq = true;
			}
		}
	}
	if (dspreq) {
		dispatch();
	}
	ercd = E_OK;
	t_unlock_cpu();

  error_exit:
	LOG_INI_MTX_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_ini_mtx */

/*
 *  �ߥ塼�ƥå����ξ��ֻ���
 */
#ifdef TOPPERS_ref_mtx

ER
ref_mtx(ID mtxid, T_RMTX *pk_rmtx)
{
	MTXCB	*p_mtxcb;
	ER		ercd;
    
	LOG_REF_MTX_ENTER(mtxid, pk_rmtx);
	CHECK_TSKCTX_UNL();
	CHECK_MTXID(mtxid);
	p_mtxcb = get_mtxcb(mtxid);

	t_lock_cpu();
	pk_rmtx->htskid = (p_mtxcb->p_loctsk != NULL) ? TSKID(p_mtxcb->p_loctsk)
													: TSK_NONE;
	pk_rmtx->wtskid = wait_tskid(&(p_mtxcb->wait_queue));
	ercd = E_OK;
	t_unlock_cpu();

  error_exit:
	LOG_REF_MTX_LEAVE(ercd, pk_rmtx);
	return(ercd);
}

#endif /* TOPPERS_ref_mtx */
