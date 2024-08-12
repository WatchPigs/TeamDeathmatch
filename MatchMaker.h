/**
 * @file MatchMaker.h
 * @author Yexiang Zhou
 * @brief MatchMaker declaration
 * @date 2024-06-02
 * 
 */

#pragma once
#include "TDMMatchConfig.h"
#include "MatchEndInfo.h"
#include "MapGameplayObjects.h"

/**
 * @brief   It provides match start information and receiving match end information. It's a singleton
 *          and has the same lifecycle as the game instance, and can serve as an intermediate layer
 *          for communicating with systems outside of the match session or even the game instance, such as player databases.
 *          Only the key data and functions related to our game mode are listed.
 * 
 */
class MatchMaker
{
public:
    /**
     * @brief (Unimplemented) Get the pointer of the instance (as a singleton)
     * 
     * @return MatchMaker* 
     */
    static MatchMaker* GetMatchMaker();

    /**
     * @brief be called to start the match
     * 
     */
    void TDMMatchStart();

    /**
     * @brief (Unimplemented) be called by the game mode to receive the match result 
     * 
     * @param match_end_info    match result
     */
    void MatchEnd(MatchEndInfo match_end_info);

private:
    TDMMatchConfig      match_config_;
};
