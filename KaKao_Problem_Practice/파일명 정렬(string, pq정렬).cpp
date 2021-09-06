#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cctype>
#include <string.h>
using namespace std;
struct cmp {
          bool operator()(pair<pair<string, int>,int>&a, pair<pair<string, int>,int>&b) {
              if (a.first.first != b.first.first){
                  return a.first.first.compare(b.first.first) > 0;
              }
              else if ((a.first.first == b.first.first) && (a.first.second == b.first.second)) {
                  return a.second > b.second;
              }
              else if(a.first.first == b.first.first){
                  return a.first.second > b.first.second;
              }
              else {
                  return a.first.first < b.first.first;
              }
          }
};
priority_queue<pair<pair<string,int>,int>, vector<pair<pair<string,int>,int>>,cmp> pq;
vector<string> solution(vector<string> files) {
    vector<string> answer;
    int start = 0;
    int end = 0;
    int flag = 0;
    int tmpnum = 0;
    string tmphead = "";
    for(int i = 0 ; i < files.size(); i++){
        flag = 0;
        start = end = 0;
        for(int j = 0; j < files[i].size(); j++){
            if((files[i][j] >= '0' && files[i][j] <= '9') && flag == 0 ){
                start = end = j;
                flag = 1;
            }
            else if((files[i][j] >= '0' && files[i][j] <= '9') && flag == 1){
                end = j;
            }
        }
        tmphead = files[i].substr(0, start);
        transform(tmphead.cbegin(), tmphead.cend(), tmphead.begin(), ::tolower);
        tmpnum = stoi(files[i].substr(start, end - start + 1));
        pq.push(make_pair(make_pair(tmphead, tmpnum), i));
    }
    while(!pq.empty()){
        answer.push_back(files[pq.top().second]);
        pq.pop();
    }
    return answer;
}