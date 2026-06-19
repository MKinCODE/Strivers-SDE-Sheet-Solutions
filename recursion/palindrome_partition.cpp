#include<vector>
#include<string>
using namespace std;

class Solution {
private:
    vector<vector<string>> ans;
    vector<string> temp;
public:
    bool isPalindrome(string& s, int l, int h){
        while(l<=h){
            if(s[l]!=s[h])return false;
            l++;
            h--;
        }
        return true;
    }
    void recurse(string& s, int start){
        if(start==s.length()){
            ans.push_back(temp);
            return;
        }
        for(int end=start; end<s.length(); end++){
            if(isPalindrome(s,start,end)){
                temp.push_back(s.substr(start,end-start+1));
                recurse(s,end+1);
                temp.pop_back();
            }
            
        }
    }
    vector<vector<string>> partition(string s) {
        recurse(s,0);
        return ans;
    }
};