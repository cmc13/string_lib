#include <CUnit/Basic.h>
#include "../string_lib.h"

static STRING str = NULL;

static int init_suite()
{
	str = str_new();
	return 0;
}

static int clean_suite()
{
	str_destroy(str);
	str = NULL;
	return 0;
}

static void test_str_new_returns_non_null_pointer()
{
	CU_ASSERT_PTR_NOT_NULL(str);
}

static void test_str_new_returns_0_length_string()
{
	CU_ASSERT_EQUAL(str_length(str), 0);
}

static void test_str_new_returns_20_size_string()
{
	CU_ASSERT_EQUAL(str_size(str), 20);
}

static void test_str_new_returns_empty_string()
{
	CU_ASSERT_STRING_EQUAL(str, "");
}

static CU_TestInfo tests[] = {
	{ "Test str_new() returns non-null pointer", test_str_new_returns_non_null_pointer },
	{ "Test str_new() returns 0-length string", test_str_new_returns_0_length_string },
	{ "Test str_new() returns size 20 string", test_str_new_returns_20_size_string },
	{ "Test str_new() returns empty string", test_str_new_returns_empty_string },
	CU_TEST_INFO_NULL
};

CU_SuiteInfo str_new_suite = {
	"str_new() suite",
	init_suite,
	clean_suite,
	tests
};
