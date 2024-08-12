/**
 * @file DamageCauser.cpp
 * @author Yexiang Zhou
 * @brief DamageCauser definition
 * @date 2024-06-02
 * 
 */

#include "DamageCauser.h"

Player* DamageCauser::GetOwner()
{
    return owner_;
}

void DamageCauser::ApplyDamage(Player* target, int damage)
{
    target->TakeDamage(this, damage);
}