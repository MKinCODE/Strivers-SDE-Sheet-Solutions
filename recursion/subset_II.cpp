#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> temp;
public:
    void solve(int start, vector<int>& nums, int n){
        ans.push_back(temp);
        for(int i=start; i<n; i++){
            if(i>start && nums[i-1]==nums[i]) continue;
            temp.push_back(nums[i]);
            solve(i+1, nums, n);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        solve(0,nums,nums.size());
        return ans;
    }
};