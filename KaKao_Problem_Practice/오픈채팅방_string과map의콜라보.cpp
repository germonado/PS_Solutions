#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string,string> m;
    vector<pair<int, string>> v;
    string uid;
    for(int i = 0; i < record.size(); i++){
        int uid_location = record[i].find(' ') + 1;
        // Enter
        if(record[i][0] == 'E'){
            int name_location = record[i].find(' ',uid_location);
            string uid = record[i].substr(uid_location, name_location - uid_location);
            m[uid] = record[i].substr(name_location+1);
            v.push_back(make_pair(0,uid));
        }
        // Leave
        else if(record[i][0] == 'L'){
            string uid = record[i].substr(uid_location);
            v.push_back(make_pair(1,uid));
        }
        // Change
        else if(record[i][0] == 'C'){
            int name_location = record[i].find(' ',uid_location);
            string uid = record[i].substr(uid_location, name_location - uid_location);
            m[uid] = record[i].substr(name_location+1);
        }
    }
    for(int i = 0; i < v.size(); i++){
        // Enter
        if(v[i].first == 0){
            answer.push_back(m[v[i].second] + "님이 들어왔습니다.");
        }
        // Leave
        else{
            answer.push_back(m[v[i].second] + "님이 나갔습니다.");
        }
    }
    return answer;
}