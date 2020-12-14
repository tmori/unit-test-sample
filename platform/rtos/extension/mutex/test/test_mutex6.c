/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2007-2009 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: test_mutex6.c 1696 2010-01-01 16:01:25Z ertl-hiro $
 */

/* 
 *		�ߥ塼�ƥå����Υƥ���(6)
 *
 * �ڥƥ��Ȥ���Ū��
 *
 *  ͥ���پ�¥ߥ塼�ƥå������Ф��ơ��������ν�λ������������ͥ����
 *  �β�ž���Υߥ塼�ƥå�����Ϣ�ν���������Ū�˥ƥ��Ȥ��롥
 *
 * �ڥƥ��ȹ��ܡ�
 *
 *	(A) �������ν�λ����ext_tsk��
 *		(A-1) ��å����Ƥ����ߥ塼�ƥå�����1�ġˤ���å��������뤳�ȡ�
 *		(A-2) ��å����Ƥ����ߥ塼�ƥå�����1�ġˤ���å�������졤���
 *			  �����ԤäƤ�����������������å�����ͥ���٤��Ѳ�������
 *			  ���������뤳�ȡ�
 *		(A-3) ��å����Ƥ����ߥ塼�ƥå�����ʣ���ˤ����٤ƥ�å������
 *			  ��뤳�ȡ�
 *		(A-4) ��å����Ƥ����ߥ塼�ƥå�����ʣ���ˤ���å�������졤���
 *			  �����ԤäƤ�����������ʣ���ˤ�������å�����ͥ���٤���
 *			  �������Ԥ��������뤳�ȡ����λ��ˡ���ǥߥ塼�ƥå�����
 *			  ��å���������������˥�å����Ƥ����ߥ塼�ƥå������Ԥ�
 *			  �Ƥ����������ˤ�������ͥ���̤��⤯�ʤ뤳�ȡ�
 *	(B) ��������ͥ���̤β�ž��rot_rdq��
 *		(B-1) TPRI_SELF����ꤷ�����ˡ��������Υ١���ͥ���٤�ͥ���̤�
 *		��������ž���뤳�ȡ�
 *		(B-2) TPRI_SELF����ꤷ�����ˡ��������θ���ͥ���٤�ͥ���̤���
 *		������ž���ʤ����ȡ�
 *
 * �ڥƥ��ȹ��ܤμ¸���ˡ��
 *
 *	(A-1)
 *		��ͥ���٥�������TASK2�ˤ˥ߥ塼�ƥå�����MTX1�ˤ��å�������
 *		ext_tsk����ȡ���å����������뤳�Ȥ��ǧ���롥
 *	(A-2)
 *		��ͥ���٥�������TASK2�ˤ˹�ͥ���پ�¥ߥ塼�ƥå�����MTX1�ˤ���
 *		���������̤���ͥ���٥�������TASK3�ˤ�MTX1���Ԥ��������֤ǡ�
 *		TASK2 ��ext_tsk����ȡ�TASK3����ͥ���٤ˤʤä��Ԥ��������뤳
 *		�Ȥ��ǧ���롥
 *	(A-3)
 *		��ͥ���٥�������TASK2�ˤ˥ߥ塼�ƥå�����2�ġ�MTX1��MTX2�˥��
 *		��������ext_tsk����ȡ�ξ���Υ�å����������뤳�Ȥ��ǧ���롥
 *	(A-4)
 *		��ͥ���٥�������TASK2�ˤ˹�ͥ���پ�¥ߥ塼�ƥå���2�ġ�MTX1��
 *		MTX2�ˤ򤳤ν�ǥ�å��������̤���ͥ���٥�����2�ġ�TASK3��
 *		TASK4�ˤˤ��줾��Υ�å����Ԥ��������֤ǡ�TASK2��ext_tsk����ȡ�
 *		TASK3��TASK4����ͥ���٤ˤʤä��Ԥ��������뤳�Ȥ��ǧ���롥��
 *		������˥�å����Ƥ����ߥ塼�ƥå�����MTX1�ˤ��ԤäƤ���������
 *		��TASK3�ˤ���TASK4����ͥ���̤��⤯�ʤ뤳�Ȥ��ǧ���롥
 *	(B-1)
 *		��ͥ���٥�������3�ġ�TASK2��TASK3��TASK4�ˤ��¹ԤǤ�����֤λ�
 *		�ˡ�1�Ĥ���ͥ���٥�������TASK2�ˤ˹�ͥ���پ�¥ߥ塼�ƥå�����
 *		��å�������rot_rdq(TPRI_SELF)����ȡ��Ĥ��2�Ĥ���ͥ���٥�����
 *		��ͥ���̤���ž���뤳�Ȥ��ǧ���롥
 *	(B-2)
 *		���Ʊ�������ǡ���ͥ���٥�������ͥ���̤���ž���ʤ����Ȥ��ǧ
 *		���롥
 *
 * �ڻ��ѥ꥽������
 *
 *	TASK1: ��ͥ���٥��������ᥤ�󥿥������ǽ餫�鵯ư
 *	TASK2: ��ͥ���٥�����
 *	TASK3: ��ͥ���٥�����
 *	TASK4: ��ͥ���٥�����
 *	MTX1: �ߥ塼�ƥå�����TA_CEILING°������¤Ϲ�ͥ���١�
 *	MTX2: �ߥ塼�ƥå�����TA_CEILING°������¤Ϲ�ͥ���١�
 *
 * �ڥƥ��ȥ������󥹡�
 *
 *	== TASK1��ͥ���١����==
 *		call(set_bit_func(bit_mutex))
 *	1:	act_tsk(TASK2)
 *	2:	rot_rdq(TPRI_SELF)
 *	//		�㡧TASK2��TASK1
 *	== TASK2-1��ͥ���١����1��� ==
 *	3:	loc_mtx(MTX1)
 *	//		�⡧TASK2���㡧TASK1��MTX1��TASK2
 *	4:	ext_tsk() -> noreturn			... (A-1)
 *	//		�㡧TASK1
 *	== TASK1��³����==
 *	5:	ref_mtx(MTX1, &rmtx)
 *		assert(rmtx.htskid == TSK_NONE)
 *		assert(rmtx.wtskid == TSK_NONE)
 *
 *	6:	act_tsk(TASK2)
 *		act_tsk(TASK3)
 *	7:	rot_rdq(TPRI_SELF)
 *	//		�㡧TASK2��TASK3��TASK1
 *	== TASK2-2��ͥ���١����2��� ==
 *	8:	loc_mtx(MTX1)
 *	//		�⡧TASK2���㡧TASK3��TASK1��MTX1��TASK2
 *	9:	slp_tsk()
 *	//		�㡧TASK3��TASK1��MTX1��TASK2
 *	== TASK3��ͥ���١����==
 *	10:	loc_mtx(MTX1)
 *	//		�㡧TASK1��MTX1��TASK2��TASK3
 *	== TASK1��³����==
 *	11:	wup_tsk(TASK2)
 *	//		�⡧TASK2���㡧TASK1��MTX1��TASK2��TASK3
 *	== TASK2-2��³����==
 *	12:	ext_tsk() -> noreturn			... (A-2)
 *	//		�⡧TASK3���㡧TASK1��MTX1��TASK3
 *	== TASK3��³����==
 *	13:	ref_mtx(MTX1, &rmtx)
 *		assert(rmtx.htskid == TASK3)
 *		assert(rmtx.wtskid == TSK_NONE)
 *		get_pri(TPRI_SELF, &tskpri)
 *		assert(tskpri == HIGH_PRIORITY)
 *		unl_mtx(MTX1)
 *		slp_tsk()
 *	//		�㡧TASK1
 *
 *	== TASK1��³����==
 *	14:	act_tsk(TASK2)
 *	15:	rot_rdq(TPRI_SELF)
 *	//		�㡧TASK2��TASK1
 *	== TASK2-3��ͥ���١����3��� ==
 *	16:	loc_mtx(MTX1)
 *		loc_mtx(MTX2)
 *	//		�⡧TASK2���㡧TASK1��MTX1��TASK2��MTX2��TASK2
 *	17:	ext_tsk() -> noreturn			... (A-3)
 *	//		�㡧TASK1
 *	== TASK1��³����==
 *	18:	ref_mtx(MTX1, &rmtx)
 *		assert(rmtx.htskid == TSK_NONE)
 *		assert(rmtx.wtskid == TSK_NONE)
 *		ref_mtx(MTX2, &rmtx)
 *		assert(rmtx.htskid == TSK_NONE)
 *		assert(rmtx.wtskid == TSK_NONE)
 *
 *	19:	act_tsk(TASK2)
 *		wup_tsk(TASK3)
 *		act_tsk(TASK4)
 *	20:	rot_rdq(TPRI_SELF)
 *	//		�㡧TASK2��TASK3��TASK4��TASK1
 *	== TASK2-4��ͥ���١����4��� ==
 *	21:	loc_mtx(MTX1)
 *		loc_mtx(MTX2)
 *	//		�⡧TASK2���㡧TASK3��TASK4��TASK1��MTX1��TASK2��MTX2��TASK2
 *	22:	chg_pri(TASK1, HIGH_PRIORITY)
 *	//		�⡧TASK2��TASK1���㡧TASK3��TASK4��MTX1��TASK2��MTX2��TASK2
 *	23:	rot_rdq(TPRI_SELF)				... (B-1)(B-2)
 *	//		�⡧TASK2��TASK1���㡧TASK4��TASK3��MTX1��TASK2��MTX2��TASK2
 *	24:	slp_tsk()
 *	//		�⡧TASK1���㡧TASK4��TASK3��MTX1��TASK2��MTX2��TASK2
 *	== TASK1��³����==
 *	25:	chg_pri(TSK_SELF, TPRI_INI)
 *	//		�㡧TASK4��TASK3��TASK1��MTX1��TASK2��MTX2��TASK2
 *	== TASK4��ͥ���١����==
 *	26:	loc_mtx(MTX2)
 *	//		�㡧TASK3��TASK1��MTX1��TASK2��MTX2��TASK2��TASK4
 *	== TASK3��³����==
 *	27:	loc_mtx(MTX1)
 *	//		�㡧TASK1��MTX1��TASK2��TASK3��MTX2��TASK2��TASK4
 *	== TASK1��³����==
 *	28:	wup_tsk(TASK2)
 *	//		�⡧TASK2���㡧TASK1��MTX1��TASK2��TASK3��MTX2��TASK2��TASK4
 *	== TASK2-4��³����==
 *	29:	ext_tsk() -> noreturn			... (A-4)
 *	//		�⡧TASK3��TASK4���㡧TASK1��MTX1��TASK3��MTX2��TASK4
 *	== TASK3��³����==
 *	30:	ref_mtx(MTX1, &rmtx)
 *		assert(rmtx.htskid == TASK3)
 *		assert(rmtx.wtskid == TSK_NONE)
 *		ref_mtx(MTX2, &rmtx)
 *		assert(rmtx.htskid == TASK4)
 *		assert(rmtx.wtskid == TSK_NONE)
 *		get_pri(TPRI_SELF, &tskpri)
 *		assert(tskpri == HIGH_PRIORITY)
 *		ext_tsk() -> noreturn
 *	//		�⡧TASK4���㡧TASK1��MTX2��TASK4
 *	== TASK4��³����==
 *	31:	get_pri(TPRI_SELF, &tskpri)
 *		assert(tskpri == HIGH_PRIORITY)
 *		ext_tsk() -> noreturn
 *	//		�㡧TASK1
 *	== TASK1��³����==
 *	32:	END
 */

