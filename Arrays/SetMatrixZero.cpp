/*
LeetCode 73 - Set Matrix Zeroes

Problem:
Given an m x n integer matrix matrix, if an element is 0,
set its entire row and column to 0.

You must do it in-place.

Example:
Input:
matrix =
[
 [1,1,1],
 [1,0,1],
 [1,1,1]
]

Output:
[
 [1,0,1],
 [0,0,0],
 [1,0,1]
]

Explanation:
The element at position (1,1) is 0.
Therefore, the entire row 1 and column 1 are set to zero.

Approach:
Instead of using extra arrays to store which rows and columns must be zeroed,
we use the **first row and first column of the matrix as markers**.

If matrix[i][j] is zero:
- Mark matrix[i][0] = 0 (row marker)
- Mark matrix[0][j] = 0 (column marker)

However, the first row and column themselves may originally contain zero.
So we track them separately using two boolean variables.

Algorithm:
1. Check if the first row contains any zero → store in firstRowZero.
2. Check if the first column contains any zero → store in firstColZero.
3. Traverse the matrix from (1,1) to (m-1,n-1):
   - If matrix[i][j] == 0:
     - mark row: matrix[i][0] = 0
     - mark column: matrix[0][j] = 0
4. Traverse again from (1,1):
   - If row or column marker is zero, set matrix[i][j] = 0.
5. If firstRowZero is true → make entire first row zero.
6. If firstColZero is true → make entire first column zero.

Time Complexity:
O(m × n) — matrix is traversed a constant number of times.

Space Complexity:
O(1) — no extra space is used apart from two boolean variables.

Pattern:
Matrix Traversal, In-place Marking
*/

/*
Brute Method:
For every zero element found, mark its entire row and column.
To avoid affecting further checks, use a separate visited matrix.

Time Complexity:
O(m × n × (m + n))

Space Complexity:
O(m × n)
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        bool firstRowZero = false;
        bool firstColZero = false;

        // Check first row
        for(int j = 0; j < n; j++){
            if(matrix[0][j] == 0){
                firstRowZero = true;
                break;
            }
        }

        // Check first column
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0){
                firstColZero = true;
                break;
            }
        }

        // Use first row & column as markers
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Update cells based on markers
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        // Update first row
        if(firstRowZero){
            for(int j = 0; j < n; j++){
                matrix[0][j] = 0;
            }
        }

        // Update first column
        if(firstColZero){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};
