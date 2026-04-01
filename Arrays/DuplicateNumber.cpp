/*
LeetCode 287 - Find the Duplicate Number

Problem:
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array and using only constant extra space.

Example:
Input:  nums = [1,3,4,2,2]
Output: 2

Input:  nums = [3,1,3,4,2]
Output: 3

Explanation:
Since there are n+1 numbers in the range [1,n], at least one number must repeat
(Pigeonhole Principle).

Approach:
Treat the array as a linked list where:
- Index represents a node
- Value at index represents the next pointer

This creates a cycle due to the duplicate number.

We use Floyd’s Cycle Detection Algorithm:
- Slow pointer moves one step
- Fast pointer moves two steps

Step 1: Detect the cycle (intersection point)
Step 2: Find the entrance of the cycle → duplicate number

Algorithm:
1. Initialize:
   slow = nums[0], fast = nums[0]
2. Move:
   slow = nums[slow]
   fast = nums[nums[fast]]
   until slow == fast (cycle detected)
3. Reset slow = nums[0]
4. Move both pointers one step at a time:
   slow = nums[slow]
   fast = nums[fast]
5. When they meet again → duplicate element

Time Complexity:
O(n) — each element is visited at most a few times.

Space Complexity:
O(1) — no extra space used.

Pattern:
Linked List Cycle Detection, Fast & Slow Pointers
*/

/*
Brute Method:
Sort the array and check adjacent elements for duplicates.

Time Complexity:
O(n log n)

Space Complexity:
O(1) or O(n) depending on sorting.
*/

/*
Better Method:
Use a hash set to track seen elements.

Time Complexity:
O(n)

Space Complexity:
O(n)
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Step 1: Detect cycle
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        // Step 2: Find entrance of cycle
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
