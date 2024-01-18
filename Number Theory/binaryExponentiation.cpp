#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll power(ll a, ll b){
    ll pwr=1;
    while(b){
        if(b&1)pwr*=a;
        a*=a;
        b>>=1;
    }
    return pwr;
}

int main(){
    ll a,b;
    cout<<"Enter Base Number: ";cin>>a;
    cout<<"Enter Exponent Number: ";cin>>b;
    cout<<"Power("<<a<<","<<b<<"): "<<power(a,b)<<endl;

    return 0;
}