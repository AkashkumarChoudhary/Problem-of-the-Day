 int isSumTreeHelper(Node* root, bool &isSum) {
    // An empty tree is a Sum Tree and sum of an empty tree is 0
    if (root == nullptr) {
        return 0;
    }

    // A leaf node is also considered a Sum Tree
    if (root->left == nullptr && root->right == nullptr) {
        return root->data;
    }

    // Recursively get the sum of left and right subtrees
    int leftSum = isSumTreeHelper(root->left, isSum);
    int rightSum = isSumTreeHelper(root->right, isSum);

    // Check if the current node satisfies the Sum Tree property
    if (root->data != leftSum + rightSum) {
        isSum = false;
    }

    // Return the sum of the tree rooted at the current node
    return root->data + leftSum + rightSum;
}
    bool isSumTree(Node* root) {
    bool isSum = true;
    isSumTreeHelper(root, isSum);
    return isSum;
}