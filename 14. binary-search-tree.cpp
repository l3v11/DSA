#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // constructor
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *searchBST(TreeNode *root, int val) {
        while (root != NULL && root->val != val)
            root = val < root->val ? root->left : root->right;
        return root;
    }
};

// Function to insert a new node into BST
TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (root == NULL)
        return new TreeNode(val);

    if (val < root->val)
        root->left = insertIntoBST(root->left, val);
    else
        root->right = insertIntoBST(root->right, val);

    return root;
};

// Function to create a BST from a vector
TreeNode *createBST(const vector<int> &nodes) {
    if (nodes.empty())
        return NULL;

    TreeNode *root = NULL;
    for (int val : nodes)
        root = insertIntoBST(root, val);

    return root;
};

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    
    int target;
    cin >> target;

    TreeNode *root = createBST(v);
    Solution obj;

    TreeNode *ans = obj.searchBST(root, target);

    if (ans != NULL)
        cout << "FOUND" << endl;
    else
        cout << " NOT FOUND" << endl;

    return 0;
}
