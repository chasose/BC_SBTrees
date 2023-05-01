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
#include "Map.h"

using namespace std;

void methodAVL() {
    std::cout << "Method AVL is executed\n";

    //LINEAR
    //avlSET
    avlSet<string, int>* avl_treeS = new avlSet<string, int>();
    avlSet<int, int>* avl_treeI = new avlSet<int, int>();
    InsertTesterLinearString<avlSet<string, int>>* testerAVLS = new InsertTesterLinearString<avlSet<string, int>>(avl_treeS, 50, 100, 750, "Linear/avl_tree/I-L-AVL-String.csv");
    InsertTesterLinearINT<avlSet<int, int>>* testerAVLI = new InsertTesterLinearINT<avlSet<int, int>>(avl_treeI, 50, 100, 750, "Linear/avl_tree/I-L-AVL-Int.csv");
    testerAVLI->analyze();
    testerAVLS->analyze();

    FindTesterLinearString<avlSet<string, int>>* testerAVLSFIND = new FindTesterLinearString<avlSet<string, int>>(avl_treeS, 50, 100, 750, "Linear/avl_tree/F-L-AVL-String1.csv");
    FindTesterLinearINT<avlSet<int, int>>* testerAVLIFIND = new FindTesterLinearINT<avlSet<int, int>>(avl_treeI, 50, 100, 750, "Linear/avl_tree/F-L-AVL-Int.csv");
    testerAVLIFIND->analyze();
    testerAVLSFIND->analyze();

    RemoveTesterLinearString<avlSet<string, int>>* testerAVLSREMOVE = new RemoveTesterLinearString<avlSet<string, int>>(avl_treeS, 50, 100, 750, "Linear/avl_tree/R-L-AVL-String.csv");
    RemoveTesterLinearINT<avlSet<int, int>>* testerAVLIREMOVE = new RemoveTesterLinearINT<avlSet<int, int>>(avl_treeI, 50, 100, 750, "Linear/avl_tree/R-L-AVL-Int.csv");
    testerAVLIREMOVE->analyze();
    testerAVLSREMOVE->analyze();
    
    delete testerAVLSREMOVE;
    delete testerAVLIREMOVE;
    delete testerAVLSFIND;
    delete testerAVLIFIND;
    delete avl_treeS;
    delete avl_treeI;
    delete testerAVLI;
    delete testerAVLS;
    // 
    //RNG
    avlSet<string, int>* avl_treeSr = new avlSet<string, int>();
    avlSet<int, int>* avl_treeIr = new avlSet<int, int>();
    
    InsertTesterRNG_STRING<avlSet<string, int>>* testerAVLSr = new InsertTesterRNG_STRING<avlSet<string, int>>(avl_treeSr, 50, 100, 750, "RNG/avl_tree/I-L-AVL-String.csv");
    InsertTesterRNG_INT<avlSet<int, int>>* testerAVLIr = new InsertTesterRNG_INT<avlSet<int, int>>(avl_treeIr, 50, 100, 750, "RNG/avl_tree/I-L-AVL-Int.csv");
    testerAVLIr->analyze();
    testerAVLSr->analyze();

    FindTesterRNG_String<avlSet<string, int>>* testerAVLSFINDr = new FindTesterRNG_String<avlSet<string, int>>(avl_treeSr, 50, 100, 750, "RNG/avl_tree/F-L-AVL-String1.csv");
    FindTesterRNG_INT<avlSet<int, int>>* testerAVLIFINDr = new FindTesterRNG_INT<avlSet<int, int>>(avl_treeIr, 50, 100, 750, "RNG/avl_tree/F-L-AVL-Int.csv");
    testerAVLIFINDr->analyze();
    testerAVLSFINDr->analyze();

    RemoveTesterRNG_String<avlSet<string, int>>* testerAVLSREMOVEr = new RemoveTesterRNG_String<avlSet<string, int>>(avl_treeSr, 50, 100, 750, "RNG/avl_tree/R-L-AVL-String.csv");
    RemoveTesterRNG_INT<avlSet<int, int>>* testerAVLIREMOVEr = new RemoveTesterRNG_INT<avlSet<int, int>>(avl_treeIr, 50, 100, 750, "RNG/avl_tree/R-L-AVL-Int.csv");
    testerAVLIREMOVEr->analyze();
    testerAVLSREMOVEr->analyze();

    delete testerAVLSREMOVEr;
    delete testerAVLIREMOVEr;
    delete testerAVLSFINDr;
    delete testerAVLIFINDr;
    delete avl_treeSr;
    delete avl_treeIr;
    delete testerAVLIr;
    delete testerAVLSr;
}

