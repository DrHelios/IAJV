#include "StateMachine.h"
StateMachine::StateMachine() : begin(), current_states() {}
StateMachine::StateMachine(States* start) : begin(start), current_states(start) { }
StateMachine::~StateMachine() { delete begin; }
States* StateMachine::GetBeginState() const{ return begin; };
States* StateMachine::GetCurrentState() const{ return current_states; };
void StateMachine::SetCurrentState(int newCurrentState) { current_states->SetPossibleState(newCurrentState); }