#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Inorder Traversal (Iterative): Left -> Root -> Right
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while (curr != NULL || !st.empty()) {
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        result.push_back(curr->val);
        curr = curr->right;
    }
    return result;
}

// Preorder Traversal (Iterative): Root -> Left -> Right
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* node = st.top(); st.pop();
        result.push_back(node->val);

        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }

    return result;
}

// Postorder Traversal (Iterative using 2 stacks): Left -> Right -> Root
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    stack<TreeNode*> st1, st2;
    st1.push(root);

    while (!st1.empty()) {
        TreeNode* node = st1.top(); st1.pop();
        st2.push(node);

        if (node->left) st1.push(node->left);
        if (node->right) st1.push(node->right);
    }

    while (!st2.empty()) {
        result.push_back(st2.top()->val);
        st2.pop();
    }

    return result;
}

// Level Order Traversal (BFS): Level by level
vector<vector<int>> levelOrderTraversal(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front(); q.pop();
            level.push_back(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        result.push_back(level);
    }

    return result;
}

// Helper to print 1D vector
void printVector(const vector<int>& v) {
    for (int val : v) cout << val << " ";
    cout << endl;
}

// Helper to print 2D vector
void print2DVector(const vector<vector<int>>& v) {
    for (const auto& level : v) {
        for (int val : level) cout << val << " ";
        cout << endl;
    }
}

int main() {
    // Sample Binary Tree
    /*
           1
         /   \
        2     3
       / \
      4   5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Inorder Traversal: ";
    printVector(inorderTraversal(root));

    cout << "Preorder Traversal: ";
    printVector(preorderTraversal(root));

    cout << "Postorder Traversal: ";
    printVector(postorderTraversal(root));

    cout << "Level Order Traversal:" << endl;
    print2DVector(levelOrderTraversal(root));

    return 0;
}
