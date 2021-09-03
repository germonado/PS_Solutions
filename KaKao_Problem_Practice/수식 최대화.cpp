#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
char arr[101];
char op[3] = {'-', '*', '+'};
int vis[4];
vector <long long> v;
vector <char> vo;
long long answer;
void calc(int i, vector <long long> v, vector<char> cop, int lev){
    if(lev == 3) return;
    vis[i] = 1;
    long long tmp = 0;
    vector <long long> vtmp;
    vector <char> nc;
    for(int j = 0; j < cop.size(); j++){
        if(cop[j] == op[i]){
            if(op[i] == '-'){
                tmp = v[j] - v[j+1];
                v.erase(v.begin() + j);
                v.erase(v.begin() + j);
                v.insert(v.begin() + j, tmp);
                cop.erase(cop.begin() + j);
                j--;
            }
            else if(op[i] == '*'){
                tmp = v[j] * v[j+1];
                v.erase(v.begin() + j);
                v.erase(v.begin() + j);
                v.insert(v.begin() + j, tmp);
                cop.erase(cop.begin() + j);
                j--;
            }
            else if(op[i] == '+'){
                tmp = v[j] + v[j+1];
                v.erase(v.begin() + j);
                v.erase(v.begin() + j);
                v.insert(v.begin() + j, tmp);
                cop.erase(cop.begin() + j);
                j--;
            }
        }
    }
    if(lev == 2) answer = max(answer, abs(v[0]));
    nc.assign(cop.begin(), cop.end());
    vtmp.assign(v.begin(), v.end());
    for(int t = 0; t < 3; t++){
        if(t != i && vis[t] == 0){
            vis[t] = 1;
            calc(t, vtmp, nc, lev+1);
            vis[t] = 0;
        }
    }
    vis[i] = 0;
}
long long solution(string exp) {
    int prev = 0;
    int cnt = 0;
    for(int i = 0; i < exp.size(); i++){
        if(exp[i] == '-'){
            v.push_back(stoi(exp.substr(prev, i - prev)));
            vo.push_back('-');
            prev = i + 1;
        }
        else if(exp[i] == '*'){
            v.push_back(stoi(exp.substr(prev, i - prev)));
            vo.push_back('*');
            prev = i + 1;
        }
        else if(exp[i] == '+'){
            v.push_back(stoi(exp.substr(prev, i - prev)));
            vo.push_back('+');
            prev = i + 1;
        }
    }
    v.push_back(stoi(exp.substr(prev)));
    if(vo.size() == 0) {
        return v[0];
    }
    for(int i = 0; i < 3; i++){
        vis[i] = 1;
        calc(i, v, vo, 0);
        vis[i] = 0;
    }
    return answer;
}