#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll gcdExtended(ll a, ll b, ll &x, ll &y){
  // A IS GREATER THAN B
  if(a==0){
    x=0,y=1;
    return b;
  }
  
  ll x1,y1;
  ll gcd=gcdExtended(b%a,a,x1,y1);

  x=y1-(b/a)*x1;
  y=x1;

  return gcd;
}

int multiplicative_modulo_inverse(ll a, ll b){
    ll x,y;
    ll gcd=gcdExtended(a,b,x,y);
    if(gcd!=1)return -1;

    ll mmi=(x%b+b)%b;
    return mmi;
}

int main(){
  // ios_base::sync_with_stdio(false);cin.tie(NULL);

  ll a,b;
  cout<<"Enter bigger number: ";
  cin>>a;
  cout<<"Enter smaller number: ";
  cin>>b;

  ll mmi=multiplicative_modulo_inverse(a,b);
  if(mmi==-1)cout<<"Multiplicative Inverse is Not Possible"<<endl;
  cout<<"Multiplicative Modulo Inverse: "<<mmi<<endl;

  return 0;
}
