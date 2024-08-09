//
// Behavior Tree framework for A1 Behavior trees assignment.
// CS 131 - Artificial Intelligence
//
// version 2.0.0 - copyright (c) 2023 Santini Fabrizio. All rights reserved.
//
#pragma once

#include "bt_library/package.hpp"

#include "../globals.hpp"

// Implementation of the task "Find Home".
class FindHome final : public btl::Task
{
public:
    /**
     * Default constructor.
     */
    explicit FindHome() :
            Task("FindHome")
    {}

    /** @see btl::Task.run() for more details. */
    btl::result_e run(btl::Blackboard& blackboard) const override
    {
        printMessage("Looking for a home");

        blackboard.setInEnvironment(HOME_PATH, "Up Left Left Up Right");

        return reportSucceeded(blackboard);
    }
};
