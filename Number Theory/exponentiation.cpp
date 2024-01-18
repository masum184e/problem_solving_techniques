#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll binaryExponentiation(ll a, ll b){
    ll pwr=1;
    while(b){
        if(b&1)pwr*=a;
        a*=a;
        b>>=1;
    }
    return pwr;
}

ll modularExponentiation(ll a, ll b){
    ll pwr=1,mod = 1e9 + 7;
    while(b){
        if(b&1)pwr=(pwr*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return pwr;
}

int main(){
    ll a,b;
    cout<<"Enter Base Number: ";cin>>a;
    cout<<"Enter Exponent Number: ";cin>>b;
    cout<<"Power("<<a<<","<<b<<")-Binary: "<<binaryExponentiation(a,b)<<endl;
    cout<<"Power("<<a<<","<<b<<")-Modular: "<<modularExponentiation(a,b)<<endl;

    return 0;
}