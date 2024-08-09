//
// Behavior Tree framework for A1 Behavior trees assignment.
// CS 131 - Artificial Intelligence
//
// version 2.0.0 - copyright (c) 2023 Santini Fabrizio. All rights reserved.
//
#pragma once

#include <vector>

#include "tree_node.hpp"

namespace btl {

// The generic definition of a composite tree node class.
class Composite : public TreeNode
{
public:
    /**
     * Default constructor.
     *
     * @param name Human-readable class name
     * @param children List of children for this node
     */
    Composite(const std::string& name, const std::vector<const_ptr_t>& children) :
            TreeNode(name),
            children(children)
    {}

protected:
    const std::vector<const_ptr_t> children;  // List of children of the composite
};

}  // namespace btl
