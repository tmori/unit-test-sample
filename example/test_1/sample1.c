#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include "syssvc/serial.h"
#include "syssvc/syslog.h"
#include "kernel_cfg.h"
#include "sample1.h"
#include "unity.h"
#include "unity_fixture.h"

/*
 *  サービスコールのエラーのログ出力
 */
Inline void
svc_perror(const char *file, int_t line, const char *expr, ER ercd)
{
	if (ercd < 0) {
		t_perror(LOG_ERROR, file, line, expr, ercd);
	}
}

#define	SVC_PERROR(expr)	svc_perror(__FILE__, __LINE__, #expr, (expr))

extern void target_fput_log(char c);

void RS232_putc(int a)
{
	target_fput_log(a);
}
void RS232_flush(void)
{
	;
}
void RS232_config(int rate, int a, int b, int c)
{
	;
}
void RS232_close(void)
{
	;
}


TEST_GROUP(ProductionCode);

TEST_GROUP_RUNNER(ProductionCode)
{
  RUN_TEST_CASE(ProductionCode, test_1);
}

static void RunAllTests(void)
{
  RUN_TEST_GROUP(ProductionCode);
}

/*
 *  メインタスク
 */
void main_task(intptr_t exinf)
{
	syslog(LOG_NOTICE, "TEST START");
	UnityMain(0, NULL, RunAllTests);

	SVC_PERROR(ext_ker());
	assert(0);
}

static int Counter;

TEST_SETUP(ProductionCode)
{
  //This is run before EACH TEST
  Counter = 0x5a5a;
}

TEST_TEAR_DOWN(ProductionCode)
{
}

static int test_1(int a)
{
	return a;
}
TEST(ProductionCode, test_1)
{
	TEST_ASSERT_EQUAL(0, test_1(78));
	TEST_ASSERT_EQUAL(10, test_1(10));
}
