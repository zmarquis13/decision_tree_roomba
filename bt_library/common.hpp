//
// Behavior Tree framework for A1 Behavior trees assignment.
// CS 131 - Artificial Intelligence
//
// version 2.0.0 - copyright (c) 2023 Santini Fabrizio. All rights reserved.
//
#pragma once

#include <string>

namespace btl {

// Definition of some common types
using environment_key_t = std::string;
using node_id_t = int;

// Possible results of an evaluation
enum class result_e {
    UNDEFINED = 0,
    FAILED = 1,
    RUNNING = 2,
    SUCCEEDED = 3
};

}  // namespace btl
