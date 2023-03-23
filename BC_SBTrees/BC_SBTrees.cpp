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
#include "FindTesterLinearINT.h"
#include "FindTesterLinearString.h"
#include "RemoveTesterLinearINT.h"
#include "RemoveTesterLinearString.h"
#include "FindTesterRNG_INT.h"
#include "FindTesterRNG_String.h"
#include "RemoveTesterRNG_INT.h"
#include "RemoveTesterRNG_String.h"

using namespace std;

int main() {
    initHeapMonitor();
    //LINEAR
    //sgSET
    sgSet<string, int>* sg_treeS = new sgSet<string, int>();
    sgSet<int, int>* sg_treeI = new sgSet<int, int>();
    InsertTesterLinearString<sgSet<string, int>>* testerSGS = new InsertTesterLinearString<sgSet<string, int>>(sg_treeS, 50, 100, 1000, "I-L-SG-String.csv");
    InsertTesterLinearINT<sgSet<int, int>>* testerSGI = new InsertTesterLinearINT<sgSet<int, int>>(sg_treeI, 50, 100, 1000, "I-L-SG-Int.csv");
    /*testerSGI->analyze();
    testerSGS->analyze();*/

    FindTesterLinearString<sgSet<string, int>>* testerSGSFIND = new FindTesterLinearString<sgSet<string, int>>(sg_treeS, 50, 100, 1000, "F-L-SG-String1.csv");
    FindTesterLinearINT<sgSet<int, int>>* testerSGIFIND = new FindTesterLinearINT<sgSet<int, int>>(sg_treeI, 50, 100,1000, "F-L-SG-Int.csv");
    /*testerSGSFIND->analyze();*/
    testerSGIFIND->analyze();

    RemoveTesterLinearString<sgSet<string, int>>* testerSGSREMOVE = new RemoveTesterLinearString<sgSet<string, int>>(sg_treeS, 50, 100, 1000, "R-L-SG-String.csv");
    RemoveTesterLinearINT<sgSet<int, int>>* testerSGIREMOVE = new RemoveTesterLinearINT<sgSet<int, int>>(sg_treeI, 50, 100, 1000, "R-L-SG-Int.csv");
    /*testerSGSREMOVE->analyze();
    testerSGIREMOVE->analyze();*/
    
    delete testerSGSREMOVE;
    delete testerSGIREMOVE;
    delete testerSGSFIND;
    delete testerSGIFIND;
    delete sg_treeS;
    delete sg_treeI;
    delete testerSGI;
    delete testerSGS;
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
    /*sgSet<string, int>* sg_treeS = new sgSet<string, int>();
    sgSet<int, int>* sg_treeI = new sgSet<int, int>();
    InsertTesterRNG_STRING<sgSet<string, int>>* testerSGS = new InsertTesterRNG_STRING<sgSet<string, int>>(sg_treeS, 50, 100, 100, "rngSGStringRelease.csv");
    InsertTesterRNG_INT<sgSet<int, int>>* testerSGI = new InsertTesterRNG_INT<sgSet<int, int>>(sg_treeI, 50, 100, 100, "rngSGINTRelease.csv");
    testerSGI->analyze();
    testerSGS->analyze();

    delete sg_treeS;
    delete sg_treeI;
    delete testerSGI;
    delete testerSGS;*/

    //avlSET
    //avlSet<string, int>* avl_treeS = new avlSet<string, int>();
    //avlSet<int, int>* avl_treeI = new avlSet<int, int>();
    //InsertTesterRNG_STRING<avlSet<string, int>>* testerAVLS = new InsertTesterRNG_STRING<avlSet<string, int>>(avl_treeS, 50, 10, 250, "rngAVLString.csv");
    //InsertTesterRNG_INT<avlSet<int, int>>* testerAVLI = new InsertTesterRNG_INT<avlSet<int, int>>(avl_treeI, 50, 10, 250, "rngAVLINT.csv");
    //testerAVLI->analyze();
    //testerAVLS->analyze();

    //delete avl_treeS;
    //delete avl_treeI;
    //delete testerAVLI;
    //delete testerAVLS;
    ////splaySET
    //splaySet<string, int>* splay_treeS = new splaySet<string, int>();
    //splaySet<int, int>* splay_treeI = new splaySet<int, int>();
    //InsertTesterRNG_STRING<splaySet<string, int>>* testerSPLAYS = new InsertTesterRNG_STRING<splaySet<string, int>>(splay_treeS, 50, 10, 250, "rngSPLAYString.csv");
    //InsertTesterRNG_INT<splaySet<int, int>>* testerSPLAYI = new InsertTesterRNG_INT<splaySet<int, int>>(splay_treeI, 50, 10, 250, "rngSPLAYINT.csv");
    //testerSPLAYI->analyze();
    //testerSPLAYS->analyze();


    //delete splay_treeS;
    //delete splay_treeI;
    //delete testerSPLAYS;
    //delete testerSPLAYI;

    
    /*FindTesterLinearString<sgSet<string, int>>* testerSGSFIND = new FindTesterLinearString<sgSet<string, int>>(sg_treeS, 50, 100, 100, "FINDlinearSG_StringRelease.csv");
    FindTesterLinearINT<sgSet<int, int>>* testerSGIFIND = new FindTesterLinearINT<sgSet<int, int>>(sg_treeI, 50, 100, 100, "FINDlinearSG_INTRelease.csv");
    testerSGSFIND->analyze();
    testerSGIFIND->analyze();

    delete sg_treeS;
    delete sg_treeI;
    delete testerSGSFIND;
    delete testerSGIFIND;*/


    //////////////////////////////////////////////////////////////////////////
    //sgSet<string, int>* sg_treeS = new sgSet<string, int>(0.9);
    //sgSet<int, int>* sg_treeI = new sgSet<int, int>();
    //InsertTesterLinearString<sgSet<string, int>>* testerSGS = new InsertTesterLinearString<sgSet<string, int>>(sg_treeS, 1, 100, 1000, "INSERT_stringONEREPLICATION.csv");
    //InsertTesterLinearINT<sgSet<int, int>>* testerSGI = new InsertTesterLinearINT<sgSet<int, int>>(sg_treeI, 50, 100, 100, "INSERT_int.csv");
    ///*testerSGI->analyze();*/
    //testerSGS->analyze();

    //FindTesterLinearString<sgSet<string, int>>* testerSGSFIND = new FindTesterLinearString<sgSet<string, int>>(sg_treeS, 50, 100, 100, "FIND_string.csv");
    //FindTesterLinearINT<sgSet<int, int>>* testerSGIFIND = new FindTesterLinearINT<sgSet<int, int>>(sg_treeI, 50, 100, 100, "FIND_int.csv");
    ///*testerSGSFIND->analyze();
    //testerSGIFIND->analyze();*/

    //RemoveTesterLinearString<sgSet<string, int>>* testerSGSREMOVE = new RemoveTesterLinearString<sgSet<string, int>>(sg_treeS, 50, 100, 100, "REMOVE_string.csv");
    //RemoveTesterLinearINT<sgSet<int, int>>* testerSGIREMOVE = new RemoveTesterLinearINT<sgSet<int, int>>(sg_treeI, 50, 100, 100, "REMOVE_int.csv");
    ///*testerSGSREMOVE->analyze();
    //testerSGIREMOVE->analyze();*/


    //delete testerSGSFIND;
    //delete testerSGIFIND;
    //delete testerSGSREMOVE;
    //delete testerSGIREMOVE;
    //delete sg_treeS;
    //delete sg_treeI;
    //delete testerSGI;
    //delete testerSGS;

    return 0;
}