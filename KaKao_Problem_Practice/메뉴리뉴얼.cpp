#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
int cos[11];
int check[11];
vector<string> str_ans[11];
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<string, int> m;
    for(int i =0; i < course.size(); i++){
        cos[course[i]] = 1;
    }
    for(int i = 0; i < orders.size(); i++){
        sort(orders[i].begin(), orders[i].end());
        int i_length = orders[i].size();
        for(int j = 0; j < (1 << i_length); j++){
            char carr[11];
            int cnt = 0;
            for(int k= 0; k < i_length; k++){
                if(j&(1 << k)){
                    carr[cnt++] = orders[i][k];
                }
            }
            carr[cnt] = '\0';
            if(cnt >= 2){
                string tmp = carr;
                if(m.find(tmp) == m.end()){
                    m[tmp] = 1;
                }
                else {
                    m[tmp] = m[tmp] + 1;
                    int t = m[tmp];
                    if(check[tmp.size()] < t){
                        check[tmp.size()] = t;
                        str_ans[tmp.size()].clear();
                        str_ans[tmp.size()].push_back(tmp);
                    }
                    else if(check[tmp.size()] == t){
                        str_ans[tmp.size()].push_back(tmp);
                    }
                }
            }
        }
    }
    for(int i = 0; i < course.size(); i++){
            for(int j = 0; j < str_ans[course[i]].size(); j++){
                answer.push_back(str_ans[course[i]][j]);
            }
    }
    sort(answer.begin(), answer.end());
    return answer;
}