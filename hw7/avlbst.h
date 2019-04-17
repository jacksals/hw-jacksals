#ifndef RBBST_H
#define RBBST_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include <algorithm>
#include "bst.h"

struct KeyError { };

/**
* A special kind of node for an AVL tree, which adds the balance as a data member, plus
* other additional helper functions. You do NOT need to implement any functionality or
* add additional data members or helper functions.
*/
template <typename Key, typename Value>
class AVLNode : public Node<Key, Value>
{
public:
    // Constructor/destructor.
    AVLNode(const Key& key, const Value& value, AVLNode<Key, Value>* parent);
    virtual ~AVLNode();

    // Getter/setter for the node's height.
    char getBalance () const;
    void setBalance (char balance);
    void updateBalance(char diff);

    // Getters for parent, left, and right. These need to be redefined since they
    // return pointers to AVLNodes - not plain Nodes. See the Node class in bst.h
    // for more information.
    virtual AVLNode<Key, Value>* getParent() const override;
    virtual AVLNode<Key, Value>* getLeft() const override;
    virtual AVLNode<Key, Value>* getRight() const override;

protected:
    char balance_;
};

/*
  -------------------------------------------------
  Begin implementations for the AVLNode class.
  -------------------------------------------------
*/

/**
* An explicit constructor to initialize the elements by calling the base class constructor and setting
* the color to red since every new node will be red when it is first inserted.
*/
template<class Key, class Value>
AVLNode<Key, Value>::AVLNode(const Key& key, const Value& value, AVLNode<Key, Value> *parent) :
    Node<Key, Value>(key, value, parent), balance_(0)
{

}

/**
* A destructor which does nothing.
*/
template<class Key, class Value>
AVLNode<Key, Value>::~AVLNode()
{

}

/**
* A getter for the balance of a AVLNode.
*/
template<class Key, class Value>
char AVLNode<Key, Value>::getBalance() const
{
    return balance_;
}

/**
* A setter for the balance of a AVLNode.
*/
template<class Key, class Value>
void AVLNode<Key, Value>::setBalance(char balance)
{
    balance_ = balance;
}

/**
* Adds diff to the balance of a AVLNode.
*/
template<class Key, class Value>
void AVLNode<Key, Value>::updateBalance(char diff)
{
    balance_ += diff;
}

/**
* An overridden function for getting the parent since a static_cast is necessary to make sure
* that our node is a AVLNode.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getParent() const
{
    return static_cast<AVLNode<Key, Value>*>(this->parent_);
}

/**
* Overridden for the same reasons as above.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getLeft() const
{
    return static_cast<AVLNode<Key, Value>*>(this->left_);
}

/**
* Overridden for the same reasons as above.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getRight() const
{
    return static_cast<AVLNode<Key, Value>*>(this->right_);
}


/*
  -----------------------------------------------
  End implementations for the AVLNode class.
  -----------------------------------------------
*/


template <class Key, class Value>
class AVLTree : public BinarySearchTree<Key, Value>
{
public:
    virtual void insert (const std::pair<const Key, Value> &new_item); // TODO
    virtual void remove(const Key& key);  // TODO


protected:
    virtual void nodeSwap( AVLNode<Key,Value>* n1, AVLNode<Key,Value>* n2);

    // Add helper functions here
    void rightRotate(const Key& key);
    void leftRotate(const Key& key);
    void removeFix(AVLNode<Key, Value>* n, int diff);
    void insertFix(AVLNode<Key, Value>* p, AVLNode<Key, Value>* n);
    int fndiff(AVLNode<Key, Value>* n);
    void changebalances(AVLNode<Key,Value>* item);

};

template<class Key, class Value>
void AVLTree<Key, Value>::changebalances(AVLNode<Key,Value>* item)
{
    if(item->getParent()->getBalance() == -1 || item->getParent()->getBalance() == 1)
    {
        item->getParent()->setBalance(0);
    }
    else
    {
        AVLNode<Key, Value>* curr = item;
        int b;
        while(curr->getParent() != NULL)
        {
        std::cout << "curr parent is " << curr->getParent()->getValue() << std::endl;
        std::cout << "balance of " << curr->getParent()->getValue() << " :"<< (int)curr->getParent()->getBalance() << std::endl;
            if(curr->getParent()->getRight() == curr)
            {
                b = 1;
                std::cout << "adding 1 to " << curr->getParent()->getValue() << std::endl;
            }
            else
            {
                b = -1;
                std::cout << "subtracting 1 to " << curr->getParent()->getValue() << std::endl;
            }
            curr->getParent()->updateBalance(b);
            std::cout << "new balance of " << curr->getParent()->getValue() << " is "<< (int)curr->getParent()->getBalance() << std::endl;
            curr = curr->getParent();
        }
        insertFix(item->getParent(), item);
    }
}

