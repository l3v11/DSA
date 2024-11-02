#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraverse(TreeNode *root)
    {
        vector<int> preorder;

        if (root == NULL)
            return preorder;

        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            root = st.top();
            st.pop();
            preorder.push_back(root->val);
            if (root->right != NULL)
                st.push(root->right);

            if (root->left != NULL)
                st.push(root->left);
        }
        return preorder;
    }
};

TreeNode *insert(vector<int> &arr, int i)
{
    if (i < arr.size() && arr[i] != -1) {
        TreeNode *root = new TreeNode(arr[i]);
        root->left = insert(arr, 2 * i + 1);
        root->right = insert(arr, 2 * i + 2);
        return root;
    }
    return NULL;
}

int main() {
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    // creating binary tree
    TreeNode *root = insert(v, 0);
    Solution obj;
    vector<int> res = obj.preorderTraverse(root);
    cout << "Preorder traversal using stack/ iterative preorder" << endl;
    
    for (auto &it : res)
        cout << it << " ";
    cout << endl;

    return 0;
}
