#include <iostream>
#include <algorithm>
#include <random>

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
        int key;
        Node* left = nullptr;
        Node* right = nullptr;
        Node(int key): key{key} {}
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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdin);

    return 0;
}
