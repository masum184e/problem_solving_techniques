#include <bits/stdc++.h>
using namespace std;
#define int long long int

int binaryExponentiation(int a, int b){
    int pwr=1;
    while(b){
        if(b&1)pwr*=a;
        a*=a;
        b>>=1;
    }
    return pwr;
}

int modularExponentiation(int a, int b){
    int pwr=1,mod = 1e9 + 7;
    while(b){
        if(b&1)pwr=(pwr*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return pwr;
}

double fastPower(double a, int n){
    if(n==INT_MAX)return(a==1)?1:(a==-1)?-1:0;
    if(n==INT_MIN)return(a==1 || a==-1)?1:0;

h    int N=n;
    if(N<0){
        a=1/a;
        N=-N;
    }

    if(n==0)return 1.0;
    
    double subProb=fastPower(a, N/2);
    double subProbSq=subProb*subProb;

    if(n&1)return a*subProbSq;
    return subProbSq;
}

int32_t main(){
    int a,b;
    cout<<"Enter Base Number: ";cin>>a;
    cout<<"Enter Exponent Number: ";cin>>b;
    cout<<"Power("<<a<<","<<b<<")-Binary: "<<binaryExponentiation(a,b)<<endl;
    cout<<"Power("<<a<<","<<b<<")-Modular: "<<modularExponentiation(a,b)<<endl;
    cout<<"Fast Power("<<a<<","<<b<<"): "<<fastPower(a,b)<<endl;

    return 0;
}