/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2011 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: sil.h 2242 2011-08-26 21:00:19Z ertl-hiro $
 */

/*
 *		�����ƥ।�󥿥ե������쥤��
 *
 *  �����ƥ।�󥿥ե������쥤��Υ����ӥ�����������������ȥޥ����
 *  �ɤ������ޤ�إå��ե����롥
 *
 *  ������֥����Υ������ե����뤫�餳�Υե�����򥤥󥯥롼�ɤ����
 *  �ϡ�TOPPERS_MACRO_ONLY��������Ƥ������Ȥǡ��ޥ�������ʳ��ε��Ҥ�
 *  �������Ȥ��Ǥ��롥
 *
 *  ���Υե�����򥤥󥯥롼�ɤ������˥��󥯥롼�ɤ��Ƥ����٤��ե�����
 *  �Ϥʤ���
 */

#ifndef TOPPERS_SIL_H
#define TOPPERS_SIL_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 *	TOPPERS���̤Υǡ�������������ޥ���
 */
#include <t_stddef.h>

/*
 *  �������åȰ�¸��
 */
#include "target_sil.h"

#ifndef TOPPERS_MACRO_ONLY

/*
 *  ������ߥ�å����֤�����
 *
 *  SIL_PRE_LOC��SIL_LOC_INT()��SIL_UNL_INT()�ϡ��������åȰ�¸������
 *  �դ��롥�ǥե���Ȥ�������Ѱդ��Ƥ��ʤ���
 */

/*
 *  ���������Ԥ�
 */
extern void	sil_dly_nse(ulong_t dlytim) throw();

/*
 *  ����ǥ������ȿž
 */
#ifndef TOPPERS_SIL_REV_ENDIAN_UINT16
#define	TOPPERS_SIL_REV_ENDIAN_UINT16(data) \
				((((data) & 0xffU) << 8) | (((data) >> 8) & 0xffU))
#endif /* TOPPERS_SIL_REV_ENDIAN_UINT16 */

#ifndef TOPPERS_SIL_REV_ENDIAN_UINT32
#define	TOPPERS_SIL_REV_ENDIAN_UINT32(data) \
				((((data) & 0xffU) << 24) | (((data) & 0xff00U) << 8) \
					| (((data) >> 8) & 0xff00U) | (((data) >> 24) & 0xffU))
#endif /* TOPPERS_SIL_REV_ENDIAN_UINT32 */

/*
 *  ������֥��������ؿ�
 */
#ifndef TOPPERS_OMIT_SIL_ACCESS

/*
 *  8�ӥå�ñ�̤��ɽФ��������
 */
#ifdef UINT8_MAX

Inline uint8_t
sil_reb_mem(const uint8_t *mem)
{
	uint8_t	data;

	data = *((const volatile uint8_t *) mem);
	return(data);
}

Inline void
sil_wrb_mem(uint8_t *mem, uint8_t data)
{
	*((volatile uint8_t *) mem) = data;
}

#endif /* UINT8_MAX */

/*
 *  16�ӥå�ñ�̤��ɽФ��������
 */

Inline uint16_t
sil_reh_mem(const uint16_t *mem)
{
	uint16_t	data;

	data = *((const volatile uint16_t *) mem);
	return(data);
}

Inline void
sil_wrh_mem(uint16_t *mem, uint16_t data)
{
	*((volatile uint16_t *) mem) = data;
}

#ifdef SIL_ENDIAN_BIG			/* �ӥå�����ǥ�����ץ��å� */

#define	sil_reh_bem(mem)		sil_reh_mem(mem)
#define	sil_wrh_bem(mem, data)	sil_wrh_mem(mem, data)

#ifndef TOPPERS_OMIT_SIL_REH_LEM

Inline uint16_t
sil_reh_lem(const uint16_t *mem)
{
	uint16_t	data;

	data = *((const volatile uint16_t *) mem);
	return(TOPPERS_SIL_REV_ENDIAN_UINT16(data));
}

#endif /* TOPPERS_OMIT_SIL_REH_LEM */
#ifndef TOPPERS_OMIT_SIL_WRH_LEM

