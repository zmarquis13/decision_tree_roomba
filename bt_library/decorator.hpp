//
// Behavior Tree framework for A1 Behavior trees assignment.
// CS 131 - Artificial Intelligence
//
// version 2.0.0 - copyright (c) 2023 Santini Fabrizio. All rights reserved.
//
#pragma once

#include "tree_node.hpp"

namespace btl {

// The generic definition of a decorator tree node class.
class Decorator : public TreeNode
{
public:
    /**
     * Default constructor.
     *
     * @param name Human-readable class name
     * @param child Child for this node
     */
    Decorator(const std::string& name, const const_ptr_t child) :
            TreeNode(name),
            child(child)
    {}

protected:
    const const_ptr_t child;  // Child associated with this decorator
};

}  // namespace btl
