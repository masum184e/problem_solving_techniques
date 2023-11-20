#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll> divisors(int n){
  vector<ll> divisorList;

  for(ll i=1;i<=n;i++)
    if(n%i==0)
      divisorList.push_back(i);

  return divisorList;
}

int main(){
  // ios_base::sync_with_stdio(false);cin.tie(NULL);
  
  ll n;
  cout<<"Enter a number: ";
  cin>>n;

  vector<ll> divisorList=divisors(n);
  cout<<"Divisors: ";
  for(ll divisor:divisorList)
    cout<<" "<<divisor;

  return 0;
}
