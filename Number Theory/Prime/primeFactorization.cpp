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

map<ll, ll> primeFactorization(ll N){
    vector<ll> primes=prime_sieve(N);

    map<ll, ll> primeFact;
    ll i=0;

    while(N>1){
        if(N%primes[i]==0){
            N=N/primes[i];
            primeFact[primes[i]]++;
        }else i++;
    }

    return primeFact;
}
int main(){
    // ios_base::sync_with_stdio(false);cin.tie(NULL);

    ll n;
    cout<<"Enter a number: ";
    cin>>n;

    map<ll,ll> primeFact=primeFactorization(n);

    cout<<"Prime Factors are(Prime:Power):"<<endl;
    for(auto i:primeFact)cout<<i.first<<" "<<i.second<<endl;

    return 0;
}