$ ======================================================================
$ 
$   TOPPERS/ASP Kernel
$       Toyohashi Open Platform for Embedded Real-Time Systems/
$       Advanced Standard Profile Kernel
$ 
$   Copyright (C) 2007 by TAKAGI Nobuhisa
$   Copyright (C) 2007-2012 by Embedded and Real-Time Systems Laboratory
$               Graduate School of Information Science, Nagoya Univ., JAPAN
$  
$   �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
$   �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
$   �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
$   (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
$       ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
$       ����������˴ޤޤ�Ƥ��뤳�ȡ�
$   (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
$       �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
$       �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
$       ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
$   (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
$       �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
$       �ȡ�
$     (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
$         �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
$     (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
$         ��𤹤뤳�ȡ�
$   (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
$       ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
$       �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
$       ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
$       ���դ��뤳�ȡ�
$  
$   �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
$   ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
$   ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
$   �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
$   ����Ǥ�����ʤ���
$ 
$   $Id: kernel.tf 2426 2012-11-11 08:40:51Z ertl-hiro $
$  
$ =====================================================================

$ =====================================================================
$ AID_XXX�ν���
$ =====================================================================

$num_atskid = 0$
$FOREACH i ATSK.ORDER_LIST$
	$num_atskid = num_atskid + ATSK.NOTSK[i]$
$END$
$num_tskid = LENGTH(TSK.ID_LIST) + num_atskid$

$num_asemid = 0$
$FOREACH i ASEM.ORDER_LIST$
	$num_asemid = num_asemid + ASEM.NOSEM[i]$
$END$
$num_semid = LENGTH(SEM.ID_LIST) + num_asemid$

$num_aflgid = 0$
$FOREACH i AFLG.ORDER_LIST$
	$num_aflgid = num_aflgid + AFLG.NOFLG[i]$
$END$
$num_flgid = LENGTH(FLG.ID_LIST) + num_aflgid$

$num_adtqid = 0$
$FOREACH i ADTQ.ORDER_LIST$
	$num_adtqid = num_adtqid + ADTQ.NODTQ[i]$
$END$
$num_dtqid = LENGTH(DTQ.ID_LIST) + num_adtqid$

$num_apdqid = 0$
$FOREACH i APDQ.ORDER_LIST$
	$num_apdqid = num_apdqid + APDQ.NOPDQ[i]$
$END$
$num_pdqid = LENGTH(PDQ.ID_LIST) + num_apdqid$

$num_ambxid = 0$
$FOREACH i AMBX.ORDER_LIST$
	$num_ambxid = num_ambxid + AMBX.NOMBX[i]$
$END$
$num_mbxid = LENGTH(MBX.ID_LIST) + num_ambxid$

$num_ampfid = 0$
$FOREACH i AMPF.ORDER_LIST$
	$num_ampfid = num_ampfid + AMPF.NOMPF[i]$
$END$
$num_mpfid = LENGTH(MPF.ID_LIST) + num_ampfid$

$num_acycid = 0$
$FOREACH i ACYC.ORDER_LIST$
	$num_acycid = num_acycid + ACYC.NOCYC[i]$
$END$
$num_cycid = LENGTH(CYC.ID_LIST) + num_acycid$

$num_aalmid = 0$
$FOREACH i AALM.ORDER_LIST$
	$num_aalmid = num_aalmid + AALM.NOALM[i]$
$END$
$num_almid = LENGTH(ALM.ID_LIST) + num_aalmid$

$num_aisrid = 0$
$FOREACH i AISR.ORDER_LIST$
	$num_aisrid = num_aisrid + AISR.NOISR[i]$
$END$
$num_isrid = num_aisrid$
$num_isr = LENGTH(ISR.ORDER_LIST) + num_aisrid$

$ =====================================================================
$ kernel_cfg.h������
$ =====================================================================

$FILE "kernel_cfg.h"$
/* kernel_cfg.h */$NL$
#ifndef TOPPERS_KERNEL_CFG_H$NL$
#define TOPPERS_KERNEL_CFG_H$NL$
$NL$
#define TNUM_TSKID	$num_tskid$$NL$
#define TNUM_SEMID	$num_semid$$NL$
#define TNUM_FLGID	$num_flgid$$NL$
#define TNUM_DTQID	$num_dtqid$$NL$
#define TNUM_PDQID	$num_pdqid$$NL$
#define TNUM_MBXID	$num_mbxid$$NL$
#define TNUM_MPFID	$num_mpfid$$NL$
#define TNUM_CYCID	$num_cycid$$NL$
#define TNUM_ALMID	$num_almid$$NL$
#define TNUM_ISRID	$num_isrid$$NL$
$NL$
$FOREACH id TSK.ID_LIST$
	#define $id$	$+id$$NL$
$END$
$FOREACH id SEM.ID_LIST$
	#define $id$	$+id$$NL$
$END$
$FOREACH id FLG.ID_LIST$
	#define $id$	$+id$$NL$
$END$
$FOREACH id DTQ.ID_LIST$
	#define $id$	$+id$$NL$
$END$
$FOREACH id PDQ.ID_LIST$
	#define $id$	$+id$$NL$
$END$
$FOREACH id MBX.ID_LIST$
	#define $id$	$+id$$NL$
$END$
$FOREACH id MPF.ID_LIST$
	#define $id$	$+id$$NL$
$END$
$FOREACH id CYC.ID_LIST$
	#define $id$	$+id$$NL$
$END$
$FOREACH id ALM.ID_LIST$
	#define $id$	$+id$$NL$
$END$
$NL$
#endif /* TOPPERS_KERNEL_CFG_H */$NL$

$ =====================================================================
$ kernel_cfg.c������
$ =====================================================================

$FILE "kernel_cfg.c"$
/* kernel_cfg.c */$NL$
#include "kernel/kernel_int.h"$NL$
#include "kernel_cfg.h"$NL$
$NL$
#if TKERNEL_PRID != 0x07u$NL$
#error The kernel does not match this configuration file.$NL$
#endif$NL$
$NL$

$ 
$  ���󥯥롼�ɥǥ��쥯�ƥ��֡�#include��
$ 
/*$NL$
$SPC$*  Include Directives (#include)$NL$
$SPC$*/$NL$
$NL$
$INCLUDES$
$NL$

$ 
$  ���֥������Ȥ�ID�ֹ���ݻ������ѿ�
$ 
$IF USE_EXTERNAL_ID$
	/*$NL$
	$SPC$*  Variables for Object ID$NL$
	$SPC$*/$NL$
	$NL$
	$FOREACH id TSK.ID_LIST$
		const ID $id$_id$SPC$=$SPC$$+id$;$NL$
	$END$
	$FOREACH id SEM.ID_LIST$
		const ID $id$_id$SPC$=$SPC$$+id$;$NL$
	$END$
	$FOREACH id FLG.ID_LIST$
		const ID $id$_id$SPC$=$SPC$$+id$;$NL$
	$END$
	$FOREACH id DTQ.ID_LIST$
		const ID $id$_id$SPC$=$SPC$$+id$;$NL$
	$END$
	$FOREACH id PDQ.ID_LIST$
		const ID $id$_id$SPC$=$SPC$$+id$;$NL$
	$END$
	$FOREACH id MBX.ID_LIST$
		const ID $id$_id$SPC$=$SPC$$+id$;$NL$
	$END$
	$FOREACH id MPF.ID_LIST$
		const ID $id$_id$SPC$=$SPC$$+id$;$NL$
	$END$
	$FOREACH id CYC.ID_LIST$
		const ID $id$_id$SPC$=$SPC$$+id$;$NL$
	$END$
	$FOREACH id ALM.ID_LIST$
		const ID $id$_id$SPC$=$SPC$$+id$;$NL$
	$END$
$END$

$ 
$  ������
$ 
/*$NL$
$SPC$*  Task Management Functions$NL$
$SPC$*/$NL$
$NL$

$ ��Ū���������줿��������1�İʾ�¸�ߤ��뤳�ȤΥ����å�
$IF !LENGTH(TSK.ID_LIST)$
	$ERROR$$FORMAT(_("no task is registered"))$$END$
$END$

$ ��Ū���������줿�������ο�
#define TNUM_STSKID	$LENGTH(TSK.ID_LIST)$$NL$
$NL$

$ ������ID�ֹ�κ�����
const ID _kernel_tmax_tskid = (TMIN_TSKID + TNUM_TSKID - 1);$NL$
const ID _kernel_tmax_stskid = (TMIN_TSKID + TNUM_STSKID - 1);$NL$
$NL$

$ ���顼�����å�
$FOREACH tskid TSK.ID_LIST$
$	// tskatr���ʡ�TA_ACT�ϡˤǤʤ�����E_RSATR��
	$IF (TSK.TSKATR[tskid] & ~(TA_ACT|TARGET_TSKATR)) != 0$
		$ERROR TSK.TEXT_LINE[tskid]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "tskatr", TSK.TSKATR[tskid], tskid, "CRE_TSK")$$END$
	$END$

$	// (TMIN_TPRI <= itskpri && itskpri <= TMAX_TPRI)�Ǥʤ�����E_PAR��
	$IF !(TMIN_TPRI <= TSK.ITSKPRI[tskid] && TSK.ITSKPRI[tskid] <= TMAX_TPRI)$
		$ERROR TSK.TEXT_LINE[tskid]$E_PAR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "itskpri", TSK.ITSKPRI[tskid], tskid, "CRE_TSK")$$END$
	$END$

$ 	// texatr����TA_NULL�ˤǤʤ�����E_RSATR��
	$IF LENGTH(TSK.TEXATR[tskid]) && TSK.TEXATR[tskid] != 0$
		$ERROR DEF_TEX.TEXT_LINE[tskid]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "texatr", TSK.TEXATR[tskid], tskid, "DEF_TEX")$$END$
	$END$
$END$

$ �����å��ΰ�������Ȥ���˴ؤ��륨�顼�����å�
$FOREACH tskid TSK.ID_LIST$
$	// stksz��0�����������å�����κǾ��͡�TARGET_MIN_STKSZ�ˤ��⾮��������E_PAR��
	$IF TSK.STKSZ[tskid] == 0 || (TARGET_MIN_STKSZ
									&& TSK.STKSZ[tskid] < TARGET_MIN_STKSZ)$
		$ERROR TSK.TEXT_LINE[tskid]$E_PAR: $FORMAT(_("%1% `%2%\' of `%3%\' in %4% is too small"), "stksz", TSK.STKSZ[tskid], tskid, "CRE_TSK")$$END$
	$END$

$ 	// stksz�������å��ΰ�Υ������Ȥ����������ʤ�����E_PAR��
	$IF !EQ(TSK.STK[tskid], "NULL") && CHECK_STKSZ_ALIGN
							&& (TSK.STKSZ[tskid] & (CHECK_STKSZ_ALIGN - 1))$
		$ERROR TSK.TEXT_LINE[tskid]$E_PAR: $FORMAT(_("%1% `%2%\' of `%3%\' in %4% is not aligned"), "stksz", TSK.STKSZ[tskid], tskid, "CRE_TSK")$$END$
	$END$

	$IF EQ(TSK.STK[tskid],"NULL")$
		static STK_T _kernel_stack_$tskid$[COUNT_STK_T($TSK.STKSZ[tskid]$)];$NL$
		$TSK.TINIB_STKSZ[tskid] = FORMAT("ROUND_STK_T(%1%)", TSK.STKSZ[tskid])$
		$TSK.TINIB_STK[tskid] = CONCAT("_kernel_stack_", tskid)$
	$ELSE$
		$TSK.TINIB_STKSZ[tskid] = TSK.STKSZ[tskid]$
		$TSK.TINIB_STK[tskid] = TSK.STK[tskid]$
	$END$
$END$
$NL$

$ ������������֥�å��������ʥ�������1�İʾ�¸�ߤ����
const TINIB _kernel_tinib_table[TNUM_STSKID] = {$NL$
$JOINEACH tskid TSK.ID_LIST ",\n"$
$	// ������°������ĥ���󡤵�ư���ϡ���ư��ͥ����
	$TAB${
	$SPC$($TSK.TSKATR[tskid]$), (intptr_t)($TSK.EXINF[tskid]$),
	$SPC$((TASK)($TSK.TASK[tskid]$)), INT_PRIORITY($TSK.ITSKPRI[tskid]$),

$	// ���������������ƥ����ȥ֥�å��������å��ΰ�
	$IF USE_TSKINICTXB$
		$GENERATE_TSKINICTXB(tskid)$
	$ELSE$
		$SPC$$TSK.TINIB_STKSZ[tskid]$, $TSK.TINIB_STK[tskid]$,
	$END$

$	// �������㳰�����롼�����°���ȵ�ư����
	$SPC$($ALT(TSK.TEXATR[tskid],"TA_NULL")$), ($ALT(TSK.TEXRTN[tskid],"NULL")$) }
$END$$NL$
};$NL$
$NL$

$ ưŪ�����������ѤΥ�����������֥�å�������
$IF num_atskid > 0$
	TINIB _kernel_atinib_table[$num_atskid$];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(TINIB, _kernel_atinib_table);$NL$
$END$$NL$

$ �����������֥�å�������
TCB _kernel_tcb_table[TNUM_TSKID];$NL$
$NL$

$ ��������������ơ��֥������
const ID _kernel_torder_table[TNUM_STSKID] = {$NL$
$TAB$$JOINEACH tskid TSK.ORDER_LIST ", "$$tskid$$END$$NL$
};$NL$
$NL$

$ 
$  ���ޥե�
$ 
/*$NL$
$SPC$*  Semaphore Functions$NL$
$SPC$*/$NL$
$NL$

$ ��Ū���������줿���ޥե��ο�
#define TNUM_SSEMID	$LENGTH(SEM.ID_LIST)$$NL$
$NL$

$ ���ޥե�ID�ֹ�κ�����
const ID _kernel_tmax_semid = (TMIN_SEMID + TNUM_SEMID - 1);$NL$
const ID _kernel_tmax_ssemid = (TMIN_SEMID + TNUM_SSEMID - 1);$NL$
$NL$

$ ���ޥե�������֥�å�������
$IF LENGTH(SEM.ID_LIST)$
	const SEMINIB _kernel_seminib_table[TNUM_SSEMID] = {$NL$
	$JOINEACH semid SEM.ID_LIST ",\n"$
$		// sematr���ʡ�TA_TPRI�ϡˤǤʤ�����E_RSATR��
		$IF (SEM.SEMATR[semid] & ~TA_TPRI) != 0$
			$ERROR SEM.TEXT_LINE[semid]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "sematr", SEM.SEMATR[semid], semid, "CRE_SEM")$$END$
		$END$

$		// (0 <= isemcnt && isemcnt <= maxsem)�Ǥʤ�����E_PAR��
		$IF !(0 <= SEM.ISEMCNT[semid] && SEM.ISEMCNT[semid] <= SEM.MAXSEM[semid])$
			$ERROR SEM.TEXT_LINE[semid]$E_PAR: $FORMAT(_("too large %1% `%2%\' of `%3%\' in %4%"), "isemcnt", SEM.ISEMCNT[semid], semid, "CRE_SEM")$$END$
		$END$

$		// (1 <= maxsem && maxsem <= TMAX_MAXSEM)�Ǥʤ�����E_PAR��
		$IF !(1 <= SEM.MAXSEM[semid] && SEM.MAXSEM[semid] <= TMAX_MAXSEM)$
			$ERROR SEM.TEXT_LINE[semid]$E_PAR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "maxsem", SEM.MAXSEM[semid], semid, "CRE_SEM")$$END$
		$END$

$		// ���ޥե�������֥�å�
		$TAB${ ($SEM.SEMATR[semid]$), ($SEM.ISEMCNT[semid]$), ($SEM.MAXSEM[semid]$) }
	$END$$NL$
	};$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(const SEMINIB, _kernel_seminib_table);$NL$
$END$$NL$

$ ưŪ�������ޥե��ѤΥ��ޥե�������֥�å�������
$IF num_asemid > 0$
	SEMINIB _kernel_aseminib_table[$num_asemid$];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(SEMINIB, _kernel_aseminib_table);$NL$
$END$$NL$

$ ���ޥե������֥�å�������
$IF num_semid$
	SEMCB _kernel_semcb_table[TNUM_SEMID];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(SEMCB, _kernel_semcb_table);$NL$
$END$$NL$

$ 
$  ���٥�ȥե饰
$ 
/*$NL$
$SPC$*  Eventflag Functions$NL$
$SPC$*/$NL$
$NL$

$ ��Ū���������줿���٥�ȥե饰�ο�
#define TNUM_SFLGID	$LENGTH(FLG.ID_LIST)$$NL$
$NL$

$ ���٥�ȥե饰ID�ֹ�κ�����
const ID _kernel_tmax_flgid = (TMIN_FLGID + TNUM_FLGID - 1);$NL$
const ID _kernel_tmax_sflgid = (TMIN_FLGID + TNUM_SFLGID - 1);$NL$
$NL$

$ ���٥�ȥե饰������֥�å�������
$IF LENGTH(FLG.ID_LIST)$
	const FLGINIB _kernel_flginib_table[TNUM_SFLGID] = {$NL$
	$JOINEACH flgid FLG.ID_LIST ",\n"$
$		// flgatr���ʡ�TA_TPRI�ϡá�TA_WMUL�ϡá�TA_CLR�ϡˤǤʤ�����E_RSATR��
		$IF (FLG.FLGATR[flgid] & ~(TA_TPRI|TA_WMUL|TA_CLR)) != 0$
			$ERROR FLG.TEXT_LINE[flgid]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "flgatr", FLG.FLGATR[flgid], flgid, "CRE_FLG")$$END$
		$END$

$		// ���٥�ȥե饰������֥�å�
		$TAB${ ($FLG.FLGATR[flgid]$), ($FLG.IFLGPTN[flgid]$) }
	$END$$NL$
	};$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(const FLGINIB, _kernel_flginib_table);$NL$
