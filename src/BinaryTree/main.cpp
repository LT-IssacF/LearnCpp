#include <iostream>
#include "LearnCppConfig.h"
#ifdef USE_BITREE
#include "BiTree.h"
#endif

int main() {
    BiTree<int> T;
    T.insert(3);
    T.insert(1);
    T.insert(2);
    T.insert(5);
    T.insert(4);
    T.inorder();
    return 0;
}
