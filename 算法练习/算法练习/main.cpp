#include <iostream>
#include <string>
#include <regex>

using namespace std;


//匹配整个字符串
void regex_matchDemo() {
    string str;
    while(cin >> str) {
        if(regex_match(str, regex("[a-z]{1,100}"))) {//匹配小写字母、范围是1到100个字符
            cout << "匹配" << endl;
        } else {
            cout << "不匹配" << endl;
        }
    }
}

//匹配子串-搜索匹配
void regex_searchDemo() {
    
}

//正则替换
void regex_replaceDemo() {
    string str = "han-ki-bou";
    cout << regex_replace(str, regex("-"), "/") << endl;//将字符串中符合正则的内容修改为 /
    cout << str << endl;//正则不会修改原字符串内容、而是返回一个新的字符串
}

int main() {
    regex_replaceDemo();
    return 0;
}
