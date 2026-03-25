// Binary Tree Level Order Traversal

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = NULL;
    
    if (root == NULL) {
        return NULL;
    }

    struct TreeNode* queue[2001];
    int front = 0, rear = 0;

    int** result = (int**)malloc(2001 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2001 * sizeof(int));

    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;

        result[*returnSize] = (int*)malloc(levelSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = levelSize;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* curr = queue[front++];
            result[*returnSize][i] = curr->val;

            if (curr->left != NULL) {
                queue[rear++] = curr->left;
            }
            if (curr->right != NULL) {
                queue[rear++] = curr->right;
            }
        }

        (*returnSize)++;
    }

    return result;
}