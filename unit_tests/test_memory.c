#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "memory.h"

static void test_memset(void** state)
{
		assert_int_equal(3,3);
}


int main (void)
{
	const struct CMUnitTest tests[] =
	{
		cmocka_unit_test(test_memset),
	};
	
	return cmocka_run_group_tests(tests,NULL,NULL);

}