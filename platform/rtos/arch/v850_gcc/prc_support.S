/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel  
 * 
 *  Copyright (C) 2000-2002 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 * 
 *  Copyright (C) 2005 by Freelines CO.,Ltd
 *
 *  Copyright (C) 2010-2011,2013 by Meika Sugimoto
 * 
 *  �嵭����Ԥϡ��ʲ��� (1)���(4) �ξ�狼��Free Software Foundation 
 *  �ˤ�äƸ�ɽ����Ƥ��� GNU General Public License �� Version 2 �˵�
 *  �Ҥ���Ƥ���������������˸¤ꡤ�ܥ��եȥ��������ܥ��եȥ�����
 *  ����Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ������ۡʰʲ���
 *  ���ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
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
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ��������Ȥ�
 *        ��𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����TOPPERS�ץ��������Ȥ����դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ��������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����Ŭ�Ѳ�ǽ����
 *  �ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ����������Ѥˤ��ľ
 *  ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤������Ǥ�����ʤ���
 * 
 */

/*
 *	�ץ����å���¸�⥸�塼�� ������֥��������V850�ѡ�
 */

#include "v850asm.inc"

#define	TOPPERS_MACRO_ONLY
#define UINT_C(val)			(val)		/* uint_t�����������ޥ��� */
#define ULONG_C(val)		(val)		/* ulong_t�����������ޥ��� */
#define CAST(type, val)		(val)		/* �����㥹�Ȥ�Ԥ��ޥ��� */
#define TOPPERS_LABEL_ASM
#include "kernel_impl.h"
#include "offset.h"

/* ����������� */
	.globl	_set_intpri
	.globl	_call_texrtn
	.globl	_ipmflg
	
/*
 *	�ǥ����ѥå��γ���
 *
 *	����߶ػ߾��֡�lock_flag = true�Ǥ����ؤϤ�äƤ��뤬��
 *	����ߥޥ�����٥��0�Ǥ��뤿�ᡤ������CPU���å����֤�
 *	���ꤷ�ƺǽ�Υǥ����ѥå��˰ܤ롥
 *	
 */
	.globl	_start_dispatch
_start_dispatch:
	/* ����ߥޥ�����٥��CPU���å����֤��ͤ����� */
	mov		INTPRI_LOCK , r6
	jarl	_set_intpri , lp
	/* ����߶ػ߾��֤��� */
	ei
	/* �ǥ����ѥå������Τ� */
	br		dispatcher

/*
 *  �������ǥ����ѥå���
 */
 	.globl	_dispatch
 	.globl	_exit_and_dispatch
_dispatch:
	/*
	 * ����ƥ����Ȥ����� 
	 */
	addi	-60, sp, sp
	st.w	ep , 0[sp]
	mov		sp, ep
	sst.w	r2,  56[ep]
	sst.w	r10, 52[ep]
	sst.w	r11, 48[ep]
	sst.w	r20, 44[ep]
	sst.w	r21, 40[ep]
	sst.w	r22, 36[ep]
	sst.w	r23, 32[ep]
	sst.w	r24, 28[ep]
	sst.w	r25, 24[ep]
	sst.w	r26, 20[ep]
	sst.w	r27, 16[ep]
	sst.w	r28, 12[ep]
	sst.w	r29,  8[ep]
	sst.w	r31,  4[ep]
	
	/* �����å��ȼ��ε�ư���Ϥ���¸ */
	Lea		_p_runtsk, ep
	sld.w	0[ep], ep
	sst.w	sp, TCB_sp[ep]
	Lea		dispatch_r, r10
	sst.w	r10, TCB_pc[ep]
	
	/*
	 *  �������ǥ����ѥå���
	 *  
	 *  ������CPU���å����֡��ǥ����ѥå����ν���ñ�̤�
	 *  ����ƥ���������Ѥߤ�����֤����ɬ�פ�����.
	 */
_exit_and_dispatch:
dispatcher:
	Lea		_p_runtsk, r21
#ifdef LOG_DSP_ENTER
	ld.w		0[r21] , r6		/* ������p_runtsk����� */
	jarl	_log_dsp_enter , lp
