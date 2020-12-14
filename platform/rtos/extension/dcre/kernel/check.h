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
 *  @(#) $Id: check.h 2412 2012-09-01 04:05:55Z ertl-hiro $
 */

/*
 *		���顼�����å��ѥޥ���
 */

#ifndef TOPPERS_CHECK_H
#define TOPPERS_CHECK_H

/*
 *  ͽ��°�����顼�Υ����å���E_PAR��
 */
#define CHECK_RSATR(atr, valid_atr) do {					\
	if (((atr) & ~(valid_atr)) != 0U) {						\
		ercd = E_RSATR;										\
		goto error_exit;									\
	}														\
} while (false)

/*
 *  ͥ���٤��ϰϤ�Ƚ��
 */
#define VALID_TPRI(tpri)	(TMIN_TPRI <= (tpri) && (tpri) <= TMAX_TPRI)

#define VALID_DPRI(dpri)	(TMIN_DPRI <= (dpri) && (dpri) <= TMAX_DPRI)

#define VALID_MPRI(mpri)	(TMIN_MPRI <= (mpri) && (mpri) <= TMAX_MPRI)

#define VALID_ISRPRI(isrpri) \
				(TMIN_ISRPRI <= (isrpri) && (isrpri) <= TMAX_ISRPRI)

#ifndef VALID_INTPRI_CHGIPM
#define VALID_INTPRI_CHGIPM(intpri) \
				(TMIN_INTPRI <= (intpri) && (intpri) <= TIPM_ENAALL)
#endif /* VALID_INTPRI_CHGIPM */

/*
 *  ������ͥ���٤Υ����å���E_PAR��
 */
#define CHECK_TPRI(tpri) do {								\
	if (!VALID_TPRI(tpri)) {								\
		ercd = E_PAR;										\
		goto error_exit;									\
	}														\
} while (false)

#define CHECK_TPRI_INI(tpri) do {							\
	if (!(VALID_TPRI(tpri) || (tpri) == TPRI_INI)) {		\
		ercd = E_PAR;										\
		goto error_exit;									\
	}														\
} while (false)

#define CHECK_TPRI_SELF(tpri) do {							\
	if (!(VALID_TPRI(tpri) || (tpri) == TPRI_SELF)) {		\
		ercd = E_PAR;										\
		goto error_exit;									\
	}														\
} while (false)

/*
 *  �ǡ���ͥ���٤Υ����å���E_PAR��
 */
#define CHECK_DPRI(dpri) do {								\
	if (!VALID_DPRI(dpri)) {								\
		ercd = E_PAR;										\
		goto error_exit;									\
	}														\
} while (false)

/*
 *  ��å�����ͥ���٤Υ����å���E_PAR��
 */
#define CHECK_MPRI(mpri) do {								\
	if (!VALID_MPRI(mpri)) {								\
		ercd = E_PAR;										\
		goto error_exit;									\
	}														\
} while (false)

/*
 *  ����ߥ����ӥ��롼����ͥ���٤Υ����å���E_PAR��
 */
#define CHECK_ISRPRI(isrpri) do {							\
	if (!VALID_ISRPRI(isrpri)) {							\
		ercd = E_PAR;										\
		goto error_exit;									\
	}														\
} while (false)

/*
 *  �����ॢ���Ȼ����ͤΥ����å���E_PAR��
 */
#define CHECK_TMOUT(tmout) do {								\
	if (!(TMO_FEVR <= (tmout))) {							\
		ercd = E_PAR;										\
		goto error_exit;									\
	}														\
} while (false)

/*
 *  �����ͥ���٤Υ����å���E_PAR��
 */
#define CHECK_INTPRI_CHGIPM(intpri) do {					\
	if (!VALID_INTPRI_CHGIPM(intpri)) {						\
		ercd = E_PAR;										\
		goto error_exit;									\
	}														\
} while (false)

/*
 *  ������ֹ�Υ����å���E_PAR��
 */
#define CHECK_INTNO_CREISR(intno) do {						\
	if (!VALID_INTNO_CREISR(intno)) {						\
		ercd = E_PAR;										\
		goto error_exit;									\
	}														\
} while (false)

