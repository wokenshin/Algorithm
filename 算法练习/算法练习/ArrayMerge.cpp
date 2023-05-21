//
//  ArrayMerge.cpp
//  算法练习
//
//  Created by HanKibou on 2023/5/21.
//

#include "ArrayMerge.hpp"

#include <iostream>//输入输出
#include <vector>//向量
#include <list>//链表
#include <string>
#include <sstream>
using namespace std;
void ArrayMerge() {
    //处理输入------------------------------------------------------------------------------------------------>开始
    int k;//每次取出k个数
    int n;//有多少个数组
    cin >> k >> n;//当用键盘输入一个整数回车后、这个整数就赋值给k了、接着输入第二个整数再次回车、第二个整数就赋值给了n
    cin.ignore();//忽略掉换行符（为什么？）
    
    //初始化数组（根据接收的参数n、循环接收字符串、拿到每一个数组、然后将接收到的字符串转换成数组、循环添加到另一个数组中）
    vector<list<int>> numArrays;
    for (int i = 0; i < n; i++) {
        list<int> numArray;//注意 这里的numArray没有s
        string line;
        getline(cin, line);//读取一行输入，并赋值给line
        stringstream ss(line);//将读取的字符串转换为stringstream对象
        string numStr;
        while (getline(ss, numStr, ',')) {//以逗号为分隔符、读取每一个数字
            numArray.push_back(stoi(numStr));//将字符串转换为整数并添加到list中
        }
        numArrays.push_back(numArray);//将list添加到vector中
    }
    //处理输入------------------------------------------------------------------------------------------------>结束
    
    //处理输出------------------------------------------------------------------------------------------------>开始
    //拼接字符串
    stringstream builder;
    int index = 0;
    while (numArrays.size() > 0) {
        list<int>& singleArray = numArrays[index];//遍历数组中的每一个元素（元素依然是数组）
        // 取出前k个
        for(int i = 0; i < k; i++) {
            if(singleArray.empty()) {//当某一行的数组被全部取出时、这一行的数组就要被删除掉
                numArrays.erase(numArrays.begin() + index);//？？？
                index--;
                break;
            }
            builder << singleArray.front() << ",";//看一下 nm命令输出到文件 是不是 向右的>>
            singleArray.pop_front();
        }
        index++;
        if (index >= numArrays.size()) {
            index = 0;//结束循环
        }
    }
    string result = builder.str();//将stringstream转为string
    cout << result.substr(0, result.length()-1) << endl; //输出拼接好的字符串，去掉最后以个逗号
    //处理输出------------------------------------------------------------------------------------------------>结束
}

/*
 总结：
 题目其实考察了两个方面
 1、输入：怎么接收参数，怎么将接收到的参数转换成想要的数据
 2、输出：怎么将输入的参数数据通过一定的算法得到想要的结果并输出
 */


