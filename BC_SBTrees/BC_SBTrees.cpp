#include <boost/intrusive/avl_set.hpp>
#include <iostream>
#include "avlSet.h"
#include "splaySet.h"
#include "sgSet.h"
#include "heap_monitor.h"
#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include "InsertTester.h"

using namespace std;

int main() {
    initHeapMonitor();

    /*avlSet<int,int>* avl_tree = new avlSet<int, int>();
    splaySet<int, int>* splay_tree = new splaySet<int, int>();*/
    

   /* sg_tree->insert(1, 1);
    sg_tree->insert(2, 2);
    sg_tree->insert(3, 3);
    sg_tree->insert(4, 1);
    sg_tree->insert(5, 2);
    sg_tree->insert(6, 3);

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
    avl_tree->listAllElements();
    avl_tree->remove(2);
    cout << "" <<endl;
    avl_tree->listAllElements();

    splay_tree->listAllElements();
    splay_tree->remove(2);
    cout << "" << endl;
    splay_tree->listAllElements();

    sg_tree->listAllElements();
    sg_tree->remove(10);
    cout << "" << endl;
    sg_tree->listAllElements();*/

    /*std::string filename = "output2.csv";
    std::ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        std::cout << "Error opening file: " << filename << std::endl;
        return 1;
    }*/
    
    //for (int a = 1; a < 1000; a++)
    //{
    //    sgSet<int, int>* splay_tree = new sgSet<int, int>();

    //    auto startTime = std::chrono::high_resolution_clock::now();

    //    // Insert data into tree
    //    for (int i = 0; i < 10*a; i=i+1)
    //    {
    //        splay_tree->insert(i, i + 1);
    //    }

    //    // Record end time
    //    auto endTime = std::chrono::high_resolution_clock::now();
    //    int dataSize = a * 10;
    //    // Calculate duration in microseconds
    //    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    //    cout << "size is: " << dataSize << endl;
    //    // Write tree size and duration to CSV file
    //    delete splay_tree;
    //    outputFile << dataSize << ";" << duration.count() << std::endl;
    //}
    //outputFile.close();
    
    sgSet<int, int>* sg_tree = new sgSet<int, int>();
    avlSet<int, int>* avl_tree = new avlSet<int, int>();
    splaySet<int, int>* splay_tree = new splaySet<int, int>();
    InsertTester<sgSet<int, int>>* testerSG = new InsertTester<sgSet<int, int>>(sg_tree, 50, 10, 500, "pokusSG2.csv");
    testerSG->analyze();
    delete testerSG;
    InsertTester<avlSet<int, int>>* testerAVL = new InsertTester<avlSet<int, int>>(avl_tree, 50, 10, 500, "pokusAV2L.csv");
    testerAVL->analyze();
    delete testerAVL;
    InsertTester<splaySet<int, int>>* testerSPLAY = new InsertTester<splaySet<int, int>>(splay_tree, 50, 10, 500, "pokusSPLAY2.csv");
    testerSPLAY->analyze();
    delete testerSPLAY;
    return 0;
}