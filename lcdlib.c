/*
 * lcdlib.c
 *
 *  Created on: ٠٤‏/٠٤‏/٢٠١٨
 *      Author: ENG:RAGAB
 */
#define FCY 4000000UL
#include "lcdlib.h"


void LCD_init(){
	i2c_init();
	i2c_start();
	i2c_write(ADDRESS_OF_LCD);

	//LCD_CTRL_PORT_DIR |=(1<<RS) |(1<<RW) |(1<<E);
	//LCD_DATA_PORT_DIR = 0XFF;
	LCD_command(FOUR_BITS_DATA_MODE);
	LCD_command(0x28);
	LCD_command(CURSOR_OFF);
	LCD_command(0x01);

}



void LCD_command(unsigned char command){
	//RS=0,RW=0
	i2c_write(0x00);
	__delay_ms(1);
	i2c_write(1<<E);
	__delay_ms(1);
	i2c_write((1<<E)|((command) & 0xF0));
	__delay_ms(1);
	i2c_write((~(1<<E))&((command) & 0xF0));
	__delay_ms(1);
	i2c_write((1<<E));
	__delay_ms(1);
	i2c_write((1<<E)|((command << 4) & 0xF0));
	__delay_ms(1);
	i2c_write((~(1<<E))&((command << 4) & 0xF0));
	__delay_ms(1);

}
void LCD_Data(unsigned char data){
	//RS=1,RW=0
	i2c_write((1<<RS));
	__delay_ms(1);
	i2c_write((1<<E)|(1<<RS));
	__delay_ms(1);
	i2c_write(((1<<E)|((data) & 0xF0))|(1<<RS));
	__delay_ms(1);
	i2c_write(((~(1<<E))&((data) & 0xF0))|(1<<RS));
	__delay_ms(1);
	i2c_write((1<<E)|(1<<RS));
	__delay_ms(1);
	i2c_write(((1<<E)|((data << 4) & 0xF0))|(1<<RS));
	__delay_ms(1);
	i2c_write(((~(1<<E))&((data << 4) & 0xF0))|(1<<RS));
	__delay_ms(1);

}
void LCD_goToRowCol(unsigned char row ,unsigned char col ){
	unsigned char fristCharAddr[]={0x80 , 0XC0, 0X94 ,0XD4};
	LCD_command(fristCharAddr[row-1] + col-1);
	__delay_ms(1);

}
void LCD_displayCharacter(unsigned char Byte ){
	LCD_Data(Byte);
}

void LCD_displayString( unsigned char *str ){
	do{
		LCD_Data(*str++);
	}while(*str);
}
void LCD_displayStringRowCol(unsigned char row , unsigned char col , unsigned char *str ){
	LCD_goToRowCol(row , col);
	LCD_displayString(str);
}
void LCD_clearScreen(void){
	LCD_command(0x01); //clear display
}
//void LCD_intToString(int data){
//	unsigned char buff[16]; /* String to hold the ascii result */
//	// itoa(data,buff,10); /* 10 for decimal */
//	 LCD_displayString(buff);
//}


