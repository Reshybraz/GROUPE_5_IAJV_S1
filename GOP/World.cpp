#include "World.hpp"

WorldAction::WorldAction(string name) {
	this->name = name;
}

void WorldAction::setvariables(const string key, const bool value) {
	this->variables[key] = value;
}

unordered_map<string, bool> WorldAction::getvariables() {
	return this->variables;
}
