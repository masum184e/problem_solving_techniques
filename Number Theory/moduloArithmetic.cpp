#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll add(ll x, ll y, ll p){
    return (x+y)%p;
}

ll sub(ll x, ll y, ll p){
    return ((x-y)%p+p)%p;
}

ll mul(ll x, ll y, ll p){
    return (x*y)%p;
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

ll div(ll x, ll y, ll p){
    return mul(x, modularExponentiation(y,p-2), p);
}

int main(){

    ll x,y,p;
    cout<<"Enter two number: ";
    cin>>x>>y;
    cout<<"Enter prime number: ";
    cin>>p;

    cout<<"Additive       Modulo: "<<add(x,y,p)<<endl;
    cout<<"Substractive   Modulo: "<<sub(x,y,p)<<endl;
    cout<<"Multiplicative Modulo: "<<mul(x,y,p)<<endl;
    cout<<"Division       Modulo: "<<div(x,y,p)<<endl;

    return 0;
}