#define CHECK_INTNO_DISINT(intno) do {						\
	if (!VALID_INTNO_DISINT(intno)) {						\
		ercd = E_PAR;										\
		goto error_exit;									\
	}														\
} while (false)

/*
 *  ���饤�󤷤Ƥ��뤫��Ƚ��
 */
#define ALIGNED(val, align)		((((uintptr_t)(val)) & ((align) - 1U)) == 0U)

#ifdef CHECK_FUNC_ALIGN
#define FUNC_ALIGNED(func)		ALIGNED(func, CHECK_FUNC_ALIGN)
#else /* CHECK_FUNC_ALIGN */
#define FUNC_ALIGNED(func)		true
#endif /* CHECK_FUNC_ALIGN */

#ifdef CHECK_STKSZ_ALIGN
#define STKSZ_ALIGNED(stksz)	ALIGNED(stksz, CHECK_STKSZ_ALIGN)
#else /* CHECK_STKSZ_ALIGN */
#define STKSZ_ALIGNED(stksz)	true
#endif /* CHECK_STKSZ_ALIGN */

#ifdef CHECK_STACK_ALIGN
#define STACK_ALIGNED(stack)	ALIGNED(stack, CHECK_STACK_ALIGN)
#else /* CHECK_STACK_ALIGN */
#define STACK_ALIGNED(stack)	true
#endif /* CHECK_STACK_ALIGN */

#ifdef CHECK_MPF_ALIGN
#define MPF_ALIGNED(mpf)		ALIGNED(mpf, CHECK_MPF_ALIGN)
#else /* CHECK_MPF_ALIGN */
#define MPF_ALIGNED(mpf)		true
#endif /* CHECK_MPF_ALIGN */

#ifdef CHECK_MB_ALIGN
#define MB_ALIGNED(mb)			ALIGNED(mb, CHECK_MB_ALIGN)
#else /* CHECK_MB_ALIGN */
#define MB_ALIGNED(mb)			true
#endif /* CHECK_MB_ALIGN */

/*
 *  NULL�Ǥʤ����ȤΥ����å�
 */
#ifdef CHECK_FUNC_NONNULL
#define FUNC_NONNULL(func)		((func) != NULL)
#else /* CHECK_FUNC_NONNULL */
#define FUNC_NONNULL(func)		true
#endif /* CHECK_FUNC_NONNULL */

#ifdef CHECK_STACK_NONNULL
#define STACK_NONNULL(stack)	((stack) != NULL)
#else /* CHECK_STACK_NONNULL */
#define STACK_NONNULL(stack)	true
#endif /* CHECK_STACK_NONNULL */

#ifdef CHECK_MPF_NONNULL
#define MPF_NONNULL(mpf)		((mpf) != NULL)
#else /* CHECK_MPF_NONNULL */
#define MPF_NONNULL(mpf)		true
#endif /* CHECK_MPF_NONNULL */

/*
 *  �ؿ�����Ƭ���ϤΥ����å���E_PAR��
 */
#define CHECK_ALIGN_FUNC(func) do {							\
	if (!FUNC_ALIGNED(func)) {								\
		ercd = E_PAR;										\
		goto error_exit;									\
	}														\
} while (false)

#define CHECK_NONNULL_FUNC(func) do {						\
	if (!FUNC_NONNULL(func)) {								\
		ercd = E_PAR;										\
		goto error_exit;									\
	}														\
} while (false)

/*
 *  �����å��������Υ����å���E_PAR��
 */
#define CHECK_ALIGN_STKSZ(stksz) do {						\
	if (!STKSZ_ALIGNED(stksz)) {							\
		ercd = E_PAR;										\
		goto error_exit;									\
	}														\
} while (false)

#ifndef TARGET_MIN_STKSZ
#define TARGET_MIN_STKSZ	1U		/* ̤����ξ���0�Ǥʤ����Ȥ�����å� */
#endif /* TARGET_MIN_STKSZ */

#define CHECK_STKSZ_MIN(stksz) do {							\
	if ((stksz) < TARGET_MIN_STKSZ) {						\
		ercd = E_PAR;										\
		goto error_exit;									\
	}														\
} while (false)

