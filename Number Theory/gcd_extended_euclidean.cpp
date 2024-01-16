#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll gcd_euclidean_recursive(ll a, ll b, ll &t1, ll &t2){
  // A IS GREATER THAN B
  if(a==0){
    t1=1,t2=0;
    return b;
  }
  
  ll x,y;
  ll gcd=gcd_euclidean_recursive(b%a,a,x,y);

  t1=y;
  t2=x-(b/a)*y;

  return gcd;
}

ll gcd_euclidean_iterative(ll a, ll b, ll &t1, ll &t2){
  // A IS GREATER THAN B
  ll prevX,prevY,currX,currY,tmpX,tmpY;
  prevX=0,prevY=1,currX=1,currY=0;

  while(b!=0){
    ll q=a/b;
    ll r=a%b;

    a=b;
    b=r;

    tmpX=currX;
    currX=prevX-q*currX;
    prevX=tmpX;

    tmpY=currY;
    currY=prevY-q*currY;
    prevY=tmpY;
  }

  t1=prevX;
  t2=prevY;

  return a;
}

int main(){
  // ios_base::sync_with_stdio(false);cin.tie(NULL);

  ll a,b,x,y,p,q;
  cout<<"Enter bigger number: ";
  cin>>a;
  cout<<"Enter smaller number: ";
  cin>>b;
  cout<<"GCD is(recursive): "<<gcd_euclidean_recursive(a,b,x,y)<<endl;
  cout<<"Bezout's Coefficients S= "<<x<<" AND T="<<y<<endl<<endl;
  cout<<"GCD is(iterative): "<<gcd_euclidean_iterative(a,b,p,q)<<endl;
  cout<<"Bezout's Coefficients S= "<<p<<" AND T="<<q<<endl;  

  return 0;
}
