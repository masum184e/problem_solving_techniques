#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll gcd_euclidean_recursive(ll a, ll b){
  // A IS GREATER THAN B
  if(a==0)return b;
  return gcd_euclidean_recursive(b%a,a);
}

ll gcd_euclidean_iterative(ll a, ll b){
  // A IS GREATER THAN B
  while(b!=0){
    ll r=a%b;
    a=b;
    b=r;
  }
  return a;
}

int main(){
  // ios_base::sync_with_stdio(false);cin.tie(NULL);

  ll a,b;
  cout<<"Enter bigger number: ";
  cin>>a;
  cout<<"Enter smaller number: ";
  cin>>b;
  cout<<"GCD is(recursive): "<<gcd_euclidean_recursive(a,b)<<endl;
  cout<<"GCD is(iterative): "<<gcd_euclidean_iterative(a,b)<<endl;
  return 0;
}