#endif	/* LOG_DSP_ENTER */
	Lea		_p_schedtsk, r20
	ld.w	0[r20], r22
	st.w	r22, 0[r21]
	cmp		r22 , r0
	be		pre_idle
	/* �����å��ȼ��ε�ư���Ϥ����� */
	mov		r22, ep
	sld.w	TCB_pc[ep], r20
	sld.w	TCB_sp[ep], sp
#ifdef LOG_DSP_LEAVE
	ld.w	0[r21] , r6	/* ������p_runtsk����� */
	jarl	_log_dsp_leave , lp
#endif	/* LOG_DSP_LEAVE */
	jmp		r20


	/*
	 * �����ɥ�롼��
	 */
pre_idle:
	/* �����ߥ����å����ڤ��ؤ� */
	Lea		__kernel_istkpt, sp
	ld.w	0[sp], sp
	/* CPU���å����֤β�� */
	Lea		_lock_flag , r10
	st.w	r0 , 0[r10]
	di
	mov		INTPRI_ENAALL , r6
	jarl	_set_intpri , lp
	/* intnest��1�ˤ��� */
	mov		1, r10
	Lea		_intnest, r11
	st.b	r10, 0[r11]
	/* reqflg�Υ��ɥ쥹������� */
	Lea		_reqflg , r20
idle_loop:	
	/* �������Ԥ� */
	halt
	/*
	 * HALT̿���ˤϡ�NOP̿���5̿��ʾ���������ɬ�פ�����
	 * 4.3.3 ������Х���ǽ������������1�򻲾ȤΤ���
	 */
	nop
	nop
	nop
	nop
	nop


	/* �������Ԥ� */
	ei
	nop
	di
	
	/* reqflg�Υ����å� */
	ld.w	0[r20], r10
	cmp		r10 , r0
	be		idle_loop
	
	/* reqflg�Υ��ꥢ */
	st.w	r0 , 0[r20]
	
	/* intnest�򥯥ꥢ���� */
	Lea		_intnest, r10
	st.b	r0, 0[r10]
	/* CPU���å����֤ذܹ� */
	di
	mov		INTPRI_LOCK , r6
	jarl	_set_intpri , lp
	ei
	/* �ǥ����ѥå���� */
	br	dispatcher
	
	/* �ǥ����ѥå���������롼���� */
dispatch_r:
	Lea		_p_runtsk, r10
	ld.w	0[r10], r10
	ld.w	TCB_enatex[r10], r11
	mov		(1 << TCB_enatex_bit) , r12
	tst		r11 , r12
	bz		ret_to_task
	ld.w	TCB_texptn[r10], r11
	cmp		r0, r11
	be		ret_to_task
	Lea		_ipmflg , r10
	ld.w	0[r10] , r10
	cmp		r0 , r10
	be		ret_to_task

	/* �������㳰�θƤӽФ� */
	jarl	_call_texrtn, lp
ret_to_task:
	mov		sp, ep
	sld.w	56[ep], r2
	sld.w	52[ep], r10
	sld.w	48[ep], r11
	sld.w	44[ep], r20
	sld.w	40[ep], r21
	sld.w	36[ep], r22
	sld.w	32[ep], r23
	sld.w	28[ep], r24
	sld.w	24[ep], r25
	sld.w	20[ep], r26
	sld.w	16[ep], r27
	sld.w	12[ep], r28
	sld.w	 8[ep], r29
	sld.w	 4[ep], r31
	addi	60, ep, sp
	ld.w	0[sp], ep
	jmp		lp

/*
 *  ��������ư������
 */
 	.globl _start_r
_start_r:
	/* ����ߥޥ�����٥��CPU������å����֤��ͤ����� */
	di
	mov		INTPRI_ENAALL , r6
	jarl	_set_intpri , lp
	Lea		_lock_flag , r6
	st.w	r0 , 0[r6]
	
	Lea		_p_runtsk, ep
	ld.w	0[ep], ep
	ld.w	TCB_p_tinib[ep], ep
	ld.w	TINIB_exinf[ep], r6
	ld.w	TINIB_task[ep], r10
	Lea		_ext_tsk, lp
	
	/* ���������Τ� */
	ei		/* ����߶ػ߾��֤��� */
	jmp		r10

