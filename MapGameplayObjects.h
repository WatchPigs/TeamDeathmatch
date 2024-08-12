/**
 * @file MapGameplayObjects.h
 * @author Yexiang Zhou
 * @brief MapGameplayObjects definition
 * @date 2024-06-02
 * 
 */

#pragma once
#include "SpawnPoint.h"
#include <set>

/**
 * @brief gameplay related objects in the map
 * 
 */
struct MapGameplayObjects
{
    std::set<SpawnPoint*>   tdm_spawn_points_;
};
