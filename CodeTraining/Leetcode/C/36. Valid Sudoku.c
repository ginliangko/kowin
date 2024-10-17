/*
36. Valid Sudoku

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.



A partially filled sudoku which is valid.


Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int flag[9]={0};
    int v=0;
    char c=0;

    // Check Column
    for(int x=0; x<9; x++) {
        memset(flag, 0, sizeof(flag));
        for(int y=0; y<9; y++) {
            v=0;
            c=board[x][y];
            if(c=='.')  continue;
            else        v=c-'0';

            if(++flag[v-1]>1)     return false;
        }
    }

    // Check Row
    for(int y=0; y<9; y++) {
        memset(flag, 0, sizeof(flag));
        for(int x=0; x<9; x++) {
            v=0;
            c=board[x][y];
            if(c=='.')  continue;
            else        v=c-'0';

            if(++flag[v-1]>1)    return false;
        }
    }

    // Check 3x3 block
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            memset(flag, 0, sizeof(flag));
            for(int x=0; x<3; x++) {
                for(int y=0; y<3; y++) {
                    v=0;
                    c=board[i*3+x][j*3+y];
                    if(c=='.')  continue;
                    else        v=c-'0';

                    if(++flag[v-1]>1)     return false;
                }
            }
        }
    }

    return true;
}

/* Original solution
#define VERIFY_HASH(I, J) do { \
    c = board[I][J]; \
    if (c >= '1' && c <= '9') { \
        b = 1 << (c - '1'); \
        if (hash & b) return false; \
        hash |= b; \
    }\
} while (0)

#define IDX(I, J) ((I) / 3 * (boardColSize + 2) / 3 + (J) / 3)

bool isValidSudoku(char** board, int boardSize, int* bColSize) {
    int hash;
    int i, j, m, n;
    char c;
    int b;
    int boardColSize=*bColSize;
    int boardRowSize=boardSize;

    int *hc, *hs, *buff;
    buff = calloc((boardColSize + ((boardRowSize + 2) / 3 * (boardColSize + 2) / 3)), sizeof(int));
    hc = &buff[0];
    hs = &buff[boardColSize];
    
    for (i = 0; i < boardRowSize; i ++) {
        hash = 0;
        for (j = 0; j < boardColSize; j ++) {
            c = board[i][j];
            if (c < '1' || c > '9') continue;
            b = 1 << (c - '1');
            if ((hash & b) ||           // verify failed on current line
                (hc[j] & b) ||          // verify failed on current column
                (hs[IDX(i, j)] & b)) {  // failed on current nestled square
                free(buff);
                return false;
            }
            hash |= b;
            hc[j] |= b;
            hs[IDX(i, j)] |= b;
        }
    }
    free(buff);
    
    return true;
}
*/

/*
Difficulty:Medium
Total Accepted:124.3K
Total Submissions:347.8K


Companies Snapchat Uber Apple
Related Topics Hash Table
Similar Questions 
                
                  
                    Sudoku Solver
*/
