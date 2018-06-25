/*
 * GPIO.h
 *
 *  Created on: Jun 25, 2018
 *      Author: Mark
 */

#ifndef GPIO_H_
#define GPIO_H_

//------------------INCLUDE FILES-----------------------------------
#include "types.h"
#include "HW_GPIO.h"
#include "HW_types.h"
//------------------------------------------------------------------
//------------------MACROS&TYPEDEFS---------------------------------
#ifndef TRUE
#define TRUE 1
#endif

#ifndef FLASE
#define FALSE 0
#endif

#ifndef HIGH
#define HIGH 1
#endif

#ifndef LOW
#define LOW 0
#endif

#define MAX_PORT_PINS   8
#define GPIO_DATA_HW_MASK     0x3FC

//------------------------------------------------------------------
//------------------STRUCTURES&ENUMS -------------------------------
//enumerate the number of errors in the gpio module
typedef enum {
    PASS=1, INCORRECT_PORT, INCORRECT_PIN_NUM, INCORRECT_VALUE, DIRECTION_ERROR
}gGPIOError_t;

//enumerate the types of resistor in the gpio module
typedef enum{
    PULL_UP=1, PULL_DOWN,OPEN_DRAIN
}gResType_t;
//enumerate the types of current driven in the gpio module
typedef enum{
    CURRENT_2MA=1, CURRENT_4MA, CURRENT_8MA
}gcurrentVal_t;
//enumerate the number of interrupt sensetivity in the interrupt module
typedef enum{
    FALLING_EDGE=1, RISING_EDGE, BOTH_EDGES, HIGH_LEVEL, LOW_LEVEL
}gInterrSenseControl_t;
//structure to hold pad cobfiguration
typedef struct{
    gResType_t      restype;
    gcurrentVal_t   currentval;

}gConfigPad_t;




#endif /* GPIO_H_ */
