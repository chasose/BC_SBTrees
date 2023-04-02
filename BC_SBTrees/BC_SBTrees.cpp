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
    InsertTesterLinearString<sgSet<string, int>>* testerSGS = new InsertTesterLinearString<sgSet<string, int>>(sg_treeS, 50, 100,750, "Linear/sg_tree/I-L-SG-String.csv");
    InsertTesterLinearINT<sgSet<int, int>>* testerSGI = new InsertTesterLinearINT<sgSet<int, int>>(sg_treeI, 50, 100, 750, "Linear/sg_tree/I-L-SG-Int.csv");
    testerSGI->analyze();
    testerSGS->analyze();

    FindTesterLinearString<sgSet<string, int>>* testerSGSFIND = new FindTesterLinearString<sgSet<string, int>>(sg_treeS, 50, 100, 750, "Linear/sg_tree/F-L-SG-String.csv");
    FindTesterLinearINT<sgSet<int, int>>* testerSGIFIND = new FindTesterLinearINT<sgSet<int, int>>(sg_treeI, 50, 100, 750, "Linear/sg_tree/F-L-SG-Int.csv");
    testerSGSFIND->analyze();
    testerSGIFIND->analyze();

    RemoveTesterLinearString<sgSet<string, int>>* testerSGSREMOVE = new RemoveTesterLinearString<sgSet<string, int>>(sg_treeS, 50, 100, 750, "Linear/sg_tree/R-L-SG-String.csv");
    RemoveTesterLinearINT<sgSet<int, int>>* testerSGIREMOVE = new RemoveTesterLinearINT<sgSet<int, int>>(sg_treeI, 50, 100, 750, "Linear/sg_tree/R-L-SG-Int.csv");
    testerSGSREMOVE->analyze();
    testerSGIREMOVE->analyze();
    
    delete testerSGSREMOVE;
    delete testerSGIREMOVE;
    delete testerSGSFIND;
    delete testerSGIFIND;
    delete sg_treeS;
    delete sg_treeI;
    delete testerSGI;
    delete testerSGS;
     
    //RNG
    sgSet<string, int>* sg_treeSt = new sgSet<string, int>();
    sgSet<int, int>* sg_treeIt = new sgSet<int, int>();
    InsertTesterRNG_STRING<sgSet<string, int>>* testerSGSt = new InsertTesterRNG_STRING<sgSet<string, int>>(sg_treeSt, 50, 100, 750, "RNG/sg_tree/I-R-SG-String.csv");
    InsertTesterRNG_INT<sgSet<int, int>>* testerSGIt = new InsertTesterRNG_INT<sgSet<int, int>>(sg_treeIt, 50, 100, 750, "RNG/sg_tree/I-R-SG-Int.csv");
    testerSGIt->analyze();
    testerSGSt->analyze();

    FindTesterRNG_String<sgSet<string, int>>* testerSGSFINDt = new FindTesterRNG_String<sgSet<string, int>>(sg_treeSt, 50, 100, 750, "RNG/sg_tree/F-R-SG-String.csv");
    FindTesterRNG_INT<sgSet<int, int>>* testerSGIFINDt = new FindTesterRNG_INT<sgSet<int, int>>(sg_treeIt, 50, 100,750, "RNG/sg_tree/F-R-SG-Int.csv");
    testerSGSFINDt->analyze();
    testerSGIFINDt->analyze();

    RemoveTesterRNG_String<sgSet<string, int>>* testerSGSREMOVEt = new RemoveTesterRNG_String<sgSet<string, int>>(sg_treeSt, 50, 100, 750, "RNG/sg_tree/R-R-SG-String.csv");
    RemoveTesterRNG_INT<sgSet<int, int>>* testerSGIREMOVEt = new RemoveTesterRNG_INT<sgSet<int, int>>(sg_treeIt, 50, 100, 750, "RNG/sg_tree/R-R-SG-Int.csv");
    testerSGSREMOVEt->analyze();
    testerSGIREMOVEt->analyze();
    
    delete testerSGSREMOVEt;
    delete testerSGIREMOVEt;
    delete testerSGSFINDt;
    delete testerSGIFINDt;
    delete sg_treeSt;
    delete sg_treeIt;
    delete testerSGIt;
    delete testerSGSt;
    
    



    
    //LINEAR
    ////avlSET
    //avlSet<string, int>* avl_treeS = new avlSet<string, int>();
    //avlSet<int, int>* avl_treeI = new avlSet<int, int>();
    //InsertTesterLinearString<avlSet<string, int>>* testerAVLS = new InsertTesterLinearString<avlSet<string, int>>(avl_treeS, 50, 100, 750, "Linear/avl_tree/I-L-AVL-String.csv");
    //InsertTesterLinearINT<avlSet<int, int>>* testerAVLI = new InsertTesterLinearINT<avlSet<int, int>>(avl_treeI, 50, 100, 750, "Linear/avl_tree/I-L-AVL-Int.csv");
    //testerAVLI->analyze();
    ///*testerAVLS->analyze();*/

    //FindTesterLinearString<avlSet<string, int>>* testerAVLSFIND = new FindTesterLinearString<avlSet<string, int>>(avl_treeS, 50, 100, 750, "Linear/avl_tree/F-L-AVL-String1.csv");
    //FindTesterLinearINT<avlSet<int, int>>* testerAVLIFIND = new FindTesterLinearINT<avlSet<int, int>>(avl_treeI, 50, 100, 750, "Linear/avl_tree/F-L-AVL-Int.csv");
    ///*testerAVLIFIND->analyze();
    //testerAVLSFIND->analyze();*/

    //RemoveTesterLinearString<avlSet<string, int>>* testerAVLSREMOVE = new RemoveTesterLinearString<avlSet<string, int>>(avl_treeS, 50, 100, 750, "Linear/avl_tree/R-L-AVL-String.csv");
    //RemoveTesterLinearINT<avlSet<int, int>>* testerAVLIREMOVE = new RemoveTesterLinearINT<avlSet<int, int>>(avl_treeI, 50, 100, 750, "Linear/avl_tree/R-L-AVL-Int.csv");
    //testerAVLIREMOVE->analyze();
    //testerAVLSREMOVE->analyze();
    //
    //delete testerAVLSREMOVE;
    //delete testerAVLIREMOVE;
    //delete testerAVLSFIND;
    //delete testerAVLIFIND;
    //delete avl_treeS;
    //delete avl_treeI;
    //delete testerAVLI;
    //delete testerAVLS;
    //// 
    ////RNG
    //avlSet<string, int>* avl_treeSr = new avlSet<string, int>();
    //avlSet<int, int>* avl_treeIr = new avlSet<int, int>();
    //
    //InsertTesterRNG_STRING<avlSet<string, int>>* testerAVLSr = new InsertTesterRNG_STRING<avlSet<string, int>>(avl_treeSr, 50, 100, 750, "RNG/avl_tree/I-L-AVL-String.csv");
    //InsertTesterRNG_INT<avlSet<int, int>>* testerAVLIr = new InsertTesterRNG_INT<avlSet<int, int>>(avl_treeIr, 50, 100, 750, "RNG/avl_tree/I-L-AVL-Int.csv");
    //testerAVLIr->analyze();
    //testerAVLSr->analyze();

    //FindTesterRNG_String<avlSet<string, int>>* testerAVLSFINDr = new FindTesterRNG_String<avlSet<string, int>>(avl_treeSr, 50, 100, 750, "RNG/avl_tree/F-L-AVL-String1.csv");
    //FindTesterRNG_INT<avlSet<int, int>>* testerAVLIFINDr = new FindTesterRNG_INT<avlSet<int, int>>(avl_treeIr, 50, 100, 750, "RNG/avl_tree/F-L-AVL-Int.csv");
    //testerAVLIFINDr->analyze();
    //testerAVLSFINDr->analyze();

    //RemoveTesterRNG_String<avlSet<string, int>>* testerAVLSREMOVEr = new RemoveTesterRNG_String<avlSet<string, int>>(avl_treeSr, 50, 100, 750, "RNG/avl_tree/R-L-AVL-String.csv");
    //RemoveTesterRNG_INT<avlSet<int, int>>* testerAVLIREMOVEr = new RemoveTesterRNG_INT<avlSet<int, int>>(avl_treeIr, 50, 100, 750, "RNG/avl_tree/R-L-AVL-Int.csv");
    //testerAVLIREMOVEr->analyze();
    //testerAVLSREMOVEr->analyze();

    //delete testerAVLSREMOVEr;
    //delete testerAVLIREMOVEr;
    //delete testerAVLSFINDr;
    //delete testerAVLIFINDr;
    //delete avl_treeSr;
    //delete avl_treeIr;
    //delete testerAVLIr;
    //delete testerAVLSr;






    //splaySet
    //LINEAR
    ////avlSET
    //splaySet<string, int>* splay_treeS = new splaySet<string, int>();
    //splaySet<int, int>* splay_treeI = new splaySet<int, int>();
    //InsertTesterLinearString< splaySet<string, int>>* testerSPLAYS = new InsertTesterLinearString<splaySet<string, int>>(splay_treeS, 50, 100, 750, "Linear/splay_tree/I-L-SPLAY-String.csv");
    //InsertTesterLinearINT< splaySet<int, int>>* testerSPLAYI = new InsertTesterLinearINT< splaySet<int, int>>(splay_treeI, 50, 100, 750, "Linear/splay_tree/I-L-SPLAY-Int.csv");
    //testerSPLAYI->analyze();
    //testerSPLAYS->analyze();

    //FindTesterLinearString<splaySet<string, int>>* testerSPLAYSFIND = new FindTesterLinearString<splaySet<string, int>>(splay_treeS, 50, 100, 750, "Linear/splay_tree/F-L-SPLAY-String1.csv");
    //FindTesterLinearINT< splaySet<int, int>>* testerSPLAYIFIND = new FindTesterLinearINT< splaySet<int, int>>(splay_treeI, 50, 100, 750, "Linear/splay_tree/F-L-SPLAY-Int.csv");
    //testerSPLAYIFIND->analyze();
    //testerSPLAYSFIND->analyze();

    //RemoveTesterLinearString<splaySet<string, int>>* testerSPLAYSREMOVE = new RemoveTesterLinearString<splaySet<string, int>>(splay_treeS, 50, 100, 750, "Linear/splay_tree/R-L-SPLAY-String.csv");
    //RemoveTesterLinearINT<splaySet<int, int>>* testerSPLAYIREMOVE = new RemoveTesterLinearINT<splaySet<int, int>>(splay_treeI, 50, 100, 750, "Linear/splay_tree/R-L-SPLAY-Int.csv");
    //testerSPLAYIREMOVE->analyze();
    //testerSPLAYSREMOVE->analyze();

    //delete testerSPLAYSFIND;
    //delete testerSPLAYIFIND;
    //delete testerSPLAYSREMOVE;
    //delete testerSPLAYIREMOVE;
    //delete splay_treeS;
    //delete splay_treeI;
    //delete testerSPLAYI;
    //delete testerSPLAYS;
    //// 
    ////RNG
    //splaySet<string, int>* splay_treeSs = new splaySet<string, int>();
    //splaySet<int, int>* splay_treeIs = new splaySet<int, int>();
    //InsertTesterRNG_STRING< splaySet<string, int>>* testerSPLAYSs = new InsertTesterRNG_STRING<splaySet<string, int>>(splay_treeSs, 50, 100, 750, "RNG/splay_tree/I-L-AVL-String.csv");
    //InsertTesterRNG_INT< splaySet<int, int>>* testerSPLAYIs = new InsertTesterRNG_INT< splaySet<int, int>>(splay_treeIs, 50, 100, 750, "RNG/splay_tree/I-L-AVL-Int.csv");
    //testerSPLAYIs->analyze();
    //testerSPLAYSs->analyze();

    //FindTesterRNG_String<splaySet<string, int>>* testerSPLAYSFINDs = new FindTesterRNG_String<splaySet<string, int>>(splay_treeSs, 50, 100, 750, "RNG/splay_tree/F-L-AVL-String1.csv");
    //FindTesterRNG_INT< splaySet<int, int>>* testerSPLAYIFINDs = new FindTesterRNG_INT< splaySet<int, int>>(splay_treeIs, 50, 100, 750, "RNG/splay_tree/F-L-AVL-Int.csv");
    //testerSPLAYIFINDs->analyze();
    //testerSPLAYSFINDs->analyze();

    //RemoveTesterRNG_String<splaySet<string, int>>* testerSPLAYSREMOVEs = new RemoveTesterRNG_String<splaySet<string, int>>(splay_treeSs, 50, 100, 750, "RNG/splay_tree/R-L-AVL-String.csv");
    //RemoveTesterRNG_INT<splaySet<int, int>>* testerSPLAYIREMOVEs = new RemoveTesterRNG_INT<splaySet<int, int>>(splay_treeIs, 50, 100, 750, "RNG/splay_tree/R-L-AVL-Int.csv");
    //testerSPLAYIREMOVEs->analyze();
    //testerSPLAYSREMOVEs->analyze();

    //delete testerSPLAYSFINDs;
    //delete testerSPLAYIFINDs;
    //delete testerSPLAYSREMOVEs;
    //delete testerSPLAYIREMOVEs;
    //delete splay_treeSs;
    //delete splay_treeIs;
    //delete testerSPLAYIs;
    //delete testerSPLAYSs;


    return 0;
}