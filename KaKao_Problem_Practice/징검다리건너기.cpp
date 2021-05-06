#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
priority_queue <pair<int,int> > pq;
int solution(vector<int> stones, int k) {
	int ans = 200000001;
	for(int t = 0; t < stones.size(); t++) {
		pq.push(make_pair(stones[t], t));
		while(pq.top().second <= t - k && !pq.empty()){
			pq.pop();
		}
		if(pq.top().first < ans && t >= k - 1){
			ans = pq.top().first;
		}
	}
	return ans;
}
