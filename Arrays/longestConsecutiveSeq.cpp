/*
LeetCode 128 - Longest Consecutive Sequence

Problem:
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example:
Input:  nums = [100,4,200,1,3,2]
Output: 4

Explanation:
The longest consecutive sequence is [1,2,3,4].
Therefore, its length is 4.

Input:  nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Approach:
Use a HashSet to store all elements for O(1) lookups.

Key Idea:
Only start counting a sequence when the current number is the **start** of a sequence.
A number is the start if (num - 1) is not present in the set.

This avoids recomputation and ensures O(n) complexity.

Algorithm:
1. Insert all elements into an unordered_set.
2. Iterate through each element in the set:
   - If (it - 1) is NOT present:
     → It is the start of a sequence.
3. Start counting consecutive numbers:
   - Keep checking (x + 1) in the set.
   - Increment count until sequence breaks.
4. Update the longest length.
5. Return the maximum length found.

Time Complexity:
O(n) — each element is processed at most once.

Space Complexity:
O(n) — hash set storage.

Pattern:
Hashing, Sequence Detection
*/

/*
Brute Method:
Sort the array and count consecutive elements linearly.

Time Complexity:
O(n log n)

Space Complexity:
O(1) or O(n) depending on sorting method.
*/

class Solution{
public:
    int longestConsecutive(vector<int>& nums){
        int n = nums.size();
        if(n == 0) return 0;

        int longest = 1;
        unordered_set<int> st;

        // Insert all elements into set
        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
        }

        // Traverse set
        for(auto it : st){
            
            // Check if it is start of sequence
            if(st.find(it - 1) == st.end()){
                
                int cnt = 1;
                int x = it;

                // Count consecutive elements
                while(st.find(x + 1) != st.end()){
                    x++;
                    cnt++;
                }

                longest = max(cnt, longest);
            }
        }

        return longest;
    }
};
