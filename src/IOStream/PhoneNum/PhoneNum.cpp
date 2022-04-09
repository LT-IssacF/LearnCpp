#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct PersonInfo {
    std::string name;
    std::vector<std::string> phone;
};

bool check(const std::string &str) {
    return str[0] == '+' && str.length() == 14;
}

std::string format(std::string str) {
    if(str[0] != '+') {
        str.insert(0, "+86");
    }
    while(str.length() < 14) {
        str.push_back('X');
    }
    while(str.length() > 14) {
        str.erase(str.end() - 1);
    }
    return str;
}

int main() {
    std::ifstream is("../src/IOStream/PhoneNum/input.txt"); // 文件读入流打开文件
    std::ofstream os("output.txt", std::ostream::trunc);
    std::string line;
    std::vector<PersonInfo> people;
    while(std::getline(is, line)) { // 一行一行地从流读入string中
        std::istringstream info(line); // 字符串读入流需要绑定string对象
        PersonInfo p;
        info >> p.name;
        std::string num;
        while(info >> num) {
            p.phone.emplace_back(num);
        }
        people.emplace_back(p);
    }
    for(const auto &i : people) {
        os << i.name; // 同步写出到文本中
        std::ostringstream valid, invalid; // 字符串写出流不绑定对象
        int validCnt = 0, invalidCnt = 0;
        for(const std::string &num : i.phone) {
            if(!check(num)) {
                os << " " << format(num);
                invalid << " " << num;
                invalidCnt++;
            } else {
                os << " " << num;
                valid << " " << num;
                validCnt++;
            }
        }
        os << std::endl;
        std::string ans;
        if(invalid.str().empty()) { // 字符串写出流的str()函数返回所保存string的拷贝，str(s)将string拷贝至s中并返回void
            ans = i.name + valid.str() + '\n';
        } else {
            ans = i.name + "'s";
            if(invalidCnt >= 2) {
                ans += " errors are" + invalid.str();
            } else {
                ans += " error is" + invalid.str();
            }
            ans += " and" + (validCnt > 0 ? valid.str() + (validCnt >= 2 ? " are" : " is") + " still valid" : " NO valid") + '\n';
        }
        std::cout << ans;
    }
    os.close();
    return 0;
}