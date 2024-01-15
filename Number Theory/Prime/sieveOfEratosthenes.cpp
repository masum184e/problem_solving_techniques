#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll> prime_sieve(ll N){
    vector<bool> sieve(N,true);
    sieve[0]=sieve[1]=false;

    // MARKING PRIME AND NON-PRIME
    for(int i=2;i*i<=N;i++)
        if(sieve[i])
            for(int j=i*i;j<=N;j+=i)
                sieve[j]=false;

    // GENERATING PRIME LIST
    vector<ll> primes;
    for(ll i=0;i<sieve.size();i++)
        if(sieve[i])
            primes.push_back(i);

    return primes;
}

void countPrimes(ll lower, ll upper){ 
  vector<ll> primes=prime_sieve(upper);
  ll count=0;

  cout<<"Primes within the range between "<<lower<<" and "<<upper<<": ";
  for(ll i=0;i<primes.size();i++)
    if(primes[i]>=lower && primes[i]<=upper){
      cout<<primes[i]<<" ";
      count++;
    }

  cout<<endl<<"Number of primes: "<<count<<endl;
}

int main(){
    ll N;
    cout<<"Enter boundary for prime: ";
    cin>>N;
    
    cout<<"Primes are: ";
    vector<ll> primes=prime_sieve(N);
    for(ll i=0;i<primes.size();i++)
        cout<<primes[i]<<" ";

    ll lower,upper;
    cout<<endl<<"Enter lower bound: ";
    cin>>lower;
    cout<<"Enter upper bound: ";
    cin>>upper;
    countPrimes(lower,upper);

    return 0;
}