// Construct Binary Tree from Preorder and Inorder Traversal


int findIndex(int* inorder, int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value) {
            return i;
        }
    }
    return -1;
}

struct TreeNode* build(int* preorder, int* inorder, int start, int end, int* preIndex) {
    if (start > end) {
        return NULL;
    }

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[*preIndex];
    root->left = NULL;
    root->right = NULL;
    (*preIndex)++;

    if (start == end) {
        return root;
    }

    int inIndex = findIndex(inorder, start, end, root->val);

    root->left = build(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = build(preorder, inorder, inIndex + 1, end, preIndex);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int preIndex = 0;
    return build(preorder, inorder, 0, inorderSize - 1, &preIndex);
}