$END$$NL$

$ ưŪ�������٥�ȥե饰�ѤΥ��٥�ȥե饰������֥�å�������
$IF num_aflgid > 0$
	FLGINIB _kernel_aflginib_table[$num_aflgid$];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(FLGINIB, _kernel_aflginib_table);$NL$
$END$$NL$

$ ���٥�ȥե饰�����֥�å�������
$IF num_flgid$
	FLGCB _kernel_flgcb_table[TNUM_FLGID];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(FLGCB, _kernel_flgcb_table);$NL$
$END$$NL$

$ 
$  �ǡ������塼
$ 
/*$NL$
$SPC$*  Dataqueue Functions$NL$
$SPC$*/$NL$
$NL$

$ ��Ū���������줿�ǡ������塼�ο�
#define TNUM_SDTQID	$LENGTH(DTQ.ID_LIST)$$NL$
$NL$

$ �ǡ������塼ID�ֹ�κ�����
const ID _kernel_tmax_dtqid = (TMIN_DTQID + TNUM_DTQID - 1);$NL$
const ID _kernel_tmax_sdtqid = (TMIN_DTQID + TNUM_SDTQID - 1);$NL$
$NL$

$IF LENGTH(DTQ.ID_LIST)$
	$FOREACH dtqid DTQ.ID_LIST$
