#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int lock_arr[21][21];
int key_arr[51][51];
int origin_key[21][21];
int turned_key[21][21];
int n, m, cnt_lock;
vector <pair<int,int>> vp;
void turn(){
    int tmp_cnt = 0;
     for(int i =0; i <m; i++){
        for(int j = 0; j <m; j++){
            turned_key[i][j] = 0;
        }
    }
    vp.clear();
    for(int i =0; i <m; i++){
        for(int j = 0; j <m; j++){
            if(origin_key[i][j] == 1){
                turned_key[j][m-1 - i] = 1;
                vp.push_back(make_pair(j, m-1-i));
            }
        }
    }
    for(int i =0; i <m; i++){
        for(int j = 0; j <m; j++){
            origin_key[i][j] = turned_key[i][j];
        }
    }
}
bool possible(int y, int x){
    return y>= 0 && y < n && x >= 0 && x < n;
}
bool check(){
    for(int i = -(m); i < n; i++){
        for(int j = -(m); j < n; j++){
            int cnt = 0;
            int flag = 1;
            for(int t = 0; t < vp.size(); t++){
                int ny = vp[t].first + i;
                int nx = vp[t].second + j;
                if(possible(ny,nx)){
                    if(lock_arr[ny][nx] == 0) {
                        cnt++;
                    }
                    else if(lock_arr[ny][nx] == 1){
                        flag = 0;
                        break;
                    }
                }
            }
            if(cnt == cnt_lock && flag == 1) return true;
        }
    }
   return false;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    m = key.size();
    n = lock.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            lock_arr[i][j] = lock[i][j];
            if(lock[i][j] == 0){
                cnt_lock++;
            }
        }
    }
    if(cnt_lock == 0) return true;
    int key_cnt = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            origin_key[i][j] = turned_key[i][j] = key[i][j];
            if(key[i][j] == 1) {
                vp.push_back(make_pair(i,j));
                key_cnt++;
            }
        }
    }
    // 4 방향 turn 하면서, 지도 움직이기
    int flag = 0;
    for(int k = 0; k < 4; k ++){
        if(check()){
            flag = 1;
        }
        turn();
    }
    if(flag) return true;
    else return false;
}