#include <kernel.h>
#include <t_syslog.h>
#include "syssvc/logtask.h"
#include "kernel_cfg.h"
#include "test_lib.h"
#include "test_mutex6.h"

extern ER	bit_mutex(void);

void
task1(intptr_t exinf)
{
	ER		ercd;
	T_RMTX	rmtx;

	set_bit_func(bit_mutex);

	check_point(1);
	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(2);
	ercd = rot_rdq(TPRI_SELF);
	check_ercd(ercd, E_OK);

	check_point(5);
	ercd = ref_mtx(MTX1, &rmtx);
	check_ercd(ercd, E_OK);
	check_assert(rmtx.htskid == TSK_NONE);
	check_assert(rmtx.wtskid == TSK_NONE);

	check_point(6);
	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	ercd = act_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(7);
	ercd = rot_rdq(TPRI_SELF);
	check_ercd(ercd, E_OK);

	check_point(11);
	ercd = wup_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(14);
	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(15);
	ercd = rot_rdq(TPRI_SELF);
	check_ercd(ercd, E_OK);

	check_point(18);
	ercd = ref_mtx(MTX1, &rmtx);
	check_ercd(ercd, E_OK);
	check_assert(rmtx.htskid == TSK_NONE);
	check_assert(rmtx.wtskid == TSK_NONE);

	ercd = ref_mtx(MTX2, &rmtx);
	check_ercd(ercd, E_OK);
	check_assert(rmtx.htskid == TSK_NONE);
	check_assert(rmtx.wtskid == TSK_NONE);

	check_point(19);
	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	ercd = wup_tsk(TASK3);
	check_ercd(ercd, E_OK);

	ercd = act_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(20);
	ercd = rot_rdq(TPRI_SELF);
	check_ercd(ercd, E_OK);

	check_point(25);
	ercd = chg_pri(TSK_SELF, TPRI_INI);
	check_ercd(ercd, E_OK);

	check_point(28);
	ercd = wup_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_finish(32);

	check_point(0);
}

