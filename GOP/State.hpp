#pragma once
#include <string>

using namespace std;
#ifndef _STATE_HPP_
#define _STATE_HPP_

class State{
private:
	string precondition;
	string name;
	string effect;
	int cost;
public:
	State(string p, string n, string e, int c);
	string getpreco() const;
	string getname() const;
	string geteffect() const;
	int getcost() const;
};

#endif