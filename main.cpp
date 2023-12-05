#include <iostream>
#include <algorithm>
#include <random>

using std::cout;
using std::cin;
using std::endl;

// treap - tree + heap

static std::minstd_rand generator;

struct Node {
    int key, priority;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int key): key{key}, priority{generator()} {}
}

class CartessianTree
{
private:
    Node *root;
    // void successor();
    // объединение деревьев
    static Node* merge(Node* a, Node* b) 
    {
        if(!a || !b) {
            return a ? a : b;
        }
        if(a->priority > b->priority) {
            a->right = merge(a->right, b);
            return a;
        } else {
            b->left = merge(a, b->left);
            return b;
        }
    }
    // разрезание деревьев по ключу
    static void split(Node* n, int key, Node *&a, Node*&b) {
    CartessianTree(/* args */) : root {nullptr}{}
    ~CartessianTree(){}
        if(!n) {
            a = b = nullptr;
            return;
        }

        if(n->key < key) {
            /*
                 n
            [n->left]  [n->right ]
            */
            // теперь правый должен дробиться
            /*
                    a=n
            [n->left]  [n->right = a', b = b']
            */
           split(n->right, key, n->right, b);
           a = n;
        } else {
            /*
                     n
            [n->left]  [n->right ]
            */
            // теперь левый должен дробиться
            /*
                b=n
            [a=a', n->left=b']  [n->right]
            */
           split(n->left, key, a, n->left);
           n = b;
        }
    }
public:

    void min();
    void max();
};

std::minstd_rand generator;

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdin);

    return 0;
}
