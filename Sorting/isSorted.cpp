#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isSorted(vector<int>& vec, int n) {
    if (n==1||n==0)return true;
    if (vec[n-1]>=vec[n-2] && isSorted(vec, n-1))return true;
    // if (vec[0]<=vec[1] && isSorted(vec+1, n-1))return true;
    return false;
}

int main() {
    int size;

    cout<<"Enter Size of The Array: ";
    cin>>size;

    vector<int> arr(size);
    cout<<"Enter The Elements of The Array: ";
    for(int i=0;i<size;i++)cin>>arr[i];

    cout<<"Sorted Status: "<<isSorted(arr, arr.size())<<endl;

    return 0;
}
