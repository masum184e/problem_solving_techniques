#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
  ll T;
  cout<<"How Many Times: ";
  cin>>T;
  while(T--){
    ll N,count=1;
    cout<<endl<<"Array Size: ";
    cin>>N;
    ll A[N];
    cout<<"Array Item: ";
    for(ll i=0;i<N;i++)cin>>A[i];

    cout<<"Unique Pair List:"<<endl;
    for(ll i=0;i<N;i++){
      for(ll j=i+1;j<N;j++){
        cout<<count<<". "<<A[i]<<" "<<A[j]<<endl;
        count++;
      }
    }

  }
  return 0;
}
