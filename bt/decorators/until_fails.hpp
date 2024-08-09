/*
* until_fails.hpp - Until fails decorator
* Author: Zeno Marquis
* HW1: Decision Trees
* 2/12/2024
* File structure based on timer.hpp by Santini Fabrizio (2023)
*/


#pragma once

#include "bt_library/decorator.hpp"

namespace btl {

// The generic definition of a decorator tree node class.
class UntilFails final : public Decorator
{
public:
    

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /**
     * Static factory of the tree node.
     *
     * @param child Child for this node
     */
    static ptr_t make(const const_ptr_t child)
    {
        return new UntilFails(child);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /**
     * Default constructor.
     *
     * @param child Child for this node
     */
    UntilFails(const const_ptr_t child):
            Decorator("UntilFails", child)
    {}

    /**
     * Runs child, reports running unless child fails,
     * in which case reports succeeded
     * 
     * @param blackboard Blackboard being used
     */
    result_e run(Blackboard& blackboard) const override
    {
        // If the child failed, terminate immediately the timer
        if (child->run(blackboard) == result_e::FAILED) {
            return reportSucceeded(blackboard);
        } else {
            return reportRunning(blackboard);
        }
    }
};

}  // namespace btl
