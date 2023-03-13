#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Sales_data {
	// 非成员函数的友元声明
	friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
	friend std::istream &read(std::istream &is, Sales_data &rhs);
	friend std::ostream &print(std::ostream &ou, const Sales_data &os);
public:
	Sales_data(const std::string &s, const unsigned int &cnt, const double &price);

	Sales_data();
	Sales_data(const std::string &s);

	Sales_data(const Sales_data &rhs);
	Sales_data &operator=(const Sales_data &rhs);

	Sales_data(Sales_data &&rhs) = default;
	Sales_data &operator=(Sales_data &&rhs) = default;

	Sales_data(std::istream &is);

	std::string isbn() const;

	Sales_data &combine(const Sales_data &rhs);

	double avg_price() const;
private:
	std::string bookNO;
	unsigned int units_sold;
	double revenue;
};
#endif
