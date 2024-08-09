//
// Behavior Tree framework for A1 Behavior trees assignment.
// CS 131 - Artificial Intelligence
//
// version 2.0.0 - copyright (c) 2023 Santini Fabrizio. All rights reserved.
//


#include <cstdlib>
#include <string>

#include "bt_library/package.hpp"

#include "bt/globals.hpp"
#include "bt/behavior_tree.hpp"

void prompt_user(btl::Blackboard *currentBlackboard);
void set_dust_sensor(int num_cycles, btl::Blackboard *currentBlackboard);

int main()
{
    btl::Blackboard currentBlackboard;

    currentBlackboard.setInEnvironment(BATTERY_LEVEL, 31);
    currentBlackboard.setInEnvironment(SPOT_CLEANING, false);
    currentBlackboard.setInEnvironment(GENERAL_CLEANING, true);
    currentBlackboard.setInEnvironment(DUSTY_SPOT_SENSOR, false);
    currentBlackboard.setInEnvironment(HOME_PATH, "");

    //variables for tracking number of evaluations and evaluation results
    auto done = false;
    int num_cycles = 0;
    auto result = btl::result_e::UNDEFINED;

    while (!done) {

        //reduce battery level by 1
        int battery = currentBlackboard.getInEnvironment(BATTERY_LEVEL, -1);
        battery--;
        currentBlackboard.setInEnvironment(BATTERY_LEVEL, battery);
 
        //if no process is currently running, get an input command from the user
        //and randomly set dust sensor
        if (result != btl::result_e::RUNNING){
            prompt_user(&currentBlackboard);
            set_dust_sensor(num_cycles, &currentBlackboard);
        }

        //check if the process has been ordered to terminate and 
        //either evaluate the tree or end the program
        if (currentBlackboard.getInEnvironment("Done", false)){
            done = true;
        } else {
            //evaluate the tree
            result = TREE_ROOT->run(currentBlackboard);
        }     

        num_cycles++;

    }
}

/**
 * prompt_user: gets a cleaning command from the user and puts it in blackboard
 * 
 * @param currentBlackboard a pointer to the blackboard in use
 */

void prompt_user(btl::Blackboard *currentBlackboard){
    
    bool success = false;
    std::string input_string;
    int int_input;

    while (!success){
        std::cout << "Enter 1 for spot cleaning, 2 for general cleaning, ";
        std::cout << "or 3 to terminate: ";
        std::cin >> input_string;
        
        //attempt to turn the input into an int
        try{
            int_input = stoi(input_string);
        } catch(std::invalid_argument){
            int_input = 0;
        }   

        if (int_input == 1){
            currentBlackboard->setInEnvironment(SPOT_CLEANING, true);
            success = true;
        } else if (int_input == 2){
            currentBlackboard->setInEnvironment(GENERAL_CLEANING, true);
            success = true;
        } else if (int_input == 3) {
            currentBlackboard->setInEnvironment("Done", true);
            success = true;
        } else {
            std::cout << "Invalid input, please try again\n";
        }
    }
}

/**
 * set_dust_sensor: sets the value of the dusty spot sensor
 * 
 * @param num_cycles the number of times the tree has been evaluated
 * @param currentBlackboard a pointer to the blackboard in use
 */
void set_dust_sensor(int num_cycles, btl::Blackboard *currentBlackboard){

    //randomly set the dusty spot sensor, making it more likely
    //to return false as time goes on (as the robot cleans more)
    if ((rand() % (5 + num_cycles)) <= 10){
        currentBlackboard->setInEnvironment(DUSTY_SPOT_SENSOR, true);
    } else {
        currentBlackboard->setInEnvironment(DUSTY_SPOT_SENSOR, false);
    }
}
