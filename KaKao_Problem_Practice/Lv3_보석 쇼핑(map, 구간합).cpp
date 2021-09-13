#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;
map <string,int> m;
int minv = 20000000;
int arr[100005];
vector<int> solution(vector<string> gems) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    int left = 0;
    int right = 0;
    int cnt = 0;
    int t = gems.size();
    for(int k = 0; k < t; k++){
        m[gems[k]] = 0;
    }
    int gems_size = m.size();
    for(int i = 0; i < t; i++){
        if(cnt != gems_size){
            if(m[gems[i]] == 0){
                cnt += 1;
                m[gems[i]] += 1;
                right = i;
            }
            else{
                m[gems[i]] += 1;
                right = i;
            }
        }
        while(cnt == gems_size){
            if(minv > (right-left)){
                minv = right-left;
                answer[0] = left;
                answer[1] = right;
            }
            if(m[gems[i]] == 0){
                cnt += 1;
                m[gems[i]] += 1;
                right = i;
            }
            else{
               if(m[gems[left]] == 1){
                    cnt -= 1;
                    m[gems[left]] -= 1;
                }   
                else {
                    m[gems[left]] -=1;
                }
                left++;
            }
        }
    }
    answer[0]+=1;
    answer[1]+=1;
    return answer;
}