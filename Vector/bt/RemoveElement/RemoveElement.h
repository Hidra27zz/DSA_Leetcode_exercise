/*
Vector: Remove Element ( ** Interview Question)
Title: Remove Specific Element from an Array

Introduction: Imagine you have a collection of items (represented by numbers), and you want to get rid of every occurrence of a specific item without using extra storage or another collection. The task is to perform this action using as minimal space as possible and in the most efficient way.

Objective: Write a function that takes in two parameters: a list of numbers (nums) and a target number (val). The goal is to remove all occurrences of the target number from the list without creating a new list. After the removals, the list should not have any gaps between the remaining numbers. The function should not return the modified list since it will be modified in place; however, the function should resize the list so that the remaining length matches the number of items left after the removals.

Detailed Requirements:

Input:

A list of numbers (nums). The list can be of any length, including zero.

A target number (val). This is the number you want to remove from the list.

Output:

The function should not return any value. However, the input list (nums) should be modified in place.

After the function is executed, the list (nums) should contain only the numbers that are not equal to the target number (val), and there should be no gaps between them.

The order of the other numbers (those not equal to val) in the list should remain the same.

Examples:

Example 1:

Input:

nums: [3, 2, 3, 6, 3, 4, 5, 3]

val: 3

Output:

Modified nums: [2, 6, 4, 5]

Example 2:

Input:

nums: [1, 2, 3, 4, 5]

val: 10

Output:

Modified nums: [1, 2, 3, 4, 5] (No changes because 10 is not in the list.)



Tips:

Try to avoid using extra space or another collection to store intermediate results. The goal is to modify the list in place.

Think of how you can keep track of which numbers to keep and which ones to discard while iterating through the list.

After removing the occurrences of val, ensure that the remaining numbers in the list are tightly packed without any gaps.

Resizing the list at the end can help remove any extraneous values that may be left over from the original list.



Remember, the key is efficiency. The task should be achieved by making a single pass through the list without the need for nested loops or additional collections.


*/

#ifndef EXERCISE_H
#define EXERCISE_H

#include <vector>

using namespace std;

void removeElement(vector<int>& nums, int val);


#endif // _EXERCISE_H
