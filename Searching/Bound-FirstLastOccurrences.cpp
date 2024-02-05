#include<bits/stdc++.h>
using namespace std;

// FIRST OCCURENCES
int lower_bound(vector<int> arr, int item){
    int left,mid,right,index;
    left=0,right=arr.size()-1,index=-1;

    while(left<=right){
        mid=left+(right-left)/2;
        if(arr[mid]==item){
            index=mid;
            right=mid-1;
        }else if(arr[mid]>item)right=mid-1;
        else left=mid+1;
    }

    return index;
}

int main(){
  int size,search;

  cout<<"Enter Size of The Array: ";
  cin>>size;

  vector<int> arr(size);
  cout<<"Enter The Elements of The Array: ";
  for(int i=0;i<size;i++)cin>>arr[i];

  cout<<"Enter Search Item in The Array: ";
  cin>>search;

  cout<<endl;

  cout<<"First Occurences Found at Index: "<<lower_bound(arr,search)<<endl;

  return 0;
}