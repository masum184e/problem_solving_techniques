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

ll fastPower(ll a, ll n){
    if(n==0)return 1;
    
    ll subProb=fastPower(a, n/2);
    ll subProbSq=subProb*subProb;

    if(n&1)return a*subProbSq;
    return subProbSq;
}

int main(){
    ll a,b;
    cout<<"Enter Base Number: ";cin>>a;
    cout<<"Enter Exponent Number: ";cin>>b;
    cout<<"Power("<<a<<","<<b<<")-Binary: "<<binaryExponentiation(a,b)<<endl;
    cout<<"Power("<<a<<","<<b<<")-Modular: "<<modularExponentiation(a,b)<<endl;
    cout<<"Fast Power("<<a<<","<<b<<"): "<<fastPower(a,b)<<endl;

    return 0;
}