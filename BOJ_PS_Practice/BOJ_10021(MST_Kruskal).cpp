#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int root[2001];
pair<int,int> pos[2001];
int n, c, y, x;
struct cmp{
    bool operator()(pair<int,pair<int,int>>&a, pair<int,pair<int,int>>&b){
        return a.first > b.first;
    }
};
int find(int x){
    if(x == root[x]) return x;
    return root[x] = find(root[x]);
}
void make_set(int left, int right){
    int root_left = find(left);
    int root_right = find(right);
    root[root_left] = root_right;
}
priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,cmp>pq;
int make_irrigation(){
    int ans = 0;
    pair<int,pair<int,int>> tmp;
    int cy, cx, cost;
    for(int i = 0; i < n; i++){
        root[i] = i;
        for(int j = 0; j < n; j++){
            if(i != j){
                cy = pos[i].first - pos[j].first;
                cx = pos[i].second - pos[j].second;
                cost = cy*cy + cx*cx;
                if(cost >= c) pq.push(make_pair(cost, make_pair(i, j)));
            }
        }
    }
    int cnt = 0;
    while(!pq.empty()){
        tmp = pq.top();
        if(find(tmp.second.first) != find(tmp.second.second)){
            ans += tmp.first;
            make_set(tmp.second.first, tmp.second.second);
            cnt++;
            if(cnt == n - 1) break;
        }
        pq.pop();
    }
    if(cnt == n - 1) return ans;
    else return -1;
}
int main() {
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        pos[i] = make_pair(y,x);
    }
    int answer = make_irrigation();
    printf("%d\n", answer);
    return 0;
}