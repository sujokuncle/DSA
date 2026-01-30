/*
Array Leaders in an Array

Problem:
Given an array of integers, find all the leaders in the array.
An element is considered a leader if it is strictly greater than all the elements to its right side.
The rightmost element is always a leader.

Example:
Input:  arr = [1, 2, 5, 3, 1, 2]
Output: [5, 3, 2]

Explanation:
- 2 is a leader as it is the last element.
- 3 is greater than all elements to its right (1, 2).
- 5 is greater than all elements to its right (3, 1, 2).

Approach:
Traverse the array from right to left while keeping track of the maximum element seen so far.
If the current element is greater than this maximum, it is a leader.
Store such elements and reverse the result at the end to maintain left-to-right order.

Algorithm:
1. Initialize an empty result array ans[].
2. Set maxi = last element of the array and add it to ans[].
3. Traverse the array from right to left (n-2 to 0):
   - If arr[i] > maxi:
     - Add arr[i] to ans[].
     - Update maxi = arr[i].
4. Reverse ans[] to maintain the original order.
5. Return ans[].

Time Complexity:
O(n) — single traversal of the array.

Space Complexity:
O(n) — space used to store leader elements.

Pattern:
Array Traversal, Prefix/Max Tracking
*/

/*
Brute Method:
For each element, check all elements to its right to see if any element is greater.
If none is greater, then the element is a leader.

Time Complexity:
O(n^2)

Space Complexity:
O(1)
*/
//Optimal Code
#include <bits/stdc++.h>
using namespace std;

vector<int> ArrayLeader(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans;

    int maxi = arr[n - 1];
    // Rightmost element is always a leader
    ans.push_back(maxi);

    // Traverse from right to left
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > maxi)
        {
            ans.push_back(arr[i]);
            maxi = arr[i];
        }
    }

    // Reverse to maintain left-to-right order
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 5, 3, 1, 2};
    vector<int> ans = ArrayLeader(nums);

    for (int x : ans)
        cout << x << " ";

    return 0;
}
