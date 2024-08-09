/*
* spot_cleaning.hpp - Spot cleaning conditional
* Author: Zeno Marquis
* HW1: Decision Trees
* 2/12/2024
*/


#pragma once

#include "bt_library/package.hpp"

#include "../globals.hpp"

// Implementation of the condition "spot_cleaning".
class SpotCleaning final : public btl::Condition
{
public:
    /**
     * Default constructor.
     */
    explicit SpotCleaning() :
            Condition("SpotCleaning")
    {}

    /**
     * Checks whether spot cleaning has been requested and reports it
     * 
     * @param blackboard Blackboard being used
     */
    btl::result_e run(btl::Blackboard& blackboard) const override
    {
        printMessage("Spot Cleaning");

        if (blackboard.getInEnvironment(SPOT_CLEANING, false)){
            return reportSucceeded(blackboard);
        } else {
            return reportFailed(blackboard);
        }
        

    }
};
