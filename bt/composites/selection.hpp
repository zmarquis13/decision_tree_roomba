//
// Behavior Tree framework for A1 Behavior trees assignment.
// CS 131 - Artificial Intelligence
//
// version 2.0.0 - copyright (c) 2023 Santini Fabrizio. All rights reserved.
//
#pragma once

#include <vector>

#include "bt_library/package.hpp"

/** The generic definition of a sequence tree node class. */
class Selection final : public btl::Composite
{
public:
    /**
     * Static factory of the tree node.
     *
     * @param children List of children for this node
     */
    static ptr_t make(const std::vector<const_ptr_t>& children)
    {
        return new Selection(children);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /**
     * Default constructor.
     *
     * @param children List of children for this node
     */
    explicit Selection(const std::vector<const_ptr_t>& children) :
            Composite("Selection", children)
    {}

    //runs each child in order, returns running if any are running, failed if all fail, and succeeded if any succeed  

    /** @see Composite.run() for more details. */
    btl::result_e run(btl::Blackboard& blackboard) const override
    {
        const auto runningChild = additionalInformation<int>(blackboard);

        for (int childPosition = runningChild; childPosition < children.size(); ++childPosition) {
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
