#include <vector>
using namespace std;
//this is the most optimal and clearner sol
//since we cant compare elements from front like in the problem of "median of two sorted arrays" we will compare elements from back and put the greater one at the end of nums1
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return;
        int a1=m-1, a2=n-1;
        int t=m+n-1;
        while(a1>=0 && a2>=0){
            if(nums1[a1]>=nums2[a2]){
                nums1[t]=nums1[a1];
                a1--;
                t--;
            }
            else{
                nums1[t]=nums2[a2];
                a2--;
                t--;
            }
        }
        while(a2>=0){
            nums1[t]=nums2[a2];
            a2--;
            t--;
        }
    }
};