$		// dtqatr���ʡ�TA_TPRI�ϡˤǤʤ�����E_RSATR��
		$IF (DTQ.DTQATR[dtqid] & ~TA_TPRI) != 0$
			$ERROR DTQ.TEXT_LINE[dtqid]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "dtqatr", DTQ.DTQATR[dtqid], dtqid, "CRE_DTQ")$$END$
		$END$

$		// dtqmb��NULL�Ǥʤ�����E_NOSPT��
		$IF !EQ(DTQ.DTQMB[dtqid], "NULL")$
			$ERROR DTQ.TEXT_LINE[dtqid]$E_NOSPT: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "dtqmb", DTQ.DTQMB[dtqid], dtqid, "CRE_DTQ")$$END$
		$END$

$		// �ǡ������塼�����ΰ�
		$IF DTQ.DTQCNT[dtqid]$
			static DTQMB _kernel_dtqmb_$dtqid$[$DTQ.DTQCNT[dtqid]$];$NL$
		$END$
	$END$

$	// �ǡ������塼������֥�å�������
	const DTQINIB _kernel_dtqinib_table[TNUM_SDTQID] = {$NL$
	$JOINEACH dtqid DTQ.ID_LIST ",\n"$
		$TAB${ ($DTQ.DTQATR[dtqid]$), ($DTQ.DTQCNT[dtqid]$), $IF DTQ.DTQCNT[dtqid]$(_kernel_dtqmb_$dtqid$)$ELSE$NULL$END$ }
	$END$$NL$
	};$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(const DTQINIB, _kernel_dtqinib_table);$NL$
$END$$NL$

$ ưŪ�����ǡ������塼�ѤΥǡ������塼������֥�å�������
$IF num_adtqid > 0$
	DTQINIB _kernel_adtqinib_table[$num_adtqid$];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(DTQINIB, _kernel_adtqinib_table);$NL$
$END$$NL$

$ �ǡ������塼�����֥�å�������
$IF num_dtqid$
	DTQCB _kernel_dtqcb_table[TNUM_DTQID];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(DTQCB, _kernel_dtqcb_table);$NL$
$END$$NL$

$ 
$  ͥ���٥ǡ������塼
$ 
/*$NL$
$SPC$*  Priority Dataqueue Functions$NL$
$SPC$*/$NL$
$NL$

$ ��Ū���������줿ͥ���٥ǡ������塼�ο�
#define TNUM_SPDQID	$LENGTH(PDQ.ID_LIST)$$NL$
$NL$

$ ͥ���٥ǡ������塼ID�ֹ�κ�����
const ID _kernel_tmax_pdqid = (TMIN_PDQID + TNUM_PDQID - 1);$NL$
const ID _kernel_tmax_spdqid = (TMIN_PDQID + TNUM_SPDQID - 1);$NL$
$NL$

$IF LENGTH(PDQ.ID_LIST)$
	$FOREACH pdqid PDQ.ID_LIST$
$		// pdqatr���ʡ�TA_TPRI�ϡˤǤʤ�����E_RSATR��
		$IF (PDQ.PDQATR[pdqid] & ~TA_TPRI) != 0$
			$ERROR PDQ.TEXT_LINE[pdqid]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "pdqatr", PDQ.PDQATR[pdqid], pdqid, "CRE_PDQ")$$END$
		$END$

$		// (TMIN_DPRI <= maxdpri && maxdpri <= TMAX_DPRI)�Ǥʤ�����E_PAR��
		$IF !(TMIN_DPRI <= PDQ.MAXDPRI[pdqid] && PDQ.MAXDPRI[pdqid] <= TMAX_DPRI)$
			$ERROR PDQ.TEXT_LINE[pdqid]$E_PAR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "maxdpri", PDQ.MAXDPRI[pdqid], pdqid, "CRE_PDQ")$$END$
		$END$

$		// pdqmb��NULL�Ǥʤ�����E_NOSPT��
		$IF !EQ(PDQ.PDQMB[pdqid], "NULL")$
			$ERROR PDQ.TEXT_LINE[pdqid]$E_NOSPT: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "pdqmb", PDQ.PDQMB[pdqid], pdqid, "CRE_PDQ")$$END$
		$END$

$		// ͥ���٥ǡ������塼�����ΰ�
		$IF PDQ.PDQCNT[pdqid]$
			static PDQMB _kernel_pdqmb_$pdqid$[$PDQ.PDQCNT[pdqid]$];$NL$
		$END$
	$END$

$	// ͥ���٥ǡ������塼������֥�å�������
	const PDQINIB _kernel_pdqinib_table[TNUM_SPDQID] = {$NL$
	$JOINEACH pdqid PDQ.ID_LIST ",\n"$
		$TAB${ ($PDQ.PDQATR[pdqid]$), ($PDQ.PDQCNT[pdqid]$), ($PDQ.MAXDPRI[pdqid]$), $IF PDQ.PDQCNT[pdqid]$(_kernel_pdqmb_$pdqid$)$ELSE$NULL$END$ }
	$END$$NL$
	};$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(const PDQINIB, _kernel_pdqinib_table);$NL$
$END$$NL$

$ ưŪ����ͥ���٥ǡ������塼�Ѥ�ͥ���٥ǡ������塼������֥�å�������
$IF num_apdqid > 0$
	PDQINIB _kernel_apdqinib_table[$num_apdqid$];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(PDQINIB, _kernel_apdqinib_table);$NL$
$END$$NL$

$ ͥ���٥ǡ������塼�����֥�å�������
$IF num_pdqid$
	PDQCB _kernel_pdqcb_table[TNUM_PDQID];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(PDQCB, _kernel_pdqcb_table);$NL$
$END$$NL$

$ 
$  �᡼��ܥå���
$ 
/*$NL$
$SPC$*  Mailbox Functions$NL$
$SPC$*/$NL$
$NL$

$ ��Ū���������줿�᡼��ܥå����ο�
#define TNUM_SMBXID	$LENGTH(MBX.ID_LIST)$$NL$
$NL$

$ �᡼��ܥå���ID�ֹ�κ�����
const ID _kernel_tmax_mbxid = (TMIN_MBXID + TNUM_MBXID - 1);$NL$
const ID _kernel_tmax_smbxid = (TMIN_MBXID + TNUM_SMBXID - 1);$NL$
$NL$

$ �᡼��ܥå���������֥�å�������
$IF LENGTH(MBX.ID_LIST)$
	const MBXINIB _kernel_mbxinib_table[TNUM_SMBXID] = {$NL$
	$JOINEACH mbxid MBX.ID_LIST ",\n"$
$		// mbxatr���ʡ�TA_TPRI�ϡá�TA_MPRI�ϡˤǤʤ�����E_RSATR��
		$IF (MBX.MBXATR[mbxid] & ~(TA_TPRI|TA_MPRI)) != 0$
			$ERROR MBX.TEXT_LINE[mbxid]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "mbxatr", MBX.MBXATR[mbxid], mbxid, "CRE_MBX")$$END$
		$END$

