/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2010 by Embedded and Real-Time Systems Laboratory
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
 *  $Id: test_rstr1.c 1887 2010-08-06 06:15:19Z ertl-hiro $
 */

/* 
 *		���󥿥����Υƥ���(1)
 *
 * �ڥƥ��Ȥ���Ū��
 *
 *  ���󥿥����δ���Ū�ʿ��񤤡�ras_pri�����ӥ�������ʳ���ư��ˤ�ƥ�
 *  �Ȥ��롥
 *
 * �ڥƥ��ȹ��ܡ�
 *
 *	(A) ���󥿥������������������Ԥ����֤ˤ����ǽ���Τ��륵���ӥ�����
 *      ���ƤӽФ�����硤E_NOSPT���顼�Ȥʤ�
 *		(A-1) slp_tsk
 *		(A-2) tslp_tsk
 *		(A-3) dly_tsk
 *      �� ¾�ˤ⤢�뤬�����������α���
 *	(B) ���󥿥������оݤȤ��ơ�chg_pri��wup_tsk��iwup_tsk��can_wup��
 *	    rel_wai��irel_wai��sus_tsk��rsm_tsk��ƤӽФ�����硤E_NOSPT��
 *	    �顼�Ȥʤ�
 *		(B-1) chg_pri
 *		(B-2) wup_tsk
 *		(B-3) iwup_tsk
 *		(B-4) can_wup
 *		(B-5) rel_wai
 *		(B-6) irel_wai
 *		(B-7) sus_tsk
 *		(B-8) rsm_tsk
 *  (C) rot_rdq��irot_rdq�ϡ��о�ͥ���٤���ļ¹ԤǤ�����֤Υ���������
 *      �ǺǤ�ͥ���̤��⤤�����������󥿥����Ǥ����硤E_NOSPT���顼
 *      �Ȥʤ�
 *		(C-1) rot_rdq��������ư���
 *		(C-2) rot_rdq��E_NOSPT���֤�
 *		(C-3) irot_rdq��������ư���
 *		(C-4) irot_rdq��E_NOSPT���֤�
 *
 * �ڻ��ѥ꥽������
 *
 *	TASK1: ��ͥ���٥��������ᥤ�󥿥������ǽ餫�鵯ư
 *	TASK2: ��ͥ���٥����������󥿥���
 *	TASK3: ��ͥ���٥����������󥿥���
 *	TASK4: ��ͥ���٥����������󥿥���
 *	ALM1:  ���顼��ϥ�ɥ�
 *
 * �ڥƥ��ȥ������󥹡�
 *
 *	== TASK1��ͥ���١����==
 *	1:	act_tsk(TASK2)
 *	== TASK2-1��ͥ���١����==
 *	2:	slp_tsk() -> E_NOSPT						... (A-1)
 *	3:	tslp_tsk(10) -> E_NOSPT						... (A-2)
 *	4:	dly_tsk(10) -> E_NOSPT						... (A-3)
 *  5:	ext_tsk()
 *	== TASK1��³����==
 *	6:	chg_pri(TASK3, HIGH_PRIORITY) -> E_NOSPT	... (B-1)
 *	7:	wup_tsk(TASK3) -> E_NOSPT					... (B-2)
 *	8:	can_wup(TASK3) -> E_NOSPT					... (B-4)
 *	9:	rel_wai(TASK3) -> E_NOSPT					... (B-5)
 *	10:	sus_tsk(TASK3) -> E_NOSPT					... (B-7)
 *	11:	rsm_tsk(TASK3) -> E_NOSPT					... (B-8)
 *	12:	sta_alm(ALM1, 10)
 *	13:	slp_tsk()
 *	== ALM1 ==
 *	14:	iwup_tsk(TASK3) -> E_NOSPT					... (B-3)
 *	15:	irel_wai(TASK3) -> E_NOSPT					... (B-6)
 *	16:	iwup_tsk(TASK1)
 *	17:	iact_tsk(TASK3)
 *	18:	iact_tsk(TASK4)
 *	19:	irot_rdq(MID_PRIORITY)						... (C-3)
 *	20:	irot_rdq(MID_PRIORITY) -> E_NOSPT			... (C-4)
 *	21:	RETURN
 *	== TASK3-1��ͥ���١����==
 *	22:	act_tsk(TASK2)
 *	== TASK2-2��ͥ���١����2��� ==
 *	23:	rot_rdq(MID_PRIORITY) -> E_NOSPT			... (C-2)
 *	24:	ext_tsk()
 *	== TASK3-1��³����==
 *	25:	ext_tsk()
 *	== TASK4-1��ͥ���١����1��� ==
 *	26:	ext_tsk()
 *	== TASK1��³����==
 *	27:	act_tsk(TASK3)
 *	28:	act_tsk(TASK4)
 *	29:	act_tsk(TASK2)
 *	== TASK2-3��ͥ���١����3��� ==
 *	30:	rot_rdq(MID_PRIORITY)						... (C-1)
 *	31:	ext_tsk()
 *	== TASK3-2��ͥ���١����2��� ==
 *	32:	ext_tsk()
 *	== TASK4-2��ͥ���١����2��� ==
 *	33:	ext_tsk()
 *	== TASK1��³����==
 *	34: END
 */