Inline void
sil_wrh_lem(uint16_t *mem, uint16_t data)
{
	*((volatile uint16_t *) mem) = TOPPERS_SIL_REV_ENDIAN_UINT16(data);
}

#endif /* TOPPERS_OMIT_SIL_WRH_LEM */
#else /* SIL_ENDIAN_BIG */
#ifdef SIL_ENDIAN_LITTLE		/* ��ȥ륨��ǥ�����ץ��å� */

#define	sil_reh_lem(mem)		sil_reh_mem(mem)
#define	sil_wrh_lem(mem, data)	sil_wrh_mem(mem, data)

#ifndef TOPPERS_OMIT_SIL_REH_BEM

Inline uint16_t
sil_reh_bem(const uint16_t *mem)
{
	uint16_t	data;

	data = *((const volatile uint16_t *) mem);
	return(TOPPERS_SIL_REV_ENDIAN_UINT16(data));
}

#endif /* TOPPERS_OMIT_SIL_REH_BEM */
#ifndef TOPPERS_OMIT_SIL_WRH_BEM

Inline void
sil_wrh_bem(uint16_t *mem, uint16_t data)
{
	*((volatile uint16_t *) mem) = TOPPERS_SIL_REV_ENDIAN_UINT16(data);
}

#endif /* TOPPERS_OMIT_SIL_WRH_BEM */
#else /* SIL_ENDIAN_LITTLE */

#error Neither SIL_ENDIAN_BIG nor SIL_ENDIAN_LITTLE is defined.

#endif /* SIL_ENDIAN_LITTLE */
#endif /* SIL_ENDIAN_BIG */

/*
 *  32�ӥå�ñ�̤��ɽФ��������
 */

Inline uint32_t
sil_rew_mem(const uint32_t *mem)
{
	uint32_t	data;

	data = *((const volatile uint32_t *) mem);
	return(data);
}

Inline void
sil_wrw_mem(uint32_t *mem, uint32_t data)
{
	*((volatile uint32_t *) mem) = data;
}

#ifdef SIL_ENDIAN_BIG			/* �ӥå�����ǥ�����ץ��å� */

#define	sil_rew_bem(mem)		sil_rew_mem(mem)
#define	sil_wrw_bem(mem, data)	sil_wrw_mem(mem, data)

#ifndef TOPPERS_OMIT_SIL_REW_LEM

Inline uint32_t
sil_rew_lem(const uint32_t *mem)
{
	uint32_t	data;

	data = *((const volatile uint32_t *) mem);
	return(TOPPERS_SIL_REV_ENDIAN_UINT32(data));
}

#endif /* TOPPERS_OMIT_SIL_REW_LEM */
#ifndef TOPPERS_OMIT_SIL_WRW_LEM

Inline void
sil_wrw_lem(uint32_t *mem, uint32_t data)
{
	*((volatile uint32_t *) mem) = TOPPERS_SIL_REV_ENDIAN_UINT32(data);
}

#endif /* TOPPERS_OMIT_SIL_WRW_LEM */
#else /* SIL_ENDIAN_BIG */		/* ��ȥ륨��ǥ�����ץ��å� */

#define	sil_rew_lem(mem)		sil_rew_mem(mem)
#define	sil_wrw_lem(mem, data)	sil_wrw_mem(mem, data)

#ifndef TOPPERS_OMIT_SIL_REW_BEM

Inline uint32_t
sil_rew_bem(const uint32_t *mem)
{
	uint32_t	data;

	data = *((const volatile uint32_t *) mem);
	return(TOPPERS_SIL_REV_ENDIAN_UINT32(data));
}

#endif /* TOPPERS_OMIT_SIL_REW_BEM */
#ifndef TOPPERS_OMIT_SIL_WRW_BEM

Inline void
sil_wrw_bem(uint32_t *mem, uint32_t data)
{
	*((volatile uint32_t *) mem) = TOPPERS_SIL_REV_ENDIAN_UINT32(data);
}

#endif /* TOPPERS_OMIT_SIL_WRW_BEM */
#endif /* SIL_ENDIAN_BIG */
#endif /* TOPPERS_OMIT_SIL_ACCESS */

#endif /* TOPPERS_MACRO_ONLY */

#ifdef __cplusplus
}
#endif

#endif /* TOPPERS_SIL_H */
