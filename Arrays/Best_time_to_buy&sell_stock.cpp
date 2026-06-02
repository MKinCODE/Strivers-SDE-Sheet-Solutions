#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minstock=prices[0];
        int maxp=0;
        for(int i=1; i<prices.size(); i++){
            minstock=min(minstock,prices[i]);
            maxp=max(maxp,(prices[i]-minstock));
        }
        return maxp;
    }
};
//by changing the initialisation of minstock to INT_MAX, we can handle the case when prices array is empty as well. In that case, maxp will remain 0 and will be returned as expected. also runtime decreases as we are not comparing minstock with prices[0] in the first iteration.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minstock=INT_MAX;
        int maxp=0;
        for(int i=0; i<prices.size(); i++){
            minstock=min(minstock,prices[i]);
            maxp=max(maxp,(prices[i]-minstock));
        }
        return maxp;
    }
};