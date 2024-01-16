#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll gcd_euclidean_recursive(ll a, ll b, ll &x, ll &y){
  // A IS GREATER THAN B
  if(a==0){
    x=0,y=1;
    return b;
  }
  
  ll x1,y1;
  ll gcd=gcd_euclidean_recursive(b%a,a,x1,y1);

  x=y1-(b/a)*x1;
  y=x1;

  return gcd;
}

ll gcd_euclidean_iterative(ll a, ll b, ll &t1, ll &t2){
  // A IS GREATER THAN B
  ll prevX,prevY,currX,currY,tmpX,tmpY;
  prevX=1,prevY=0,currX=0,currY=1;

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
