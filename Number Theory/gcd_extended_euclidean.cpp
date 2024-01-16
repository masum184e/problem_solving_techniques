#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll gcd_euclidean_recursive(ll a, ll b, ll &t1, ll &t2){
  // A IS GREATER THAN B
  if(a==0){
    t1=1,t2=0;
    return b;
  }
  
  ll x,y;
  ll gcd=gcd_euclidean_recursive(b%a,a,x,y);

  t1=y;
  t2=x-(b/a)*y;

  return gcd;
}

int main(){
  // ios_base::sync_with_stdio(false);cin.tie(NULL);

  ll a,b,x,y;
  cout<<"Enter bigger number: ";
  cin>>a;
  cout<<"Enter smaller number: ";
  cin>>b;
  cout<<"GCD is(recursive): "<<gcd_euclidean_recursive(a,b,x,y)<<endl;
  cout<<"Bezout's Coefficients S= "<<x<<" AND T="<<y<<endl<<endl;

  return 0;
}
