/**
 * @file utest.cpp
 * @author joohjo
 */

#include <iostream>
#include <limits>
#include <fstream>
#include <cmath>

#include "utest.h"
#include "CalculationEngine.h"

using namespace std;

#define TOLERANCE (0.000001)

inline void PASS(void) { cout << "---> PASS" << endl;}
inline void FAIL(void) { cout << "---> FAIL" << endl; return;}

/**
 * @brief Testing read_input_data() of Divider
 * @details Check the scope of integer which is entered as input data\n
 *          This test is inside scope of integer including min value, zero and max value\n
 *
 *          - Test Step 001 : Input min\n
 *          -- Pass Criteria 001-1 : The size of input storage should be 1\n
 *          -- Pass Criteria 001-2 : The output value should be equal to min\n
 *          - Test Step 002 : Input zero\n
 *          -- Pass Criteria 002-1 : The size of input storage should be 2\n
 *          -- Pass Criteria 002-2 : The output value should be equal to zero\n
 *          - Test Step 003 : Input max\n
 *          -- Pass Criteria 003-1 : The size of input storage should be 3\n
 *          -- Pass Criteria 003-2 : The output value should be equal to max\n
 */
void UnitTest::TEST_DIVIDER_001(void) {
	cout << "########################################" << endl;
	cout << "###        TEST_DIVIDER_001          ###" << endl;
	cout << "########################################" << endl;

	Divider<int> actDivider;
	vector<int>* storage = actDivider.get_input_storage();

	{
		// Test Step 001
		int in_value = numeric_limits<int>::min();
		string in_value_str = to_string(in_value);
		cout << "[Test Step 001] Input a value : " << in_value_str << endl;
		actDivider.read_input_data(in_value_str);

		// Pass Criteria 001-1
		cout << "[Pass Criteria 001-1] Check the size of input storage" << endl;
		int size = storage->size();
		if (size != 1) {
			cout << "[Pass Criteria 001-1] size of the storage is incorrect : " << size << endl;
			FAIL();
		}
		else { PASS(); }

		// Pass Criteria 001-2
		cout << "[Pass Criteria 001-2] Check the out value if it is equal to min value" << endl;
		int out_value = storage->at(0);
		if (out_value != in_value) {
			cout << "[Pass Criteria 001-2] value is not matched : " << out_value << endl;
			FAIL();
		}
		else { PASS(); }
	}

	cout << endl;

	{
		// Test Step 002
		int in_value = 0;
		string in_value_str = to_string(in_value);
		cout << "[Test Step 002] Input a value : " << in_value_str << endl;
		actDivider.read_input_data(in_value_str);

		// Pass Criteria 002-1
		cout << "[Pass Criteria 002-1] Check the size of input storage" << endl;
		int size = storage->size();
		if (size != 2) {
			cout << "[Pass Criteria 002-1] size of the storage is incorrect : " << size << endl;
			FAIL();
		}
		else { PASS(); }

		// Pass Criteria 002-2
		cout << "[Pass Criteria 002-2] Check the out value if it is equal to 0" << endl;
		int out_value = storage->at(1);
		if (out_value != in_value) {
			cout << "[Pass Criteria 002-2] value is not matched : " << out_value << endl;
			FAIL();
		}
		else { PASS(); }
	}

	cout << endl;

	{
		// Test Step 003
		int in_value = numeric_limits<int>::max();
		string in_value_str = to_string(in_value);
		cout << "[Test Step 003] Input a value : " << in_value_str << endl;
		actDivider.read_input_data(in_value_str);

		// Pass Criteria 003-1
		cout << "[Pass Criteria 003-1] Check the size of input storage" << endl;
		int size = storage->size();
		if (size != 3) {
			cout << "[Pass Criteria 003-1] size of the storage is incorrect : " << size << endl;
			FAIL();
		}
		else { PASS(); }

		// Pass Criteria 003-2
		cout << "[Pass Criteria 003-2] Check the out value if it is equal to max value" << endl;
		int out_value = storage->at(2);
		if (out_value != in_value) {
			cout << "[Pass Criteria 002-2] value is not matched : " << out_value << endl;
			FAIL();
		}
		else { PASS(); }
	}

	cout << endl;
}

