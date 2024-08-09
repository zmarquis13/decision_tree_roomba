//
// Behavior Tree framework for A1 Behavior trees assignment.
// CS 131 - Artificial Intelligence
//
// version 2.0.0 - copyright (c) 2023 Santini Fabrizio. All rights reserved.
//
#pragma once

#include "bt_library/package.hpp"

#include "../globals.hpp"

// Implementation of the condition "battery_level < 30".
class BatteryLessThan30 final : public btl::Condition
{
public:
    /**
     * Default constructor.
     */
    explicit BatteryLessThan30() :
            Condition("BatteryLessThan30")
    {}

    /** @see btl::Condition.run() for more details. */
    btl::result_e run(btl::Blackboard& blackboard) const override
    {
        printMessage("Checking battery < 30");

        const auto batteryLevel = blackboard.getInEnvironment(BATTERY_LEVEL, 0);
        return batteryLevel < 30 ? reportSucceeded(blackboard) : reportFailed(blackboard);
    }
};
