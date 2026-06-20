#include<string>
#include<algorithm>
#include<vector>
using namespace std;
//most cleaner and optimal by removing computing fact again and again
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i=1; i<=n; i++){
            nums.push_back(i);
        }
        k--;
        string ans="";
        int fact=1;
        for(int i=1; i<=n; i++){
            fact*=i;
        }
        while(n>1){
            fact=fact/n;
            int index=k/fact;
            ans+=nums[index]+'0';
            nums.erase(nums.begin()+index);
            k%=fact;
            n--;
        }
        return ans+=(nums[0]+'0');
    }
};


//more optimal
class Solution {
public:
    int fact(int n){
        int ans=1;
        for(int i=1; i<=n; i++){
            ans*=i;
        }
        return ans;
    }
    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i=1; i<=n; i++){
            nums.push_back(i);
        }
        k--;
        string ans="";
        while(n>1){
            int facto=fact(n-1);
            int index=k/facto;
            ans+=nums[index]+'0';
            nums.erase(nums.begin()+index);
            k%=facto;
            n--;
        }
        return ans+=(nums[0]+'0');
    }
};


//less optimal
class Solution {
public:
    string getPermutation(int n, int k) {
        string s="";
        for(int i=1;i<=n;i++){
            char c = i + '0';
            s+=c;
        }
        int count=0;
        do{
            count++;
            if(count==k) break;
        }while(next_permutation(s.begin(),s.end()));
        return s;
    }
};