/**
 * @brief Testing read_input_data() of Divider
 * @details Check the scope of integer which is entered as input data\n
 *          This test is outside scope of integer including 'greater than max' and 'less than min'\n
 *
 *          - Test Step 001 : Input max + 1\n
 *          -- Pass Criteria 001 : The method should return RES_ERR_OUT_OF_RANGE\n
 *          - Test Step 002 : Input min - 1\n
 *          -- Pass Criteria 002 : The method should return RES_ERR_OUT_OF_RANGE\n
 */
void UnitTest::TEST_DIVIDER_002(void) {
	cout << "########################################" << endl;
	cout << "###        TEST_DIVIDER_002          ###" << endl;
	cout << "########################################" << endl;

	CResult res;
	Divider<int> actDivider;

	{
		// Test Step 001
		long in_value = static_cast<long>(numeric_limits<int>::max()) + 1;
		string in_value_str = to_string(in_value);
		cout << "[Test Step 001] Input a value : " << in_value_str << endl;
		res = actDivider.read_input_data(in_value_str);

		// Pass Criteria 001
		cout << "[Pass Criteria 001] Check if the function returned RES_ERR_OUT_OF_RANGE" << endl;
		if (res != RES_ERR_OUT_OF_RANGE) {
			cout << "Wrong return value from read_input_data : " << res << endl;
			FAIL();
		}
		else { PASS(); }
	}

	cout << endl;

	{
		// Test Step 002 - input value is min - 1
		long in_value = static_cast<long>(numeric_limits<int>::min()) - 1;
		string in_value_str = to_string(in_value);
		cout << "[Test Step 002] Input a value : " << in_value_str << endl;
		res = actDivider.read_input_data(in_value_str);

		// Pass Criteria 002 : read_input_data should return RES_ERR_OUT_OF_RANGE
		cout << "[Pass Criteria 002] Check if the function returned RES_ERR_OUT_OF_RANGE" << endl;
		if (res != RES_ERR_OUT_OF_RANGE) {
			cout << "Wrong return value from read_input_data : " << res << endl;
			FAIL();
		}
		else { PASS(); }
	}

	cout << endl;
}

/**
 * @brief Testing read_input_data() of Divider
 * @details Check if this method read the input data correctly from files\n
 *          \n
 *
 *          - Test Step 001 : Input data from one file, input1.txt\n
 *          -- Pass Criteria 001 : The input storage has same contents compared to the file\n
 *          - Test Step 002 : Input data from two files, input1.txt and input2.txt\n
 *          -- Pass Criteria 002-1 : The input storage has same contents compared to input1.txt\n
 *          -- Pass Criteria 002-2 : The input storage has same contents compared to input2.txt\n
 */
