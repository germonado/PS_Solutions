#include <string>
#include <vector>
#include <string.h>
#include <iostream>
using namespace std;
vector <char> vec[31];
int copymap[31][31];
int ans;
int gm, gn;
int leftup[3][2] = {{0,-1}, {-1,-1}, {-1,0}};
int leftdown[3][2] = {{0,-1},{1,-1},{1,0}};
int rightup[3][2] = {{0,1}, {-1,1}, {-1,0}};
int rightdown[3][2] = {{0,1}, {1,1}, {1,0}};
bool check(int y, int x){
    return (y < vec[x].size() && y >=0 && x < gn && x >=0);
}
void check_map(int y, int x){
    int cnt = 0;
    // leftup
    for(int i = 0; i < 3; i++){
        int ny = leftup[i][0] + y;
        int nx = leftup[i][1] + x;
        if(check(ny, nx)){
            if(vec[nx][ny] == vec[x][y]){
                cnt++;
            }
        }
        else break;
    }
    if(cnt == 3){
        copymap[x][y] = 1;
        for(int i = 0; i < 3; i++){
        int ny = leftup[i][0] + y;
        int nx = leftup[i][1] + x;
        copymap[nx][ny] = 1;
        }
    }
    cnt = 0;
    // rightup
    for(int i = 0; i < 3; i++){
        int ny = rightup[i][0] + y;
        int nx = rightup[i][1] + x;
        if(check(ny, nx)){
            if(vec[nx][ny] == vec[x][y]){
                cnt++;
            }
        }
        else break;
    }
    if(cnt == 3){
        copymap[x][y] = 1;
        for(int i = 0; i < 3; i++){
        int ny = rightup[i][0] + y;
        int nx = rightup[i][1] + x;
        copymap[nx][ny] = 1;
        }
    }
    cnt = 0;
    // leftdown
    for(int i = 0; i < 3; i++){
        int ny = leftdown[i][0] + y;
        int nx = leftdown[i][1] + x;
        if(check(ny, nx)){
            if(vec[nx][ny] == vec[x][y]){
                cnt++;
            }
        }
        else break;
    }
    if(cnt == 3){
        copymap[x][y] = 1;
        for(int i = 0; i < 3; i++){
        int ny = leftdown[i][0] + y;
        int nx = leftdown[i][1] + x;
        copymap[nx][ny] = 1;
        }
    }
    cnt = 0;
    // rightdown
    for(int i = 0; i < 3; i++){
        int ny = rightdown[i][0] + y;
        int nx = rightdown[i][1] + x;
        if(check(ny, nx)){
            if(vec[nx][ny] == vec[x][y]){
                cnt++;
            }
        }
        else break;
    }
    if(cnt == 3){
        copymap[x][y] = 1;
        for(int i = 0; i < 3; i++){
        int ny = rightdown[i][0] + y;
        int nx = rightdown[i][1] + x;
        copymap[nx][ny] = 1;
        }
    }
    
}
int bomb(){
    int flag = 0;
    memset(copymap, 0, sizeof(copymap));
    for(int i = 0; i < gn; i++){
        for(int j = 0; j < vec[i].size(); j++){
            check_map(j,i);
        }
    }
    for(int i = 0; i < gn; i++){
        int height = 0;
        int mapheight = vec[i].size();
        for(int j = 0; j < mapheight; j++){
            if(copymap[i][j] == 1){
                copymap[i][j] = 0;
                flag = 1;
                ans += 1;
                vec[i].erase(vec[i].begin() + j - height);
                height += 1;
            }
        }
    }
    cout << endl;
    return flag;
}
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    gm = m; // 세로
    gn = n; // 가로
    // 바닥이 밑이니까 거꾸로 채우기 (0 부터 바닥, i 는 y)
    for(int j = 0; j < n; j++){
        for(int i = m - 1; i >= 0; i--){
            vec[j].push_back(board[i][j]);
        }
    }
    int tmp = 0;
    do{
        tmp = bomb();
    }
    while(tmp != 0);
    return ans;
}