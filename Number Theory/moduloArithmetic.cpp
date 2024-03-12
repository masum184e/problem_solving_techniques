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

int main(){

    ll x,y,p;
    cout<<"Enter two number: ";
    cin>>x>>y;
    cout<<"Enter prime number: ";
    cin>>p;

    cout<<"Additive       Modulo: "<<add(x,y,p)<<endl;
    cout<<"Substractive   Modulo: "<<sub(x,y,p)<<endl;
    cout<<"Multiplicative Modulo: "<<mul(x,y,p)<<endl;

    return 0;
}