void UnitTest::TEST_DIVIDER_003(void) {
	cout << "########################################" << endl;
	cout << "###        TEST_DIVIDER_003          ###" << endl;
	cout << "########################################" << endl;

	{
		// Test Step 001
		cout << "[Test Step 001] Input data by file, input1.txt" << endl;

		Divider<int> actDivider1;
		vector<int>* storage1 = actDivider1.get_input_storage();
		string param = "input1";
		actDivider1.read_input_data(param);

		// Pass Criteria 001
		fstream data_file("input1.txt", std::ios_base::in);

		int in_data = 0;
		int out_data = 0;
		int cnt = 0;
		cout << "[Pass Criteria 001] Check if the out data is equal to in data from file" << endl;
		while(data_file >> in_data) {
			out_data = storage1->at(cnt++);
			cout << "in_data : " << in_data << ", out_data : " << out_data << endl;
			if (in_data != out_data) {
				cout << "Not the same value" << endl;
				FAIL();
			}
		}
		PASS();
	}

	cout << endl;

	{
		// Test Step 002
		cout << "[Test Step 002] Input data by file, input1.txt and input2.txt" << endl;

		Divider<int> actDivider2;
		vector<int>* storage2 = actDivider2.get_input_storage();
		string param = "input1";
		actDivider2.read_input_data(param);
		param = "input2";
		actDivider2.read_input_data(param);

		// Pass Criteria 002
		fstream data_file1("input1.txt", std::ios_base::in);
		fstream data_file2("input2.txt", std::ios_base::in);

		int in_data = 0;
		int out_data = 0;
		int cnt = 0;
		cout << "[Pass Criteria 002-1] Check if the out data is equal to in data from input1.txt" << endl;
		while(data_file1 >> in_data) {
			out_data = storage2->at(cnt++);
			cout << "in_data : " << in_data << ", out_data : " << out_data << endl;
			if (in_data != out_data) {
				cout << "Not the same value" << endl;
				FAIL();
			}
		}
		cout << "[Pass Criteria 002-2] Check if the out data is equal to in data from input2.txt" << endl;
		while(data_file2 >> in_data) {
			out_data = storage2->at(cnt++);
			cout << "in_data : " << in_data << ", out_data : " << out_data << endl;
			if (in_data != out_data) {
				cout << "Not the same value" << endl;
				FAIL();
			}
		}
		PASS();
	}

	cout << endl;
}

/**
 * @brief Testing read_input_data() of Divider
 * @details Check if this method operates correctly when the file has non-number\n
 *          \n
 *
 *          - Test Step 001 : Input data by file which contains alphabet\n
 *          -- Pass Criteria 001-1 : The size of input storage should be 2\n
 *          -- Pass Criteria 001-2 : The out data should be equal to in data from file\n
 *          - Test Step 002 : Input data by file which contains symbol\n
 *          -- Pass Criteria 002-1 : The size of input storage should be 3\n
 *          -- Pass Criteria 002-2 : The out data should be equal to in data from file\n
 */
void UnitTest::TEST_DIVIDER_004(void) {
	cout << "########################################" << endl;
	cout << "###        TEST_DIVIDER_004          ###" << endl;
	cout << "########################################" << endl;

	{
		// Test Step 001
		cout << "[Test Step 001] Input data by file, non_number_included_alphabet.txt" << endl;
		Divider<int> actDivider1;
		vector<int>* storage1 = actDivider1.get_input_storage();
		string param = "non_number_included_alphabet";
		actDivider1.read_input_data(param);

		// Pass Criteria 001-1
		cout << "[Pass Criteria 001-1] Check if the size of the storage is 2 because the function terminates to save once it meets non-number" << endl;
		int size = storage1->size();
		if (size != 2) {
			cout << "Size of the storage is incorrect : " << size << endl;
			FAIL();
		}
		else { PASS(); }

		// Pass Criteria 001-2
		fstream data_file("non_number_included_alphabet.txt", std::ios_base::in);
		int in_data = 0;
		int out_data = 0;
		int cnt = 0;
		cout << "[Pass Criteria 001-2] Check if the out data is equal to in data from file" << endl;
		while(data_file >> in_data) {
			out_data = storage1->at(cnt++);
			cout << "in_data : " << in_data << ", out_data : " << out_data << endl;
			if (in_data != out_data) {
				cout << "Not the same value" << endl;
				FAIL();
			}
		}
		PASS();
	}

	cout << endl;

	{
		// Test Step 002
		cout << "[Test Step 002] Input data by file, non_number_included_symbol.txt" << endl;
		Divider<int> actDivider2;
		vector<int>* storage2 = actDivider2.get_input_storage();
		string param = "non_number_included_symbol";
		actDivider2.read_input_data(param);

		// Pass Criteria 002-1
		cout << "[Pass Criteria 002-1] Check if the size of the storage is 3 because the function terminates to save once it meets non-number" << endl;
		int size = storage2->size();
		if (size != 3) {
			cout << "Size of the storage is incorrect : " << size << endl;
			FAIL();
		}
		else { PASS(); }

		// Pass Criteria 002-2
		cout << "[Pass Criteria 002-2] Check if the out data is equal to in data from file" << endl;
		fstream data_file("non_number_included_symbol.txt", std::ios_base::in);
		int in_data = 0;
		int out_data = 0;
		int cnt = 0;
		while(data_file >> in_data) {
			out_data = storage2->at(cnt++);
			cout << "in_data : " << in_data << ", out_data : " << out_data << endl;
			if (in_data != out_data) {
				cout << "Not the same value" << endl;
				FAIL();
			}
		}
		PASS();
	}

	cout << endl;
}

