#pragma once
#include <string>
#include <unordered_map>

using namespace std;
#ifndef _STATE_HPP_
#define _STATE_HPP_

class State{
private:
	unordered_map<string, bool> precondition;
	string name;
	unordered_map<string, bool> effect;
	int cost;
public:
	State(string n, int c);
	unordered_map<string, bool> getpreco() const;
	unordered_map<string, bool> geteffect() const;
	void setpreco(const string key, const bool value);
	void seteffect(const string key, const bool value);
	string getname() const;
	int getcost() const;
};

#endif