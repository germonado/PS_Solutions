#include <string>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int tree[5001];
long long dp[5001];
int main(){
    int n, k, t;
    scanf("%d", &t);
    for(int tt = 0; tt < t; tt++){
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++){
            scanf("%d", &tree[i]);
        }
            memset(dp,0,sizeof(dp));
            dp[0] = tree[0];
            for(int j = 1; j < n; j++){
                dp[j] = tree[j] + dp[j-1];
            }
            int minlen = 987654321;
            for(int j = 0; j < n; j++){
                for(int x = 0; x <= j; x++){
                for(int l = 0; l < x; l++){
                    for(int v = -1; v <= l; v++){
                        if(v == -1){
                            if(dp[j] - dp[x] + dp[l] == k){
                            
                            if(minlen > (j - x) + l+1){
                             cout << "v== -1 TT " << tt+ 1  << " " << j << " " << x << " " << l << " " << v << endl;
                                cout << " section " << dp[j] - dp[x] << " section2 " << dp[l] << endl;
                                minlen = (j - x) + (l+1);
                            }
                            }
                        }
                        else{
                            if(dp[j] - dp[x] + dp[l] - dp[v] == k){
                                if(minlen > (j - x) + (l - v)){
                                      cout << "else " << tt+ 1  << " " << j << " " << x << " " << l << " " << v << endl;
                                cout << " section " << dp[j] - dp[x] << " section2 " << dp[l] - dp[v] << endl;
                                //   cout << " TT " << tt+ 1  << " " << j << " " << l << " " << v << endl;
                                //    cout << " section " << dp[n - 1] - dp[j] << " section2 " << dp[l] - dp[v] << endl;
                                    minlen = (j - x) + (l - v);
                                }
                            }
                        }
                    }
                }
                }
            }
            /*
            for(int i = 0; i < n; i++){
                if(tree[i] == k) minlen = 1;
            }*/
            for(int i = 0; i < n; i++){
                for(int g = 0 ; g <= i; g++){
                    if(dp[i] - dp[g] == k) minlen = min(minlen, i-g);
                }
            }
            if(minlen == 987654321) {
                printf("Case #%d: %d\n", tt+1, -1);
            }
            else printf("Case #%d: %d\n", tt+1, minlen);
    }
}