#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int bitwiseAdd(int a, int b) {
    while (b != 0) {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

int bitwiseSubtract(int a, int b) {
    while (b != 0) {
        int borrow = (~a) & b;
        a = a ^ b;
        b = borrow << 1;
    }
    return a;
}

int bitwiseMultiply(int a, int b) {
    int result = 0;
    while (b != 0) {
        if (b & 1) {
            result = bitwiseAdd(result, a);
        }
        a <<= 1;
        b >>= 1;
    }
    return result;
}

int bitwiseDivide(int dividend, int divisor) {
    if (divisor == 0) {
        throw invalid_argument("Division by zero");
    }

    int quotient = 0;
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

    unsigned int absDividend = abs(dividend);
    unsigned int absDivisor = abs(divisor);

    for (int i = 31; i >= 0; --i) {
        if ((absDividend >> i) >= absDivisor) {
            absDividend -= absDivisor << i;
            quotient |= 1U << i;
        }
    }

    return sign * quotient;
}

int main(){

    ll a,b;
    cout<<"Enter large number : ";cin>>a;
    cout<<"Enter small number : ";cin>>b;

    cout<<"Addition       :"<<bitwiseAdd(a,b)<<endl;
    cout<<"Subtraction    :"<<bitwiseSubtract(a,b)<<endl;
    cout<<"Multiplication :"<<bitwiseMultiply(a,b)<<endl;
    cout<<"Division       :"<<bitwiseDivide(a,b)<<endl;

    return 0;
}