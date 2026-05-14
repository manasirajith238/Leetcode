/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root) {

    if (root == NULL)
        return 0;

    int leftHeight = 0;
    int rightHeight = 0;

    struct TreeNode* left = root;
    struct TreeNode* right = root;

    // Find left height
    while (left) {
        leftHeight++;
        left = left->left;
    }

    // Find right height
    while (right) {
        rightHeight++;
        right = right->right;
    }

    // Perfect binary tree
    if (leftHeight == rightHeight)
        return (1 << leftHeight) - 1;

    return 1 + countNodes(root->left) +
               countNodes(root->right);
}
