#include<iostream>
using namespace std;
#include<string>

int main()
{
   string str1,str2,str3;
   cout<<"\nEnter a string : ";
   cin>>str1;
   cout<<"\nEnter second string : ";
   cin>>str2;
   str3 = str1 + str2;
   cout<<"\nConcatinate string is : "+str3+"\n"<<str3.size();


   return 0;
}

