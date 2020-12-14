$ ======================================================================
$ 
$   TOPPERS/ASP Kernel
$       Toyohashi Open Platform for Embedded Real-Time Systems/
$       Advanced Standard Profile Kernel
$ 
$   Copyright (C) 2010-2011 by Meika Sugimoto
$  
$   �嵭����Ԥϡ��ʲ���(1)���(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
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
$ =====================================================================

$ 
$		�������ƥ������¸�ƥ�ץ졼�ȡ�V850�ѡ�
$ 

$ 
$  �������å����¸���˴ޤޤ��ɸ����㳰������ǽ�ν�����������Ѥ��ʤ�
$ 
$OMIT_INITIALIZE_EXCEPTION = 1$

$ 
$  ATT_ISR�ǻ��ѤǤ��������ֹ�Ȥ�����б��������ߥϥ�ɥ��ֹ�
$ 
$INTNO_ATTISR_VALID = INTNO_VALID$
$INHNO_ATTISR_VALID = INHNO_VALID$

$ 
$  DEF_INT��DEF_EXC�ǻ��ѤǤ������ߥϥ�ɥ��ֹ桿CPU�㳰�ϥ�ɥ��ֹ�
$ 
$INHNO_DEFINH_VALID = INHNO_VALID$
$EXCNO_DEFEXC_VALID = EXCNO_VALID$

$ 
$  CFG_INT�ǻ��ѤǤ��������ֹ�ȳ����ͥ���١������°��
$ 
$INTNO_CFGINT_VALID = INTNO_VALID$
$INTPRI_CFGINT_VALID = { 0,-1,...,-7 }$


$ 
$  ������
$ 

$INCLUDE "../../kernel/kernel.tf"$

$ 
$ ����߽�����ǥ�¸��Τ���Υǡ�������
$ 
$ ����ߥޥ�����٥����IMR�쥸�����ͤ��������롥
$ 

$INTLVL_RANGE = {0,1, ... , 7}$
$IMR_RANGE = {0,1,2,3,4,5,6,7}$

const uint16_t imr_table[][IMR_SIZE] = $NL$
{$NL$
$JOINEACH intlvl INTLVL_RANGE " , \n"$
	$FOREACH imrno IMR_RANGE$
		$IMRn[imrno] = 0xFFFF$
	$END$
	
	$FOREACH intno { 0 , 1 , ... , 115}$
		$IF LENGTH(INT.INTPRI[intno])
		  && (-INT.INTPRI[intno] > intlvl)$
			$OFFSET = (INT.INTNO[intno]) / 16$
			$BITPOS = (INT.INTNO[intno]) % 16$
			$IMRn[OFFSET] = IMRn[OFFSET] & ~(1 << BITPOS)$
		$END$
	$END$
	$TAB${$SPC$
	$JOINEACH imrno IMR_RANGE " , "$
		$FORMAT("0x%1$x" , +IMRn[imrno])$
	$END$
	$SPC$}
$END$
$NL$};$NL$


$ 
$ CPU�㳰/����ߥϥ�ɥ������
$ 

$FILE "kernel_cfg_asm.S"$

/*$NL$
$SPC$*$TAB$CPU�㳰/����ߥϥ�ɥ�ơ��֥�����$NL$
$SPC$*$NL$
$SPC$*$TAB$�ƥϥ�ɥ��16byte����̿������ֲ�ǽ��$NL$
$SPC$*/$NL$

$NL$
$NL$

#include "v850asm.inc"$NL$
#define TOPPERS_LABEL_ASM$NL$
#define TOPPERS_MACRO_ONLY$NL$
#include "kernel_impl.h"$NL$

$NL$
$NL$

$TAB$.section .vectors , "ax"$NL$
$TAB$.align	4$NL$
$NL$
$NL$

$TAB$.globl	interrupt$NL$
$TAB$.globl	_default_exc_handler$NL$
$TAB$.globl	_default_int_handler$NL$

$NL$

_reset_handler:$NL$
$TAB$.globl _start$NL$
$TAB$jr	_start$NL$
$TAB$nop$NL$
$TAB$nop$NL$
$TAB$nop$NL$
$TAB$nop$NL$
$TAB$nop$NL$
$TAB$nop$NL$
_nmi_handler_1:$NL$
	$TAB$jr	_goto_default_int_handler$NL$
	$TAB$nop$NL$
	$TAB$nop$NL$
	$TAB$nop$NL$
	$TAB$nop$NL$
	$TAB$nop$NL$
	$TAB$nop$NL$
_nmi_handler_2:$NL$
$TAB$jr	_goto_default_int_handler$NL$
$TAB$nop$NL$
$TAB$nop$NL$
$TAB$nop$NL$
$TAB$nop$NL$
$TAB$nop$NL$
$TAB$nop$NL$

$NL$
$NL$

$FOREACH excno EXCNO_RANGE$
	_exc_handler_$excno$:$NL$
	$IF LENGTH(EXC.EXCHDR[excno]) != 0$
		$TAB$.globl	$EXC.EXCHDR[excno]$_handler$NL$
		$TAB$jr	$EXC.EXCHDR[excno]$_handler$NL$
		$TAB$nop$NL$
		$TAB$nop$NL$
		$TAB$nop$NL$
		$TAB$nop$NL$
		$TAB$nop$NL$
		$TAB$nop$NL$
	$ELSE$
		$TAB$jr	_goto_default_exc_handler$NL$
		$TAB$nop$NL$
		$TAB$nop$NL$
		$TAB$nop$NL$
		$TAB$nop$NL$
		$TAB$nop$NL$
		$TAB$nop$NL$
	$END$
$END$

$ J-Writer�Ѥ˥������ƥ�ID������
security_id:$NL$
$TAB$.long	0xFFFFFFFF$NL$
$TAB$.long	0xFFFFFFFF$NL$
$TAB$.long	0xFFFFFFFF$NL$
$TAB$.long	0xFFFFFFFF$NL$

$NL$

	$FOREACH intno { 0 , 1 , ... , 115}$
	_int_handler_$intno$:$NL$
	$IF LENGTH(INH.INTHDR[intno]) != 0$
		$IF (INH.INHATR[intno] & TA_NONKERNEL) == 0$
			$TAB$.globl	$INH.INTHDR[intno]$_handler$NL$
			$TAB$jr	__kernel_$INH.INTHDR[intno]$_$+INH.INHNO[intno]$$NL$
		$ELSE$
			$TAB$.globl	_$INH.INTHDR[intno]$$NL$
			$TAB$jr		_$INH.INTHDR[intno]$$NL$
		$END$
		$TAB$nop$NL$
		$TAB$nop$NL$
		$TAB$nop$NL$
		$TAB$nop$NL$
		$TAB$nop$NL$
		$TAB$nop$NL$
	$ELSE$
		$TAB$jr	_goto_default_int_handler$NL$
		$TAB$nop$NL$
		$TAB$nop$NL$
		$TAB$nop$NL$
		$TAB$nop$NL$
		$TAB$nop$NL$
		$TAB$nop$NL$
	$END$
$END$

$NL$
$NL$

$TAB$.section .vectors , "ax"$NL$
$TAB$.align 4$NL$

$NL$

$FOREACH excno EXCNO_RANGE$
	$IF LENGTH(EXC.EXCHDR[excno]) != 0$
		$TAB$.globl	_$EXC.EXCHDR[excno]$$NL$
		$EXC.EXCHDR[excno]$_handler:$NL$
		$TAB$addi	-80 , sp , sp$NL$
		$TAB$st.w	r10 , 52[sp]$NL$
		$TAB$st.w	r11 , 48[sp]$NL$
		$TAB$st.w	r12 , 44[sp]$NL$
		$TAB$st.w	r13 , 40[sp]$NL$
		$TAB$Lea	_$EXC.EXCHDR[excno]$ , r10$NL$
		$TAB$addi	80 , sp , r11$NL$
		$TAB$Lea	$+EXC.EXCNO[excno]$ , r12$NL$
		$TAB$Lea	exception, r13$NL$
		$TAB$jmp	r13$NL$
		$NL$
	$END$
$END$


$FOREACH intno INTNO_RANGE$
	$IF LENGTH(INH.INTHDR[intno]) != 0$
		$TAB$.globl	_$INH.INTHDR[intno]$$NL$
		$TAB$.globl	__kernel_$INH.INTHDR[intno]$_$+INH.INHNO[intno]$$NL$
		__kernel_$INH.INTHDR[intno]$_$+INH.INHNO[intno]$:$NL$
		$TAB$addi	-80 , sp , sp$NL$
		$TAB$st.w	r10 , 52[sp]$NL$
		$TAB$st.w	r11 , 48[sp]$NL$
		$TAB$st.w	r12 , 44[sp]$NL$
		$TAB$st.w	r13 , 40[sp]$NL$
$ r10�˳���ߥϥ�ɥ��ֹ桤r11�˳���ߥ�٥롤r12�˳�����ֹ���֤�
		$TAB$Lea	_$INH.INTHDR[intno]$ , r10$NL$
		$TAB$mov	$-INT.INTPRI[intno]$ , r11$NL$
		$TAB$mov	$+INH.INHNO[intno]$ , r12$NL$
		$TAB$Lea	interrupt, r13$NL$
		$TAB$jmp	r13$NL$
		$NL$
	$END$
$END$

$NL$
$NL$

_goto_default_int_handler:$NL$
$TAB$addi	-80 , sp , sp$NL$
$TAB$st.w	r10 , 0[sp]$NL$
$TAB$st.w	r13 , 40[sp]$NL$
$TAB$Lea	_default_int_handler , r10$NL$
$TAB$Lea	interrupt, r13$NL$
$TAB$jmp	r13$NL$

$NL$
$NL$

_goto_default_exc_handler:$NL$
$TAB$addi	-80 , sp , sp$NL$
$TAB$st.w	r10 , 0[sp]$NL$
$TAB$st.w	r13 , 40[sp]$NL$
$TAB$Lea	_default_exc_handler , r10$NL$
$TAB$Lea	exception, r13$NL$
$TAB$jmp	r13$NL$


$TAB$.end$NL$
$NL$

$ 
$ �����°���Υ����å�
$ 
$ ��������ߤΤ�TA_NEGEDGE��TA_POSEDGE��TA_BOTHEDGE�����ꤵ��Ƥ��뤫
$ �����å���Ԥ���
$ 

$FOREACH intno INT.ID_LIST$
	$IF LENGTH(INT.INTATR[intno])$
		$IF LENGTH(FIND(EXTINT_RANGE , +intno))$
$ ��������ߤξ�硧°������Ĥ������ꤵ��Ƥ��뤫�����å�
			$IF !(INT.INTATR[intno] == TA_NEGEDGE)
			 && !(INT.INTATR[intno] == TA_POSEDGE)
			 && !(INT.INTATR[intno] == TA_BOTHEDGE)$
				$ERROR$
					$FORMAT("Multiple external interrupt property can't set %1% `%2%\' in CFG_INT" , intno , INT.INTNO[intno])$
				$END$
			$END$
		$ELSE$
$ ��������߰ʳ��ξ�硧���������°�������ꤵ��Ƥ��ʤ��������å�
			$IF (+INT.INTATR[intno] & (+TA_NEGEDGE | +TA_POSEDGE | +TA_BOTHEDGE)) != 0$
 				$ERROR$
 					$FORMAT("TA_NEGEDGE,TA_POSEDGE,TA_BOTHEDGE can't set %1% `%2%\' in CFG_INT" , intno , INT.INTNO[intno])$
				$NL$
 				$END$
			$END$
		$END$
	$END$
$END$

