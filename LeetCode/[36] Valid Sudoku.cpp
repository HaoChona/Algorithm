/*
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku/description/
 *
 * algorithms
 * Medium (38.05%)
 * Total Accepted:    158.4K
 * Total Submissions: 416.3K
 * Testcase Example:
 * '[
 * ⁠["5","3",".",".","7",".",".",".","."],
 * ⁠["6",".",".","1","9","5",".",".","."],
 * [".","9","8",".",".",".",".","6","."],
 * ["8",".",".",".","6",".",".",".","3"],
 * ["4",".",".","8",".","3",".",".","1"],
 * ["7",".",".",".","2",".",".",".","6"],
 * [".","6",".",".",".",".","2","8","."],
 * [".",".",".","4","1","9",".",".","5"],
 * [".",".",".",".","8",".",".","7","9"]
 *  ]'
 *
 * Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be
 * validated according to the following rules:
 *
 *
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without
 * repetition.
 *
 *
 *
 * A partially filled sudoku which is valid.
 *
 * The Sudoku board could be partially filled, where empty cells are filled
 * with the character '.'.
 *
 * Example 1:
 *
 *
 * Input:
 * [
 * ⁠ ["5","3",".",".","7",".",".",".","."],
 * ⁠ ["6",".",".","1","9","5",".",".","."],
 * ⁠ [".","9","8",".",".",".",".","6","."],
 * ⁠ ["8",".",".",".","6",".",".",".","3"],
 * ⁠ ["4",".",".","8",".","3",".",".","1"],
 * ⁠ ["7",".",".",".","2",".",".",".","6"],
 * ⁠ [".","6",".",".",".",".","2","8","."],
 * ⁠ [".",".",".","4","1","9",".",".","5"],
 * ⁠ [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input:
 * [
 * ["8","3",".",".","7",".",".",".","."],
 * ["6",".",".","1","9","5",".",".","."],
 * [".","9","8",".",".",".",".","6","."],
 * ["8",".",".",".","6",".",".",".","3"],
 * ["4",".",".","8",".","3",".",".","1"],
 * ["7",".",".",".","2",".",".",".","6"],
 * [".","6",".",".",".",".","2","8","."],
 * [".",".",".","4","1","9",".",".","5"],
 * [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner
 * being
 * ⁠   modified to 8. Since there are two 8's in the top left 3x3 sub-box, it
 * is invalid.
 *
 *
 * Note:
 *
 *
 * A Sudoku board (partially filled) could be valid but is not necessarily
 * solvable.
 * Only the filled cells need to be validated according to the mentioned
 * rules.
 * The given board contain only digits 1-9 and the character '.'.
 * The given board size is always 9x9.
 *
 *
 */
class Solution {
public:
    bool check(vector<vector<char>>& board,int r, int c){
        int arr[10];
        memset(arr,0,sizeof(arr));
        for(int i=r; i<=r+2;i++){
            for(int j=c; j<=c+2; j++){
                if(board[i][j]=='.'){
                    continue;
                }
                arr[(board[i][j]-'0')]++;
            }
        }
        for(int k=1;k<10;k++){
            if (arr[k]>1){
                return true;
            }
        }
        return false;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int len = (int)board.size();
        int arr[10];
        memset(arr,0,sizeof(arr));
        for(int i=0; i<len; i++){
            for(int j=0;j<len;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                arr[(board[i][j]-'0')]++;
            }
            for(int k=1;k<10;k++){
                if (arr[k]>1){
                    return false;
                }
            }
            memset(arr,0,sizeof(arr));
            for(int j=0; j<len; j++){
                if(board[j][i]=='.'){
                    continue;
                }
                arr[(board[j][i]-'0')]++;
            }
            for(int k=1;k<10;k++){
                if (arr[k]>1){
                    return false;
                }
            }
            memset(arr,0,sizeof(arr));
        }
        for(int i=0; i<len-2; i+=3){
            for(int j=0;j<len-2; j+=3){
                int flag=check(board,i,j);
                if(flag){
                    return false;
                }
            }
        }
        return true;
    }
};
