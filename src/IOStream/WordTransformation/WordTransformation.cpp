#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

std::map<std::string, std::string> build_map(std::ifstream &map_file) {
    std::string line, key, value;
    std::map<std::string, std::string> trans_map; // 转换规则
    while(std::getline(map_file, line)) {
        std::istringstream info(line);
        info >> key; // 获得简写
        std::getline(info, value); // 剩下的一行都是简写对应的全写
        value.erase(value.begin()); // 去掉开头多余的空格
        trans_map.insert({key, value});
    }
    return trans_map;
}

std::ofstream &transform(std::ifstream &is, std::ofstream &os, const std::map<std::string, std::string> &trans_map) {
    std::string line, word;
    while(std::getline(is, line)) {
        std::cout << line << " -> "; // 在终端中清晰展示不同
        std::istringstream info(line);
        std::ostringstream oss;
        bool first_word = true; // 单词之间的空格
        while(info >> word) {
            if(first_word == true) {
                first_word = false;
            } else {
                oss << " ";
            }
            auto it = trans_map.find(word);
            if(it != trans_map.end()) { // 是简写
                oss << it->second;
            } else {
                oss << word; // 不在转换规则内
            }
        }
        os << oss.str() << std::endl;
        std::cout << oss.str() << std::endl; // 同步输出
    }
    return os;
}

int main() {
    std::ifstream is("../src/IOStream/WordTransformation/input.txt"), map_file("../src/IOStream/WordTransformation/map_file.txt");
    std::ofstream os("output.txt", std::ofstream::trunc);
    std::map<std::string, std::string> trans_map = build_map(map_file);
    transform(is, os, trans_map);
    os.close();
    return 0;
}