#include <algorithm>
#include<vector>
using namespace std;
//optimal approach: O(N) time and O(1) space
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot=-1;
        int n=nums.size();
        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                pivot=i;
                break;
            }
        }
        if(pivot==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1; i>pivot; i--){
            if(nums[i]>nums[pivot]){
                swap(nums[i],nums[pivot]);
                break;
            }
        }
        reverse(nums.begin()+pivot+1,nums.end());
        return;
    }
};


//brute force: O(N!) very high
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<vector<int>> all;
        vector<int> orig=nums;
        sort(orig.begin(),orig.end());
        do{
            all.push_back(orig);
        }
        while(next_permutation(orig.begin(),orig.end())); //inbuilt fn to generate next permutations

        for(int i=0; i<all.size(); i++){
            if(all[i]==nums){
                if(i==all.size()-1){
                    nums = all[0];
                }
                else{
                nums = all[i+1];
                }
                return;
            }
        }
    }
};