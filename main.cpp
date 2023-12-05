#include <iostream>
#include <algorithm>
#include <random>

using std::cout;
using std::cin;
using std::endl;

// treap - tree + heap

static std::minstd_rand generator;


typedef struct Node {
    int key, priority;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int key): key{key}, priority(generator()) {}
} Node;

class TreeIterator : public std::iterator<std::input_iterator_tag, Node*>
{
    friend class CartessianTree;
private:
    TreeIterator(Node* node) : node(node)
    {

    }
public:
    TreeIterator(const TreeIterator& it) : node(it.node)
    {

    }

    bool operator==(const TreeIterator& it) const
    {
        return this->node == it.node;
    }
    bool operator!=(const TreeIterator& it) const
    {
        return !(*this == it);
    }

    typename TreeIterator::reference operator*()
    {
        return node;
    }

    TreeIterator& operator++() {
        ++node;
        return *this;
    }
private:
    Node *node;
};



class CartessianTree
{
public:
    typedef TreeIterator iterator;
    typedef TreeIterator const_iterator;

    iterator begin() const {
        Node* node = this->root;
        while(node->left != nullptr) {
            node = node->left;
        }
        
        return iterator(node);
    }
    iterator end() {
        Node* node = this->root;
        while(node->right != nullptr) {
            node = node->right;
        }
        // end must be next to the real last, but what is +1 to max value node? 
        // Guess it's not what supposed to find
        return iterator(node+1);
    }

    CartessianTree(/* args */) : root {nullptr}{}
    ~CartessianTree(){}

    int min(Node* node) const {
        if(!node) {
            return -1;
        }

        while(node->left) {
            node = node->left;
        }

        return node->key;
    }
    int max(Node* node) const {
        if(!node) {
            return -1;
        }

        while(node->right) {
            node = node->right;
        }

        return node->key;
    }

    void insert(int key) {
        Node *less, *greater;

        split(root, key, less, greater);

        less = merge(less, new Node(key));
        root = merge(less, greater);
    }

    bool contains(int key) {
        Node *less, *equal, *greater;
        split(root, key, less, greater);
        split(greater, key + 1, equal, greater);

        bool result = equal;

        // собрать дерево обратно
        greater = merge(equal, greater);
        root = merge(less, greater);    

        return result;
    }

    void erase(int key) {
        Node *less, *equal, *greater;
        split(root, key, less, greater);
        split(greater, key + 1, equal, greater);

        root = merge(less, greater);

        // необходимо очистить память от equal
    }

    int next(int key) {
        Node *less, *greater;
        split(root, key, less, greater);
        // split(greater, key, equal, greater);
        int res {min(greater)};

        root = merge(less, greater);

        return res;
    }
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
        if(!n) {
            // если дерево пусто, то и результатом его деления будут 2 пустых
            // дерева. Делаем всё null ptr и возвращаемся
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
            b = n;
        }
    }
};

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    CartessianTree treap;

    int n;
    cin >> n;

    int prevRes {};

    for (int i = 0; i < n; i++)
    {
        std::string command;
        int key;
        cin >> command >> key;

        if(command == "+") {
            // key = (key + prevRes) % static_cast<int>(1e9);
            if(!treap.contains(key)) {
                treap.insert(key);
            }
            prevRes = 0;
        } else {
            prevRes = treap.next(key);
            cout << prevRes << endl;
        }        
    }
    

    return 0;
}
