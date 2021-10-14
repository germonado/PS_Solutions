#include <string>
#include <vector>
#include <iostream>

using namespace std;
string solution(int n) {
    string answer = "";
    int i = 1;
    while(n > 0){
        i = n % 3;
        if(i == 0){
            answer = "4" + answer;
        }
        else if(i == 1){
            answer = "1" + answer;
        }
        else{
            answer = "2" + answer;
        }
        if(i == 0){
            n = n/3;
            n -= 1;
        }
        else n = n/3;
    }
    return answer;
}