static uint_t	task2_count = 0;

void
task2(intptr_t exinf)
{
	ER		ercd;

	switch (++task2_count) {
	case 1:
		check_point(3);
		ercd = loc_mtx(MTX1);
		check_ercd(ercd, E_OK);

		check_point(4);
		ercd = ext_tsk();

		check_point(0);

	case 2:
		check_point(8);
		ercd = loc_mtx(MTX1);
		check_ercd(ercd, E_OK);

		check_point(9);
		ercd = slp_tsk();
		check_ercd(ercd, E_OK);

		check_point(12);
		ercd = ext_tsk();

		check_point(0);

	case 3:
		check_point(16);
		ercd = loc_mtx(MTX1);
		check_ercd(ercd, E_OK);

		ercd = loc_mtx(MTX2);
		check_ercd(ercd, E_OK);

		check_point(17);
		ercd = ext_tsk();

		check_point(0);

	case 4:
		check_point(21);
		ercd = loc_mtx(MTX1);
		check_ercd(ercd, E_OK);

		ercd = loc_mtx(MTX2);
		check_ercd(ercd, E_OK);

		check_point(22);
		ercd = chg_pri(TASK1, HIGH_PRIORITY);
		check_ercd(ercd, E_OK);

		check_point(23);
		ercd = rot_rdq(TPRI_SELF);
		check_ercd(ercd, E_OK);

		check_point(24);
		ercd = slp_tsk();
		check_ercd(ercd, E_OK);

		check_point(29);
		ercd = ext_tsk();

		check_point(0);
	}
	check_point(0);
}