template<class Key, class Value>
void AVLTree<Key, Value>::insert(const std::pair<const Key, Value> &new_item)
{
    // TODO
    if(BinarySearchTree<Key, Value>::empty())
    {
        AVLNode<Key, Value>* i = new AVLNode<Key, Value>(new_item.first, new_item.second, NULL); //constructor sets balance to 0
        this->root_ = i;
    }
    else
    {

        bool done = false;
        if(BinarySearchTree<Key, Value>::internalFind(new_item.first) != NULL)
        {
            AVLNode<Key, Value>* replace = static_cast<AVLNode<Key, Value>* >(BinarySearchTree<Key, Value>::internalFind(new_item.first));
            replace->setValue(new_item.second);
            std::cout << "inserting " << new_item.second << std::endl;
            done = true;
        }
        Node<Key, Value>* curr = this->root_;
        while(!done)
        {
            if(new_item.first > curr->getKey())
            {
                if(curr->getRight() == nullptr)
                {
                    AVLNode<Key, Value>* k = new AVLNode<Key, Value>(new_item.first, new_item.second, static_cast<AVLNode<Key, Value>* >(curr));
                    curr->setRight(k);
                    std::cout << "inserting " << new_item.second << std::endl;
                    changebalances(k);
                    done = true;
                }
                else
                {
                    curr = curr->getRight();
                }
            }
            else //(new_item->getValue() < curr->getValue())
            {
                if(curr->getLeft() == nullptr)
                {
                    AVLNode<Key, Value>* k = new AVLNode<Key, Value>(new_item.first, new_item.second, static_cast<AVLNode<Key, Value>* >(curr));
                    curr->setLeft(k);
                    std::cout << "inserting " << new_item.second << std::endl;
                    changebalances(k);
                    done = true;
                }
                else
                {
                    curr = curr->getLeft();
                }
            }
        }
        // AVLNode<Key, Value>* item = static_cast<AVLNode<Key, Value>* >(BinarySearchTree<Key, Value>::internalFind(new_item.first));
        // item->setBalance(0);
        // std::cout << "balance: " << (int)item->getBalance() << std::endl;
        
    }
}
template<class Key, class Value>
void AVLTree<Key, Value>:: insertFix(AVLNode<Key, Value>* p, AVLNode<Key, Value>* n)
{
    if(p == NULL || p->getParent() == NULL)
    {
        return;
    }
    AVLNode<Key, Value>* g = p->getParent();
    //p is left child
    if(g->getLeft() == p)
    {
        //g->updateBalance(-1);
        if(g->getBalance() == 0)
        {
            return;
        }
        else if(g->getBalance() == -1)
        {
            insertFix(g, p);
        }
        else if(g->getBalance() == -2)
        {
            std::cout << "left ROTATION SHOULD BE HAPPENING" << std::endl;
            AVLNode<Key, Value>* curr = g;
            while(curr->getParent() != NULL)
                {
                    curr->getParent()->updateBalance(1);
                    curr = curr->getParent();
                }
            //Zig-zig
            if(p->getBalance() == -1 || p->getBalance() == 0)
            {
                std::cout << "in here" << std::endl;
                std::cout << "rotating on " << g->getValue() << std::endl;
                //std::cout << "x parent is " << g->getParent()->getValue() << std::endl;
                // if(g->getParent() != NULL)
                // {
                //     g->getParent()->updateBalance(1);
                // }
                rightRotate(g->getKey());
                p->setBalance(0);
                g->setBalance(0);
            }
            //Zig-zag
            else if(p->getBalance() == 1)
            {
                /////////////////////////////////////////
                // if(g->getParent() != NULL)
                // {
                //     g->getParent()->updateBalance(1);
                // }
                ///////////////////////////////////
                leftRotate(p->getKey());
                rightRotate(g->getKey());
                if(n->getBalance() == -1)
                {
                    p->setBalance(0);
                    g->setBalance(1);
                    n->setBalance(0);
                }
                else if(n->getBalance() == 0)
                {
                    p->setBalance(0);
                    g->setBalance(0);
                    n->setBalance(0);
                }
                else if(n->getBalance() == 1)
                {
                    p->setBalance(-1);
                    g->setBalance(0);
                    n->setBalance(0);
                }
            }
        }
    }
    //p is right child
    else
    {
        std::cout << "HERERERERERE" << std::endl;
        std::cout << "balance of " << g->getValue() << " is " << (int)g->getBalance() << std::endl;
        if(g->getBalance() == 0)
        {
            return;
        }
        else if(g->getBalance() == 1)
        {
            insertFix(g, p);
        }
        else if(g->getBalance() == 2)
        {
            std::cout << "right ROTATION SHOULD BE HAPPENING" << std::endl;
            AVLNode<Key, Value>* curr = g;
            while(curr->getParent() != NULL)
                {
                    curr->getParent()->updateBalance(-1);
                    curr = curr->getParent();
                }
            //Zig-zig
            if(p->getBalance() == 1 || p->getBalance() == 0)
            {
                // if(g->getParent() != NULL)
                // {
                //     g->getParent()->updateBalance(-1);
                // }
                leftRotate(g->getKey());
                p->setBalance(0);
                std::cout << "gPa is " << g->getValue() << std::endl;
                g->setBalance(0);
            }
            //Zig-zag
            else if(p->getBalance() == -1)
            {
                /////////////////////////////////////////
                // if(g->getParent() != NULL)
                // {
                //     g->getParent()->updateBalance(-1);
                // }
                ///////////////////////////////////
                rightRotate(p->getKey());
                leftRotate(g->getKey());
                if(n->getBalance() == 1)
                {
                    p->setBalance(0);
                    g->setBalance(-1);
                    n->setBalance(0);
                }
                else if(n->getBalance() == 0)
                {
                    p->setBalance(0);
                    g->setBalance(0);
                    n->setBalance(0);
                }
                else if(n->getBalance() == -1)
                {
                    p->setBalance(1);
                    g->setBalance(0);
                    n->setBalance(0);
                }
            }
        }
    }
}

