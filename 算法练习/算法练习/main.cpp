#include <iostream>
#include <map>
using namespace std;


int main() {
    //输入部分
    int N,m;
    cin >> N >> m;
    int v,p,q;
    map<int, map<int, int>> arr[m];
    map<int, map<int, int>>myMap;//价格:[重要程度:是否有主件]
    
    for(int i = 0; i < m; i++) {
        cin >> v >> p >> q;
        map<int, int>subMap;
        subMap[p] = q;
        myMap[v] = subMap;
        arr[i] = myMap;
    }
    
    //输出部分
    
}

/*
 1000 5
 800 2 0
 400 5 1
 300 5 1
 400 3 0
 500 2 0
 条件
 1、如果要买归类为附件的物品，必须先买该附件所属的主件
 2、每件物品只能购买一次
 3、每个主件可以有 0 个、 1 个或 2 个附件
 
 要求 获取最大值
 
 公式：x个主件+y个附件 这里的y个附件中对应的主件一定包含在x里、x里有的主件不一定有对应的附件在y里
 v：价格
 p：重要程度---权重
 q：q>0 ，表示该物品为附件， q 是所属主件的编号
 
 */
