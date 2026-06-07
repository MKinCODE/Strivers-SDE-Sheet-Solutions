#include<vector>
#include<unordered_map>
using namespace std;
//the most optimal with time and space: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> um;
        for(int i=0; i<nums.size(); i++){
            int need=target-nums[i];
            if(um.count(need)){
                return {um[need],i};
            }
            um[nums[i]]=i;
        }
        return {-1,-1};
    }
};