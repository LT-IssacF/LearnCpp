#include <memory>
#include <string>
#include <vector>
#include <initializer_list>
#include <stdexcept>
class StrBlob {
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob( );
	StrBlob( std::initializer_list<std::string> il );
	// 这两种成员函数不需要改变元素，所以直接利用底层的vector的相对应成员来完成工作
	size_type size( ) const { return data->size( ); };
	bool empty( ) const { return data->empty( ); };
	// 需要添加或删除，但添加没有限制，所以也可以如上
	void push_back( const std::string &t ) { return data->push_back( t ); }
	void pop_back( );
	// 对元素进行访问，返回左值
	const std::string &front( ) const;
	const std::string &back( ) const;
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check( size_type i, const std::string &msg ) const;
};
// 无参初始化，分配一个空vector
StrBlob::StrBlob( ) : data( std::make_shared<std::vector<std::string>>( ) ) { };
// 用initializer_list初始化vector
StrBlob::StrBlob( std::initializer_list<std::string> il ) :
	data( std::make_shared<std::vector<std::string>>( il ) ) { };
void StrBlob::check( size_type i, const std::string &msg ) const {
	if( i >= data->size( ) )
		throw std::out_of_range( msg );
}
void StrBlob::pop_back( ) {
	check( 0, "pop_back on empty StrBlob" );
	data->pop_back( );
}
const std::string &StrBlob::front( ) const {
	check( 0, "front on empty StrBlob" );
	return data->front( );
}
const std::string &StrBlob::back( ) const {
	check( 0, "back on empty StrBlob" );
	return data->back( );
}
