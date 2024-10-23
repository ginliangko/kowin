/*
54. Spiral Matrix

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.



For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]


You should return [1,2,3,6,9,8,7,4,5].
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// Runtime 0ms Beats 100.00%, Memory 8.27MB Beats 48.47%
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int x_start=0, y_end=matrixSize-1, y_start=0, x_end=(*matrixColSize)-1, total=matrixSize*(*matrixColSize);
    int *ret=malloc(total* sizeof(int));
    int idx=0, d=0, x_d=1, y_d=0;
    int i=x_start, j=y_start;

    while(i<=x_end && j<=y_end && idx<total) {
        ret[idx++]=matrix[j][i];
        if(1)  {
            if(i==x_end && d==0) {
                y_start++;
                x_d=0;
                y_d=1;
                d++;
            } else if(j==y_end && d==1) {
                x_end--;
                x_d=-1;
                y_d=0;
                d++;
            } else if(i==x_start && d==2) {
                y_end--;
                x_d=0;
                y_d=-1;
                d++;
            } else if(j==y_start && d==3) {
                x_start++;
                x_d=1;
                y_d=0;
                d=0;
            }
        }
        i+=x_d;
        j+=y_d;
    }
    *returnSize=idx;
    return ret;
}

// Original solution
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int top, bottom, left, right, where;
    int i;
    int *p = (int *)malloc(matrixRowSize * matrixColSize * sizeof(int));
    if (!p) {
        return p;
    }
    
    i = 0;
    top = 0;
    left = 0;
    bottom = matrixRowSize;
    right = matrixColSize;
    
    while (i < matrixRowSize * matrixColSize) {
        if (top < bottom) {
            where = left;
            while (where < right) {         // on top, left -> right
                p[i++] = matrix[top][where];
                where ++;
            }
            top ++;
        }
        if (right > left) {
            where = top;
            while (where < bottom) {        // on right, top -> bottom
                p[i++] = matrix[where][right - 1];
                where ++;
            }
            right --;
        }
        if (bottom > top) {                 // on bottom, right -> left
            where = right;
            while (where > left) {
                p[i++] = matrix[bottom - 1][where - 1];
                where --;
            }
            bottom --;
        }
        if (left < right) {                 // on left, bottom -> top
            where = bottom;
            while (where > top) {
                p[i++] = matrix[where - 1][left];
                where --;
            }
            left ++;
        }
    }
    
    return p;
}


/*
Difficulty:Medium
Total Accepted:106.2K
Total Submissions:409K


Companies Microsoft Google Uber
Related Topics Array
Similar Questions 
                
                  
                    Spiral Matrix II
*/