void methodSPLAY() {
    std::cout << "Method SPLAY is executed\n";

    //splaySet
   //LINEAR

   splaySet<string, int>* splay_treeS = new splaySet<string, int>();
   splaySet<int, int>* splay_treeI = new splaySet<int, int>();
   InsertTesterLinearString< splaySet<string, int>>* testerSPLAYS = new InsertTesterLinearString<splaySet<string, int>>(splay_treeS, 50, 100, 750, "Linear/splay_tree/I-L-SPLAY-String.csv");
   InsertTesterLinearINT< splaySet<int, int>>* testerSPLAYI = new InsertTesterLinearINT< splaySet<int, int>>(splay_treeI, 50, 100, 750, "Linear/splay_tree/I-L-SPLAY-Int.csv");
   testerSPLAYI->analyze();
   testerSPLAYS->analyze();

   FindTesterLinearString<splaySet<string, int>>* testerSPLAYSFIND = new FindTesterLinearString<splaySet<string, int>>(splay_treeS, 50, 100, 750, "Linear/splay_tree/F-L-SPLAY-String1.csv");
   FindTesterLinearINT< splaySet<int, int>>* testerSPLAYIFIND = new FindTesterLinearINT< splaySet<int, int>>(splay_treeI, 50, 100, 750, "Linear/splay_tree/F-L-SPLAY-Int.csv");
   testerSPLAYIFIND->analyze();
   testerSPLAYSFIND->analyze();

   RemoveTesterLinearString<splaySet<string, int>>* testerSPLAYSREMOVE = new RemoveTesterLinearString<splaySet<string, int>>(splay_treeS, 25, 500, 800, "Linear/splay_tree/R-L-SPLAY5-String.csv");
   RemoveTesterLinearINT<splaySet<int, int>>* testerSPLAYIREMOVE = new RemoveTesterLinearINT<splaySet<int, int>>(splay_treeI, 25, 500, 800, "Linear/splay_tree/R-L-SPLAY-Int5.csv");
   testerSPLAYIREMOVE->analyze();
   testerSPLAYSREMOVE->analyze();

   delete testerSPLAYSFIND;
   delete testerSPLAYIFIND;
   delete testerSPLAYSREMOVE;
   delete testerSPLAYIREMOVE;
   delete splay_treeS;
   delete splay_treeI;
   delete testerSPLAYI;
   delete testerSPLAYS;
   // 
   //RNG
   splaySet<string, int>* splay_treeSs = new splaySet<string, int>();
   splaySet<int, int>* splay_treeIs = new splaySet<int, int>();
   InsertTesterRNG_STRING< splaySet<string, int>>* testerSPLAYSs = new InsertTesterRNG_STRING<splaySet<string, int>>(splay_treeSs, 50, 100, 750, "RNG/splay_tree/I-L-SPLAY-String.csv");
   InsertTesterRNG_INT< splaySet<int, int>>* testerSPLAYIs = new InsertTesterRNG_INT< splaySet<int, int>>(splay_treeIs, 50, 100, 750, "RNG/splay_tree/I-L-SPLAY-Int.csv");
   testerSPLAYIs->analyze();
   testerSPLAYSs->analyze();

   FindTesterRNG_String<splaySet<string, int>>* testerSPLAYSFINDs = new FindTesterRNG_String<splaySet<string, int>>(splay_treeSs, 50, 100, 750, "RNG/splay_tree/F-L-SPLAY-String.csv");
   FindTesterRNG_INT< splaySet<int, int>>* testerSPLAYIFINDs = new FindTesterRNG_INT< splaySet<int, int>>(splay_treeIs, 50, 100, 750, "RNG/splay_tree/F-L-SPLAY-Int.csv");
   testerSPLAYIFINDs->analyze();
   testerSPLAYSFINDs->analyze();

   RemoveTesterRNG_String<splaySet<string, int>>* testerSPLAYSREMOVEs = new RemoveTesterRNG_String<splaySet<string, int>>(splay_treeSs, 25, 500, 800, "RNG/splay_tree/R-L-SPLAY-String5.csv");
   RemoveTesterRNG_INT<splaySet<int, int>>* testerSPLAYIREMOVEs = new RemoveTesterRNG_INT<splaySet<int, int>>(splay_treeIs, 25, 500, 800, "RNG/splay_tree/R-L-SPLAY-Int5.csv");
   testerSPLAYIREMOVEs->analyze();
   testerSPLAYSREMOVEs->analyze();

   delete testerSPLAYSFINDs;
   delete testerSPLAYIFINDs;
   delete testerSPLAYSREMOVEs;
   delete testerSPLAYIREMOVEs;
   delete splay_treeSs;
   delete splay_treeIs;
   delete testerSPLAYIs;
   delete testerSPLAYSs;
}

void methodScapegoat() {
    std::cout << "Method Scapegoat is executed\n";

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
}

