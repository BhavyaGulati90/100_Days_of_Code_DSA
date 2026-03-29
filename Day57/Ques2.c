// Flatten Binary Tree to Linked List

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* prev = NULL;

void flattenHelper(struct TreeNode* root) {
    if (root == NULL) return;

    flattenHelper(root->right);
    flattenHelper(root->left);

    root->right = prev;
    root->left = NULL;
    prev = root;
}

void flatten(struct TreeNode* root) {
    prev = NULL;
    flattenHelper(root);
}