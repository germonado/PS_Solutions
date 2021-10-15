#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
long long answer;
int N;
void find_answer(long long start, long long end, vector<int> v){
    long long mid = 0;
    while(start <= end){
        mid = (start + end)/2;
        long long cnt = 0;
        for(int i = 0; i < v.size(); i++){
            cnt += mid/v[i];
        }
        if(cnt >= N){
            if(cnt == N) answer = mid;
            end = mid - 1;
        }
        else if(cnt < N){
            start = mid + 1;
        }
    }
    answer = start;
    return;
}
long long solution(int n, vector<int> times) {
    N = n;
    sort(times.begin(), times.end());
    long long end = (long long)n * times[times.size() - 1];
    find_answer(1,end,times);
    return answer;
}
