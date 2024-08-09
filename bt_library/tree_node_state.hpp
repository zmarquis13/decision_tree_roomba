//
// Behavior Tree framework for A1 Behavior trees assignment.
// CS 131 - Artificial Intelligence
//
// version 2.0.0 - copyright (c) 2023 Santini Fabrizio. All rights reserved.
//
#pragma once

#include <any>
#include <memory>
#include <utility>

#include "common.hpp"

namespace btl {

// Definition of the state of a node
class TreeNodeState
{
public:
    using ptr_t = std::shared_ptr<TreeNodeState>;  // Pointer definition

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /**
     * Default constructor.
     *
     * @param result Result to associate with the node
     * @param additionalInformation Additional information to attach
     */
    TreeNodeState(const result_e result, std::any additionalInformation) :
            additionalInformation(std::move(additionalInformation)),
            result(result)
    {}

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    const std::any additionalInformation;  // Additional information attached to the node

    const result_e result;  // Current result associated with the node
};

}  // namespace btl