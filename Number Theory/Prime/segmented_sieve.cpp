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

void segment_sieve(ll lower, ll upper){
    vector<ll> primes=prime_sieve(upper);
	vector<int> segment(upper-lower+1,0);

    for(auto prime:primes){
        if(prime*prime>upper)break;

        int start=(lower/prime)*prime;
		if(prime>=lower && prime<=upper)start=2*prime;

        for(int j=start;j<=upper;j+=prime){
            if(j<lower)continue;
            segment[j-lower]=1;
        }
        
    }

    cout<<"Primes in the range ["<<lower<<", "<<upper<< "]: ";
    for(int j=lower;j<=upper;j++)
        if(segment[j-lower]==0 && j!=1)cout<<j<<" ";
}

int main(){
    
    ll lower,upper;
    cout<<"Enter lower bound: ";
    cin>>lower;
    cout<<"Enter upper bound: ";
    cin>>upper;

    segment_sieve(lower, upper);


    return 0;
}