/*
* dock.hpp - Dock task
* Author: Zeno Marquis
* HW1: Decision Trees
* 2/12/2024
*/

#pragma once

#include "bt_library/package.hpp"

#include "../globals.hpp"

#include <string>

// Implementation of the task "Dock".
class Dock final : public btl::Task
{
public:

    //Default constructor.
    explicit Dock() :
            Task("Dock")
    {}


    /**
     * Charges the battery by changing the blackboard value
     * 
     * @param blackboard Blackboard being used
     */
    btl::result_e run(btl::Blackboard& blackboard) const override
    {
        
        int curr_battery = blackboard.getInEnvironment(BATTERY_LEVEL, -1);
        
        //check for invalid battery state 
        //(unsuccessful charge or no blackboard value)
        if (curr_battery == -1){
            printMessage("ERROR: Could not retrieve battery value");
            exit(EXIT_FAILURE);
        }

        //charges battery or reports full charging
        if (curr_battery < 94){
            curr_battery += 6;
            printMessage("Charging. Now at " + std::to_string(curr_battery) + '%');
        } else {
            curr_battery = 100;
            printMessage("Charging complete");
        }

        blackboard.setInEnvironment(BATTERY_LEVEL, curr_battery);

        //reports battery state
        if (curr_battery == 100){
            return reportFailed(blackboard);
        } else {
            return reportRunning(blackboard);
        } 
    }
};
