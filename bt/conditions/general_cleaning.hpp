/*
* general_cleaning.hpp - General cleaning conditional
* Author: Zeno Marquis
* HW1: Decision Trees
* 2/12/2024
*/


#pragma once

#include "bt_library/package.hpp"

#include "../globals.hpp"

// Implementation of the condition "general_cleaning".
class GeneralCleaning final : public btl::Condition
{
public:
    /**
     * Default constructor.
     */
    explicit GeneralCleaning() :
            Condition("GeneralCleaning")
    {}

    /**
     * Checks whether general cleaning has been requested and reports it
     * 
     * @param blackboard Blackboard being used
     */
    btl::result_e run(btl::Blackboard& blackboard) const override
    {
        printMessage("General Cleaning");

        if (blackboard.getInEnvironment(GENERAL_CLEANING, false)){
            return reportSucceeded(blackboard);
        } else {
            return reportFailed(blackboard);
        }
        

    }
};
