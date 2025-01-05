in bts with both positive and negative nodes return subtree with maximum number of subnodes
#include <iostream>
#include <utility>

std::pair<int, int> maxSubtree(TreeNode* root) {
    if (root == nullptr) {
        return std::make_pair(0, 0);
    }

    std::pair<int, int> left = maxSubtree(root->left);
    std::pair<int, int> right = maxSubtree(root->right);

    int numNodes = 1 + left.first + right.first;
    int maxSum = root->val + left.second + right.second;

    return std::max(std::make_pair(numNodes, maxSum), std::max(left, right));
}


int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    std::pair<int, int> result = maxSubtree(root);
    std::cout << "Maximum number of nodes in a subtree: " << result.first << std::endl;

    return 0;
}
