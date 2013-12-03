#include <CUnit/Basic.h>
#include "../string_lib.h"

void test_str_copy_copies_string_data()
{
	STRING str1 = str_new();
	STRING str2 = str_create("This is a test");

	str_copy(&str1, str2);

	CU_ASSERT_STRING_EQUAL(str1, str2);

	str_destroy(str1);
	str_destroy(str2);
}

void test_str_copy_makes_strings_equal_length()
{
	STRING str1 = str_new();
	STRING str2 = str_create("This is a test");

	str_copy(&str1, str2);

	CU_ASSERT_EQUAL(str_length(str1), str_length(str2));

	str_destroy(str1);
	str_destroy(str2);
}

static CU_TestInfo tests[] = {
	{ "Test str_copy() copies string data", test_str_copy_copies_string_data },
	{ "Test str_copy() makes strings equal length", test_str_copy_makes_strings_equal_length },
	CU_TEST_INFO_NULL
};

CU_SuiteInfo str_copy_suite = {
	"str_copy() suite",
	NULL,
	NULL,
	tests
};
