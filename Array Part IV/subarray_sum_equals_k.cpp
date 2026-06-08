#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int,int>  um;
        um[arr[0]]=0;
        int ans=0;
        for(int i=1; i<arr.size(); i++){
            arr[i]=arr[i]+arr[i-1];
            if(um.find(arr[i])!=um.end()) continue;
            um[arr[i]]=i;
        }
        for(int i=0; i<arr.size(); i++){
            if(arr[i]==k) ans=max(ans,i+1);
            else if(um.find(arr[i]-k)!=um.end()){
                ans=max(ans,i-um[arr[i]-k]);
            }
        }
        return ans;
    }
};
