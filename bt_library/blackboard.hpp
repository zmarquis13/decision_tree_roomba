//
// Behavior Tree framework for A1 Behavior trees assignment.
// CS 131 - Artificial Intelligence
//
// version 2.0.0 - copyright (c) 2023 Santini Fabrizio. All rights reserved.
//
#pragma once

#include <any>
#include <unordered_map>

#include "common.hpp"
#include "tree_node_state.hpp"

namespace btl {

// Definition of the blackboard class
class Blackboard {
public:
    /**
     * Return the value in the environment associated with the specified key.
     *
     * @tparam RETURN_TYPE Type of the value to return
     * @param key Key to query
     * @param defaultValue Value to return if the key was not found in the blackboard
     * @return The value associated with the key (if it exists)
     */
    template<typename RETURN_TYPE>
    RETURN_TYPE getInEnvironment(const environment_key_t& key,
                                 RETURN_TYPE defaultValue = RETURN_TYPE()) const
    {
        return environment_.count(key) > 0 ? std::any_cast<RETURN_TYPE>(environment_.at(key)) : defaultValue;
    }

    /**
     * Return the value in the states associated with the specified node ID.
     *
     * @param nodeId Identification of the node to query
     * @return The value associated with the node ID (if it exists)
     */
    TreeNodeState::ptr_t getInStates(const node_id_t nodeId) const
    {
        return states_.count(nodeId) > 0 ? states_.at(nodeId) : nullptr;
    }

    /**
     * Return TRUE if the specified node ID is in the states map.
     *
     * @param nodeId Identification of the node to query
     * @return TRUE if the node ID is in the states map
     */
    bool isInStates(const node_id_t nodeId) const
    {
        return states_.count(nodeId) > 0;
    }

    /**
     * Set a variable in the environment portion of the blackboard.
     *
     * @param key Key to set
     * @param value Value associated with the key
     */
    void setInEnvironment(const environment_key_t &key, const std::any& value)
    {
        environment_[key] = value;
    }

    /**
     * Set a variable in the states portion of the blackboard.
     *
     * @param nodeId Identification of the node to set
     * @param value Value associated with the key
     */
    void setInStates(const node_id_t nodeId, const TreeNodeState::ptr_t& value)
    {
        states_[nodeId] = value;
    }

private:
    std::unordered_map<environment_key_t, std::any> environment_;  // State of the environmental variables

    std::unordered_map<node_id_t, TreeNodeState::ptr_t> states_;  // State of the nodes
};

}  // namespace btl
