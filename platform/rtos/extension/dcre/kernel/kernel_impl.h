/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2010 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: kernel_impl.h 1966 2010-11-20 07:23:56Z ertl-hiro $
 */

/*
 *		TOPPERS/ASP�����ͥ���������ɸ��إå��ե�����
 *
 *  ���Υإå��ե�����ϡ������ͥ��������ץ����Υ������ե�����
 *  ��ɬ�����󥯥롼�ɤ���٤�ɸ��إå��ե�����Ǥ��롥
 *
 *  ������֥����Υ������ե����뤫�餳�Υե�����򥤥󥯥롼�ɤ����
 *  �ϡ�TOPPERS_MACRO_ONLY��������Ƥ���������ˤ�ꡤ�ޥ�������ʳ���
 *  �����褦�ˤʤäƤ��롥
 */

#ifndef TOPPERS_KERNEL_IMPL_H
#define TOPPERS_KERNEL_IMPL_H

/*
 *  �����ͥ����������̾�Υ�͡���
 */
#include "kernel_rename.h"

/*
 *  ���ץꥱ�������ȶ��̤Υإå��ե�����
 */
#include <kernel.h>

/*
 *  �����ƥ����ǽ�Τ�������
 */
#include <t_syslog.h>

/*
 *  �����㥹�Ȥ�Ԥ��ޥ�������
 */
#ifndef CAST
#define CAST(type, val)		((type)(val))
#endif /* CAST */

/*
 *  �������åȰ�¸��������
 */
#include "target_config.h"

/*
 *  ���٤Ƥδؿ��򥳥�ѥ��뤹�뤿������
 */
#ifdef ALLFUNC
#include "allfunc.h"
#endif /* ALLFUNC */

/*
 *  �ӥåȥե�����ɤǤ����̵��������
 *
 *  8�ӥåȰʲ������Υӥåȥե�����ɤǡ����̵�������ͤ��ݻ����������
 *  ���Ѥ���٤��ǡ�������ANSI C�Ǥϡ��ӥåȥե�����ɤΥǡ������ˤ�
 *  int��unsigned int����������ʤ����ᡤ�ǥե���Ȥ������unsigned
 *  int�Ȥ��Ƥ��뤬���������åȤ���ӥġ����¸�ǡ�unsigned char�ޤ���
 *  unsigned short���������������Ψ���ɤ���礬���롥
 */
#ifndef BIT_FIELD_UINT
#define BIT_FIELD_UINT		unsigned int
#endif /* BIT_FIELD_UINT */

/*
 *  �ӥåȥե�����ɤǤΥ֡��뷿
 *
 *  1�ӥå����Υӥåȥե�����ɤǡ��֡����ͤ��ݻ������������Ѥ���٤�
 *  �ǡ��������ǥե���ȤǤ�BIT_FIELD_UINT��Ʊ���������Ƥ��뤬���֡�
 *  ���ͤ��ݻ����뤳�Ȥ��������뤿����̤�̾�ΤȤ��Ƥ��롥
 */
#ifndef BIT_FIELD_BOOL
#define BIT_FIELD_BOOL		BIT_FIELD_UINT
#endif /* BIT_FIELD_BOOL */

/*
 *  ���֥�������ID�κǾ��ͤ����
 */
#define TMIN_TSKID		1		/* ������ID�κǾ��� */
#define TMIN_SEMID		1		/* ���ޥե�ID�κǾ��� */
#define TMIN_FLGID		1		/* �ե饰ID�κǾ��� */
#define TMIN_DTQID		1		/* �ǡ������塼ID�κǾ��� */
#define TMIN_PDQID		1		/* ͥ���٥ǡ������塼ID�κǾ��� */
#define TMIN_MBXID		1		/* �᡼��ܥå���ID�κǾ��� */
#define TMIN_MPFID		1		/* ����Ĺ����ס���ID�κǾ��� */
#define TMIN_CYCID		1		/* �����ϥ�ɥ�ID�κǾ��� */
#define TMIN_ALMID		1		/* ���顼��ϥ�ɥ�ID�κǾ��� */
#define TMIN_ISRID		1		/* ����ߥ����ӥ��롼����ID�κǾ��� */

/*
 *  ͥ���٤��ʳ��������
 */
#define TNUM_TPRI		(TMAX_TPRI - TMIN_TPRI + 1)
#define TNUM_MPRI		(TMAX_MPRI - TMIN_MPRI + 1)
#define TNUM_INTPRI		(TMAX_INTPRI - TMIN_INTPRI + 1)

/*
 *  �����ͥ������ǻ��Ѥ���°�������
 */
#define TA_NOEXS		((ATR)(-1))			/* ̤��Ͽ���� */

#ifndef TA_MEMALLOC
#define TA_MEMALLOC		UINT_C(0x8000)		/* �����ΰ�򥫡��ͥ�ǳ��� */
#endif /* TA_MEMALLOC */
#ifndef TA_MBALLOC
#define TA_MBALLOC		UINT_C(0x4000)		/* �����ΰ�򥫡��ͥ�ǳ��� */
#endif /* TA_MBALLOC */

/*
 *  �������å�����Υ��顼�����å��ޥ���Υǥե�����ͤ����
 */
#ifndef TARGET_TSKATR
#define TARGET_TSKATR		0U		/* �������å�����Υ�����°�� */
#endif /* TARGET_TSKATR */

#ifndef TARGET_ISRATR
#define TARGET_ISRATR		0U		/* �������å������ISR°�� */
#endif /* TARGET_ISRATR */

/*
 *  �إå��ե����������ʤ��⥸�塼��δؿ����ѿ������
 */
#ifndef TOPPERS_MACRO_ONLY

/*
 *  �ƥ⥸�塼��ν������kernel_cfg.c��
 */
extern void	initialize_object(void);

/*
 *  ������롼����μ¹ԡ�kernel_cfg.c��
 */
extern void	call_inirtn(void);

/*
 *  ��λ�����롼����μ¹ԡ�kernel_cfg.c��
 */
extern void	call_terrtn(void);

/*
 *  �󥿥�������ƥ������ѤΥ����å��ΰ��kernel_cfg.c��
 */
extern const SIZE	istksz;		/* �����å��ΰ�Υ������ʴݤ᤿�͡� */
extern STK_T *const	istk;		/* �����å��ΰ����Ƭ���� */
#ifdef TOPPERS_ISTKPT
extern STK_T *const	istkpt;		/* �����å��ݥ��󥿤ν���� */
#endif /* TOPPERS_ISTKPT */

/*
 *  �����ͥ뤬����դ�������ΰ��kernel_cfg.c��
 */
extern const SIZE	kmmsz;		/* �����ͥ뤬����դ�������ΰ�Υ����� */
extern MB_T *const	kmm;		/* �����ͥ뤬����դ�������ΰ����Ƭ���� */

/*
 *  �����ͥ�ư����֥ե饰��startup.c��
 */
extern bool_t	kerflg;

/*
 *  �����ͥ�ε�ư��startup.c��
 */
extern void	sta_ker(void);

/*
 *  �����ͥ�ν�λ������startup.c��
 */
extern void	exit_kernel(void);

/*
 *  �����ͥ�γ���դ�������ΰ�δ�����startup.c��
 */
extern void initialize_kmm(void);
extern void *kernel_malloc(SIZE size);
extern void kernel_free(void *ptr);

#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_KERNEL_IMPL_H */