/*
 *  ����ߥϥ�ɥ�
 *
 *  ���λ����ǥ����å���80byteʬ���ݤ��Ƥ��ꡤ�쥸�����˳���ߥϥ�ɥ����
 *  ��Ǽ����Ƥ��롥
 *
 *  - r10������ߥϥ�ɥ饢�ɥ쥹
 *  - r11��������ͥ����(����ɽ��)
 *  - r12������ߥϥ�ɥ��ֹ�
 *
 *  �����å��ι����ϰʲ��ΤȤ��ꡥ
 *
 *    |----------------|<- �����ȯ������SP
 * 76 | current_intpri |
 *    |----------------|
 * 72 |       r1       |
 *    |----------------|
 * 68 |       r6       |
 *    |----------------|
 * 64 |       r7       |
 *    |----------------|
 * 60 |       r8       |
 *    |----------------|
 * 56 |       r9       |
 *    |----------------|
 * 52 |      r10       |
 *    |----------------|
 * 48 |      r11       |
 *    |----------------|
 * 44 |      r12       |
 *    |----------------|
 * 40 |      r13       |
 *    |----------------|
 * 36 |      r14       |
 *    |----------------|
 * 32 |      r15       |
 *    |----------------|
 * 28 |      r16       |
 *    |----------------|
 * 24 |      r17       |
 *    |----------------|
 * 20 |      r18       |
 *    |----------------|
 * 16 |      r19       |
 *    |----------------|
 * 12 |      r30       |
 *    |----------------|
 *  8 |      r31       |
 *    |----------------|
 *  4 |      EIPC      |
 *    |----------------|
 *  0 |     EIPSW      |
 *    |----------------|<- �����ȯ������SP - 80
 */
	.globl interrupt
interrupt:
	/*
	 *  �Ĥ�Υ쥸�������� EP�ǤΥ����������ڤ��ؤ��ƹԤ�
	 *  (r10-r12������Ѥ�)
	 */
	st.w	ep,   12[sp]
	mov		sp ,  ep 
	sst.w	r1 ,  72[ep]
	sst.w	r6 ,  68[ep]
	sst.w	r7 ,  64[ep]
	sst.w	r8 ,  60[ep]
	sst.w	r9 ,  56[ep]
	sst.w	r14 , 36[ep]
	sst.w	r15 , 32[ep]
	sst.w	r16 , 28[ep]
	sst.w	r17 , 24[ep]
	sst.w	r18 , 20[ep]
	sst.w	r19 , 16[ep]
	sst.w	r31 ,  8[ep]
	/* ¿�ų���ߤΤ��ᡤ���ߤ�EIPC��EIPSW����¸ */
	stsr	eipc,   r6
	sst.w	r6 ,   4[ep]
	stsr	eipsw,  r6
	sst.w	r6 ,   0[ep]
	
	/* ���å��ե饰�������� */
	Lea		_lock_flag , r7
	st.w	r0 , 0[r7]
	
	/* �����ȯ�����γ���ߥ�٥����¸��ȯ����γ���ߥ�٥�(r11)�˽񤭴��� */
	Lea		_current_intpri , r13
	ld.bu	0[r13] , r14
	sst.w	r14 , 76[ep]
	st.b	r11 , 0[r13]
	
	/* ¿�ų����ߥ����å��ȥͥ��ȥ����󥿤򥤥󥯥���� */
	Lea		_intnest, r13
	ld.bu	0[r13], r6
	add		1, r6
	st.b	r6, 0[r13]
	cmp		1 , r6
	bne		call_int_handler
save_tsksp:
	/* ������ߤǤ���Х����å��򥫡��ͥ륹���å����ڤ��ؤ� */
	mov		sp , r13
	Lea		__kernel_istkpt, sp
	ld.w	0[sp], sp
	add		-4 , sp
	st.w	r13 , 0[sp]
