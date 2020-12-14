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
 *  Copyright (C) 2010-2011 by Meika Sugimoto
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
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
 *        ��𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����Ŭ�Ѳ�ǽ����
 *  �ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ����������Ѥˤ��ľ
 *  ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤������Ǥ�����ʤ���
 * 
 */

/*
 *	�ץ��å���¸�⥸�塼���V850�ѡ�
 *
 *  ���Υ��󥯥롼�ɥե�����ϡ�target_config.h�ʤޤ��ϡ��������饤��
 *  �롼�ɤ����ե�����ˤΤߤ��饤�󥯥롼�ɤ���롥¾�Υե����뤫��
 *  ľ�ܥ��󥯥롼�ɤ��ƤϤʤ�ʤ���
 */

#ifndef TOPPERS_PRC_CONFIG_H
#define TOPPERS_PRC_CONFIG_H

#ifndef TOPPERS_MACRO_ONLY

/*
 *  �ץ��å����ü�̿��Υ���饤��ؿ����
 */
#include "prc_insn.h"
#include <sil.h>

/*
 *  �󥿥�������ƥ������ѤΥ����å������
 */
#define TOPPERS_ISTKPT(istk, istksz) ((STK_T *)((char *)(istk) + (istksz)))

/*
 *  ����������ƥ����ȥ֥�å������
 */
typedef struct task_context_block {
	void	*sp;		/* �����å��ݥ��� */
	FP		pc;			/* �ץ���५���� */
} TSKCTXB;

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  �����ͥ���٥ޥ������饤�֥��
 *
 *	V850��ɽ�̾�ϳ����ͥ���٥ޥ���������ʤ����ᡤ���եȥ�������
 *	���ߥ�졼����󤹤롥����Ū�ˤϡ�CFG_INT��������줿������׵�饤������
 *	����Ƴ����ͥ���٥ޥ������ͤˤ��б�����ISPR�쥸�����ͤ���������
 *	���ꤹ�뤳�ȤǹԤ���
 */


/*
 *  �����ͥ���٥ޥ����γ���ɽ��������ɽ�����Ѵ�
 *
 *  ������֥����Υ������ե����뤫�饤�󥯥롼�ɤ�����Τ���ˡ�CAST�����
 */
#define EXT_IPM(iipm)	 (-CAST(PRI,(iipm)))	   /* ����ɽ������ɽ���� */
#define INT_IPM(ipm)	 (CAST(uint32_t, -(ipm)))  /* ����ɽ��������ɽ���� */

#ifndef TOPPERS_MACRO_ONLY

/* (��ǥ���)���ߤγ����ͥ���� */
extern uint8_t current_intpri;
/* CPU��å��ե饰 */
extern bool_t lock_flag;
/* CPU��å����CPU��å�����IMR�쥸�����ͤ��Ǽ�����ΰ� */
extern uint16_t saved_imr[];
/* �ػߤ���Ƥ��������װ����Ǽ�����ΰ� */
extern uint16_t disint_table[];
/* ����ߥͥ��Ȳ�� */
extern uint8_t intnest;

/*
 *  ����ƥ����Ȥλ���
 */
Inline bool_t
sense_context(void)
{
    return (intnest > 0)? true : false;
}

/*
 *	���ߤγ����ͥ���٥ޥ���(����ɽ��)�μ���
 */
Inline uint8_t
get_intpri(void)
{
	return current_intpri;
}

/*
 *	���ߤγ����ͥ���٥ޥ���(����ɽ��)������
 */

extern void set_intpri(uint8_t intpri);

/*
 *	IMR�쥸�����ͤ�����
 *
 *  restore_imr���Ф˸ƤФʤ���Фʤ�ʤ���
 */
Inline void save_imr(void)
{
	uint_least8_t i;
	
	/* ISPR�����ɤ߽Ф� */
	for(i = 0 ; i < IMR_SIZE ; i++)
	{
		saved_imr[i] = sil_reh_mem((void *)(IMR0 + (2 * i)));
	}
}

/*
 *  IMR�쥸�����ͤ�����
 *
 *  save_imr���Ф˸ƤФʤ���Фʤ�ʤ���
 */
Inline void restore_imr(void)
{
	uint_least8_t i;
	
	/* ISPR�˽񤭹��� */
	for(i = 0 ; i < IMR_SIZE ; i++)
	{
		sil_wrh_mem((void *)(IMR0 + (2 * i)) , saved_imr[i]);
	}
}

/*
 *  TOPPERSɸ�����߽�����ǥ�μ¸�
 */


#endif /* TOPPERS_MACRO_ONLY */

