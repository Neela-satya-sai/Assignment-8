
#include <iostream>
#include <vector>
#include<climits>
#include<stack>

using namespace std;
bool is_valid_string(string s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        
        if(st.size()==0 && s[i]==')') return false;
        
        else if (st.size()==0 && (s[i]=='(' or s[i]=='*')){
            st.push(s[i]);
        }
        else if(s[i]=='('){  
            if(st.top()==')' or st.top()=='*')  st.pop();
            else st.push(s[i]);
        }
        else if(s[i]==')'){
            if(st.top()=='(' or st.top()=='*') st.pop();
        }
        else if(s[i]=='*'){
            if(st.top()=='(' or st.top()=='*') st.pop();
            
        }
    }
    if(st.size()==0) return true;
    else return false;
}

int main()
{
    //valid string '(',')','*'.
    string s="*((*)((*)*";  //valid string
    cout<<is_valid_string(s);

    return 0;
}
