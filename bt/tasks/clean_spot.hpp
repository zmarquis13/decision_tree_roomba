/*
* clean_spot.hpp - Clean spot task
* Author: Zeno Marquis
* HW1: Decision Trees
* 2/12/2024
*/

#pragma once


#include "bt_library/package.hpp"

#include "../globals.hpp"

// Implementation of the task "Clean spot".
class CleanSpot final : public btl::Task
{
public:
    /**
     * Default constructor.
     */
    explicit CleanSpot() :
            Task("CleanSpot")
    {}

    /**
     * Prints spot cleaning, returns success
     * 
     * @param blackboard Blackboard being used
     */
    btl::result_e run(btl::Blackboard& blackboard) const override
    {
        printMessage("Spot Cleaning");
        
        return reportSucceeded(blackboard);
    }
};
