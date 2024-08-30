#include<bits/stdc++.h>
using namespace std;
#define int long long int

int sumOfDivisors(int N){
    int sum = 0;
    for(int i=1; i<=N; i++){
        sum += (N/i) * i;
    }
    return sum;
}
/*
SUM OF DIVISOR FROM 1 TO N
1=> 1
2=> 1 2 
3=> 1 3
4=> 1 2 4
5=> 1 5
6=> 1 2 3 6
7=> 1 7
8=> 1 2 4 8

1 occur 8 times
2 occur 4 times
3 occur 2 times
4 occur 2 times
5 occur 1 times
6 occur 1 times
7 occur 1 times
8 occur 1 times
so total sum= 1*8 + 2*4 + 3*2 + 4*2 + 5*1 + 6*1 + 7*1 + 8*1

1 occur (8/1) times
2 occur (8/2) times
3 occur (8/3) times
4 occur (8/4) times
5 occur (8/5) times
6 occur (8/6) times
7 occur (8/7) times
8 occur (8/8) times
so total sum = (8/1)*1 + (8/2)*2 + (8/3)*3 + (8/4)*4 + (8/5)*5 + (8/6)*6 + (8/7)*7 + (8/8)*8
(N/i)*i
*/

vector<int> divisors(int n){
  vector<int> divisorList;

  for(int i=1;i<=sqrt(n);i++){
    if(n%i==0){
      divisorList.push_back(i);
      if(i!=n/i){
        divisorList.push_back(n/i);
      }
    }
  }

  return divisorList;
}

int main(){
  // ios_base::sync_with_stdio(false);cin.tie(NULL);
  
  int n;
  cout<<"Enter a number: ";
  cin>>n;

  vector<int> divisorList=divisors(n);
  cout<<"Divisors: ";
  for(int divisor:divisorList)
    cout<<" "<<divisor;

  return 0;
}
