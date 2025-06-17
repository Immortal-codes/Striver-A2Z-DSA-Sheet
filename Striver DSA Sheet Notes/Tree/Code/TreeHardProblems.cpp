#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

/* 1. Root‑to‑Node Path */
bool rootToNode(TreeNode* root, TreeNode* target, vector<int>& path) {
    if (!root) return false;
    path.push_back(root->val);
    if (root == target ||
        rootToNode(root->left, target, path) ||
        rootToNode(root->right, target, path))
        return true;
    path.pop_back();
    return false;
}

/* 2. Lowest Common Ancestor (LCA) */
TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = LCA(root->left, p, q);
    TreeNode* right = LCA(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
}

/* 3. Maximum Width */
int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    long long ans = 0;
    queue<pair<TreeNode*, long long>> q;
    q.push({root, 0});
    while (!q.empty()) {
        int sz = q.size();
        long long start = q.front().second;
        long long end = start;
        for (int i = 0; i < sz; ++i) {
            auto [node, idx] = q.front(); q.pop();
            idx -= start;
            end = idx;
            if (node->left) q.push({node->left, idx*2 + 1});
            if (node->right) q.push({node->right, idx*2 + 2});
        }
        ans = max(ans, end + 1);
    }
    return ans;
}

/* 4. Children Sum Property */
bool childSum(TreeNode* root) {
    if (!root || (!root->left && !root->right)) return true;
    int sum = 0;
    if (root->left) sum += root->left->val;
    if (root->right) sum += root->right->val;
    return root->val == sum && childSum(root->left) && childSum(root->right);
}

/* 5. Print nodes at distance K */
void nodesAtDistanceKDown(TreeNode* root, int k, vector<int>& res) {
    if (!root || k < 0) return;
    if (k == 0) { res.push_back(root->val); return; }
    nodesAtDistanceKDown(root->left, k-1, res);
    nodesAtDistanceKDown(root->right, k-1, res);
}
int nodesAtDistanceKUtil(TreeNode* root, TreeNode* target, int k, vector<int>& res) {
    if (!root) return -1;
    if (root == target) {
        nodesAtDistanceKDown(root, k, res);
        return 0;
    }
    int dl = nodesAtDistanceKUtil(root->left, target, k, res);
    if (dl != -1) {
        if (dl + 1 == k) res.push_back(root->val);
        else nodesAtDistanceKDown(root->right, k - dl - 2, res);
        return 1 + dl;
    }
    int dr = nodesAtDistanceKUtil(root->right, target, k, res);
    if (dr != -1) {
        if (dr + 1 == k) res.push_back(root->val);
        else nodesAtDistanceKDown(root->left, k - dr - 2, res);
        return 1 + dr;
    }
    return -1;
}
vector<int> nodesAtDistanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int> res;
    nodesAtDistanceKUtil(root, target, k, res);
    return res;
}

// /* 6. Time to Burn Tree */
// int minTimeToBurn(TreeNode* root, TreeNode* target) {
//     unordered_map<TreeNode*, TreeNode*> parent;
//     queue<TreeNode*> q;
//     q.push(root);
//     parent[root] = nullptr;
//     TreeNode* t = nullptr;
//     while (!q.empty()) {
//         auto cur = q.front(); q.pop();
//         if (cur->val == target->val) t = cur;
//         if (cur->left) { parent[cur->left] = cur; q.push(cur->left); }
//         if (cur->right){ parent[cur->right] = cur; q.push(cur->right); }
//     }
//     // queue<TreeNode*> burn{t};
//     unordered_map<TreeNode*, bool> vis;
//     vis[t] = true;
//     int time = 0;
//     // while (!burn.empty()) {
//         // int sz = burn.size(); bool have = false;
//         while (sz--) {
//             auto cur = burn.front(); burn.pop();
//             auto check = [&](TreeNode* neigh){
//                 if (neigh && !vis[neigh]) {
//                     vis[neigh] = true; burn.push(neigh); have = true;
//                 }
//             };
//             check(cur->left); check(cur->right);
//             check(parent[cur]);
//         }
//         if (have) ++time;
//     }
//     return time;
// // }

