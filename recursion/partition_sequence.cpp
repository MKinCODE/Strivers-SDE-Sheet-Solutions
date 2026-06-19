#include<string>
#include<algorithm>
using namespace std;

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