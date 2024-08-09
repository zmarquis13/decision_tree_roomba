/*
* do_nothing.hpp - Do nothing task
* Author: Zeno Marquis
* HW1: Decision Trees
* 2/12/2024
*/


#pragma once

#include "bt_library/package.hpp"

#include "../globals.hpp"

// Implementation of the task "Do Nothing".
class DoNothing final : public btl::Task
{
public:
    /**
     * Default constructor.
     */
    explicit DoNothing() :
            Task("DoNothing")
    {}

    /**
     * Does nothing
     * 
     * @param blackboard Blackboard being used
     */
    btl::result_e run(btl::Blackboard& blackboard) const override
    {
        printMessage("Doing Nothing");
        
        return reportSucceeded(blackboard);
    }
};