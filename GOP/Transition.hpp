#pragma once
#include <string>
#include <unordered_map>
#include "World.hpp"
class Action;

using namespace std;
#ifndef _TRANSITION_HPP_
#define _TRANSITION_HPP_

class Transition {
private:
	WorldState *ws_;
	Action *action_;
	WorldState *parent_;

public:
	Transition(WorldState& ws, Action& action, WorldState& parent);

};

#endif