/*
 *  �����å�����Ƭ���ϤΥ����å���E_PAR��
 */
#define CHECK_ALIGN_STACK(stack) do {						\
	if (!STACK_ALIGNED(stack)) {							\
		ercd = E_PAR;										\
		goto error_exit;									\
	}														\
} while (false)

#define CHECK_NONNULL_STACK(stack) do {						\
	if (!STACK_NONNULL(stack)) {							\
		ercd = E_PAR;										\
		goto error_exit;									\
	}														\
} while (false)

/*
 *  ����Ĺ����ס����ΰ����Ƭ���ϤΥ����å���E_PAR��
 */
#define CHECK_ALIGN_MPF(mpf) do {							\
	if (!MPF_ALIGNED(mpf)) {								\
		ercd = E_PAR;										\
		goto error_exit;									\
	}														\
} while (false)

#define CHECK_NONNULL_MPF(mpf) do {							\
	if (!MPF_NONNULL(mpf)) {								\
		ercd = E_PAR;										\
		goto error_exit;									\
	}														\
} while (false)

/*
 *  �����ΰ����Ƭ���ϤΥ����å���E_PAR��
 */
#define CHECK_ALIGN_MB(mb) do {								\
	if (!MB_ALIGNED(mb)) {									\
		ercd = E_PAR;										\
		goto error_exit;									\
	}														\
} while (false)

/*
 *  ����¾�Υѥ�᡼�����顼�Υ����å���E_PAR��
 */
#define CHECK_PAR(exp) do {									\
	if (!(exp)) {											\
		ercd = E_PAR;										\
		goto error_exit;									\
	}														\
} while (false)

/*
 *  ���֥�������ID���ϰϤ�Ƚ��
 */
#define VALID_TSKID(tskid)	(TMIN_TSKID <= (tskid) && (tskid) <= tmax_tskid)
#define VALID_SEMID(semid)	(TMIN_SEMID <= (semid) && (semid) <= tmax_semid)
#define VALID_FLGID(flgid)	(TMIN_FLGID <= (flgid) && (flgid) <= tmax_flgid)
#define VALID_DTQID(dtqid)	(TMIN_DTQID <= (dtqid) && (dtqid) <= tmax_dtqid)
#define VALID_PDQID(pdqid)	(TMIN_PDQID <= (pdqid) && (pdqid) <= tmax_pdqid)
#define VALID_MBXID(mbxid)	(TMIN_MBXID <= (mbxid) && (mbxid) <= tmax_mbxid)
#define VALID_MPFID(mpfid)	(TMIN_MPFID <= (mpfid) && (mpfid) <= tmax_mpfid)
#define VALID_CYCID(cycid)	(TMIN_CYCID <= (cycid) && (cycid) <= tmax_cycid)
#define VALID_ALMID(almid)	(TMIN_ALMID <= (almid) && (almid) <= tmax_almid)
#define VALID_ISRID(isrid)	(TMIN_ISRID <= (isrid) && (isrid) <= tmax_isrid)

/*
 *  ���֥�������ID�Υ����å���E_ID��
 */
#define CHECK_TSKID(tskid) do {								\
	if (!VALID_TSKID(tskid)) {								\
		ercd = E_ID;										\
		goto error_exit;									\
	}														\
} while (false)

#define CHECK_TSKID_SELF(tskid) do {						\
	if (!(VALID_TSKID(tskid) || (tskid) == TSK_SELF)) {		\
		ercd = E_ID;										\
		goto error_exit;									\
	}														\
} while (false)

#define CHECK_SEMID(semid) do {								\
	if (!VALID_SEMID(semid)) {								\
		ercd = E_ID;										\
		goto error_exit;									\
	}														\
} while (false)

#define CHECK_FLGID(flgid) do {								\
	if (!VALID_FLGID(flgid)) {								\
		ercd = E_ID;										\
		goto error_exit;									\
	}														\
} while (false)

#define CHECK_DTQID(dtqid) do {								\
	if (!VALID_DTQID(dtqid)) {								\
		ercd = E_ID;										\
		goto error_exit;									\
	}														\
} while (false)

