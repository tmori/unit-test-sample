APPL_CFG += sample1.cfg

APPLDIR	+= $(APL_DIR)
APPLDIR	+= $(TESTFW_DIR)/src
APPLDIR	+= $(TESTFW_DIR)/extras/fixture/src
APPLDIR	+= $(TESTFW_DIR)/extras/memory/src

APPL_COBJS	+= sample1.o
APPL_COBJS	+= unity.o
APPL_COBJS	+= unity_fixture.o
