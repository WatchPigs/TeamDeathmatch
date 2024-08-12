/**
 * @file TDMGameMode.cpp
 * @author Yexiang Zhou
 * @brief 
 * @date 2024-06-02
 * 
 */

#include "TDMGameMode.h"
#include "UISystem.h"
#include "MatchEndInfo.h"
#include "MatchMaker.h"

void TDMGameMode::Init(TDMMatchConfig match_config)
{
    // set match config
    match_config_ = match_config;

    // reset team scores
    score_team_a_ = 0;
    score_team_b_ = 0;
    for (auto player_info : players_info_)
    {
        // reset combat infos
        player_info.second.kills_ = 0;
        player_info.second.deaths_ = 0;

        // spawn players
        Respawn(player_info.first);
    }
    
    // set match timer
    match_timer_ = Timer::NewTimer(match_config_.max_match_time, std::bind(&TDMGameMode::MatchEnd, this), true);
}

Time TDMGameMode::GetMatchTime()
{
    return match_timer_.GetTime();
}

void TDMGameMode::Frag(DamageCauser* source, Player* killed)
{
    respawn_queue_.push(killed);
    Timer::DelayCall(match_config_.respawn_time, std::bind(&TDMGameMode::RespawnNext, this));

    Player* damage_owner = source->GetOwner();
    UISystem::GetUISystem()->NewFragInfo(damage_owner, killed, source);

    // update the killed player info
    players_info_[killed].deaths_++;
    UISystem::GetUISystem()->UpdatePlayerCombatInfo(killed, players_info_[killed]);

    // if it's not environmental kill, killer and killer's team get one kill and score
    if (damage_owner != nullptr)
    {
        if (damage_owner->GetTeamID() == TeamID::kTeamA) UISystem::GetUISystem()->UpdateTeamScore(damage_owner->GetTeamID(), ++score_team_a_);
        else UISystem::GetUISystem()->UpdateTeamScore(damage_owner->GetTeamID(), ++score_team_b_);
        players_info_[damage_owner].kills_++;
        UISystem::GetUISystem()->UpdatePlayerCombatInfo(damage_owner, players_info_[damage_owner]);
    }

    CheckEnd();
}

void TDMGameMode::Respawn(Player* player)
{
    player->Spawn(PickSpawnPoint(player->GetTeamID()));
}

void TDMGameMode::RespawnNext()
{
    Respawn(respawn_queue_.front());
    respawn_queue_.pop();
}

void TDMGameMode::CheckEnd()
{
    if (score_team_a_ >= match_config_.max_score_ || score_team_b_ >= match_config_.max_score_) MatchEnd();
}

void TDMGameMode::MatchEnd()
{
    // decide winner
    TeamID winner = score_team_a_ > score_team_b_ ? TeamID::kTeamA : TeamID::kTeamB;
    if (score_team_a_ == score_team_b_) winner = TeamID::kNone;

    MatchEndInfo match_end_info = { winner, score_team_a_, score_team_b_, players_info_};

    UISystem::GetUISystem()->MatchEnd(match_end_info);
    MatchMaker::GetMatchMaker()->MatchEnd(match_end_info);
}