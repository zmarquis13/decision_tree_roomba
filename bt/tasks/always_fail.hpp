/*
* always_fail.hpp - Always fail task
* Author: Zeno Marquis
* HW1: Decision Trees
* 2/12/2024
*/

#pragma once

#include "bt_library/package.hpp"

#include "../globals.hpp"

// Implementation of the task "Always Fail".
class AlwaysFail final : public btl::Task
{
public:
    /**
     * Default constructor.
     */
    explicit AlwaysFail() :
            Task("AlwaysFail")
    {}

    /**
     * Reports failure to blackboard
     * 
     * @param blackboard Blackboard being used
     */
    btl::result_e run(btl::Blackboard& blackboard) const override
    {
        printMessage("Failing");

        return reportFailed(blackboard);
    }
};
