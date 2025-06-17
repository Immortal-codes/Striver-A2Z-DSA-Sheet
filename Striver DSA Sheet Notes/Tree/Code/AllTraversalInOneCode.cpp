#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Binary Tree Node Structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Node wrapper with state for traversal
struct Pair {
    TreeNode* node;
    int state;  // 1 = Pre, 2 = In, 3 = Post
    Pair(TreeNode* n, int s) : node(n), state(s) {}
};

void allTraversals(TreeNode* root, vector<int>& preorder, vector<int>& inorder, vector<int>& postorder) {
    if (!root) return;

    stack<Pair> st;
    st.push(Pair(root, 1));

    while (!st.empty()) {
        Pair& top = st.top();

        if (top.state == 1) {
            preorder.push_back(top.node->val); // Preorder
            top.state++;
            if (top.node->left) {
                st.push(Pair(top.node->left, 1));
            }
        }
        else if (top.state == 2) {
            inorder.push_back(top.node->val); // Inorder
            top.state++;
            if (top.node->right) {
                st.push(Pair(top.node->right, 1));
            }
        }
        else {
            postorder.push_back(top.node->val); // Postorder
            st.pop();
        }
    }
}

// Helper to print traversal
void printVector(const vector<int>& v, const string& name) {
    cout << name << ": ";
    for (int val : v) cout << val << " ";
    cout << endl;
}

int main() {
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

    vector<int> preorder, inorder, postorder;
    allTraversals(root, preorder, inorder, postorder);

    printVector(preorder, "Preorder");
    printVector(inorder, "Inorder");
    printVector(postorder, "Postorder");

    return 0;
}
