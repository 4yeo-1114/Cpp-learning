/* C | tree: inorder traversal. */
#include <stdio.h>
#include <stdlib.h>

// 二叉树节点
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// 创建新节点
Node* createNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    if (n == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// 插入节点（递归）
Node* insert(Node* root, int data) {
    if (root == NULL) return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// 查找节点
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) return root;

    if (data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

// 找到最小值节点（用于删除）
Node* findMin(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int data) {
    if (root == NULL) return root;  // 树空，无节点可删

    // 步骤1：定位待删除节点（递归找到目标节点）
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {  // 找到目标节点，开始删除逻辑
        // 情况2：只有右孩子 或 叶子节点
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;  // 返回右孩子，替代当前节点
        }
        // 情况2：只有左孩子
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;  // 返回左孩子，替代当前节点
        }

        // 情况3：有两个孩子（找中序后继）
        Node* temp = findMin(root->right);  // 右子树的最小值节点
        root->data = temp->data;            // 用后继值覆盖当前节点值
        root->right = deleteNode(root->right, temp->data);  // 递归删除后继节点
    }
    return root;
}
// 中序遍历
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// 销毁整棵树
void destroyTree(Node* root) {
    if (root != NULL) {
        destroyTree(root->left);
        destroyTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("中序遍历: ");
    inorder(root);
    printf("\n");

    printf("查找 40: %s\n", search(root, 40) ? "找到" : "未找到");
    printf("查找 90: %s\n", search(root, 90) ? "找到" : "未找到");

    printf("删除 20...\n");
    root = deleteNode(root, 20);
    printf("中序遍历: ");
    inorder(root);
    printf("\n");

    printf("删除 30...\n");
    root = deleteNode(root, 30);
    printf("中序遍历: ");
    inorder(root);
    printf("\n");

    printf("删除 50...\n");
    root = deleteNode(root, 50);
    printf("中序遍历: ");
    inorder(root);
    printf("\n");

    destroyTree(root);
    return 0;
}
