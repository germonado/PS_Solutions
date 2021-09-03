#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
using namespace std;
set <string> st[512];
int arr[9];
vector <int> vec;
int maxv = 0;
int t, tot;
/* 
    1. 경우의수만큼 set 만들고 담는다
    2. relation안의 튜플과 갯수 같은지 확인 후 vector에 넣는다.
    3. & 연산했는데 어떤 숫자 값이 그대로 나온다는 거는 subset이란 뜻이니까 그런애들은 제외하고 넣는다
    4. 결국 후보 column 들 중에 subset이 아닌 값들만 집어넣어서 만들어 지는 vector 사이즈 return
*/
int solution(vector<vector<string>> relation) {
    int answer = 0;
    t = relation[0].size();
    tot = relation.size();
    for(int i = 0; i < relation.size(); i++){
        for(int j = 1; j < (1 << t); j++){
            string stmp;
            for(int k = 0; k < t; k++){
                if(j & (1 << k)){
                    stmp += relation[i][k] + " ";
                }
            }
            if(st[j].find(stmp) == st[j].end()){
                st[j].insert(stmp);
            }
        }
    }
    for(int i = 1; i < (1 << t); i++){
        if(st[i].size() == tot) {
            int flag = 0;
            for(int k = 0; k < vec.size(); k++){
                if(((i & vec[k]) == vec[k]) || ((i & vec[k]) == i)){
                    flag = 1;
                }
            }  
            if (flag == 0) vec.push_back(i);
        }
    }
    return vec.size();
}