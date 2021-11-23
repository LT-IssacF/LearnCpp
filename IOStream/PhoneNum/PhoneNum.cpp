#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
struct PersonInfo {
	string name;
	vector<string> phones;
};
vector<PersonInfo> people;

int main( ) {
	string line, number;
	ifstream input( "input.txt" ); // 文件读取流打开文件
	while( getline( input, line ) ) { // 一行一行地从流读入string中
		PersonInfo temp;
		// 字符串读取流需要绑定对象
		istringstream record( line );
		// 字符串读取流以空格为分隔，可以挨个挨个读取
		record >> temp.name;
		while( record >> number )
			temp.phones.push_back( number );
		people.push_back( temp );
	}
	for( const auto &it : people ) { // const PersonInfo &it
		ostringstream valid, invalid; // 字符串写入流不绑定对象
		for( const auto &calls : it.phones ) { // 底层const只改变引用对象，不改变对象内容
			if( calls != "00000" ) // 根据条件判断分别写入各自的字符串流
				valid << " " << calls;
			else
				invalid << " " << "$" + calls;
		}
		if( invalid.str( ).empty( ) ) // 没有错误的号码
			cout << it.name << valid.str( ) << endl; // 字符串写入流的内容需要用其成员函数调用
		else
			cerr << it.name << "'s error is" << invalid.str( )
			<< " and" << valid.str( ) << " is still valid!" << endl;
	}
	return 0;
}
