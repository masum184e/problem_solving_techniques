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

int main(){
    ll N;
    cout<<"Enter boundary for prime: ";
    cin>>N;
    
    cout<<"Primes are: ";
    vector<ll> primes=prime_sieve(N);
    for(ll i=0;i<primes.size();i++)
        cout<<primes[i]<<" ";

    return 0;
}