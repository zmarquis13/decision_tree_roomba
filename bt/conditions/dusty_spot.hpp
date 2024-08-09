/*
* dusty_spot.hpp - Dusty spot conditional
* Author: Zeno Marquis
* HW1: Decision Trees
* 2/12/2024
*/


#pragma once

#include "bt_library/package.hpp"

#include "../globals.hpp"

// Implementation of the condition "dusty_spot".
class DustySpot final : public btl::Condition
{
public:
    /**
     * Default constructor.
     */
    explicit DustySpot() :
            Condition("DustySpot")
    {}

    /**
     * Checks the value of the dusty spot sensor and reports it
     * 
     * @param blackboard Blackboard being used
     */
    btl::result_e run(btl::Blackboard& blackboard) const override
    {
        printMessage("Checking if Spot is Dusty");

        if (blackboard.getInEnvironment(DUSTY_SPOT_SENSOR, false)){
            return reportSucceeded(blackboard);
        } else {
            return reportFailed(blackboard);
        }
        
    }
};
