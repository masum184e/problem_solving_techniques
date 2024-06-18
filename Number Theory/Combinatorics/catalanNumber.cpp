#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int catalan_recursive(int n){
    if(n==0 || n==1)return 1;

    int catalan=0;
    for(int i=1;i<=n;i++)
        catalan+=(catalan_recursive(i-1)*catalan_recursive(n-i));
    
    return catalan;
}

int catalan_topdown_dp(int n, int dp[]){
    if(n==0 || n==1)return 1;

    if(dp[n]!=0)return dp[n];

    int catalan=0;
    for(int i=1;i<=n;i++)
        catalan+=(catalan_topdown_dp(i-1, dp)*catalan_topdown_dp(n-i, dp));
    
    return catalan;
}

int catalan_bottomup_dp(int n){
    vector<int> dp(n+1, 0);
    dp[0]=dp[1]=1;

    for(int i=2;i<=n;i++)
        for(int j=1;j<=i;j++)
            dp[i]+=(dp[j-1]*dp[i-j]);
    
    return dp[n];
}

int main(){

    int n;
    cout<<"Enter Value of N: ";cin>>n;
    
    int dp[n+1]={0};
    
    cout<<"Catalan Number - Recursive  : "<<catalan_recursive(n)<<endl;
    cout<<"Catalan Number - TopDown DP : "<<catalan_topdown_dp(n, dp)<<endl;
    cout<<"Catalan Number - BottomUp DP: "<<catalan_bottomup_dp(n)<<endl;

    return 0;
}