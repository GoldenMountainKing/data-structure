//目的：通过对比同一个问题不同解法的绝对执行时间体会如何设计"好"的算法
//内容：编写一个程序exp1-3.cpp,求1~n的素数的个数 

//超级复杂版
#include<iostream>
using namespace std;
int main(){
    int i,j,k=0;
    for(i=1;i<=100;i++){
        for(j=2;j<i;j++){
            if(i!=j&&i%j==0)
            break;
        }
        if(i==j)
        k++;
    }
    cout<<k<<endl;
    return 0;
}
