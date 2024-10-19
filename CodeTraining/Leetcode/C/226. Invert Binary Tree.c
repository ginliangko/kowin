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
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Example 2:
Input: root = [2,1,3]
Output: [2,3,1]

Example 3:
Input: root = []
Output: []
*/

// Runtime 0ms Beats 100.00%, Memory 8.71MB Beats 19.87%
struct TreeNode* invertTree(struct TreeNode* root) {
    struct TreeNode *p=root, *tmp;

    if(!p) return NULL;

    if(p->left) invertTree(p->left);
    if(p->right) invertTree(p->right);

    tmp = p->left;
    p->left = p->right;
    p->right = tmp;

    return p;
}
