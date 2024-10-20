/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
Example 1:
  Input: root = [3,9,20,null,null,15,7]
  Output: [3.00000,14.50000,11.00000]
  Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
  Hence return [3, 14.5, 11].

Example 2:
  Input: root = [3,9,20,15,7]
  Output: [3.00000,14.50000,11.00000]
*/

// Runtime 0ms Beats 100.00%, Memory 17.09MB Beats 28.05%
double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    
    if(!root)   return NULL;
    
    struct TreeNode **p=malloc(10000*sizeof(struct TreeNode *));
    double *ret=malloc(10000*sizeof(double));
    int start=0, end=0, idx=0;

    p[end++]=root;
    while(start<end) {
        double sum=0;
        int cnt=0;
        for(int i=start; i<end; i++) {
            if(p[i]) {
                sum+=p[i]->val;
                cnt++;
            }
        }
        ret[idx++]=(double)sum/cnt;

        int k=end;
        for(int i=start; i<k; i++) {
            if(p[i]) {
                if(p[i]->left) p[end++]=p[i]->left;
                if(p[i]->right) p[end++]=p[i]->right;
            }
        }
        start=k;
    }
    free(p);

    *returnSize=idx;

    return ret;
}
