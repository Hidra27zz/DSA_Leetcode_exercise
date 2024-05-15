#include "RemoveDuplicates.h"


int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    
    int writePointer = 1;
    for (int readPointer = 1; readPointer < nums.size(); readPointer++) {
        if (nums[readPointer] != nums[readPointer - 1]) {
            nums[writePointer] = nums[readPointer];
            writePointer++;
        }
    }
    
    return writePointer;
}