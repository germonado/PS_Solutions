#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cstring>
using namespace std;
map <string, int> m;
vector<int> solution(string msg) {
    vector<int> answer;
    for(int i = 0; i < 26; i++){
        m[string(1,65+i)] = i+1;
    }
    char arr[1001];
    strcpy(arr, msg.c_str());
    int cnt = 27;
    int i = 0;
    char bigyo[1001];
    int t = 0;
    while(i < msg.size()){
        t = i;
        int tmp = 0;
        while(t < msg.size()){
            bigyo[tmp++] = arr[t++];
            bigyo[tmp] = '\0';
            if(m.find(bigyo) == m.end()){
                break;
            }
        }
        if((m.find(bigyo) != m.end()) && t == msg.size()){
            answer.push_back(m[bigyo]);
            break;
        }
        m[bigyo] = cnt++;
        bigyo[tmp - 1] = '\0';
        answer.push_back(m[bigyo]);
        i += tmp - 1;
        if(i == msg.size() - 1){
            answer.push_back(m[string(1,msg.back())]);
            break;
        }
        else if(i >= msg.size()){
            break;
        }
    }
    return answer;
}