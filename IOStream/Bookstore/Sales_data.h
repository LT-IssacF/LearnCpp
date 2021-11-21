#include <string>
class Sales_data {
	// 非成员函数的友元声明
	friend Sales_data add( const Sales_data&, const Sales_data& );
	friend std::istream &read( std::istream&, Sales_data& );
	friend std::ostream &print( std::ostream&, const Sales_data& );
public:
	// 构造函数声明
	Sales_data( ) = default;
	// 构造函数初始值列表
	Sales_data( const std::string &s, unsigned n, double p ) :
		bookNo( s ), units_sold( n ), revenue( p * n ) {
	}
	Sales_data( std::istream& ); // 外部构造函数声明
	// 成员函数
	std::string isbn( ) const {
		return bookNo;
	}
	double avg_price( ) const;
	Sales_data &combine( const Sales_data& );
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
// 外部定义构造函数
Sales_data::Sales_data( std::istream &is ) {
	read( is, *this );
}
// 外部定义成员函数
double Sales_data::avg_price( ) const {
	if( units_sold )
		return revenue / units_sold;
	else
		return 0;
}
Sales_data& Sales_data::combine( const Sales_data &rhs ) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
// 接口声明
Sales_data add( const Sales_data&, const Sales_data& );
std::istream &read( std::istream&, Sales_data& );
std::ostream &print( std::ostream&, const Sales_data& );
