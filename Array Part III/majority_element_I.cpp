#include<vector>
#include<algorithm>
using namespace std;
//Boyer-Moore approach- standard
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate=0;
        int count=0;
        for(int num:nums){
            if(count==0) candidate=num;

            if(candidate==num) count++;
            else count--;
        }
        return candidate;
    }
};

//very simple approach
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};