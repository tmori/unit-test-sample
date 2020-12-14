/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel  
 * 
 *  Copyright (C) 2010 by Meika Sugimoto
 * 
 *  �嵭����Ԥϡ��ʲ���(1)���(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
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
 */

#ifndef TOPPERS_PRC_INSN_H
#define TOPPERS_PRC_INSN_H

Inline uint32_t current_psw(void)
{
	volatile uint32_t psw;
	
	Asm("stsr 5 , %0" : "=r"(psw) : );
	
	return psw;
}

Inline void set_psw(uint32_t psw)
{
	Asm("ldsr %0 , 5" :  : "r"(psw));
	
	return ;
}

Inline void disable_int(void)
{
	Asm("	di");
}

Inline void enable_int(void)
{
	Asm("	ei");
}

Inline void do_trap(uint8_t vector)
{
	switch (vector) {
	case 0x0:
		Asm("trap 0x00");
		break;
	case 0x1:
		Asm("trap 0x01");
		break;
	case 0x2:
		Asm("trap 0x02");
		break;
	case 0x3:
		Asm("trap 0x03");
		break;
	case 0x4:
		Asm("trap 0x04");
		break;
	default:
		Asm("trap 0x00");
		break;
	}
}

Inline void do_halt(void)
{
	Asm("	halt");
}
Inline void do_nop(void)
{
	Asm("	nop");
}

Inline void set_bit(uint8_t bit_offset , uint32_t addr)
{
	uint32_t any;
	
	Asm("mov %1 , %0;"
		"set1 %2 , 0[%0]" : "=r"(any) : "i"(addr) , "i"(bit_offset));
}

Inline void clr_bit(uint8_t bit_offset , uint32_t addr)
{
	uint32_t any;
	
	Asm("mov %1 , %0;"
		"clr1 %2 , 0[%0]" : "=r"(any) : "i"(addr) , "i"(bit_offset));
}

#endif	/* TOPPERS_PRC_INSN_H */

