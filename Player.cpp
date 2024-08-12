/**
 * @file Player.h
 * @author Yexiang Zhou
 * @brief Player implementation
 * @date 2024-06-02
 * 
 */

#include "Player.h"
#include "TDMGameMode.h"

TeamID Player::GetTeamID()
{
    return team_id_;
}

void Player::TakeDamage(DamageCauser* source, int damage)
{
    health_ -= damage;
    if (health_ <= 0)
    {
        TDMGameMode::GetGameMode()->Frag(source, this);
        Die();
    }
}