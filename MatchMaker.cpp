/**
 * @file MatchMaker.cpp
 * @author Yexiang Zhou
 * @brief MatchMaker implementation
 * @date 2024-06-02
 * 
 */

#include "MatchMaker.h"
#include "TDMGameMode.h"

void MatchMaker::TDMMatchStart()
{
    TDMGameMode::GetGameMode()->Init(match_config_);
}