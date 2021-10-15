#include <iostream>
#include <stack>
#include <string>
using namespace std;
int solution(string s)
{
    int answer = 0;
    if(s.size() <= 1) return answer;
    stack <char> st;
    int ind = 1;
    st.push(s[0]);
    while(ind < s.length()){
        if(!st.empty()){
            if(st.top() == s[ind]){
                st.pop();
            }
            else st.push(s[ind]);
        }
        else st.push(s[ind]);
        ind++;
    }
    if(st.size() == 0) answer = 1;
    return answer;
}