/*
 *  CPU��å����֤Ǥγ����ͥ���٥ޥ���
 *
 *  TIPM_LOCK�ϡ�CPU��å����֤Ǥγ����ͥ���٥ޥ��������ʤ����������
 *  ��������Τ�Τ�������٤Ƥγ���ߤ�ޥ��������ͤ�������롥
 */
#define TIPM_LOCK		TMIN_INTPRI

/*
 *  CPU��å����֤Ǥγ����ͥ���٥ޥ���������ɽ��
 */
#define INTPRI_LOCK		INT_IPM(TIPM_LOCK)

/*
 *  TIPM_ENAALL�ʳ����ͥ���٥ޥ���������ˤ�����ɽ��
 */
#define INTPRI_ENAALL	INT_IPM(TIPM_ENAALL)

#ifndef TOPPERS_MACRO_ONLY


/*
 *  CPU��å����֤ؤΰܹ�
 */
Inline void
x_lock_cpu(void)
{
	/* ����ǳ���ߤ����äƤϤʤ�ʤ����ᡤ����ߤ�ػߤ��롥 */
	disable_int();
	
	save_imr();	/* ���ߤ�IMR������ */
	set_intpri(INTPRI_LOCK);
	lock_flag = true;
	
	/* ����߲�� */
	enable_int();
}

#define t_lock_cpu()    x_lock_cpu()
#define i_lock_cpu()    x_lock_cpu()

/*
 *  CPU��å����֤β��
 */
Inline void
x_unlock_cpu(void)
{
	/* ����ǳ���ߤ����äƤϤʤ�ʤ����ᡤ����ߤ�ػߤ��롥 */
	disable_int();
	
	restore_imr();	/* IMR������ */
	set_intpri(current_intpri);
	lock_flag = false;
	
	/* ����߲�� */
	enable_int();
}

#define t_unlock_cpu()    x_unlock_cpu()
#define i_unlock_cpu()    x_unlock_cpu()

/*
 *  CPU��å����֤λ���
 */
Inline bool_t
x_sense_lock(void)
{
    return lock_flag;
}

#define t_sense_lock()    x_sense_lock()
#define i_sense_lock()    x_sense_lock()

/* ena_int/disint��ͭ���ʳ�����ֹ���ϰϤ�Ƚ�� */
#define VALID_INTNO_CFGINT(intno)	(((7u <= (intno)) && ((intno) <= 116u))	\
										|| (intno == 1u))
#define VALID_INTNO_DISINT(intno)	VALID_INTNO_CFGINT((intno))

/* cre_int��ͭ���ʳ�����ֹ�λ���  */
#define VALID_INTNO_CREINT          VALID_INTNO_CFGINT((intno))

/*
 * �ʥ�ǥ��Ρ˳����ͥ���٥ޥ���������
 */

Inline void
x_set_ipm(PRI intpri)
{
	current_intpri = INT_IPM(intpri);
	set_intpri(current_intpri);
}

#define t_set_ipm(intpri)    x_set_ipm(intpri)
#define i_set_ipm(intpri)    x_set_ipm(intpri)

/*
 * �ʥ�ǥ��Ρ˳����ͥ���٥ޥ����λ���
 */
Inline PRI
x_get_ipm(void)
{
	return EXT_IPM(current_intpri);
}

#define t_get_ipm()    x_get_ipm()
#define i_get_ipm()    x_get_ipm()

/*
 *  �ǹ�ͥ���̥������ؤΥǥ����ѥå���prc_support.S��
 *
 *  dispatch�ϡ�����������ƥ����Ȥ���ƤӽФ��줿�����ӥ������������
 *  ��ƤӽФ��٤���Τǡ�����������ƥ����ȡ�CPU��å����֡��ǥ����ѥ�
 *  �����ľ��֡��ʥ�ǥ��Ρ˳����ͥ���٥ޥ�����������֤ǸƤӽФ���
 *  ����Фʤ�ʤ���
 */
extern void dispatch(void);

/*
 *  �ǥ����ѥå����ư��ϡ�prc_support.S��
 *
 *  start_dispatch�ϡ������ͥ뵯ư���˸ƤӽФ��٤���Τǡ����٤Ƥγ��
 *  �ߤ�ػߤ������֡�������ߥ�å����֤�Ʊ���ξ��֡ˤǸƤӽФ��ʤ����
 *  �ʤ�ʤ���
 */
extern void start_dispatch(void);

