void reverse(vector<int>& nums, int start, int end) {
    while (start < end) {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}

void rotate(vector<int>& nums, int k) {
    if (nums.empty()) {
        return; // Exit if the array is empty
    }

    k = k % nums.size(); // Normalize rotation steps

    // Reverse the first part of the array
    int start = 0;
    int end = nums.size() - k - 1;
    while (start < end) {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }

    // Reverse the second part of the array
    start = nums.size() - k;
    end = nums.size() - 1;
    while (start < end) {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }

    // Reverse the entire array
    start = 0;
    end = nums.size() - 1;
    while (start < end) {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}