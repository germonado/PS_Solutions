#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <cstring>
using namespace std;
priority_queue <int> start;
int solution(vector<string> lines) {
    int answer = 0;
    unsigned long end = 0;
    unsigned long maxv = 0;
    for(int i = lines.size() - 1; i>= 0; i--){
        int hour = stoi(lines[i].substr(11, 2)) * 60 * 60000;
        int min = stoi(lines[i].substr(14, 2)) * 60000;
        int sec = stoi(lines[i].substr(17, 2)) * 1000;
        int msec = stoi(lines[i].substr(20, 3));
        int cutsec = stoi(string(1,lines[i][24]))* 1000;
        if(lines[i][25] != 's'){
            cutsec += stoi(lines[i].substr(26, lines[i].size() - 26));
        }
        int tot = hour+min+sec+msec;   
        end++;
        while(!start.empty() && (i != lines.size() - 1)){
            if(start.top() - tot >= 999){
                start.pop();
                end--;
            }
            else break;
        }
        start.push(tot - cutsec);
        maxv = max(maxv, end);
    }
    return maxv;
}