/*
LeetCode 54 - Spiral Matrix

Problem:
Given an m x n matrix, return all elements of the matrix in spiral order.

Spiral order means traversing the matrix layer by layer:
- Left → Right (top row)
- Top → Bottom (right column)
- Right → Left (bottom row)
- Bottom → Top (left column)

Example:
Input:
matrix =
[
 [1,2,3],
 [4,5,6],
 [7,8,9]
]

Output:
[1,2,3,6,9,8,7,4,5]

Explanation:
We traverse the matrix in spiral form:
Top row → Right column → Bottom row → Left column → repeat.

Approach:
Use four pointers to represent the current boundaries of the matrix:
- top → starting row
- bottom → ending row
- left → starting column
- right → ending column

At each step:
1. Traverse from left to right across the top row.
2. Traverse from top to bottom along the right column.
3. Traverse from right to left across the bottom row (if valid).
4. Traverse from bottom to top along the left column (if valid).

Shrink the boundaries after each traversal.

Algorithm:
1. Initialize:
   top = 0, bottom = m-1, left = 0, right = n-1
2. While (top <= bottom AND left <= right):
   a. Traverse left → right (top row), then top++
   b. Traverse top → bottom (right column), then right--
   c. If top <= bottom:
        Traverse right → left (bottom row), then bottom--
   d. If left <= right:
        Traverse bottom → top (left column), then left++
3. Return the result array.

Time Complexity:
O(m × n) — every element is visited exactly once.

Space Complexity:
O(1) — ignoring output array.

Pattern:
Matrix Traversal, Boundary Simulation
*/

/*
Brute Method:
Simulate traversal using a visited matrix and direction vectors.
Change direction when hitting a boundary or visited cell.

Time Complexity:
O(m × n)

Space Complexity:
O(m × n) — for visited matrix.
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        int top = 0;
        int left = 0;
        int right = matrix[0].size() - 1;
        int bottom = matrix.size() - 1;

        while(top <= bottom && left <= right){

            // Traverse left → right (top row)
            for(int i = left; i <= right; i++){
                result.push_back(matrix[top][i]);
            }
            top++;

            // Traverse top → bottom (right column)
            for(int i = top; i <= bottom; i++){
                result.push_back(matrix[i][right]);
            }
            right--;

            // Traverse right → left (bottom row)
            if(top <= bottom){
                for(int i = right; i >= left; i--){
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Traverse bottom → top (left column)
            if(left <= right){
                for(int i = bottom; i >= top; i--){
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return result;
    }
};
