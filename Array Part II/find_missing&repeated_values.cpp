#include <vector>
#include <unordered_set>
using namespace std;

//more optimal solution using math formulas:
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long N = 1LL * n * n; // multiplying by 1LL to avoid overflow(it converts a var in int to long long)

        long long expectedSum = N * (N + 1) / 2;
        long long expectedSqSum = N * (N + 1) * (2 * N + 1) / 6;

        long long actualSum = 0;
        long long actualSqSum = 0;

        for (const auto& row : grid) {
            for (int x : row) {
                actualSum += x;
                actualSqSum += 1LL * x * x;
            }
        }

        long long diff = actualSum - expectedSum; // repeated - missing
        long long sum = (actualSqSum - expectedSqSum) / diff; // repeated + missing

        long long repeated = (diff + sum) / 2;
        long long missing = sum - repeated;

        return {(int)repeated, (int)missing};
    }
};
//less optimal, first thought:
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int> us;
        int repeated=0,missing=0;
        for(auto& row:grid){
            for(int x:row){
                if(us.count(x)){repeated=x;}
                us.insert(x);
            }
        }
        int n=grid.size();
        for(int i=1; i<=n*n; i++){
            if(us.find(i)==us.end()){
                missing=i;
                break;
            }
        }
        return {repeated,missing};
    }
};