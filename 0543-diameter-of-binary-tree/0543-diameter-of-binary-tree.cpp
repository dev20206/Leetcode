class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int lheight = height(root->left);
        int rheight = height(root->right);
        int ldiameter = diameterOfBinaryTree(root->left);
        int rdiameter = diameterOfBinaryTree(root->right);

        // Diameter is calculated as the sum of heights without adding extra nodes (no +1)
        return std::max(lheight + rheight, std::max(ldiameter, rdiameter));
    }

    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + std::max(height(root->left), height(root->right));
    }
};
