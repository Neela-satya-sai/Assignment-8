
#include <iostream>
#include<bits/stdc++.h>

using namespace std;
//given two  strings  s and p, return an array of all the start indexs of
// p's anagram in s. you may return the answer in any order.

int main()
{
    string s,p;
    cin>>s;      //gigiraffe
    cin>>p;      //gi
    int m=s.size(); //9
    int n=p.size();  //2
    if(n>m)
    {
        cout<<"No anagram exist";
    }
    else
    { vector<int> count_s(26,0), count_p(26,0);
      vector<int> ans;  // to store starting index of s[idx] if the window is an anagram of p. 
      for(int i=0;i<n;i++)  // to count freq of all char of string p.
      {
          count_p[p[i]-'a']++;
      }
      int i=0;
      for(;i<n;i++)          // starting window
      {
        count_s[s[i]-'a']++;  // freq of s[i] to p.size() is add in count_s (window of size n)
      }                         // window size is equal to size of string p.
      bool flag=1;
      for(int j=0;j<26;j++)   //comparision of freq 
      {
          if(count_s[j]!=count_p[j]) 
          {
              flag=0;
              break;
          }
      }
      if(flag) ans.push_back(0);
      
      
      while(i<m)   // still i is at 2   // now window moving process
      {   flag=1;
          count_s[s[i-n]-'a']--;     // removing freq of last ele which is in window
          count_s[s[i]-'a']++;      // adding freq of next ele s[i] to the window
          for(int j=0;j<26;j++)     // checking freq of both s and p.//if false then window elements 
                                    // are not anagram.
          {
             if(count_s[j]!=count_p[j]) 
              {
                flag=0;
                break;
              }
          }
          if(flag) ans.push_back(i-n+1);
          i++;
      }
      cout<<"starting indexs of p's anagram in s are: "<<endl;
      for(auto x:ans)
       cout<<x<<" ";
      
      
        
    }

    return 0;
}
