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

};

template <typename Key, typename Data>
struct key_comparator_sg {
    bool operator()(const my_node_sg<Key, Data>& node1, const my_node_sg<Key, Data>& node2) const {
        return node1.value < node2.value;
    }
    bool operator()(const Key& key1, const my_node_sg<Key, Data>& node2) const {
        return key1 < node2.value;
    }
    bool operator()(const my_node_sg<Key, Data>& node1, const Key& key2) const {
        return node1.value < key2;
    }
};

template <typename Key, typename Data>
using my_tree_sg = sg_set<my_node_sg<Key, Data>, compare<key_comparator_sg<Key,Data>>>;


template <typename Key, typename Data>
class sgSet
{
public:
    sgSet(float alpha = 0.75);
    ~sgSet();
    void insert(Key key, Data data);
    const my_node_sg<Key, Data>* find(Key key) const;
    void remove(Key key);
    void clear();
    void listAllElements();
private:
    my_tree_sg<Key, Data>* tree_;
};

template <typename Key, typename Data>
sgSet<Key, Data>::sgSet(float alpha) {
    tree_ = new my_tree_sg<Key, Data>();
    tree_->balance_factor(alpha);
}

template <typename Key, typename Data>
sgSet<Key,Data>::~sgSet() {
    auto it = tree_->begin();
    while (it != tree_->end()) {
        auto node = &*it;
        it = tree_->erase(it);
        delete node;
    }
    delete tree_;
}

template <typename Key, typename Data>
void sgSet<Key, Data>::insert(Key key, Data data)
{
    my_node_sg<Key, Data>* node1 = new my_node_sg<Key, Data>(key, data);
    tree_->insert_unique(*node1);
}

template <typename Key, typename Data>
const my_node_sg<Key, Data>* sgSet<Key, Data>::find(Key key) const {

    auto cmp = tree_->value_comp();
    auto it = tree_->find(key,key_comparator_sg<Key,Data>()); // pass the search node to find()
    if (it != tree_->end()) {
        return &(*it);
    }
    else {
        return nullptr;
    }
}

template <typename Key, typename Data>
void sgSet<Key, Data>::remove(Key key) {
    auto node = find(key);
    if (node != nullptr)
    {
        tree_->erase(*node); // remove node from tree
        delete node; // delete the node object
    }
    

}

template<typename Key, typename Data>
inline void sgSet<Key, Data>::clear()
{
    auto it = tree_->begin();
    while (it != tree_->end()) {
        auto node = &*it;
        it = tree_->erase(it);
        delete node;
    }
}

template <typename Key, typename Data>
void sgSet<Key, Data>::listAllElements() {
    for (auto& node : *tree_) {
        std::cout << node.value << "   " << node.data << std::endl;
    }
}