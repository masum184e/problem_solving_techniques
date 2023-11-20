#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool isPrime(int n){
  if(n<=1)return false;
  for(ll i=2;i*i<=n;i++)
    if(n%i==0)
      return false;
  return true;
}

int main(){
  
  ll n;
  cout<<"Enter a number: ";
  cin>>n;
  (isPrime(n))?cout<<"Given number is prime"<<endl:cout<<"Given number is not prime"<<endl;

  return 0;
}
