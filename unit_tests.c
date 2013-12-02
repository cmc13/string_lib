#include <CUnit/Basic.h>
#include "string_lib.h"

int main()
{
	CU_pSuite pSuite = NULL;
	CU_SuiteInfo suites[] = {
		CU_SUITE_INFO_NULL
	};

	if (CU_initialize_registry() != CUE_SUCCESS)
		return CU_get_error();

	if (CU_register_suites(suites) != CUE_SUCCESS)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

	return CU_get_error();
}