/**
 * @brief Testing read_input_data() of Divider
 * @details In case of the empty file, there should be no numbers in the input storage\n
 *          \n
 *
 *          - Test Step 001 : Input data by file which is empty\n
 *          -- Pass Criteria 001 : The size of input storage should be 0\n
 */
void UnitTest::TEST_DIVIDER_005(void) {
	cout << "########################################" << endl;
	cout << "###        TEST_DIVIDER_005          ###" << endl;
	cout << "########################################" << endl;

	CResult res;
	Divider<int> actDivider;
	vector<int>* storage = actDivider.get_input_storage();

	{
		// Test Step 001
		cout << "[Test Step 001] Input data by file which is empty" << endl;
		string param = "empty_file";
		res = actDivider.read_input_data(param);

		// Pass Criteria 001
		cout << "[Pass Criteria 001] Check if the size of the storage is zero" << endl;
		int size = storage->size();
		if (size != 0) {
			cout << "Wrong size of the file : " << size << endl;
			FAIL();
		}
		else { PASS(); }
	}

	cout << endl;
}

/**
 * @brief Testing read_input_data() of Divider
 * @details In case that there are no file to open, this method should return error\n
 *          \n
 *
 *          - Test Step 001 : Input data by file which doesn't exist\n
 *          -- Pass Criteria 001 : RES_ERR_FILE_NOT_EXIST should be returned\n
 */
void UnitTest::TEST_DIVIDER_006(void) {
	cout << "########################################" << endl;
	cout << "###        TEST_DIVIDER_006          ###" << endl;
	cout << "########################################" << endl;

	CResult res;
	Divider<int> actDivider;
	vector<int>* storage = actDivider.get_input_storage();

	{
		// Test Step 001
		cout << "[Test Step 001] Input data by file which doesn't exist" << endl;
		string param = "not_existed";
		res = actDivider.read_input_data(param);

		// Pass Criteria 001
		cout << "[Pass Criteria 001] Check if the function returned RES_ERR_FILE_NOT_EXIST" << endl;
		if (res != RES_ERR_FILE_NOT_EXIST) {
			cout << "Wrong return value from read_input_data : " << res << endl;
			FAIL();
		}
		else { PASS(); }
	}

	cout << endl;
}

/**
 * @brief Testing read_input_data() of Divider
 * @details In case that input parameter is blank, this method should return error\n
 *          \n
 *
 *          - Test Step 001 : Input param is blank\n
 *          -- Pass Criteria 001 : RES_ERR_INVALID_PARAM should be returned\n
 */
void UnitTest::TEST_DIVIDER_007(void) {
	cout << "########################################" << endl;
	cout << "###        TEST_DIVIDER_007          ###" << endl;
	cout << "########################################" << endl;

	CResult res;
	Divider<int> actDivider;
	vector<int>* storage = actDivider.get_input_storage();

	{
		// Test Step 001
		cout << "[Test Step 001] Input param is blank" << endl;
		string param = "";
		res = actDivider.read_input_data(param);

		// Pass Criteria 001
		cout << "[Pass Criteria 001] Check if the function returned RES_ERR_INVALID_PARAM" << endl;
		if (res != RES_ERR_INVALID_PARAM) {
			cout << "Wrong return value from read_input_data : " << res << endl;
			FAIL();
		}
		else { PASS(); }
	}

	cout << endl;
}

