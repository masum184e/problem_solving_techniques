#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll binomialCoefficient(ll n, ll r){

    vector<vector<ll>> triangle(n+1,vector<ll>(r+1,0));

    for(ll i=0;i<=n;i++)
        for(ll j=0;j<=min(i,r);j++)
            (j==0||j==i)?triangle[i][j]=1:triangle[i][j]=triangle[i-1][j-1]+triangle[i-1][j];

    return triangle[n][r];
}

void pascalTriangle(ll row){
    for(ll i=0;i<row;i++){
        for(ll j=0;j<=i;j++)cout<<binomialCoefficient(i,j)<<" ";
        cout<<endl;
    }
}

int main(){

    ll n,r;
    cout<<"Enter Value of N: ";cin>>n;
    cout<<"Enter Value of R: ";cin>>r;

    cout<<"Binomial Coefficient-("<<n<<"C"<<r<<"): "<<binomialCoefficient(n,r)<<endl<<endl;

    cout<<"Enter End Line for Pascal Triangle: ";cin>>n;
    pascalTriangle(n);

    return 0;
}