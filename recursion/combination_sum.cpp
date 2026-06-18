#include<vector>
#include<algorithm>
using namespace std;
//my approach using extra sum - runtime 0ms
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> temp;
    int sum=0;
public:
    void helper(int index, vector<int>& nums, int target, int n){
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        if(sum>target) return;
        for(int i=index;i<n; i++){
            sum+=nums[i];
            if(sum>target){
                sum-=nums[i];
                break;
            } 
            temp.push_back(nums[i]);
            helper(i,nums,target,n);
            sum-=nums[i];
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        helper(0,candidates,target,candidates.size());
        return ans;
    }
};

//using remaining approach - runtime 2ms
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> temp;
public:
    void helper(int index, vector<int>& nums, int remaining, int n){
        if(remaining==0){
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<n; i++){
            if(nums[i]>remaining)
                break;
            temp.push_back(nums[i]);
            helper(i,nums,remaining-nums[i],n);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        helper(0,candidates,target,candidates.size());
        return ans;
    }
};