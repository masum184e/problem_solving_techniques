#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll zero_at_end_of_factorial(ll input){
  ll m=1,sum=0;
  
  while(input/m){
    m=m*5;
    sum+=(input/m);
  }

  return sum;
}

int main(){
  // ios_base::sync_with_stdio(false);cin.tie(NULL);

  ll input;
  cout<<"Enter a number: ";
  cin>>input;
  cout<<"Zero at end of fact: "<<zero_at_end_of_factorial(input)<<endl;

  return 0;
}

/*
every zero at the end indicate 10
so every zero means 10
each 10 contains 5*2
in factor, each 5 makes a 10, makes a 0
so number 0 is equal to number of 10
*/