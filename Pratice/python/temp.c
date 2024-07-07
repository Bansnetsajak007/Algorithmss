void search(root* root, int key) {
    if(root == NULL) return;

    if(root->data == key) return key;

    if(root->data > key) return search(root->right, key)
    if(root->data < key) return search(root->left, key)
}