call_int_handler:
#ifdef LOG_INH_ENTER
	/* ����ߥϥ�ɥ饢�ɥ쥹�������ͥ���١�������ֹ������ */
	add		-8 , sp
	st.w	r10 , 0[sp]
	st.w	r12 , 4[sp]
	mov		r12 , r6
	jarl	_log_inh_enter , lp
	ld.w	0[sp] , r10
	ld.w	4[sp] , r12
	add		8 , sp
#endif	/* LOG_INH_ENTER */
#ifdef LOG_INH_LEAVE
	add		-4 , sp
	st.w	r12 , 0[sp]
#endif	/* LOG_INH_LEAVE */
	Lea		end_int_handler, lp
	/* �����ߵ��� */
	ei
	/* �ϥ�ɥ鵯ư */
	jmp		r10
end_int_handler:
	/* �����߶ػ� */
	di
#ifdef LOG_INH_LEAVE
	ld.w	0[sp] , r6
	add		4 , sp
	jarl	_log_inh_leave , lp
#endif	/* LOG_INH_LEAVE */
	/* CPU���å����֤򥢥���å����֤��᤹ */
	Lea		_lock_flag , r10
	st.w	r0 , 0[r10]
	/* intnest��ǥ������ */
	Lea		_intnest, r11
	ld.bu	0[r11], r10
	add		-1 , r10
	st.b	r10, 0[r11]
	cmp		r0 , r10
	be		return_to_task
return_from_int:
	/*
	 * �쥸�������� 
	 */
	mov		sp , ep	/* EP���ڤ��ؤ� */
	Lea		_current_intpri , r10
	sld.w	76[ep] , r6
	st.b	r6 , 0[r10]
	di
	jarl	_set_intpri , lp
	/* CPU���å��ե饰�β�� */
	Lea		_lock_flag , r6
	st.w	r0 , 0[r6]
	sld.w	 4[ep] , r10
	ldsr	r10 , eipc
	sld.w    0[ep] , r10
	ldsr    r10 , eipsw
	sld.w	72[ep] , r1
	sld.w	68[ep] , r6
	sld.w	64[ep] , r7
	sld.w	60[ep] , r8
	sld.w	56[ep] , r9
	sld.w	52[ep] , r10
	sld.w	48[ep] , r11
	sld.w	44[ep] , r12
	sld.w	40[ep] , r13
	sld.w	36[ep] , r14
	sld.w	32[ep] , r15
	sld.w	28[ep] , r16
	sld.w	24[ep] , r17
	sld.w	20[ep] , r18
	sld.w	16[ep] , r19
	sld.w	 8[ep] , r31
	addi	80 , ep, sp
	sld.w	12[ep] , r30

	reti	/* ����߸��� */

return_to_task:
	/* �����å������� */
	ld.w	0[sp], sp
	
	/* �ٱ�ǥ����ѥå��ڤӥ������㳰�����ν����׵᤬���뤫�����å� */
	Lea		_reqflg, r10
	ld.w	0[r10], r11
	cmp		r0, r11
	be		return_from_int
	st.w	r0, 0[r10]			/* reqflg�Υ��ꥢ */
	
	/* �ǥ����ѥå���ǽ���֤������å� */
	Lea		_dspflg , r10
	ld.w	0[r10], r10
	cmp		r0, r10
	bz		check_texrtn_cond
	
	/* �������������֥ե饰�Υ����å� */
	Lea		_ipmflg , r10
	ld.w	0[r10], r10
	cmp		r0, r10
	bz		check_texrtn_cond
	
	/* �������ڤ��ؤ���ɬ�פ����뤫�����å� */
	Lea		_p_schedtsk, r10
	ld.w	0[r10], r10
	Lea		_p_runtsk, r11
	ld.w	0[r11], r11
	cmp		r10,r11
	bne		ret_int
	br		check_texrtn_cond_1
	
check_texrtn_cond:
	/* �¹��楿����������� */
	Lea		_p_runtsk, r11
	ld.w	0[r11], r11

