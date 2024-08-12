/**
 * @file Enumerations.h
 * @author Yexiang Zhou
 * @brief Practical enumeration definitions
 * @date 2024-06-02
 * 
 */

/**
 * @brief   Representing team info
 * 
 */
enum class TeamID
{
    kNone,
    kTeamA,
    kTeamB
};

/**
 * @brief   Representing game mode info for other game systems (such as UI)
 * 
 */
enum class GameMode
{
    kNone,
    kTeamDeathmatch
};