/*
* clean_floor.hpp - Clean floor task
* Author: Zeno Marquis
* HW1: Decision Trees
* 2/12/2024
*/

#pragma once

#include <cstdlib>

#include "bt_library/package.hpp"

#include "../globals.hpp"

// Implementation of the task "Clean floor".
class CleanFloor final : public btl::Task
{
public:
    /**
     * Default constructor.
     */
    explicit CleanFloor() :
            Task("CleanFloor")
    {}

    /**
     * Randomly determines whether floor cleaning is successful
     * 
     * @param blackboard Blackboard being used
     */
    btl::result_e run(btl::Blackboard& blackboard) const override
    {
        printMessage("Cleaning Floor");

        if (rand() % 10 == 0){
            return reportFailed(blackboard);
        } else {
            return reportSucceeded(blackboard);
        }

    }
};
