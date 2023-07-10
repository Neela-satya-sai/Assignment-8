
#include <iostream>
#include <vector>
#include<climits>
#include<stack>

using namespace std;
int compress(vector<char>& chars) {
        int n=chars.size();
        int k=0;
        int i=0,j=0;
        int c=0;
        while(i<n && j<n){
           if(chars[i]==chars[j]){
               c++;
               j++;
           }
          
           else if(c==1){
                chars[k++]=chars[i];
                c=0;
                i=j;
           }
           else if(c!=1){
                chars[k++]=chars[i];
                string s=to_string(c);
               for(int l=0;l<s.length();l++){
                   chars[k++]=s[l];
               }
               c=0;
               i=j;
           }
              
           
           
        }
        chars[k++]=chars[i];
        if(c!=1)  {
           string s=to_string(c);
               for(int l=0;l<s.size();l++){
                   chars[k++]=s[l];
               }
        }
        

        return k;
    }

int main()
{
    //compress string 
    vector<char> s={'a','a','a','b','c','c','c','d'}; 
    cout<<compress(s);

    return 0;
}
