// in BST,with unique elements with a vector find subtree having all 
//elements of vectors otherwise return null
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)  {}
};

TreeNode* findSubtree(TreeNode* root, vector<int>& nums) {
    if (root == nullptr || nums.empty()) {
        return nullptr;
    }
    if (root->val == nums[0]) {
        if (nums.size() == 1) {
            return root;
        }
        TreeNode* leftSubtree = findSubtree(root->left, vector<int>(nums.begin() + 1, nums.end()));
        TreeNode* rightSubtree = findSubtree(root->right, vector<int>(nums.begin() + 1, nums.end()));
        if (leftSubtree != nullptr && rightSubtree != nullptr) {
            return root;
        } else if (leftSubtree != nullptr) {
            return leftSubtree;
        } else {
            return rightSubtree;
        }
    } else if (root->val < nums[0]) {
        return findSubtree(root->right, nums);
    } else {
        return findSubtree(root->left, nums);
    }
}
int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    vector<int> target = {3, 2, 4};

    TreeNode* subtree = findSubtree(root, target);
    if (subtree) {
        cout << "Subtree found: " << subtree->val << endl;
    } else {
        cout << "Subtree not found." << endl;
    }
    return 0;
}
