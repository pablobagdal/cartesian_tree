#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// treap - tree + heap
class CartessianTree
{
private:
    /* data */
    void successor();
public:
    CartessianTree(/* args */);
    ~CartessianTree();
    void merge(); // объединение деревьев
    void split(); // разрезание деревьев по ключу
    void min();
    void max();
};

CartessianTree::CartessianTree(/* args */)
{
}

CartessianTree::~CartessianTree()
{
}

void CartessianTree::merge()
{
    
}

void CartessianTree::split()
{

}

void CartessianTree::successor()
{

}

void min()
{

}

void max()
{

}

class BST
{
private:
    struct Node {
        int data;
        Node* left = nullptr;
        Node* right = nullptr;
    } *root = nullptr;
public:
    BST(/* args */);
    ~BST();
};

BST::BST(/* args */)
{
}

BST::~BST()
{
}


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
