#include <vector>
using namespace std;

//dutch national flag algorithm: take 2's to the end and 0's to beginning and 1's will be in the middle automatically
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;                          // keep track of 0s
        int mid=0;                          //used to traverse the array
        int high=nums.size()-1;             //keep track of 2s
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};

//cleaner code of counting sort
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int arr[3]={0};
        for(int num:nums){
            arr[num]++;
        }
        int i=0;
        for(int c=0; c<3; c++){
            while(arr[c]--){
                nums[i++]=c;
            }
        }
    }
};

//my approach: counting sort
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int arr[3]={0,0,0};
        for(int num:nums){
            if(num==0) arr[0]++;
            else if(num==1) arr[1]++;
            else arr[2]++;
        }
        int i=0;
        while(arr[0]!=0){
            nums[i]=0;
            i++;
            arr[0]--;
        }
        while(arr[1]!=0){
            nums[i]=1;
            i++;
            arr[1]--;
        }
        while(arr[2]!=0){
            nums[i]=2;
            i++;
            arr[2]--;
        }
    }
};