#include <kernel.h>
#include <test_lib.h>
#include <t_syslog.h>
#include "kernel_cfg.h"
#include "test_rstr1.h"

void
alarm1_handler(intptr_t exinf)
{
	ER		ercd;

	check_point(14);
	ercd = iwup_tsk(TASK3);
	check_ercd(ercd, E_NOSPT);

	check_point(15);
	ercd = irel_wai(TASK3);
	check_ercd(ercd, E_NOSPT);

	check_point(16);
	ercd = iwup_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(17);
	ercd = iact_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(18);
	ercd = iact_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(19);
	ercd = irot_rdq(MID_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(20);
	ercd = irot_rdq(MID_PRIORITY);
	check_ercd(ercd, E_NOSPT);

	check_point(21);
	return;

	check_point(0);
}

void
task1(intptr_t exinf)
{
	ER		ercd;

	check_point(1);
	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(6);
	ercd = chg_pri(TASK3, HIGH_PRIORITY);
	check_ercd(ercd, E_NOSPT);

	check_point(7);
	ercd = wup_tsk(TASK3);
	check_ercd(ercd, E_NOSPT);

	check_point(8);
	ercd = can_wup(TASK3);
	check_ercd(ercd, E_NOSPT);

	check_point(9);
	ercd = rel_wai(TASK3);
	check_ercd(ercd, E_NOSPT);

	check_point(10);
	ercd = sus_tsk(TASK3);
	check_ercd(ercd, E_NOSPT);

	check_point(11);
	ercd = rsm_tsk(TASK3);
	check_ercd(ercd, E_NOSPT);

	check_point(12);
	ercd = sta_alm(ALM1, 10);
	check_ercd(ercd, E_OK);

	check_point(13);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(27);
	ercd = act_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(28);
	ercd = act_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(29);
	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_finish(34);

	check_point(0);
}

static uint_t	task2_count = 0;

void
task2(intptr_t exinf)
{
	ER		ercd;

	switch (++task2_count) {
	case 1:
		check_point(2);
		ercd = slp_tsk();
		check_ercd(ercd, E_NOSPT);

		check_point(3);
		ercd = tslp_tsk(10);
		check_ercd(ercd, E_NOSPT);

		check_point(4);
		ercd = dly_tsk(10);
		check_ercd(ercd, E_NOSPT);

		check_point(5);
		ercd = ext_tsk();
		check_ercd(ercd, E_OK);

		check_point(0);

	case 2:
		check_point(23);
		ercd = rot_rdq(MID_PRIORITY);
		check_ercd(ercd, E_NOSPT);

		check_point(24);
		ercd = ext_tsk();
		check_ercd(ercd, E_OK);

		check_point(0);

	case 3:
		check_point(30);
		ercd = rot_rdq(MID_PRIORITY);
		check_ercd(ercd, E_OK);

		check_point(31);
		ercd = ext_tsk();
		check_ercd(ercd, E_OK);

		check_point(0);
	}
	check_point(0);
}

static uint_t	task3_count = 0;

void
task3(intptr_t exinf)
{
	ER		ercd;

	switch (++task3_count) {
	case 1:
		check_point(22);
		ercd = act_tsk(TASK2);
		check_ercd(ercd, E_OK);

		check_point(25);
		ercd = ext_tsk();
		check_ercd(ercd, E_OK);

		check_point(0);

	case 2:
		check_point(32);
		ercd = ext_tsk();
		check_ercd(ercd, E_OK);

		check_point(0);
	}
	check_point(0);
}

static uint_t	task4_count = 0;

void
task4(intptr_t exinf)
{
	ER		ercd;

	switch (++task4_count) {
	case 1:
		check_point(26);
		ercd = ext_tsk();
		check_ercd(ercd, E_OK);

		check_point(0);

	case 2:
		check_point(33);
		ercd = ext_tsk();
		check_ercd(ercd, E_OK);

		check_point(0);
	}
	check_point(0);
}
