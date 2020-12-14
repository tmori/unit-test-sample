#
#  TOPPERS/JSP Kernel
#      Toyohashi Open Platform for Embedded Real-Time Systems/
#      Just Standard Profile Kernel
#
#  Copyright (C) 2000,2001 by Embedded and Real-Time Systems Laboratory
#                              Toyohashi Univ. of Technology, JAPAN
#  Copyright (C) 2005 by Freelines CO.,Ltd
#
#  Copyright (C) 2010 by Meika Sugimoto
#
#  �嵭����Ԥϡ��ʲ��� (1)���(4) �ξ�狼��Free Software Foundation
#  �ˤ�äƸ�ɽ����Ƥ��� GNU General Public License �� Version 2 �˵�
#  �Ҥ���Ƥ���������������˸¤ꡤ�ܥ��եȥ��������ܥ��եȥ�����
#  ����Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ������ۡʰʲ���
#  ���ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
#  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
#      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
#      ����������˴ޤޤ�Ƥ��뤳�ȡ�
#  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
#      �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
#      �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
#      ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
#  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
#      �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
#      �ȡ�
#    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
#        �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
#    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
#        ��𤹤뤳�ȡ�
#  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
#      ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
#
#  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
#  ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����Ŭ�Ѳ�ǽ����
#  �ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ����������Ѥˤ��ľ
#  ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤������Ǥ�����ʤ���
#
#

#
#  Makefile �Υץ��å���¸ (V850ES/FK3��)
#

#
#  GNU��ȯ�Ķ��Υ������åȥ������ƥ���������
#
GCC_TARGET = v850-elf

#
#  ����ѥ���ե饰
#
INCLUDES := $(INCLUDES) -I$(SRCDIR)/arch/$(PRC)_$(TOOL)
COPTS := $(COPTS) -mv850e2v3 -mdisable-callt
CDEFS := $(CDEFS) -DLABEL_ASM

#
#  �����ͥ�˴ؤ������
#
KERNEL_DIR		:= $(KERNEL_DIR) $(SRCDIR)/arch/$(PRC)_$(TOOL)
KERNEL_ASMOBJS	:= $(KERNEL_ASMOBJS) prc_support.o prc_sil.o
KERNEL_COBJS	:= $(KERNEL_COBJS) prc_config.o

#
#  ����ե�����졼����Ϣ������
#
CFG2_OUT := kernel_cfg_asm.S $(CFG2_OUT)
CFG_ASMOBJS := kernel_cfg_asm.o $(CFG_ASMOBJS)
CFG_TABS := --cfg1-def-table $(SRCDIR)/arch/v850_gcc/prc_def.csv $(CFG_TABS)

#
#  ��󥯤˴ؤ�������
#

LDFLAGS := -nostartfiles -lgcc -lc $(LDFLAGS)
CFG1_OUT_LDFLAGS := -nostdlib

#
#  �������ȥ��åץ⥸�塼��˴ؤ������
#
START_OBJS = start.o

$(START_OBJS): %.o: %.S
	$(CC) -c $(CFLAGS) $(KERNEL_CFLAGS) $<

$(START_OBJS:.o=.d): %.d: %.S
	@$(PERL) $(SRCDIR)/utils/makedep -C $(CC) \
		-O "$(CFLAGS) $(KERNEL_CFLAGS)" $< >> Makefile.depend

#
#  kernel_cfg_asm.S�ΤΥ���ѥ���롼��Ȱ�¸�ط������롼������
#
#  kernel_cfg_asm.S�ϡ����ץꥱ�������ץ�����ѡ������ƥॵ��
#  �ӥ��ѡ������ͥ��ѤΤ��٤ƤΥ��ץ������դ��ƥ���ѥ��뤹�롥
#

CFG2_OUT_SRCS := kernel_cfg_asm.S $(CFG2_OUT_SRCS)

#
#  ����ե�����졼���Ѥΰ�¸�ط������
#

cfg1_out.c: $(SRCDIR)/arch/v850_gcc/prc_def.csv
