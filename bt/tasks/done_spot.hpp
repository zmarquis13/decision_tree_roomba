/*
* done_spot.hpp - Done spot task
* Author: Zeno Marquis
* HW1: Decision Trees
* 2/12/2024
*/


#pragma once

#include "bt_library/package.hpp"

#include "../globals.hpp"

// Implementation of the condition "done_spot".
class DoneSpot final : public btl::Condition
{
public:
    /**
     * Default constructor.
     */
    explicit DoneSpot() :
            Condition("DoneSpot")
    {}

    /**
     * Sets spot cleaning to false, reports succeeded
     * 
     * @param blackboard Blackboard being used
     */
    btl::result_e run(btl::Blackboard& blackboard) const override
    {
        printMessage("Spot cleaning complete");

        blackboard.setInEnvironment(SPOT_CLEANING, false);
        return reportSucceeded(blackboard);
        

    }
};
