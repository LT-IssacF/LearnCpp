#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
using namespace std;
// 建立转换规则即映射
// 参数为一个读取文件流
map<string, string> BuildMap( ifstream &map_file ) {
	map<string, string> trans_map;
	string key, value; // 键和值
	// 读取第一个单词存入key，行中剩余内容存入value
	while( map_file >> key && getline( map_file, value ) ) {
		if( value.size( ) > 1 ) // 跳过前导空格
			trans_map[key] = value.substr( 1 );
		else // 实际根据提供输入流的性质不会出现异常
			throw runtime_error( "no rule for " + key );
	}
	return trans_map;
}
// 实际的转换工作
// 参数为一个待转换的字符串即单词和转换规则
const string &Transform( const string &s, const map<string, string> &trans_map ) {
	auto map_it = trans_map.find( s );
	auto map_end = trans_map.cend( );
	if( map_it != map_end ) // 如果单词在转换规则中
		return map_it->second; // 返回替换短语
	else // 不在就原路返回
		return s;
}
// 参数为两个读取文件流，前者是转换规则，后者是待转换文本
void Word_Transform( ifstream &map_file, ifstream &input ) {
	auto trans_map = BuildMap( map_file );
	string text;
	while( getline( input, text ) ) { // 读入输入流每一行
		istringstream stream( text ); // 读取每一个单词
		string word;
		bool firstWord = true; // 控制单词之间的空格
		while( stream >> word ) {
			if( firstWord == true )
				firstWord = false;
			else
				cout << " ";
			cout << Transform( word, trans_map );
		}
		cout << endl; // 一行结束
	}
}

int main( ) {
	ifstream map_file( "map_file.txt" );
	ifstream input( "input.txt" );
	Word_Transform( map_file, input );
	return 0;
}