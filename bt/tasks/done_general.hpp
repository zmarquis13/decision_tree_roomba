/*
* done_general.hpp - Done genral task
* Author: Zeno Marquis
* HW1: Decision Trees
* 2/12/2024
*/

#pragma once


#include "bt_library/package.hpp"

#include "../globals.hpp"

#include <string>

// Implementation of the task "Done general".
class DoneGeneral final : public btl::Task
{
public:

    //Default constructor.
    explicit DoneGeneral() :
            Task("DoneGeneral")
    {}


    /**
     * Sets general cleaning to false, reports succeeded
     * 
     * @param blackboard Blackboard being used
     */
    btl::result_e run(btl::Blackboard& blackboard) const override
    {

        printMessage("General cleaning complete");
        
        blackboard.setInEnvironment(GENERAL_CLEANING, false);
        return reportSucceeded(blackboard);
        
    }
};
