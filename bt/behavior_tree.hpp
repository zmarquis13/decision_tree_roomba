//
// Behavior Tree framework for A1 Behavior trees assignment.
// CS 131 - Artificial Intelligence
//
// version 2.0.0 - copyright (c) 2023 Santini Fabrizio. All rights reserved.
// modified by Zeno Marquis 2/12/2024
//
#pragma once


#include "bt_library/package.hpp"

#include "conditions/battery_less_than_30.hpp"
#include "conditions/general_cleaning.hpp"
#include "conditions/spot_cleaning.hpp"
#include "conditions/dusty_spot.hpp"
#include "tasks/find_home.hpp"
#include "tasks/go_home.hpp"
#include "tasks/always_fail.hpp"
#include "tasks/dock.hpp"
#include "tasks/do_nothing.hpp"
#include "tasks/clean_spot.hpp"
#include "tasks/clean_floor.hpp"
#include "tasks/done_spot.hpp"
#include "tasks/done_general.hpp"
#include "composites/selection.hpp"
#include "composites/sequence.hpp"
#include "composites/priority.hpp"
#include "decorators/until_fails.hpp"



// Instantiation of the behavior tree (structure explained below):
const auto TREE_ROOT = Priority::make({
    Sequence::make({
        new BatteryLessThan30(), 
        new FindHome(), 
        new GoHome(), 
        new Dock()}), 
    Selection::make({
        Sequence::make({
            new SpotCleaning(),
            btl::Timer::make(20, new CleanSpot()),
            new DoneSpot()
        }),
        Sequence::make({
            new GeneralCleaning(),
            Sequence::make({
                Priority::make({
                    Sequence::make({
                        new DustySpot(),
                        btl::Timer::make(35, new CleanSpot()),
                        new AlwaysFail()
                    }),
                    btl::UntilFails::make(new CleanFloor())
                }),
                new DoneGeneral()
            })
        })
    }), 
    new DoNothing()
});

/*
Structure of the tree:
Root: priority node 

Root priority: 
1. Battery Sequence
2. Cleaning Selection
3. Do nothing

Battery Sequence: 
1. Check whether battery is less than 30 (condition)
2. Find home task
3. Go home task
4. Dock task

Cleaning Selection: 
1. Spot Cleaning Sequence
2. First Intermediate Sequence

Spot Cleaning Sequence:
1. Spot cleaning condition
2. 20s timer decorator on clean spot task
3. Done spot task

First Intermediate Sequence:
1. General cleaning condition
2. Second Intermediate Sequence

Second Intermediate Sequence:
1. Spot Priority
2. Done general task

Spot Priority:
1. Spot Sequence
2. Until fails decorator on clean floor task

Spot Sequence:
1. Dusty spot condition 
2. 35s timer decorator on clean spot task
3. Always fail task
*/

