/*
Problem: Sudoku Solver
Link: https://leetcode.com/problems/sudoku-solver/description/
Difficulty: Hard
Topic: Backtracking / DFS / Recursion

Problem Statement:
Write a program to solve a Sudoku puzzle by filling the empty cells.
The board is a 9×9 grid, where empty cells are filled with '.'.
You must fill the board so that:
1. Every row contains the digits 1–9 exactly once.
2. Every column contains the digits 1–9 exactly once.
3. Every of the nine 3×3 sub-boxes contains digits 1–9 exactly once.

Example:
Input:
[
 ["5","3",".", ".","7",".", ".",".","."],
 ["6",".",".", "1","9","5", ".",".","."],
 [".","9","8", ".",".",".", ".","6","."],
 ["8",".",".", ".","6",".", ".",".","3"],
 ["4",".",".", "8",".","3", ".",".","1"],
 ["7",".",".", ".","2",".", ".",".","6"],
 [".","6",".", ".",".",".", "2","8","."],
 [".",".",".", "4","1","9", ".",".","5"],
 [".",".",".", ".","8",".", ".","7","9"]
]

Output (one valid solution):
[
 ["5","3","4","6","7","8","9","1","2"],
 ["6","7","2","1","9","5","3","4","8"],
 ["1","9","8","3","4","2","5","6","7"],
 ["8","5","9","7","6","1","4","2","3"],
 ["4","2","6","8","5","3","7","9","1"],
 ["7","1","3","9","2","4","8","5","6"],
 ["9","6","1","5","3","7","2","8","4"],
 ["2","8","7","4","1","9","6","3","5"],
 ["3","4","5","2","8","6","1","7","9"]
]

Approach (Backtracking – Optimized with Bitmasks):
1. Use three arrays to track used digits:
   - `rows[9][10]`
   - `cols[9][10]`
   - `boxes[9][10]`
2. Pre-fill trackers for digits already on board.
3. Recursively fill empty cells:
   - Pick next empty cell
   - Try all valid digits 1–9 not used in same row/col/box
   - Place digit and update trackers
   - Backtrack on failure
4. Stop when all cells are filled.

Time Complexity: Practically fast (pruned search)  
Space Complexity: O(1) extra (board is modified in place)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        initTrackers(board);
        backtrack(board, 0, 0);
    }

private:
    bool rows[9][10]  = {false};
    bool cols[9][10]  = {false};
    bool boxes[9][10] = {false};

    void initTrackers(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') {
                    int val = board[r][c] - '0';
                    rows[r][val]  = true;
                    cols[c][val]  = true;
                    boxes[boxIndex(r, c)][val] = true;
                }
            }
        }
    }

    int boxIndex(int r, int c) {
        return (r / 3) * 3 + (c / 3);
    }

    bool backtrack(vector<vector<char>>& board, int r, int c) {
        if (r == 9) return true;
        if (c == 9) return backtrack(board, r + 1, 0);

        if (board[r][c] != '.') {
            return backtrack(board, r, c + 1);
        }

        for (int d = 1; d <= 9; d++) {
            if (!rows[r][d] && !cols[c][d] && !boxes[boxIndex(r, c)][d]) {
                board[r][c] = char('0' + d);
                rows[r][d] = cols[c][d] = boxes[boxIndex(r, c)][d] = true;

                if (backtrack(board, r, c + 1)) return true;

                // undo
                board[r][c] = '.';
                rows[r][d] = cols[c][d] = boxes[boxIndex(r, c)][d] = false;
            }
        }

        return false;
    }
};