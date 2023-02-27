#include <iostream>
// 类模板不能分离编译
template <typename T>
class BiTree;

template <typename T>
class BiNode {
    friend class BiTree<T>;
public:
    BiNode(const T &val) : data(val) {
        lchild = rchild = nullptr;
    }
    T getData() const {
        return data;
    }
    void insert_node(const T &val) { // 不能给this直接赋值
        if(val < data) {
            if(lchild == nullptr) {
                lchild = new BiNode(val);
            } else {
                lchild->insert_node(val);
            }
        } else {
            if(rchild == nullptr) {
                rchild = new BiNode(val);
            } else {
                rchild->insert_node(val);
            }
        }
    }
    void lchild_leaf(BiNode *leaf, BiNode *subTree) {
        while(subTree->lchild != nullptr) {
            subTree = subTree->lchild;
        } subTree->lchild = leaf;
    }
    void remove_value(const T &val, BiNode *&pre) {
        if(val < data) {
            if(lchild == nullptr) {
                std::cout << "NO VALUE!" <<std::endl;
                return;
            } else {
                lchild->remove_value(val, lchild);
            }
        } else if(val > data) {
            if(rchild == nullptr) {
                std::cout << "NO VALUE!" <<std::endl;
                return;
            } else {
                rchild->remove_value(val, rchild);
            }
        } else { // 找到需要删除的节点了
            if(rchild != nullptr) {
                pre = rchild;
                if(lchild != nullptr) {
                    if(pre->lchild == nullptr) {
                        pre->lchild = lchild;
                    } else {
                        lchild_leaf(lchild, pre->lchild);
                    }
                }
            } else {
                pre = lchild;
            } delete this;
        }
    }
    void inorder() const {
        if(this != nullptr) {
            lchild->inorder();
            std::cout << data << " ";
            rchild->inorder();
        }
    }
private:
    T data;
    BiNode *lchild, *rchild;
};

template <typename T>
class BiTree {
public:
    BiTree() {
        root = nullptr;
    }
    BiTree(const T &val) {
        root = new BiNode(val);
    }
    ~BiTree() {
        delete root;
    }
    void insert(const T &val) {
        if(root == nullptr) {
            root = new BiNode(val);
        } else {
            root->insert_node(val);
        }
    }
    void remove_root() {
        if(root == nullptr) {
            return;
        } if(root->lchild == nullptr) {
            root = nullptr;
        } else {
            BiNode<T> *tmp = root;
            root = root->lchild;
            delete tmp;
        }
    }
    void remove(const T &val) {
        if(root != nullptr) {
            if(val == root->data && root->rchild == nullptr) { // 删除根节点
                remove_root();
            } else {
                root->remove_value(val, root);
            }
        }
    }
    void clear() {
        if(root != nullptr) {
            clear(root);
            root = nullptr;
        }
    }
    void inorder() {
        root->inorder();
    }
private:
    BiNode<T> *root;
    void clear(BiNode<T> *p) {
        if(p != nullptr) {
            clear(p->lchild);
            clear(p->rchild);
            delete p;
        }
    }
};
