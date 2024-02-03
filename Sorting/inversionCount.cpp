#include<bits/stdc++.h>
using namespace std;

int merge(vector<int>& arr, int left, int mid, int right){
    int i,j,k,size_l,size_r,inversionCount;

    size_l=mid-left+1;
    size_r=right-mid;
    inversionCount=0;

    int L[size_l],R[size_r];

    for(i=0;i<size_l;i++)L[i]=arr[left+i];
    for(j=0;j<size_r;j++)R[j]=arr[mid+1+j];

    i=0;
    j=0;
    k=left;

    while(i<size_l && j<size_r){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
            inversionCount += size_l - i;
        }
        k++;
    }

    while(i<size_l){
        arr[k]=L[i];
        i++;
        k++;
    }

    while(j<size_r){
        arr[k]=R[j];
        j++;
        k++;
    }

    return inversionCount;
}

int merge_sort(vector<int>& arr, int left, int right){
    int inversionCount=0;
    if(left>=right)return 0;

    int mid=left+(right-left)/2;
    inversionCount+=merge_sort(arr,left,mid);
    inversionCount+=merge_sort(arr,mid+1,right);

    inversionCount+=merge(arr,left,mid,right);

    return inversionCount;
}

int numberOfInversions(vector<int>& a, int n) {
    return merge_sort(a, 0, n - 1);
}


int main(){
  int size;

  cout<<"Enter Size of The Array: ";
  cin>>size;

  vector<int> arr(size);
  cout<<"Enter The Elements of The Array: ";
  for(int i=0;i<size;i++)cin>>arr[i];

  cout<<"Number of Inversion: "<<numberOfInversions(arr,size)<<endl;


  return 0;
}