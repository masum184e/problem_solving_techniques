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

    cout<<"Sub Array List:"<<endl;
    vector<ll> subArray;
    for(ll i=0;i<N;i++){
      for(ll j=i;j>=0;j--){
        subArray.push_back(A[j]);
        cout<<count<<". ";
        for (ll item : subArray){
          cout<<item<<" ";
        }
        count++;
        cout<<endl;
      }
      subArray.clear();
    }

  }
  return 0;
}