check_texrtn_cond_1:
	/* �������㳰��ȯ�����Ƥ��뤫�Υ����å��ȥ������㳰�����롼����μ¹� */
	ld.w	TCB_enatex[r11] , r13
	mov		(1 << TCB_enatex_bit) , r12
	tst		r12 , r13
	bz		return_from_int
	ld.w	TCB_texptn[r11] , r11
	cmp		r0, r11
	bz		return_from_int
	jarl	_call_texrtn , lp
	br		return_from_int

/*
 *  ������󥹥���å��쥸���������򤹤�
 *
 *    |------------------|<- �����ȯ������SP - 80
 * 40 |        r2        |
 *    |------------------|
 * 36 |       r20        |
 *    |------------------|
 * 32 |       r21        |
 *    |------------------|
 * 28 |       r22        |
 *    |------------------|
 * 24 |       r23        |
 *    |------------------|
 * 20 |       r24        |
 *    |------------------|
 * 16 |       r25        |
 *    |------------------|
 * 12 |       r26        |
 *    |------------------|
 *  8 |       r27        |
 *    |------------------|
 *  4 |       r28        |
 *    |------------------|
 *  0 |       r29        |
 *    |------------------|<- �����ȯ������SP - 80 - 44
 */      
	.globl	ret_int
ret_int:
	addi	-44, sp, sp
	mov		sp , ep
	sst.w	r2 ,  40[ep]
	sst.w	r20 , 36[ep]
	sst.w	r21 , 32[ep]
	sst.w	r22 , 28[ep]
	sst.w	r23 , 24[ep]
	sst.w	r24 , 20[ep]
	sst.w	r25 , 16[ep]
	sst.w	r26 , 12[ep]
	sst.w	r27 ,  8[ep]
	sst.w	r28 ,  4[ep]
	sst.w	r29 , 0[ep]
	
	/* TCB��������ξ�������� */
	Lea		_p_runtsk, r10
	ld.w	0[r10], r10
	st.w	sp , TCB_sp[r10]
	Lea		ret_int_r, r11
	st.w	r11 , TCB_pc[r10]
	
	/* CPU���å����֤����� */
	mov		INTPRI_LOCK , r6
	jarl	_set_intpri , lp
	Lea		_current_intpri , r6	/* ���ߤβ��۾�γ����ͥ���٤�0�� */
	st.b	r0 , 0[r6]
	mov		1 , r7
	Lea		_lock_flag , r6			/* ���å��ե饰��true�� */
	st.w	r7 , 0[r6]
	
	/* �ǥ����ѥå���� */
	ldsr	r0, eipsw	/* ����ߤϵ��ľ��֤Ǥ褤 */
	Lea		dispatcher, r10
	ldsr	r10, eipc
	reti

	.globl ret_int_r
ret_int_r:
	/* �󥹥���å��쥸���������� */
	mov		sp, ep
	sld.w	40[ep], r2
	sld.w	36[ep], r20
	sld.w	32[ep], r21
	sld.w	28[ep], r22
	sld.w	24[ep], r23
	sld.w	20[ep], r24
	sld.w	16[ep], r25
	sld.w	12[ep], r26
	sld.w	 8[ep], r27
	sld.w	 4[ep], r28
	sld.w	 0[ep], r29
	addi	44 , ep, sp
	
	/* ������Ȥ��������������Ф� */
	br		check_texrtn_cond

/*
 *  CPU�㳰����
 *
 *  CPU�㳰����ȯ������p_excinf�˳�Ǽ�������ϰʲ����̤ꡥ
 *  ��offset:0 CPU�㳰ȯ������ȯ������PC
 *  ��offset:4 CPU�㳰ȯ������SP
 *  ��offset:8 CPU�㳰ȯ������PSW
 *  ��offset:12 �㳰������
 */

	.globl	exception
