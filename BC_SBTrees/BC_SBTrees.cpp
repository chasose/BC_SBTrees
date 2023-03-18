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
#include "InsertTesterLinearINT.h"
#include "InsertTesterLinearString.h"
#include "InsertTesterRNG_INT.h"
#include "InsertTesterRNG_STRING.h"

using namespace std;

int main() {
    initHeapMonitor();
    //LINEAR
    //sgSET
    //sgSet<string, int>* sg_treeS = new sgSet<string, int>();
    //sgSet<int, int>* sg_treeI = new sgSet<int, int>();
    //InsertTesterLinearString<sgSet<string, int>>* testerSGS = new InsertTesterLinearString<sgSet<string, int>>(sg_treeS, 50, 10, 250, "pokusSGString.csv");
    //InsertTesterLinearINT<sgSet<int, int>>* testerSGI = new InsertTesterLinearINT<sgSet<int, int>>(sg_treeI, 50, 10, 250, "pokusSGINT.csv");
    //testerSGI->analyze();
    //testerSGS->analyze();

    //delete sg_treeS;
    //delete sg_treeI;
    //delete testerSGI;
    //delete testerSGS;
    ////avlSET
    //avlSet<string, int>* avl_treeS = new avlSet<string, int>();
    //avlSet<int, int>* avl_treeI = new avlSet<int, int>();
    //InsertTesterLinearString<avlSet<string, int>>* testerAVLS = new InsertTesterLinearString<avlSet<string, int>>(avl_treeS, 50, 10, 250, "pokusAVLString.csv");
    //InsertTesterLinearINT<avlSet<int, int>>* testerAVLI = new InsertTesterLinearINT<avlSet<int, int>>(avl_treeI, 50, 10, 250, "pokusAVLINT.csv");
    //testerAVLI->analyze();
    //testerAVLS->analyze();

    //delete avl_treeS;
    //delete avl_treeI;
    //delete testerAVLI;
    //delete testerAVLS;
    ////splaySET
    //splaySet<string, int>* splay_treeS = new splaySet<string, int>();
    //splaySet<int, int>* splay_treeI = new splaySet<int, int>();
    //InsertTesterLinearString<splaySet<string, int>>* testerSPLAYS = new InsertTesterLinearString<splaySet<string, int>>(splay_treeS, 50, 10, 250, "pokusSPLAYString.csv");
    //InsertTesterLinearINT<splaySet<int, int>>* testerSPLAYI = new InsertTesterLinearINT<splaySet<int, int>>(splay_treeI, 50, 10, 250, "pokusSPLAYINT.csv");
    //testerSPLAYI->analyze();
    //testerSPLAYS->analyze();
    //

    //delete splay_treeS;
    //delete splay_treeI;
    //delete testerSPLAYS;
    //delete testerSPLAYI;


    //RANDOM
    //sgSET
    sgSet<string, int>* sg_treeS = new sgSet<string, int>();
    sgSet<int, int>* sg_treeI = new sgSet<int, int>();
    InsertTesterRNG_STRING<sgSet<string, int>>* testerSGS = new InsertTesterRNG_STRING<sgSet<string, int>>(sg_treeS, 50, 10, 250, "rngSGString.csv");
    InsertTesterRNG_INT<sgSet<int, int>>* testerSGI = new InsertTesterRNG_INT<sgSet<int, int>>(sg_treeI, 50, 10, 250, "rngSGINT.csv");
    testerSGI->analyze();
    testerSGS->analyze();

    delete sg_treeS;
    delete sg_treeI;
    delete testerSGI;
    delete testerSGS;
    //avlSET
    avlSet<string, int>* avl_treeS = new avlSet<string, int>();
    avlSet<int, int>* avl_treeI = new avlSet<int, int>();
    InsertTesterRNG_STRING<avlSet<string, int>>* testerAVLS = new InsertTesterRNG_STRING<avlSet<string, int>>(avl_treeS, 50, 10, 250, "rngAVLString.csv");
    InsertTesterRNG_INT<avlSet<int, int>>* testerAVLI = new InsertTesterRNG_INT<avlSet<int, int>>(avl_treeI, 50, 10, 250, "rngAVLINT.csv");
    testerAVLI->analyze();
    testerAVLS->analyze();

    delete avl_treeS;
    delete avl_treeI;
    delete testerAVLI;
    delete testerAVLS;
    //splaySET
    splaySet<string, int>* splay_treeS = new splaySet<string, int>();
    splaySet<int, int>* splay_treeI = new splaySet<int, int>();
    InsertTesterRNG_STRING<splaySet<string, int>>* testerSPLAYS = new InsertTesterRNG_STRING<splaySet<string, int>>(splay_treeS, 50, 10, 250, "rngSPLAYString.csv");
    InsertTesterRNG_INT<splaySet<int, int>>* testerSPLAYI = new InsertTesterRNG_INT<splaySet<int, int>>(splay_treeI, 50, 10, 250, "rngSPLAYINT.csv");
    testerSPLAYI->analyze();
    testerSPLAYS->analyze();


    delete splay_treeS;
    delete splay_treeI;
    delete testerSPLAYS;
    delete testerSPLAYI;


    return 0;
}