/**
 * @file Player.h
 * @author Yexiang Zhou
 * @brief Player declaration
 * @date 2024-06-02
 * 
 */

#pragma once
#include "Enumerations.h"
#include "DamageCauser.h"
#include "Weapon.h"
#include "Equipment.h"
#include "SpawnPoint.h"
#include <vector>
#include <string>

/**
 * @brief Player class, with gameplay attributes and pointers of attached objects
 *        Only the key data and functions related to our game mode are listed
 * 
 */
class Player
{
public:

    /**
     * @brief Get the player's Team ID
     * 
     * @return TeamID 
     */
    TeamID GetTeamID();

    /**
     * @brief (Unimplemented) spawn at the spawn point, reset all the stats, like health, loadout, ammo
     * 
     * @param spawn_point
     */
    void Spawn(SpawnPoint* spawn_point);
    
    /**
     * @brief Take damage from something
     * 
     * @param source    can be weapons, equipments or environment
     * @param damage    how many damage points
     */
    void TakeDamage(DamageCauser* source, int damage);
    
    /**
     * @brief (Unimplemented) just die, the logic depends on the core combat system (clean stats, play animation, etc.)
     * 
     */
    void Die();
    
private:
    TeamID                  team_id_;   // the player's team id
    int                     health_;    // current health
    std::vector<Weapon*>    weapons_;   // all the weapons in current loadout
    std::vector<Equipment*> equipments_;// all the equipments in current loadout
};

