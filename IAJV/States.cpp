#include "States.h"
#include "Transition.h"
States::States() : transistionList() {}
States::States(possibleStates state) : actualState(state), transistionList() {}
States::~States() {	transistionList.clear();}
std::vector<std::pair<Transition*, int>> States::GetTransitionList() const { return transistionList; }
int States::GetPossibleState() const { return actualState; }
void States::SetPossibleState(int newActualState) { actualState = newActualState; }
// Ajoute une transition à la liste des transition
void States::AddTransition(Transition* transitionToUpdateStates, int targetStates) { transistionList.push_back(std::make_pair(transitionToUpdateStates, targetStates)); }