#define CHECK_PDQID(pdqid) do {								\
	if (!VALID_PDQID(pdqid)) {								\
		ercd = E_ID;										\
		goto error_exit;									\
	}														\
} while (false)

#define CHECK_MBXID(mbxid) do {								\
	if (!VALID_MBXID(mbxid)) {								\
		ercd = E_ID;										\
		goto error_exit;									\
	}														\
} while (false)

#define CHECK_MPFID(mpfid) do {								\
	if (!VALID_MPFID(mpfid)) {								\
		ercd = E_ID;										\
		goto error_exit;									\
	}														\
} while (false)

#define CHECK_CYCID(cycid) do {								\
	if (!VALID_CYCID(cycid)) {								\
		ercd = E_ID;										\
		goto error_exit;									\
	}														\
} while (false)

#define CHECK_ALMID(almid) do {								\
	if (!VALID_ALMID(almid)) {								\
		ercd = E_ID;										\
		goto error_exit;									\
	}														\
} while (false)

#define CHECK_ISRID(isrid) do {								\
	if (!VALID_ISRID(isrid)) {								\
		ercd = E_ID;										\
		goto error_exit;									\
	}														\
} while (false)

/*
 *  �ƽФ�����ƥ����ȤΥ����å���E_CTX��
 */
#define CHECK_TSKCTX() do {									\
	if (sense_context()) {									\
		ercd = E_CTX;										\
		goto error_exit;									\
	}														\
} while (false)

#define CHECK_INTCTX() do {									\
	if (!sense_context()) {									\
		ercd = E_CTX;										\
		goto error_exit;									\
	}														\
} while (false)

/*
 *  �ƽФ�����ƥ����Ȥ�CPU��å����֤Υ����å���E_CTX��
 */
#define CHECK_TSKCTX_UNL() do {								\
	if (sense_context() || t_sense_lock()) {				\
		ercd = E_CTX;										\
		goto error_exit;									\
	}														\
} while (false)

#define CHECK_INTCTX_UNL() do {								\
	if (!sense_context() || i_sense_lock()) {				\
		ercd = E_CTX;										\
		goto error_exit;									\
	}														\
} while (false)

/*
 *  �ǥ����ѥå���α���֤Ǥʤ����Υ����å���E_CTX��
 */
#define CHECK_DISPATCH() do {								\
	if (sense_context() || t_sense_lock() || !dspflg) {		\
		ercd = E_CTX;										\
		goto error_exit;									\
	}														\
} while (false)

/*
 *  ����¾�Υ���ƥ����ȥ��顼�Υ����å���E_CTX��
 */
#define CHECK_CTX(exp) do {									\
	if (!(exp)) {											\
		ercd = E_CTX;										\
		goto error_exit;									\
	}														\
} while (false)

/*
 *  ������������ꤷ�Ƥ��ʤ����Υ����å���E_ILUSE��
 */
#define CHECK_NONSELF(p_tcb) do {							\
	if ((p_tcb) == p_runtsk) {								\
		ercd = E_ILUSE;										\
		goto error_exit;									\
	}														\
} while (false)

/*
 *  ����¾���������ѥ��顼�Υ����å���E_ILUSE��
 */
#define CHECK_ILUSE(exp) do {								\
	if (!(exp)) {											\
		ercd = E_ILUSE;										\
		goto error_exit;									\
	}														\
} while (false)

/*
 *  ̤���ݡ��ȵ�ǽ���顼�Υ����å���E_NOSPT��
 */
#define CHECK_NOSPT(exp) do {								\
	if (!(exp)) {											\
		ercd = E_NOSPT;										\
		goto error_exit;									\
	}														\
} while (false)

/*
 *  ��Ū�ʥ��֥������Ⱦ��֥��顼�Υ����å���E_OBJ��
 */
#define CHECK_OBJ(exp) do {									\
	if (!(exp)) {											\
		ercd = E_OBJ;										\
		goto error_exit;									\
	}														\
} while (false)

#endif /* TOPPERS_CHECK_H */