/*
 *  ���ߤΥ���ƥ����Ȥ�ΤƤƥǥ����ѥå���prc_support.S��
 *
 *  exit_and_dispatch�ϡ�ext_tsk����ƤӽФ��٤���Τǡ�����������ƥ�
 *  ���ȡ�CPU��å����֡��ǥ����ѥå����ľ��֡��ʥ�ǥ��Ρ˳����ͥ��
 *  �٥ޥ�����������֤ǸƤӽФ��ʤ���Фʤ�ʤ���
 */
extern void exit_and_dispatch(void);

/*
 *  �����ͥ�ν�λ�����θƽФ���prc_support.S��
 *
 *  call_exit_kernel�ϡ������ͥ�ν�λ���˸ƤӽФ��٤���Τǡ��󥿥���
 *  ����ƥ����Ȥ��ڤ괹���ơ������ͥ�ν�λ������exit_kernel�ˤ�Ƥӽ�
 *  ����
 */
extern void call_exit_kernel(void) NoReturn;

/*
 *  ����������ƥ����Ȥν����
 *
 *  ���������ٻ߾��֤���¹ԤǤ�����֤˰ܹԤ�����˸ƤФ�롥���λ���
 *  �ǥ����å��ΰ��ȤäƤϤʤ�ʤ���
 *
 *  activate_context�򡤥���饤��ؿ��ǤϤʤ��ޥ�������Ȥ��Ƥ���Τϡ�
 *  ���λ����Ǥ�TCB���������Ƥ��ʤ�����Ǥ��롥
 */
extern void    start_r(void);

#define activate_context(p_tcb)												\
{																			\
	(p_tcb)->tskctxb.sp = (uint32_t *)(((uint32_t)(p_tcb)->p_tinib->stk) + 	\
								(p_tcb)->p_tinib->stksz);					\
	(p_tcb)->tskctxb.pc = (void *) start_r;									\
}

/*
 * �������å����¸���˴ޤޤ��ɸ����㳰������ǽ�ν�����������Ѥ��ʤ�
 */
#define OMIT_INITIALIZE_EXCEPTION

/*
 * CPU�㳰�ϥ�ɥ�ν����
 * �����ޥ���ˤ���������asp/kernel/exception.h�ǥץ�ȥ��������
 * ������Ƥ��뤿�ᡢ�ؿ��Ȥ���������ʤ���Фʤ�ʤ���
 */
extern void initialize_exception(void);

/*
 *  ������ֹ桦����ߥϥ�ɥ��ֹ�
 *
 *  ����ߥϥ�ɥ��ֹ�(inhno)�ȳ�����ֹ�(intno)�ϡ��٥����ֹ���Ѥ��롥
 *
 *  �٥����ֹ��64����Ϥޤ뤿�ᡤ���Τޤޤ��ͤ�ͥ���ٴ������Υơ��֥��
 *  ����ǥå������Ѥ���ȡ�̵�̤��ΰ褬ȯ�����롥���Τ��ᡤ�����ͥ�����
 *  �Ǥϡ�-64�����ͤ��Ѥ��롥
 *
 *  ����ɽ����̾���ϡ�iintno,iinhno�Ȥ��롥
 */

/*
 * ����ߥϥ�ɥ��ֹ������������ɽ������Ѵ�
 */
/* ����ɽ������ɽ���� */
#define EXT_INHNO(iintno) (iintno)
/* ����ɽ��������ɽ���� */
#define INT_INHNO(intno)  (intno)

/*
 * ������ֹ������������ɽ������Ѵ�
 */
/* ����ɽ������ɽ���� */
#define EXT_INTNO(iintno)   (iintno)
/* ����ɽ��������ɽ���� */
#define INT_INTNO(intno)    (intno)

/*
 *  CPU�㳰�ϥ�ɥ��ֹ�
 *
 */
#define VALID_EXCNO_DEFEXC(excno) (1)

/*
 *  ����ߥϥ�ɥ������
 *
 *	TF�ե�������������뤿�ᡤ���ˤ��Ƥ���
 */

#define x_define_inh(inhno, int_entry)

/*
 *  ����ߥϥ�ɥ�ν����������������ޥ���
 *
 */
#define _INT_ENTRY(inhno, inthdr)    _kernel_##inthdr##_##inhno
#define INT_ENTRY(inhno, inthdr)     _INT_ENTRY(inhno, inthdr)

#define _INTHDR_ENTRY(inhno, inthdr) extern void _kernel_##inthdr##_##inhno(void);
#define INTHDR_ENTRY(inhno, inhno_num, inthdr)  _INTHDR_ENTRY(inhno, inthdr) 

extern bool_t dev_disable_int(INTNO intno);

/*
 *  ������׵�ػߥե饰�Υ��å�
 *
 *  �����°�������ꤵ��Ƥ��ʤ�������׵�饤����Ф��Ƴ�����׵�ػ�
 *  �ե饰�򥯥ꥢ���褦�Ȥ������ˤϡ�false���֤���
 */
