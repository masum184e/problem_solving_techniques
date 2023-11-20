#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int gcd(int a, int b){
  // A IS GREATER THAN B
  if(a==0)return b;
  return gcd(b%a,a);
}

int main(){
  // ios_base::sync_with_stdio(false);cin.tie(NULL);

  ll a,b;
  cout<<"Enter bigger number: ";
  cin>>a;
  cout<<"Enter smaller number: ";
  cin>>b;
  cout<<"GCD is: "<<gcd(a,b)<<endl;
  return 0;
}
