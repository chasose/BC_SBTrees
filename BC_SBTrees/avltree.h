#pragma once
#include <boost/intrusive/avltree.hpp>


using namespace boost::intrusive;

struct int_node;

struct int_node_base {
    avltree_node_traits<int_node>::node node_hook;

    int_node_base() = default;
    int_node_base(const int_node_base&) = delete;
    int_node_base& operator=(const int_node_base&) = delete;

    int_node_base(int_node_base&& other) noexcept
        : node_hook(std::move(other.node_hook))
    {}

    int_node_base& operator=(int_node_base&& other) noexcept {
        node_hook = std::move(other.node_hook);
        return *this;
    }
};

struct int_node : public int_node_base {
    int value;

    int_node(int v) : value(v) {}
};

using int_tree = avltree<int_node_base, avltree_node_traits<int_node>, compare<std::less<int>>>;

class avl_tree
{
private:
    int_tree tree;
    
public:
    void store() {
        tree.insert_unique(new int_node(5));
        tree.insert_unique(new int_node(2));
    }
};

