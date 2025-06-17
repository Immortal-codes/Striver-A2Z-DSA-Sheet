#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <unordered_set>
#include <algorithm>
#include <functional>
using namespace std;

// ✅ 0. TreeNode class
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
        this->val = val;
        left = right = NULL;
    }
};

// ✅ BST Class
class BST {
public:

    // ✅ 1. Insert a node into BST
    TreeNode* insert(TreeNode* root, int key) {
        if (!root) return new TreeNode(key);
        if (key < root->val) root->left = insert(root->left, key);
        else root->right = insert(root->right, key);
        return root;
    }

    // ✅ 2. Delete a node from BST
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        if (key < root->val) root->left = deleteNode(root->left, key);
        else if (key > root->val) root->right = deleteNode(root->right, key);
        else {
            if (!root->left) return root->right;
            if (!root->right) return root->left;
            TreeNode* temp = root->right;
            while (temp->left) temp = temp->left;
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }

    // ✅ 3. Find Floor in BST
    int findFloor(TreeNode* root, int key) {
        int floor = -1;
        while (root) {
            if (root->val == key) return root->val;
            if (key > root->val) {
                floor = root->val;
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return floor;
    }

    // ✅ 4. Find Ceil in BST
    int findCeil(TreeNode* root, int key) {
        int ceil = -1;
        while (root) {
            if (root->val == key) return root->val;
            if (key < root->val) {
                ceil = root->val;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return ceil;
    }

    // ✅ 5. Validate if tree is a BST
    bool isValidBST(TreeNode* root, long minV = LONG_MIN, long maxV = LONG_MAX) {
        if (!root) return true;
        if (root->val <= minV || root->val >= maxV) return false;
        return isValidBST(root->left, minV, root->val) &&
               isValidBST(root->right, root->val, maxV);
    }

    // ✅ 6. K-th Smallest Element in BST
    int kthSmallest(TreeNode* root, int& k) {
        if (!root) return -1;
        int left = kthSmallest(root->left, k);
        if (k == 0) return left;
        k--;
        if (k == 0) return root->val;
        return kthSmallest(root->right, k);
    }

    // ✅ 7. Lowest Common Ancestor in BST
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        if (p->val < root->val && q->val < root->val) return LCA(root->left, p, q);
        if (p->val > root->val && q->val > root->val) return LCA(root->right, p, q);
        return root;
    }

    // ✅ 8. Inorder Successor in BST
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* succ = NULL;
        while (root) {
            if (p->val < root->val) {
                succ = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return succ;
    }

    // ✅ 9. Inorder Predecessor in BST
    TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p) {
        TreeNode* pred = NULL;
        while (root) {
            if (p->val > root->val) {
                pred = root;
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return pred;
    }

    // ✅ 10. Inorder Traversal Helper (used for merging BSTs)
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

    // ✅ 11. Convert Sorted Array to Balanced BST
    TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r) {
        if (l > r) return NULL;
        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, l, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, r);
        return root;
    }

    // ✅ 12. Merge Two BSTs into One Balanced BST
    TreeNode* mergeBSTs(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;
        inorder(root1, a);
        inorder(root2, b);
        vector<int> merged;
        merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(merged));
        return sortedArrayToBST(merged, 0, merged.size() - 1);
    }

    // ✅ 13. Two Sum in BST - check if a pair with sum k exists
    bool twoSumBST(TreeNode* root, int k, unordered_set<int>& s) {
        if (!root) return false;
        if (s.count(k - root->val)) return true;
        s.insert(root->val);
        return twoSumBST(root->left, k, s) || twoSumBST(root->right, k, s);
    }

    // ✅ 14. Recover BST - fix two swapped nodes
    void recoverTree(TreeNode* root) {
        TreeNode* first = NULL, *middle = NULL, *last = NULL, *prev = NULL;

        function<void(TreeNode*)> inorderFix = [&](TreeNode* node) {
            if (!node) return;
            inorderFix(node->left);
            if (prev && node->val < prev->val) {
                if (!first) {
                    first = prev;
                    middle = node;
                } else {
                    last = node;
                }
            }
            prev = node;
            inorderFix(node->right);
        };

        inorderFix(root);
        if (first && last) swap(first->val, last->val);
        else if (first && middle) swap(first->val, middle->val);
    }

    // ✅ 15. Largest BST in a Binary Tree
    int largestBSTSubtree(TreeNode* root) {
        struct Info {
            int size, minV, maxV, largestBSTSize;
            bool isBST;
        };

        int maxSize = 0;

        function<Info(TreeNode*)> dfs = [&](TreeNode* node) -> Info {
            if (!node) return {0, INT_MAX, INT_MIN, 0, true};
            Info left = dfs(node->left);
            Info right = dfs(node->right);
            Info curr;
            curr.size = 1 + left.size + right.size;
            if (left.isBST && right.isBST &&
                node->val > left.maxV && node->val < right.minV) {
                curr.minV = min(node->val, left.minV);
                curr.maxV = max(node->val, right.maxV);
                curr.largestBSTSize = curr.size;
                curr.isBST = true;
                maxSize = max(maxSize, curr.size);
            } else {
                curr.isBST = false;
                curr.largestBSTSize = max(left.largestBSTSize, right.largestBSTSize);
            }
            return curr;
        };

        dfs(root);
        return maxSize;
    }
};

// ✅ 16. Main Function to Test All Features
int main() {
    BST tree;
    TreeNode* root = NULL;

    // Insert nodes
    vector<int> values = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    for (int val : values) {
        root = tree.insert(root, val);
    }

    // Floor and Ceil
    cout << "Floor of 5: " << tree.findFloor(root, 5) << endl;
    cout << "Ceil of 5: " << tree.findCeil(root, 5) << endl;

    // Validate BST
    cout << "Is Valid BST? " << (tree.isValidBST(root) ? "Yes" : "No") << endl;

    // K-th smallest
    int k = 3;
    cout << "3rd smallest: " << tree.kthSmallest(root, k) << endl;

    // Two sum
    unordered_set<int> s;
    cout << "Two Sum 9 exists? " << (tree.twoSumBST(root, 9, s) ? "Yes" : "No") << endl;

    // Inorder successor of node with val = 6
    TreeNode* node6 = root->left->right; // 6
    TreeNode* succ = tree.inorderSuccessor(root, node6);
    cout << "Successor of 6: " << (succ ? succ->val : -1) << endl;

    return 0;
}
