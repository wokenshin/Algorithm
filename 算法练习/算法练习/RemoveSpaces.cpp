//
//  RemoveSpaces.cpp
//  算法练习
//
//  Created by HanKibou on 2023/5/21.
//

#include "RemoveSpaces.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <sstream> // 用于字符串分割

using namespace std;

// 存储输入的数据
vector<string> input_lines;

// 处理函数声明
void get_result(vector<vector<int>>& range_arr, string str);

int main() {
    // 创建 readline 接口实例
    string line;
    while (getline(cin, line)) {
        input_lines.push_back(line);

        // 当输入的数据达到 2 行时，进行处理
        if (input_lines.size() == 2) {
            const string& str = input_lines[0];
            vector<vector<int>> arr;
            stringstream ss(input_lines[1]);
            string pos;
            while (getline(ss, pos, ',')) {
                stringstream ss2(pos);
                int start, end;
                ss2 >> start >> end;
                arr.push_back({start, end});
            }

            // 调用处理函数
            get_result(arr, str);

            // 清空存储的数据
            input_lines.clear();
        }
    }
    return 0;
}

// 处理函数
void get_result(vector<vector<int>>& range_arr, string str) {
    bool quota_start = false;
    vector<int> need_del;

    // 遍历字符串，记录需要删除的空格位置
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ' && str[i - 1] == ' ' && !quota_start) {
            need_del.push_back(i);
        }

        if (str[i] == '\'') {
            quota_start = !quota_start;
        }
    }

    // 将字符串转为数组，并进行删除空格操作
    vector<char> str_arr(str.begin(), str.end());
    vector<vector<int>> ans = range_arr; // 深拷贝

    for (int del : need_del) {
        str_arr[del] = ' ';
        for (int i = 0; i < range_arr.size(); i++) {
            const int start = range_arr[i][0];
            if (del < start) {
                ans[i][0]--;
                ans[i][1]--;
            }
        }
    }

    // 输出结果
    for (char c : str_arr) {
        cout << c;
    }
    cout << endl;
    for (const vector<int>& range : ans) {
        cout << "[" << range[0] << ", " << range[1] << "]";
    }
}
