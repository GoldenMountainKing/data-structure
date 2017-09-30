#include<iostream>
using namespace std;
int main(){
    int fun(int n);
    int num,i=1,sum=1;
    cin>>num;
    while(num!=1){
        sum=sum+fun(num);
        num=num-1;
    }
    cout<<sum<<endl;
    return 0;
}
int fun(int n){
    int s=1,i=1;
    do{
        s*=i;
        i++;
        }
    while(i<=n);
    return s;
}
