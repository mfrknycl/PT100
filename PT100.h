#ifndef __PT100_H__
#define __PT100_H__

/* Includes ---------------------------------------------------- */
#include "stm32f0xx_hal.h"
/* Private defines ---------------------------------------------------- */

/* Typedef Decleration ---------------------------------------------------- */
typedef struct{

	float x; 
	float y;
} ptcStruct_t;


static const ptcStruct_t ptcTemp[] = {


	

};


/* Fucntion Decleration ---------------------------------------------------- */
float findTemp(const ptcStruct_t *table, float adcVal, int size);


#endif //__PT100_H__
