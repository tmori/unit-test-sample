/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2009 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: test_mutex8.c 1696 2010-01-01 16:01:25Z ertl-hiro $
 */

/* 
 *		�ߥ塼�ƥå����Υƥ���(8)
 *
 * �ڥƥ��Ȥ���Ū��
 *
 *  ͥ���پ�¥ߥ塼�ƥå������Ф��ơ�chg_pri��ȼ���ߥ塼�ƥå�����Ϣ��
 *  ͥ�����ѹ�����������Ū�˥ƥ��Ȥ��롥��������change_priority��
 *  mutex_calc_priority�����Ƥˤ�Ƨ�߹��ޤʤ���
 *
 * �ڥƥ��ȹ��ܡ�
 *
 *	(A) �������Υ١���ͥ���٤��ѹ�������chg_pri��
 *		(A-1) �оݥ��������¹ԤǤ�����֤ǡ��ߥ塼�ƥå������å�����
 *			  ���ʤ����ˡ�Ʊ��ͥ������Ǥ�ͥ���̤�����ˤʤ뤳��
 *		(A-2) �оݥ��������¹ԤǤ�����֤ǡ�ͥ���پ�¥ߥ塼�ƥå�����
 *			  ���Υߥ塼�ƥå����Τߤ��å����Ƥ�����ˡ�Ʊ��ͥ����
 *			  ��Ǥ�ͥ���̤�����ˤʤ뤳��
 *		(A-3) �оݥ��������¹ԤǤ�����֤ǡ�ͥ���پ�¥ߥ塼�ƥå�����
 *			  ��å����Ƥ�����ˡ�Ʊ��ͥ������Ǥ�ͥ���̤��Ѥ���
 *			  ������
 *		(A-4) �оݥ��������Ԥ����֤ǡ�ͥ���ٽ���Ԥ�����ˤĤʤ���Ƥ�
 *			  �ꡤ�ߥ塼�ƥå������å����Ƥ��ʤ����ˡ�ͥ���٤�����
 *			  ���ѹ����졤Ʊ��ͥ������Ǥν�����Ǹ�ˤʤ뤳��
 *		(A-5) �оݥ��������Ԥ����֤ǡ�ͥ���ٽ���Ԥ�����ˤĤʤ���Ƥ�
 *			  �ꡤͥ���پ�¥ߥ塼�ƥå����ʳ��Υߥ塼�ƥå����Τߤ���
 *			  �����Ƥ�����ˡ�ͥ���٤��������ѹ����졤Ʊ��ͥ�������
 *			  �ν�����Ǹ�ˤʤ뤳��
 *		(A-6) �оݥ��������Ԥ����֤ǡ�ͥ���ٽ���Ԥ�����ˤĤʤ���Ƥ�
 *			  �ꡤͥ���پ�¥ߥ塼�ƥå������å����Ƥ�����ˡ�Ʊ��
 *			  ͥ������Ǥν�����Ѥ��ʤ�����
 *	(B) �������Υ١���ͥ���٤��ѹ�������chg_pri�ˤ�E_ILUSE���顼
 *		(B-1) �оݥ���������å����Ƥ���ߥ塼�ƥå����ξ��ͥ���٤��
 *			  �⡤�١���ͥ���٤�⤯���褦�Ȥ�������E_ILUSE���顼�ˤʤ�
 *			  ����
 *		(B-2) �оݥ�������ͥ���پ�¥ߥ塼�ƥå������å����Ƥ��Ƥ⡤
 *			  ��å����Ƥ���ߥ塼�ƥå����ξ��ͥ���٤��⡤�١���ͥ
 *			  ���٤�⤯���褦�Ȥ��ʤ����ˤϡ�E_ILUSE���顼�ˤʤ�ʤ�
 *			  ����
 *		(B-3) �оݥ���������å����ԤäƤ���ߥ塼�ƥå����ξ��ͥ����
 *			  ���⡤�١���ͥ���٤�⤯���褦�Ȥ�������E_ILUSE���顼��
 *			  �ʤ뤳��
 *		(B-4) �оݥ�������ͥ���پ�¥ߥ塼�ƥå����Ԥ��Ǥ��äƤ⡤���
 *			  �����ԤäƤ���ߥ塼�ƥå����ξ��ͥ���٤��⡤�١���ͥ
 *			  ���٤�⤯���褦�Ȥ��ʤ����ˤϡ�E_ILUSE���顼�ˤʤ�ʤ�
 *			  ����
 *
 * �ڥƥ��ȹ��ܤμ¸���ˡ��
 *
 *	(A-1)
 *		��ͥ���٥�������TASK1�ˤ��¹Բ�ǽ���֤λ��ˡ���ͥ���٥�����
 *		��TASK5�ˤ���TASK1����ͥ���٤�chg_pri����ȡ��¹Բ�ǽ���֤�¾��
 *		��ͥ���٥�������TASK4�ˤ��⡤ͥ���̤��㤯�ʤ뤳�Ȥ��ǧ���롥
 *	(A-2)
 *		��ͥ���٥�������TASK1�ˤ�ͥ���ٽ�ߥ塼�ƥå�����MTX3�ˤ��å�
 *		�����¹Բ�ǽ���֤λ��ˡ���ͥ���٥�������TASK5�ˤ���TASK1����ͥ
 *		���٤�chg_pri����ȡ��¹Բ�ǽ���֤�¾����ͥ���٥�������TASK4��
 *		���⡤ͥ���̤��㤯�ʤ뤳�Ȥ��ǧ���롥
 *	(A-3)
 *		��ͥ���٥�������TASK1�ˤ���ͥ���پ�¥ߥ塼�ƥå�����MTX1�ˤ���
 *		�������¹Բ�ǽ���֤λ��ˡ���ͥ���٥�������TASK5�ˤ���TASK1����
 *		ͥ���٤�chg_pri����ȡ�TASK1��ͥ���٤��Ѳ����ʤ����Ȥ��ǧ���롥
 *		�ޤ����¹Բ�ǽ���֤���ͥ���٥�������2�ġ�TASK2��TASK3�ˤ��Ѱդ�
 *		�Ƥ�����ͥ���̤��Ѥ��ʤ����Ȥ��ǧ���롥
 *	(A-4)
 *		��ͥ���٥�������TASK1�ˤ���ͥ���پ�¥ߥ塼�ƥå�����MTX2�ˤ��Ԥ�
 *		�Ƥ�����ˡ���ͥ���٥�������TASK5�ˤ���TASK1����ͥ���٤�
 *		chg_pri����ȡ�MTX2���ԤäƤ���¾����ͥ���٥�������TASK4�ˤ��
 *		�⡤�Ԥ�������Ǥν������ˤʤ뤳�Ȥ��ǧ���롥
 *	(A-5)
 *		��ͥ���٥�������TASK1�ˤ�ͥ���ٽ�ߥ塼�ƥå�����MTX3�ˤ��å�
 *		������ͥ���پ�¥ߥ塼�ƥå�����MTX2�ˤ��ԤäƤ�����ˡ���ͥ���٥�
 *		������TASK5�ˤ���TASK1����ͥ���٤�chg_pri����ȡ�MTX2���ԤäƤ�
 *		��¾����ͥ���٥�������TASK4�ˤ��⡤�Ԥ�������Ǥν�����Ѥ��
 *		�ʤ����Ȥ��ǧ���롥
 *	(A-6)
 *		��ͥ���٥�������TASK1�ˤ���ͥ���پ�¥ߥ塼�ƥå�����MTX1�ˤ���
 *		��������ͥ���پ�¥ߥ塼�ƥå�����MTX2�ˤ��ԤäƤ�����ˡ���ͥ
 *		���٥�������TASK5�ˤ���TASK1����ͥ���٤�chg_pri����ȡ�TASK1��
 *		ͥ���٤��Ѳ����ʤ����Ȥ��ǧ���롥�ޤ���MTX2���ԤäƤ�����ͥ��
 *		�٥�������2�ġ�TASK2��TASK3�ˤ��Ѱդ��Ƥ������Ԥ�������Ǥν��
 *		���Ѥ��ʤ����Ȥ��ǧ���롥
 *	(B-1)
 *		��ͥ���٥�������TASK1�ˤ���ͥ���پ�¥ߥ塼�ƥå�����MTX1�ˤ���
 *		�������¹Բ�ǽ���֤λ��ˡ���ͥ���٥�������TASK5�ˤ���TASK1���
 *		ͥ���٤�chg_pri����ȡ�E_ILUSE���顼�ˤʤ뤳�Ȥ��ǧ���롥
 *	(B-2)
 *		(A-3)�Υƥ��ȹ��ܤǡ�chg_pri��E_ILUSE���顼�ˤʤ�ʤ����Ȥǳ�ǧ
 *		�Ǥ��Ƥ��롥
 *	(B-3)
 *		��ͥ���٥�������TASK2�ˤ���ͥ���پ�¥ߥ塼�ƥå�����MTX1�ˤΥ��
 *		�����ԤäƤ�����ˡ���ͥ���٥�������TASK5�ˤ���TASK2���ͥ����
 *		��chg_pri����ȡ�E_ILUSE���顼�ˤʤ뤳�Ȥ��ǧ���롥
 *	(B-4)
 *		(A-6)�Υƥ��ȹ��ܤǡ�chg_pri��E_ILUSE���顼�ˤʤ�ʤ����Ȥǳ�ǧ
 *		�Ǥ��Ƥ��롥
 *
 * �ڻ��ѥ꥽������
 *
 *	TASK1: ��ͥ���٥��������ᥤ�󥿥������ǽ餫�鵯ư
 *	TASK2: ��ͥ���٥�����
 *	TASK3: ��ͥ���٥�����
 *	TASK4: ��ͥ���٥�����
 *	TASK5: ��ͥ���٥�����
 *	MTX1: �ߥ塼�ƥå�����TA_CEILING°������¤���ͥ���١�
 *	MTX2: �ߥ塼�ƥå�����TA_CEILING°������¤Ϲ�ͥ���١�
 *	MTX3: �ߥ塼�ƥå�����TA_TPRI°����
 *
 * �ڥƥ��ȥ������󥹡�
 *
 *	== TASK1��ͥ���١����==
 *		call(set_bit_func(bit_mutex))
 *	1:	act_tsk(TASK4)
 *	2:	act_tsk(TASK5)
 *	//		�⡧TASK5���桧TASK1���㡧TASK4
 *	== TASK5��ͥ���١����==
 *	3:	chg_pri(TASK1, LOW_PRIORITY)		... (A-1)
 *	//		�⡧TASK5���㡧TASK4��TASK1
 *	4:	slp_tsk()
 *	== TASK4��ͥ���١����==
 *	5:	slp_tsk()
 *	== TASK1��³����==
 *	6:	chg_pri(TSK_SELF, TPRI_INI)
 *
 *	7:	loc_mtx(MTX3)
 *	8:	wup_tsk(TASK4)
 *	9:	wup_tsk(TASK5)
 *	//		�⡧TASK5���桧TASK1���㡧TASK4��MTX3��TASK1
 *	== TASK5��³����==
 *	10:	chg_pri(TASK1, LOW_PRIORITY)		... (A-2)
 *	//		�⡧TASK5���㡧TASK4��TASK1��MTX3��TASK1
 *	11:	slp_tsk()
 *	== TASK4��³����==
 *	12:	slp_tsk()
 *	== TASK1��³����==
 *	13:	unl_mtx(MTX3)
 *		chg_pri(TSK_SELF, TPRI_INI)
 *
 *	14:	loc_mtx(MTX1)
 *	15:	act_tsk(TASK2)
 *	16:	dis_dsp()
 *	17:	rot_rdq(MID_PRIORITY)
 *	18:	act_tsk(TASK3)
 *	//		�桧TASK2��TASK1��TASK3��MTX1��TASK1
 *	19:	wup_tsk(TASK5)
 *	//		�⡧TASK5���桧TASK2��TASK1��TASK3��MTX1��TASK1
 *	20:	ena_dsp()
 *	== TASK5��³����==
 *	21:	chg_pri(TASK1, LOW_PRIORITY)		... (A-3)(B-2)
 *	//		�⡧TASK5���桧TASK2��TASK1��TASK3��MTX1��TASK1
 *		get_pri(TASK1, &tskpri)
 *		assert(tskpri == MID_PRIORITY)
 *	22:	slp_tsk()
 *	//		�桧TASK2��TASK1��TASK3��MTX1��TASK1
 *	== TASK2��³����==
 *	23:	slp_tsk()
 *	//		�桧TASK1��TASK3��MTX1��TASK1
 *	== TASK1��³����==
 *	24:	unl_mtx(MTX1)
 *	//		�桧TASK3���㡧TASK1
 *	== TASK3��³����==
 *	25:	slp_tsk()
 *	== TASK1��³����==
 *	26:	chg_pri(TSK_SELF, TPRI_INI)
 *
 *	27:	wup_tsk(TASK5)
 *	== TASK5��³����==
 *	28:	loc_mtx(MTX2)
 *	29:	tslp_tsk(10) -> E_TMOUT
 *	== TASK1��³����==
 *	30:	wup_tsk(TASK4)
 *	31:	loc_mtx(MTX2)
 *	== TASK4��³����==
 *	32:	loc_mtx(MTX2)
 *	//		MTX2��TASK5��TASK1��TASK4
 *	//		�����ॢ�����Ԥ�
 *	//		�⡧TASK5��MTX2��TASK5��TASK1��TASK4
 *	== TASK5��³����==
 *	33:	chg_pri(TASK1, LOW_PRIORITY)		... (A-4)
 *	//		�⡧TASK5��MTX2��TASK5��TASK4��TASK1
 *	34:	unl_mtx(MTX2)
 *	//		�⡧TASK5��TASK4��MTX2��TASK4��TASK1
 *	35:	slp_tsk()
 *	//		�⡧TASK4��MTX2��TASK4��TASK1
 *	== TASK4��³����==
 *	36:	unl_mtx(MTX2)
 *	//		�⡧TASK1���㡧TASK4��MTX2��TASK1
 *	== TASK1��³����==
 *	37:	unl_mtx(MTX2)
 *	//		�㡧TASK1��TASK4
 *	38:	chg_pri(TSK_SELF, TPRI_INI)
 *
 *	39:	loc_mtx(MTX3)
 *	40:	wup_tsk(TASK5)
 *	//		�⡧TASK5���桧TASK1���㡧TASK4��MTX3��TASK1
 *	== TASK5��³����==
 *	41:	loc_mtx(MTX2)
 *	42:	tslp_tsk(10) -> E_TMOUT
 *	== TASK1��³����==
 *	43:	loc_mtx(MTX2)
 *	== TASK4��³����==
 *	44:	loc_mtx(MTX2)
 *	//		MTX2��TASK5��TASK1��TASK4��MTX3��TASK1
 *	//		�����ॢ�����Ԥ�
 *	//		�⡧TASK5��MTX2��TASK5��TASK1��TASK4��MTX3��TASK1
 *	== TASK5��³����==
 *	45:	chg_pri(TASK1, LOW_PRIORITY)		... (A-5)
 *	//		�⡧TASK5��MTX2��TASK5��TASK4��TASK1��MTX3��TASK1
 *	46:	unl_mtx(MTX2)
 *	//		�⡧TASK5��TASK4��MTX2��TASK4��TASK1��MTX3��TASK1
 *	47:	slp_tsk()
 *	//		�⡧TASK4��MTX2��TASK4��TASK1��MTX3��TASK1
 *	== TASK4��³����==
 *	48:	unl_mtx(MTX2)
 *	//		�⡧TASK1���㡧TASK4��MTX2��TASK1��MTX3��TASK1
 *	== TASK1��³����==
 *	49:	unl_mtx(MTX2)
 *	//		�㡧TASK1��TASK4��MTX3��TASK1
 *	50:	unl_mtx(MTX3)
 *	//		�㡧TASK1��TASK4
 *	51:	ter_tsk(TASK4)
 *	52:	chg_pri(TSK_SELF, TPRI_INI)
 *
 *	53:	loc_mtx(MTX1)
 *	54:	wup_tsk(TASK5)
 *	//		�⡧TASK5���桧TASK1��MTX1��TASK1
 *	== TASK5��³����==
 *	55:	loc_mtx(MTX2)
 *	56:	tslp_tsk(10) -> E_TMOUT
 *	//		�桧TASK1��MTX1��TASK1��MTX2��TASK5
 *	== TASK1��³����==
 *	57:	wup_tsk(TASK2)
 *	58:	rot_rdq(MID_PRIORITY)
 *	== TASK2��³����==
 *	59:	loc_mtx(MTX2)
 *	//		�桧TASK1��MTX1��TASK1��MTX2��TASK5��TASK2
 *	== TASK1��³����==
 *	60:	wup_tsk(TASK3)
 *	61:	loc_mtx(MTX2)
 *	//		�桧TASK3��MTX1��TASK1��MTX2��TASK5��TASK2��TASK1
 *	== TASK3��³����==
 *	62:	loc_mtx(MTX2)
 *	//		MTX1��TASK1��MTX2��TASK5��TASK2��TASK1��TASK3
 *	//		�����ॢ�����Ԥ�
 *	//		�⡧TASK5��MTX1��TASK1��MTX2��TASK5��TASK2��TASK1��TASK3
 *	== TASK5��³����==
 *	63:	chg_pri(TASK1, LOW_PRIORITY)		... (A-6)(B-4)
 *	//		�⡧TASK5��MTX1��TASK1��MTX2��TASK5��TASK2��TASK1��TASK3
 *		get_pri(TASK1, &tskpri)
 *		assert(tskpri == MID_PRIORITY)
 *	64:	unl_mtx(MTX2)
 *	//		�⡧TASK5��TASK2��MTX1��TASK1��MTX2��TASK2��TASK1��TASK3
 *	65:	slp_tsk()
 *	//		�⡧TASK2��MTX1��TASK1��MTX2��TASK2��TASK1��TASK3
 *	== TASK2��³����==
 *	66:	unl_mtx(MTX2)
 *	//		�⡧TASK1���桧TASK2��MTX1��TASK1��MTX2��TASK1��TASK3
 *	== TASK1��³����==
 *	67:	unl_mtx(MTX2)
 *	//		�⡧TASK3���桧TASK1��TASK2��MTX1��TASK1��MTX2��TASK3
 *	== TASK3��³����==
 *	68:	unl_mtx(MTX2)
 *	//		�桧TASK3��TASK1��TASK2��MTX1��TASK1
 *	69:	ext_tsk() -> noreturn
 *	//		�桧TASK1��TASK2��MTX1��TASK1
 *	== TASK1��³����==
 *	70:	chg_pri(TSK_SELF, TPRI_INI)
 *	//		�桧TASK1��TASK2��MTX1��TASK1
 *
 *	71:	rot_rdq(MID_PRIORITY)
 *	//		�桧TASK2��TASK1��MTX1��TASK1
 *	== TASK2��³����==
 *	72:	loc_mtx(MTX1)
 *	//		�桧TASK1��MTX1��TASK1��TASK2
 *	== TASK1��³����==
 *	73:	wup_tsk(TASK5)
 *	//		�⡧TASK5���桧TASK1��MTX1��TASK1��TASK2
 *	== TASK5��³����==
 *	74:	chg_pri(TASK1, HIGH_PRIORITY) -> E_ILUSE	... (B-1)
 *	75:	chg_pri(TASK2, HIGH_PRIORITY) -> E_ILUSE	... (B-3)
 *	76:	ext_tsk() -> noreturn
 *	//		�桧TASK1��MTX1��TASK1��TASK2
 *	== TASK1��³����==
 *	77:	unl_mtx(MTX1)
 *	//		�桧TASK1��TASK2��MTX1��TASK2
 *	78:	ext_tsk() -> noreturn
 *	== TASK2��³����==
 *	79:	unl_mtx(MTX1)
 *	80:	END
 */

