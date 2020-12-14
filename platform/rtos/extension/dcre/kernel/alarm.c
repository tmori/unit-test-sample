/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2012 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: alarm.c 2415 2012-09-06 03:13:06Z ertl-hiro $
 */

/*
 *		���顼��ϥ�ɥ鵡ǽ
 */

#include "kernel_impl.h"
#include "check.h"
#include "alarm.h"

/*
 *  �ȥ졼�����ޥ���Υǥե�������
 */
#ifndef LOG_ALM_ENTER
#define LOG_ALM_ENTER(p_almcb)
#endif /* LOG_ALM_ENTER */

#ifndef LOG_ALM_LEAVE
#define LOG_ALM_LEAVE(p_almcb)
#endif /* LOG_ALM_LEAVE */

#ifndef LOG_ACRE_ALM_ENTER
#define LOG_ACRE_ALM_ENTER(pk_calm)
#endif /* LOG_ACRE_ALM_ENTER */

#ifndef LOG_ACRE_ALM_LEAVE
#define LOG_ACRE_ALM_LEAVE(ercd)
#endif /* LOG_ACRE_ALM_LEAVE */

#ifndef LOG_DEL_ALM_ENTER
#define LOG_DEL_ALM_ENTER(almid)
#endif /* LOG_DEL_ALM_ENTER */

#ifndef LOG_DEL_ALM_LEAVE
#define LOG_DEL_ALM_LEAVE(ercd)
#endif /* LOG_DEL_ALM_LEAVE */

#ifndef LOG_STA_ALM_ENTER
#define LOG_STA_ALM_ENTER(almid, almtim)
#endif /* LOG_STA_ALM_ENTER */

#ifndef LOG_STA_ALM_LEAVE
#define LOG_STA_ALM_LEAVE(ercd)
#endif /* LOG_STA_ALM_LEAVE */

#ifndef LOG_ISTA_ALM_ENTER
#define LOG_ISTA_ALM_ENTER(almid, almtim)
#endif /* LOG_ISTA_ALM_ENTER */

#ifndef LOG_ISTA_ALM_LEAVE
#define LOG_ISTA_ALM_LEAVE(ercd)
#endif /* LOG_ISTA_ALM_LEAVE */

#ifndef LOG_STP_ALM_ENTER
#define LOG_STP_ALM_ENTER(almid)
#endif /* LOG_STP_ALM_ENTER */

#ifndef LOG_STP_ALM_LEAVE
#define LOG_STP_ALM_LEAVE(ercd)
#endif /* LOG_STP_ALM_LEAVE */

#ifndef LOG_ISTP_ALM_ENTER
#define LOG_ISTP_ALM_ENTER(almid)
#endif /* LOG_ISTP_ALM_ENTER */

#ifndef LOG_ISTP_ALM_LEAVE
#define LOG_ISTP_ALM_LEAVE(ercd)
#endif /* LOG_ISTP_ALM_LEAVE */

#ifndef LOG_REF_ALM_ENTER
#define LOG_REF_ALM_ENTER(almid, pk_ralm)
#endif /* LOG_REF_ALM_ENTER */

#ifndef LOG_REF_ALM_LEAVE
#define LOG_REF_ALM_LEAVE(ercd, pk_ralm)
#endif /* LOG_REF_ALM_LEAVE */

/*
 *  ���顼��ϥ�ɥ�ο�
 */
#define tnum_alm	((uint_t)(tmax_almid - TMIN_ALMID + 1))
#define tnum_salm	((uint_t)(tmax_salmid - TMIN_ALMID + 1))

/*
 *  ���顼��ϥ�ɥ�ID���饢�顼��ϥ�ɥ�����֥�å�����Ф�����Υޥ���
 */
#define INDEX_ALM(almid)	((uint_t)((almid) - TMIN_ALMID))
#define get_almcb(almid)	(&(almcb_table[INDEX_ALM(almid)]))

#ifdef TOPPERS_almini

/*
 *  ���Ѥ��Ƥ��ʤ����顼��ϥ�ɥ�����֥�å��Υꥹ��
 *
 *  ���顼��ϥ�ɥ�����֥�å�����Ƭ�ˤϥ��塼�ˤĤʤ�������ΰ褬��
 *  �����ᡤ�����।�٥�ȥ֥�å���tmevtb�ˤ��ΰ���Ѥ��롥
 */
QUEUE	free_almcb;

/*
 *  ���顼��ϥ�ɥ鵡ǽ�ν����
 */
