/**
 * @file TDMGameMode.h
 * @author Yexiang Zhou
 * @brief 
 * @date 2024-06-02
 * 
 */

#pragma once
#include "Enumerations.h"
#include "TDMMatchConfig.h"
#include "Player.h"
#include "CombatInfo.h"
#include "Timer.h"
#include <map>
#include <queue>

/**
 * @brief Core mechanics of the game mode, handling team and player scores, game progress,
 *        frags, player respawns, and communicating with the match makers and the UI system
 * 
 */
class TDMGameMode
{
public:
    /**
     * @brief (Unimplemented) Get the pointer of the instance (as a singleton)
     * 
     * @return TDMGameMode* 
     */
    static TDMGameMode* GetGameMode();

    /**
     * @brief Set up match config, initialize all the data and start the match
     * 
     * @param match_config 
     */
    void Init(TDMMatchConfig match_config);

    /**
     * @brief Get current match time
     * 
     * @return Time 
     */
    Time GetMatchTime();

    /**
     * @brief Be called when a player got fragged
     * 
     * @param source    source of the damage, can be weapons, equipments or environment
     * @param killed    the player who got fragged
     */
    void Frag(DamageCauser* source, Player* killed);

private:
    /**
     * @brief spawn a dead player on the best spawn point
     * 
     * @param player 
     */
    void Respawn(Player* player);
    
    /**
     * @brief spawn a dead player on the best spawn point
     * 
     */
    void RespawnNext();

    /**
     * @brief (Unimplemented) Pick a best spawn point for the team. It's a complicated task.
     * 
     * @param team_id
     * @return SpawnPoint* 
     */
    SpawnPoint* PickSpawnPoint(TeamID team_id);

    /**
     * @brief Check if the match is over (time is up or a team reaches the max score)
     * 
     */
    void CheckEnd();

    /**
     * @brief Match is over. Send match end info to the match maker
     * 
     */
    void MatchEnd();
    
    TDMMatchConfig                  match_config_;          // match config, including rules and map objects
    int                             score_team_a_;          // score of team a
    int                             score_team_b_;          // score of team b
    std::map<Player*, CombatInfo>   players_info_;          // players and their combat info
    Timer                           match_timer_;           // match time
    std::queue<Player*>             respawn_queue_;         // player respawn queue
};