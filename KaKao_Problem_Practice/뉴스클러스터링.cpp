#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    map<string,pair<int,int>> m;
    string tmp;
    int intersection = 0;
    int total = 0;
    int str1set = 0;
    int str2set = 0;
    for(int i = 0; i < str1.size() - 1; i++){
        tmp = str1.substr(i,2);
        // 소문자로 바꿈
        transform(tmp.cbegin(), tmp.cend(), tmp.begin(), ::tolower);
        if(!(tmp[0] >= 'a' && tmp[0] <= 'z')) continue;
        if(!(tmp[1] >= 'a' && tmp[1] <= 'z')) continue;
        else{
            // 없으면 합집합 만듬
            if(m.find(tmp) == m.end()){
                m[tmp] = make_pair(1,0);
            }
            // 있으면 
            else{
                m[tmp] = make_pair(m[tmp].first + 1, 0);
            }
        }
    }
    for(int i = 0; i < str2.size() - 1; i++){
        tmp = str2.substr(i,2);
        // 소문자로 바꿈
        transform(tmp.cbegin(), tmp.cend(), tmp.begin(), ::tolower);
        if(!(tmp[0] >= 'a' && tmp[0] <= 'z')) continue;
        if(!(tmp[1] >= 'a' && tmp[1] <= 'z')) continue;
        else{
            // str2에만 있는거
            if(m.find(tmp) == m.end()){
                m[tmp] = make_pair(0,1);
            }
            // 있으면 
            else{
                m[tmp] = make_pair(m[tmp].first, m[tmp].second + 1);
            }
        }
    }
    int fst = 0;
    int sec = 0;
    for(auto iter = m.begin(); iter != m.end(); iter++){
        fst = (*iter).second.first;
        sec = (*iter).second.second;
        if(fst != 0 && sec != 0){
            total += max(fst, sec);
            intersection += min(fst, sec);
        }
        else{
            total += fst;
            total += sec;
        }
    }
    if(total == 0 && intersection == 0) return 65536;
    else if(intersection == 0) return 0;
    else {
        answer = ((float)intersection/total) * 65536;
    }
    return answer;
}