#pragma once
#include <boost/intrusive/avl_set.hpp>
#include <iostream>
#include <string>

using namespace boost::intrusive;
template <typename Key, typename Data>
struct my_node_avl : public avl_set_base_hook<> {
    Key value;
    Data data;
    my_node_avl(Key v, Data data) : value(v), data(data) {}

};

template <typename Key, typename Data>
struct key_comparator_avl {
    bool operator()(const my_node_avl<Key, Data>& node1, const my_node_avl<Key, Data>& node2) const {
        return node1.value < node2.value;
    }
    bool operator()(const Key& key1, const my_node_avl<Key, Data>& node2) const {
        return key1 < node2.value;
    }
    bool operator()(const my_node_avl<Key, Data>& node1, const Key& key2) const {
        return node1.value < key2;
    }
};

template <typename Key, typename Data>
using my_tree = avl_set<my_node_avl<Key,Data>, compare<key_comparator_avl<Key,Data>>>;

template <typename Key, typename Data>
class avlSet
{
public:
    avlSet();
    ~avlSet();
    void insert(Key key, Data data);
    const my_node_avl<Key, Data>* find(Key key) const;
    void remove(Key key);
    void clear();
    void listAllElements();
private:
    my_tree<Key, Data>* tree_;
};

template <typename Key, typename Data>
avlSet<Key,Data>::avlSet() {
    tree_ = new my_tree<Key,Data>();
}

template <typename Key, typename Data>
avlSet<Key, Data>::~avlSet() {
    auto it = tree_->begin();
    while (it != tree_->end()) {
        auto node = &*it;
        it = tree_->erase(it);
        delete node;
    }
    delete tree_;
}

template <typename Key, typename Data>
void avlSet<Key, Data>::insert(Key key, Data data)
{
    my_node_avl<Key, Data>* node1 = new my_node_avl<Key, Data>(key,data);
    tree_->insert_unique(*node1);
}

template <typename Key, typename Data>
const my_node_avl<Key, Data>* avlSet<Key, Data>::find(Key key) const {

    auto it = tree_->find(key, key_comparator_avl<Key, Data>());
    if (it != tree_->end()) {
        return &(*it);
    }
    else {
        return nullptr;
    }
}

template <typename Key, typename Data>
void avlSet<Key, Data>::remove(Key key) {
    
    auto node = find(key);
    if (node != nullptr)
    {
        tree_->erase(*node); // remove node from tree
        delete node; // delete the node object
        tree_->rebalance();
    }
}

template<typename Key, typename Data>
inline void avlSet<Key, Data>::clear()
{
    auto it = tree_->begin();
    while (it != tree_->end()) {
        auto node = &*it;
        it = tree_->erase(it);
        delete node;
    }
}

template <typename Key, typename Data>
void avlSet<Key, Data>::listAllElements() {
    for (auto& node : *tree_) {
        std::cout << node.value << "   " << node.data << std::endl;
    }
}