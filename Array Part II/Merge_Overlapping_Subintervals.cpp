#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& m) {
        vector<vector<int>> ans;
        sort(m.begin(),m.end());
        int n=m.size();
        int low=m[0][0];
        int high=m[0][1];
        for(int i=1; i<n; i++){
            if(m[i][0]<=high){
                high=max(m[i][1],high);
                continue;
            }
            ans.push_back({low,high});
            low=m[i][0];
            high=m[i][1];  
        }
        ans.push_back({low,high});
        return ans;
    }
};