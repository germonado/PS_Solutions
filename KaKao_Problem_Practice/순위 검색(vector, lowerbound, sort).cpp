#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <set>
using namespace std;
vector<int> smap[4][3][3][3];
int value_mapping(int N, char C) {
    if (N == 1)
    {
        if (C == 'c') return 1;
        if (C == 'j') return 2;
        if (C == 'p') return 3;
    }
    else if (N == 2)
    {
        if (C == 'b') return 1;
        if (C == 'f') return 2;
    }
    else if (N == 3)
    {
        if (C == 'j') return 1;
        if (C == 's') return 2;
    }
    else if (N == 4)
    {
        if (C == 'c') return 1;
        if (C == 'p') return 2;
    }

    return 0;
}
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    int ind = 0;
    int sco = 0;
    int cnt = 0;
    int L, W, C, F;
    for (int j = 0; j < info.size(); j++) {
        // language
        L = value_mapping(1, info[j][0]);
        ind = info[j].find(' ');
        // cate
        W = value_mapping(2, info[j][ind + 1]);
        // career
        ind = info[j].find(' ', ind + 1);
        C = value_mapping(3, info[j][ind + 1]);
        // soul
        ind = info[j].find(' ', ind + 1);
        F = value_mapping(4, info[j][ind + 1]);
        // score
        ind = info[j].find(' ', ind + 1);
        sco = stoi(info[j].substr(ind + 1));
        smap[L][W][C][F].push_back(sco);
        smap[0][W][C][F].push_back(sco);
        smap[L][0][C][F].push_back(sco);
        smap[L][W][0][F].push_back(sco);
        smap[L][W][C][0].push_back(sco);
        smap[0][0][C][F].push_back(sco);
        smap[0][W][0][F].push_back(sco);
        smap[0][W][C][0].push_back(sco);
        smap[L][0][0][F].push_back(sco);
        smap[L][0][C][0].push_back(sco);
        smap[L][W][0][0].push_back(sco);
        smap[0][0][0][F].push_back(sco);
        smap[L][0][0][0].push_back(sco);
        smap[0][W][0][0].push_back(sco);
        smap[0][0][C][0].push_back(sco);
        smap[0][0][0][0].push_back(sco);
    }
    for(int i = 0; i < 4; i++){
        for(int j =0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                for(int l = 0; l < 3; l++){
                    sort(smap[i][j][k][l].begin(), smap[i][j][k][l].end());
                }
            }
        }
    }
    for (int j = 0; j < query.size(); j++) {
        // language 
        L = value_mapping(1, query[j][0]);
        ind = query[j].find("and");
        // cate
        W = value_mapping(2, query[j][ind + 4]);
        // career
        ind = query[j].find("and", ind + 4);
        C = value_mapping(3, query[j][ind + 4]);
        // soul
        ind = query[j].find("and", ind + 4);
        F = value_mapping(4, query[j][ind + 4]);
        // score
        ind = query[j].find(' ', ind + 4);
        sco = stoi(query[j].substr(ind + 1));
        ind = lower_bound(smap[L][W][C][F].begin(), smap[L][W][C][F].end(), sco) - smap[L][W][C][F].begin();
        answer.push_back(smap[L][W][C][F].size() - ind);
    }
    return answer;
}