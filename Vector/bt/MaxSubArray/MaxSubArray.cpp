#include "MaxSubarray.h"


int maxSubarray(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
 
    int maxSum = nums[0];
    int currentSum = nums[0];
 
    for (int i = 1; i < nums.size(); i++) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }
 
    return maxSum;

}