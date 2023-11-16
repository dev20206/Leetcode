/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void dfs(struct TreeNode *root, int *returnSize, int **returnColumnSizes, int level, int **ans){
    if(!root) return;
    if(level + 1 > *returnSize) *returnSize = level + 1;
    if(ans[level] == NULL) ans[level] = malloc(sizeof(int)*2000);
    ans[level][(*returnColumnSizes)[level]] = root->val;
    (*returnColumnSizes)[level]++;
    dfs(root->left, returnSize, returnColumnSizes, level+1, ans);
    dfs(root->right, returnSize, returnColumnSizes, level+1, ans);
}
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int **ans = (int **)calloc(2000, sizeof(int *)), tmp;
    *returnSize = 0;
    *returnColumnSizes = (int *)calloc(2000, sizeof(int));
    dfs(root, returnSize, returnColumnSizes, 0, ans);
    for(int i = 1; i < *returnSize; i+=2){
        for(int j = 0, k = (*returnColumnSizes)[i] - 1; j < k; j++, k--){
            tmp = ans[i][j];
            ans[i][j] = ans[i][k];
            ans[i][k] = tmp;
        }
    }
    return ans;
}