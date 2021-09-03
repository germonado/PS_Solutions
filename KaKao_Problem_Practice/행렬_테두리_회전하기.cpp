#include <string>
#include <vector>
#include <iostream>
using namespace std;
int arr[101][101];
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    int cnt = 1;
    for(int i = 1; i <= rows; i++){
        for(int j = 1 ; j <= columns; j++){
            arr[i][j] = cnt++;
        }
    }
    vector<int> answer;
    for(int i = 0; i < queries.size(); i++){
        int min = 200000;
        int y_diff = queries[i][2] - queries[i][0];
        int x_diff = queries[i][3] - queries[i][1];
        int sy = queries[i][0];
        int sx = queries[i][1];
        int ey = queries[i][2];
        int ex = queries[i][3];
        int start_v = arr[sy+1][sx];
        int prev = arr[sy][sx];
        int current = 0;
        if(min > prev) min = prev;
        for(int i = 1; i <= x_diff; i++){
            if(min > prev) min = prev;
            current = arr[sy][sx+i];
            arr[sy][sx+i] = prev;
            prev = current;
        }
        for(int i = 1; i <= y_diff; i++){
            if(min > prev) min = prev;
            current = arr[sy+i][ex];
            arr[sy+i][ex] = prev;
            prev = current;
        }
        for(int i = 1; i <= x_diff; i++){
            if(min > prev) min = prev;
            current = arr[ey][ex - i];
            arr[ey][ex - i] = prev;
            prev = current;
        }
        for(int i = 1; i <= y_diff; i++){
            if(min > prev) min = prev;
            current = arr[ey -i][sx];
            arr[ey - i][sx] = prev;
            prev = current;
        }
        arr[sy][sx] = start_v;
        if(min > prev) min = prev;
        answer.push_back(min);
    }
    return answer;
}