void
initialize_alarm(void)
{
	uint_t	i, j;
	ALMCB	*p_almcb;
	ALMINIB	*p_alminib;

	for (i = 0; i < tnum_salm; i++) {
		p_almcb = &(almcb_table[i]);
		p_almcb->p_alminib = &(alminib_table[i]);
		p_almcb->almsta = false;
	}
	queue_initialize(&free_almcb);
	for (j = 0; i < tnum_alm; i++, j++) {
		p_almcb = &(almcb_table[i]);
		p_alminib = &(aalminib_table[j]);
		p_alminib->almatr = TA_NOEXS;
		p_almcb->p_alminib = ((const ALMINIB *) p_alminib);
		queue_insert_prev(&free_almcb, ((QUEUE *) &(p_almcb->tmevtb)));
	}
}

#endif /* TOPPERS_almini */

/*
 *  ���顼��ϥ�ɥ������
 */
#ifdef TOPPERS_acre_alm

ER_UINT
acre_alm(const T_CALM *pk_calm)
{
	ALMCB	*p_almcb;
	ALMINIB	*p_alminib;
	ER		ercd;

	LOG_ACRE_ALM_ENTER(pk_calm);
	CHECK_TSKCTX_UNL();
	CHECK_RSATR(pk_calm->almatr, TA_NULL);
	CHECK_ALIGN_FUNC(pk_calm->almhdr);
	CHECK_NONNULL_FUNC(pk_calm->almhdr);

	t_lock_cpu();
	if (tnum_alm == 0 || queue_empty(&free_almcb)) {
		ercd = E_NOID;
	}
	else {
		p_almcb = ((ALMCB *)(((char *) queue_delete_next(&free_almcb))
												- offsetof(ALMCB, tmevtb)));
		p_alminib = (ALMINIB *)(p_almcb->p_alminib);
		p_alminib->almatr = pk_calm->almatr;
		p_alminib->exinf = pk_calm->exinf;
		p_alminib->almhdr = pk_calm->almhdr;

		p_almcb->almsta = false;
		ercd = ALMID(p_almcb);
	}
	t_unlock_cpu();

  error_exit:
	LOG_ACRE_ALM_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_acre_alm */

/*
 *  ���顼��ϥ�ɥ�κ��
 */
#ifdef TOPPERS_del_alm

ER
del_alm(ID almid)
{
	ALMCB	*p_almcb;
	ALMINIB	*p_alminib;
	ER		ercd;

	LOG_DEL_ALM_ENTER(almid);
	CHECK_TSKCTX_UNL();
	CHECK_ALMID(almid);
	p_almcb = get_almcb(almid);

	t_lock_cpu();
	if (p_almcb->p_alminib->almatr == TA_NOEXS) {
		ercd = E_NOEXS;
	}
	else if (ALMID(p_almcb) > tmax_salmid) {
		if (p_almcb->almsta) {
			p_almcb->almsta = false;
			tmevtb_dequeue(&(p_almcb->tmevtb));
		}

		p_alminib = (ALMINIB *)(p_almcb->p_alminib);
		p_alminib->almatr = TA_NOEXS;
		queue_insert_prev(&free_almcb, ((QUEUE *) &(p_almcb->tmevtb)));
		ercd = E_OK;
	}
	else {
		ercd = E_OBJ;
	}
	t_unlock_cpu();

  error_exit:
	LOG_DEL_ALM_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_del_alm */

/*
 *  ���顼��ϥ�ɥ��ư���
 */
#ifdef TOPPERS_sta_alm

ER
sta_alm(ID almid, RELTIM almtim)
{
	ALMCB	*p_almcb;
	ER		ercd;

	LOG_STA_ALM_ENTER(almid, almtim);
	CHECK_TSKCTX_UNL();
	CHECK_ALMID(almid);
	CHECK_PAR(almtim <= TMAX_RELTIM);
	p_almcb = get_almcb(almid);

	t_lock_cpu();
	if (p_almcb->p_alminib->almatr == TA_NOEXS) {
		ercd = E_NOEXS;
	}
	else if (p_almcb->almsta) {
		tmevtb_dequeue(&(p_almcb->tmevtb));
	}
	else {
		p_almcb->almsta = true;
	}
	tmevtb_enqueue(&(p_almcb->tmevtb), almtim,
								(CBACK) call_almhdr, (void *) p_almcb);
	ercd = E_OK;
	t_unlock_cpu();

  error_exit:
	LOG_STA_ALM_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_sta_alm */

/*
 *  ���顼��ϥ�ɥ��ư��ϡ��󥿥�������ƥ������ѡ�
 */
#ifdef TOPPERS_ista_alm

ER
ista_alm(ID almid, RELTIM almtim)
{
	ALMCB	*p_almcb;
	ER		ercd;

	LOG_ISTA_ALM_ENTER(almid, almtim);
	CHECK_INTCTX_UNL();
	CHECK_ALMID(almid);
	CHECK_PAR(almtim <= TMAX_RELTIM);
	p_almcb = get_almcb(almid);

	i_lock_cpu();
	if (p_almcb->p_alminib->almatr == TA_NOEXS) {
		ercd = E_NOEXS;
	}
	else if (p_almcb->almsta) {
		tmevtb_dequeue(&(p_almcb->tmevtb));
	}
	else {
		p_almcb->almsta = true;
	}
	tmevtb_enqueue(&(p_almcb->tmevtb), almtim,
								(CBACK) call_almhdr, (void *) p_almcb);
	ercd = E_OK;
	i_unlock_cpu();

  error_exit:
	LOG_ISTA_ALM_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_ista_alm */

/*
 *  ���顼��ϥ�ɥ��ư�����
 */
#ifdef TOPPERS_stp_alm

ER
stp_alm(ID almid)
{
	ALMCB	*p_almcb;
	ER		ercd;

	LOG_STP_ALM_ENTER(almid);
	CHECK_TSKCTX_UNL();
	CHECK_ALMID(almid);
	p_almcb = get_almcb(almid);

	t_lock_cpu();
	if (p_almcb->p_alminib->almatr == TA_NOEXS) {
		ercd = E_NOEXS;
	}
	else if (p_almcb->almsta) {
		p_almcb->almsta = false;
		tmevtb_dequeue(&(p_almcb->tmevtb));
	}
	ercd = E_OK;
	t_unlock_cpu();

  error_exit:
	LOG_STP_ALM_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_stp_alm */

/*
 *  ���顼��ϥ�ɥ��ư����ߡ��󥿥�������ƥ������ѡ�
 */
#ifdef TOPPERS_istp_alm

ER
istp_alm(ID almid)
{
	ALMCB	*p_almcb;
	ER		ercd;

	LOG_ISTP_ALM_ENTER(almid);
	CHECK_INTCTX_UNL();
	CHECK_ALMID(almid);
	p_almcb = get_almcb(almid);

	i_lock_cpu();
	if (p_almcb->p_alminib->almatr == TA_NOEXS) {
		ercd = E_NOEXS;
	}
	else if (p_almcb->almsta) {
		p_almcb->almsta = false;
		tmevtb_dequeue(&(p_almcb->tmevtb));
	}
	ercd = E_OK;
	i_unlock_cpu();

  error_exit:
	LOG_ISTP_ALM_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_istp_alm */

/*
 *  ���顼��ϥ�ɥ�ξ��ֻ���
 */
#ifdef TOPPERS_ref_alm

ER
ref_alm(ID almid, T_RALM *pk_ralm)
{
	ALMCB	*p_almcb;
	ER		ercd;
    
	LOG_REF_ALM_ENTER(almid, pk_ralm);
	CHECK_TSKCTX_UNL();
	CHECK_ALMID(almid);
	p_almcb = get_almcb(almid);

	t_lock_cpu();
	if (p_almcb->p_alminib->almatr == TA_NOEXS) {
		ercd = E_NOEXS;
	}
	else {
		if (p_almcb->almsta) {
			pk_ralm->almstat = TALM_STA;
			pk_ralm->lefttim = tmevt_lefttim(&(p_almcb->tmevtb));
		}
		else {
			pk_ralm->almstat = TALM_STP;
		}
		ercd = E_OK;
	}
	t_unlock_cpu();

  error_exit:
	LOG_REF_ALM_LEAVE(ercd, pk_ralm);
	return(ercd);
}

#endif /* TOPPERS_ref_alm */

/*
 *  ���顼��ϥ�ɥ鵯ư�롼����
 */
#ifdef TOPPERS_almcal

void
call_almhdr(ALMCB *p_almcb)
{
	PRI		saved_ipm;

	/*
	 *  ���顼��ϥ�ɥ����߾��֤ˤ��롥
	 */
	p_almcb->almsta = false;

	/*
	 *  ���顼��ϥ�ɥ��CPU��å�������֤ǸƤӽФ���
	 */
	saved_ipm = i_get_ipm();
	i_unlock_cpu();

	LOG_ALM_ENTER(p_almcb);
	(*((ALMHDR)(p_almcb->p_alminib->almhdr)))(p_almcb->p_alminib->exinf);
	LOG_ALM_LEAVE(p_almcb);

	if (!i_sense_lock()) {
		i_lock_cpu();
	}
	i_set_ipm(saved_ipm);
}

#endif /* TOPPERS_almcal */
