#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {

    queue<int> answer;
    for(int i = 0; i < progresses.size(); i++){
        if((100 - progresses[i]) % speeds[i] == 0){
            answer.push((100 - progresses[i])/speeds[i]);
        }
        else answer.push(((100 - progresses[i])/speeds[i]) + 1);
    }
    vector<int> ans;
    int t = answer.front();
    answer.pop();
    ans.push_back(1);
    int ind = 0;
    while(!answer.empty()){
        if(t >= answer.front()){
            ans[ind]++;
        }
        else{
            t = answer.front();
            ans.push_back(1);
            ind++;
        }
        answer.pop();
    }
    
    return ans;
}