$		// (TMIN_MPRI <= maxmpri && maxmpri <= TMAX_MPRI)�Ǥʤ�����E_PAR��
		$IF !(TMIN_MPRI <= MBX.MAXMPRI[mbxid] && MBX.MAXMPRI[mbxid] <= TMAX_MPRI)$
			$ERROR MBX.TEXT_LINE[mbxid]$E_PAR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "maxmpri", MBX.MAXMPRI[mbxid], mbxid, "CRE_MBX")$$END$
		$END$

$		// mprihd��NULL�Ǥʤ�����E_NOSPT��
		$IF !EQ(MBX.MPRIHD[mbxid], "NULL")$
			$ERROR MBX.TEXT_LINE[mbxid]$E_NOSPT: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "mprihd", MBX.MPRIHD[mbxid], mbxid, "CRE_MBX")$$END$
		$END$

$		// �᡼��ܥå���������֥�å�
		$TAB${ ($MBX.MBXATR[mbxid]$), ($MBX.MAXMPRI[mbxid]$) }
	$END$$NL$
	};$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(const MBXINIB, _kernel_mbxinib_table);$NL$
$END$$NL$

$ ưŪ�����᡼��ܥå����ѤΥ᡼��ܥå���������֥�å�������
$IF num_ambxid > 0$
	MBXINIB _kernel_ambxinib_table[$num_ambxid$];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(MBXINIB, _kernel_ambxinib_table);$NL$
$END$$NL$

$ �᡼��ܥå��������֥�å�������
$IF num_mbxid$
	MBXCB _kernel_mbxcb_table[TNUM_MBXID];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(MBXCB, _kernel_mbxcb_table);$NL$
$END$$NL$

$ 
$  ����Ĺ����ס���
$ 
/*$NL$
$SPC$*  Fixed-sized Memorypool Functions$NL$
$SPC$*/$NL$
$NL$

$ ��Ū���������줿����Ĺ����ס���ο�
#define TNUM_SMPFID	$LENGTH(MPF.ID_LIST)$$NL$
$NL$

$ ����Ĺ����ס���ID�ֹ�κ�����
const ID _kernel_tmax_mpfid = (TMIN_MPFID + TNUM_MPFID - 1);$NL$
const ID _kernel_tmax_smpfid = (TMIN_MPFID + TNUM_SMPFID - 1);$NL$
$NL$

$IF LENGTH(MPF.ID_LIST)$
	$FOREACH mpfid MPF.ID_LIST$
$		// mpfatr���ʡ�TA_TPRI�ϡˤǤʤ�����E_RSATR��
		$IF (MPF.MPFATR[mpfid] & ~TA_TPRI) != 0$
			$ERROR MPF.TEXT_LINE[mpfid]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "mpfatr", MPF.MPFATR[mpfid], mpfid, "CRE_MPF")$$END$
		$END$

$		// blkcnt��0�ξ���E_PAR��
		$IF MPF.BLKCNT[mpfid] == 0$
			$ERROR MPF.TEXT_LINE[mpfid]$E_PAR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "blkcnt", MPF.BLKCNT[mpfid], mpfid, "CRE_MPF")$$END$
		$END$

$		// blksz��0�ξ���E_PAR��
		$IF MPF.BLKSZ[mpfid] == 0$
			$ERROR MPF.TEXT_LINE[mpfid]$E_PAR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "blksz", MPF.BLKSZ[mpfid], mpfid, "CRE_MPF")$$END$
		$END$

$		// ����Ĺ����ס����ΰ�
		$IF EQ(MPF.MPF[mpfid], "NULL")$
			static MPF_T _kernel_mpf_$mpfid$[($MPF.BLKCNT[mpfid]$) * COUNT_MPF_T($MPF.BLKSZ[mpfid]$)];$NL$
		$END$

$		// mpfmb��NULL�Ǥʤ�����E_NOSPT��
		$IF !EQ(MPF.MPFMB[mpfid], "NULL")$
			$ERROR MPF.TEXT_LINE[mpfid]$E_NOSPT: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "mpfmb", MPF.MPFMB[mpfid], mpfid, "CRE_MPF")$$END$
		$END$

$		// ����Ĺ����ס�������ΰ�
		static MPFMB _kernel_mpfmb_$mpfid$[$MPF.BLKCNT[mpfid]$];$NL$
	$END$

$	// ����Ĺ����ס��������֥�å�������
	const MPFINIB _kernel_mpfinib_table[TNUM_SMPFID] = {$NL$
	$JOINEACH mpfid MPF.ID_LIST ",\n"$
		$TAB${ ($MPF.MPFATR[mpfid]$), ($MPF.BLKCNT[mpfid]$), ROUND_MPF_T($MPF.BLKSZ[mpfid]$), $IF EQ(MPF.MPF[mpfid],"NULL")$(_kernel_mpf_$mpfid$)$ELSE$($MPF.MPF[mpfid]$)$END$, (_kernel_mpfmb_$mpfid$) }
	$END$$NL$
	};$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(const MPFINIB, _kernel_mpfinib_table);$NL$
$END$$NL$

$ ưŪ��������Ĺ����ס����Ѥθ���Ĺ����ס��������֥�å�������
$IF num_ampfid > 0$
	MPFINIB _kernel_ampfinib_table[$num_ampfid$];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(MPFINIB, _kernel_ampfinib_table);$NL$
$END$$NL$

$ ����Ĺ����ס�������֥�å�������
$IF num_mpfid$
	MPFCB _kernel_mpfcb_table[TNUM_MPFID];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(MPFCB, _kernel_mpfcb_table);$NL$
$END$$NL$

$ 
$  �����ϥ�ɥ�
$ 
/*$NL$
$SPC$*  Cyclic Handler Functions$NL$
$SPC$*/$NL$
$NL$

$ ��Ū���������줿�����ϥ�ɥ�ο�
#define TNUM_SCYCID	$LENGTH(CYC.ID_LIST)$$NL$
$NL$

$ �����ϥ�ɥ�ID�ֹ�κ�����
const ID _kernel_tmax_cycid = (TMIN_CYCID + TNUM_CYCID - 1);$NL$
const ID _kernel_tmax_scycid = (TMIN_CYCID + TNUM_SCYCID - 1);$NL$
$NL$

$ �����ϥ�ɥ������ơ��֥������
$IF LENGTH(CYC.ID_LIST)$
	const CYCINIB _kernel_cycinib_table[TNUM_SCYCID] = {$NL$
	$JOINEACH cycid CYC.ID_LIST ",\n"$
$		// cycatr���ʡ�TA_STA�ϡˤǤʤ�����E_RSATR��
		$IF (CYC.CYCATR[cycid] & ~TA_STA) != 0$
			$ERROR CYC.TEXT_LINE[cycid]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "cycatr", CYC.CYCATR[cycid], cycid, "CRE_CYC")$$END$
		$END$

$		// (0 < cyctim && cyctim <= TMAX_RELTIM)�Ǥʤ�����E_PAR��
		$IF !(0 < CYC.CYCTIM[cycid] && CYC.CYCTIM[cycid] <= TMAX_RELTIM)$
			$ERROR CYC.TEXT_LINE[cycid]$E_PAR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "cyctim", CYC.CYCTIM[cycid], cycid, "CRE_CYC")$$END$
		$END$

$		// (0 <= cycphs && cycphs <= TMAX_RELTIM)�Ǥʤ�����E_PAR��
		$IF !(0 <= CYC.CYCPHS[cycid] && CYC.CYCPHS[cycid] <= TMAX_RELTIM)$
			$ERROR CYC.TEXT_LINE[cycid]$E_PAR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "cycphs", CYC.CYCPHS[cycid], cycid, "CRE_CYC")$$END$
		$END$

$		// �ٹ�cycatr��TA_STA�����ꤵ��Ƥ��ơ�(cycphs == 0)�ξ��
		$IF (CYC.CYCATR[cycid] & TA_STA) != 0 && CYC.CYCPHS[cycid] == 0$
			$WARNING CYC.TEXT_LINE[cycid]$$FORMAT(_("%1% is not recommended when %2% is set to %3% in %4%"), "cycphs==0", "TA_STA", "cycatr", "CRE_CYC")$$END$
		$END$

