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

    bool operator<(const my_node_avl& other) const {
        return value < other.value;
    }
};

template <typename Key, typename Data>
using my_tree = avl_set<my_node_avl<Key,Data>>;

template <typename Key, typename Data>
class avlSet
{
public:
    avlSet();
    ~avlSet();
    void insert(Key key, Data data);
    const my_node_avl<Key, Data>* find(Key key) const;
    void remove(Key key);
    void listAllElements();
private:
    my_tree<Key, Data>* tree_;
};

template <typename Key, typename Data>
avlSet<Key,Data>::avlSet() {
    tree_ = new my_tree<Key,Data>();
}

template <typename Key, typename Data>
void avlSet<Key, Data>::insert(Key key, Data data)
{
    my_node_avl<Key, Data>* node1 = new my_node_avl<Key, Data>(key,data);
    tree_->insert_unique(*node1);
}

template <typename Key, typename Data>
const my_node_avl<Key, Data>* avlSet<Key, Data>::find(Key key) const {
    
    my_node_avl<Key, Data> search_node(key, Data()); // create a search node with the given key
    auto it = tree_->find(search_node); // pass the search node to find()
    if (it != tree_->end()) {
        return &(*it);
    }
    else {
        return nullptr;
    }
}

template <typename Key, typename Data>
void avlSet<Key, Data>::remove(Key key) {
    my_node_avl<Key, Data> search_node(key, Data()); // create a search node with the given key
    auto it = tree_->find(search_node); // pass the search node to find()
    if (it == tree_->end()) {
        return; // Node not found, do nothing
    }

    // Node found, remove it
    tree_->erase(it);

    // Now, rebalance the tree to maintain the AVL property
    tree_->rebalance();
}

template <typename Key, typename Data>
void avlSet<Key, Data>::listAllElements() {
    for (auto& node : *tree_) {
        std::cout << node.value << "   " << node.data << std::endl;
    }
}