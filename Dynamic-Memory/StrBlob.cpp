#include <memory>
#include <string>
#include <vector>
#include <initializer_list>
#include <stdexcept>
#include "StrBlob.h"

int main( ) {
	StrBlob p1; // p1有一块单独的内存保存其vector
	{
		StrBlob p2{ "a", "an", "the" }; // p2也有一块单独的内存保存其vector
		p1 = p2; // p1共享了p2的vector，所以他们的shared_ptr的引用计数器为2
		p2.push_back( "about" );
	}
	return 0;
}
