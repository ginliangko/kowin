/*
101. Symmetric Tree

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).


For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3



But the following [1,2,2,null,3,null,3]  is not:
    1
   / \
  2   2
   \   \
   3    3




Note:
Bonus points if you could solve it both recursively and iteratively.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define PUSH(N) do { p[n ++] = N; } while (0)
​
bool isSymmetric(struct TreeNode* root) {
    struct TreeNode **p, **tmp;
    int dep, n, i, j, k;

    if (!root) return true;

    dep = 0; n = 0;
    p = malloc((1 << dep) * sizeof(struct TreeNode *));

    PUSH(root);
    //printf("root ["); for(int z=0; z<n; z++) {if(p[z]) printf("[%d,%d]", z, p[z]->val);} printf("] n=%d\n", n);
    while (n) {
        for (i = 0, j = n - 1; i < j; i ++, j --) {
            //printf("     i=%d, j=%d, ", i, j);
            if ((!p[i] && p[j]) ||
                (!p[j] && p[i]) ||
                ( p[i] && p[i]->val != p[j]->val)) {
                //printf("->different, free0()\n");
                free(p);
                return false;
            } //else printf("->same\n");
        }
        //printf("1    ["); for(int z=0; z<n; z++) {if(p[z]) printf("[%d,%d]", z, p[z]->val);} printf("] n=%d\n", n);

        tmp = p; k = n;
        dep ++; n = 0;
        p = malloc((1 << dep) * sizeof(struct TreeNode *));

        for (i = 0; i < k; i ++) {
            if (tmp[i]) {
                PUSH(tmp[i]->left);
                PUSH(tmp[i]->right);

                //printf("  (%d)[", i); for(int z=0; z<n; z++) {if(p[z]) printf("[%d,%d]", z, p[z]->val, n);} printf("] n=%d\n", n);
            }
        }
        //if(tmp[0]) printf("     free1(%d)\n\n", tmp[0]->val);
        //else printf("     free1()\n\n");
        free(tmp);
        //printf("2    ["); for(int z=0; z<n; z++) {if(p[z]) printf("[%d,%d] ", z, p[z]->val);} printf("] n=%d\n", n);
    }
    free(p);
    return true;
}

/*
Difficulty:Easy
Total Accepted:187.9K
Total Submissions:484.8K


Companies LinkedIn Bloomberg Microsoft
Related Topics Tree Depth-first Search Breadth-first Search

*/
