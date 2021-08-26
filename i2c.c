/* 
 * File:   i2c.c
 * Author: ENG.RAGAB
 *
 * Created on 04 ?????, 2018, 11:31 ?
 */

#include <p24FJ256GA705.h>
#include "i2c.h"

void i2c_init(){
    
    I2C1BRG=CLOCK_I2C;
    I2C1CONL =(1<<15);
}
void i2c_start(){
    I2C1CONL |=(1<<0);
    while(I2C1STAT & (1<<14));//still on progress
  
}
void i2c_rstart(){
    I2C1CONL |=(1<<1);
    while(I2C1STAT & (1<<14));//still on progress
}

void i2c_stop(){
    I2C1CONL |=(1<<2);
    // I2C1CONbits.PEN=1;
    while(I2C1STAT & (1<<14));//still on progress
}

void i2c_write(unsigned byte){
   
    while(I2C1STAT & (1<<14));//still on progress
    I2C1TRN =byte;
    while((I2C1STAT & (1<<0)));

}

unsigned char i2c_read(unsigned byte){ //if you want receive only on byte make byte by 1 i2c_read(1)
    
    while(!(I2C1STAT & (1<<1)));
    if(byte){
        I2C1CONL |=(1<<4);
    }
    return I2C1RCV;
    
}
