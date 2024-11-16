/**
 * @file utest.h
 * @author joohjo
 */

#ifndef UTEST_H_
#define UTEST_H_

/**
 * @brief UnitTest Class
 * @details This class is to verify the functionalities of each method\n
 *          This test is executed in the command line
 *
 * @code
 *	$ ./calc UnitTest
 * @endcode
 */
class UnitTest
{
public:
	UnitTest() {}
	~UnitTest() {}

	void TEST_DIVIDER_001(void);
	void TEST_DIVIDER_002(void);
	void TEST_DIVIDER_003(void);
	void TEST_DIVIDER_004(void);
	void TEST_DIVIDER_005(void);
	void TEST_DIVIDER_006(void);
	void TEST_DIVIDER_007(void);
	void TEST_DIVIDER_008(void);
	void TEST_DIVIDER_009(void);
	void TEST_DIVIDER_010(void);
};

#endif /* UTEST_H_ */
