/*
LeetCode 31 - Next Permutation

Problem:
Given an array of integers nums, rearrange the numbers into the lexicographically next greater permutation.
If such an arrangement is not possible (i.e., the array is in descending order),
it must be rearranged as the lowest possible order (ascending order).

The replacement must be done in-place and use only constant extra memory.

Example:
Input:  nums = [1,2,3]
Output: [1,3,2]

Input:  nums = [3,2,1]
Output: [1,2,3]

Input:  nums = [1,1,5]
Output: [1,5,1]

Approach:
The next permutation follows a fixed pattern.
We aim to slightly increase the current permutation by modifying it from the rightmost side.

Key Observations:
- The next permutation is formed by finding the first decreasing element from the right.
- Swapping this element with the next larger element on its right ensures the smallest increment.
- Reversing the suffix gives the smallest lexicographical arrangement afterward.

Algorithm:
1. Traverse from right to left to find the first index `i` such that nums[i] < nums[i+1].
   This index is called the breakpoint.
2. If no such index exists, the array is in descending order:
   reverse the entire array and return.
3. Traverse from the end to find an element just larger than nums[i].
4. Swap nums[i] with that element.
5. Reverse the subarray from i+1 to the end.

Time Complexity:
O(n) — one backward traversal, one swap, and one reverse operation.

Space Complexity:
O(1) — in-place operations with constant extra space.

Pattern:
Array Manipulation, Two Pointers, Greedy
*/

/*
Brute Method:
Generate all permutations of the array, sort them lexicographically,
and return the permutation that comes immediately after the current one.

This approach is impractical due to extremely high time complexity.

Time Complexity:
O(n! * n)

Space Complexity:
O(n!)
*/
//optimal TC code
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;

        //Find the breakpoint
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }

        //If no breakpoint(means array in descnding order), reverse entire array
        if (idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // find element just larger than nums[idx]
        for (int i = n - 1; i > idx; i--) {
            if (nums[i] > nums[idx]) {
                swap(nums[i], nums[idx]);
                break;
            }
        }

        // Reverse the suffix
        reverse(nums.begin() + idx + 1, nums.end());
    }
};
