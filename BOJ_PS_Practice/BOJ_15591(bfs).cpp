#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, q, l, r, usa, v, k;
vector <pair<int, int>> map[5001];
void bfs(int node, int k) {
    int visit[5001] = { 0, };
    queue <pair<int,int>> q;
    visit[node] = 1;
    pair<int, int> bef;
    pair<int, int> aft;
    int minv = 2000000000;
    int answer = 0;
    for (int i = 0; i < map[node].size(); i++) {
        if (map[node][i].second >= k) answer++;
        q.push(make_pair(map[node][i].first, map[node][i].second));
    }
    while (!q.empty()) {
        bef = q.front();
        visit[bef.first] = 1;
        for (int i = 0; i < map[bef.first].size(); i++) {
            if (visit[map[bef.first][i].first] == 0) {
                if (map[bef.first][i].second <= bef.second) {
                    aft = make_pair(map[bef.first][i].first, map[bef.first][i].second);
                }
                else {
                    aft = make_pair(map[bef.first][i].first, bef.second);
                }
                q.push(aft);
                if (aft.second >= k) answer++;
            }
        }
        q.pop();
    }
    printf("%d\n", answer);
}
int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d %d", &l, &r, &usa);
        map[r].push_back(make_pair(l, usa));
        map[l].push_back(make_pair(r, usa));
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &k, &v);
        bfs(v, k);
    }
    return 0;
}