#include <string>
#include <vector>
#include <queue>
#include <string.h>
#include <cmath>
#include <iostream>
#include <cstring>
using namespace std;
struct cmp {
          //연산자 오버로딩
          bool operator()(pair<pair<int, int>,int>&a, pair<pair<int, int>,int>&b) {
              if (a.first.first == b.first.first) {
                  return a.first.second > b.first.second;
              }
              else {
                  return a.first.first < b.first.first;
              }
          }
};
priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>, cmp> pq;
string replace_str(string s){
    if(s.find("C#") != string::npos){
        s.replace(s.find("C#"), 2, "H");
    }
    else if(s.find("D#") != string::npos){
        s.replace(s.find("D#"), 2, "I");
    }
    else if(s.find("F#") != string::npos){
        s.replace(s.find("F#"), 2, "J");
    }
    else if(s.find("G#") != string::npos){
        s.replace(s.find("G#"), 2, "K");
    }
    else if(s.find("A#") != string::npos){
        s.replace(s.find("A#"), 2, "L");
    }
    return s;
}
string solution(string m, vector<string> musicinfos) {
    // 문제 조건을 꼼꼼하게 잘 보고 구현하자,,, 확인해야 할 제약조건이 자잘하게 많음
    string answer = "(None)";
    int hour, min, pretime, aftime;
    if(musicinfos.size() == 0) return answer;
    for(int i = 0; i < musicinfos.size(); i++){
        hour = stoi(musicinfos[i].substr(0,2));
        min = stoi(musicinfos[i].substr(3,2));
        pretime = hour*60 + min;
        hour = stoi(musicinfos[i].substr(6,2));
        min = stoi(musicinfos[i].substr(9,2));
        aftime = hour*60 + min;
        pq.push(make_pair(make_pair(aftime-pretime, pretime), i));
    }
    while(m != replace_str(m)){
        m = replace_str(m);
    }
    while(!pq.empty()){
        int t = pq.top().second;
        int pf = pq.top().first.first;
        string tmp = musicinfos[t].substr(musicinfos[t].rfind(',') + 1);
        while(tmp != replace_str(tmp)){
            tmp = replace_str(tmp);
        }
        if(pf < tmp.size()){
            if(pf == 0) return answer;
            tmp = tmp.substr(0, pf);
        }
        else if(pf > tmp.size()){
            while(pf > tmp.size()){
                tmp += tmp;
            }
            if(tmp.size() > pf){
                tmp = tmp.substr(0, pf);
            }
        }
        if(m.size() < tmp.size()){
            if(tmp.find(m) != string::npos){
                    answer = musicinfos[t].substr(12, musicinfos[t].rfind(',') - 12);
                    break;
            }
        }
        else if(m.size() >= tmp.size()){
            if(m.find(tmp) != string::npos){
                answer =  musicinfos[t].substr(12, musicinfos[t].rfind(',') - 12);
                break;
            }
        }
        pq.pop();
    }
    return answer;
}