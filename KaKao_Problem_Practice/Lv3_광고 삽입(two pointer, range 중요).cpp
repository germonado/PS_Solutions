#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
int arr[360000];
string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int start = 0;
    int end = stoi(play_time.substr(0,2)) * 60 * 60 + stoi(play_time.substr(3,2)) * 60 + stoi(play_time.substr(6,2));
    int advtime = stoi(adv_time.substr(0,2)) * 60 * 60 + stoi(adv_time.substr(3,2)) * 60 + stoi(adv_time.substr(6,2));
    for(int i = 0; i < logs.size(); i++){
        int ahour = stoi(logs[i].substr(9,2));
        int amin = stoi(logs[i].substr(12,2));
        int asec = stoi(logs[i].substr(15,2));
        int shour = stoi(logs[i].substr(0,2));
        int smin = stoi(logs[i].substr(3,2));
        int ssec = stoi(logs[i].substr(6,2));
        int endt = ahour * 60 * 60 + amin * 60 + asec;
        int stat = shour * 60 * 60 + smin * 60 + ssec;
        for(int i = stat; i < endt; i++){
            arr[i] += 1;
        }
    }
    int ans = 0;
    long long sum = 0;
    long long maxv = 0;
    for(int i = 0; i < advtime; i++){
        sum += arr[i];
    }
    maxv = sum;
    for(int j = advtime; j < end; j++){
        sum += arr[j];
        sum -= arr[j - advtime];
        if(sum > maxv){
            maxv = sum;
            ans = j - advtime + 1;
        }
    }
    int sec = ans%60;
    ans -= sec;
    int hour = ans/3600;
    ans = ans%3600;
    int min = ans/60;
    if(hour == 0){
        answer += "00";
    }
    else {
        if(hour < 10){
            answer += "0";
        }
        answer += to_string(hour);
    }
    answer += ":";
    if(min == 0){
        answer += "00";
    }
    else{
        if(min < 10){
            answer += "0";
        }
        answer += to_string(min);
    }
    answer += ":";
    if(sec == 0){
        answer += "00";
    }
    else{
        if(sec < 10){
            answer += "0";
        }
        answer += to_string(sec);
    }
    return answer;
}