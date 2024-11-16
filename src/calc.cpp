/**
 * @file calc.cpp
 * @author joohjo
 */

#include <string.h>
#include <iostream>
#include <typeinfo>

#include "CalculationEngine.h"
#include "utest.h"

using namespace std;


int main(int argc, char* argv[]) {
	CResult res = RES_OK;

	// Multiplier
	if(!strcmp(argv[1], "Multiplier")) {
		// check argc
		if (argc < 3) {
			cout << "[Multiplier][Error] Please input the file name" << endl;
			return -1;
		}

		CalculationEngine *actMultiplier = CalculationEngine::generateCalculator(MULTIPLICATION, INTEGER);

		// read input data
		for (int i=2; i<argc; i++) {
			string param(argv[i]);
			res = actMultiplier->read_input_data(param);
			if (res != RES_OK) {
				cout << "[Multiplier][Error] read_input_data : " << res << endl;
				return -1;
			}
		}

		// calculate
		res = actMultiplier->calculate();
		if (res != RES_OK) {
			cout << "[Multiplier][Error] calculate : " << res << endl;
			return -1;
		}

		// display result
		actMultiplier->display_result();
	}
	// Divider
	else if (!strcmp(argv[1], "Divider")) {
		// check argc
		if (argc < 3) {
			cout << "[Multiplier][Error] Please input the file name" << endl;
			return -1;
		}

		CalculationEngine *actDivider = CalculationEngine::generateCalculator(DIVISION, INTEGER);

		// read input data
		for (int i=2; i<argc; i++) {
			string param(argv[i]);
			res = actDivider->read_input_data(param);
			if (res != RES_OK) {
				cout << "[Divider][Error] read_input_data : " << res << endl;
				return -1;
			}
		}

		// calculate
		res = actDivider->calculate();
		if (res != RES_OK) {
			cout << "[Divider][Error] calculate : " << res << endl;
			return -1;
		}

		// display result
		actDivider->display_result();
	}
	// UnitTest
	else if (!strcmp(argv[1], "UnitTest")) {
		UnitTest ut;
		ut.TEST_DIVIDER_001();
		ut.TEST_DIVIDER_002();
		ut.TEST_DIVIDER_003();
		ut.TEST_DIVIDER_004();
		ut.TEST_DIVIDER_005();
		ut.TEST_DIVIDER_006();
		ut.TEST_DIVIDER_007();
		ut.TEST_DIVIDER_008();
		ut.TEST_DIVIDER_009();
		ut.TEST_DIVIDER_010();
	}
	else { /* nothing */}

	return 0;
}
