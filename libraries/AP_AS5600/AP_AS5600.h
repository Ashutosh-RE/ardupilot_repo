/**
 * Angle of attack sensor using magnetic encoder
 * @author Ashutosh
**/


#pragma once

#include <AP_HAL/AP_HAL.h>
#include <AP_HAL/I2CDevice.h>
//#include <AP_HAL/Semaphores.h>
#include <utility>

#define AS5600_adds 0x36
#define AS5600_Raw_Data_Reg 0xC
#define AS5600_Data_Reg 0xE

class AP_AS5600
{
private:
    uint16_t AOA;
    uint8_t data[2];
    bool new_data;

    AP_HAL::OwnPtr<AP_HAL::Device> dev;

    //HAL_Semaphore sem;

    // to deg 360/4096 =0.087890625
public:
    AP_AS5600();
    void init();
    void update();
    void read_data();

};

