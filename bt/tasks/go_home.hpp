/*
* go_hone.hpp - Go home task
* Author: Zeno Marquis
* HW1: Decision Trees
* 2/12/2024
*/

#pragma once


#include "bt_library/package.hpp"

#include "../globals.hpp"

#include <string>

// Implementation of the task "Go Home".
class GoHome final : public btl::Task
{
public:

    //Default constructor.
    explicit GoHome() :
            Task("GoHome")
    {}


    /**
     * Checks for path home, prints path and returns success if found
     * 
     * @param blackboard Blackboard being used
     */
    btl::result_e run(btl::Blackboard& blackboard) const override
    {
        
        std::string path = blackboard.getInEnvironment(HOME_PATH, "ERROR");
        if (path != "ERROR"){
            printMessage("Going home using path: ");
            printMessage(path);
            return reportSucceeded(blackboard);
        } else {
            return reportFailed(blackboard);
        }
    }
};
