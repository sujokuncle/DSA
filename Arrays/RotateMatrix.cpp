/*
LeetCode 48 - Rotate Image

Problem:
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).

You have to rotate the matrix in-place, meaning you cannot use another matrix
to perform the rotation.

Example:
Input:
matrix =
[
 [1,2,3],
 [4,5,6],
 [7,8,9]
]

Output:
[
 [7,4,1],
 [8,5,2],
 [9,6,3]
]

Explanation:
After rotating the matrix by 90 degrees clockwise, the rows become columns
in reversed order.

Approach:
To rotate the matrix by 90° clockwise in-place, we can perform two operations:

1. Transpose the matrix
   - Convert rows into columns by swapping matrix[i][j] with matrix[j][i].

2. Reverse each row
   - This aligns the elements to achieve a 90° clockwise rotation.

This avoids using extra space and modifies the matrix directly.

Algorithm:
1. Traverse the matrix and swap elements across the diagonal:
   swap(matrix[i][j], matrix[j][i]) for j > i.
2. After transposition, reverse each row of the matrix.
3. The matrix is now rotated 90° clockwise.

Time Complexity:
O(n²) — every element in the matrix is visited.

Space Complexity:
O(1) — rotation is done in-place without extra memory.

Pattern:
Matrix Manipulation, Transpose, In-place Transformation
*/

/*
Brute Method:
Create a new matrix and place each element in its rotated position.

new[j][n - i - 1] = matrix[i][j]

Time Complexity:
O(n²)

Space Complexity:
O(n²) — extra matrix required.
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Transpose the matrix
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
