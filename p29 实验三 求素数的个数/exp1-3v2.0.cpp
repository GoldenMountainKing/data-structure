#include<iostream>
#include<time.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
#define CLOCKS_PRE_SEC 1000
//--------------方法一--------------
bool prime1(long int n){    //方法一:判断正整数n是否为素数
    long i;
    for(i=2;i<n;i++){
        if(n%i==0)
            return false;
    }
    return true;
} 
void Prime1Time(long int n){
    clock_t t;
    long sum=0,i;
    t=clock();
    for(i=2;i<=n;i++)
        if(prime1(i))
            sum++;
    t=clock()-t;
    cout<<"方法2:"<<endl;
    cout<<"结果:2~"<<n<<"的素数个数:"<<sum<<endl;
    cout<<"用时:"<<((float)t)/CLOCKS_PRE_SEC<<endl;
}              
//--------------方法二--------------
bool prime2(long int n){
    long i;
    for(i=2;i<=(int)sqrt(n);i++)
        if(n%i==0)
            return false;
    return true;
}
void Prime2Time(long int n){
    clock_t t;
    long sum=0,i;
    t=clock();
    for(i=2;i<=n;i++)
        if(prime2(i))
            sum++;
    t=clock()-t;
    cout<<"方法2:"<<endl;
    cout<<"结果:2~"<<n<<"的素数个数:"<<sum<<endl;
    cout<<"用时:"<<((float)t)/CLOCKS_PRE_SEC<<endl;
}
//-------------------------------------------------
int main(){
    long int n;
    cout<<"n(大于100000):"<<endl;
    cin>>n;
    if(n<100000) 
        return 0;
    Prime1Time(n);
    Prime2Time(n);
    return 1;
}
