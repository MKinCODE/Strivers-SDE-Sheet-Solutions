//combination solution:
#include<algorithm>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int N=m+n-2;
        int R=min(m-1,n-1);
        int ans=1;
        for(int i=1; i<=R; i++){
            ans=ans*(N-R+i)/i;      //imp to find only the part we want nd not calculating factorials of all
        }
        return (int)ans;
    }
};