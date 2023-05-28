【短期记忆】---【长期记忆】需要将这里的数据整理成有逻辑的文档
1、一定要给整数初始化0值，否则将拿到错误值，比如 题目1
2、cin 在接收字符串时中间不能有空格，空格将会中断cin的接收，整行字符串的接收要用getline 比如：getline(cin, yourStr);
3、A == 65 a == 97 大写-->小写 x+32 == X    非字母<65  a~z 之后也是非字母

4、注意 数组、list、字典等的使用、遍历、访问等

-----------------------题目1-----------------------HJ1 字符串最后一个单词的长度
#include<iostream>
#include<string>
using namespace std;
int main() {
    string words;
    getline(cin, words);
    int lastWordLen = 0;//注意！一定要出实话，否则会报错
    for(int i = words.size()-1; i >= 0; i--) {
        if(words[i] == ' ') {
            break;
        }
        //注意++不要放在判断空格之前，因为空格不计算长度
        lastWordLen++;
    }
    cout << lastWordLen << endl;
    return 0;
}

Xcode代码格式化：全选代码/选中部分代码-->Editor -> Structure ->Re-Indent