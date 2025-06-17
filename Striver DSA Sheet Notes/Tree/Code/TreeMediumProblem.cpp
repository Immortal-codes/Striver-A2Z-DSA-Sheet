#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* 1. Height of Binary Tree */
int height(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

/* 2. Check if Binary Tree is Height Balanced */
bool isBalanced(TreeNode* root) {
    function<int(TreeNode*)> check = [&](TreeNode* node) -> int {
        if (!node) return 0;
        int left = check(node->left);
        if (left == -1) return -1;
        int right = check(node->right);
        if (right == -1) return -1;
        if (abs(left - right) > 1) return -1;
        return 1 + max(left, right);
    };
    return check(root) != -1;
}

/* 3. Diameter of Binary Tree */
int diameter(TreeNode* root, int& maxDia) {
    if (!root) return 0;
    int left = diameter(root->left, maxDia);
    int right = diameter(root->right, maxDia);
    maxDia = max(maxDia, left + right);
    return 1 + max(left, right);
}
int diameterOfBinaryTree(TreeNode* root) {
    int maxDia = 0;
    diameter(root, maxDia);
    return maxDia;
}

/* 4. Maximum Path Sum */
int maxPathSumUtil(TreeNode* root, int& maxSum) {
    if (!root) return 0;
    int left = max(0, maxPathSumUtil(root->left, maxSum));
    int right = max(0, maxPathSumUtil(root->right, maxSum));
    maxSum = max(maxSum, root->val + left + right);
    return root->val + max(left, right);
}
int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    maxPathSumUtil(root, maxSum);
    return maxSum;
}

/* 5. Check if Two Trees are Identical */
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q || p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

/* 6. Zigzag Traversal of Binary Tree */
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;
    while (!q.empty()) {
        int n = q.size();
        vector<int> level(n);
        for (int i = 0; i < n; ++i) {
            TreeNode* node = q.front(); q.pop();
            int index = leftToRight ? i : n - 1 - i;
            level[index] = node->val;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        leftToRight = !leftToRight;
        res.push_back(level);
    }
    return res;
}

/* 7. Boundary Traversal */
void addLeft(TreeNode* root, vector<int>& res) {
    TreeNode* curr = root->left;
    while (curr) {
        if (curr->left || curr->right) res.push_back(curr->val);
        curr = curr->left ? curr->left : curr->right;
    }
}
void addLeaves(TreeNode* root, vector<int>& res) {
    if (!root) return;
    if (!root->left && !root->right) {
        res.push_back(root->val);
        return;
    }
    addLeaves(root->left, res);
    addLeaves(root->right, res);
}
void addRight(TreeNode* root, vector<int>& res) {
    TreeNode* curr = root->right;
    vector<int> tmp;
    while (curr) {
        if (curr->left || curr->right) tmp.push_back(curr->val);
        curr = curr->right ? curr->right : curr->left;
    }
    reverse(tmp.begin(), tmp.end());
    res.insert(res.end(), tmp.begin(), tmp.end());
}
vector<int> boundaryOfBinaryTree(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    if (root->left || root->right) res.push_back(root->val);
    addLeft(root, res);
    addLeaves(root, res);
    addRight(root, res);
    return res;
}

/* 8. Vertical Order Traversal */
vector<vector<int>> verticalOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    map<int, vector<int>> nodes;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto [node, x] = q.front(); q.pop();
        nodes[x].push_back(node->val);
        if (node->left) q.push({node->left, x - 1});
        if (node->right) q.push({node->right, x + 1});
    }
    for (auto& [_, v] : nodes) res.push_back(v);
    return res;
}

/* 9. Top View of Binary Tree */
vector<int> topView(TreeNode* root) {
    map<int, int> top;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto [node, hd] = q.front(); q.pop();
        if (!top.count(hd)) top[hd] = node->val;
        if (node->left) q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }
    vector<int> res;
    for (auto& [_, v] : top) res.push_back(v);
    return res;
}

/* 10. Bottom View of Binary Tree */
vector<int> bottomView(TreeNode* root) {
    map<int, int> bottom;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto [node, hd] = q.front(); q.pop();
        bottom[hd] = node->val;
        if (node->left) q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }
    vector<int> res;
    for (auto& [_, v] : bottom) res.push_back(v);
    return res;
}

/* 11. Right View of Binary Tree */
vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front(); q.pop();
            if (i == size - 1) res.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return res;
}

/* 12. Left View of Binary Tree */
vector<int> leftSideView(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front(); q.pop();
            if (i == 0) res.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return res;
}

/* 13. Symmetric Binary Tree */
bool isMirror(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2 || t1->val != t2->val) return false;
    return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}
bool isSymmetric(TreeNode* root) {
    return isMirror(root->left, root->right);
}


int main() {
    // Sample Tree:
    //        1
    //      /   \
    //     2     3
    //    / \   / \
    //   4   5 6   7

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Height: " << height(root) << endl;
    cout << "Is Balanced: " << (isBalanced(root) ? "Yes" : "No") << endl;
    cout << "Diameter: " << diameterOfBinaryTree(root) << endl;
    cout << "Max Path Sum: " << maxPathSum(root) << endl;

    cout << "Is Same Tree (with itself): " << (isSameTree(root, root) ? "Yes" : "No") << endl;

    cout << "Zigzag Traversal: ";
    auto zz = zigzagLevelOrder(root);
    for (auto &level : zz) for (int val : level) cout << val << " ";
    cout << endl;

    // cout << "Boundary Traversal: ";
    // auto boundary = boundaryTraversal(root);
    // for (int val : boundary) cout << val << " ";
    // cout << endl;

    cout << "Vertical Order: ";
    auto vertical = verticalOrder(root);
    for (auto &col : vertical) for (int val : col) cout << val << " ";
    cout << endl;

    cout << "Top View: ";
    auto top = topView(root);
    for (int val : top) cout << val << " ";
    cout << endl;

    cout << "Bottom View: ";
    auto bottom = bottomView(root);
    for (int val : bottom) cout << val << " ";
    cout << endl;

    cout << "Right View: ";
    auto right = rightSideView(root);
    for (int val : right) cout << val << " ";
    cout << endl;

    cout << "Left View: ";
    auto left = leftSideView(root);
    for (int val : left) cout << val << " ";
    cout << endl;

    return 0;
}