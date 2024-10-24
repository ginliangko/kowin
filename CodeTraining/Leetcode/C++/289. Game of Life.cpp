/*
289. Game of Life
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

Write a function to compute the next state (after one update) of the board given its current state.

Follow up: 
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?

Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Example 1:
Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]

Example 2:
Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]

*/
class Solution {
public:
    int calNeighbor(vector<vector<int>>& board, int x, int y) {
        int row=board.size();
        int col=board[0].size();
        
        int sum=0;
        for(int j=y-1; j<=y+1; j++) {
            for(int i=x-1; i<=x+1; i++) {
                if((i!=x || j!=y) && (i>=0&&j>=0&& i<col&&j<row)) {
                    int d=board[j][i];
                    if(d==-1)       d=1;
                    else if(d==2)   d=0;
                    sum+=d;
                }
            }
        }
        return sum;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int row=board.size();
        int col=board[0].size();

        for(int j=0; j<row; j++) {
            for(int i=0; i<col; i++) {
                int v=calNeighbor(board, i, j);
                if((v<2 || v>3)&& board[j][i]==1)   board[j][i]=-1;
                else if(v==3 && board[j][i]==0)     board[j][i]=2;
            }
        }

        for(int j=0; j<row; j++) {
            for(int i=0; i<col; i++) {
                if(board[j][i]==-1)   board[j][i]=0;
                else if(board[j][i]==2)     board[j][i]=1;
            }
        }
    }
};
