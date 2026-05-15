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
#define MAX 2000

void traverse(struct TreeNode* root, int level,
              int** result, int* returnSize,
              int** returnColumnSizes) {

    if (root == NULL)
        return;

    // New level
    if (level == *returnSize) {

        result[level] = (int*)malloc(MAX * sizeof(int));

        (*returnColumnSizes)[level] = 0;

        (*returnSize)++;
    }

    result[level][(*returnColumnSizes)[level]] = root->val;

    (*returnColumnSizes)[level]++;

    traverse(root->left, level + 1,
             result, returnSize, returnColumnSizes);

    traverse(root->right, level + 1,
             result, returnSize, returnColumnSizes);
}

int** levelOrder(struct TreeNode* root,
                 int* returnSize,
                 int** returnColumnSizes) {

    int** result = (int**)malloc(MAX * sizeof(int*));

    *returnColumnSizes = (int*)malloc(MAX * sizeof(int));

    *returnSize = 0;

    traverse(root, 0, result,
             returnSize, returnColumnSizes);

    return result;
}