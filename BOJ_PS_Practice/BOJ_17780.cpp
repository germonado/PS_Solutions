#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int k, n, cnt, x, y, d;
// for stack knight
deque<int> q[15][15];
// for distinguish map color
int board[15][15];
int dir[4][2] = {{0,1}, {0,-1},{-1,0}, {1,0}};
vector <pair<pair<int,int>,int>> knight_info;
vector <int> simulate_q;
int change_direction(int old_d){
    if(old_d == 0){
        return 1;
    }
    else if(old_d == 1){
        return 0;
    }
    else if(old_d == 2){
        return 3;
    }
    else return 2;
}
bool check(int y, int x) {
    return (y>=0 && y < n && x >= 0 && x < n);
}
int dfs(){
    int ny, nx;
    pair<pair<int,int>,int> ptr;
    for(int i = 0; i < k; i++){
        ptr = knight_info[i];
        // knight info
        y = ptr.first.first;
        x = ptr.first.second;
        if(q[y][x].size() == 0) continue;
        if(q[y][x].size() != 0){
            // if the knight is not located bottom, then skip
            if(q[y][x].front() != i){
                continue;
            }
        }
        int tmpdir = ptr.second;
        ny = y + dir[tmpdir][0];
        nx = x + dir[tmpdir][1];
        // if ny, nx is located in map boundary
        if(check(ny, nx)){
            // white
            if(board[ny][nx] == 0){
                while(!q[y][x].empty()){
                    q[ny][nx].push_back(q[y][x].front());
                    knight_info[q[y][x].front()].first.first = ny;
                    knight_info[q[y][x].front()].first.second = nx;
                    q[y][x].pop_front();
                }
                 if(q[ny][nx].size() >= 4) return 1;
            }
            // red
            else if(board[ny][nx] == 1){
                while(!q[y][x].empty()){
                    q[ny][nx].push_back(q[y][x].back());
                    knight_info[q[y][x].back()].first.first = ny;
                    knight_info[q[y][x].back()].first.second = nx;
                    q[y][x].pop_back();
                }
                 if(q[ny][nx].size() >= 4) return 1;
            }
            // blue
            else{
                knight_info[i].second = change_direction(tmpdir);
                tmpdir = knight_info[i].second;
                ny = y + dir[tmpdir][0];
                nx = x + dir[tmpdir][1];
                if(check(ny,nx)){
                    if(board[ny][nx] == 0){
                        // right
                        while(!q[y][x].empty()){
                            q[ny][nx].push_back(q[y][x].front());
                            knight_info[q[y][x].front()].first.first = ny;
                            knight_info[q[y][x].front()].first.second = nx;
                            q[y][x].pop_front();
                        }
                         if(q[ny][nx].size() >= 4) return 1;
                    }
                    // red
                    else if(board[ny][nx] == 1){
                        while(!q[y][x].empty()){
                            q[ny][nx].push_back(q[y][x].back());
                            knight_info[q[y][x].back()].first.first = ny;
                            knight_info[q[y][x].back()].first.second = nx;
                            q[y][x].pop_back();
                        }
                         if(q[ny][nx].size() >= 4) return 1;
                    }
                    if(q[y][x].size() >= 4) return 1;
                }
            }
            if(q[y][x].size() >= 4) return 1;
        }
        // cannot go to next step
        else{
            knight_info[i].second = change_direction(tmpdir);
            tmpdir = knight_info[i].second;
            ny = y + dir[tmpdir][0];
            nx = x + dir[tmpdir][1];
            if(check(ny,nx)){
                if(board[ny][nx] == 0){
                    // right
                    while(!q[y][x].empty()){
                        q[ny][nx].push_back(q[y][x].front());
                        knight_info[q[y][x].front()].first.first = ny;
                        knight_info[q[y][x].front()].first.second = nx;
                        q[y][x].pop_front();
                    }
                        if(q[ny][nx].size() >= 4) return 1;
                }
                // red
                else if(board[ny][nx] == 1){
                    while(!q[y][x].empty()){
                        q[ny][nx].push_back(q[y][x].back());
                        knight_info[q[y][x].back()].first.first = ny;
                        knight_info[q[y][x].back()].first.second = nx;
                        q[y][x].pop_back();
                    }
                    if(q[ny][nx].size() >= 4) return 1;
                }
            }
            if(q[y][x].size() >= 4) return 1;
        }
    }
    return 0;
}
int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            scanf("%d", &board[i][j]);
        }
    }
    for(int i = 0; i < k; i++){
        scanf("%d %d %d", &y, &x, &d);
        knight_info.emplace_back(make_pair(make_pair(y-1,x-1),d - 1));
        q[y-1][x-1].push_back(i);
        simulate_q.push_back(i);
    }
    for(int i = 0; i < 1000; i++){
        if(dfs() == 1){
            printf("%d\n", i+1);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}