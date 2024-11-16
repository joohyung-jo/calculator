/**
 * @file CalculationEngine.cpp
 * @author joohjo
 */

#include <iostream>
#include <fstream>
#include <limits>

#include "CalculationEngine.h"

#define INPUT_FILE_EXT ".txt"

using namespace std;

/**
 * @brief Check if the input is Number or String
 * @param[in] s The input parameter represents Integer or File name
 * @retval true Integer
 * @retval false File name
 */
inline bool isNumber(string s)
{
	// first can be +, - and digit
	if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
		return false;

    for (unsigned long i = 1; i < s.length(); i++) {
		if (isdigit(s[i]) == false)
			return false;
    }

    return true;
}

/**
 * @brief Constructor of Multiplier
 * @details Type of the member variables are decided by the factory method of CalculationEngine class.\n
 *          In the constructor member variables are initialized.
 */
template <class T1, class T2>
Multiplier<T1,T2>::Multiplier() {
	m_input_storage = new std::vector<T1>;
	m_result = new T2;

	m_input_storage->clear();
	*m_result = 0;
}

/**
 * @brief Destructor of Multiplier
 * @details Free member variables
 */
template <class T1, class T2>
Multiplier<T1,T2>::~Multiplier() {
	delete m_input_storage;
	delete m_result;
}

/**
 * @brief Read the input data and save numbers to the storage
 * @param[in] param Input data which represents only file name
 * @retval CResult the operation result of the method
 */
template <class T1, class T2>
CResult Multiplier<T1,T2>::read_input_data(std::string &param) {
	T1 in_data = 0;

	// check if param is integer
	if (true == isNumber(param))
		return RES_ERR_NOT_SUPPORT;

	string file_name = param + INPUT_FILE_EXT;

	// open file
	fstream data_file(file_name.c_str(), std::ios_base::in);
	if (!data_file.is_open())
		return RES_ERR_FILE_NOT_EXIST;

	// put the input data to the storage
	while(data_file >> in_data) {
		m_input_storage->push_back(in_data);
	}

	return RES_OK;
}

/**
 * @brief Calculate from the input storage
 * @details All the numbers in the input storage will be multiplied\n
 *          This method makes one result value
 * @retval CResult the operation result of the method
 */
template <class T1, class T2>
CResult Multiplier<T1,T2>::calculate() {
	T2 tmp = 1;

	for (unsigned int i = 0; i < m_input_storage->size(); i++) {
		tmp = tmp * m_input_storage->at(i);
		// check max/min value of T2
		if (tmp > numeric_limits<T2>::max() || tmp < numeric_limits<T2>::min())
			return RES_ERR_OUT_OF_RANGE;
	}

	*m_result = tmp;

	return RES_OK;
}

/**
 * @brief Constructor of Divider
 * @details Type of the member variables are decided by the factory method of CalculationEngine class\n
 *          In the constructor member variables are initialized.
 */
template <class T>
Divider<T>::Divider() {
	m_input_storage = new std::vector<T>;
	m_result = new std::vector<float>;

	m_input_storage->clear();
	m_result->clear();
}

/**
 * @brief Destructor of Divider
 * @details Free member variables
 */
template <class T>
Divider<T>::~Divider() {
	delete m_input_storage;
	delete m_result;
}

/**
 * @brief Read the input data and save numbers to the storage
 * @details This is the template specialization for integer\n
 *          If you use other types(e.g. float), you should implement new method for the new type(e.g. Divider<float>::read_input_data())
 * @param[in] param Input data which represents integer or file name
 * @retval CResult the operation result of the method
 */
template <>
CResult Divider<int>::read_input_data(std::string &param) {
	int in_data = 0;

	// check if param is number or file
	if (true == isNumber(param)) {
		try {
			in_data = stoi(param);
		} catch (const out_of_range& oor) {
			return RES_ERR_OUT_OF_RANGE;
		}

		m_input_storage->push_back(in_data);
	}
	else {
		if (param.size() == 0)
			return RES_ERR_INVALID_PARAM;

		string file_name = param + INPUT_FILE_EXT;

		// open file
		fstream data_file(file_name.c_str(), std::ios_base::in);
		if (!data_file.is_open())
			return RES_ERR_FILE_NOT_EXIST;

		// put the input data to the storage
		while(data_file >> in_data) {
			//cout << "in_data : " << in_data << endl;
			if((in_data > numeric_limits<int>::max()) || (in_data < numeric_limits<int>::min()))
				return RES_ERR_OUT_OF_RANGE;

			m_input_storage->push_back(in_data);
		}
	}

	return RES_OK;
}

/**
 * @brief Calculate from the input storage
 * @details All the numbers in the input storage will be divided one after another\n
 *          This method makes result values and stores it to the output storage\n
 *          For instance, if there are 4, 5, 6 and 7 in the input storage then Divider calculates like mentioned below\n
 *          - div1 = 4/5
 *          - div2 = 6/7
 *
 * @retval CResult the operation result of the method
 * @endcode
 */
template <class T>
CResult Divider<T>::calculate() {
	float res = 0.0f;

	// check if the size of storage
	if (m_input_storage->empty() || ((m_input_storage->size() % 2) != 0))
		return RES_ERR_SIZE;

	for (unsigned int i = 0; i < m_input_storage->size(); i=i+2) {
		if (m_input_storage->at(i+1) == 0) {
			// In case of divide by zero, make the result zero
			m_result->push_back(0);
			continue;
		}
		else {
			res = m_input_storage->at(i) / static_cast<float>(m_input_storage->at(i+1));
			m_result->push_back(res);
		}
	}

	return RES_OK;
}

/**
 * @brief Factory method to generate Calculator Engine
 * @details For calcuation, mulitiplication and division are supported.
 *          Only integer is supported for now.
 * @param[in] cal_t The type of calcuation
 * @param[in] input_type allowable input type
 *
 * @code
 *	// For instance
 *	CalculationEngine *actMultiplier = CalculationEngine::generateCalculator(MULTIPLICATION, INTEGER);
 *	CalculationEngine *actDivider = CalculationEngine::generateCalculator(DIVISION, INTEGER);
 * @endcode
 */
CalculationEngine* CalculationEngine::generateCalculator(Calculation cal_t, InputType input_type) {
	if (cal_t == MULTIPLICATION) {
		if (input_type == INTEGER)
			return new Multiplier<int,long long>;
	}
	else if (cal_t == DIVISION)
		if (input_type == INTEGER)
			return new Divider<int>;

	return NULL;
}
