#include <bits/stdc++.h>
using namespace std;
class AVL {
    struct node {
        int val;  // Value of the node
        node *right;  // Pointer to the right child
        node *left;  // Pointer to the left child

        node() {
            val = 0;
            right = left = nullptr;
        }

        node(int val) {
            this->val = val;
            right = left = nullptr;
        }
    };

    // Function to perform a left rotation on the subtree rooted at Root
    node *LeftRotation(node *Root) {
        node *NextNode = Root->right;  // NextNode becomes the new root of the subtree
        node *T = NextNode->left;  // T is the left child of NextNode
        NextNode->left = Root;  // The old root becomes the left child of NextNode
        Root->right = T;  // T becomes the right child of the old root
        return NextNode;  // Return the new root of the subtree
    }

    // Function to perform a right rotation on the subtree rooted at Root
    node *RightRotation(node *Root) {
        node *NextNode = Root->left;  // NextNode becomes the new root of the subtree
        node *T = NextNode->right;  // T is the right child of NextNode
        NextNode->right = Root;  // The old root becomes the right child of NextNode
        Root->left = T;  // T becomes the left child of the old root
        return NextNode;  // Return the new root of the subtree
    }

    // Function to insert a value into the AVL tree
    node* inserter(node *Root, int val) {
        if (Root == nullptr) {  // If the tree is empty, create a new node as the root
            node *newnode = new node(val);
            Root = newnode;
        } else if (val > Root->val) {  // If the value is greater, insert into the right subtree
            Root->right = inserter(Root->right, val);
        } else {  // If the value is smaller, insert into the left subtree
            Root->left = inserter(Root->left, val);
        }

        int BF = GetBF(Root);  // Calculate the balance factor of the root
        cout << BF << endl;

        // Left-Left case
        if (BF > 1 && Root->left && val < Root->left->val) {
            return RightRotation(Root);
        }

        // Right-Right case
        if (BF < -1 && Root->right && val > Root->right->val) {
            return LeftRotation(Root);
        }

        // Left-Right case
        if (BF > 1 && Root->left && val > Root->left->val) {
            Root->left = LeftRotation(Root->left);
            return RightRotation(Root);
        }

        // Right-Left case
        if (BF < -1 && Root->right && val < Root->right->val) {
            Root->right = RightRotation(Root->right);
            return LeftRotation(Root);
        }

        return Root;  // Return the (possibly new) root of the subtree
    }

    // Function to calculate the balance factor of a node
    int GetBF(node *Root) {
        if (Root == nullptr) {
            return -1;  // An empty tree has a balance factor of -1
        }
        return height(Root->left) - height(Root->right);  // Balance factor is the difference in heights of left and right subtrees
    }

    // Function to find the maximum value node in a subtree
    node * FMax(node *Root) {
        if (Root->right == nullptr) {
            return Root;  // The rightmost node is the maximum
        }
        return FMax(Root->right);  // Continue to the right subtree
    }

    // Function to find the minimum value node in a subtree
    node * FMin(node *Root) {
        if (Root->left == nullptr) {
            return Root;  // The leftmost node is the minimum
        }
        return FMin(Root->left);  // Continue to the left subtree
    }

    // Function to check if a node has no children
    bool HasNotChild(node *Root) {
        return Root->left == nullptr && Root->right == nullptr;
    }

    // Function to check if a node has only a left child
    bool HasLeftChild(node *Root) {
        return Root->left != nullptr && Root->right == nullptr;
    }

    // Function to check if a node has only a right child
    bool HasRightChild(node *Root) {
        return Root->right != nullptr && Root->left == nullptr;
    }

    // Function to delete a value from the AVL tree
    node * Delete(node *Root, int val) {
        if (Root == nullptr) {
            return nullptr;  // If the tree is empty, return null
        }

        if (Root->val < val) {  // If the value is greater, delete from the right subtree
            Root->right = Delete(Root->right, val);
        } else if (Root->val > val) {  // If the value is smaller, delete from the left subtree
            Root->left = Delete(Root->left, val);
        } else {  // If the value matches, delete this node
            if (HasNotChild(Root)) {
                delete Root;  // If the node has no children, simply delete it
                Root = nullptr;
            } else if (HasLeftChild(Root)) {
                node *tmp = Root;
                Root = Root->left;  // If the node has only a left child, replace it with its left child
                delete tmp;
            } else if (HasRightChild(Root)) {
                node *tmp = Root;
                Root = Root->right;  // If the node has only a right child, replace it with its right child
                delete tmp;
            } else {
                node *mx = FMax(Root->left);  // If the node has two children, replace it with the maximum value in the left subtree
                Root->val = mx->val;
                Root->left = Delete(Root->left, mx->val);
            }
        }

        if (Root == nullptr) {
            return Root;  // If the tree becomes empty, return null
        }

        int BF = GetBF(Root);  // Calculate the balance factor of the root

        // Left heavy subtree
        if (BF == 2) {
            if (Root->left && GetBF(Root->left) > 0) {
                return RightRotation(Root);  // Left-Left case
            }
            if (Root->left && GetBF(Root->left) < 0) {
                Root->left = LeftRotation(Root->left);  // Left-Right case
                return RightRotation(Root);
            }
        }

        // Right heavy subtree
        if (BF == -2) {
            if (Root->right && GetBF(Root->right) < 0) {
                return LeftRotation(Root);  // Right-Right case
            }
            if (Root->right && GetBF(Root->right) > 0) {
                Root->right = RightRotation(Root->right);  // Right-Left case
                return LeftRotation(Root);
            }
        }

        return Root;  // Return the (possibly new) root of the subtree
    }

    node *root;  // Root of the AVL tree

public:
    AVL() {
        root = nullptr;  // Initialize the tree as empty
    }

    // Public function to insert a value into the AVL tree
    void insert(int val) {
        root = inserter(root, val);
    }

    // Public function to delete a value from the AVL tree
    void Delete(int val) {
       root = Delete(root, val);
    }

    // Function to calculate the height of a node
    int height(node *Root) {
        if (Root == nullptr) {
            return -1;  // The height of an empty tree is -1
        }
        int LSTHeight = height(Root->left);  // Height of the left subtree
        int RSTHeight = height(Root->right);  // Height of the right subtree
        if (LSTHeight > RSTHeight)
            return (LSTHeight + 1);  // The height is the greater of the two subtrees' heights plus one
        return (RSTHeight + 1);
    }

    // Function to get the root of the AVL tree
    node * getroot() {
        return root;
    }
};
