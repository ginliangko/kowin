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
*/

int calNeighbor(int** board, int boardSize, int boardColSize, int x, int y) {
    int sum=0;

    for(int j=y-1; j<=y+1; j++) {
        for(int i=x-1; i<=x+1; i++) {
            if((i!=x || j!=y) && (i>=0 && j>=0 && i<boardColSize && j<boardSize)){
                int v=board[j][i];
                if(board[j][i]==-1) v=1;
                else if(board[j][i]==2) v=0;
                sum+=v;
            }
        }
    }
    return sum;
}

void gameOfLife(int** board, int boardSize, int* boardColSize) {

    for(int j=0; j<boardSize; j++) {
        for(int i=0; i<(*boardColSize); i++) {
            int n=calNeighbor(board, boardSize, (*boardColSize), i, j);
            if(n<2 && board[j][i]==1)       board[j][i]=-1;
            else if(n>3 && board[j][i]==1)  board[j][i]=-1;
            else if(n==3 && board[j][i]==0) board[j][i]=2;
        }
    }

    for(int j=0; j<boardSize; j++) {
        for(int i=0; i<(*boardColSize); i++) {
            if(board[j][i]==-1)       board[j][i]=0;
            else if(board[j][i]==2)   board[j][i]=1;
        }
    }
}

/* Original solution
void update(int **board, int rowsz, int colsz, int *visited, int x, int y) {
    int a, b, c, d, e, f, g, h;

    int t;
    
    if (x < 0 || x >= rowsz ||
        y < 0 || y >= colsz ||
        visited[x * colsz + y]) return;

    visited[x * colsz + y] = 1;
    
    t = 0;
    
    if (x > 0) {
        t +=  board[x - 1][y];
    }
    if (x > 0 && y < colsz - 1) {
        t += board[x - 1][y + 1];
    }
    if (y < colsz - 1) {
        t += board[x][y + 1];
    }
    if (x < rowsz - 1 && y < colsz - 1) {
        t += board[x + 1][y + 1];
    }
    if (x < rowsz - 1) {
        t += board[x + 1][y];
    }
    if (x < rowsz - 1 && y > 0) {
        t += board[x + 1][y - 1];
    }
    if (y > 0) {
        t += board[x][y - 1];
    }
    if (x > 0 && y > 0) {
        t += board[x - 1][y - 1];
    }
    
    update(board, rowsz, colsz, visited, x - 1, y);
    update(board, rowsz, colsz, visited, x - 1, y + 1);
    update(board, rowsz, colsz, visited, x, y + 1);
    update(board, rowsz, colsz, visited, x + 1, y + 1);
    update(board, rowsz, colsz, visited, x + 1, y);
    update(board, rowsz, colsz, visited, x + 1, y - 1);
    update(board, rowsz, colsz, visited, x, y - 1);
    update(board, rowsz, colsz, visited, x - 1, y - 1);
    
    if (board[x][y]) {
        if (t < 2 || t > 3) board[x][y] = 0;
    } else {
        if (t == 3) board[x][y] = 1;
    }
}
void gameOfLife(int** board, int boardRowSize, int boardColSize) {
    int *visited = calloc(boardRowSize * boardColSize, sizeof(int));
    //assert(visited);
    update(board, boardRowSize, boardColSize, visited, 0, 0);
    free(visited);
}
*/

/*
Difficulty:Medium
Total Accepted:49.8K
Total Submissions:134.9K


Companies Dropbox Google Two Sigma Snapchat
Related Topics Array
Similar Questions 
                
                  
                    Set Matrix Zeroes
*/