exception:
	/*
	 *  �Ĥ�Υ쥸�������� EP�ǤΥ����������ڤ��ؤ��ƹԤ�
	 *  (r10-r12������Ѥ�)
	 */
	st.w	ep,   16[sp]
	mov		sp ,  ep 
	sst.w	r1 ,  72[ep]
	sst.w	r6 ,  68[ep]
	sst.w	r7 ,  64[ep]
	sst.w	r8 ,  60[ep]
	sst.w	r9 ,  56[ep]
	sst.w	r14 , 36[ep]
	sst.w	r15 , 32[ep]
	sst.w	r16 , 28[ep]
	sst.w	r17 , 24[ep]
	sst.w	r18 , 20[ep]
	sst.w	r19 , 12[ep]
	sst.w	r31 ,  8[ep]
	/* ¿���㳰�Τ��ᡤ���ߤ�EIPC��EIPSW����¸ */
	stsr	eipc,   r6
	sst.w	r6 ,   4[ep]
	stsr	eipsw,  r6
	sst.w	r6 ,   0[ep]
	/* �����ȯ�����γ���ߥ�٥����¸ */
	Lea		_current_intpri , r13
	ld.bu	0[r13] , r14
	sst.w	r14 , 76[ep]
	
	/* ¿�ų����/�㳰�����å��ȥͥ��ȥ����󥿤򥤥󥯥���� */
	Lea		_intnest, r13
	ld.bu	0[r13], r6
	add		1, r6
	st.b	r6, 0[r13]
	cmp		1 , r6
	bne		set_excinf
	
exc_save_tsksp:
	/* ������ߤǤ���Х����å��򥫡��ͥ륹���å����ڤ��ؤ� */
	mov		sp , r13
	Lea		__kernel_istkpt, sp
	ld.w	0[sp], sp
	add		-4 , sp
	st.w	r13 , 0[sp]
	
set_excinf:
	/* CPU�㳰����򥹥��å��˳�Ǽ */
	addi	-20 , sp , sp
	mov		sp , r6
	stsr	0 , r13				/* CPU�㳰ȯ������EIPC */
	st.w	r13 , 0[r6]
	stsr	1 , r13				/* CPU�㳰ȯ������EIPSW */
	st.w	r13 , 8[r6]
	stsr	4 , r13
	mov		0x0000ffff , r14	/* CPU�㳰ȯ������EICC(ECR�β���16bit) */
	and		r14 , r13
	st.w	r13 , 12[r6]
	st.w	r11 , 4[r6]			/* CPU�㳰ȯ������sp */
	Lea		_lock_flag , r14
	ld.w	0[r14] , r13
	st.w	r13 , 16[r6]		/* CPU�㳰ȯ�����Υ��å��ե饰 */
	
	/* CPU�㳰ȯ������CPU���å����֤ʤ饢����å����� */
	cmp 	r0 , r13
	be		call_exc_handler
	/*
	 *  TIPM_ENAALL�����ꤹ��ȳ���ߥϥ�ɥ��ȯ������CPU�㳰��
	 *  ͥ���٤���ž���뤿�ᡤ�����ϸ��ߤγ����ͥ���٥ޥ������Ѥ���
	 */
	/* st.w	r0 , 0[r14] */
	add		-8 , sp
	st.w	r10 , 4[sp]
	st.w	r6 , 0[sp]
	Lea		_current_intpri , r6
	ld.bu	0[r6] , r6
	jarl	_set_intpri , lp
	ld.w	4[sp] , r10
	ld.w	0[sp] , r6
	add		8 , sp
call_exc_handler:
#ifdef LOG_EXC_ENTER
	/* CPU�㳰�ϥ�ɥ饢�ɥ쥹���㳰ȯ������SP��CPU�㳰�ֹ������ */
	add		-12 , sp
	st.w	r10 , 0[sp]
	st.w	r6 , 4[sp]
	st.w	r12 , 8[sp]
	mov		r12 , r6
	jarl	_log_exc_enter , lp
	ld.w	0[sp] , r10
	ld.w	4[sp] , r6
	ld.w	8[sp] , r12
	add		12 , sp
#endif	/* LOG_EXC_ENTER */
#ifdef LOG_EXC_LEAVE
	add		-4 , sp
	st.w	r12 , 0[sp]
#endif	/* LOG_EXC_LEAVE */
	Lea		end_exc_handler , lp
	/* �ϥ�ɥ鵯ư */
	ei
	jmp		r10
