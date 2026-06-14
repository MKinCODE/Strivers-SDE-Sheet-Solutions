#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        for(int x : nums){
            s.insert(x);
        }
        copy(s.begin(), s.end(), nums.begin());
        return s.size();
    }
};