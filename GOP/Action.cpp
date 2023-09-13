#include "Action.hpp"

Action::Action(string n, int c) {
	this->name = n;
	this->cost = c;
}

unordered_map<string, bool> Action::getpreco() const {
	return this->precondition;
}

unordered_map<string, bool> Action::geteffect() const {
	return this->effect;
}

void Action::setpreco(const string k, const bool v) {
	this->precondition[k] = v;
}

void Action::seteffect(const string k, const bool v) {
	this->effect[k] = v;
}

string Action::getname() const {
	return this->name;
}

int Action::getcost() const {
	return this->cost;
}