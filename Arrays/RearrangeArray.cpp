/*
LeetCode 2149 - Rearrange Array Elements by Sign

/*
Problem:
Given a 0-indexed integer array nums of even length containing an equal number of positive and negative integers,
rearrange the elements so that every consecutive pair has opposite signs.
The relative order of numbers with the same sign must remain preserved, and the final array must begin with a positive integer.

Example:
Input:  nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:
The positives are [3,1,2] and negatives are [-2,-5,-4] in original order.
They are placed alternately starting with positive, producing the required rearranged array.

Approach:
Use auxiliary hashing containers to separate positive and negative elements in one traversal.
Then rebuild a new result array by alternately picking elements from both containers.
This ensures order preservation and satisfies all conditions efficiently.

Algorithm:
1. Create two empty lists: pos[] and neg[].
2. Traverse the array and push all positive numbers into pos[] and negative numbers into neg[].
3. Initialize a result array ans[] of size 2n.
4. Fill ans[] by alternating elements from pos[] and neg[], starting with pos[0].
5. Return the rearranged array ans[].

Time Complexity:
O(n) — only a single pass is required to separate elements and another linear pass to rebuild the result.

Space Complexity:
O(n) — additional space is used for storing separated positive and negative lists as well as the output array.

Pattern:
Hashing, Array Manipulation
*/

/*
Brute Method:
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;

        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }

        for(int i=0;i<n/2;i++){
            nums[2*i]=pos[i];
            nums[2*i+1]=neg[i];
        }
        return nums;
    }
};

Time Complexity: O(n)
Space Complexity: O(n)
Extra space: two vectors of size n/2 each → total O(n)
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int posIndex=0; int negIndex=1;
      
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[posIndex] = nums[i];
                posIndex+=2;
            }
            else{
                ans[negIndex] = nums[i];
                negIndex+=2;
            }
        }
        return ans;
    }
};