void methodMAP() {
    std::cout << "Method MAP is executed\n";

    //MAP
    //LINEAR
    Map<string, int>* map_s = new Map<string, int>();
    Map<int, int>* map_i = new Map<int, int>();

    InsertTesterLinearString<Map<string, int>>* testerMAPS = new InsertTesterLinearString<Map<string, int>>(map_s, 50, 100,750, "Linear/MAP/I-L-MAP-String.csv");
    InsertTesterLinearINT<Map<int, int>>* testerMAPI = new InsertTesterLinearINT<Map<int, int>>(map_i, 50, 100, 750, "Linear/MAP/I-L-MAP-Int.csv");
    testerMAPI->analyze();
    testerMAPS->analyze();

    FindTesterLinearString<Map<string, int>>* testerMAPSFIND = new FindTesterLinearString<Map<string, int>>(map_s, 50, 100, 750, "Linear/MAP/F-L-MAP-String.csv");
    FindTesterLinearINT<Map<int, int>>* testerMAPIFIND = new FindTesterLinearINT<Map<int, int>>(map_i, 50, 100, 750, "Linear/MAP/F-L-MAP-Int.csv");
    testerMAPIFIND->analyze();
    testerMAPSFIND->analyze();

    RemoveTesterLinearString<Map<string, int>>* testerMAPSREMOVE = new RemoveTesterLinearString<Map<string, int>>(map_s, 50, 100, 750, "Linear/MAP/R-L-MAP-String.csv");
    RemoveTesterLinearINT<Map<int, int>>* testerMAPIREMOVE = new RemoveTesterLinearINT<Map<int, int>>(map_i, 50, 100, 750, "Linear/MAP/R-L-MAP-Int.csv");
    testerMAPIREMOVE->analyze();
    testerMAPSREMOVE->analyze();
    
    delete testerMAPS;
    delete testerMAPI;
    delete testerMAPSFIND;
    delete testerMAPIFIND;
    delete map_s;
    delete map_i;
    delete testerMAPSREMOVE;
    delete testerMAPIREMOVE;

    ////RNG
    Map<string, int>* map_sR = new Map<string, int>();
    Map<int, int>* map_iR = new Map<int, int>();
    InsertTesterRNG_STRING<Map<string, int>>* testerMAPSr = new InsertTesterRNG_STRING<Map<string, int>>(map_sR, 50, 100, 750, "RNG/MAP/I-R-MAP-String.csv");
    InsertTesterRNG_INT<Map<int, int>>* testerMAPIr = new InsertTesterRNG_INT<Map<int, int>>(map_iR, 50, 100, 750, "RNG/MAP/I-R-MAP-Int.csv");
    testerMAPIr->analyze();
    testerMAPSr->analyze();

    FindTesterRNG_String<Map<string, int>>* testerMAPSFINDr = new FindTesterRNG_String<Map<string, int>>(map_sR, 50, 100, 750, "RNG/MAP/F-R-MAP-String1.csv");
    FindTesterRNG_INT<Map<int, int>>* testerMAPIFINDr = new FindTesterRNG_INT<Map<int, int>>(map_iR, 50, 100, 750, "RNG/MAP/F-R-MAP-Int.csv");
    testerMAPIFINDr->analyze();
    testerMAPSFINDr->analyze();

    RemoveTesterRNG_String<Map<string, int>>* testerMAPSREMOVEr = new RemoveTesterRNG_String<Map<string, int>>(map_sR, 50, 100, 750, "RNG/MAP/R-R-MAP-String.csv");
    RemoveTesterRNG_INT<Map<int, int>>* testerMAPIREMOVEr = new RemoveTesterRNG_INT<Map<int, int>>(map_iR, 50, 100, 750, "RNG/MAP/R-R-MAP-Int.csv");
    testerMAPIREMOVEr->analyze();
    testerMAPSREMOVEr->analyze();

    delete testerMAPSFINDr;
    delete testerMAPIFINDr;
    delete testerMAPSREMOVEr;
    delete testerMAPIREMOVEr;
    delete map_sR;
    delete map_iR;
    delete testerMAPIr;
    delete testerMAPSr;
}



int main() {
    initHeapMonitor();

    int userInput;

    do {
        std::cout << "Enter a number from 1 to 4 (or 99 to exit): \n";
        std::cout << "1: testing AVL tree \n";
        std::cout << "2: testing SPLAY tree \n";
        std::cout << "3: testing Scapegoat tree \n";
        std::cout << "4: testing MAP \n";

        if (!(std::cin >> userInput)) {
            // Clear input stream
            std::cin.clear();
            // Ignore any extra characters in the input buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input\n";
            continue;
        }

        switch (userInput) {
        case 1:
            methodAVL();
            break;
        case 2:
            methodSPLAY();
            break;
        case 3:
            methodScapegoat();
            break;
        case 4:
            methodMAP();
            break;
        case 99:
            std::cout << "Exiting program\n";
            return 0;
        default:
            std::cout << "Invalid input\n";
            break;
        }
    } while (true);

    return 0;

}