/**
 * @brief Testing calculate() of Divider
 * @details In case that the number of integers is wrong, this method should return error\n
 *          \n
 *
 *          - Test Step 001 : Calculate when the size of the input storage is 0\n
 *          -- Pass Criteria 001 : RES_ERR_SIZE should be returned\n
 *          - Test Step 002 : Calculate when the size of the input storage is less than 2\n
 *          -- Pass Criteria 002-1 : The size of the input storage should be 1\n
 *          -- Pass Criteria 002-2 : RES_ERR_SIZE should be returned\n
 *          - Test Step 003 : Calculate when the size of the input storage is not even\n
 *          -- Pass Criteria 003-1 : The size of the input storage should be 3\n
 *          -- Pass Criteria 003-2 : RES_ERR_SIZE should be returned\n
 */
void UnitTest::TEST_DIVIDER_008(void) {
	cout << "########################################" << endl;
	cout << "###        TEST_DIVIDER_008          ###" << endl;
	cout << "########################################" << endl;

	CResult res;
	Divider<int> actDivider;
	vector<int>* storage = actDivider.get_input_storage();

	{
		// Test Step 001
		cout << "[Test Step 001] Calculate when the storage is empty" << endl;
		res = actDivider.calculate();

		// Pass Criteria 001
		cout << "[Pass Criteria 001] Check if the function returned RES_ERR_SIZE" << endl;
		if (res != RES_ERR_SIZE) {
			cout << "Wrong return value from calculate : " << res << endl;
			FAIL();
		}
		else { PASS(); }
	}

	cout << endl;

	{
		// Test Step 002
		cout << "[Test Step 002] Calculate when the size of the storage is less than 2" << endl;
		int in_value = 1234;
		string in_value_str = to_string(in_value);
		actDivider.read_input_data(in_value_str);
		res = actDivider.calculate();

		// Pass Criteria 002
		cout << "Pass Criteria 002-1] Check if the size of the storage is 1" << endl;
		int size = storage->size();
		if (size != 1) {
			cout << "Wrong size of the storage : " << size << endl;
			FAIL();
		}
		else { PASS(); }

		cout << "[Pass Criteria 002-2] Check if the function returned RES_ERR_SIZE" << endl;
		if (res != RES_ERR_SIZE) {
			cout << "Wrong return value from calculate : " << res << endl;
			FAIL();
		}
		else { PASS(); }
	}

	cout << endl;

	{
		// Test Step 003
		cout << "[Test Step 003] Calculate when the size of the storage is not even" << endl;
		int in_value = 1234;
		string in_value_str = to_string(in_value);
		actDivider.read_input_data(in_value_str);
		in_value = 3456;
		in_value_str = to_string(in_value);
		actDivider.read_input_data(in_value_str);
		res = actDivider.calculate();

		// Pass Criteria 003
		cout << "Pass Criteria 003-1] Check if the size of the storage is 3" << endl;
		int size = storage->size();
		if (size != 3) {
			cout << "Wrong size of the storage : " << size << endl;
			FAIL();
		}
		else { PASS(); }

		cout << "[Pass Criteria 003-2] Check if the function returned RES_ERR_SIZE" << endl;
		if (res != RES_ERR_SIZE) {
			cout << "Wrong return value from calculate : " << res << endl;
			FAIL();
		}
		else { PASS(); }
	}

	cout << endl;
}

