#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll number_of_digit_in_factorial(ll input){
  double sum=0;  
  for(int i=1;i<=input;i++)sum+=log10(i);
  return floor(sum);
}

int main(){
  // ios_base::sync_with_stdio(false);cin.tie(NULL);

  ll input;
  cout<<"Enter a number: ";
  cin>>input;
  cout<<"Num of digit in fact: "<<number_of_digit_in_factorial(input)<<endl;  

  return 0;
}

/*
50!=3.04140932*10^64
log10(50!)=log10(3.04140932*10^64)
          =log10(3.04140932)+log10(10^64)
          =0.483+64
          =64.483
          =floor(64.483)
          =64 number of digit ace

log10(50!)=log10(1*2*3*.....*49*50)
          =log10(1)+log10(2)+log10(3)+log10(4)+....+log10(49)+log10(50)
*/