/* 7. Count Nodes in Complete Binary Tree */
int countNodes(TreeNode* root) {
    if (!root) return 0;
    int lh=0, rh=0;
    TreeNode *l=root,*r=root;
    while (l) { lh++; l=l->left; }
    while (r) { rh++; r=r->right; }
    if (lh == rh) return (1<<lh)-1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

/* 8. Construct from inorder+preorder */
TreeNode* buildPreIn(vector<int>& pre, int ps, int pe, vector<int>& in, int is, int ie, unordered_map<int,int>& idx) {
    if (ps > pe || is > ie) return nullptr;
    TreeNode* root = new TreeNode(pre[ps]);
    int inRoot = idx[pre[ps]];
    int leftSize = inRoot - is;
    root->left = buildPreIn(pre, ps+1, ps+leftSize, in, is, inRoot-1, idx);
    root->right = buildPreIn(pre, ps+leftSize+1, pe, in, inRoot+1, ie, idx);
    return root;
}
TreeNode* buildTreePreIn(vector<int>& pre, vector<int>& in) {
    unordered_map<int,int> idx;
    for (int i=0;i<in.size();i++) idx[in[i]] = i;
    return buildPreIn(pre, 0, pre.size()-1, in, 0, in.size()-1, idx);
}

/* 9. Construct from inorder+postorder */
TreeNode* buildPostIn(vector<int>& post, int ps, int pe, vector<int>& in, int is, int ie, unordered_map<int,int>& idx) {
    if (ps > pe || is > ie) return nullptr;
    TreeNode* root = new TreeNode(post[pe]);
    int inRoot = idx[post[pe]];
    int leftSize = inRoot - is;
    root->left = buildPostIn(post, ps, ps+leftSize-1, in, is, inRoot-1, idx);
    root->right = buildPostIn(post, ps+leftSize, pe-1, in, inRoot+1, ie, idx);
    return root;
}
TreeNode* buildTreePostIn(vector<int>& post, vector<int>& in) {
    unordered_map<int,int> idx;
    for (int i=0;i<in.size();i++) idx[in[i]] = i;
    return buildPostIn(post, 0, post.size()-1, in, 0, in.size()-1, idx);
}

/* 10. Serialize & Deserialize */
void serialize(TreeNode* root, ostream &out) {
    if (!root) { out << "# "; return; }
    out << root->val << " ";
    serialize(root->left, out);
    serialize(root->right, out);
}
TreeNode* deserialize(istringstream &in) {
    string s;
    // if (!(in>>s) || s=="#") return nullptr;
    TreeNode* root = new TreeNode(stoi(s));
    root->left = deserialize(in);
    root->right = deserialize(in);
    return root;
}

/* 11/12. Morris Preorder & Inorder Traversal */
vector<int> morrisPreorder(TreeNode* root) {
    vector<int> res; TreeNode* cur = root;
    while (cur) {
        if (!cur->left) {
            res.push_back(cur->val);
            cur = cur->right;
        } else {
            TreeNode* pred = cur->left;
            while (pred->right && pred->right != cur) pred = pred->right;
            if (!pred->right) {
                res.push_back(cur->val);
                pred->right = cur;
                cur = cur->left;
            } else {
                pred->right = nullptr;
                cur = cur->right;
            }
        }
    }
    return res;
}
vector<int> morrisInorder(TreeNode* root) {
    vector<int> res; TreeNode* cur = root;
    while (cur) {
        if (!cur->left) {
            res.push_back(cur->val);
            cur = cur->right;
        } else {
            TreeNode* pred = cur->left;
            while (pred->right && pred->right != cur) pred = pred->right;
            if (!pred->right) {
                pred->right = cur;
                cur = cur->left;
            } else {
                pred->right = nullptr;
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return res;
}

/* 13. Flatten to LinkedList */
void flatten(TreeNode* root) {
    TreeNode* cur = root;
    while (cur) {
        if (cur->left) {
            TreeNode* pred = cur->left;
            while (pred->right) pred = pred->right;
            pred->right = cur->right;
            cur->right = cur->left;
            cur->left = nullptr;
        }
        cur = cur->right;
    }
}

/* Helper Print Functions */
void printVec(const vector<int>& v) { for (int x : v) cout << x << " "; cout << "\n"; }
void printDFS(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printDFS(root->left); printDFS(root->right);
}

int main(){
    // Build sample tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Root to Node Path (5): ";
    vector<int> path;
    rootToNode(root, root->left->right, path);
    printVec(path);

    cout << "LCA of 4 & 5: " << LCA(root, root->left->left, root->left->right)->val << "\n";
    cout << "Max Width: " << widthOfBinaryTree(root) << "\n";
    cout << "Child Sum Property: " << (childSum(root) ? "Yes" : "No") << "\n";

    cout << "Nodes at distance 2 from root: ";
    printVec(nodesAtDistanceK(root, root, 2));

    // cout << "Time to burn from node 4: " << minTimeToBurn(root, root->left->left) << "\n";
    // cout << "Count nodes in Complete Tree: " << countNodes(root) << "\n";

    vector<int> pre={1,2,4,5,3,6,7}, in={4,2,5,1,6,3,7};
    TreeNode* t1 = buildTreePreIn(pre, in);
    cout << "Reconstructed (Pre+In) DFS: "; printDFS(t1); cout << "\n";

    vector<int> post={4,5,2,6,7,3,1};
    TreeNode* t2 = buildTreePostIn(post, in);
    cout << "Reconstructed (Post+In) DFS: "; printDFS(t2); cout << "\n";

    cout << "Morris Preorder: "; printVec(morrisPreorder(root));
    cout << "Morris Inorder: "; printVec(morrisInorder(root));

    flatten(root);
    cout << "Flattened Tree (Preorder): ";
    TreeNode* tmp = root;
    while(tmp) { cout << tmp->val << " "; tmp = tmp->right; }
    cout << "\n";

    return 0;
}
