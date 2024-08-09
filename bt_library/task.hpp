//
// Behavior Tree framework for A1 Behavior trees assignment.
// CS 131 - Artificial Intelligence
//
// version 2.0.0 - copyright (c) 2023 Santini Fabrizio. All rights reserved.
//
#pragma once

#include "tree_node.hpp"

namespace btl {

// The generic definition of a task tree node class.
class Task : public TreeNode
{
public:
    /**
     * Default constructor.
     *
     * @param name Human-readable class name
     */
    explicit Task(const std::string& name):
            TreeNode(name)
    {}
};


}  // namespace btl