Inline bool_t
private_disable_int(INTNO intno)
{
	
	if(!VALID_INTNO_DISINT(intno))
	{
		return false;
	}

#if 0	
	uint32_t intreg_addr = INTREG_ADDRESS(intno);
	/* 6bit�ܤ򥻥å� */
	sil_wrb_mem((void *)intreg_addr , 
		sil_reb_mem((void *)intreg_addr) | (0x01U << 6));
#endif
	/* ����߶ػ߾��֥ӥåȤ򥻥å� */
	disint_table[(intno / 16u)] |= (1u << (intno % 16u));
	
	return(true);
}
extern bool_t x_disable_int(INTNO intno);

#define t_disable_int(intno) x_disable_int(intno)
#define i_disable_int(intno) x_disable_int(intno)

/*
 *  ������׵�ػߥե饰�β��
 *
 *  �����°�������ꤵ��Ƥ��ʤ�������׵�饤����Ф��Ƴ�����׵�ػ�
 *  �ե饰�򥯥ꥢ���褦�Ȥ������ˤϡ�false���֤���
 */

extern bool_t dev_enable_int(INTNO intno);

Inline bool_t
private_enable_int(INTNO intno)
{
	if(!VALID_INTNO_DISINT(intno))
	{
		return false;
	}

#if 0	
	uint32_t intreg_addr = INTREG_ADDRESS(intno);
	/* 6bit�ܤ򥯥ꥢ */
	sil_wrb_mem((void *)intreg_addr , 
		sil_reb_mem((void *)intreg_addr) & ~(0x01U << 6));
#endif
	/* ����߶ػ߾��֥ӥåȤ򥯥ꥢ */
	disint_table[(intno / 16u)] &= ~(1u << (intno % 16u));
	
	return(true);
}

extern bool_t x_enable_int(INTNO intno);


#define t_enable_int(intno) x_enable_int(intno)
#define i_enable_int(intno) x_enable_int(intno)


/*
 *  ������׵�Υ��ꥢ
 */
Inline void
x_clear_int(INTNO intno)
{
	uint32_t intreg_addr = INTREG_ADDRESS(intno);
	
	if(!VALID_INTNO_DISINT(intno))
	{
		return ;
	}
	
	/* 7bit�ܤ򥯥ꥢ */
	sil_wrb_mem((void *)intreg_addr , 
		sil_reb_mem((void *)intreg_addr) & ~(0x01U << 7));
}

#define t_clear_int(intno)		x_clear_int(intno)
#define i_clear_int(intno)		x_clear_int(intno)

/*
 *  ������׵�Υ����å�
 */
Inline bool_t
x_probe_int(INTNO intno)
{
	uint32_t intreg_addr = INTREG_ADDRESS(intno);
	
	if(!VALID_INTNO_DISINT(intno))
	{
		return false;
	}
	
	/* 6bit�ܤΥӥå��ͤ�Ƚ�ꤹ�롥*/
	if((sil_reb_mem((void *)intreg_addr) & (0x01U << 6u)) != 0x00)
	{
		return true;
	}
	
	return false;
}

#define t_probe_int(intno) x_probe_int(intno)
#define i_probe_int(intno) x_probe_int(intno)


/*
 *  ������׵�饤���°��������
 *
 *  V850�Ǥϡ������ͥ�ǰ���������ͥ���٤�8�ʳ��Ǥ��뤿�ᡤintpri
 *  �Ȥ���Ϳ���뤳�Ȥ��Ǥ����ͤ�-7���0��ɸ��Ǥ��롥
 */
extern void x_config_int(INTNO intno, ATR intatr, PRI intpri);

/*
 *  ����ߥϥ�ɥ�������ɬ�פ�IRC���
 *
 *  ������װ��ϼ�ư���ꥢ����뤿�Ჿ�⤷�ʤ�
 */
Inline void
i_begin_int(INTNO intno)
{
}

/*
 *  ����ߥϥ�ɥ�νи���ɬ�פ�IRC���
 *
 * 
 */
Inline void
i_end_int(INTNO intno)
{
}

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  CPU�㳰�ϥ�ɥ�ط�
 */

/*
 *  �㳰�ϥ�ɥ���� p_excinf ����Ƽ�������Ф�����Υޥ���
 */
#define P_EXCINF_OFFSET_PC				UINT_C(0)
#define P_EXCINF_OFFSET_SP				UINT_C(4)
#define P_EXCINF_OFFSET_PSW				UINT_C(8)
#define P_EXCINF_OFFSET_ECR				UINT_C(12)
#define P_EXCINF_OFFSET_CPU_LOCKED		UINT_C(16)

