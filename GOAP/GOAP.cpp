// GOAP.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Solver.h"
#include "People.h"
#include "AllEffects.h"
#include "AllPrecondtions.h"

//Goap solver doit être absrait ne doit pas modifier les valeur 
GameState gs;

int main()
{
    People p = People();
    gs.villagers.push_back(p);
    Solver solver = Solver(100, p, gs);
    std::vector<Action*> finalListAction;

    Precondition* GetNbOFtrees = new GetTreesInForest(P_ENOUGHTREES);
    Precondition* GetNbOfVilagers = new WorkerToBuild(P_ENOUGHTREES);
    Effect* GatherWood = new ChopWood(P_ENOUGHTREES);
    Action* gather = new Action("Gather wood", 2);
    gather->AddPrecondition(GetNbOFtrees);
    gather->AddPrecondition(GetNbOfVilagers);
    gather->AddEffect(GatherWood);

    Precondition* CheckPocketFull = new PocketFull(P_POCKETSFULL);
    Effect* ReffilesStock = new Stock(P_POCKETSFULL);
    Action* stock = new Action("reffiled stock", 1);
    stock->AddPrecondition(CheckPocketFull);
    stock->AddEffect(ReffilesStock);


    Precondition* verifyQtOfWood = new  WoodToBuild(P_ENOUGHWOOD);
    Precondition* GetVilagers = new WorkerToBuild(P_ENOUGHWOOD);
    Effect* ReffinedWood = new ReffineWood(P_ENOUGHWOOD);
    Action* reffined = new Action("reffined wood", 5);
    reffined->AddPrecondition(verifyQtOfWood);
    reffined->AddPrecondition(GetVilagers);
    reffined->AddEffect(ReffinedWood);

    Precondition* verifyQtOfReffinedWood = new ReffinedWoodToBuild(P_BUILD);
    Precondition* GetNbVilagers = new WorkerToBuild(P_BUILD);
    Effect* Buildhouse = new BuildHouse(P_BUILD);
    Action* build = new Action("build house",10);
    build->AddPrecondition(verifyQtOfReffinedWood);
    build->AddPrecondition(GetNbVilagers);
    build->AddEffect(Buildhouse);

    solver.Add(gather);
    solver.Add(stock);
    solver.Add(reffined);
    solver.Add(build);

}

