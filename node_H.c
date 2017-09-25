
int height(avl* node) {
if (node = null)
    return 0;
else
    left = height(node->left);
    right = height(node->right);
    return 1 + max(left, right);
}
