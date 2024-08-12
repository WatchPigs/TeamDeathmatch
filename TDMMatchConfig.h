/**
 * @file TDMMatchConfig.h
 * @author Yexiang Zhou
 * @brief TDMMatchConfig definition
 * @date 2024-06-02
 * 
 */

#pragma once
#include "Time.h"
#include "MapGameplayObjects.h"

/**
 * @brief   Information related to match rules and map objects
 * 
 */
struct TDMMatchConfig
{
    int                 max_score_;
    Time                max_match_time;
    Time                respawn_time;
    MapGameplayObjects  map_objects_;
};
