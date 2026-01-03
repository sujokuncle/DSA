// LeetCode 53 - Maximum Subarray Sum
/*
Problem:
Given an integer array nums, find the subarray with the largest sum and return the sum of the elements present in that subarray.
A subarray is a contiguous non-empty sequence of elements within an array

Example:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Approach:
This problem is solved using Kadane’s Algorithm.
We iterate through the array while maintaining a running sum of the current subarray.
If the running sum becomes negative, we reset it to 0 since a negative sum will reduce
the sum of any future subarray.

Algorithm:
1. Initialize maxSum with the first element of the array.
2. Initialize currentSum = 0.
3. Traverse the array:
   - Add the current element to currentSum.
   - Update maxSum with the maximum of maxSum and currentSum.
   - If currentSum becomes negative, reset it to 0.
4. Return maxSum.

Time Complexity:
O(n) — single traversal of the array.

Space Complexity:
O(1) — constant extra space used.

Pattern:
Greedy, Dynamic Programming (Kadane’s Algorithm)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxSum=nums[0];
        int currSum=0;
        for(int i=0;i<n;i++){
            currSum += nums[i];
            maxSum = max(maxSum,currSum);
            if(currSum<0){
                currSum=0;
            }
        }
        return maxSum;
    }
};
