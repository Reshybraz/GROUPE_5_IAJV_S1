#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include "Action.hpp"
#include "World.hpp"

using namespace std;

int main()
{
    vector <Action> actions;

    const string Weapon = "HasWeapon";
    const string Ammo = "HasAmmo";
    const string inRange = "InRange";
    const string killEnnemy = "KillEnemy";

    string finalcondition = killEnnemy;

    Action attack("Attack", 1);
    attack.setpreco(Weapon, true);
    attack.setpreco(Ammo, true);
    attack.setpreco(inRange, true);
    attack.seteffect(killEnnemy, true);
    actions.push_back(attack);

    Action moveinrange("Move_in_range", 5);
    moveinrange.setpreco(inRange, false);
    moveinrange.seteffect(inRange, true);
    actions.push_back(moveinrange);

    Action getweapon("GetWeapon", 3);
    getweapon.setpreco(Weapon, false);
    getweapon.setpreco(Ammo, false);
    getweapon.seteffect(Weapon, true);
    getweapon.seteffect(Ammo, true);
    actions.push_back(getweapon);

    Action reload("Reload", 1);
    reload.setpreco(Weapon, true);
    reload.setpreco(Ammo, false);
    reload.seteffect(Ammo, true);
    actions.push_back(reload);

    WorldState initial_state("initial_state");
    initial_state.setvariables(Weapon, false);
    initial_state.setvariables(Ammo, false);
    initial_state.setvariables(inRange, false);
    initial_state.setvariables(killEnnemy, false);

    WorldState goal_state("goal_state");
    goal_state.setvariables(killEnnemy, true);

    cout << "lancement de l'algorythme\n";
    list<Action> actionstodo;
    vector<string> precos;
    vector<string>precosverified;
    for (auto& prec : goal_state.getvariables()) {
        precos.push_back(prec.first);
    }
    assert(precos.size() != 0);
    int i = 0;
    int cost = 0;
    while (precos.size() > 0 && i < 10) {
        string preco = precos[0];
        const auto& begin = precos.begin();
        const auto& end = precos.end();
        ptrdiff_t pos = find(begin, end, preco) - begin;
        if (find(precosverified.begin(), precosverified.end(), preco) != precosverified.end()) {
            precos.erase(begin + pos);
        }
        for (Action a : actions) {
            unordered_map<string, bool> aEffects = a.geteffect(); // attentio !
            if (aEffects.find(preco) != aEffects.end() && aEffects.at(preco) == true) {
                actionstodo.push_back(a);
                cost += a.getcost();
                precosverified.push_back(preco);
                for (auto& prec : a.getpreco()) {
                    if (find(begin, end, prec.first) != end) {
                        if (!(find(precosverified.begin(), precosverified.end(), prec.first) != precosverified.end())) {
                            precosverified.push_back(prec.first);
                            precos.erase(precos.begin() + pos);

                        }
                    }
                    else {
                        precos.push_back(prec.first);
                    }
                }
                break;
            }
        }
        precos.erase(precos.begin()+pos);
        i++;
    }
    for (Action a : actionstodo) {
        cout << a.getname() << "\n";
    }
    cout << "\n";
    cout << "cout total : " << cost;
    /*
    for (string s : precos) {
        cout << s << "\n";
    }
    cout << "\n";
    for (string s : precosverified) {
        cout << s << "\n";
    }*/
};

