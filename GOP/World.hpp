#pragma once
#include <string>
#include <unordered_map>

using namespace std;
#ifndef _WORLD_HPP_
#define _WORLD_HPP_

class WorldState {
private:
	string name;
	unordered_map<string,bool> variables;
public:
	WorldState(string name);

	void setvariables(const string key, const bool value);
	unordered_map<string, bool> getvariables();
};

#endif
