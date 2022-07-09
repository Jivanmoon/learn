#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    TreeNode(const string &s = string()):
        value(s), count(new int(1)), left(nullptr), right(nullptr) {}
    TreeNode(const TreeNode &rhs):
        value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right) {
            ++*count;
        }
    TreeNode &operator=(const TreeNode &rhs) {
        ++*rhs.count;
        if(--*count == 0) {
            if(left) {
                delete left;
            }
            if(right) {
                delete right;
            }
            delete count;
        }
        value = rhs.value;
        count = rhs.count;
        left = rhs.left;
        right = rhs.right;
        return *this;
    }
    ~TreeNode() {
        if(--*count == 0) {
            if(left) {
                delete left;
            }
            if(right) {
                delete right;
            }
            delete count;
        }
    }
    
private:
    string value;
    int *count;
    TreeNode *left;
    TreeNode *right;
};

class BinStrTree {

public:
    BinStrTree(): root(new TreeNode()) {}
    BinStrTree(const BinStrTree &rhs): root(new TreeNode(*rhs.root)) {}
    BinStrTree &operator=(const BinStrTree &rhs) {
        auto newp = new TreeNode(*rhs.root);
        delete root;
        root = newp;
        return *this;
    }
    ~BinStrTree() {
        delete root;
    }
private:
    TreeNode *root;
};