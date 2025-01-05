//in binary tree linked implementatuon return vector with all nodes at level 
//kreturn empety vector of there is no node at level k
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)  {}
};

vector<TreeNode*>nodesAtLevelK(TreeNode* root, int k) {
    vector<TreeNode*> result;
    if (root==NULL) {
        return result;
    }
    queue<pair<TreeNode*, int> > q;
    q.push(make_pair(root, 1));
    while (!q.empty()) {
        pair<TreeNode*, int> p = q.front();
        q.pop();
        TreeNode* node = p.first;
        int level = p.second;

        if (level == k) {
            result.push_back(node);
        }
        if (node->left) {
            q.push(make_pair(node->left, level + 1));
        }
        if (node->right) {
            q.push(make_pair(node->right, level + 1));
        }
    }

    return result;
}
int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    int level = 2;
    vector<TreeNode*> nodes = nodesAtLevelK(root, level);

    cout << "Nodes at level " << level << ": ";
    for (TreeNode* node : nodes) {
        cout << node->val << " ";
    }
    cout << endl;

    return 0;
}
