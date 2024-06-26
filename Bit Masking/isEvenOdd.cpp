#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isEvenOdd(int a){
    return a&1;
}

int main(){

    int a;cout<<"Enter a number: ";cin>>a;
    cout<<"Odd Status: "<<(isEvenOdd(a)?"TRUE":"FALSE")<<endl;
    
    return 0;
}