/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      High Reliable system Profile Kernel
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
 *  @(#) $Id: bit_mutex.c 2136 2011-06-26 03:35:48Z ertl-hiro $
 */

/*
 *		�ߥ塼�ƥå�����ǽ������������
 */

#include "kernel/kernel_impl.h"
#include "kernel/task.h"
#include "kernel/mutex.h"

/*
 *  �ߥ塼�ƥå���ID����ߥ塼�ƥå��������֥�å�����Ф�����Υޥ�
 *  ���mutex.c����
 */
#define INDEX_MTX(mtxid)	((uint_t)((mtxid) - TMIN_MTXID))
#define get_mtxcb(mtxid)	(&(mtxcb_table[INDEX_MTX(mtxid)]))

/*
 *  �ߥ塼�ƥå��������֥�å����mutex_queue�ؤΥݥ��󥿤��顤�ߥ塼�ƥ�
 *  ���������֥�å��ؤΥݥ��󥿤���Ф�����Υޥ����mutex.c����
 */
#define MTXCB_QUEUE(p_queue) \
			((MTXCB *)(((char *) p_queue) - offsetof(MTXCB, mutex_queue)))

/*
 *  �ߥ塼�ƥå����Υץ�ȥ����Ƚ�Ǥ���ޥ����mutex.c����
 */
#define MTXPROTO_MASK			0x03U
#define MTXPROTO(p_mtxcb)		((p_mtxcb)->p_mtxinib->mtxatr & MTXPROTO_MASK)
#define MTX_CEILING(p_mtxcb)	(MTXPROTO(p_mtxcb) == TA_CEILING)

/*
 *   ���顼�����ɤ����
 */
#define E_SYS_LINENO	ERCD(E_SYS, -(__LINE__))

/*
 *  �����֥�å��Υ��ɥ쥹���������Υ����å�
 */
#define VALID_TCB(p_tcb) \
		((((char *) p_tcb) - ((char *) tcb_table)) % sizeof(TCB) == 0 \
			&& TMIN_TSKID <= TSKID(p_tcb) && TSKID(p_tcb) <= tmax_tskid)

#define VALID_MTXCB(p_mtxcb) \
		((((char *) p_mtxcb) - ((char *) mtxcb_table)) % sizeof(MTXCB) == 0 \
			&& TMIN_MTXID <= MTXID(p_mtxcb) && MTXID(p_mtxcb) <= tmax_mtxid)
				
/*
 *  ���塼�Υ����å��Τ���δؿ�
 *
 *  p_queue��p_entry���ޤޤ�Ƥ��뤫��Ĵ�٤롥�ޤޤ�Ƥ����true���ޤ�
 *  ��Ƥ��ʤ����ˤ�false���֤������֥��󥯤�������ξ��ˤ⡤
 *  false���֤���
 */
static bool_t
in_queue(QUEUE *p_queue, QUEUE *p_entry)
{
	QUEUE	*p_current, *p_next;

	p_current = p_queue->p_next;
	if (p_current->p_prev != p_queue) {
		return(false);					/* ���֥��󥯤������� */
	}
	while (p_current != p_queue) {
		if (p_current == p_entry) {
			return(true);				/* p_entry���ޤޤ�Ƥ��� */
		}

		/*
		 *  ���塼�μ������Ǥ˿ʤ�
		 */
		p_next = p_current->p_next;
		if (p_next->p_prev != p_current) {
			return(false);				 /* ���֥��󥯤������� */
		}
		p_current = p_next;
	}
	return(false);
}

/*
 *  ��������θ���
 */
static ER
bit_mutex_task(ID tskid)
{
	TCB			*p_tcb;
	MTXCB		*p_mtxcb;
	QUEUE		*p_queue, *p_next;
	uint_t		pri;

	if (!(TMIN_TSKID <= (tskid) && (tskid) <= tmax_tskid)) {
		return(E_ID);
	}
	p_tcb = get_tcb(tskid);
	pri = p_tcb->bpriority;

	/*
	 *  ����������å����Ƥ���ߥ塼�ƥå����Υ��塼�θ���
	 */
	p_queue = p_tcb->mutex_queue.p_next;
	if (p_queue->p_prev != &(p_tcb->mutex_queue)) {
		return(E_SYS_LINENO);
	}
	while (p_queue != &(p_tcb->mutex_queue)) {
		p_mtxcb = MTXCB_QUEUE(p_queue);
		if (!VALID_MTXCB(p_mtxcb)) {
			return(E_SYS_LINENO);
		}

		/*
		 *  �ߥ塼�ƥå������å����Ƥ��륿�����Υ����å�
		 */
		if (p_mtxcb->p_loctsk != p_tcb) {
			return(E_SYS_LINENO);
		}

		/*
		 *  ����ͥ���٤η׻�
		 */
		if (MTXPROTO(p_mtxcb)) {
			if (p_mtxcb->p_mtxinib->ceilpri < pri) {
				pri = p_mtxcb->p_mtxinib->ceilpri;
			}
		}

		/*
		 *  ���塼�μ������Ǥ˿ʤ�
		 */
		p_next = p_queue->p_next;
		if (p_next->p_prev != p_queue) {
			return(E_SYS_LINENO);
		}
		p_queue = p_next;
	}

	/*
	 *  ����ͥ���٤θ���
	 */
	if (p_tcb->priority != pri) {
		return(E_SYS_LINENO);
	}

	/*
	 *  ���������ԤäƤ���ߥ塼�ƥå����˴ؤ��븡��
	 */
	if (TSTAT_WAIT_MTX(p_tcb->tstat)) {
		p_mtxcb = ((WINFO_MTX *)(p_tcb->p_winfo))->p_mtxcb;
		if (!VALID_MTXCB(p_mtxcb)) {
			return(E_SYS_LINENO);
		}
		if (!in_queue(&(p_mtxcb->wait_queue), &(p_tcb->task_queue))) {
			return(E_SYS_LINENO);
		}
	}
	return(E_OK);
}

/*
 *  �ߥ塼�ƥå�����θ���
 */
static ER
bit_mutex_mutex(ID mtxid)
{
	MTXCB		*p_mtxcb;
	TCB			*p_tcb;
	QUEUE		*p_queue, *p_next;
	uint_t		pri;

	if (!(TMIN_MTXID <= (mtxid) && (mtxid) <= tmax_mtxid)) {
		return(E_ID);
	}
	p_mtxcb = get_mtxcb(mtxid);

	/*
	 *  ������֥�å��ؤΥݥ��󥿤θ���
	 */
	if (p_mtxcb->p_mtxinib != &(mtxinib_table[INDEX_MTX(mtxid)])) {
		return(E_SYS_LINENO);
	}

	/*
	 *  �ߥ塼�ƥå����Ԥ����塼�θ���
	 */
	p_queue = p_mtxcb->wait_queue.p_next;
	if (p_queue->p_prev != &(p_mtxcb->wait_queue)) {
		return(E_SYS_LINENO);
	}
	pri = TMIN_TPRI;
	while (p_queue != &(p_mtxcb->wait_queue)) {
		p_tcb = (TCB *) p_queue;
		if (!VALID_TCB(p_tcb)) {
			return(E_SYS_LINENO);
		}

		/*
		 *  ���塼��������ͥ���ٽ�ˤʤäƤ��뤫�θ���
		 */
		if (MTXPROTO(p_mtxcb) != TA_NULL) {
			if (p_tcb->priority < pri) {
				return(E_SYS_LINENO);
			}
		}
		pri = p_tcb->priority;

		/*
		 *  ���������֤θ���
		 *
		 *  �ߥ塼�ƥå����Ԥ����֤Υ������θ����ϡ���������θ����ǹԤ�
		 *  �Ƥ��뤿�ᡤ�����ǤϹԤ�ʤ���
		 */
		if (!TSTAT_WAIT_MTX(p_tcb->tstat)) {
			return(E_SYS_LINENO);
		}

		/*
		 *  ͥ���پ�¤θ���
		 */
		if (MTXPROTO(p_mtxcb) == TA_CEILING) {
			if (p_tcb->bpriority < p_mtxcb->p_mtxinib->ceilpri) {
				return(E_SYS_LINENO);
			}
		}

		/*
		 *  ���塼�μ������Ǥ˿ʤ�
		 */
		p_next = p_queue->p_next;
		if (p_next->p_prev != p_queue) {
			return(E_SYS_LINENO);
		}
		p_queue = p_next;
	}

	/*
	 *  �ߥ塼�ƥå������å����Ƥ��륿�����θ���
	 */
	p_tcb = p_mtxcb->p_loctsk;
	if (p_tcb == NULL) {
		/*
		 *  �ߥ塼�ƥå�������å�����Ƥ��ʤ���
		 */
		if (!queue_empty(&(p_mtxcb->wait_queue))) {
			return(E_SYS_LINENO);
		}
	}
	else {
		/*
		 *  �ߥ塼�ƥå�������å�����Ƥ����
		 *
		 *  �ߥ塼�ƥå������å����Ƥ��륿�����θ����ϡ���������θ�
		 *  ���ǹԤäƤ��뤿�ᡤ�����ǤϹԤ�ʤ���
		 */
		if (!VALID_TCB(p_tcb)) {
			return(E_SYS_LINENO);
		}
		if (!in_queue(&(p_tcb->mutex_queue), &(p_mtxcb->mutex_queue))) {
			return(E_SYS_LINENO);
		}

		/*
		 *  ͥ���پ�¤θ���
		 */
		if (MTXPROTO(p_mtxcb) == TA_CEILING) {
			if (p_tcb->bpriority < p_mtxcb->p_mtxinib->ceilpri) {
				return(E_SYS_LINENO);
			}
		}
	}
	return(E_OK);
}

/*
 *  �����������롼��������
 */
ER
bit_mutex(void)
{
	ID		tskid, mtxid;
	ER		ercd;

	/*
	 *  ��������θ���
	 */
	for (tskid = TMIN_TSKID; tskid <= tmax_tskid; tskid++) {
		ercd = bit_mutex_task(tskid);
		if (ercd != E_OK) {
			return(ercd);
		}
	}

	/*
	 *  �ߥ塼�ƥå�����θ���
	 */
	for (mtxid = TMIN_MTXID; mtxid <= tmax_mtxid; mtxid++) {
		ercd = bit_mutex_mutex(mtxid);
		if (ercd != E_OK) {
			return(ercd);
		}
	}
	return(E_OK);
}