template<class Key, class Value>
void AVLTree<Key, Value>:: remove(const Key& key)
{
    // TODO
    if(this->root_ == NULL)
    {
        return;
    }
    AVLNode<Key, Value>* curr = static_cast<AVLNode<Key, Value>* >(BinarySearchTree<Key, Value>::internalFind(key));
    if(curr == NULL)
    {
        return;
    }
    AVLNode<Key, Value>* pcurr = curr->getParent();
    std::cout << "here" << std::endl;
    // std::cout << "removing " << curr->getValue() << std::endl;
    // std::cout << "with balance of " << (int)curr->getBalance() << std::endl;
    // std::cout << "pcurr is " << pcurr->getValue() << std::endl;
    // std::cout << "with balance of " << (int)pcurr->getBalance() << std::endl;
    //std::cout << curr->getRight()->getValue() << std::endl;
    //std::cout << curr->getLeft()->getValue() << std::endl;
    int diff = 0;
    // std::cout << "curr is " << curr->getValue() << std::endl;
    // std::cout << "pcurr right " << pcurr->getRight()->getValue() << std::endl;
    // std::cout << "pcurr left " << pcurr->getLeft()->getValue() << std::endl;

    if(pcurr != NULL)
    {
        //curr is a left child
        if(pcurr->getLeft() == curr)
        {
            std::cout << "curr is left child" << std::endl;
            diff = 1;
        }
        //curr is a right child
        else
        {
            std::cout << "why is curr right?" << std::endl;
            diff = -1;
        }
        //update balance of parent
        //std::cout << "before update" << std::endl;
        //pcurr->updateBalance(diff);
        //std::cout << "after update" << std::endl;
    }
    if(curr == this->root_)
    {
        if(curr->getLeft() != NULL && curr->getRight() != NULL)
        {
            AVLNode<Key, Value>* pred = static_cast<AVLNode<Key, Value>* >(BinarySearchTree<Key,Value>::predecessor(curr));
            nodeSwap(curr, pred);
        }
        else if(curr->getLeft() == NULL && curr->getRight() != NULL)
        {
            curr->getRight()->setParent(NULL);
            this->root_ = curr->getRight();
            delete curr;
            return;
        }
        else if(curr->getLeft() != NULL && curr->getRight() == NULL)
        {
            curr->getLeft()->setParent(NULL);
            this->root_ = curr->getLeft();
            delete curr;
            return;
        }
        else if(curr->getLeft() == NULL && curr->getRight() == NULL)
        {
            std::cout << "no way" << std::endl;
            this->root_ = NULL;
            delete curr;
            return;
        }
    }
    std::cout << "here2" << std::endl;
    //NOT ROOT
    //has 2 children
    if(curr->getRight() != NULL && curr->getLeft() != NULL)
    {
        AVLNode<Key, Value>* pred = static_cast<AVLNode<Key, Value>* >(BinarySearchTree<Key,Value>::predecessor(curr));
        if(pred != NULL)
        {
            nodeSwap(curr, pred);   
        }
    }
    std::cout << "here3" << std::endl;
    //has 1 child
    if(curr->getRight() != NULL)
    {
        curr->getParent()->setRight(curr->getRight());
        curr->getRight()->setParent(curr->getParent());
    }
    else if(curr->getLeft() != NULL)
    {
        std::cout << "made it" << std::endl;
        curr->getParent()->setLeft(curr->getLeft());
        curr->getLeft()->setParent(curr->getParent());
    }
    //has no children
    else
    {
        std::cout << "in correct spot" << std::endl;
        AVLNode<Key, Value>* p = curr->getParent();
        if(p->getLeft() == curr)
        {
            std::cout << "huh?" << std::endl;
            p->setLeft(NULL);
            std::cout << "here" << std::endl;
        }
        if(p->getRight() == curr)
        {
            p->setRight(NULL);
        }
    }
    delete curr;
    // std::cout << "pcurr is " << pcurr->getValue() << std::endl;
    // std::cout << "pcurr balance is " << (int)pcurr->getBalance() << std::endl;
    std::cout << "diff is " << diff << std::endl;
    //std::cout << "pcurr r is " << pcurr->getRight()->getValue() << std::endl;
    removeFix(pcurr, diff);
    std::cout << "after fix" << std::endl;
    //curr is the root
}
template<class Key, class Value>
int AVLTree<Key, Value>::fndiff(AVLNode<Key, Value>* n)
{
    int ndiff = 0;
    if(n->getParent() != NULL)
    {
        if(n->getParent()->getLeft() == n)
        {
            ndiff = 1;
        }
        else
        {
            ndiff = -1;
        }
    }
    return ndiff;
}
template<class Key, class Value>
void AVLTree<Key, Value>::removeFix(AVLNode<Key, Value>* n, int diff)
{
    if(n == NULL)
    {
        return;
    }
    std::cout << "n balance is " << (int)n->getBalance() << std::endl;
    std::cout << "diff is " << diff << std::endl;
    AVLNode<Key, Value>* p = n->getParent();
    int ndiff;
    if(fndiff(n) != 0)
    {
        ndiff = fndiff(n);
    }
    std::cout << ndiff << std::endl;
    std::cout << (int)n->getBalance() << std::endl;
    //Case 1
    if(n->getBalance() + diff == -2)
    {
        AVLNode<Key, Value>* c = n->getLeft();
        if(c == NULL)
        {
            std::cout << "c is NULL" << std::endl;
        }
        //Zig-Zig case
        if(c->getBalance() == -1 || c->getBalance() == 0)
        {
            rightRotate(n->getKey());
            if(c->getBalance() == -1)
            {
                n->setBalance(0);
                c->setBalance(0);
                removeFix(p, ndiff);
            }
            else if(c->getBalance() == 0)
            {
                n->setBalance(-1);
                c->setBalance(1);
            }
        }
        //Zig-Zag case
        else if(c->getBalance() == 1)
        {
            AVLNode<Key, Value>* g = c->getRight();
            leftRotate(c->getKey());
            rightRotate(n->getKey());
            if(g->getBalance() == 1)
            {
                n->setBalance(0);
                c->setBalance(-1);
                g->setBalance(0);
            }
            else if(g->getBalance() == 0)
            {
                n->setBalance(0);
                c->setBalance(0);
                //g balance already 0
            }
            else if(g->getBalance() == -1)
            {
                n->setBalance(1);
                c->setBalance(0);
                g->setBalance(0);
            }
            removeFix(p, ndiff);
        }
    }
    else if(n->getBalance() + diff == 2)
    {
        AVLNode<Key, Value>* c = n->getRight();
        //Zig-Zig case
        if(c->getBalance() == -1 || c->getBalance() == 0)
        {
            leftRotate(n->getKey());
            if(c->getBalance() == 1)
            {
                n->setBalance(0);
                c->setBalance(0);
                removeFix(p, ndiff);
            }
            else if(c->getBalance() == 0)
            {
                n->setBalance(1);
                c->setBalance(-1);
            }
        }
        //Zig-Zag case
        else if(c->getBalance() == -1)
        {
            AVLNode<Key, Value>* g = c->getLeft();
            rightRotate(c->getKey());
            leftRotate(n->getKey());
            if(g->getBalance() == -1)
            {
                n->setBalance(0);
                c->setBalance(1);
                g->setBalance(0);
            }
            else if(g->getBalance() == 0)
            {
                n->setBalance(0);
                c->setBalance(0);
                //g balance already 0?
            }
            else if(g->getBalance() == 1)
            {
                n->setBalance(-1);
                c->setBalance(0);
                g->setBalance(0);
            }
            removeFix(p, ndiff);
        }
    }
    //Case 2
    else if(n->getBalance() + diff == -1)
    {
        n->setBalance(-1);
    }
    else if(n->getBalance() + diff == 1)
    {
        n->setBalance(1);
    }
    //Case 3
    else if(n->getBalance() + diff == 0)
    {
        n->setBalance(0);
        int ndiff;
        if(fndiff(n) != 0)
        {
            ndiff = fndiff(n);
            removeFix(n->getParent(), ndiff);
        }
    }
}