void
task3(intptr_t exinf)
{
	ER		ercd;
	PRI		tskpri;
	T_RMTX	rmtx;

	check_point(10);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(13);
	ercd = ref_mtx(MTX1, &rmtx);
	check_ercd(ercd, E_OK);
	check_assert(rmtx.htskid == TASK3);
	check_assert(rmtx.wtskid == TSK_NONE);

	ercd = get_pri(TPRI_SELF, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == HIGH_PRIORITY);

	ercd = unl_mtx(MTX1);
	check_ercd(ercd, E_OK);

	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(27);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(30);
	ercd = ref_mtx(MTX1, &rmtx);
	check_ercd(ercd, E_OK);
	check_assert(rmtx.htskid == TASK3);
	check_assert(rmtx.wtskid == TSK_NONE);

	ercd = ref_mtx(MTX2, &rmtx);
	check_ercd(ercd, E_OK);
	check_assert(rmtx.htskid == TASK4);
	check_assert(rmtx.wtskid == TSK_NONE);

	ercd = get_pri(TPRI_SELF, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == HIGH_PRIORITY);

	ercd = ext_tsk();

	check_point(0);
}

void
task4(intptr_t exinf)
{
	ER		ercd;
	PRI		tskpri;

	check_point(26);
	ercd = loc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(31);
	ercd = get_pri(TPRI_SELF, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == HIGH_PRIORITY);

	ercd = ext_tsk();

	check_point(0);
}
