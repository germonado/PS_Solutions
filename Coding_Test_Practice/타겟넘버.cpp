#include <string>
#include <vector>
using namespace std;
int tar;
int ans;
void find_target(int bef, vector<int> nums, int ind){
    if(ind == nums.size()){
        if(bef == tar) ans++;
        return;
    }
        find_target(bef+nums[ind], nums, ind+1);
        find_target(bef-nums[ind], nums, ind+1);

}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    tar = target;
    find_target(numbers[0], numbers, 1);
    find_target(-numbers[0], numbers, 1);
    return ans;
}
