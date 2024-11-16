/**
 * @file CalculationEngine.h
 * @author joohjo
 */

#ifndef CALCULATIONENGINE_H_
#define CALCULATIONENGINE_H_

#include <vector>
#include <string>

/**
 * @brief Return value of CalculationEngine
 */
typedef enum {
	RES_OK = 0,				/**< No Error **/
	RES_ERR,				/**< General Error **/
	RES_ERR_NOT_SUPPORT,	/**< Not support functionalities (e.g. wrong data type) **/
	RES_ERR_FILE_NOT_EXIST,	/**< There are no files to open **/
	RES_ERR_OUT_OF_RANGE,	/**< The value exceed its range **/
	RES_ERR_SIZE,			/**< Size Error (e.g not enough to calculate) **/
	RES_ERR_INVALID_PARAM,	/**< Invalid parameter was given**/

	RES_MAX
} CResult;

/**
 * @brief Calculation type
 */
typedef enum  {
	MULTIPLICATION = 0,		/**< Calculator for multiplication **/
	DIVISION				/**< Calculator for division **/
} Calculation;

/**
 * @brief Allowable input type
 */
typedef enum  {
	INTEGER = 0,			/**< Integer (-2,147,483,648 ~ 2,147,483,647) **/
} InputType;

using namespace std;

/**
 * @brief CalculationEngine Class
 * @details This class is abstraction class to provide the factory method and virtual functions should be implemented by sub class
 */
class CalculationEngine
{
public:
	/**
	 * @brief Destructor of CalculationEngine Class
	 */
	virtual ~CalculationEngine() {}

	static CalculationEngine *generateCalculator(Calculation cal_t, InputType input_t);

	/**
	 * @brief virtual method to read input data
	 */
	virtual CResult read_input_data(std::string &param) = 0;

	/**
	 * @brief virtual method to calculate
	 */
	virtual CResult calculate() = 0;

	/**
	 * @brief virtual method to display result
	 */
	virtual void display_result() = 0;
};

/**
 * @brief Multiplier Class
 * @details This class is for calculation of multiplication
 */
template <class T1, class T2>
class Multiplier : public CalculationEngine
{
public:
	Multiplier();
	~Multiplier();

	virtual CResult read_input_data(std::string &param);
	virtual CResult calculate();

	/**
	 * @brief Display the results of Multiplier to stdout
	 */
	virtual void display_result() {
		for (unsigned int i = 0; i < m_input_storage->size(); i++) {
			cout << "*" << m_input_storage->at(i);
		}
		cout << endl << *m_result << endl;
	}

	/**
	 * @brief Get the result of Multiplier
	 * @retval T2* the pointer of result value
	 */
	T2* get_result() { return m_result; }

private:
	std::vector<T1>* m_input_storage;
	T2* m_result;
};

/**
 * @brief Divider Class
 * @details This class is for calculation of division
 */
template <class T>
class Divider : public CalculationEngine
{
public:
	Divider();
	~Divider();

	virtual CResult read_input_data(std::string &param);
	virtual CResult calculate();

	/**
	 * @brief Display the results of Multiplier to stdout
	 * @details An example of display in stsdout is like below
	 *          5/10=0.5
	 *          4/2=2
	 *          ...
	 */
	virtual void display_result() {
		for (unsigned int i=0, j=0; i<m_input_storage->size(); i=i+2, j++)
			cout << m_input_storage->at(i) << "/" << m_input_storage->at(i+1) << "=" << m_result->at(j) << endl;
	}

	/**
	 * @brief Get the input data storage
	 * @retval std::vector<T>* The pointer of the input data storage
	 */
	std::vector<T>* get_input_storage() { return m_input_storage; }

	/**
	 * @brief Get the result of Divider
	 * @retval std::vector<float>* the pointer of result value (vector)
	 */
	std::vector<float>* get_result() { return m_result; }

private:
	std::vector<T>* m_input_storage;
	std::vector<float>* m_result;
};

#endif /* CALCULATIONENGINE_H_ */
