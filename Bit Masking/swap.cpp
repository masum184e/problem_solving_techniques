#include <bits/stdc++.h>
using namespace std;
#define ll long long int

pair<int, int> swapNumber(int a, int b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    return make_pair(a, b);
}

int main(){

    ll a,b;
    cout<<"Enter first number : ";cin>>a;
    cout<<"Enter second number : ";cin>>b;

    pair<int, int> swapped=swapNumber(a,b);
    cout<<"First Number: "<<swapped.first<<endl;
    cout<<"First Second: "<<swapped.second<<endl;

    return 0;
}