$		// �����ϥ�ɥ������֥�å�
		$TAB${ ($CYC.CYCATR[cycid]$), (intptr_t)($CYC.EXINF[cycid]$), ($CYC.CYCHDR[cycid]$), ($CYC.CYCTIM[cycid]$), ($CYC.CYCPHS[cycid]$) }
	$END$$NL$
	};$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(const CYCINIB, _kernel_cycinib_table);$NL$
$END$$NL$

$ ưŪ���������ϥ�ɥ��Ѥμ����ϥ�ɥ������֥�å�������
$IF num_acycid > 0$
	CYCINIB _kernel_acycinib_table[$num_acycid$];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(CYCINIB, _kernel_acycinib_table);$NL$
$END$$NL$

$ �����ϥ�ɥ�����֥�å�
$IF num_cycid$
	CYCCB _kernel_cyccb_table[TNUM_CYCID];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(CYCCB, _kernel_cyccb_table);$NL$
$END$$NL$

$ 
$  ���顼��ϥ�ɥ�
$ 
/*$NL$
$SPC$*  Alarm Handler Functions$NL$
$SPC$*/$NL$
$NL$

$ ��Ū���������줿���顼��ϥ�ɥ�ο�
#define TNUM_SALMID	$LENGTH(ALM.ID_LIST)$$NL$
$NL$

$ ���顼��ϥ�ɥ�ID�ֹ�κ�����
const ID _kernel_tmax_almid = (TMIN_ALMID + TNUM_ALMID - 1);$NL$
const ID _kernel_tmax_salmid = (TMIN_ALMID + TNUM_SALMID - 1);$NL$
$NL$

$ ���顼��ϥ�ɥ������֥�å�������
$IF LENGTH(ALM.ID_LIST)$
	const ALMINIB _kernel_alminib_table[TNUM_SALMID] = {$NL$
	$JOINEACH almid ALM.ID_LIST ",\n"$
$		// almatr����TA_NULL�ˤǤʤ�����E_RSATR��
		$IF ALM.ALMATR[almid] != 0$
			$ERROR ALM.TEXT_LINE[almid]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' of `%3%\' in %4%"), "almatr", ALM.ALMATR[almid], almid, "CRE_ALM")$$END$
		$END$

$		// ���顼��ϥ�ɥ������֥�å�
		$TAB${ ($ALM.ALMATR[almid]$), (intptr_t)($ALM.EXINF[almid]$), ($ALM.ALMHDR[almid]$) }
	$END$$NL$
	};$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(const ALMINIB, _kernel_alminib_table);$NL$
$END$$NL$

$ ưŪ�������顼��ϥ�ɥ��ѤΥ��顼��ϥ�ɥ������֥�å�������
$IF num_aalmid > 0$
	ALMINIB _kernel_aalminib_table[$num_aalmid$];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(ALMINIB, _kernel_aalminib_table);$NL$
$END$$NL$

$ ���顼��ϥ�ɥ�����֥�å�
$IF num_almid$
	ALMCB _kernel_almcb_table[TNUM_ALMID];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(const ALMINIB, _kernel_alminib_table);$NL$
$END$$NL$

$ 
$  ����ߴ�����ǽ
$ 
/*$NL$
$SPC$*  Interrupt Management Functions$NL$
$SPC$*/$NL$
$NL$

$ ������ֹ�ȳ���ߥϥ�ɥ��ֹ���Ѵ��ơ��֥�κ���
$IF LENGTH(INTNO_ATTISR_VALID) != LENGTH(INHNO_ATTISR_VALID)$
	$ERROR$length of `INTNO_ATTISR_VALID' is different from length of `INHNO_ATTISR_VALID'$END$
$END$
$i = 0$
$FOREACH intno INTNO_ATTISR_VALID$
	$inhno = AT(INHNO_ATTISR_VALID, i)$
	$INHNO[intno] = inhno$
	$INTNO[inhno] = intno$
	$i = i + 1$
$END$

$ ������׵�饤��˴ؤ��륨�顼�����å�
$i = 0$
$FOREACH intno INT.ORDER_LIST$
$	// intno��CFG_INT���Ф��������ֹ�Ȥ����������ʤ�����E_PAR��
	$IF !LENGTH(FIND(INTNO_CFGINT_VALID, INT.INTNO[intno]))$
		$ERROR INT.TEXT_LINE[intno]$E_PAR: $FORMAT(_("illegal %1% `%2%\' in %3%"), "intno", INT.INTNO[intno], "CFG_INT")$$END$
	$END$

$	// intno��CFG_INT�ˤ�ä�����Ѥߤξ���E_OBJ��
	$j = 0$
	$FOREACH intno2 INT.ORDER_LIST$
		$IF INT.INTNO[intno] == INT.INTNO[intno2] && j < i$
			$ERROR INT.TEXT_LINE[intno]$E_OBJ: $FORMAT(_("%1% `%2%\' in %3% is duplicated"), "intno", INT.INTNO[intno], "CFG_INT")$$END$
		$END$
		$j = j + 1$
	$END$

$	// intatr���ʡ�TA_ENAINT�ϡá�TA_EDGE�ϡˤǤʤ�����E_RSATR��
	$IF (INT.INTATR[intno] & ~(TA_ENAINT|TA_EDGE|TARGET_INTATR)) != 0$
		$ERROR INT.TEXT_LINE[intno]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' of %3% `%4%\' in %5%"), "intatr", INT.INTATR[intno], "intno", INT.INTNO[intno], "CFG_INT")$$END$
	$END$

$	// intpri��CFG_INT���Ф�������ͥ���٤Ȥ����������ʤ�����E_PAR��
	$IF !LENGTH(FIND(INTPRI_CFGINT_VALID, INT.INTPRI[intno]))$
		$ERROR INT.TEXT_LINE[intno]$E_PAR: $FORMAT(_("illegal %1% `%2%\' in %3%"), "intpri", INT.INTPRI[intno], "CFG_INT")$$END$
	$END$

$	// �����ͥ�����˸��ꤵ��Ƥ���intno���Ф��ơ�intpri��TMIN_INTPRI
$	// ���⾮�����ͤ����ꤵ�줿����E_OBJ��
	$IF LENGTH(FIND(INTNO_FIX_KERNEL, intno))$
		$IF INT.INTPRI[intno] < TMIN_INTPRI$
			$ERROR INT.TEXT_LINE[intno]$E_OBJ: $FORMAT(_("%1% `%2%\' must not have higher priority than %3%"), "intno", INT.INTNO[intno], "TMIN_INTPRI")$$END$
		$END$
	$END$

$	// �����ͥ�������˸��ꤵ��Ƥ���intno���Ф��ơ�intpri��TMIN_INTPRI
$	// ���⾮�����ͤ����ꤵ��ʤ��ä�����E_OBJ��
	$IF LENGTH(FIND(INTNO_FIX_NONKERNEL, intno))$
		$IF INT.INTPRI[intno] >= TMIN_INTPRI$
			$ERROR INT.TEXT_LINE[intno]$E_OBJ: $FORMAT(_("%1% `%2%\' must have higher priority than %3%"), "intno", INT.INTNO[intno], "TMIN_INTPRI")$$END$
		$END$
	$END$
	$i = i + 1$
$END$

$ ����ߥϥ�ɥ�˴ؤ��륨�顼�����å�
$i = 0$
$FOREACH inhno INH.ORDER_LIST$
$	// inhno��DEF_INH���Ф������ߥϥ�ɥ��ֹ�Ȥ����������ʤ�����E_PAR��
	$IF !LENGTH(FIND(INHNO_DEFINH_VALID, INH.INHNO[inhno]))$
		$ERROR INH.TEXT_LINE[inhno]$E_PAR: $FORMAT(_("illegal %1% `%2%\' in %3%"), "inhno", INH.INHNO[inhno], "DEF_INH")$$END$
	$END$

$	// inhno��DEF_INH�ˤ�ä�����Ѥߤξ���E_OBJ��
	$j = 0$
	$FOREACH inhno2 INH.ORDER_LIST$
		$IF INH.INHNO[inhno] == INH.INHNO[inhno2] && j < i$
			$ERROR INH.TEXT_LINE[inhno]$E_OBJ: $FORMAT(_("%1% `%2%\' in %3% is duplicated"), "inhno", INH.INHNO[inhno], "DEF_INH")$$END$
		$END$
		$j = j + 1$
	$END$

$	// inhatr����TA_NULL�ˤǤʤ�����E_RSATR��
	$IF (INH.INHATR[inhno] & ~TARGET_INHATR) != 0$
		$ERROR INH.TEXT_LINE[inhno]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' of %3% `%4%\' in %5%"), "inhatr", INH.INHATR[inhno], "inhno", INH.INHNO[inhno], "DEF_INH")$$END$
	$END$

