/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/*
Example 1:
  Input: root = [4,2,6,1,3]
  Output: 1

Example 2:
  Input: root = [1,0,48,null,null,12,49]
  Output: 1
*/

// Runtime 0ms Beats 100.00%, Memory 13.57MB Beats 52.38%
int prev=-1;
int inorder(struct TreeNode *r) {
    if(!r)  return INT_MAX;

    int min=INT_MAX;

    int ret = inorder(r->left);
    min = min<ret?min:ret;

    if(prev != -1) {
        int diff = r->val - prev;
        min = min<diff?min:diff;
    }

    prev=r->val;

    ret = inorder(r->right);
    min = min<ret?min:ret;
    
    return min;
}

int getMinimumDifference(struct TreeNode* root) {
    int ret = inorder(root);

    printf("%d", ret);
    
    return ret;
}
