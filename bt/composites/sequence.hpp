/*
* sequence.hpp - Sequence composite
* Author: Zeno Marquis
* HW1: Decision Trees
* 2/12/2024
*/

#pragma once

#include <vector>

#include "bt_library/package.hpp"

//Sequence composite definition 
class Sequence final : public btl::Composite
{
public:
    /**
     * Static factory of the tree node.
     *
     * @param children List of children for this node
     */
    static ptr_t make(const std::vector<const_ptr_t>& children)
    {
        return new Sequence(children);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /**
     * Default constructor.
     *
     * @param children List of children for this node
     */
    explicit Sequence(const std::vector<const_ptr_t>& children) :
            Composite("Sequence", children)
    {}


    /**
     * Runs children in sequence, returns first non-success state
     * of a child, or success if all children succeed.
     * 
     * @param blackboard Current blackboard being used
     */
    btl::result_e run(btl::Blackboard& blackboard) const override
    {
        const auto runningChild = additionalInformation<int>(blackboard);

        for (int childPosition = runningChild; childPosition < children.size(); ++childPosition) {
            const auto child = children[childPosition];

            const auto resultChild = child->run(blackboard);
            if (resultChild == btl::result_e::FAILED) {
                return reportFailed(blackboard, 0);
            }
            if (resultChild == btl::result_e::RUNNING) {
                return reportRunning(blackboard, childPosition);
            }
        }

        return reportSucceeded(blackboard, 0);
    }
};
