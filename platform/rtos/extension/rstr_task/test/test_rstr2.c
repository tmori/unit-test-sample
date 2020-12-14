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
 *  $Id: test_rstr2.c 1887 2010-08-06 06:15:19Z ertl-hiro $
 */

/* 
 *		���󥿥����Υƥ���(2)
 *
 * �ڥƥ��Ȥ���Ū��
 *
 *  ras_pri�����ӥ��������ư���ƥ��Ȥ��롥
 *
 * �ڥƥ��ȹ��ܡ�
 *
 *	(A) ���󥿥�������ras_pri��ƤӽФ���ͥ���٤�夲��
 *		(A-1) �ǥ����ѥå����ľ��֤ǸƤӽФ������
 *		(A-2) �ǥ����ѥå��ػ߾��֤ǡ��ǹ�ͥ���̥��������¹Ծ��֤Ǥ�
 *		      �����˸ƤӽФ������
 *	(B) ͥ���٤��夬�ä����󥿥�������ras_pri(TPRI_INI)��ƤӽФ�����ư
 *      ��ͥ���٤��᤹
 *		(B-1) ��ư��ͥ���٤���⤤ͥ���٤Υ��������¹Բ�ǽ�ξ��ˡ�
 *		      �������ڴ����������뤳�Ȥ��ǧ����
 *		(B-2) ��ư��ͥ���٤�Ʊ��ͥ���٤Υ��������¹Բ�ǽ�ξ��ˡ�����
 *		      ���ڴ�����������ʤ����Ȥ��ǧ����
 *		(B-3) ��ư��ͥ���٤����㤤ͥ���٤Υ��������¹Բ�ǽ�ξ��ˡ�
 *		      �������ڴ�����������ʤ����Ȥ��ǧ����
 *	(C) ���󥿥�������ras_pri��ƤӽФ�����ư��ͥ���٤����㤤ͥ���٤�
 *	    �ѹ����褦�Ȥ���ȡ�E_ILUSE�ˤʤ뤳�Ȥ��ǧ����
 *
 * �ڻ��ѥ꥽������
 *
 *	TASK1: ��ͥ���٥��������ᥤ�󥿥������ǽ餫�鵯ư
 *	TASK2: ��ͥ���٥����������󥿥���
 *	TASK3: ��ͥ���٥�����
 *
 * �ڥƥ��ȥ������󥹡�
 *
 *	== TASK1��ͥ���١����==
 *	1:	act_tsk(TASK2)
 *	2:	slp_tsk()
 *	== TASK2��ͥ���١����==
 *	3:	get_pri(TSK_SELF, &tskpri)
 *		assert(tskpri == MID_PRIORITY)
 *	4:	ras_pri(HIGH_PRIORITY)
 *	5:	get_pri(TSK_SELF, &tskpri)
 *		assert(tskpri == HIGH_PRIORITY)
 *	6:	act_tsk(TASK3)
 *	7:	ras_pri(LOW_PRIORITY) -> E_ILUSE			... (C)
 *	8:	ras_pri(TPRI_INI)							... (B-1)
 *	== TASK3��ͥ���١����==
 *	9:	get_pri(TASK2, &tskpri)
 *		assert(tskpri == MID_PRIORITY)
 *	10:	slp_tsk()
 *	== TASK2��³����==
 *	11:	dis_dsp()
 *	12:	wup_tsk(TASK3)
 *	13:	ras_pri(HIGH_PRIORITY)						... (A-2)
 *	14:	ena_dsp()
 *	15:	ras_pri(TPRI_INI)							... (B-3)
 *	== TASK3��³����==
 *	16:	chg_pri(TSK_SELF, LOW_PRIORITY)
 *	== TASK2��³����==
 *	17:	ras_pri(HIGH_PRIORITY)
 *	18:	wup_tsk(TASK1)
 *	19:	ras_pri(TPRI_INI)							... (B-2)
 *	20:	ext_tsk()
 *	== TASK1��³����==
 *	21: END
 */

#include <kernel.h>
#include <test_lib.h>
#include <t_syslog.h>
#include "kernel_cfg.h"
#include "test_rstr1.h"

void
task1(intptr_t exinf)
{
	ER		ercd;

	check_point(1);
	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(2);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_finish(21);

	check_point(0);
}

void
task2(intptr_t exinf)
{
	ER		ercd;
	PRI		tskpri;

	check_point(3);
	ercd = get_pri(TSK_SELF, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == MID_PRIORITY);

	check_point(4);
	ercd = ras_pri(HIGH_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(5);
	ercd = get_pri(TSK_SELF, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == HIGH_PRIORITY);

	check_point(6);
	ercd = act_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(7);
	ercd = ras_pri(LOW_PRIORITY);
	check_ercd(ercd, E_ILUSE);

	check_point(8);
	ercd = ras_pri(TPRI_INI);
	check_ercd(ercd, E_OK);

	check_point(11);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	check_point(12);
	ercd = wup_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(13);
	ercd = ras_pri(HIGH_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(14);
	ercd = ena_dsp();
	check_ercd(ercd, E_OK);

	check_point(15);
	ercd = ras_pri(TPRI_INI);
	check_ercd(ercd, E_OK);

	check_point(17);
	ercd = ras_pri(HIGH_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(18);
	ercd = wup_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(19);
	ercd = ras_pri(TPRI_INI);
	check_ercd(ercd, E_OK);

	check_point(20);
	ercd = ext_tsk();
	check_ercd(ercd, E_OK);

	check_point(0);
}

void
task3(intptr_t exinf)
{
	ER		ercd;
	PRI		tskpri;

	check_point(9);
	ercd = get_pri(TASK2, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == MID_PRIORITY);

	check_point(10);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(16);
	ercd = chg_pri(TSK_SELF, LOW_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(0);
}
