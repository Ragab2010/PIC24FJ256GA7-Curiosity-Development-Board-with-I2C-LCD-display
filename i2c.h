/* 
 * File:   i2c.h
 * Author: ENG.RAGAB
 *
 * Created on 04 ?????, 2018, 11:27 ?
 */

#ifndef I2C_H
#define	I2C_H
#include "PLATFORM_CONFIGRATION.h"
void i2c_init();
void i2c_start();
void i2c_rstart();
void i2c_stop();
void i2c_write(unsigned byte);
unsigned char i2c_read(unsigned byte);

#endif	/* I2C_H */

