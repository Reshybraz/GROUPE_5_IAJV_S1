#pragma once
#include <string>
#include <unordered_map>

using namespace std;
#ifndef _ACTION_HPP_
#define _ACTION_HPP_

class Action{
private:
	unordered_map<string, bool> precondition;
	string name;
	unordered_map<string, bool> effect;
	int cost;
public:
	Action(string n, int c);
	unordered_map<string, bool> getpreco() const;
	unordered_map<string, bool> geteffect() const;
	void setpreco(const string key, const bool value);
	void seteffect(const string key, const bool value);
	string getname() const;
	int getcost() const;
};

#endif