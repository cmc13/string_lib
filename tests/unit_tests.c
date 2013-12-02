#include <CUnit/Basic.h>
#include "../string_lib.h"

extern CU_SuiteInfo str_new_suite;
extern CU_SuiteInfo str_nnew_suite;

int main()
{
	CU_SuiteInfo suites[] = {
		str_new_suite,
		str_nnew_suite,
		CU_SUITE_INFO_NULL
	};

	if (CU_initialize_registry() == CUE_SUCCESS)
	{
		if (CU_register_suites(suites) == CUE_SUCCESS)
		{
			CU_basic_set_mode(CU_BRM_VERBOSE);
			CU_basic_run_tests();
		}
	}

	CU_cleanup_registry();

	return CU_get_error();
}
