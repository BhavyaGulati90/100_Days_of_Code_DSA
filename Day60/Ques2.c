// Binary Tree Cameras


int cameras = 0;

int dfs(struct TreeNode* root) {
    if (root == NULL) return 1;

    int left = dfs(root->left);
    int right = dfs(root->right);

    if (left == 2 || right == 2) {
        cameras++;
        return 0;
    }

    if (left == 0 || right == 0) {
        return 1;
    }

    return 2;
}

int minCameraCover(struct TreeNode* root) {
    cameras = 0;
    if (dfs(root) == 2) cameras++;
    return cameras;
}