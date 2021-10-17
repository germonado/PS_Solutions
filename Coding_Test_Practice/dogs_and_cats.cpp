#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    long long t, d, c, n, m;
    scanf("%lld", &t);
    string order;
    for(int i = 0; i < t; i++){
        scanf("%lld %lld %lld %lld", &n, &d, &c, &m);
        cin >> order;
        int num_dog = 0;
        for(int k = 0; k < order.size(); k++){
            if(order[k] == 'D') num_dog++;
        }
        for(int j = 0; j < order.size(); j++){
            if(order[j] == 'D'){
                if(d > 0){
                    d -= 1;
                    num_dog -=1;
                    c += m;
                }
                else break;
            }
            else{
                if(c > 0){
                    c -= 1;
                }
                else break;
            }
        }
        if(num_dog == 0){
            printf("Case #%d: YES\n", i+1);
        }
        else{
            printf("Case #%d: NO\n", i+1);
        }
    }
}