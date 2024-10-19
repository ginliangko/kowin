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
      Input: p = [1,2,3], q = [1,2,3]
      Output: true

  Example 2:
      Input: p = [1,2], q = [1,null,2]
      Output: false

  Example 3:
      Input: p = [1,2,1], q = [1,1,2]
      Output: false
*/

// Runtime 0ms Beats 100.00%, Memory 8.25MB Beats 34.39%
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {

    if(p && q) {
        if(p->val==q->val) {
            if(!isSameTree(p->left, q->left))   return false;
            if(!isSameTree(p->right, q->right)) return false;

            return true;
        }
    } else if(!p&&!q)   return true;
    return false;
}
