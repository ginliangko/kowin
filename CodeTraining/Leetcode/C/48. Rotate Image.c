/*
48. Rotate Image

You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
Follow up:
Could you do this in-place?
*/

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int n=matrixSize;
    int tmp;

    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            tmp=matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=tmp;
        }
    }

    for(int i=0; i<n/2; i++) {
        for(int j=0; j<n; j++) {
            tmp=matrix[j][i];
            matrix[j][i]=matrix[j][n-1-i];
            matrix[j][n-1-i]=tmp;
        }
    }
}

/* original solution
#define RIGHT(I)    (matrix[I][y])
#define BOTTOM(I)   (matrix[y][y + x - I])
#define LEFT(I)     (matrix[y + x - I][x])
#define TOP(I)      (matrix[x][I])
​
void spin(int **matrix, int x, int y) {
    int i;
    int a, b, c;
    
    if (x >= y) return;
    
    for (i = x; i < y; i ++) {
        a = RIGHT(i);
        RIGHT(i) = TOP(i);
        
        b = BOTTOM(i);
        BOTTOM(i) = a;
        
        c = LEFT(i);
        LEFT(i) = b;
        
        TOP(i) = c;
    }
    spin(matrix, x + 1, y - 1);
}
void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    spin(matrix, 0, matrixRowSize - 1);
}
*/

/*
Difficulty:Medium
Total Accepted:121.1K
Total Submissions:314.2K


Companies Amazon Microsoft Apple
Related Topics Array

*/
