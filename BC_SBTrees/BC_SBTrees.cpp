#include <boost/intrusive/avl_set.hpp>
#include <iostream>
#include "avlSet.h"
#include "splaySet.h"
#include "sgSet.h"

using namespace std;

int main() {
    avlSet<int,int>* avl_tree = new avlSet<int, int>();
    splaySet<int, int>* splay_tree = new splaySet<int, int>();
    sgSet<int, int>* sg_tree = new sgSet<int, int>();

    sg_tree->insert(1, 1);
    sg_tree->insert(2, 2);
    sg_tree->insert(3, 3);

    avl_tree->insert(1, 1);
    avl_tree->insert(2, 2);
    avl_tree->insert(3, 3);
    
    splay_tree->insert(1, 1);
    splay_tree->insert(2, 2);
    splay_tree->insert(3, 3);

    const my_node_sg<int, int>* najdeny;
    najdeny = sg_tree->find(1);
    if (najdeny == nullptr)
    {
        cout << "nebol najdeny" << endl;
    }
    else
    {
        cout << "bol najdeny a ma hodnotu "<< najdeny->data << endl;
    }
    /*avl_tree->listAllElements();
    avl_tree->remove(2);
    cout << "" <<endl;
    avl_tree->listAllElements();*/

    /*splay_tree->listAllElements();
    splay_tree->remove(2);
    cout << "" << endl;
    splay_tree->listAllElements();*/

    sg_tree->listAllElements();
    sg_tree->remove(2);
    cout << "" << endl;
    sg_tree->listAllElements();
    return 0;
}