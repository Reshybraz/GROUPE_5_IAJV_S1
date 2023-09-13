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
	WorldAction *ws_;
	Action *action_;
	WorldAction *parent_;

public:
	Transition(WorldAction& ws, Action& action, WorldAction& parent);

};

#endif