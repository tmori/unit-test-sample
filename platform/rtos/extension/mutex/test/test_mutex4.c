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
 *  @(#) $Id: test_mutex4.c 1696 2010-01-01 16:01:25Z ertl-hiro $
 */

/* 
 *		�ߥ塼�ƥå����Υƥ���(4)
 *
 * �ڥƥ��Ȥ���Ū��
 *
 *  ͥ���پ�¥ߥ塼�ƥå������Ф��ơ�loc_mtx��unl_mtx��ȼ��ͥ���٤���
 *  ������������Ū�˥ƥ��Ȥ��롥��������change_priority��
 *  mutex_calc_priority�����Ƥˤ�Ƨ�߹��ޤʤ���
 *
 * �ڥƥ��ȹ��ܡ�
 *
 *	(A) �ߥ塼�ƥå����Υ�å�������loc_mtx�ˤ�ȼ��ͥ�����ѹ�
 *		(A-1) ��å������ߥ塼�ƥå�����ͥ���پ�¤����������θ���ͥ��
 *			  �٤���⤤���ˡ�����������ͥ���٤�����ͥ���پ�¤ޤ�
 *			  �夬�뤳�ȡ��ޤ���Ʊ��ͥ������Ǥ�ͥ���̤��ǹ�ˤʤ뤳
 *			  ��
 *		(A-2) ��å������ߥ塼�ƥå�����ͥ���پ�¤����������θ���ͥ��
 *			  �٤�Ʊ�����ˡ�����������ͥ���٤��Ѥ��ʤ����ȡ��ޤ���
 *			  Ʊ��ͥ������Ǥ�ͥ���̤��Ѥ��ʤ�����
 *		(A-3) ��å������ߥ塼�ƥå�����ͥ���پ�¤����������θ���ͥ��
 *			  �٤����㤤���ˡ�����������ͥ���٤��Ѥ��ʤ����ȡ���
 *			  ����Ʊ��ͥ������Ǥ�ͥ���̤��Ѥ��ʤ�����
 *	(B) �ߥ塼�ƥå����Υ�å����������unl_mtx�ˤ�ȼ����å��������
 * 		��������ͥ�����ѹ�
 *		(B-1) ��å���������ߥ塼�ƥå����ξ��ͥ���٤����������θ���
 *			  ͥ���٤�Ʊ���ǡ��ߥ塼�ƥå����Υ�å������ͥ���٤�����
 *			  ��٤����ˡ�����������ͥ���٤�Ŭ�ڤ˲������뤳�ȡ���
 *			  ����Ʊ��ͥ������Ǥ�ͥ���̤��ǹ�ˤʤ뤳��
 *		(B-2) ��å���������ߥ塼�ƥå����ξ��ͥ���٤����������θ���
 *			  ͥ���٤�Ʊ���ǡ��ߥ塼�ƥå����Υ�å������ͥ���٤��Ѥ�
 *			  ��٤��Ǥʤ����ˡ�����������ͥ���٤��Ѥ��ʤ����ȡ���
 *			  ����Ʊ��ͥ������Ǥ�ͥ���̤��Ѥ��ʤ�����
 *		(B-3) ��å���������ߥ塼�ƥå����ξ��ͥ���٤����������θ���
 *			  ͥ���٤����㤤���ˡ�����������ͥ���٤��Ѥ��ʤ����ȡ�
 *			  �ޤ���Ʊ��ͥ������Ǥ�ͥ���̤��Ѥ��ʤ�����
 *	(C) �ߥ塼�ƥå����Υ�å����������unl_mtx�ˤ�ȼ���ߥ塼�ƥå�����
 *		��å�������������ͥ�����ѹ�
 *		(C-1) �ߥ塼�ƥå�����ͥ���پ�¤������˥ߥ塼�ƥå������å�
 *			  �����������θ���ͥ���٤���⤤���ˡ�������������ͥ��
 *			  �٤�����ͥ���پ�¤ޤǾ夬�뤳�ȡ��ޤ���Ʊ��ͥ������Ǥ�
 *			  ͥ���̤�����ˤʤ뤳��
 *		(C-2) �ߥ塼�ƥå�����ͥ���پ�¤������˥ߥ塼�ƥå������å�
 *			  �����������θ���ͥ���٤�Ʊ�����ˡ�������������ͥ���٤�
 *			  �Ѥ��ʤ����ȡ��ޤ���Ʊ��ͥ������Ǥ�ͥ���̤�����ˤ�
 *			  �뤳��
 *		(C-3) �ߥ塼�ƥå�����ͥ���پ�¤������˥ߥ塼�ƥå������å�
 *			  �����������θ���ͥ���٤����㤤���ˡ�������������ͥ��
 *			  �٤��Ѥ��ʤ����ȡ��ޤ���Ʊ��ͥ������Ǥ�ͥ���̤�����
 *			  �ˤʤ뤳��
 *	(D) �ߥ塼�ƥå����Υ�å�������loc_mtx�ˤ�E_ILUSE���顼
 *		(D-1) ���������Υ١���ͥ���٤�����å����褦�Ȥ����ߥ塼�ƥå�
 *			  ���ξ��ͥ���٤���⤤����E_ILUSE���顼�ˤʤ뤳��
 *		(D-2) ���������Υ١���ͥ���٤�����å����褦�Ȥ����ߥ塼�ƥå�
 *			  ���ξ��ͥ���٤�Ʊ�����������㤱��С����������θ���ͥ
 *			  ���٤�������⤯�Ƥ⡤E_ILUSE���顼�ˤʤ�ʤ�����
 *
 * �ڥƥ��ȹ��ܤμ¸���ˡ��
 *
 *	(A-1)
 *		��ͥ���٥�������TASK1�ˤˡ���ͥ���پ�¥ߥ塼�ƥå�����MTX2�ˤ�
 *		��å���������ͥ���٤ˤʤ뤳�Ȥ��ǧ���롥�ޤ����¹Բ�ǽ���֤�
 *		��ͥ���٥�������TASK4�ˤ��⡤ͥ���̤��⤯�ʤ뤳�Ȥ��ǧ���롥
 *		�ǥ����ѥå��ػ߾��֤Ǽ»ܤ��롥
 *	(A-2)
 *		��ͥ���٥�������TASK1�ˤˡ���ͥ���پ�¥ߥ塼�ƥå�����MTX1�ˤ�
 *		��å�������ͥ���٤��Ѥ��ʤ����Ȥ��ǧ���롥�ޤ����¹Բ�ǽ��
 *		�֤���ͥ���٥�������2�ġ�TASK2��TASK3�ˤ��Ѱդ��Ƥ�����ͥ����
 *		���Ѥ��ʤ����Ȥ��ǧ���롥�ǥ����ѥå��ػ߾��֤Ǽ»ܤ��롥
 *	(A-3)
 *		��ͥ���٥�������TASK1�ˤ���ͥ���پ�¥ߥ塼�ƥå�����MTX2�ˤ���
 *		�����ƹ�ͥ���٤ˤʤäƤ�����֤ǡ���ͥ���پ�¥ߥ塼�ƥå���
 *		��MTX1�ˤ��å�������ͥ���٤��Ѥ��ʤ����Ȥ��ǧ���롥�ޤ���
 *		�¹Բ�ǽ���֤ι�ͥ���٥�������2�ġ�TASK4��TASK5�ˤ��Ѱդ��Ƥ�����
 *		ͥ���̤��Ѥ��ʤ����Ȥ��ǧ���롥�ǥ����ѥå��ػ߾��֤Ǽ»�
 *		���롥
 *	(B-1)
 *		��ͥ���٥�������TASK1�ˤ˹�ͥ���پ�¥ߥ塼�ƥå�����MTX2�ˤΤ�
 *		���å������Ƥ�����֤ǡ�������å������������ͥ���٤ˤʤ�
 *		���Ȥ��ǧ���롥�ޤ����¹Բ�ǽ���֤���ͥ���٥�������TASK2�ˤ��
 *		�⡤ͥ���̤��⤯�ʤ뤳�Ȥ��ǧ���롥
 *	(B-2)
 *		��ͥ���٥�������TASK1�ˤ���ͥ���پ�¥ߥ塼�ƥå�����MTX1�ˤΤ�
 *		���å������Ƥ�����֤ǡ�������å����������ͥ���٤��Ѥ��
 *		�ʤ����Ȥ��ǧ���롥�ޤ����¹Բ�ǽ���֤���ͥ���٥�������2��
 *		��TASK2��TASK3�ˤ��Ѱդ��Ƥ�����ͥ���̤��Ѥ��ʤ����Ȥ��ǧ
 *		���롥�ǥ����ѥå��ػ߾��֤Ǽ»ܤ��롥
 *	(B-3)
 *		��ͥ���٥�������TASK1�ˤ˹�ͥ���پ�¥ߥ塼�ƥå�����MTX2�ˤ���
 *		ͥ���پ�¥ߥ塼�ƥå�����MTX1�ˤ��å������Ƥ�����֤ǡ���ͥ
 *		���پ�¥ߥ塼�ƥå�����MTX1�ˤ��å����������ͥ���٤��Ѥ��
 *		�ʤ����Ȥ��ǧ���롥�ޤ����¹Բ�ǽ���֤ι�ͥ���٥�������2��
 *		��TASK4��TASK5�ˤ��Ѱդ��Ƥ�����ͥ���̤��Ѥ��ʤ����Ȥ��ǧ
 *		���롥�ǥ����ѥå��ػ߾��֤Ǽ»ܤ��롥
 *	(C-1)
 *		��ͥ���٥�������TASK1�ˤ˹�ͥ���پ�¥ߥ塼�ƥå�����2�ġ�MTX2��
 *		MTX3�˥�å��������̤���ͥ���٥�������TASK2�ˤ�MTX2���ԤäƤ���
 *		���֤ǡ�TASK1��MTX2���å����������TASK2��ͥ���٤���ͥ���٤�
 *		�ʤ뤳�Ȥ��ǧ���롥�ޤ���TASK2��ͥ���̤���TASK1�����㤯��
 *		�뤳�Ȥ��ǧ���롥
 *	(C-2)
 *		��ͥ���٥�������TASK2�ˤ���ͥ���پ�¥ߥ塼�ƥå�����MTX1�ˤ���
 *		���������̤���ͥ���٥�������TASK1�ˤ�MTX1���ԤäƤ�����֤ǡ�
 *		TASK2��MTX1���å����������TASK1��ͥ���٤���ͥ���٤Τޤ��Ѳ�
 *		���ʤ����Ȥ��ǧ���롥�ޤ����¹Բ�ǽ���֤���ͥ���٥�������⤦
 *		1�ġ�TASK3���Ѱդ��Ƥ�����TASK1��ͥ���̤�TASK3�����㤯�ʤ�
 *		���Ȥ��ǧ���롥
 *	(C-3)
 *		��ͥ���٥�������TASK1�ˤ���ͥ���پ�¥ߥ塼�ƥå�����MTX1�ˤȹ�
 *		ͥ���پ�¥ߥ塼�ƥå�����MTX3�ˤ��å��������̤���ͥ���٥���
 *		����TASK2�ˤ��̤ι�ͥ���پ�¥ߥ塼�ƥå�����MTX2�ˤ��å�����
 *		MTX1���ԤäƤ�����֤ǡ�TASK1��MTX1���å����������TASK2��ͥ
 *		���٤���ͥ���٤Τޤ��Ѳ����ʤ����Ȥ��ǧ���롥�ޤ���TASK2��ͥ��
 *		��̤���TASK1�����㤯�ʤ뤳�Ȥ��ǧ���롥
 *	(D-1)
 *		��ͥ���٥�������TASK4�ˤˡ���ͥ���پ�¥ߥ塼�ƥå�����MTX1�ˤ�
 *		��å�������E_ILUSE���顼�ˤʤ뤳�Ȥ��ǧ���롥
 *	(D-2)
 *		��ͥ���٥�������TASK1�ˤ���ͥ���پ�¥ߥ塼�ƥå�����MTX2�ˤ���
 *		�����ƹ�ͥ���٤ˤʤäƤ�����֤ǡ���ͥ���پ�¥ߥ塼�ƥå���
 *		��MTX1�ˤ��å�������E_ILUSE���顼�ˤʤ�ʤ����Ȥ��ǧ���롥
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
 *	MTX3: �ߥ塼�ƥå�����TA_CEILING°������¤Ϲ�ͥ���١�
 *
 * �ڥƥ��ȥ������󥹡�
 *
 *	== TASK1��ͥ���١����==
 *		call(set_bit_func(bit_mutex))
 *	1:	dis_dsp()
 *	2:	act_tsk(TASK2)
 *		act_tsk(TASK4)
 *	//		�⡧TASK4���桧TASK1��TASK2
 *	3:	ploc_mtx(MTX2)								... (A-1)
 *	//		�⡧TASK1��TASK4���桧TASK2��MTX2��TASK1
 *		get_pri(TSK_SELF, &tskpri)
 *		assert(tskpri == HIGH_PRIORITY)
 *	4:	ena_dsp()
 *	5:	unl_mtx(MTX2)								... (B-1)
 *	//		�⡧TASK4���桧TASK1��TASK2
 *	== TASK4��ͥ���١����==
 *	6:	loc_mtx(MTX1) -> E_ILUSE					... (D-1)
 *	7:	slp_tsk()
 *	//		�桧TASK1��TASK2
 *	== TASK1��³����==
 *	8:	get_pri(TSK_SELF, &tskpri)
 *		assert(tskpri == MID_PRIORITY)
 *
 *	9:	dis_dsp()
 *	10:	rot_rdq(MID_PRIORITY)
 *	//		�桧TASK2��TASK1
 *	11:	act_tsk(TASK3)
 *	//		�桧TASK2��TASK1��TASK3
 *	12:	ploc_mtx(MTX1)								... (A-2)
 *	//		�桧TASK2��TASK1��TASK3��MTX1��TASK1
 *		get_pri(TSK_SELF, &tskpri)
 *		assert(tskpri == MID_PRIORITY)
 *	13:	ena_dsp()
 *	== TASK2��ͥ���١����==
 *	14:	slp_tsk()
 *	//		�桧TASK1��TASK3��MTX1��TASK1
 *	== TASK1��³����==
 *	15:	slp_tsk()
 *	//		�桧TASK3��MTX1��TASK1
 *	== TASK3��ͥ���١����==
 *	16:	wup_tsk(TASK1)
 *	//		�桧TASK3��TASK1��MTX1��TASK1
 *	17:	slp_tsk()
 *	//		�桧TASK1��MTX1��TASK1
 *
 *	== TASK1��³����==
 *	18:	wup_tsk(TASK2)
 *	//		�桧TASK1��TASK2��MTX1��TASK1
 *	19:	dis_dsp()
 *	20:	rot_rdq(MID_PRIORITY)
 *	//		�桧TASK2��TASK1��MTX1��TASK1
 *	21:	wup_tsk(TASK3)
 *	//		�桧TASK2��TASK1��TASK3��MTX1��TASK1
 *	22:	unl_mtx(MTX1)								... (B-2)
 *	//		�桧TASK2��TASK1��TASK3
 *		get_pri(TSK_SELF, &tskpri)
 *		assert(tskpri == MID_PRIORITY)
 *	23:	ena_dsp()
 *	== TASK2��ͥ���١����==
 *	24:	slp_tsk()
 *	//		�桧TASK1��TASK3
 *	== TASK1��³����==
 *	25:	slp_tsk()
 *	//		�桧TASK3
 *	== TASK3��ͥ���١����==
 *	26:	wup_tsk(TASK1)
 *	//		�桧TASK3��TASK1
 *	27:	slp_tsk()
 *	//		�桧TASK1
 *
 *	== TASK1��³����==
 *	28:	dis_dsp()
 *	29:	wup_tsk(TASK4)
 *	//		�⡧TASK4���桧TASK1
 *	30:	ploc_mtx(MTX2)
 *	//		�⡧TASK1��TASK4��MTX2��TASK1
 *	31:	rot_rdq(HIGH_PRIORITY)
 *	//		�⡧TASK4��TASK1��MTX2��TASK1
 *	32:	act_tsk(TASK5)
 *	//		�⡧TASK4��TASK1��TASK5��MTX2��TASK1
 *	33:	ploc_mtx(MTX1)								... (A-3)(D-2)
 *	//		�⡧TASK4��TASK1��TASK5��MTX2��TASK1��MTX1��TASK1
 *		get_pri(TSK_SELF, &tskpri)
 *		assert(tskpri == HIGH_PRIORITY)
 *	34:	ena_dsp()
 *	== TASK4��³����==
 *	35:	slp_tsk()
 *	//		�⡧TASK1��TASK5��MTX2��TASK1��MTX1��TASK1
 *	== TASK1��³����==
 *	36:	slp_tsk()
 *	//		�⡧TASK5��MTX2��TASK1��MTX1��TASK1
 *	== TASK5��ͥ���١����==
 *	37:	wup_tsk(TASK1)
 *	//		�⡧TASK5��TASK1��MTX2��TASK1��MTX1��TASK1
 *	38:	slp_tsk()
 *	//		�⡧TASK1��MTX2��TASK1��MTX1��TASK1
 *
 *	== TASK1��³����==
 *	39:	dis_dsp()
 *	40:	wup_tsk(TASK4)
 *	//		�⡧TASK1��TASK4��MTX2��TASK1��MTX1��TASK1
 *	41:	rot_rdq(HIGH_PRIORITY)
 *	//		�⡧TASK4��TASK1��MTX2��TASK1��MTX1��TASK1
 *	42:	wup_tsk(TASK5)
 *	//		�⡧TASK4��TASK1��TASK5��MTX2��TASK1��MTX1��TASK1
 *	43:	unl_mtx(MTX1)								... (B-3)
 *	//		�⡧TASK4��TASK1��TASK5��MTX2��TASK1
 *		get_pri(TSK_SELF, &tskpri)
 *		assert(tskpri == HIGH_PRIORITY)
 *	44:	ena_dsp()
 *	== TASK4��³����==
 *	45:	slp_tsk()
 *	//		�⡧TASK1��TASK5��MTX2��TASK1
 *	== TASK1��³����==
 *	46:	slp_tsk()
 *	//		�⡧TASK5��MTX2��TASK1
 *	== TASK5��³����==
 *	47:	wup_tsk(TASK1)
 *	//		�⡧TASK5��TASK1��MTX2��TASK1
 *	48:	slp_tsk()
 *	//		�⡧TASK1��MTX2��TASK1
 *
 *	== TASK1��³����==
 *	49:	wup_tsk(TASK2)
 *		wup_tsk(TASK3)
 *		slp_tsk()
 *	//		�桧TASK2��TASK3��MTX2��TASK1
 *	== TASK2��³����==
 *	50:	loc_mtx(MTX2)
 *	//		�桧TASK3��MTX2��TASK1��TASK2
 *	== TASK3��³����==
 *	51:	wup_tsk(TASK1)
 *	//		�⡧TASK1���桧TASK3��MTX2��TASK1��TASK2
 *	== TASK1��³����==
 *	52:	loc_mtx(MTX3)
 *	//		�⡧TASK1���桧TASK3��MTX2��TASK1��TASK2��MTX3��TASK1
 *	53:	unl_mtx(MTX2)								... (C-1)
 *	//		�⡧TASK1��TASK2���桧TASK3��MTX2��TASK2��MTX3��TASK1
 *		get_pri(TASK2, &tskpri)
 *		assert(tskpri == HIGH_PRIORITY)
 *	54:	loc_mtx(MTX1)
 *	//		�⡧TASK1��TASK2���桧TASK3��MTX1��TASK1��MTX2��TASK2��MTX3��TASK1
 *	55:	slp_tsk()
 *	//		�⡧TASK2���桧TASK3��MTX1��TASK1��MTX2��TASK2��MTX3��TASK1
 *
 *	== TASK2��³����==
 *	56:	wup_tsk(TASK1)
 *	//		�⡧TASK2��TASK1���桧TASK3��MTX1��TASK1��MTX2��TASK2��MTX3��TASK1
 *	57:	loc_mtx(MTX1)
 *	//		�⡧TASK1���桧TASK3��MTX1��TASK1��TASK2��MTX2��TASK2��MTX3��TASK1
 *	== TASK1��³����==
 *	58:	unl_mtx(MTX1)								... (C-3)
 *	//		�⡧TASK1��TASK2���桧TASK3��MTX1��TASK2��MTX2��TASK2��MTX3��TASK1
 *		get_pri(TASK2, &tskpri)
 *		assert(tskpri == HIGH_PRIORITY)
 *	59:	unl_mtx(MTX3)
 *	//		�⡧TASK2���桧TASK1��TASK3��MTX1��TASK2��MTX2��TASK2
 *	== TASK2��³����==
 *	60:	unl_mtx(MTX2)
 *	//		�桧TASK2��TASK1��TASK3��MTX1��TASK2
 *
 *	61:	rot_rdq(MID_PRIORITY)
 *	//		�桧TASK1��TASK3��TASK2��MTX1��TASK2
 *	== TASK1��³����==
 *	62:	loc_mtx(MTX1)
 *	//		�桧TASK3��TASK2��MTX1��TASK2��TASK1
 *	== TASK3��³����==
 *	63:	rot_rdq(MID_PRIORITY)
 *	//		�桧TASK2��TASK3��MTX1��TASK2��TASK1
 *	== TASK2��³����==
 *	64:	unl_mtx(MTX1)								... (C-2)
 *	//		�桧TASK2��TASK3��TASK1��MTX1��TASK1
 *		get_pri(TASK1, &tskpri)
 *		assert(tskpri == MID_PRIORITY)
 *	== TASK2��³����==
 *	65:	ext_tsk() -> noreturn
 *	//		�桧TASK3��TASK1��MTX1��TASK1
 *	== TASK3��³����==
 *	66:	ext_tsk() -> noreturn
 *	//		�桧TASK1��MTX1��TASK1
 *	== TASK1��³����==
 *	67:	END
 */

#include <kernel.h>
#include <t_syslog.h>
#include "syssvc/logtask.h"
#include "kernel_cfg.h"
#include "test_lib.h"
#include "test_mutex4.h"

extern ER	bit_mutex(void);

void
task1(intptr_t exinf)
{
	ER		ercd;
	PRI		tskpri;

	set_bit_func(bit_mutex);

	check_point(1);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	check_point(2);
	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	ercd = act_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(3);
	ercd = ploc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TSK_SELF, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == HIGH_PRIORITY);

	check_point(4);
	ercd = ena_dsp();
	check_ercd(ercd, E_OK);

	check_point(5);
	ercd = unl_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(8);
	ercd = get_pri(TSK_SELF, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == MID_PRIORITY);

	check_point(9);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	check_point(10);
	ercd = rot_rdq(MID_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(11);
	ercd = act_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(12);
	ercd = ploc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TSK_SELF, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == MID_PRIORITY);

	check_point(13);
	ercd = ena_dsp();
	check_ercd(ercd, E_OK);

	check_point(15);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(18);
	ercd = wup_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(19);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	check_point(20);
	ercd = rot_rdq(MID_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(21);
	ercd = wup_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(22);
	ercd = unl_mtx(MTX1);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TSK_SELF, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == MID_PRIORITY);

	check_point(23);
	ercd = ena_dsp();
	check_ercd(ercd, E_OK);

	check_point(25);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(28);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	check_point(29);
	ercd = wup_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(30);
	ercd = ploc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(31);
	ercd = rot_rdq(HIGH_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(32);
	ercd = act_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(33);
	ercd = ploc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TSK_SELF, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == HIGH_PRIORITY);

	check_point(34);
	ercd = ena_dsp();
	check_ercd(ercd, E_OK);

	check_point(36);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(39);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	check_point(40);
	ercd = wup_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(41);
	ercd = rot_rdq(HIGH_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(42);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(43);
	ercd = unl_mtx(MTX1);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TSK_SELF, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == HIGH_PRIORITY);

	check_point(44);
	ercd = ena_dsp();
	check_ercd(ercd, E_OK);

	check_point(46);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(49);
	ercd = wup_tsk(TASK2);
	check_ercd(ercd, E_OK);

	ercd = wup_tsk(TASK3);
	check_ercd(ercd, E_OK);

	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(52);
	ercd = loc_mtx(MTX3);
	check_ercd(ercd, E_OK);

	check_point(53);
	ercd = unl_mtx(MTX2);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TASK2, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == HIGH_PRIORITY);

	check_point(54);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(55);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(58);
	ercd = unl_mtx(MTX1);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TASK2, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == HIGH_PRIORITY);

	check_point(59);
	ercd = unl_mtx(MTX3);
	check_ercd(ercd, E_OK);

	check_point(62);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_finish(67);

	check_point(0);
}

