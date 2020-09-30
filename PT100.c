#include "PT100.h"

/*
 *
 *		          Linear interpolation equation 
 *
 *			        		y0(x1-x) + y1(x - x0)		
 *			        y = ----------------------
 *			        					 x1-x0
 *
 *
 *			y0 = ptcTemp[i].y      x0 = ptcTemp[i].x
 *			y1 = ptcTemp[i+1].y    x1 = ptcTemp[i+1].x
 *			
 *	
 * 
 */



/**
	* @brief Find the range of temperature from lookup table.
						This function uses liner interpolation method.
	* @param *table is pointer to ptcStruct_t
	* @param adcVal is adc value from temperature sensor
	* @param size is the size of the *table
	* @retval it returns the temperature after it's calculated
	*/
float findTemp(const ptcStruct_t *table, float adcVal, int size){
		
	float y_ans;
	
	for(int i = 0; i < size; i++){
		
		if(adcVal > ptcTemp[0].x){break;}	
		
		if(ptcTemp[i].x <= adcVal && adcVal >= ptcTemp[i+1].x){
			y_ans = (ptcTemp[i].y*(ptcTemp[i+1].x-adcVal)+ptcTemp[i+1].y*(adcVal-ptcTemp[i].x))/(ptcTemp[i+1].x-ptcTemp[i].x);
			return y_ans;
		}
	}
	return -1;
}





