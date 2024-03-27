#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){

    ll count;
    float totalDays, availAbaleDays, percentage;
    count=0;
    totalDays=365;
    availAbaleDays=365;

    float prob_diff_bday=1;

    cout<<"Enter percentage of probability: ";
    cin>>percentage;

    while(prob_diff_bday>(percentage/100)){
        prob_diff_bday*=(availAbaleDays/totalDays);
        availAbaleDays--;
        count++;
    }

    cout<<"Total People: "<<count<<endl;

    return 0;
}