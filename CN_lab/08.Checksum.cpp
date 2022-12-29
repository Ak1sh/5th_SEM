#include<bits/stdc++.h>
#include<string>
#include <climits>
using namespace std;

int binaryToDecimal(string& str) {
  int sum = 0;
  for (int i = 0; i < str.size(); i++)
    if (str[i] == '1')  sum += (1 << (str.size() - 1 - i));
  return sum;
}
string DecimalToBinary(int num)
{
    string str;
      while(num){
      if(num & 1)
        str+='1';
      else 
        str+='0';
      num>>=1; 
    }  
    int n=str.size();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
      return str;
}

int main() {
 
   string str = "1000100000010001";
   int dividend = binaryToDecimal(str);
   string data;
   cout<<"Enter the data:";
   cin>>data;
   string zeros="0000000000000000";
   string num=data+zeros;
  
  int divisor= binaryToDecimal(num);
  string addon=DecimalToBinary(divisor%dividend);

  string checksum=data+addon;
  cout<<"Checksum is:"<<checksum<<endl;
  int checker=binaryToDecimal(checksum);
  cout<<checker%dividend<<endl;
  return 0;
}
