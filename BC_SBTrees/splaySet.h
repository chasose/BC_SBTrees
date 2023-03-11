#pragma once
#include <boost/intrusive/splay_set.hpp>
#include <boost/intrusive/bs_set_hook.hpp>
#include <iostream>
#include <string>

using namespace boost::intrusive;
template <typename Key, typename Data>
struct my_node_splay : public bs_set_base_hook<> {
    Key value;
    Data data;
    my_node_splay(Key v, Data data) : value(v), data(data) {}

    bool operator<(const my_node_splay& other) const {
        return value < other.value;
    }
};

template <typename Key, typename Data>
using my_tree_splay = splay_set<my_node_splay<Key, Data>>;

template <typename Key, typename Data>
class splaySet
{
public:
    splaySet();
    ~splaySet();
    void insert(Key key, Data data);
    const my_node_splay<Key, Data>* find(Key key) const;
    void remove(Key key);
    void listAllElements();
private:
    my_tree_splay<Key, Data>* tree_;
};

template <typename Key, typename Data>
splaySet<Key, Data>::splaySet() {
    tree_ = new my_tree_splay<Key, Data>();
}

template <typename Key, typename Data>
void splaySet<Key, Data>::insert(Key key, Data data)
{
    my_node_splay<Key, Data>* node1 = new my_node_splay<Key, Data>(key, data);
    tree_->insert_unique(*node1);
}

template <typename Key, typename Data>
const my_node_splay<Key, Data>* splaySet<Key, Data>::find(Key key) const {

    my_node_splay<Key, Data> search_node(key, Data()); // create a search node with the given key
    auto it = tree_->find(search_node); // pass the search node to find()
    if (it != tree_->end()) {
        return &(*it);
    }
    else {
        return nullptr;
    }
}

template <typename Key, typename Data>
void splaySet<Key, Data>::remove(Key key) {
    my_node_splay<Key, Data> search_node(key, Data()); // create a search node with the given key
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
void splaySet<Key, Data>::listAllElements() {
    for (auto& node : *tree_) {
        std::cout << node.value << "   " << node.data << std::endl;
    }
}