template<class Key, class Value>
void AVLTree<Key, Value>::nodeSwap( AVLNode<Key,Value>* n1, AVLNode<Key,Value>* n2)
{
    BinarySearchTree<Key, Value>::nodeSwap(n1, n2);
    char tempB = n1->getBalance();
    n1->setBalance(n2->getBalance());
    n2->setBalance(tempB);
}
template<class Key, class Value>
void AVLTree<Key, Value>::rightRotate(const Key& key)
{
    AVLNode<Key, Value>* z = static_cast<AVLNode<Key, Value>* >(BinarySearchTree<Key, Value>::internalFind(key));
    if(z == NULL)
    {
        return;
    }

    //z takes c's place
    //c becomes child of z
    AVLNode<Key, Value>* y = z->getLeft();

    if(z == this->root_)
    {
        this->root_ = y;
    }
    if(z->getParent() != NULL)
    {
        if(z->getParent()->getRight() == z)
        {
            z->getParent()->setRight(y);
        }
        else
        {
            z->getParent()->setLeft(y);
        }
    }
    AVLNode<Key, Value>* c = y->getRight();
    z->setLeft(c);
    if(y->getRight() != NULL) //if(c != NULL)
    {
        c->setParent(z);
    }
    y->setParent(z->getParent());
    y->setRight(z);
    z->setParent(y);
}
template<class Key, class Value>
void AVLTree<Key, Value>::leftRotate(const Key& key)
{
    AVLNode<Key, Value>* x = static_cast<AVLNode<Key, Value>* >(BinarySearchTree<Key, Value>::internalFind(key));
    if(x == NULL)
    {
        return;
    }
    AVLNode<Key, Value>* y = x->getRight();
    if(x == this->root_)
    {
        this->root_ = y;
    }
    if(x->getParent() != NULL)
    {
        if(x->getParent()->getRight() == x)
        {
            x->getParent()->setRight(y);
        }
        else
        {
            x->getParent()->setLeft(y);
        }
    }
    AVLNode<Key, Value>* b = y->getLeft();
    y->setLeft(x);
    y->setParent(x->getParent());
    x->setParent(y);
    x->setRight(b);
    if(b != NULL)
    {
        b->setParent(x);
    }
}

#endif
