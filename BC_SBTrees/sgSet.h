#pragma once
#include <boost/intrusive/sg_set.hpp>
#include <boost/intrusive/bs_set_hook.hpp>
#include <iostream>
#include <string>

using namespace boost::intrusive;
template <typename Key, typename Data>
struct my_node_sg : public bs_set_base_hook<> {
    Key value;
    Data data;
    my_node_sg(Key v, Data data) : value(v), data(data) {}

    bool operator<(const my_node_sg& other) const {
        return value < other.value;
    }
};

template <typename Key, typename Data>
using my_tree_sg = sg_set<my_node_sg<Key, Data>>;

template <typename Key, typename Data>
class sgSet
{
public:
    sgSet();
    ~sgSet();
    void insert(Key key, Data data);
    const my_node_sg<Key, Data>* find(Key key) const;
    void remove(Key key);
    void listAllElements();
private:
    my_tree_sg<Key, Data>* tree_;
};

template <typename Key, typename Data>
sgSet<Key, Data>::sgSet() {
    tree_ = new my_tree_sg<Key, Data>();
}

template <typename Key, typename Data>
void sgSet<Key, Data>::insert(Key key, Data data)
{
    my_node_sg<Key, Data>* node1 = new my_node_sg<Key, Data>(key, data);
    tree_->insert_unique(*node1);
}

template <typename Key, typename Data>
const my_node_sg<Key, Data>* sgSet<Key, Data>::find(Key key) const {

    my_node_sg<Key, Data> search_node(key, Data()); // create a search node with the given key
    auto it = tree_->find(search_node); // pass the search node to find()
    if (it != tree_->end()) {
        return &(*it);
    }
    else {
        return nullptr;
    }
}

template <typename Key, typename Data>
void sgSet<Key, Data>::remove(Key key) {
    my_node_sg<Key, Data> search_node(key, Data()); // create a search node with the given key
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
void sgSet<Key, Data>::listAllElements() {
    for (auto& node : *tree_) {
        std::cout << node.value << "   " << node.data << std::endl;
    }
}