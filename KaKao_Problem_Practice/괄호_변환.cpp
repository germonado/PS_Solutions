#include <string>
#include <vector>
#include <stack>
using namespace std;
bool right_string(string s){
    stack<char> st;
    if(s.length() == 0) return true;
    st.push(s[0]);
    for(int i = 1; i < s.length(); i++){
        if(st.empty()) st.push(s[i]);
        if(st.top() == '(' && s[i] ==')'){
            st.pop();
        }
        else st.push(s[i]);
    }
    return st.empty();
}
string find(string s){
    if(s.length() == 0) return "";
    else{
        int l = 0;
        int r = 0;
        int i = 0;
        if(s[0] == '(') l++;
        else r++;
        for(i = 1; i < s.length(); i++){
            if(l==r){
                break;
            }
            else{
                if(s[i] == '(') l++;
                else r++;
            }
        }
        string u = s.substr(0, i);
        string v = s.substr(i);
        if(right_string(u)){
            return u + find(v);
        }
        else{
            for(int i = 1; i < u.length() - 1; i++){
                if(u[i] =='('){
                    u[i] = ')';
                }
                else u[i] = '(';
            }
            return "(" + find(v) + ")" + u.substr(1,u.length()-2);
        }
        
    }
}
string solution(string p) {
    string answer = "";
    if(p.length() == 0) return answer;
    else{
        answer = find(p);
    }
    return answer;
}