$	// �����ͥ�����˸��ꤵ��Ƥ���inhno���Ф��ơ�inhatr��TA_NONKERNEL
$	//�������ꤵ��Ƥ������E_RSATR��
	$IF LENGTH(FIND(INHNO_FIX_KERNEL, inhno))$
		$IF (INH.INHATR[inhno] & TA_NONKERNEL) != 0$
			$ERROR INH.TEXT_LINE[inhno]$E_RSATR: $FORMAT(_("%1% `%2%\' must not be non-kernel interrupt"), "inhno", INH.INHNO[inhno])$$END$
		$END$
	$END$

$	// �����ͥ�������˸��ꤵ��Ƥ���inhno���Ф��ơ�inhatr��TA_NONKERNEL
$	// �����ꤵ��Ƥ��ʤ�����E_RSATR��
	$IF LENGTH(FIND(INHNO_FIX_NONKERNEL, inhno))$
		$IF (INH.INHATR[inhno] & TA_NONKERNEL) == 0$
			$ERROR INH.TEXT_LINE[inhno]$E_RSATR: $FORMAT(_("%1% `%2%\' must be non-kernel interrupt"), "inhno", INH.INHNO[inhno])$$END$
		$END$
	$END$

	$IF LENGTH(INTNO[INH.INHNO[inhno]])$
		$intno = INTNO[INH.INHNO[inhno]]$
$		// inhno���б�����intno���Ф���CFG_INT���ʤ�����E_OBJ��
		$IF !LENGTH(INT.INTNO[intno])$
			$ERROR INH.TEXT_LINE[inhno]$E_OBJ: $FORMAT(_("%1% `%2%\' corresponding to %3% `%4%\' is not configured with %5%"), "intno", INT.INTNO[intno], "inhno", INH.INHNO[inhno], "CFG_INT")$$END$
		$ELSE$
			$IF (INH.INHATR[inhno] & TA_NONKERNEL) == 0$
$				// inhatr��TA_NONKERNEL�����ꤵ��Ƥ��餺��inhno���б�
$				// ����intno���Ф���CFG_INT�����ꤵ�줿�����ͥ���٤�
$				// TMIN_INTPRI���⾮��������E_OBJ��
				$IF INT.INTPRI[intno] < TMIN_INTPRI$
					$ERROR INT.TEXT_LINE[intno]$E_OBJ: $FORMAT(_("%1% `%2%\' configured for %3% `%4%\' is higher than %5%"), "intpri", INT.INTPRI[intno], "inhno", INH.INHNO[inhno], "TMIN_INTPRI")$$END$
				$END$
			$ELSE$
$				// inhatr��TA_NONKERNEL�����ꤵ��Ƥ��ꡤinhno���б�
$				// ����intno���Ф���CFG_INT�����ꤵ�줿�����ͥ���٤�
$				// TMIN_INTPRI�ʾ�Ǥ������E_OBJ��
				$IF INT.INTPRI[intno] >= TMIN_INTPRI$
					$ERROR INT.TEXT_LINE[intno]$E_OBJ: $FORMAT(_("%1% `%2%\' configured for %3% `%4%\' is lower than or equal to %5%"), "intpri", INT.INTPRI[intno], "inhno", INH.INHNO[inhno], "TMIN_INTPRI")$$END$
				$END$
			$END$
		$END$
	$END$
	$i = i + 1$
$END$

$ ����ߥ����ӥ��롼�����ISR�ˤ˴ؤ��륨�顼�����å�
$FOREACH order ISR.ORDER_LIST$
$	// isratr����TA_NULL�ˤǤʤ�����E_RSATR��
	$IF (ISR.ISRATR[order] & ~TARGET_ISRATR) != 0$
		$ERROR ISR.TEXT_LINE[order]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' in %3%"), "isratr", ISR.ISRATR[order], "ATT_ISR")$$END$
	$END$

$	// intno��ATT_ISR���Ф��������ֹ�Ȥ����������ʤ�����E_PAR��
	$IF !LENGTH(FIND(INTNO_ATTISR_VALID, ISR.INTNO[order]))$
		$ERROR ISR.TEXT_LINE[order]$E_PAR: $FORMAT(_("illegal %1% `%2%\' in %3%"), "intno", ISR.INTNO[order], "ATT_ISR")$$END$
	$END$

$	// (TMIN_ISRPRI <= isrpri && isrpri <= TMAX_ISRPRI)�Ǥʤ�����E_PAR��
	$IF !(TMIN_ISRPRI <= ISR.ISRPRI[order] && ISR.ISRPRI[order] <= TMAX_ISRPRI)$
		$ERROR ISR.TEXT_LINE[order]$E_PAR: $FORMAT(_("illegal %1% `%2%\' in %3%"), "isrpri", ISR.ISRPRI[order], "ATT_ISR")$$END$
	$END$
$END$

$FOREACH intno INTNO_ATTISR_VALID$
	$inhno = INHNO[intno]$

$	// ������ֹ�intno���Ф�����Ͽ���줿ISR�Υꥹ�Ȥκ���
	$isr_order_list = {}$
	$FOREACH order ISR.ORDER_LIST$
		$IF ISR.INTNO[order] == intno$
			$isr_order_list = APPEND(isr_order_list, order)$
			$order_for_error = order$
		$END$
	$END$

$	// ������ֹ�intno���Ф�����Ͽ���줿ISR��¸�ߤ�����
	$IF LENGTH(isr_order_list) > 0$
$		// intno���б�����inhno���Ф���DEF_INH���������E_OBJ��
		$IF LENGTH(INH.INHNO[inhno])$
			$ERROR ISR.TEXT_LINE[order_for_error]$E_OBJ: $FORMAT(_("%1% `%2%\' in %3% is duplicated with %4% `%5%\'"), "intno", ISR.INTNO[order_for_error], "ATT_ISR", "inhno", INH.INHNO[inhno])$$END$
		$END$

$		// intno���Ф���CFG_INT���ʤ�����E_OBJ��
		$IF !LENGTH(INT.INTNO[intno])$
			$ERROR ISR.TEXT_LINE[order_for_error]$E_OBJ: $FORMAT(_("%1% `%2%\' is not configured with %3%"), "intno", ISR.INTNO[order_for_error], "CFG_INT")$$END$
		$ELSE$
$			// intno���Ф���CFG_INT�����ꤵ�줿�����ͥ���٤�TMIN_INTPRI
$			// ���⾮��������E_OBJ��
			$IF INT.INTPRI[intno] < TMIN_INTPRI$
				$ERROR INT.TEXT_LINE[intno]$E_OBJ: $FORMAT(_("%1% `%2%\' configured for %3% `%4%\' is higher than %5%"), "intpri", INT.INTPRI[intno], "intno", ISR.INTNO[order_for_error], "TMIN_INTPRI")$$END$
			$END$
		$END$
	$END$
$END$

$ ����ߥ����ӥ��롼�����ISR�˴����Υǡ�����¤
$intno_isr_list = {}$
$FOREACH intno INTNO_ATTISR_VALID$
	$inhno = INHNO[intno]$
	$IF LENGTH(INT.INTNO[intno]) && !LENGTH(INH.INHNO[inhno])$
		$intno_isr_list = APPEND(intno_isr_list, intno)$
	$END$
$END$

$INTNO_ISR = {}$
$i = 0$
$FOREACH intno SORT(intno_isr_list, "INT.INTNO")$
	$INTNO_ISR = APPEND(INTNO_ISR, intno)$
	$ISR_QUEUE_HEADER[intno] = FORMAT("&(_kernel_isr_queue_table[%d])", i)$
	$i = i + 1$
$END$

const uint_t _kernel_tnum_isr_queue = $LENGTH(INTNO_ISR)$;$NL$
$NL$

$IF LENGTH(INTNO_ISR)$
	const ISR_ENTRY _kernel_isr_queue_list[$LENGTH(INTNO_ISR)$] = {$NL$
	$JOINEACH intno INTNO_ISR ",\n"$
		$TAB${ $intno$, $ISR_QUEUE_HEADER[intno]$ }
	$END$$NL$
	};$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(QUEUE, _kernel_isr_queue_table);$NL$
$END$$NL$

$IF LENGTH(INTNO_ISR)$
	QUEUE _kernel_isr_queue_table[$LENGTH(INTNO_ISR)$];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(QUEUE, _kernel_isr_queue_table);$NL$
$END$$NL$

$ ����ߥ����ӥ��롼�����ISR�˸ƽФ��Τ���γ���ߥϥ�ɥ������
$FOREACH intno INTNO_ISR$
	$inhno = INHNO[intno]$

$	// DEF_INH(inhno, { TA_NULL, _kernel_inthdr_<intno> } );
	$INH.INHNO[inhno] = inhno$
	$INH.INHATR[inhno] = VALUE("TA_NULL", 0)$
	$INH.INTHDR[inhno] = CONCAT("_kernel_inthdr_", intno)$
	$INH.ORDER_LIST = APPEND(INH.ORDER_LIST, inhno)$

