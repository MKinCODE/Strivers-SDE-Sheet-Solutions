#include<vector>
#include<algorithm>
using namespace std;

//using global variable
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> temp;
    int sum=0;
public:
    void recurse(int index, vector<int>& nums, int n, int target){
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        for(int i=index; i<n; i++){
            if(i>index && nums[i-1]==nums[i]) continue;
            if(sum+nums[i]>target) break;
            sum+=nums[i];
            temp.push_back(nums[i]);
            recurse(i+1,nums,n,target);
            sum-=nums[i];
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        recurse(0,candidates,candidates.size(),target);
        return ans;
    }
};

//using as parameter
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> temp;
    int sum=0;
public:
    void recurse(int index, vector<int>& nums, int n, int remaining){
        if(remaining==0){
            ans.push_back(temp);
            return;
        }
        for(int i=index; i<n; i++){
            if(i>index && nums[i-1]==nums[i]) continue;
            if(nums[i]>remaining) break;
            temp.push_back(nums[i]);
            recurse(i+1,nums,n,remaining-nums[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        recurse(0,candidates,candidates.size(),target);
        return ans;
    }
};