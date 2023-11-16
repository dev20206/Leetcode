/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 100); // Allocate memory for integers, not pointers
    *returnSize = 0;

    if (root == NULL) {
        return result;
    }

    struct TreeNode* stack[100];  // Assuming a maximum of 100 nodes
    struct TreeNode* outStack[100];  // Another stack to reverse the traversal order
    int top1 = -1;
    int top2 = -1;

    stack[++top1] = root;

    while (top1 >= 0) {
        struct TreeNode* current = stack[top1--];
        outStack[++top2] = current;

        // Push left child first, then right child
        if (current->left) {
            stack[++top1] = current->left;
        }
        if (current->right) {
            stack[++top1] = current->right;
        }
    }

    // Pop elements from outStack to get postorder traversal
    while (top2 >= 0) {
        result[(*returnSize)++] = outStack[top2--]->val;
    }

    return result;
}