$	// ISR�Ѥγ���ߥϥ�ɥ�
	void$NL$
	_kernel_inthdr_$intno$(void)$NL$
	{$NL$
	$TAB$i_begin_int($intno$);$NL$
	$TAB$call_isr($ISR_QUEUE_HEADER[intno]$);$NL$
	$TAB$i_end_int($intno$);$NL$
	}$NL$
	$NL$
$END$

$ ��Ū���������줿����ߥ����ӥ��롼����ο�
#define TNUM_SISR	$LENGTH(ISR.ORDER_LIST)$$NL$
#define TNUM_ISR	$LENGTH(ISR.ORDER_LIST) + num_aisrid$$NL$
$NL$

$ ����ߥ����ӥ��롼����ID�ֹ�κ�����
const ID _kernel_tmax_isrid = (TMIN_ISRID + TNUM_ISRID - 1);$NL$
const uint_t _kernel_tnum_sisr = TNUM_SISR;$NL$
$NL$

$ ����ߥ����ӥ��롼���������֥�å�������
$IF LENGTH(ISR.ORDER_LIST)$
	const ISRINIB _kernel_sisrinib_table[TNUM_SISR] = {$NL$
	$JOINEACH order ISR.ORDER_LIST ",\n"$
		$TAB${ ($ISR.ISRATR[order]$), ($ISR.EXINF[order]$), ($ISR.INTNO[order]$), ($ISR_QUEUE_HEADER[ISR.INTNO[order]]$), ($ISR.ISR[order]$), ($ISR.ISRPRI[order]$) }
	$END$$NL$
	};$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(const ISRINIB, _kernel_sisrinib_table);$NL$
$END$
$NL$

$ ưŪ��������ߥ����ӥ��롼�����Ѥγ���ߥ����ӥ��롼���������֥��
$ ��������
$IF num_aisrid > 0$
	ISRINIB _kernel_aisrinib_table[$num_aisrid$];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(ISRINIB, _kernel_aisrinib_table);$NL$
$END$
$NL$

$ ����ߥ����ӥ��롼��������֥�å�������
$IF LENGTH(ISR.ORDER_LIST) || num_aisrid > 0$
	ISRCB _kernel_isrcb_table[TNUM_ISR];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(ISRCB, _kernel_isrcb_table);$NL$
$END$
$NL$

$ 
$  ����ߴ�����ǽ�Τ����ɸ��Ū�ʽ�������������
$ 
$ ����ߥϥ�ɥ�ν������ɬ�פʾ���
$IF !OMIT_INITIALIZE_INTERRUPT || ALT(USE_INHINIB_TABLE,0)$

$ ����ߥϥ�ɥ��
#define TNUM_INHNO	$LENGTH(INH.ORDER_LIST)$$NL$
const uint_t _kernel_tnum_inhno = TNUM_INHNO;$NL$
$NL$
$FOREACH inhno INH.ORDER_LIST$
	$IF (INH.INHATR[inhno] & TA_NONKERNEL) == 0$
		INTHDR_ENTRY($INH.INHNO[inhno]$, $+INH.INHNO[inhno]$, $INH.INTHDR[inhno]$)$NL$
	$END$
$END$
$NL$

$ ����ߥϥ�ɥ������ơ��֥�
$IF LENGTH(INH.ORDER_LIST)$
	const INHINIB _kernel_inhinib_table[TNUM_INHNO] = {$NL$
	$JOINEACH inhno INH.ORDER_LIST ",\n"$
		$IF (INH.INHATR[inhno] & TA_NONKERNEL) == 0$
			$TAB${ ($INH.INHNO[inhno]$), ($INH.INHATR[inhno]$), (FP)(INT_ENTRY($INH.INHNO[inhno]$, $INH.INTHDR[inhno]$)) }
		$ELSE$
			$TAB${ ($INH.INHNO[inhno]$), ($INH.INHATR[inhno]$), (FP)($INH.INTHDR[inhno]$) }
		$END$
	$END$$NL$
	};$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(const INHINIB, _kernel_inhinib_table);$NL$
$END$$NL$
$END$

$ ������׵�饤��ν������ɬ�פʾ���
$IF !OMIT_INITIALIZE_INTERRUPT || ALT(USE_INTINIB_TABLE,0)$

$ ������׵�饤���
#define TNUM_INTNO	$LENGTH(INT.ORDER_LIST)$$NL$
const uint_t _kernel_tnum_intno = TNUM_INTNO;$NL$
$NL$

$ ������׵�饤�������ơ��֥�
$IF LENGTH(INT.ORDER_LIST)$
	const INTINIB _kernel_intinib_table[TNUM_INTNO] = {$NL$
	$JOINEACH intno INT.ORDER_LIST ",\n"$
		$TAB${ ($INT.INTNO[intno]$), ($INT.INTATR[intno]$), ($INT.INTPRI[intno]$) }
	$END$$NL$
	};$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(const INTINIB, _kernel_intinib_table);$NL$
$END$$NL$
$END$

$ 
$  CPU�㳰������ǽ
$ 
/*$NL$
$SPC$*  CPU Exception Management Functions$NL$
$SPC$*/$NL$
$NL$

$ CPU�㳰�ϥ�ɥ�˴ؤ��륨�顼�����å�
$i = 0$
$FOREACH excno EXC.ORDER_LIST$
$	// excno��DEF_EXC���Ф���CPU�㳰�ϥ�ɥ��ֹ�Ȥ����������ʤ�����E_PAR��
	$IF !LENGTH(FIND(EXCNO_DEFEXC_VALID, EXC.EXCNO[excno]))$
		$ERROR EXC.TEXT_LINE[excno]$E_PAR: $FORMAT(_("illegal %1% `%2%\' in %3%"), "excno", EXC.EXCNO[excno], "DEF_EXC")$$END$
	$END$

$	// excno��DEF_EXC�ˤ�ä�����Ѥߤξ���E_OBJ��
	$j = 0$
	$FOREACH excno2 EXC.ORDER_LIST$
		$IF EXC.EXCNO[excno] == EXC.EXCNO[excno2] && j < i$
			$ERROR EXC.TEXT_LINE[excno]$E_OBJ: $FORMAT(_("%1% `%2%\' in %3% is duplicated"), "excno", EXC.EXCNO[excno], "DEF_EXC")$$END$
		$END$
		$j = j + 1$
	$END$

$	// excatr����TA_NULL�ˤǤʤ�����E_RSATR��
	$IF (EXC.EXCATR[excno] & ~TARGET_EXCATR) != 0$
		$ERROR EXC.TEXT_LINE[excno]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' of %3% `%4%\' in %5%"), "excatr", EXC.EXCATR[excno], "excno", EXC.EXCNO[excno], "DEF_EXC")$$END$
	$END$
	$i = i + 1$
$END$

$ CPU�㳰�ϥ�ɥ�Τ����ɸ��Ū�ʽ�������������
$IF !OMIT_INITIALIZE_EXCEPTION$

$ CPU�㳰�ϥ�ɥ��
#define TNUM_EXCNO	$LENGTH(EXC.ORDER_LIST)$$NL$
const uint_t _kernel_tnum_excno = TNUM_EXCNO;$NL$
$NL$
$FOREACH excno EXC.ORDER_LIST$
	EXCHDR_ENTRY($EXC.EXCNO[excno]$, $+EXC.EXCNO[excno]$, $EXC.EXCHDR[excno]$)$NL$
$END$
$NL$

$ CPU�㳰�ϥ�ɥ������ơ��֥�
$IF LENGTH(EXC.ORDER_LIST)$
	const EXCINIB _kernel_excinib_table[TNUM_EXCNO] = {$NL$
	$JOINEACH excno EXC.ORDER_LIST ",\n"$
		$TAB${ ($EXC.EXCNO[excno]$), ($EXC.EXCATR[excno]$), (FP)(EXC_ENTRY($EXC.EXCNO[excno]$, $EXC.EXCHDR[excno]$)) }
	$END$$NL$
	};$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(const EXCINIB, _kernel_excinib_table);$NL$
$END$$NL$
$END$

$ 
$  �󥿥�������ƥ������ѤΥ����å��ΰ�
$ 
/*$NL$
$SPC$*  Stack Area for Non-task Context$NL$
$SPC$*/$NL$
$NL$

