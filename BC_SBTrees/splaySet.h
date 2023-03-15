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
};

template <typename Key, typename Data>
struct key_comparator_splay {
    bool operator()(const my_node_splay<Key, Data>& node1, const my_node_splay<Key, Data>& node2) const {
        return node1.value < node2.value;
    }
    bool operator()(const Key& key1, const my_node_splay<Key, Data>& node2) const {
        return key1 < node2.value;
    }
    bool operator()(const my_node_splay<Key, Data>& node1, const Key& key2) const {
        return node1.value < key2;
    }
};

template <typename Key, typename Data>
using my_tree_splay = splay_set<my_node_splay<Key, Data>, compare<key_comparator_splay<Key, Data>>>;

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
splaySet<Key, Data>::~splaySet() {
    auto it = tree_->begin();
    while (it != tree_->end()) {
        auto node = &*it;
        it = tree_->erase(it);
        delete node;
    }
    delete tree_;
}

template <typename Key, typename Data>
void splaySet<Key, Data>::insert(Key key, Data data)
{
    my_node_splay<Key, Data>* node1 = new my_node_splay<Key, Data>(key, data);
    tree_->insert_unique(*node1);
}

template <typename Key, typename Data>
const my_node_splay<Key, Data>* splaySet<Key, Data>::find(Key key) const {
    auto it = tree_->find(key, key_comparator_splay<Key, Data>());
    if (it != tree_->end()) {
        return &(*it);
    }
    else {
        return nullptr;
    }
}

template <typename Key, typename Data>
void splaySet<Key, Data>::remove(Key key) {
    auto node = find(key);
    if (node != nullptr)
    {
        tree_->erase(*node); // remove node from tree
        delete node; // delete the node object
    }
}

template <typename Key, typename Data>
void splaySet<Key, Data>::listAllElements() {
    for (auto& node : *tree_) {
        std::cout << node.value << "   " << node.data << std::endl;
    }
}