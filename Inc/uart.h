#ifndef UART_H_
#define UART_H_

#include "hardwareinit.h"
#include "string.h"
#include "stdio.h"

/*	my Function Prototype	*/
void myUART_Print(char *pData);
void myUART_Println(char *pData);
void myUART_PrintNum(uint16_t number);


#endif /* UART_H_ */
