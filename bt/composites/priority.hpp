/*
* priority.hpp - Priority composite
* Author: Zeno Marquis
* HW1: Decision Trees
* 2/12/2024
*/

#pragma once

#include <vector>

#include "bt_library/package.hpp"

//Priority composite definiton
class Priority final : public btl::Composite
{
public:
    /**
     * Static factory of the tree node.
     *
     * @param children List of children for this node
     */
    static ptr_t make(const std::vector<const_ptr_t>& children)
    {
        return new Priority(children);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /**
     * Default constructor.
     *
     * @param children List of children for this node
     */
    explicit Priority(const std::vector<const_ptr_t>& children) :
            Composite("Priority", children)
    {}

    /**
     * Runs children in order of priority, returns first non-fail state
     * of a child, or failed if all children fail.
     * 
     * @param blackboard Current blackboard being used
     */
    btl::result_e run(btl::Blackboard& blackboard) const override
    {
        
        for (int childPosition = 0; childPosition < children.size(); ++childPosition) {
            const auto child = children[childPosition];

            const auto resultChild = child->run(blackboard);
            if (resultChild == btl::result_e::SUCCEEDED) {
                return reportSucceeded(blackboard, 0);
            }
            if (resultChild == btl::result_e::RUNNING) {
                return reportRunning(blackboard, childPosition);
            }
        }

        return reportFailed(blackboard, 0);
    }
};
