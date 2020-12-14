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
 *  @(#) $Id: interrupt.c 2415 2012-09-06 03:13:06Z ertl-hiro $
 */

/*
 *		����ߴ�����ǽ
 */

#include "kernel_impl.h"
#include "check.h"
#include "task.h"
#include "interrupt.h"

/*
 *  �ȥ졼�����ޥ���Υǥե�������
 */
#ifndef LOG_ISR_ENTER
#define LOG_ISR_ENTER(intno)
#endif /* LOG_ISR_ENTER */

#ifndef LOG_ISR_LEAVE
#define LOG_ISR_LEAVE(intno)
#endif /* LOG_ISR_LEAVE */

#ifndef LOG_ACRE_ISR_ENTER
#define LOG_ACRE_ISR_ENTER(pk_cisr)
#endif /* LOG_ACRE_ISR_ENTER */

#ifndef LOG_ACRE_ISR_LEAVE
#define LOG_ACRE_ISR_LEAVE(ercd)
#endif /* LOG_ACRE_ISR_LEAVE */

#ifndef LOG_DEL_ISR_ENTER
#define LOG_DEL_ISR_ENTER(isrid)
#endif /* LOG_DEL_ISR_ENTER */

#ifndef LOG_DEL_ISR_LEAVE
#define LOG_DEL_ISR_LEAVE(ercd)
#endif /* LOG_DEL_ISR_LEAVE */

#ifndef LOG_DIS_INT_ENTER
#define LOG_DIS_INT_ENTER(intno)
#endif /* LOG_DIS_INT_ENTER */

#ifndef LOG_DIS_INT_LEAVE
#define LOG_DIS_INT_LEAVE(ercd)
#endif /* LOG_DIS_INT_LEAVE */

#ifndef LOG_ENA_INT_ENTER
#define LOG_ENA_INT_ENTER(intno)
#endif /* LOG_ENA_INT_ENTER */

#ifndef LOG_ENA_INT_LEAVE
#define LOG_ENA_INT_LEAVE(ercd)
#endif /* LOG_ENA_INT_LEAVE */

#ifndef LOG_CHG_IPM_ENTER
#define LOG_CHG_IPM_ENTER(intpri)
#endif /* LOG_CHG_IPM_ENTER */

#ifndef LOG_CHG_IPM_LEAVE
#define LOG_CHG_IPM_LEAVE(ercd)
#endif /* LOG_CHG_IPM_LEAVE */

#ifndef LOG_GET_IPM_ENTER
#define LOG_GET_IPM_ENTER(p_intpri)
#endif /* LOG_GET_IPM_ENTER */

#ifndef LOG_GET_IPM_LEAVE
#define LOG_GET_IPM_LEAVE(ercd, intpri)
#endif /* LOG_GET_IPM_LEAVE */

/*
 *  ����ߥ����ӥ��롼����ο�
 */
#define tnum_isr	((uint_t)(tmax_isrid - TMIN_SEMID + 1) + tnum_sisr)

/*
 *  ����ߥ����ӥ��롼����ID�������ߥ����ӥ��롼��������֥�å����
 *  ��Ф�����Υޥ���
 */
#define INDEX_ISR(isrid)	((uint_t)((isrid) - TMIN_ISRID) + tnum_sisr)
#define get_isrcb(isrid)	(&(isrcb_table[INDEX_ISR(isrid)]))

/*
 *  ����ߥ����ӥ��롼���󥭥塼�ؤ���Ͽ
 */
Inline void
enqueue_isr(QUEUE *p_isr_queue, ISRCB *p_isrcb)
{
	QUEUE	*p_entry;
	PRI		isrpri = p_isrcb->p_isrinib->isrpri;

	for (p_entry = p_isr_queue->p_next; p_entry != p_isr_queue;
											p_entry = p_entry->p_next) {
		if (isrpri < ((ISRCB *) p_entry)->p_isrinib->isrpri) {
			break;
		}
	}
	queue_insert_prev(p_entry, &(p_isrcb->isr_queue));
}

#ifdef TOPPERS_isrini

/*
 *  ���Ѥ��Ƥ��ʤ�����ߥ����ӥ��롼��������֥�å��Υꥹ��
 */
QUEUE	free_isrcb;

/* 
 *  ����ߥ����ӥ��롼����ǽ�ν����
 */
void
initialize_isr(void)
{
	uint_t	i, j;
	ISRCB	*p_isrcb;
	ISRINIB	*p_isrinib;

	for (i = 0; i < tnum_isr_queue; i++) {
		queue_initialize(&(isr_queue_table[i]));
	}
	for (i = 0; i < tnum_sisr; i++) {
		p_isrcb = &(isrcb_table[i]);
		p_isrcb->p_isrinib = &(sisrinib_table[i]);
		enqueue_isr(p_isrcb->p_isrinib->p_isr_queue, p_isrcb);
	}
	queue_initialize(&free_isrcb);
	for (j = 0; i < tnum_isr; i++, j++) {
		p_isrcb = &(isrcb_table[i]);
		p_isrinib = &(aisrinib_table[j]);
		p_isrinib->isratr = TA_NOEXS;
		p_isrcb->p_isrinib = ((const ISRINIB *) p_isrinib);
		queue_insert_prev(&free_isrcb, &(p_isrcb->isr_queue));
	}
}

#endif /* TOPPERS_isrini */

/*
 *  ����ߥ����ӥ��롼����θƽФ�
 */
#ifdef TOPPERS_isrcal

void
call_isr(QUEUE *p_isr_queue)
{
	QUEUE	*p_queue;
	ISRINIB	*p_isrinib;
	PRI		saved_ipm;

	saved_ipm = i_get_ipm();
	for (p_queue = p_isr_queue->p_next; p_queue != p_isr_queue;
											p_queue = p_queue->p_next) {
		p_isrinib = (ISRINIB *)(((ISRCB *) p_queue)->p_isrinib);
		LOG_ISR_ENTER(p_isrinib->intno);
		(*(p_isrinib->isr))(p_isrinib->exinf);
		LOG_ISR_LEAVE(p_isrinib->intno);

		if (p_queue->p_next != p_isr_queue) {
			/* ISR�θƽФ����ξ��֤��᤹ */
			if (i_sense_lock()) {
				i_unlock_cpu();
			}
			i_set_ipm(saved_ipm);
		}
	}
}

#endif /* TOPPERS_isrcal */

/*
 *  ����ߥ����ӥ��롼����ƽФ����塼�θ���
 */
Inline QUEUE *
search_isr_queue(INTNO intno)
{
	int_t	left, right, i;

	if (tnum_isr_queue == 0) {
		return(NULL);
	}

	left = 0;
	right = tnum_isr_queue - 1;
	while (left < right) {
		i = (left + right + 1) / 2;
		if (intno < isr_queue_list[i].intno) {
			right = i - 1;
		}
		else {
			left = i;
		}
	}
	if (isr_queue_list[left].intno == intno) {
		return(isr_queue_list[left].p_isr_queue);
	}
	else {
		return(NULL);
	}
}

/*
 *  ����ߥ����ӥ��롼���������
 */
#ifdef TOPPERS_acre_isr

ER_UINT
acre_isr(const T_CISR *pk_cisr)
{
	ISRCB	*p_isrcb;
	ISRINIB	*p_isrinib;
	QUEUE	*p_isr_queue;
	ER		ercd;

	LOG_ACRE_ISR_ENTER(pk_cisr);
	CHECK_TSKCTX_UNL();
	CHECK_RSATR(pk_cisr->isratr, TARGET_ISRATR);
	CHECK_INTNO_CREISR(pk_cisr->intno);
	CHECK_ALIGN_FUNC(pk_cisr->isr);
	CHECK_NONNULL_FUNC(pk_cisr->isr);
	CHECK_ISRPRI(pk_cisr->isrpri);

	p_isr_queue = search_isr_queue(pk_cisr->intno);
	CHECK_OBJ(p_isr_queue != NULL);

	t_lock_cpu();
	if (tnum_isr == 0 || queue_empty(&free_isrcb)) {
		ercd = E_NOID;
	}
	else {
		p_isrcb = ((ISRCB *) queue_delete_next(&free_isrcb));
		p_isrinib = (ISRINIB *)(p_isrcb->p_isrinib);
		p_isrinib->isratr = pk_cisr->isratr;
		p_isrinib->exinf = pk_cisr->exinf;
		p_isrinib->intno = pk_cisr->intno;
		p_isrinib->p_isr_queue = p_isr_queue;
		p_isrinib->isr = pk_cisr->isr;
		p_isrinib->isrpri = pk_cisr->isrpri;
		enqueue_isr(p_isr_queue, p_isrcb);
		ercd = ISRID(p_isrcb);
	}
	t_unlock_cpu();

  error_exit:
	LOG_ACRE_ISR_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_acre_isr */

/*
 *  ����ߥ����ӥ��롼����κ��
 */
#ifdef TOPPERS_del_isr

ER
del_isr(ID isrid)
{
	ISRCB	*p_isrcb;
	ISRINIB	*p_isrinib;
	ER		ercd;

	LOG_DEL_ISR_ENTER(isrid);
	CHECK_TSKCTX_UNL();
	CHECK_ISRID(isrid);
	p_isrcb = get_isrcb(isrid);

	t_lock_cpu();
	if (p_isrcb->p_isrinib->isratr == TA_NOEXS) {
		ercd = E_NOEXS;
	}
	else {
		queue_delete(&(p_isrcb->isr_queue));
		p_isrinib = (ISRINIB *)(p_isrcb->p_isrinib);
		p_isrinib->isratr = TA_NOEXS;
		queue_insert_prev(&free_isrcb, &(p_isrcb->isr_queue));
	}
	t_unlock_cpu();

  error_exit:
	LOG_DEL_ISR_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_del_isr */

/* 
 *  ����ߴ�����ǽ�ν����
 */
#ifdef TOPPERS_intini
#ifndef OMIT_INITIALIZE_INTERRUPT

void
initialize_interrupt(void)
{
	uint_t			i;
	const INHINIB	*p_inhinib;
	const INTINIB	*p_intinib;

	for (i = 0; i < tnum_inhno; i++) {
		p_inhinib = &(inhinib_table[i]);
		x_define_inh(p_inhinib->inhno, p_inhinib->int_entry);
	}
	for (i = 0; i < tnum_intno; i++) {
		p_intinib = &(intinib_table[i]);
		x_config_int(p_intinib->intno, p_intinib->intatr, p_intinib->intpri);
	}
}

#endif /* OMIT_INITIALIZE_INTERRUPT */
#endif /* TOPPERS_intini */

/*
 *  ����ߤζػ�
 */
#ifdef TOPPERS_dis_int
#ifdef TOPPERS_SUPPORT_DIS_INT

ER
dis_int(INTNO intno)
{
	bool_t	locked;
	ER		ercd;

	LOG_DIS_INT_ENTER(intno);
	CHECK_TSKCTX();
	CHECK_INTNO_DISINT(intno);

	locked = t_sense_lock();
	if (!locked) {
		t_lock_cpu();
	}
	if (t_disable_int(intno)) {
		ercd = E_OK;
	}
	else {
		ercd = E_OBJ;
	}
	if (!locked) {
		t_unlock_cpu();
	}

  error_exit:
	LOG_DIS_INT_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_SUPPORT_DIS_INT */
#endif /* TOPPERS_dis_int */

/*
 *  ����ߤε���
 */
#ifdef TOPPERS_ena_int
#ifdef TOPPERS_SUPPORT_ENA_INT

ER
ena_int(INTNO intno)
{
	bool_t	locked;
	ER		ercd;

	LOG_ENA_INT_ENTER(intno);
	CHECK_TSKCTX();
	CHECK_INTNO_DISINT(intno);

	locked = t_sense_lock();
	if (!locked) {
		t_lock_cpu();
	}
	if (t_enable_int(intno)) {
		ercd = E_OK;
	}
	else {
		ercd = E_OBJ;
	}
	if (!locked) {
		t_unlock_cpu();
	}

  error_exit:
	LOG_ENA_INT_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_SUPPORT_ENA_INT */
#endif /* TOPPERS_ena_int */

/*
 *  �����ͥ���٥ޥ������ѹ�
 */
#ifdef TOPPERS_chg_ipm

ER
chg_ipm(PRI intpri)
{
	ER		ercd;

	LOG_CHG_IPM_ENTER(intpri);
	CHECK_TSKCTX_UNL();
	CHECK_INTPRI_CHGIPM(intpri);

	t_lock_cpu();
	t_set_ipm(intpri);
	if (intpri == TIPM_ENAALL) {
		ipmflg = true;
		if (!disdsp) {
			dspflg = true;
			if (p_runtsk != p_schedtsk) {
				dispatch();
			}
		}
		if (p_runtsk->enatex && p_runtsk->texptn != 0U) {
			call_texrtn();
		}
	}
	else {
		ipmflg = false;
		dspflg = false;
	}
	ercd = E_OK;
	t_unlock_cpu();

  error_exit:
	LOG_CHG_IPM_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_chg_ipm */

/*
 *  �����ͥ���٥ޥ����λ���
 */
#ifdef TOPPERS_get_ipm

ER
get_ipm(PRI *p_intpri)
{
	ER		ercd;

	LOG_GET_IPM_ENTER(p_intpri);
	CHECK_TSKCTX_UNL();

	t_lock_cpu();
	*p_intpri = t_get_ipm();
	ercd = E_OK;
	t_unlock_cpu();

  error_exit:
	LOG_GET_IPM_LEAVE(ercd, *p_intpri);
	return(ercd);
}

#endif /* TOPPERS_get_ipm */