/**
 * @brief Testing calculate() of Divider
 * @details In case that the number of integers is even, this method should operate correctly\n
 *          \n
 *
 *          - Test Step 001 : Calculate m/n (m=0, n=non-zero)\n
 *          -- Pass Criteria 001 : The result should be 0\n
 *          - Test Step 002 : Calculate m/n (m=greater than 0, n=greater than 0)\n
 *          -- Pass Criteria 002 : The result should be in tolerance\n
 *          - Test Step 003 : Calculate m/n (m=less than 0, n=greater than 0)\n
 *          -- Pass Criteria 003 : The result should be in tolerance\n
 *          - Test Step 004 : Calculate m/n (m=greater than 0, n=less than 0)\n
 *          -- Pass Criteria 004 : The result should be in tolerance\n
 *          - Test Step 005 : Calculate m/n (m=less than 0, n=less than 0)\n
 *          -- Pass Criteria 005 : The result should be in tolerance\n
 */
void UnitTest::TEST_DIVIDER_009(void) {
	cout << "########################################" << endl;
	cout << "###        TEST_DIVIDER_009          ###" << endl;
	cout << "########################################" << endl;

	{
		// Test Step 001
		cout << "[Test Step 001] Calculate m/n (m=0, n=non-zero)" << endl;
		Divider<int> actDivider;
		vector<int>* input_storage = actDivider.get_input_storage();
		vector<float>* result_storage = actDivider.get_result();
		int in_value = 0;
		cout << "m = " << in_value << endl;
		string in_value_str = to_string(in_value);
		actDivider.read_input_data(in_value_str);
		in_value = 25;
		cout << "n = " << in_value << endl;
		in_value_str = to_string(in_value);
		actDivider.read_input_data(in_value_str);
		actDivider.calculate();

		// Pass Criteria 001
		cout << "[Pass Criteria 001] Check if the result is zero" << endl;
		float result = result_storage->at(0);
		if (result > TOLERANCE) {
			cout << "Wrong calculation result " << result << endl;
			FAIL();
		}
		else { PASS(); }
	}

	cout << endl;

	{
		// Test Step 002
		cout << "[Test Step 002] Calculate m/n (m=greater than 0, n=greater than 0)" << endl;
		Divider<int> actDivider;
		vector<int>* input_storage = actDivider.get_input_storage();
		vector<float>* result_storage = actDivider.get_result();
		int in_value1 = 5;
		cout << "m = " << in_value1 << endl;
		string in_value_str = to_string(in_value1);
		actDivider.read_input_data(in_value_str);
		int in_value2 = 8;
		cout << "m = " << in_value2 << endl;
		in_value_str = to_string(in_value2);
		actDivider.read_input_data(in_value_str);
		actDivider.calculate();

		// Pass Criteria 002
		cout << "[Pass Criteria 002] Check if the result is in tolerance" << endl;
		float result_calculated = result_storage->at(0);
		float result_expected = in_value1 / static_cast<float>(in_value2);
		cout << "calculated result = " << result_calculated << endl;
		cout << "expected result = " << result_expected << endl;
		if (fabs(result_calculated - result_expected) > TOLERANCE) {
			cout << "Wrong calculation result" << endl;
			FAIL();
		}
		else { PASS(); }
	}

	cout << endl;

	{
		// Test Step 003
		cout << "[Test Step 003] Calculate m/n (m=less than 0, n=greater than 0)" << endl;
		Divider<int> actDivider;
		vector<int>* input_storage = actDivider.get_input_storage();
		vector<float>* result_storage = actDivider.get_result();
		int in_value1 = -5;
		cout << "m = " << in_value1 << endl;
		string in_value_str = to_string(in_value1);
		actDivider.read_input_data(in_value_str);
		int in_value2 = 8;
		cout << "m = " << in_value2 << endl;
		in_value_str = to_string(in_value2);
		actDivider.read_input_data(in_value_str);
		actDivider.calculate();

		// Pass Criteria 003
		cout << "[Pass Criteria 003] Check if the result is in tolerance" << endl;
		float result_calculated = result_storage->at(0);
		float result_expected = in_value1 / static_cast<float>(in_value2);
		cout << "calculated result = " << result_calculated << endl;
		cout << "expected result = " << result_expected << endl;
		if (fabs(result_calculated - result_expected) > TOLERANCE) {
			cout << "Wrong calculation result" << endl;
			FAIL();
		}
		else { PASS(); }
	}

	cout << endl;

	{
		// Test Step 004
		cout << "[Test Step 004] Calculate m/n (m=greater than 0, n=less than 0)" << endl;
		Divider<int> actDivider;
		vector<int>* input_storage = actDivider.get_input_storage();
		vector<float>* result_storage = actDivider.get_result();
		int in_value1 = 5;
		cout << "m = " << in_value1 << endl;
		string in_value_str = to_string(in_value1);
		actDivider.read_input_data(in_value_str);
		int in_value2 = -8;
		cout << "m = " << in_value2 << endl;
		in_value_str = to_string(in_value2);
		actDivider.read_input_data(in_value_str);
		actDivider.calculate();

		// Pass Criteria 004
		cout << "[Pass Criteria 004] Check if the result is in tolerance" << endl;
		float result_calculated = result_storage->at(0);
		float result_expected = in_value1 / static_cast<float>(in_value2);
		cout << "calculated result = " << result_calculated << endl;
		cout << "expected result = " << result_expected << endl;
		if (fabs(result_calculated - result_expected) > TOLERANCE) {
			cout << "Wrong calculation result" << endl;
			FAIL();
		}
		else { PASS(); }
	}

	cout << endl;

	{
		// Test Step 005
		cout << "[Test Step 005] Calculate m/n (m=less than 0, n=less than 0)" << endl;
		Divider<int> actDivider;
		vector<int>* input_storage = actDivider.get_input_storage();
		vector<float>* result_storage = actDivider.get_result();
		int in_value1 = -5;
		cout << "m = " << in_value1 << endl;
		string in_value_str = to_string(in_value1);
		actDivider.read_input_data(in_value_str);
		int in_value2 = -8;
		cout << "m = " << in_value2 << endl;
		in_value_str = to_string(in_value2);
		actDivider.read_input_data(in_value_str);
		actDivider.calculate();

		// Pass Criteria 005
		cout << "[Pass Criteria 005] Check if the result is in tolerance" << endl;
		float result_calculated = result_storage->at(0);
		float result_expected = in_value1 / static_cast<float>(in_value2);
		cout << "calculated result = " << result_calculated << endl;
		cout << "expected result = " << result_expected << endl;
		if (fabs(result_calculated - result_expected) > TOLERANCE) {
			cout << "Wrong calculation result" << endl;
			FAIL();
		}
		else { PASS(); }
	}

	cout << endl;
}

