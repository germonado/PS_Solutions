#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
vector<int> node[20001];
queue<int> q;
int answer = -1;
int check_visit[20001];
void bfs(){
    int tmp = 0;
    while(!q.empty()){
        int qs = q.size();
        answer = qs;
        for(int j = 0; j < qs; j++){
            tmp = q.front();
            check_visit[tmp] = 1;
            q.pop();
            for(int i = 0; i < node[tmp].size(); i++){
                if(check_visit[node[tmp][i]] == 0){
                    check_visit[node[tmp][i]] = 1;
                    q.push(node[tmp][i]);
                }
            }
        }
    }
}
int solution(int n, vector<vector<int>> edge) {
    for(int i = 0; i < edge.size(); i++){
        node[edge[i][0]].push_back(edge[i][1]);
        node[edge[i][1]].push_back(edge[i][0]);
    }
    check_visit[1] = 1;
    q.push(1);
    bfs();
    return answer;
}