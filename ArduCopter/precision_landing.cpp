//
// functions to support precision landing
//

#include "Copter.h"
#include "Plane.h"

#if PRECISION_LANDING == ENABLED

void Copter::init_precland()
{
    copter.precland.init(400);
}

void Plane::init_precland(){
    plane.precland.init(400);
}

void Plane::update_precland(){
    int32_t height_above_ground_cm = current_loc.alt;

    // use range finder altitude if it is valid, otherwise use home alt
    if (rangefinder_alt_ok()) {
        height_above_ground_cm = rangefinder_state.alt_cm;
    }

    precland.update(height_above_ground_cm, rangefinder_alt_ok());
}

void Copter::update_precland()
{
    int32_t height_above_ground_cm = current_loc.alt;

    // use range finder altitude if it is valid, otherwise use home alt
    if (rangefinder_alt_ok()) {
        height_above_ground_cm = rangefinder_state.alt_cm;
    }

    precland.update(height_above_ground_cm, rangefinder_alt_ok());
}

#endif