/**
 * @brief Testing calculate() of Divider
 * @details In case of divide by zero, this method should make the result zero\n
 *          \n
 *
 *          - Test Step 001 : Calculate in case of divide by zero\n
 *          -- Pass Criteria 001 : The result should be 0\n
 */
void UnitTest::TEST_DIVIDER_010(void) {
	cout << "########################################" << endl;
	cout << "###        TEST_DIVIDER_010          ###" << endl;
	cout << "########################################" << endl;

	{
		// Test Step 001
		cout << "[Test Step 001] Calculate in case of divide by zero" << endl;
		Divider<int> actDivider;
		vector<int>* input_storage = actDivider.get_input_storage();
		vector<float>* result_storage = actDivider.get_result();
		int in_value = 25;
		cout << "m = " << in_value << endl;
		string in_value_str = to_string(in_value);
		actDivider.read_input_data(in_value_str);
		in_value = 0;
		cout << "n = " << in_value << endl;
		in_value_str = to_string(in_value);
		actDivider.read_input_data(in_value_str);
		actDivider.calculate();

		// Pass Criteria 001
		cout << "[Pass Criteria 001] Check if the result is zero because the function forces the result to zero in case of divide by zero " << endl;
		float result = result_storage->at(0);
		if (static_cast<int>(result) != 0) {
			cout << "Wrong calculation result" << result << endl;
			FAIL();
		}
		else { PASS(); }
	}
}

