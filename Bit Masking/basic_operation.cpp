#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int getIthBit(int num, int i) {
    return (num >> i) & 1;
}

int setIthBit(int num, int i) {
    return num | (1 << i);
}

int clearIthBit(int num, int i) {
    return num & ~(1 << i);
}

int toggleIthBit(int num, int i) {
    return num ^ (1 << i);
}

string decimalToBinary(int num) {
    bitset<32> binary(num);
    return binary.to_string();
}

int getLastBit(int num) {
    return num & 1;
}

int removeLastBit(int n) {
    return n & (n - 1);
}

int main(){
    
    int num,i;
    cout<<"Enter a number: ";cin>>num;
    cout<<"On which bit do you want to perform multiple operation: ";cin>>i;

    cout<<"Original Number in Binary: "<<decimalToBinary(num)<<endl;
    cout<<"The "<<i<<"th bit of "<<num<<" is: "<<getIthBit(num, i)<<endl;
    cout<<"After setting bit "<<i<<": "<<setIthBit(num, i)<<endl;
    cout<<"After clearing bit "<<i<<": "<<clearIthBit(num, i)<<endl;
    cout<<"After toggling bit "<<i<<": "<<toggleIthBit(num, i)<<endl;
    cout<<"The last bit of "<<num<<" is: "<<getLastBit(num)<<endl;
    cout<<"Removed last bit of "<<num<<" is: "<<removeLastBit(num)<<endl;

    return 0;
}