#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    string tmp = "ACFJMNRT";
    int lind = 0;
    int rind = 0;
    do{
        int chk = 0;
        for(int i = 0; i < n; i++){
            // equal check
            lind = tmp.find(data[i][0]);
            rind = tmp.find(data[i][2]);
            if(lind > rind){
                swap(lind,rind);
            }
            if(data[i][3] == '='){
                if(rind-lind == data[i][4] - '0' + 1) chk++;
            }
            else if(data[i][3] == '>'){
                if(rind-lind > data[i][4] - '0' + 1) chk++;
            }
            else if(data[i][3] == '<'){
                if(rind-lind < data[i][4] - '0' + 1) chk++;
            }
        }
        if(chk == n) answer++;
	}while(next_permutation(tmp.begin(),tmp.end()));
    
    return answer;
}