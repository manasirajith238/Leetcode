/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int height(struct TreeNode* root) {

    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    // Not balanced
    if (left == -1 || right == -1)
        return -1;

    if (left - right > 1 || right - left > 1)
        return -1;

    if (left > right)
        return left + 1;

    return right + 1;
}

bool isBalanced(struct TreeNode* root) {

    return height(root) != -1;
}