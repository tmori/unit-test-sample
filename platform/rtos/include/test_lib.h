/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2005-2011 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: test_lib.h 2252 2011-09-07 12:52:04Z ertl-hiro $
 */

/* 
 *		�ƥ��ȥץ�����ѥ饤�֥��
 */

#ifndef TOPPERS_TEST_LIB_H
#define TOPPERS_TEST_LIB_H

#ifdef __cplusplus
extern "C" {
#endif

#include <t_stddef.h>

/*
 *  �������åȰ�¸�����
 */
#include "target_test.h"

/*
 *	���ʿ��Ǵؿ��η�
 */
typedef ER (*BIT_FUNC)(void);

/*
 *	���ʿ��Ǵؿ�������
 */
extern void	set_bit_func(BIT_FUNC bit_func);

/*
 *  �����ƥ���ν��Ͻ���
 */
extern void	syslog_flush(void);

/*
 *	�ƥ��ȥץ����ν�λ
 */
extern void	test_finish(void);

/*
 *	�����å��ݥ����
 */
extern void	check_point(uint_t count);

/*
 *	��λ�����å��ݥ����
 */
extern void	check_finish(uint_t count);

/*
 *	�������å�
 */
extern void	_check_assert(const char *expr, const char *file, int_t line);
#define check_assert(exp) \
	((void)(!(exp) ? (_check_assert(#exp, __FILE__, __LINE__), 0) : 0))

/*
 *	���顼�����ɥ����å�
 */
extern void	_check_ercd(ER ercd, const char *file, int_t line);
#define check_ercd(ercd, expected_ercd) \
	((void)((ercd) != (expected_ercd) ? \
					(_check_ercd(ercd, __FILE__, __LINE__), 0) : 0))

/*
 *	�����ƥ���֤Υ����å�
 */
Inline void
check_state(bool_t ctx, bool_t loc, PRI ipm, bool_t dsp,
										bool_t dpn, bool_t tex)
{
	PRI		intpri;
	ER		ercd;

	check_assert(sns_ctx() == ctx);
	check_assert(sns_loc() == loc);
	if (!loc) {
		/*
		 *  IPM�Υ����å��ϡ�CPU��å�������֤ξ��ˤΤ߹Ԥ���
		 */
		ercd = get_ipm(&intpri);
		check_ercd(ercd, E_OK);
		check_assert(intpri == ipm);
	}
	check_assert(sns_dsp() == dsp);
	check_assert(sns_dpn() == dpn);
	check_assert(sns_tex() == tex);
}

/*
 *	�����ƥ���֤Υ����å����󥿥�������ƥ������ѡ�
 */
Inline void
check_state_i(bool_t ctx, bool_t loc, bool_t dsp, bool_t dpn, bool_t tex)
{
	check_assert(sns_ctx() == ctx);
	check_assert(sns_loc() == loc);
	check_assert(sns_dsp() == dsp);
	check_assert(sns_dpn() == dpn);
	check_assert(sns_tex() == tex);
}

#ifdef __cplusplus
}
#endif

#endif /* TOPPERS_TEST_LIB_H */
