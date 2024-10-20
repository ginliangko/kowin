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

// Runtime 0ms Beats 100.00%, Memory 17.16MB Beats 26.22%
double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    
    if(!root)   return NULL;
    
    struct TreeNode **p=malloc(10000*sizeof(struct TreeNode *));
    double *ret=malloc(10000*sizeof(double));
    int s=0, e=0, idx=0;

    p[e++]=root;
    while(s<e) {
        double sum=0;
        int cnt=0, k=e;
        for(int i=s; i<k; i++) {
            if(p[i]) {
                sum+=p[i]->val;
                cnt++;

                if(p[i]->left)  p[e++]=p[i]->left;
                if(p[i]->right) p[e++]=p[i]->right;
            }
        }
        ret[idx++]=(double)sum/cnt;

        s=k;
    }
    free(p);

    *returnSize=idx;

    return ret;
}
