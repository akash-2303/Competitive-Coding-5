// Time Complexity: O(1)
// Space Complexity: O(1)
// Did this code successfully run on Leetcode : Yes

// Approach:
// 1. We will check the validity of the sudoku by checking the rows, columns and the boxes.
// 2. We will use 3 unordered sets to store the values of the rows, columns and boxes.
// 3. We will iterate over the board and check if the value is already present in the set. 

class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            //row check
            for(int i = 0; i < 9; i++){
                unordered_set<char> rowSet;
                for(int j = 0; j < 9; j++){
                    if(board[i][j] == '.'){
                        continue;
                    }
                    if(rowSet.find(board[i][j]) != rowSet.end()){
                        return false;
                    }
                    else{rowSet.insert(board[i][j]);}
                }
            }
            //col check
            for(int j = 0; j < 9; j++){
                unordered_set<char> colSet;
                for(int i = 0; i < 9; i++){
                    if(board[i][j] == '.'){
                        continue;
                    }
                    if(colSet.find(board[i][j]) != colSet.end()){
                        return false;
                    }
                    else{colSet.insert(board[i][j]);}
                }
            }
            //box check
            vector<pair<int, int>> coordinates = {{0,0}, {0,3}, {0,6}, {3, 0}, {3,3}, {3,6}, {6,0}, {6,3}, {6,6}};
            for(auto& coord : coordinates){
                int row = coord.first;
                int col = coord.second;
                unordered_set<char> boxSet;
                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        if(board[i+row][j+col] == '.'){
                            continue;
                        }
                        if(boxSet.find(board[i+row][j+col]) != boxSet.end()){
                            return false;
                        }
                        else{boxSet.insert(board[i+row][j+col]);}
                        }
                }
            }
            return true;
        }
    };