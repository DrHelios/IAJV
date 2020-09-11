// GOAP.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

//Goap solver doit être absrait ne doit pas modifier les valeur 

int main()
{
    std::cout << "Hello World!\n";
    Precondition* verifyQtOfWood = new WoodToBuild(P_ENOUGHWOOD);
    Effect* Buildhouse = new BuildHouse(P_ENOUGHWOOD);
    Effect* GatherWood = new ChopWoods(P_ENOUGHTREES);
    Precondition* GetNbOFtrees = new GetTreesInForest(P_ENOUGHTREES);
    Precondition* GetNbOfVillagois = new GetVillager(P_ENOUGHTREES)
}

