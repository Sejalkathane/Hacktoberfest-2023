#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    vector<TreeNode*> children;

    TreeNode(int x) : val(x) {}
};

pair<int, int> dfs(TreeNode* node) {
    if (node == nullptr) {
        return {0, 0};
    }

    int firstMax = 0, secondMax = 0;

    for (TreeNode* child : node->children) {
        pair<int, int> childResult = dfs(child);
        int childDepth = childResult.first + 1;

        if (childDepth > firstMax) {
            secondMax = firstMax;
            firstMax = childDepth;
        } else if (childDepth > secondMax) {
            secondMax = childDepth;
        }

        firstMax = max(firstMax, childResult.second);
    }

    return {firstMax, max(firstMax, secondMax)};
}

int treeDiameter(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    pair<int, int> result = dfs(root);

    return result.first;
}

int main() {
    // Create your tree here.
    TreeNode* root = new TreeNode(1);
    root->children.push_back(new TreeNode(2));
    root->children.push_back(new TreeNode(3));
    root->children[0]->children.push_back(new TreeNode(4));
    root->children[0]->children.push_back(new TreeNode(5));

    int diameter = treeDiameter(root);
    cout << "The diameter of the tree is: " << diameter << endl;

    // Clean up memory if necessary.
    // Delete nodes and release memory to prevent memory leaks.
    return 0;
}
