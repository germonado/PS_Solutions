#include <string>
#include <vector>
#include <iostream>
using namespace std;
int N;
int graph[201][201];
void initialize(){
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            if(i == j) graph[i][j] = 0;
            else graph[i][j] = 987654321;
        }
    }
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    N = n;
    int answer = 987654321;
    initialize();
    for(int i = 0; i < fares.size(); i++){
        graph[fares[i][0]][fares[i][1]] = fares[i][2];
        graph[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    for (int k = 0; k <= n; k++) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        int tmp = 0;
        if(i != s){
            if(graph[s][i] == 987654321 || graph[i][a] == 987654321 || graph[i][b] == 987654321) continue;
            tmp = graph[s][i] +  graph[i][a] +  graph[i][b];
            answer = min(answer, tmp);
            if(graph[s][a] == 987654321 || graph[s][b] == 987654321) continue;
            tmp = graph[s][a] +  graph[s][b];
            answer = min(answer, tmp);
        }
    }
    return answer;
}