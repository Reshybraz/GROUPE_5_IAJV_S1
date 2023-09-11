#include "State.hpp"

State::State(string n, int c) {
	this->name = n;
	this->cost = c;
}

unordered_map<string, bool> State::getpreco() const {
	return this->precondition;
}

unordered_map<string, bool> State::geteffect() const {
	return this->effect;
}

void State::setpreco(const string k, const bool v) {
	this->precondition[k] = v;
}

void State::seteffect(const string k, const bool v) {
	this->effect[k] = v;
}

string State::getname() const {
	return this->name;
}

int State::getcost() const {
	return this->cost;
}