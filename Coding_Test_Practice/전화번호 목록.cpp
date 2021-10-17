#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
set <string> s;
bool solution(vector<string> phone_book) {
    bool answer = true;
    for(int i = 0; i < phone_book.size(); i++){
        int cnt = 0;
        for(int j = 1; j < phone_book[i].length(); j++){
                string tmp = phone_book[i].substr(0, j);
                if(s.find(tmp) == s.end()){
                    s.insert(tmp);
                }
        }
    }
    for(int i = 0; i < phone_book.size(); i++){
        if(s.find(phone_book[i]) != s.end()) return false;
    }
    return answer;
}