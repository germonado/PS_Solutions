#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int visit[26][26][4];
int map[26][26];
// up, right, down, left
// 1. 일단 직선 위주로 가게하기
// 알고보니까 dp를 활용해야함, 같은 방향에서 온 것 까지 반영해서 값 갱신
int srch[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
int m;
int mon;
bool possible(int y, int x){
    return (y>=0 && y < m && x >=0 && x < m);
}
void dfs(int y, int x, int d, int tot){
    if(y == m - 1 && x == m - 1){
        mon = min(tot, mon);
        visit[m-1][m-1][d] = mon;
        return;
    }
    else{
        int ny, nx;
        ny = y + srch[d][0];
        nx = x + srch[d][1];
        if(possible(ny,nx)){
            if((visit[ny][nx][d] >= tot + 100) && map[ny][nx] == 0){
                visit[ny][nx][d] = tot + 100;
                if(tot + 100 < mon){
                    dfs(ny,nx,d,tot+100);
                }
            }
        }
        for(int tmp = 0; tmp < 4; tmp++){
            if(tmp != d){
            ny = y + srch[tmp][0];
            nx = x + srch[tmp][1];
            if(possible(ny,nx)){
                if((visit[ny][nx][tmp] >= tot + 600) && map[ny][nx] == 0){
                    visit[ny][nx][tmp] = tot + 600;
                    if(tot + 600 < mon){
                        dfs(ny,nx,tmp,tot+600);
                    }
                }
            }
        }
        }
    }
}
int solution(vector<vector<int>> board) {
    m = board.size();
    mon = 40000000;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            map[i][j] = board[i][j];
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < 4; k++){
                visit[i][j][k] = 4000000;
            }
        }
    }
    for(int i = 0; i < 4; i++){
        dfs(0,0,i,0);
    }
    return mon;
}