#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int MOD = 1e9 + 7;

vector<vector<int>> matrix_multiplication(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int size = A.size();
    vector<vector<int>> C(size, vector<int>(size, 0));

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

int matrix_exponentiation_fib(int number, int size){
    vector<vector<int>> identity_matrix(size, vector<int>(size, 0));
	for(int i=0;i<size;i++)identity_matrix[i][i]=1;

    vector<vector<int>> base = {{1, 1}, {1, 0}};

    while(number){
        if(number&1)identity_matrix=matrix_multiplication(identity_matrix, base);
        base=matrix_multiplication(base, base);
        number/=2;
    }

    return (identity_matrix[0][0] + identity_matrix[0][1]) % MOD;
}

int main(){
    
    int a, size;
    cout<<"Enter A Number: ";cin>>a;
    
    // IDENTITY MATRIX SIZE FOR FIBONACCI NUMBERS IS 2
    size=2;

	cout<<a<<"th Fibonacci Number With Matrix Exponentiation: "<<matrix_exponentiation_fib(a, size);

    return 0;
}