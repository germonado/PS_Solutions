#include <string>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int solution(vector<int> scoville, int K) {
    int answer = 0;
    for(int i = 0; i < scoville.size(); i++){
        pq.push(scoville[i]);
    }
    long long first = 0;
    long long second = 0;
    long long new_sco = 0;
    while(!pq.empty()){
        first = pq.top();
        pq.pop();
        if(pq.empty()) break;
        second = pq.top();
        pq.pop();
        if(first >= K && second >= K){
            break;
        }ß
        new_sco = first + (second * 2);
        pq.push(new_sco);
        answer++;
    }
    if(first >= K) return answer;
    else return -1;
}
