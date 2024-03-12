#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll extended_euclidean(ll a, ll b, ll &x, ll &y){
  // A IS GREATER THAN B
  if(a==0){
    x=0,y=1;
    return b;
  }
  
  ll x1,y1;
  ll gcd=extended_euclidean(b%a,a,x1,y1);

  x=y1-(b/a)*x1;
  y=x1;

  return gcd;
}

ll chineseRemainder(vector<ll> modulo, vector<ll> remainder){
    ll prod=1;
    for(ll i:modulo)prod*=i;

    ll crt=0;
    for(ll i=0;i<modulo.size();i++){
        ll pp=prod/modulo[i];
        ll inv, y;
        extended_euclidean(pp, modulo[i], inv, y);
        crt+=remainder[i]*inv*pp;
    }

    return crt%prod;
}

int main(){

    ll numOfEqn;
    cout<<"How many equations: ";
    cin>>numOfEqn;

    vector<ll> modulo, remainder;
    for(ll i=0;i<numOfEqn;i++){
        ll m,r;
        cout<<"Enter modulo & remainder: ";
        cin>>m>>r;
        modulo.push_back(m);
        remainder.push_back(r);
    }

    cout<<"The number is: "<<chineseRemainder(modulo, remainder)<<endl;

    return 0;
}