#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <map>
#include <set>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    map <string,int> m;
    string str;
    int t = 0;
    if(cacheSize == 0) return cities.size() * 5;
    for(int j = 0; j < cities.size(); j++){
        // if there is no city name to find
        str = cities[j];
        transform(str.cbegin(), str.cend(), str.begin(), ::tolower);
        if(m.find(str) == m.end()){
            answer += 5;
            if(m.size() >= cacheSize){
                int minv = 1000001;
                string name;
                for(auto iter = m.rbegin(); iter != m.rend(); iter++){
                    if((*iter).second < minv){
                        minv = (*iter).second;
                        name = (*iter).first;
                    }
                } 
                m.erase(name);
            }
            m[str] = t++; 
        }
        // exist city name
        else{
            m[str] = t++;
            answer += 1;
        }
    }
    return answer;
}