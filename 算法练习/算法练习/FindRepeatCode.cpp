//
//  FindRepeatCode.cpp
//  算法练习
//
//  Created by HanKibou on 2023/5/21.
//

#include "FindRepeatCode.hpp"
// 引入头文件
#include <iostream>
#include <cstring>
using namespace std;


int main() {
// 首先读入两个字符串text1和text2，获取它们的长度n和m；
    string text1, text2;
   cin >> text1 >> text2;
    // 获取两个字符串的长度
    int n = text1.length();
    int m = text2.length();

    // 定义一个二维数组dp，用于记录最长公共子串的长度，dp[i][j]表示text1的前i个字符和text2的前j个字符的最长公共子串长度；
    int dp[n + 1][m + 1];
    // 将dp数组初始化为0
    memset(dp, 0, sizeof(dp));

    // 定义变量maxLen，用于记录最长公共子串的长度，初始化为0；
    int maxLen = 0;
    // 定义字符串ans，用于记录最长公共子串，初始化为空字符串
    string ans = "";

    // 遍历两个字符串text1和text2，查找最长公共子串：
    // 如果text1的第i个字符和text2的第j个字符相等，则更新dp数组，dp[i][j] = dp[i-1][j-1] + 1；
    // 如果dp[i][j]大于maxLen，则更新maxLen和ans，maxLen = dp[i][j]，ans = text1.substr(i-maxLen, maxLen)；
    // 如果text1的第i个字符和text2的第j个字符不相等，则dp数组的值为0，dp[i][j] = 0；
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // 如果两个字符相等，则更新dp数组，并更新maxLen和ans
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;

                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    ans = text1.substr(i - maxLen, maxLen);
                }
            }
            // 如果两个字符不相等，则dp数组的值为0
            else {
                dp[i][j] = 0;
            }
        }
    }
        cout << ans << endl;
    
    return 0;
}
