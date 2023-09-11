#include "State.hpp"

State::State(string p, string n, string e, int c) {
	this->precondition = p;
	this->name = n;
	this->effect = e;
	this->cost = c;
}

string State::getpreco() const {
	return this->precondition;
}

string State::getname() const {
	return this->name;
}

string State::geteffect() const {
	return this->effect;
}

int State::getcost() const {
	return this->cost;
}