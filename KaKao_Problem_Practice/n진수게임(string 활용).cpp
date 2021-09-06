#include <string>
#include <vector>
#include <iostream>
using namespace std;
char arr[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
char ans[1001];
char gamestr[100001];
int strtmp[11];
string solution(int n, int t, int m, int p) {
    string answer = "";
    int cnt = 0;
    int k = 0;
    int tmp = k;
    int need = t * m;
    while(cnt <= need){
        int stmp = 0;
        tmp = k;
        while(tmp >= n){
            strtmp[stmp++] = tmp % n;
            tmp /= n;
        }
        strtmp[stmp++] = tmp % n;
        for(int i = stmp - 1; i >= 0; i--){
            gamestr[cnt++] = arr[strtmp[i]];
        }
        k++;
    }
    gamestr[cnt] = '\0';
    int anscnt = 0;
    for(int i = p; i <= need; i+= m){
        ans[anscnt++] = gamestr[(i - 1)];
    }
    ans[anscnt] = '\0';
    return ans;
}