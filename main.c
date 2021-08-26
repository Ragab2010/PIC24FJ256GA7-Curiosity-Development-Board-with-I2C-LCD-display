/*
 * File:   main.c
 * Author: ENG:RAGAB
 *
 * Created on 05 ?????, 2018, 05:11 ?
 */

//PLEASE SEE THE PLATFORM_CONFIGRATION.H FRIST 

#include "pc.h"

int main(void) {

    
    LCD_init();
    //LCD_goToRowCol(1,1);
    LCD_displayString("welcome");
        
    while(1){
        LCD_displayCharacter(KEYPAD_pressed());
    }
    
    while(1)
    return 0;
}
