#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> us(nums.begin(),nums.end());
        int length;
        long long curr;
        int best=1;
        for(int num:us){
            if(us.find(num-1)==us.end()) {
               curr=num;
               length=1;
               while(us.count(curr+1)){
                curr++;
                length++;
               }
               best=max(length,best);
            }
            
        }
        return best;
    }
};