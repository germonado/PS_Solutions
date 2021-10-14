#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int n;
long long num;
vector<long long> v[9];
bool find(int i){
    if(i == 2){
        for(int j = 0; j < v[i].size(); j++){
            if(v[i][j] == num){
                return true;
            }
        }
        return false;
    }
    else{
        int k = 1;
        for(int j = 0; j <= i; j++){
            k = i - j;
            for(int t = 0; t < v[j].size(); t++){
                for(int l = 0; l < v[k].size(); l++){
                    v[i].push_back(v[j][t] + v[k][l]);
                    if(v[k][l] != 0) v[i].push_back(v[j][t] / v[k][l]);
                    if(v[j][t] != 0) v[i].push_back(v[k][l] / v[j][t]);
                    v[i].push_back(v[j][t] * v[k][l]);
                    v[i].push_back(v[j][t] - v[k][l]);
                    v[i].push_back(v[k][l] - v[j][t]);
                }
            }
        }
        unique(v[i].begin(), v[i].end());
        for(int s = 0; s < v[i].size(); s++){
            if(v[i][s] == num) return true;
        }
    }
    return false;
}
int solution(int N, int number) {
    int answer = -1;
    n = N;
    if(N == number) return 1;
    num = number;
    v[1].push_back(N);
    v[2].push_back(N*N);
    v[2].push_back(1);
    v[2].push_back(N-N);
    v[2].push_back(N+N);
    long long ln = n;
    for(int i = 2; i <= 8; i++){
        ln = ln * 10 + n;
        v[i].push_back(ln);
        if(find(i)){
            return i;
        }
    }
    return answer;
}
