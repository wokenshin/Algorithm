#include<algorithm>
#include<iostream>
#include <vector>
using namespace std;

// 暴力求解
void func1() {
    int n;//n个物品
    int v;//背包体积
    cin>>n>>v;
    
    //注意此处的N至少要比最大范围多1
    const int N=1001;
    int V[N];//每个物品对应的体积
    int W[N];//每个物品对应的价值
    //存储输入
    for(int i=1;i<=n;i++) {
        cin>>V[i]>>W[i];
    }
    
    int f[N][N];//用来存放结果
    for(int i=1;i<=n;i++) {
        //背包容量需从0,...,v
        for(int j=0;j<=v;j++) {
//当前背包体积<当前物品体积，装不下当前物品、那么当前背包体积的最大值就是：前一个物品放进背包后的最大值
            if(j<V[i]) {
                f[i][j]=f[i-1][j];
            } else {
//当前背包体积>当前物品体积，可以装下当前物品、那么当前背包体积的最大值就是：(放入当前物品前的最大值) 和 (放入当前物品后，背包的值+剩余体积的最大值) 之间的最大值
                f[i][j]=max(f[i-1][j],f[i-1][j-V[i]]+W[i]);
            }
        }
    }
    cout << f[n][v] << endl;
}

//暴力求解
int knapsack(int n, int V, vector<vector<int> >& vw) {
    int f[n+1][V+1];//用来存放结果
    for(int i = 0; i < n+1; i++) {
        for (int j = 0; j < V+1; j++) {
            f[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= V; j++) {
            if (j < vw[i-1][0]) {
                f[i][j] = f[i - 1][j];
            } else {
                f[i][j] = max(f[i - 1][j], f[i - 1][j - vw[i-1][0]] + vw[i-1][1]);
            }
        }
    }
    return f[n][V];
}

void func2() {
    vector<vector<int>>vec;
    vector<int>vec1;
    vector<int>vec2;
    vector<int>vec3;
    
    vec1.push_back(2);
    vec1.push_back(3);
    
    vec2.push_back(3);
    vec2.push_back(4);
    
    vec3.push_back(4);
    vec3.push_back(5);
    
//    vec.push_back(vector<int>());
    vec.push_back(vec1);
    vec.push_back(vec2);
    vec.push_back(vec3);
    cout << knapsack(3, 6, vec) << endl;
}
int main()
{
//    func1();
    func2();
    return 0;
}
/*
 3 6
 2 3
 3 5
 4 6
 */
