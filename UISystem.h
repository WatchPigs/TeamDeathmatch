/**
 * @file UISystem.h
 * @author Yexiang Zhou
 * @brief UISystem declaration
 * @date 2024-06-02
 * 
 */

#pragma once
#include "TDMGameMode.h"
#include "MatchEndInfo.h"
#include <string>

/**
 * @brief Game UI System, for display gameplay informations on client, like HUD, scoreboard, etc. It's a singleton.
 *        Only the key data and functions related to our game mode are listed
 * 
 */
class UISystem
{
public:
    /**
     * @brief (Unimplemented) Get the pointer of the instance (as a singleton)
     * 
     * @return UISystem* 
     */
    static UISystem* GetUISystem();

    /**
     * @brief (Unimplemented) Set HUD layout according to the game mode
     * 
     * @param game_mode game mode enumeration
     */
    void SetGameModeLayout(GameMode game_mode);
    
    /**
     * @brief (Unimplemented) Update team score on HUD and scoreboard
     * 
     * @param team_id
     * @param score
     */
    void UpdateTeamScore(TeamID team_id, int score);
    
    /**
     * @brief (Unimplemented) Update a player's combat info(kills, deaths) on scoreboard
     * 
     * @param player
     * @param combat_info kills, deaths
     */
    void UpdatePlayerCombatInfo(Player* player, CombatInfo combat_info);

    /**
     * @brief (Unimplemented) Display a new frag info on HUD
     * 
     * @param killer
     * @param killed
     * @param medium the object that can cause damage, can be weapons, equipments or environment
     */
    void NewFragInfo(Player* killer, Player* killed, DamageCauser* medium);

    /**
     * @brief (Unimplemented) Display match result info on HUD when the match is end
     * 
     * @param match_end_info
     */
    void MatchEnd(MatchEndInfo match_end_info);
};
