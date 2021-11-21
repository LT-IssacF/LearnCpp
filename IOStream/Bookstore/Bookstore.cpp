#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Sales_data.h"
using namespace std;

istream &read( istream &is, Sales_data &item ) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}
ostream &print( ostream &os, const Sales_data &item ) {
	os << item.isbn( ) << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price( );
	return os;
}
Sales_data add( const Sales_data &lhs, const Sales_data &rhs ) {
	Sales_data sum = lhs;
	sum.combine( rhs );
	return sum;
}

int main( ) {
	ifstream input( "input.txt" );
	ofstream output( "output.txt" ); // 隐式地截断文件
	Sales_data total; // 保存一本书的销售总额
	if( read( input, total ) ) { // 读取第一条销售记录
		Sales_data trans; // 保存下一本书的销售额
		while( read( input, trans ) ) { // 读取下一条销售记录
			if( total.isbn( ) == trans.isbn( ) ) // 是同一本书
				total.combine( trans );
			else { // 不是则打印上一本的结果
				print( output, total ) << endl;
				total = trans; // 开始处理下一本
			}
		}
		print( output, total ); // 处理最后一本
		cout << "Record done!" << endl;
	}
	else // 文件中没有数据
		cerr << "No data?!" << endl;
	return 0;
}
