#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <Sales_data.h>

int main() {
	std::ifstream is("../src/IOStream/Bookstore/input.txt");
	std::ofstream os("output.txt"); // 隐式截断文件
	//std::ofstream os("output.txt", std::ostream::out | std::ofstream::trunc); // 显示指定输出模式且截断文件
	//std::ofstream os("output.txt", std::ostream::out | std::ofstream::app); // 显示指定输出和追加
	Sales_data total; // 保存一本书的销售总额
	if(read(is, total)) { // 读取第一条销售记录
		Sales_data tmp; // 保存下一本书的销售额
		while(read(is, tmp)) { // 读取下一条销售记录
			if(tmp.isbn() == total.isbn()) { // 是同一本书
				total.combine(tmp);
			} else { // 不是则打印上一本的结果
				print(os, total);
				total = tmp; // 开始处理下一本
			}
		}
		is.close(); // 关闭输入流，以便可以用于其他文件
		print(os, total); // 处理最后一本
		os.close();
		is.open("output.txt"); // 将输出文件的数据打印到终端上
		std::string s;
		while(std::getline(is, s)) {
			std::cout << s << std::endl;
		}
	} else {
		std::cout << "NO DATA?!" << std::endl;
	}
	return 0;
}