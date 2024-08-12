/**
 * @file DamageCauser.h
 * @author Yexiang Zhou
 * @brief 
 * @date 2024-06-02
 * 
 */

#pragma once
#include "Player.h"

/**
 * @brief Game objects that can cause damage, can be weapons, equipments or environment
 * 
 */
class DamageCauser
{
public:
    /**
     * @brief Get the owner
     * 
     * @return Player* 
     */
    Player* GetOwner();

    /**
     * @brief Cause damage to a player
     * 
     * @param target    the player who will take the damage
     * @param damage    how many damage points
     */
    void ApplyDamage(Player* target, int damage);
    
private:
    Player*     owner_; // it can owner by a player, or just environment(nullptr)
};
