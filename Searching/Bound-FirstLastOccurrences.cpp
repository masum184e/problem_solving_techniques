#include<bits/stdc++.h>
using namespace std;

int first_occurences(vector<int> arr, int item){
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

int last_occurences(vector<int> arr, int item){
    int left,mid,right,index;
    left=0,right=arr.size()-1,index=-1;

    while(left<=right){
        mid=left+(right-left)/2;
        if(arr[mid]==item){
            index=mid;
            left=mid+1;
        }else if(arr[mid]<item)left=mid+1;
        else right=mid-1;
    }

    return index;
}

int custom_lower_bound(vector<int> arr, int item){
    int left,mid,right;
    left=0,right=arr.size();

    while(left<right){
        mid=left+(right-left)/2;
        (arr[mid]<item)?left=mid+1:right=mid;
    }

    return left;
}

int custom_upper_bound(vector<int> arr, int item){
    int left,mid,right;
    left=0,right=arr.size();

    while(left<right){
        mid=left+(right-left)/2;
        (arr[mid]<=item)?left=mid+1:right=mid;
    }

    return left;
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

  cout<<"First Occurences Found at Index: "<<first_occurences(arr,search)<<endl;
  cout<<"Last Occurences Found at Index : "<<last_occurences(arr,search)<<endl;
  cout<<"Lower Bound Found at Index: "<<custom_lower_bound(arr,search)<<endl;
  cout<<"Upper Bound Found at Index : "<<custom_upper_bound(arr,search)<<endl;

  return 0;
}