#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isPowerOf2(int num) {
    return num > 0 && (num & (num - 1)) == 0;
}

bool isPowerOf4(int num) {
    return isPowerOf2(num) && (num % 3 == 1);
}

int main(){
    
    int num;
    cout<<"Enter a number: ";cin>>num;
    cout<<endl;
    cout<<"Power of 2: "<<(isPowerOf2(num)?"TRUE":"FALSE")<<endl;
    cout<<"Power of 4: "<<(isPowerOf4(num)?"TRUE":"FALSE")<<endl;


    return 0;
}