$IF !LENGTH(ICS.ORDER_LIST)$
$	// DEF_ICS���ʤ����Υǥե�����ͤ�����
	#ifdef DEFAULT_ISTK$NL$
	$NL$
	#define TOPPERS_ISTKSZ		DEFAULT_ISTKSZ$NL$
	#define TOPPERS_ISTK		DEFAULT_ISTK$NL$
	$NL$
	#else /* DEAULT_ISTK */$NL$
	$NL$
	static STK_T				_kernel_istack[COUNT_STK_T(DEFAULT_ISTKSZ)];$NL$
	#define TOPPERS_ISTKSZ		ROUND_STK_T(DEFAULT_ISTKSZ)$NL$
	#define TOPPERS_ISTK		_kernel_istack$NL$
	$NL$
	#endif /* DEAULT_ISTK */$NL$
$ELSE$

$	// ��ŪAPI��DEF_ICS�פ�ʣ�������E_OBJ��
	$IF LENGTH(ICS.ORDER_LIST) > 1$
		$ERROR$E_OBJ: $FORMAT(_("too many %1%"), "DEF_ICS")$$END$
	$END$

$	// istksz��0�����������å�����κǾ��͡�TARGET_MIN_ISTKSZ�ˤ��⾮��������E_PAR��
	$IF ICS.ISTKSZ[1] == 0 || (TARGET_MIN_ISTKSZ
									&& ICS.ISTKSZ[1] < TARGET_MIN_ISTKSZ)$
		$ERROR ICS.TEXT_LINE[1]$E_PAR: $FORMAT(_("%1% `%2%\' in %3% is too small"), "istksz", ICS.ISTKSZ[1], "DEF_ICS")$$END$
	$END$

$ 	// istksz�������å��ΰ�Υ������Ȥ����������ʤ�����E_PAR��
	$IF !EQ(ICS.ISTK[1], "NULL") && CHECK_STKSZ_ALIGN
							&& (ICS.ISTKSZ[1] & (CHECK_STKSZ_ALIGN - 1))$
		$ERROR ICS.TEXT_LINE[1]$E_PAR: $FORMAT(_("%1% `%2%\' in %3% is not aligned"), "istksz", ICS.ISTKSZ[1], "DEF_ICS")$$END$
	$END$

	$IF EQ(ICS.ISTK[1], "NULL")$
$		// �����å��ΰ�μ�ư���դ�
		static STK_T				_kernel_istack[COUNT_STK_T($ICS.ISTKSZ[1]$)];$NL$
		#define TOPPERS_ISTKSZ		ROUND_STK_T($ICS.ISTKSZ[1]$)$NL$
		#define TOPPERS_ISTK		_kernel_istack$NL$
	$ELSE$
		#define TOPPERS_ISTKSZ		($ICS.ISTKSZ[1]$)$NL$
		#define TOPPERS_ISTK		($ICS.ISTK[1]$)$NL$
	$END$
$END$
$NL$

$ �󥿥�������ƥ������ѤΥ����å��ΰ�
const SIZE		_kernel_istksz = TOPPERS_ISTKSZ;$NL$
STK_T *const	_kernel_istk = TOPPERS_ISTK;$NL$
$NL$
#ifdef TOPPERS_ISTKPT$NL$
STK_T *const	_kernel_istkpt = TOPPERS_ISTKPT(TOPPERS_ISTK, TOPPERS_ISTKSZ);$NL$
#endif /* TOPPERS_ISTKPT */$NL$
$NL$

$ 
$  �����ͥ뤬����դ�������ΰ�
$ 
/*$NL$
$SPC$*  Memory Area Allocated by Kernel$NL$
$SPC$*/$NL$
$NL$

$IF !LENGTH(KMM.ORDER_LIST)$
$	// DEF_KMM���ʤ����Υǥե�����ͤ�����
	#define TOPPERS_KMMSZ		0$NL$
	#define TOPPERS_KMM			NULL$NL$
$ELSE$

$	// ��ŪAPI��DEF_KMM�פ�ʣ�������E_OBJ��
	$IF LENGTH(KMM.ORDER_LIST) > 1$
		$ERROR$E_OBJ: $FORMAT(_("too many %1%"), "DEF_KMM")$$END$
	$END$

$ 	// kmmsz�������ͥ뤬����դ�������ΰ�Υ������Ȥ����������ʤ�����E_PAR��
	$IF !EQ(KMM.KMM[1], "NULL") && CHECK_MB_ALIGN
							&& (KMM.MBSZ[1] & (CHECK_MB_ALIGN - 1))$
		$ERROR KMM.TEXT_LINE[1]$E_PAR: $FORMAT(_("%1% `%2%\' in %3% is not aligned"), "kmmsz", KMM.KMMSZ[1], "DEF_KMM")$$END$
	$END$

	$IF EQ(KMM.KMM[1], "NULL")$
$		// �����ͥ뤬����դ�������ΰ�μ�ư���դ�
		static MB_T					_kernel_memory[TOPPERS_COUNT_SZ($KMM.KMMSZ[1]$, sizeof(MB_T))];$NL$
		#define TOPPERS_KMMSZ		TOPPERS_ROUND_SZ($KMM.KMMSZ[1]$, sizeof(MB_T))$NL$
		#define TOPPERS_KMM			_kernel_memory$NL$
	$ELSE$
		#define TOPPERS_KMMSZ		($KMM.KMMSZ[1]$)$NL$
		#define TOPPERS_KMM			($KMM.KMM[1]$)$NL$
	$END$
$END$
$NL$

$ �����ͥ뤬����դ�������ΰ�
const SIZE		_kernel_kmmsz = TOPPERS_KMMSZ;$NL$
MB_T *const		_kernel_kmm = TOPPERS_KMM;$NL$
$NL$

$ 
$  �����।�٥�ȴ���
$ 
/*$NL$
$SPC$*  Time Event Management$NL$
$SPC$*/$NL$
$NL$
TMEVTN   _kernel_tmevt_heap[TNUM_TSKID + TNUM_CYCID + TNUM_ALMID];$NL$
$NL$

$ 
$  �ƥ⥸�塼��ν�����ؿ�
$ 
/*$NL$
$SPC$*  Module Initialization Function$NL$
$SPC$*/$NL$
$NL$
void$NL$
_kernel_initialize_object(void)$NL$
{$NL$
$TAB$_kernel_initialize_task();$NL$
$IF num_semid$	_kernel_initialize_semaphore();$NL$$END$
$IF num_flgid$	_kernel_initialize_eventflag();$NL$$END$
$IF num_dtqid$	_kernel_initialize_dataqueue();$NL$$END$
$IF num_pdqid$	_kernel_initialize_pridataq();$NL$$END$
$IF num_mbxid$	_kernel_initialize_mailbox();$NL$$END$
$IF num_mpfid$	_kernel_initialize_mempfix();$NL$$END$
$IF num_cycid$	_kernel_initialize_cyclic();$NL$$END$
$IF num_almid$	_kernel_initialize_alarm();$NL$$END$
$TAB$_kernel_initialize_interrupt();$NL$
$IF num_isr$	_kernel_initialize_isr();$NL$$END$
$TAB$_kernel_initialize_exception();$NL$
}$NL$
$NL$

$ 
$  ������롼����μ¹Դؿ�
$ 
/*$NL$
$SPC$*  Initialization Routine$NL$
$SPC$*/$NL$
$NL$
void$NL$
_kernel_call_inirtn(void)$NL$
{$NL$
$FOREACH order INI.ORDER_LIST$
$ 	// iniatr����TA_NULL�ˤǤʤ�����E_RSATR��
	$IF INI.INIATR[order] != 0$
		$ERROR INI.TEXT_LINE[order]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' of %3% `%4%\' in %5%"), "iniatr", INI.INIATR[order], "inirtn", INI.INIRTN[order], "ATT_INI")$$END$
	$END$
	$TAB$((INIRTN)($INI.INIRTN[order]$))((intptr_t)($INI.EXINF[order]$));$NL$
$END$
}$NL$
$NL$

$ 
$  ��λ�����롼����μ¹Դؿ�
$ 
/*$NL$
$SPC$*  Termination Routine$NL$
$SPC$*/$NL$
$NL$
void$NL$
_kernel_call_terrtn(void)$NL$
{$NL$
$FOREACH rorder TER.RORDER_LIST$
$ 	// teratr����TA_NULL�ˤǤʤ�����E_RSATR��
	$IF TER.TERATR[rorder] != 0$
		$ERROR TER.TEXT_LINE[rorder]$E_RSATR: $FORMAT(_("illegal %1% `%2%\' of %3% `%4%\' in %5%"), "teratr", TER.TERATR[rorder], "terrtn", TER.TERRTN[rorder], "ATT_TER")$$END$
	$END$
	$TAB$((TERRTN)($TER.TERRTN[rorder]$))((intptr_t)($TER.EXINF[rorder]$));$NL$
$END$
}$NL$
$NL$
