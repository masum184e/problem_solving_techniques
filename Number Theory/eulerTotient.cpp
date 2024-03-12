#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll> prime_sieve(ll N){
    vector<bool> sieve(N,true);
    sieve[0]=sieve[1]=false;

    // MARKING PRIME AND NON-PRIME
    for(ll i=2;i*i<=N;i++)
        if(sieve[i])
            for(ll j=i*i;j<=N;j+=i)
                sieve[j]=false;

    // GENERATING PRIME LIST
    vector<ll> primes;
    for(ll i=0;i<sieve.size();i++)
        if(sieve[i])
            primes.push_back(i);

    return primes;
}

ll eulerTotient(ll n){
    vector<ll> primes=prime_sieve(n);

    double et=n;
    for(ll i=0;i<primes.size();i++){
        if(n%primes[i]==0){
            et/=primes[i];
            et*=(primes[i]-1);
        }
    }

    return et;
}

int main(){

    ll n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Value of euler totient: "<<eulerTotient(n)<<endl;

    return 0;
}