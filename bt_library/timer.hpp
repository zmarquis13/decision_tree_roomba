//
// Behavior Tree framework for A1 Behavior trees assignment.
// CS 131 - Artificial Intelligence
//
// version 2.0.0 - copyright (c) 2023 Santini Fabrizio. All rights reserved.
//
#pragma once


#include "decorator.hpp"

namespace btl {

// The generic definition of a decorator tree node class.
class Timer final : public Decorator
{
public:
    const int TIMER_NOT_IN_USE = -1;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /**
     * Static factory of the tree node.
     *
     * @param time Duration of the timer [counts]
     * @param child Child for this node
     */
    static ptr_t make(const int time, const const_ptr_t child)
    {
        return new Timer(time, child);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /**
     * Default constructor.
     *
     * @param time Duration of the timer [counts]
     * @param child Child for this node
     */
    Timer(const int time, const const_ptr_t child):
            Decorator("Timer", child),
            definedTime(time)
    {}

    /** @see Decorator.run() for more details. */
    result_e run(Blackboard& blackboard) const override
    {
        // If there is no state for the timer, or it is not in use,
        // reset the timer to the defined value
        const auto timerPeriod = additionalInformation<int>(blackboard, TIMER_NOT_IN_USE);
        auto timeToExpiration = timerPeriod > TIMER_NOT_IN_USE ? timerPeriod : definedTime;

        // Advance the definedTime
        timeToExpiration--;

        // If the definedTime expired, do not evaluate the child.
        // Just return immediately with a successful result
        if (timeToExpiration < 0) {
            return reportSucceeded(blackboard, TIMER_NOT_IN_USE);
        }

        // Evaluate the child
        printMessage("time-to-expiration = " + std::to_string(timeToExpiration));

        // If the child failed, terminate immediately the timer
        if (child->run(blackboard) == result_e::FAILED) {
            return reportFailed(blackboard, TIMER_NOT_IN_USE);
        }

        return reportRunning(blackboard, timeToExpiration);
    }

protected:
    const int definedTime;  // Duration of the definedTime [counts]
};

}  // namespace btl
