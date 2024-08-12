/**
 * @file MatchEndInfo.h
 * @author Yexiang Zhou
 * @brief MatchEndInfo definition
 * @date 2024-06-02
 * 
 */

#pragma once
#include "Enumerations.h"
#include "Player.h"
#include "CombatInfo.h"
#include <map>

/**
 * @brief Match result for the match maker
 * 
 */
struct MatchEndInfo
{
    TeamID                          winner_;
    int                             score_team_a_;
    int                             score_team_b_;
    std::map<Player*, CombatInfo>   players_info_;
};
