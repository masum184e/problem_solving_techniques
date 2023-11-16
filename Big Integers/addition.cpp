#include<bits/stdc++.h>
using namespace std;
#define ll long long int
string bigAddition(string str1,string str2){
  ll mx,mn;
  mx=max(str1.size(),str2.size());
  mn=min(str1.size(),str2.size());

  string tmp="";
  for(ll i=0;i<mx-mn;i++)tmp+='0';
  (str1.size()==mx)?str2=tmp+str2:str1=tmp+str1;

  string add="";
  ll carry=0,sum;
  while(mx--){
    sum=int(str1[mx])-48+int(str2[mx])-48+carry;
    if(sum>9){
      carry=sum/10;
      sum=sum%10;   
    }else{
      carry=0;
    }
    add+=char(sum)+48;
  }
  if(carry)add+=char(carry)+48;

  reverse(add.begin(),add.end());

  return add;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string str1,str2;
  cin>>str1>>str2;

  cout<<bigAddition(str1,str2)<<endl;
  
  return 0;
}
