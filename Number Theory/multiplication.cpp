#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll mul(ll x, ll y, ll p){
    return x*y;
}

ll fastMultiplication(ll x, ll y, ll p){
    ll res=0;
    while(y){
        if(y&1)res=(res+x)%p;
        x=(x+x)%p;
        y/=2;
    }
    return res;
}

int main(){
    ll a,b,p;
    cout<<"Enter Prime Number: ";cin>>p;
    cout<<"Enter Two Number: ";cin>>a>>b;

    cout<<"Mulitiplication ("<<a<<"*"<<b<<"): "<<mul(a,b,p)<<endl;
    cout<<"Fast Mulitiplication ("<<a<<"*"<<b<<"): "<<fastMultiplication(a,b,p);

    return 0;
}