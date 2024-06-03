#include <bits/stdc++.h>
using namespace std;


template <typename T>
class binaryTree{
    struct  node {
        T val ;
        node *left;
        node *right;
        node() {
            left=right=nullptr;
        }
        node(T val) {
            this->val=val;
            left=right=nullptr;
        }
    };
    node *root;
    int size;
    node* inserter(node *Root,T val) {
        if(Root==nullptr) {
            node *newnode=new node(val);
            size++;

            Root=newnode;
        }else if(val>Root->val) {
            Root->right=inserter(Root->right,val);
        }else {
            Root->left=inserter(Root->left,val);
        }
        return Root;
    }
    node* Searcher(node*Root,T val) {
        if(Root == nullptr) {
            return nullptr;
        }
        if(Root->val ==val) {
            return Root;
        }
        if(Root->val <val) {
            return  Searcher(Root->right,val);
        }
        return Searcher(Root->left,val);

    }
    node * FMax(node * Root) {
        if(Root->right == nullptr) {
            return Root;
        }
        return  FMax(Root->right);
    }
    node * FMin(node * Root) {
        if(Root->left==nullptr) {
            return Root;
        }
        return FMin(Root->left);
    }

    bool HasNotChild(node *Root) {
        return Root->left ==nullptr && Root->right ==nullptr;
    }
    bool HasLeftChild(node *Root) {
        return Root->left !=nullptr &&Root->right==nullptr;
    }
    bool HasRightChild(node *Root) {
        return Root->right !=nullptr && Root->left==nullptr;
    }
    node * Delete(node * Root,T val) {
        if(Root->val<val) {
            Root->right=Delete(Root->right,val);
        }else if(Root->val>val) {
            Root->left= Delete(Root->left,val);
        }else {
            if(HasNotChild(Root)) {
                Root=nullptr;
            }else if(HasLeftChild(Root)) {
                node *tmp=Root;
                Root=Root->left;
                delete tmp;
            }else if(HasRightChild(Root)){
                node *tmp=Root;
                Root=Root->right;
                delete tmp;
            }else {
                node *mx=FMax(Root->left);
                Root->val=mx->val;
                Root->left=Delete(Root->left,mx->val);
            }
        }
        return Root;
    }
    void preorderPrint(node* root) {
        if (root == nullptr) {
            return;
        }
        preorderPrint(root->right);
        cout << root->val << " ";
        preorderPrint(root->left);
    }
public:
    binaryTree() {
        size=0;
        root=nullptr;
    }
    void insert(int val) {
        root=inserter(root,val);
    }
    node *search(T val) {
        return  Searcher(root,val);
    }
    node * Begin() {
        return root;
    }
    void Delete(T val) {
        Delete(root,val);
    }
    node * MaxElement() {
        return FMax(root);
    }
    node *MinElement() {
        return FMin(root);
    }
   void Print() {
        preorderPrint(root);
    }

};



int main() {
    for(int i = 2 ; i <= 16 ; i*=i) {
        cout<<i<<endl;
    }

}
