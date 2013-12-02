#include <CUnit/Basic.h>
#include "../string_lib.h"

static void test_str_nnew_returns_string_of_correct_length()
{
	STRING str = str_nnew(80);
	CU_ASSERT(str_size(str) == 80);
	str_destroy(str);
}

static CU_TestInfo tests[] = {
	{ "Test str_nnew() return string of correct length", test_str_nnew_returns_string_of_correct_length },
	CU_TEST_INFO_NULL
};

CU_SuiteInfo str_nnew_suite = {
	"str_nnew() suite",
	NULL,
	NULL,
	tests
};
