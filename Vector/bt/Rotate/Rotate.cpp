#include "Rotate.h"


void rotate(vector<int>& nums, int k) {
    if (nums.empty()) return;
    
    k = k % nums.size();
 
    // Reverse the first part
    for (int start = 0, end = nums.size() - k - 1; start < end; start++, end--) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
    }
 
    // Reverse the second part
    for (int start = nums.size() - k, end = nums.size() - 1; start < end; start++, end--) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
    }
 
    // Reverse the whole array
    for (int start = 0, end = nums.size() - 1; start < end; start++, end--) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
    }
}
