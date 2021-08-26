/*
 * KEYPAD.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ENG:RAGAB
 */
#define FCY 4000000UL
#include "KEYPAD.h"
#include <p24FJ256GA705.h>

unsigned char KEYPAD_pressed(){
	unsigned char col , row;
	unsigned char keypad_matrix[ROW][COL]=
		   {{'1','2','3' , 'A'},
			{'4','5','6' , 'B' },
			{'7','8','9' , 'C'},
			{'*','0','#' , 'D'}};
while(1){
	for(col =0 ; col<COL ; col++)
		{
			KEYPAD_DDR =~(0b00010000<<col) ;
			KEYPAD_CTRL = 0x00;
			__delay_us(30);
			for(row=0 ;row <ROW ; row++){
				if(!(KEYPAD_PIN &(1<<row))){
					while(!(KEYPAD_PIN &(1<<row)));//polling to print one key
					return keypad_matrix[row][col];
				}

			}
		}

}



}


