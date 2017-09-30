#include<iostream>
using namespace std;
int fun(int n);
int main(){
    int s=1,n;
    cin>>n;
    while(n!=1){
        s=s+fun(n);
        n=n-1;
    }
    cout<<s<<endl;
    return 0;
}
int fun(int n){
    if(n==1) 
        return 1;
    else
        return n*fun(n-1);
}