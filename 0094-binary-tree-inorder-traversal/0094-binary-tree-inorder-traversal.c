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
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 100);  // Assuming a maximum of 100 nodes
    *returnSize = 0;
    
    if (root == NULL) {
        return result;
    }
    
    struct TreeNode* stack[100];  // Assuming a maximum of 100 nodes
    int top = -1;
    struct TreeNode* current = root;
    
    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        
        current = stack[top--];
        result[(*returnSize)++] = current->val;
        current = current->right;
    }
    
    return result;
}