/*
 * 
*/

#include <stdio.h>
#include "AP_AS5600.h"

extern const AP_HAL::HAL& hal;

AP_AS5600::AP_AS5600(){}

void AP_AS5600::init()
{
    //With_Semaphore(dev->get_semaphore());
    WITH_SEMAPHORE(dev->get_semaphore());

    dev= std::move(hal.i2c_mgr->get_device(0,AS5600_adds));
    
    if(!dev){
        return;
    }
    printf("AOA sensor initialized\n");

    dev->register_periodic_callback(100000, FUNCTOR_BIND_MEMBER(&AP_AS5600::read_data,void));

}

void AP_AS5600::read_data(){
    if(!dev->read(data, sizeof(data))){
        new_data =false;
    }
    else{
        AOA = data[1] <<8| data[0];
        new_data =true;
    }
}

void AP_AS5600::update(){
    if(new_data){
        hal.console->printf("Angle of Attack: %f degrees",AOA*0.087890625);
    }
}