#include <kernel.h>
#include <t_syslog.h>
#include "syssvc/logtask.h"
#include "kernel_cfg.h"
#include "test_lib.h"
#include "test_mutex8.h"

extern ER	bit_mutex(void);

void
task1(intptr_t exinf)
{
	ER		ercd;

	set_bit_func(bit_mutex);

	check_point(1);
	ercd = act_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(2);
	ercd = act_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(6);
	ercd = chg_pri(TSK_SELF, TPRI_INI);
	check_ercd(ercd, E_OK);

	check_point(7);
	ercd = loc_mtx(MTX3);
	check_ercd(ercd, E_OK);

	check_point(8);
	ercd = wup_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(9);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(13);
	ercd = unl_mtx(MTX3);
	check_ercd(ercd, E_OK);

	ercd = chg_pri(TSK_SELF, TPRI_INI);
	check_ercd(ercd, E_OK);

	check_point(14);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(15);
	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(16);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	check_point(17);
	ercd = rot_rdq(MID_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(18);
	ercd = act_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(19);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(20);
	ercd = ena_dsp();
	check_ercd(ercd, E_OK);

	check_point(24);
	ercd = unl_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(26);
	ercd = chg_pri(TSK_SELF, TPRI_INI);
	check_ercd(ercd, E_OK);

	check_point(27);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(30);
	ercd = wup_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(31);
	ercd = loc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(37);
	ercd = unl_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(38);
	ercd = chg_pri(TSK_SELF, TPRI_INI);
	check_ercd(ercd, E_OK);

	check_point(39);
	ercd = loc_mtx(MTX3);
	check_ercd(ercd, E_OK);

	check_point(40);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(43);
	ercd = loc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(49);
	ercd = unl_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(50);
	ercd = unl_mtx(MTX3);
	check_ercd(ercd, E_OK);

	check_point(51);
	ercd = ter_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(52);
	ercd = chg_pri(TSK_SELF, TPRI_INI);
	check_ercd(ercd, E_OK);

	check_point(53);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(54);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(57);
	ercd = wup_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(58);
	ercd = rot_rdq(MID_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(60);
	ercd = wup_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(61);
	ercd = loc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(67);
	ercd = unl_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(70);
	ercd = chg_pri(TSK_SELF, TPRI_INI);
	check_ercd(ercd, E_OK);

	check_point(71);
	ercd = rot_rdq(MID_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(73);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(77);
	ercd = unl_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(78);
	ercd = ext_tsk();

	check_point(0);
}

void
task2(intptr_t exinf)
{
	ER		ercd;

	check_point(23);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(59);
	ercd = loc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(66);
	ercd = unl_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(72);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(79);
	ercd = unl_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_finish(80);

	check_point(0);
}

void
task3(intptr_t exinf)
{
	ER		ercd;

	check_point(25);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(62);
	ercd = loc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(68);
	ercd = unl_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(69);
	ercd = ext_tsk();

	check_point(0);
}

void
task4(intptr_t exinf)
{
	ER		ercd;

	check_point(5);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(12);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(32);
	ercd = loc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(36);
	ercd = unl_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(44);
	ercd = loc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(48);
	ercd = unl_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(0);
}

void
task5(intptr_t exinf)
{
	ER		ercd;
	PRI		tskpri;

	check_point(3);
	ercd = chg_pri(TASK1, LOW_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(4);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(10);
	ercd = chg_pri(TASK1, LOW_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(11);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(21);
	ercd = chg_pri(TASK1, LOW_PRIORITY);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TASK1, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == MID_PRIORITY);

	check_point(22);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(28);
	ercd = loc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(29);
	ercd = tslp_tsk(10);
	check_ercd(ercd, E_TMOUT);

	check_point(33);
	ercd = chg_pri(TASK1, LOW_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(34);
	ercd = unl_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(35);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(41);
	ercd = loc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(42);
	ercd = tslp_tsk(10);
	check_ercd(ercd, E_TMOUT);

	check_point(45);
	ercd = chg_pri(TASK1, LOW_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(46);
	ercd = unl_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(47);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(55);
	ercd = loc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(56);
	ercd = tslp_tsk(10);
	check_ercd(ercd, E_TMOUT);

	check_point(63);
	ercd = chg_pri(TASK1, LOW_PRIORITY);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TASK1, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == MID_PRIORITY);

	check_point(64);
	ercd = unl_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(65);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(74);
	ercd = chg_pri(TASK1, HIGH_PRIORITY);
	check_ercd(ercd, E_ILUSE);

	check_point(75);
	ercd = chg_pri(TASK2, HIGH_PRIORITY);
	check_ercd(ercd, E_ILUSE);

	check_point(76);
	ercd = ext_tsk();

	check_point(0);
}
