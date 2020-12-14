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
 *  @(#) $Id: test_mutex5.c 1696 2010-01-01 16:01:25Z ertl-hiro $
 */

/* 
 *		�ߥ塼�ƥå����Υƥ���(5)
 *
 * �ڥƥ��Ȥ���Ū��
 *
 *  ͥ���پ�¥ߥ塼�ƥå������Ф��ơ��ߥ塼�ƥå����κƽ������������
 *  ��Ū�˥ƥ��Ȥ��롥��������change_priority��mutex_calc_priority����
 *  �Ƥˤ�Ƨ�߹��ޤʤ���
 *
 * �ڥƥ��ȹ��ܡ�
 *
 *	(A) �ߥ塼�ƥå����ν������ini_mtx�ˤ�ȼ���ߥ塼�ƥå������å���
 *		�Ƥ����������ʼ¹ԤǤ�����֡ˤ�ͥ�����ѹ�
 *		(A-1) ����������ߥ塼�ƥå����ξ��ͥ���٤����ߥ塼�ƥå�����
 *			  ��å����Ƥ����������ʼ¹ԤǤ�����֡ˤθ���ͥ���٤�Ʊ��
 *			  �ǡ��ߥ塼�ƥå����Υ�å������ͥ���٤�������٤����ˡ�
 *			  ������������ͥ���٤�Ŭ�ڤ˲������뤳�ȡ��ޤ���Ʊ��ͥ��
 *			  ����Ǥ�ͥ���̤��ǹ�ˤʤ뤳��
 *		(A-2) ����������ߥ塼�ƥå����ξ��ͥ���٤����ߥ塼�ƥå�����
 *			  ��å����Ƥ����������ʼ¹ԤǤ�����֡ˤθ���ͥ���٤�Ʊ��
 *			  �ǡ��ߥ塼�ƥå����Υ�å������ͥ���٤��Ѥ��٤��Ǥʤ�
 *			  ���ˡ�������������ͥ���٤��Ѥ��ʤ����ȡ��ޤ���Ʊ��ͥ
 *			  ������Ǥ�ͥ���̤��Ѥ��ʤ�����
 *		(A-3) ����������ߥ塼�ƥå����ξ��ͥ���٤����ߥ塼�ƥå�����
 *			  ��å����Ƥ����������ʼ¹ԤǤ�����֡ˤθ���ͥ���٤���
 *			  �㤤���ˡ�������������ͥ���٤��Ѥ��ʤ����ȡ��ޤ���Ʊ
 *			  ��ͥ������Ǥ�ͥ���̤��Ѥ��ʤ�����
 *		(A-4) (A-1)�η�̡��������ǥ����ѥå��������뤳�ȡ�
 *	(B) �ߥ塼�ƥå����ν������ini_mtx�ˤ�ȼ���ߥ塼�ƥå������å���
 *		�Ƥ������������Ԥ����֡ˤ�ͥ�����ѹ�
 *		(B-1) ����������ߥ塼�ƥå����ξ��ͥ���٤����ߥ塼�ƥå�����
 *			  ��å����Ƥ������������Ԥ����֡ˤθ���ͥ���٤�Ʊ���ǡ�
 *			  �ߥ塼�ƥå����Υ�å������ͥ���٤�������٤����ˡ���
 *			  ����������ͥ���٤�Ŭ�ڤ˲������뤳�ȡ��ޤ���Ʊ��ͥ����
 *			  ��Ǥν�����Ǹ�ˤʤ뤳��
 *		(B-2) ����������ߥ塼�ƥå����ξ��ͥ���٤����ߥ塼�ƥå�����
 *			  ��å����Ƥ������������Ԥ����֡ˤθ���ͥ���٤�Ʊ���ǡ�
 *			  �ߥ塼�ƥå����Υ�å������ͥ���٤��Ѥ��٤��Ǥʤ����
 *			  �ˡ�������������ͥ���٤��Ѥ��ʤ����ȡ��ޤ���Ʊ��ͥ����
 *			  ��Ǥν�����Ѥ��ʤ�����
 *		(B-3) ����������ߥ塼�ƥå����ξ��ͥ���٤����ߥ塼�ƥå�����
 *			  ��å����Ƥ������������Ԥ����֡ˤθ���ͥ���٤����㤤��
 *			  ��ˡ�������������ͥ���٤��Ѥ��ʤ����ȡ��ޤ���Ʊ��ͥ��
 *			  ����Ǥν�����Ѥ��ʤ�����
 *	(C) �ߥ塼�ƥå����ν������ini_mtx�ˤ�ȼ���ߥ塼�ƥå������ԤäƤ�
 *		���������ξ����Ѳ�
 *		(C-1) �ߥ塼�ƥå������ԤäƤ������������Ԥ��������뤳�ȡ�
 *		(C-2) (C-1)�η�̡��������ǥ����ѥå��������뤳�ȡ�
 *
 * �ڥƥ��ȹ��ܤμ¸���ˡ��
 *
 *	(A-1)
 *		��ͥ���٥�������TASK1�ˤ�����ͥ���پ�¥ߥ塼�ƥå�����MTX1�ˤ�
 *		��å��������֤ǡ���ͥ���٥�������TASK5�ˤ���MTX1��ƽ��������
 *		TASK1��ͥ���٤���ͥ���٤˲����뤳�Ȥ��ǧ���롥�ޤ����¹Բ�ǽ��
 *		�֤���ͥ���٥�������TASK2�ˤ��⡤ͥ���̤��⤯�ʤ뤳�Ȥ��ǧ
 *		���롥��
 *	(A-2)
 *		��ͥ���٥�������TASK1�ˤ�����ͥ���پ�¥ߥ塼�ƥå�����2��
 *		��MTX1��MTX2�ˤ��å��������֤ǡ���ͥ���٥�������TASK5�ˤ���
 *		MTX1��ƽ��������TASK1��ͥ���٤��Ѳ����ʤ����Ȥ��ǧ���롥�ޤ���
 *		�¹Բ�ǽ���֤���ͥ���٥�������2�ġ�TASK3��TASK4�ˤ��Ѱդ��Ƥ�����
 *		ͥ���̤��Ѥ��ʤ����Ȥ��ǧ���롥
 *	(A-3)
 *		��ͥ���٥�������TASK1�ˤ�����ͥ���پ�¥ߥ塼�ƥå�����MTX2�ˤ�
 *		��ͥ���پ�¥ߥ塼�ƥå�����MTX3�ˤ��å��������֤ǡ���ͥ����
 *		��������TASK5�ˤ���MTX3��ƽ��������TASK1��ͥ���٤��Ѳ����ʤ�
 *		���Ȥ��ǧ���롥�ޤ����¹Բ�ǽ���֤���ͥ���٥�������2�ġ�TASK3��
 *		TASK4�ˤ��Ѱդ��Ƥ�����ͥ���̤��Ѥ��ʤ����Ȥ��ǧ���롥
 *	(A-4)
 *		��ͥ���٥�������TASK1�ˤ�����ͥ���پ�¥ߥ塼�ƥå�����MTX2�ˤ�
 *		��å��������֤ǡ�TASK1����MTX2��ƽ��������TASK1��ͥ���٤���
 *		ͥ���٤˲����ꡤ�¹Բ�ǽ���֤���ͥ���٥�������TASK4�ˤ��ڤ괹��
 *		�뤳�Ȥ��ǧ���롥�ޤ����¹Բ�ǽ���֤���ͥ���٥�������TASK2�ˤ�
 *		��⡤ͥ���̤��⤯�ʤ뤳�Ȥ��ǧ���롥��
 *	(B-1)
 *		��ͥ���٥�������TASK1�ˤ�����ͥ���پ�¥ߥ塼�ƥå�����MTX1�ˤ�
 *		��å��������֤ǡ��̤Υߥ塼�ƥå�����MTX4���Ԥ����֤Ȥ�����ͥ
 *		���٥�������TASK5�ˤ���MTX1��ƽ��������TASK1��ͥ���٤���ͥ��
 *		�٤˲����뤳�Ȥ��ǧ���롥�ޤ���MTX4�Ԥ����֤���ͥ���٥�����
 *		��TASK2�ˤ��⡤�Ԥ�������Ǥν������ˤʤ뤳�Ȥ��ǧ���롥
 *	(B-2)
 *		��ͥ���٥�������TASK1�ˤ�����ͥ���پ�¥ߥ塼�ƥå�����2��
 *		��MTX1��MTX2�ˤ��å��������֤ǡ��̤Υߥ塼�ƥå�����MTX4����
 *		�����֤Ȥ�����ͥ���٥�������TASK5�ˤ���MTX1��ƽ��������TASK1
 *		��ͥ���٤��Ѳ����ʤ����Ȥ��ǧ���롥�ޤ���MTX4�Ԥ����֤���ͥ��
 *		�٥�������2�ġ�TASK3��TASK4�ˤ��Ѱդ��Ƥ������Ԥ�������Ǥν��
 *		���Ѥ��ʤ����Ȥ��ǧ���롥
 *	(B-3)
 *		��ͥ���٥�������TASK1�ˤ�����ͥ���پ�¥ߥ塼�ƥå�����MTX2�ˤ�
 *		��ͥ���پ�¥ߥ塼�ƥå�����MTX3�ˤ��å��������֤ǡ��̤Υߥ塼
 *		�ƥå�����MTX4���Ԥ����֤Ȥ�����ͥ���٥�������TASK5�ˤ���MTX3��
 *		�ƽ��������TASK1��ͥ���٤��Ѳ����ʤ����Ȥ��ǧ���롥�ޤ���
 *		MTX4�Ԥ����֤���ͥ���٥�������2�ġ�TASK3��TASK4�ˤ��Ѱդ��Ƥ�����
 *		�Ԥ�������Ǥν�����Ѥ��ʤ����Ȥ��ǧ���롥
 *	(C-1)
 *		��ͥ���٥�������TASK1�ˤ���ͥ���پ�¥ߥ塼�ƥå�����MTX1�ˤ���
 *		��������ͥ���٥�������TASK3�ˤ�MTX1���ԤäƤ�����֤ǡ���ͥ����
 *		��������TASK5�ˤ���MTX1��ƽ��������TASK3���Ԥ��������뤳��
 *		���ǧ���롥�ޤ����¹Բ�ǽ���֤���ͥ���٥�������TASK4�ˤ��⡤
 *		TASK3������ͥ���̤��㤯�ʤ뤳�Ȥ��ǧ���롥��
 *	(C-2)
 *		��ͥ���٥�������TASK1�ˤ���ͥ���پ�¥ߥ塼�ƥå�����MTX1�ˤ���
 *		��������ͥ���٥�������TASK3�ˤ�MTX1���Ԥ���TASK1�򵯾��Ԥ�����
 *		�Ȥ������֤ǡ��̤���ͥ���٥�������TASK2�ˤ���MTX1��ƽ��������
 *		TASK3���Ԥ�������졤TASK3���ڤ괹��뤳�Ȥ��ǧ���롥
 *
 * �ڻ��ѥ꥽������
 *
 *	TASK1: ��ͥ���٥��������ᥤ�󥿥������ǽ餫�鵯ư
 *	TASK2: ��ͥ���٥�����
 *	TASK3: ��ͥ���٥�����
 *	TASK4: ��ͥ���٥�����
 *	TASK5: ��ͥ���٥�����
 *	MTX1: �ߥ塼�ƥå�����TA_CEILING°������¤���ͥ���١�
 *	MTX2: �ߥ塼�ƥå�����TA_CEILING°������¤���ͥ���١�
 *	MTX3: �ߥ塼�ƥå�����TA_CEILING°������¤���ͥ���١�
 *	MTX4: �ߥ塼�ƥå�����TA_CEILING°������¤Ϲ�ͥ���١�
 *
 * �ڥƥ��ȥ������󥹡�
 *
 *	== TASK1��ͥ���١����==
 *		call(set_bit_func(bit_mutex))
 *	1:	loc_mtx(MTX1)
 *	2:	act_tsk(TASK2)
 *	3:	act_tsk(TASK5)
 *	//		�⡧TASK5���桧TASK1���㡧TASK2��MTX1��TASK1
 *	== TASK5��ͥ���١����==
 *	4:	ini_mtx(MTX1)			... (A-1)
 *	//		�⡧TASK5���㡧TASK1��TASK2
 *		get_pri(TASK1, &tskpri)
 *		assert(tskpri == LOW_PRIORITY)
 *	5:	slp_tsk()
 *	//		�㡧TASK1��TASK2
 *
 *	== TASK1��³����==
 *	6:	sus_tsk(TASK2)
 *	7:	loc_mtx(MTX1)
 *		loc_mtx(MTX2)
 *	8:	act_tsk(TASK3)
 *	//		�桧TASK1��TASK3��MTX1��TASK1��MTX2��TASK1
 *	9:	dis_dsp()
 *	10:	rot_rdq(MID_PRIORITY)
 *	//		�桧TASK3��TASK1��MTX1��TASK1��MTX2��TASK1
 *	11:	act_tsk(TASK4)
 *	//		�桧TASK3��TASK1��TASK4��MTX1��TASK1��MTX2��TASK1
 *	12:	wup_tsk(TASK5)
 *	//		�⡧TASK5���桧TASK3��TASK1��TASK4��MTX1��TASK1��MTX2��TASK1
 *	13:	ena_dsp()
 *	== TASK5��³����==
 *	14:	ini_mtx(MTX1)			... (A-2)
 *	//		�⡧TASK5���桧TASK3��TASK1��TASK4��MTX2��TASK1
 *		get_pri(TASK1, &tskpri)
 *		assert(tskpri == MID_PRIORITY)
 *	15:	slp_tsk()
 *	//		�桧TASK3��TASK1��TASK4��MTX2��TASK1
 *	== TASK3��ͥ���١����==
 *	16:	slp_tsk()
 *	//		�桧TASK1��TASK4��MTX2��TASK1
 *	== TASK1��³����==
 *	17:	slp_tsk()
 *	//		�桧TASK4��MTX2��TASK1
 *	== TASK4��ͥ���١����==
 *	18:	wup_tsk(TASK1)
 *	//		�桧TASK4��TASK1��MTX2��TASK1
 *	19:	slp_tsk()
 *	//		�桧TASK1��MTX2��TASK1
 *
 *	== TASK1��³����==
 *	20:	loc_mtx(MTX3)
 *	//		�桧TASK1��MTX2��TASK1��MTX3��TASK1
 *	21:	wup_tsk(TASK3)
 *	//		�桧TASK1��TASK3��MTX2��TASK1��MTX3��TASK1
 *	22:	dis_dsp()
 *	23:	rot_rdq(MID_PRIORITY)
 *	//		�桧TASK3��TASK1��MTX2��TASK1��MTX3��TASK1
 *	24:	wup_tsk(TASK4)
 *	//		�桧TASK3��TASK1��TASK4��MTX2��TASK1��MTX3��TASK1
 *	25:	wup_tsk(TASK5)
 *	//		�⡧TASK5���桧TASK3��TASK1��TASK4��MTX2��TASK1��MTX3��TASK1
 *	26:	ena_dsp()
 *	== TASK5��³����==
 *	27:	ini_mtx(MTX3)			... (A-3)
 *	//		�⡧TASK5���桧TASK3��TASK1��TASK4��MTX2��TASK1
 *		get_pri(TASK1, &tskpri)
 *		assert(tskpri == MID_PRIORITY)
 *	28:	slp_tsk()
 *	//		�桧TASK3��TASK1��TASK4��MTX2��TASK1
 *	== TASK3��³����==
 *	29:	slp_tsk()
 *	//		�桧TASK1��TASK4��MTX2��TASK1
 *
 *	== TASK1��³����==
 *	30:	slp_tsk()
 *	//		�桧TASK4��MTX2��TASK1
 *	== TASK4��³����==
 *	31:	wup_tsk(TASK1)
 *	//		�桧TASK4��TASK1��MTX2��TASK1
 *	32:	rot_rdq(MID_PRIORITY)
 *	//		�桧TASK1��TASK4��MTX2��TASK1
 *	== TASK1��³����==
 *	33:	rsm_tsk(TASK2)
 *	//		�桧TASK1��TASK4���㡧TASK2��MTX2��TASK1
 *	34:	ini_mtx(MTX2)			... (A-4)
 *	//		�桧TASK4���㡧TASK1��TASK2
 *	== TASK4��³����==
 *	35:	get_pri(TASK1, &tskpri)
 *		assert(tskpri == LOW_PRIORITY)
 *	36:	slp_tsk()
 *	//		�㡧TASK1��TASK2
 *
 *	== TASK1��³����==
 *	37:	wup_tsk(TASK5)
 *	== TASK5��³����==
 *	38:	loc_mtx(MTX4)
 *	39:	tslp_tsk(10) -> E_TMOUT
 *	//		�㡧TASK1��TASK2��MTX4��TASK5
 *	== TASK1��³����==
 *	40:	loc_mtx(MTX1)
 *	//		�桧TASK1���㡧TASK2��MTX1��TASK1��MTX4��TASK5
 *	41:	loc_mtx(MTX4)
 *	//		�㡧TASK2��MTX1��TASK1��MTX4��TASK5��TASK1
 *	== TASK2��ͥ���١����==
 *	42:	loc_mtx(MTX4)
 *	//		MTX1��TASK1��MTX4��TASK5��TASK1��TASK2
 *	//		�����ॢ�����Ԥ�
 *	//		�⡧TASK5��MTX1��TASK1��MTX4��TASK5��TASK1��TASK2
 *	== TASK5��³����==
 *	43:	ini_mtx(MTX1)			... (B-1)
 *	//		�⡧TASK5��MTX4��TASK5��TASK2��TASK1
 *		get_pri(TASK1, &tskpri)
 *		assert(tskpri == LOW_PRIORITY)
 *	44:	unl_mtx(MTX4)
 *	//		�⡧TASK5��TASK2��MTX4��TASK2��TASK1
 *	45:	slp_tsk()
 *	//		�⡧TASK2��MTX4��TASK2��TASK1
 *	== TASK2��³����==
 *	46:	unl_mtx(MTX4)
 *	//		�⡧TASK1���㡧TASK2��MTX4��TASK1
 *	== TASK1��³����==
 *	47:	unl_mtx(MTX4)
 *	//		�㡧TASK1��TASK2
 *
 *	48:	wup_tsk(TASK5)
 *	== TASK5��³����==
 *	49:	loc_mtx(MTX4)
 *	50:	slp_tsk()
 *	//		�㡧TASK1��TASK2��MTX4��TASK5
 *	== TASK1��³����==
 *	51:	wup_tsk(TASK3)
 *	//		�桧TASK3���㡧TASK1��TASK2��MTX4��TASK5
 *	== TASK3��³����==
 *	52:	loc_mtx(MTX4)
 *	//		�㡧TASK1��TASK2��MTX4��TASK5��TASK3
 *	== TASK1��³����==
 *	53:	loc_mtx(MTX1)
 *		loc_mtx(MTX2)
 *	//		�桧TASK1���㡧TASK2��MTX1��TASK1��MTX2��TASK1��MTX4��TASK5��TASK3
 *	54:	loc_mtx(MTX4)
 *	//		�㡧TASK2��MTX1��TASK1��MTX2��TASK1��MTX4��TASK5��TASK3��TASK1
 *	== TASK2��³����==
 *	55:	wup_tsk(TASK4)
 *	== TASK4��³����==
 *	56:	loc_mtx(MTX4)
 *	//		�㡧TASK2��MTX1��TASK1��MTX2��TASK1��
 *	//								MTX4��TASK5��TASK3��TASK1��TASK4
 *	== TASK2��³����==
 *	57:	wup_tsk(TASK5)
 *	//		�⡧TASK5���㡧TASK2��MTX1��TASK1��MTX2��TASK1��
 *	//								MTX4��TASK5��TASK3��TASK1��TASK4
 *	== TASK5��³����==
 *	58:	ini_mtx(MTX1)			... (B-2)
 *	//		�⡧TASK5���㡧TASK2��MTX2��TASK1��MTX4��TASK5��TASK3��TASK1��TASK4
 *		get_pri(TASK1, &tskpri)
 *		assert(tskpri == MID_PRIORITY)
 *	59:	unl_mtx(MTX4)
 *	//		�⡧TASK5��TASK3���㡧TASK2��MTX2��TASK1��MTX4��TASK3��TASK1��TASK4
 *	60:	slp_tsk()
 *	//		�⡧TASK3���㡧TASK2��MTX2��TASK1��MTX4��TASK3��TASK1��TASK4
 *	== TASK3��³����==
 *	61:	unl_mtx(MTX4)
 *	//		�⡧TASK1���桧TASK3���㡧TASK2��MTX2��TASK1��MTX4��TASK1��TASK4
 *	== TASK1��³����==
 *	62:	unl_mtx(MTX4)
 *	//		�⡧TASK4���桧TASK1��TASK3���㡧TASK2��MTX2��TASK1��MTX4��TASK4
 *	== TASK4��³����==
 *	63:	unl_mtx(MTX4)
 *	//		�桧TASK4��TASK1��TASK3���㡧TASK2��MTX2��TASK1
 *	64:	slp_tsk()
 *	//		�桧TASK1��TASK3���㡧TASK2��MTX2��TASK1
 *	== TASK1��³����==
 *	65:	slp_tsk()
 *	//		�桧TASK3���㡧TASK2��MTX2��TASK1
 *	== TASK3��³����==
 *	66:	slp_tsk()
 *	//		�㡧TASK2��MTX2��TASK1
 *
 *	== TASK2��³����==
 *	67: wup_tsk(TASK5)
 *	== TASK5��³����==
 *	68:	loc_mtx(MTX4)
 *	69:	slp_tsk()
 *	//		�㡧TASK2��MTX4��TASK5
 *	== TASK2��³����==
 *	70:	wup_tsk(TASK3)
 *	== TASK3��³����==
 *	71:	loc_mtx(MTX4)
 *	//		�㡧TASK2��MTX4��TASK5��TASK3
 *	== TASK2��³����==
 *	72:	wup_tsk(TASK1)
 *	//		�桧TASK1���㡧TASK2��MTX4��TASK5
 *	== TASK1��³����==
 *	73:	loc_mtx(MTX3)
 *	//		�桧TASK1���㡧TASK2��MTX2��TASK1��MTX3��TASK1��MTX4��TASK5��TASK3
 *	74:	loc_mtx(MTX4)
 *	//		�㡧TASK2��MTX2��TASK1��MTX3��TASK1��MTX4��TASK5��TASK3��TASK1
 *	== TASK2��³����==
 *	75:	wup_tsk(TASK4)
 *	== TASK4��³����==
 *	76:	loc_mtx(MTX4)
 *	//		�㡧TASK2��MTX2��TASK1��MTX3��TASK1��
 *	//								MTX4��TASK5��TASK3��TASK1��TASK4
 *	== TASK2��³����==
 *	77:	wup_tsk(TASK5)
 *	//		�⡧TASK5���㡧TASK2��MTX2��TASK1��MTX3��TASK1��
 *	//								MTX4��TASK5��TASK3��TASK1��TASK4
 *	== TASK5��³����==
 *	78:	ini_mtx(MTX3)			... (B-3)
 *	//		�⡧TASK5���㡧TASK2��MTX2��TASK1��MTX4��TASK5��TASK3��TASK1��TASK4
 *		get_pri(TASK1, &tskpri)
 *		assert(tskpri == MID_PRIORITY)
 *	79:	unl_mtx(MTX4)
 *	//		�⡧TASK5��TASK3���㡧TASK2��MTX2��TASK1��MTX4��TASK3��TASK1��TASK4
 *	80:	slp_tsk()
 *	//		�⡧TASK3���㡧TASK2��MTX2��TASK1��MTX4��TASK3��TASK1��TASK4
 *	== TASK3��³����==
 *	81:	unl_mtx(MTX4)
 *	//		�⡧TASK1���桧TASK3���㡧TASK2��MTX2��TASK1��MTX4��TASK1��TASK4
 *	== TASK1��³����==
 *	82:	unl_mtx(MTX4)
 *	//		�⡧TASK4���桧TASK1��TASK3���㡧TASK2��MTX2��TASK1��MTX4��TASK4
 *	== TASK4��³����==
 *	83:	unl_mtx(MTX4)
 *	//		�桧TASK4��TASK1��TASK3���㡧TASK2��MTX2��TASK1
 *	84:	slp_tsk()
 *	//		�桧TASK1��TASK3���㡧TASK2��MTX2��TASK1
 *	== TASK1��³����==
 *	85:	unl_mtx(MTX2)
 *	//		�桧TASK3���㡧TASK1��TASK2
 *	== TASK3��³����==
 *	86:	slp_tsk()
 *	//		�㡧TASK1��TASK2
 *
 *	== TASK1��³����==
 *	87:	sus_tsk(TASK2)
 *	//		�㡧TASK1
 *	88:	loc_mtx(MTX1)
 *	//		�桧TASK1��MTX1��TASK1
 *	89:	wup_tsk(TASK3)
 *	//		�桧TASK1��TASK3��MTX1��TASK1
 *	90:	rot_rdq(MID_PRIORITY)
 *	//		�桧TASK3��TASK1��MTX1��TASK1
 *	== TASK3��³����==
 *	91:	loc_mtx(MTX1) -> E_DLT
 *	//		�桧TASK1��MTX1��TASK1��TASK3
 *	== TASK1��³����==
 *	92:	wup_tsk(TASK5)
 *	//		�⡧TASK5���桧TASK1��MTX1��TASK1��TASK3
 *	== TASK5��³����==
 *	93:	wup_tsk(TASK4)
 *	//		�⡧TASK5���桧TASK1��TASK4��MTX1��TASK1��TASK3
 *	94:	ini_mtx(MTX1)			... (C-1)
 *	//		�⡧TASK5���桧TASK4��TASK3���㡧TASK1
 *	95:	ext_tsk() -> noreturn
 *	//		�桧TASK4��TASK3���㡧TASK1
 *	== TASK4��³����==
 *	96:	ext_tsk() -> noreturn
 *	//		�桧TASK3���㡧TASK1
 *	== TASK3��³����==
 *	97:	slp_tsk()
 *	//		�㡧TASK1
 *
 *	== TASK1��³����==
 *	98:	loc_mtx(MTX1)
 *	//		�桧TASK1��MTX1��TASK1
 *	99:	wup_tsk(TASK3)
 *	//		�桧TASK1��TASK3��MTX1��TASK1
 * 100:	rot_rdq(MID_PRIORITY)
 *	//		�桧TASK3��TASK1��MTX1��TASK1
 *	== TASK3��³����==
 * 101:	loc_mtx(MTX1) -> E_DLT
 *	//		�桧TASK1��MTX1��TASK1��TASK3
 *	== TASK1��³����==
 * 102:	rsm_tsk(TASK2)
 *	//		�桧TASK1���㡧TASK2��MTX1��TASK1��TASK3
 * 103:	slp_tsk()
 *	//		�㡧TASK2��MTX1��TASK1��TASK3
 *	== TASK2��³����==
 * 104:	ini_mtx(MTX1)			... (C-2)
 *	//		�桧TASK3���㡧TASK2
 *	== TASK3��³����==
 * 105:	ext_tsk() -> noreturn
 *	//		�㡧TASK2
 *	== TASK2��³����==
 * 106:	ter_tsk(TASK1)
 * 107:	END
 */

#include <kernel.h>
#include <t_syslog.h>
#include "syssvc/logtask.h"
#include "kernel_cfg.h"
#include "test_lib.h"
#include "test_mutex5.h"

extern ER	bit_mutex(void);

void
task1(intptr_t exinf)
{
	ER		ercd;

	set_bit_func(bit_mutex);

	check_point(1);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(2);
	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(3);
	ercd = act_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(6);
	ercd = sus_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(7);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	ercd = loc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(8);
	ercd = act_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(9);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	check_point(10);
	ercd = rot_rdq(MID_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(11);
	ercd = act_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(12);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(13);
	ercd = ena_dsp();
	check_ercd(ercd, E_OK);

	check_point(17);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(20);
	ercd = loc_mtx(MTX3);
	check_ercd(ercd, E_OK);

	check_point(21);
	ercd = wup_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(22);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	check_point(23);
	ercd = rot_rdq(MID_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(24);
	ercd = wup_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(25);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(26);
	ercd = ena_dsp();
	check_ercd(ercd, E_OK);

	check_point(30);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(33);
	ercd = rsm_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(34);
	ercd = ini_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(37);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(40);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(41);
	ercd = loc_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(47);
	ercd = unl_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(48);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(51);
	ercd = wup_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(53);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	ercd = loc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(54);
	ercd = loc_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(62);
	ercd = unl_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(65);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(73);
	ercd = loc_mtx(MTX3);
	check_ercd(ercd, E_OK);

	check_point(74);
	ercd = loc_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(82);
	ercd = unl_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(85);
	ercd = unl_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(87);
	ercd = sus_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(88);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(89);
	ercd = wup_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(90);
	ercd = rot_rdq(MID_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(92);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(98);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(99);
	ercd = wup_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(100);
	ercd = rot_rdq(MID_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(102);
	ercd = rsm_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(103);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(0);
}

void
task2(intptr_t exinf)
{
	ER		ercd;

	check_point(42);
	ercd = loc_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(46);
	ercd = unl_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(55);
	ercd = wup_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(57);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(67);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(70);
	ercd = wup_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(72);
	ercd = wup_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(75);
	ercd = wup_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(77);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(104);
	ercd = ini_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(106);
	ercd = ter_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_finish(107);

	check_point(0);
}

void
task3(intptr_t exinf)
{
	ER		ercd;

	check_point(16);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(29);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(52);
	ercd = loc_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(61);
	ercd = unl_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(66);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(71);
	ercd = loc_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(81);
	ercd = unl_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(86);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(91);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_DLT);

	check_point(97);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(101);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_DLT);

	check_point(105);
	ercd = ext_tsk();

	check_point(0);
}

void
task4(intptr_t exinf)
{
	ER		ercd;
	PRI		tskpri;

	check_point(18);
	ercd = wup_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(19);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(31);
	ercd = wup_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(32);
	ercd = rot_rdq(MID_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(35);
	ercd = get_pri(TASK1, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == LOW_PRIORITY);

	check_point(36);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(56);
	ercd = loc_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(63);
	ercd = unl_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(64);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(76);
	ercd = loc_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(83);
	ercd = unl_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(84);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(96);
	ercd = ext_tsk();

	check_point(0);
}

void
task5(intptr_t exinf)
{
	ER		ercd;
	PRI		tskpri;

	check_point(4);
	ercd = ini_mtx(MTX1);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TASK1, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == LOW_PRIORITY);

	check_point(5);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(14);
	ercd = ini_mtx(MTX1);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TASK1, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == MID_PRIORITY);

	check_point(15);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(27);
	ercd = ini_mtx(MTX3);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TASK1, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == MID_PRIORITY);

	check_point(28);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(38);
	ercd = loc_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(39);
	ercd = tslp_tsk(10);
	check_ercd(ercd, E_TMOUT);

	check_point(43);
	ercd = ini_mtx(MTX1);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TASK1, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == LOW_PRIORITY);

	check_point(44);
	ercd = unl_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(45);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(49);
	ercd = loc_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(50);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(58);
	ercd = ini_mtx(MTX1);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TASK1, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == MID_PRIORITY);

	check_point(59);
	ercd = unl_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(60);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(68);
	ercd = loc_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(69);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(78);
	ercd = ini_mtx(MTX3);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TASK1, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == MID_PRIORITY);

	check_point(79);
	ercd = unl_mtx(MTX4);
	check_ercd(ercd, E_OK);

	check_point(80);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(93);
	ercd = wup_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(94);
	ercd = ini_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(95);
	ercd = ext_tsk();

	check_point(0);
}
