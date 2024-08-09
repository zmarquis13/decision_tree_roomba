//
// Behavior Tree framework for A1 Behavior trees assignment.
// CS 131 - Artificial Intelligence
//
// version 2.0.0 - copyright (c) 2023 Santini Fabrizio. All rights reserved.
//
#pragma once

#include <any>
#include <iostream>
#include <utility>

#include "common.hpp"
#include "blackboard.hpp"

namespace btl {

static int _identification_counter = 0;  // Counter for the automatic and unique generation of tree identities.

class TreeNode
{
public:
    using ptr_t = TreeNode*;  // Pointer definition
    using const_ptr_t = const TreeNode*;  // Pointer definition

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /**
     * Default constructor.
     *
     * @param name Human-readable class name
     */
    explicit TreeNode(std::string name) :
            id(_identification_counter++),
            name(std::move(name))
    {}

    /** Default destructor. */
    virtual ~TreeNode() = default;

    /**
     * Find the additional information attached to this node in the specified blackboard.
     *
     * @tparam RETURN_TYPE Type of the value to return
     * @param blackboard Blackboard with the current state of the tree
     * @param defaultValue Value to return if the node state was not found in the blackboard
     * @return The additional information associated with this node in the blackboard
     */
    template<typename RETURN_TYPE>
    [[nodiscard]] RETURN_TYPE additionalInformation(const Blackboard& blackboard,
                                                    RETURN_TYPE defaultValue = RETURN_TYPE()) const
    {
        if (!blackboard.isInStates(id)) {
            return defaultValue;
        }

        return std::any_cast<RETURN_TYPE>(blackboard.getInStates(id)->additionalInformation);
    }


    /** @return Return the pretty version of the node class and identification. */
    [[nodiscard]] std::string prettyId() const
    {
        return name + "(" + std::to_string(id) + ")";
    }

    /**
     * Print the specified message with a pretty print.
     *
     * @param message Message to print
     */
    void printMessage(const std::string& message) const
    {
        std::cout << prettyId() << ": " << message << std::endl;
    }

    /**
     * Before returning a failed state, print it in a human-readable way.
     *
     * @param blackboard Blackboard with the current state of the problem
     * @param additionalInformation Additional information for the node to store in the blackboard
     * @return The specified result
     */
    result_e reportFailed(Blackboard& blackboard, const std::any& additionalInformation = nullptr) const
    {
        blackboard.setInStates(
            id,
            std::make_shared<TreeNodeState>(result_e::FAILED, additionalInformation)
        );
        printMessage("FAILED");

        return result_e::FAILED;
    }

    /**
     * Before returning a running state, print it in a human-readable way.
     *
     * @param blackboard Blackboard with the current state of the problem
     * @param additionalInformation Additional information for the node to store in the blackboard
     * @return The specified result
     */
    result_e reportRunning(Blackboard& blackboard, const std::any& additionalInformation = nullptr) const
    {
        blackboard.setInStates(
            id,
            std::make_shared<TreeNodeState>(result_e::RUNNING, additionalInformation)
        );
        printMessage("RUNNING");

        return result_e::RUNNING;
    }

    /**
     * Before returning a succeeded state, print it in a human-readable way.
     *
     * @param blackboard Blackboard with the current state of the problem
     * @param additionalInformation Additional information for the node to store in the blackboard
     * @return The specified result
     */
    result_e reportSucceeded(Blackboard& blackboard, const std::any& additionalInformation = nullptr) const
    {
        blackboard.setInStates(
            id,
            std::make_shared<TreeNodeState>(result_e::SUCCEEDED, additionalInformation)
        );
        printMessage("SUCCEEDED");

        return result_e::SUCCEEDED;
    }

    /**
     * Find the result of this node in the specified blackboard.
     *
     * @param blackboard Blackboard with the current state of the tree
     * @return The result associated with this node in the blackboard
     */
    [[nodiscard]] result_e result(const Blackboard& blackboard) const
    {
        if (!blackboard.isInStates(id)) {
            return result_e::UNDEFINED;
        }

        return blackboard.getInStates(id)->result;
    }

    /**
     * Execute the behavior of the node.
     *
     * @param blackboard Blackboard with the current state of the problem
     * @return The result of the execution
     */
    virtual result_e run(Blackboard& blackboard) const
    {
        return reportFailed(blackboard, nullptr);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    const node_id_t id;  // Identification of the node

    const std::string name;  // Human-readable name of the node class
};

}  // namespace btl