#ifndef TOPPERS_MACRO_ONLY

/*
 *  CPU�㳰�ϥ�ɥ������
 *
 *  �ƥ�ץ졼�ȥե�������㳰�ϥ�ɥ���������뤿�ᡤ����������롥
 */
#define x_define_exc(excno, exc_entry)


/*
 *  CPU�㳰�ϥ�ɥ�����������������ޥ���
 */
#define EXC_ENTRY2(excno, exchdr)    _kernel_##exchdr##_##excno
#define EXC_ENTRY(excno, exchdr)     EXC_ENTRY2(excno, exchdr)
#define EXCHDR_ENTRY2(excno, exchdr) extern void _kernel_##exchdr##_##excno(void *sp);
#define EXCHDR_ENTRY(excno, excno_num, exchdr)  EXCHDR_ENTRY2(excno, exchdr)



/*
 *  CPU�㳰��ȯ���������Υ���ƥ����Ȥλ���
 *
 *  CPU�㳰��ȯ���������Υ���ƥ����Ȥ�������������ƥ����Ȥλ���false��
 *  �����Ǥʤ�����true���֤���
 */
Inline bool_t
exc_sense_context(void)
{
	return (intnest > 1u)? true : false;
}

/*
 *  CPU�㳰��ȯ����������������߶ػ߾��֤λ���
 *
 *  CPU�㳰��ȯ����������������߶ػ߾��֤���������߶ػ߲�����֤λ���false��
 *  �����Ǥʤ�����true���֤���
 */
Inline bool_t
exc_sense_id(void *p_excinf)
{
	return (((*((uint32_t *)((uint32_t)p_excinf + P_EXCINF_OFFSET_PSW)))
				& (1u << 5)) != 0u)?
			true : false;
}

/*
 *  CPU�㳰��ȯ����������CPU��å����֤λ���
 *
 *  CPU�㳰��ȯ����������CPU��å����֤���CPU��å�������֤λ���false��
 *  �����Ǥʤ�����true���֤���
 */
Inline bool_t
exc_sense_lock(void *p_excinf)
{
	return *((bool_t *)((uint32_t)p_excinf + P_EXCINF_OFFSET_CPU_LOCKED));
}

/*
 *  CPU�㳰��ȯ���������Υ���ƥ����Ȥȳ���ߤΥޥ������֤λ���
 *
 *  CPU�㳰��ȯ���������Υ����ƥ���֤��������ͥ�¹���Ǥʤ�����������
 *  ��ƥ����ȤǤ��ꡤ������ߥ�å����֤Ǥʤ���CPU��å����֤Ǥʤ����ʥ�
 *  �ǥ��Ρ˳����ͥ���٥ޥ�����������֤Ǥ������true�������Ǥʤ���
 *  ��false���֤���CPU�㳰�������ͥ�������γ���߽������ȯ���������
 *  �ˤ�false���֤��ˡ�
 */
Inline bool_t
exc_sense_intmask(void *p_excinf)
{
	return ((exc_sense_context() == false)
			&& (exc_sense_lock(p_excinf) == false)
			&& (exc_sense_id(p_excinf) == false)
			&& (get_intpri() == INTPRI_ENAALL))?
			true : false;
}

/*
 * Trapa�ʳ����㳰����Ͽ����Ƥ��ʤ��㳰��ȯ������ȸƤӽФ����
 */
extern void default_exc_handler(void *p_excinf);

/*
 * ̤��Ͽ�γ���ߤ�ȯ���������˸ƤӽФ����
 */
extern void default_int_handler(void *p_excinf);

/*
 *  �ץ��å���¸�ν����
 */
extern void prc_initialize(void);

/*
 *  �ץ��å���¸�ν�λ������
 */
extern void prc_terminate(void);

/*
 *  atexit�ν����ȥǥ��ȥ饯���μ¹�
 */
Inline void
call_atexit(void)
{
    extern void    software_term_hook(void);
    void (*volatile fp)(void) = software_term_hook;

    /*
     *  software_term_hook�ؤΥݥ��󥿤򡤰�övolatile����Τ���fp����
     *  �����Ƥ���Ȥ��Τϡ�0�Ȥ���Ӥ���Ŭ���Ǻ������ʤ��褦�ˤ��뤿
     *  ��Ǥ��롥
     */
    if (fp != 0) {
        (*fp)();
    }
}

#endif /* TOPPERS_MACRO_ONLY */

#endif /* TOPPERS_PRC_CONFIG_H */