end_exc_handler:
	di
#ifdef LOG_EXC_LEAVE
	ld.w	0[sp] , r6
	add		4 , sp
	jarl	_log_exc_leave , lp
#endif	/* LOG_EXC_LEAVE */
	
	/*
	 *  CPU���å����֤�CPU�㳰ȯ�����ξ��֤��᤹
	 */
	ld.w	16[sp] , r10
	Lea		_lock_flag , r11
	st.w	r10 , 0[r11]
	cmp		r0 , r10
	bz		end_exc_handler_1
	mov		INTPRI_LOCK , r6
	jarl	_set_intpri , lp
	
end_exc_handler_1:
	/* CPU�㳰ȯ�����ξ��֤��Ǽ�����ΰ���˴� */
	addi	20 , sp , sp
	/* intnest��ǥ������ */
	Lea		_intnest, r11
	ld.bu	0[r11], r10
	add		-1 , r10
	st.b	r10, 0[r11]
	cmp		r0 , r10	
	/* �ʹߤ϶��̽��� */
	be		return_to_task_from_exc
	br		return_from_exc


return_to_task_from_exc:
	/* �����å������� */
	ld.w	0[sp], sp
	
	/* �ٱ�ǥ����ѥå��ڤӥ������㳰�����ν����׵᤬���뤫�����å� */
	Lea		_reqflg, r10
	ld.w	0[r10], r11
	cmp		r0, r11
	be		return_from_exc
	st.w	r0, 0[r10]			/* reqflg�Υ��ꥢ */
	
	/* �ǥ����ѥå���ǽ���֤������å� */
	Lea		_dspflg , r10
	ld.w	0[r10], r10
	cmp		r0, r10
	bz		check_texrtn_cond
	
	/* �������������֥ե饰�Υ����å� */
	Lea		_ipmflg , r10
	ld.w	0[r10], r10
	cmp		r0, r10
	bz		check_texrtn_cond
	
	/* �������ڤ��ؤ���ɬ�פ����뤫�����å� */
	Lea		_p_schedtsk, r10
	ld.w	0[r10], r10
	Lea		_p_runtsk, r11
	ld.w	0[r11], r11
	cmp		r10,r11
	bne		ret_int
	br		check_texrtn_cond_1

return_from_exc:
	/*
	 * �쥸�������� 
	 */
	mov		sp , ep	/* EP���ڤ��ؤ� */
	Lea		_current_intpri , r10
	sld.w	76[ep] , r6
	st.b	r6 , 0[r10]
	di
	jarl	_set_intpri , lp
	/* CPU���å��ե饰�β�� */
	sld.w	 4[ep] , r10
	ldsr	r10 , eipc
	sld.w    0[ep] , r10
	ldsr    r10 , eipsw
	sld.w	72[ep] , r1
	sld.w	68[ep] , r6
	sld.w	64[ep] , r7
	sld.w	60[ep] , r8
	sld.w	56[ep] , r9
	sld.w	52[ep] , r10
	sld.w	48[ep] , r11
	sld.w	44[ep] , r12
	sld.w	40[ep] , r13
	sld.w	36[ep] , r14
	sld.w	32[ep] , r15
	sld.w	28[ep] , r16
	sld.w	24[ep] , r17
	sld.w	20[ep] , r18
	sld.w	16[ep] , r19
	sld.w	 8[ep] , r31
	addi	80 , ep, sp
	sld.w	12[ep] , r30

	reti	/* ����߸��� */

/*
 *  �����ͥ�ν�λ�����θƽФ�
 */
	.globl _call_exit_kernel
_call_exit_kernel:
	/* �󥿥�������ƥ����Ȥ��ڤ��ؤ� */
	Lea		__kernel_istkpt, sp
	ld.w	0[sp], sp
	jarl	_exit_kernel , lp
	/* ��äƤ��뤳�ȤϤʤ�������������äƤ������Τ���̵�¥롼�� */
	di
_call_exit_kernel_loop:
	br		_call_exit_kernel_loop

