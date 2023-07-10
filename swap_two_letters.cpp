#include <iostream>
#include <vector>
#include<climits>
#include<stack>

using namespace std;
bool check(string goal,string s){
    int sdx=-1;
    for(int i=0;i<s.length();i++){
        if(s[i]==goal[i]) continue;
        else{
            if(sdx==-1){ //means first idx not marked
                sdx=i;
            }
            else{
                swap(s[sdx],s[i]);
                break;
            }
        }
    }
    if(s==goal) return true;
    else  return false;
    
}

int main()
{
    //swap two letters in s to form goal
    string goal="starhero";
    string s="otarhers";
    cout<<check(goal,s);
    
    

    return 0;
}
