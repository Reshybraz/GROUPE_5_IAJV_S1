#include <iostream>
#include <string>
#include <vector>
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

    Action attack("Attack", 1);
    attack.setpreco(Weapon, true);
    attack.setpreco(Ammo, true);
    attack.setpreco(inRange, true);
    attack.seteffect(killEnnemy, true);
    actions.push_back(attack);

    Action moveinrange(inRange, 5);
    moveinrange.setpreco(inRange, false);
    moveinrange.seteffect(inRange, true);
    actions.push_back(moveinrange);

    Action reload("Reload", 1);
    reload.setpreco(Weapon, true);
    reload.setpreco(Ammo, false);
    reload.seteffect(Ammo, true);
    actions.push_back(reload);

    Action getweapon("GetWeapon", 3);
    getweapon.setpreco(Weapon, false);
    getweapon.setpreco(Ammo, false);
    getweapon.seteffect(Weapon, true);
    getweapon.seteffect(Ammo, true);
    actions.push_back(getweapon);

    WorldAction initial_Action("initial_Action");
    initial_Action.setvariables(Weapon, false);
    initial_Action.setvariables(Ammo, false);
    initial_Action.setvariables(inRange, false);
    initial_Action.setvariables(killEnnemy, false);

    WorldAction goal_Action("goal_Action");
    goal_Action.setvariables(killEnnemy, true);

};

