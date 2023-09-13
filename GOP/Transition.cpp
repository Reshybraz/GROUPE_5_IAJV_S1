#include "Transition.hpp"
#include "State.cpp"

Transition::Transition(WorldState& ws, Action& action, WorldState& parent) : ws_(ws), action_(action), parent_(parent) {
	
}