#include "World.hpp"

WorldState::WorldState(string name) {
	this->name = name;
}

void WorldState::setvariables(const string key, const bool value) {
	this->variables[key] = value;
}

unordered_map<string, bool> WorldState::getvariables() {
	return this->variables;
}