void
task2(intptr_t exinf)
{
	ER		ercd;
	PRI		tskpri;

	check_point(14);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(24);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(50);
	ercd = loc_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(56);
	ercd = wup_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(57);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_OK);

	check_point(60);
	ercd = unl_mtx(MTX2);
	check_ercd(ercd, E_OK);

	check_point(61);
	ercd = rot_rdq(MID_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(64);
	ercd = unl_mtx(MTX1);
	check_ercd(ercd, E_OK);

	ercd = get_pri(TASK1, &tskpri);
	check_ercd(ercd, E_OK);
	check_assert(tskpri == MID_PRIORITY);

	check_point(65);
	ercd = ext_tsk();

	check_point(0);
}

void
task3(intptr_t exinf)
{
	ER		ercd;

	check_point(16);
	ercd = wup_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(17);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(26);
	ercd = wup_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(27);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(51);
	ercd = wup_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(63);
	ercd = rot_rdq(MID_PRIORITY);
	check_ercd(ercd, E_OK);

	check_point(66);
	ercd = ext_tsk();

	check_point(0);
}

void
task4(intptr_t exinf)
{
	ER		ercd;

	check_point(6);
	ercd = loc_mtx(MTX1);
	check_ercd(ercd, E_ILUSE);

	check_point(7);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(35);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(45);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(0);
}

void
task5(intptr_t exinf)
{
	ER		ercd;

	check_point(37);
	ercd = wup_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(38);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(47);
	ercd = wup_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(48);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(0);
}
