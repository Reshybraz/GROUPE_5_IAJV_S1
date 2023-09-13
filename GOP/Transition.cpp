#include "Transition.hpp"


Transition::Transition(WorldAction& ws, Action& action, WorldAction& parent) {
	ws_ = &ws;
	action_ = &action;
	parent_ = &parent;
}