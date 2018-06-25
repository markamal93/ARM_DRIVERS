/*
 * GPIO.c
 *
 *  Created on: Jun 25, 2018
 *      Author: Mark
 */
#include "GPIO.h"
//----------------------------------------------------------------------------------------------------------------
gGPIOError_t SetPinDir(uint32 base,uint8 pin,uint32 dir){
    gGPIOError_t state = PASS;
    if (base == BASE_A || base == BASE_B ||base == BASE_C||
        base == BASE_D || base == BASE_E ||base == BASE_F){
        if (pin > MAX_PORT_PINS){
            state = INCORRECT_PIN_NUM;
        }else{if (dir==HIGH){
            HW_WRITE_BIT(base+GPIO_DIRECTION_OFFSET, pin, dir);
        }else{
            if (dir==LOW){

            HW_WRITE_BIT(base+GPIO_DIRECTION_OFFSET, pin, dir);
        }else {
            state = DIRECTION_ERROR;
        }
        }
      }
    }else{
        state= INCORRECT_PORT;
    }
 return state;
}
//------------------------------------------------------------------------------------------------------------
gGPIOError_t WritePin(uint32 base,uint8 pin,uint8 val){
    gGPIOError_t state = PASS;
       if (base == BASE_A || base == BASE_B ||base == BASE_C||
           base == BASE_D || base == BASE_E ||base == BASE_F){
           if (pin > MAX_PORT_PINS){
               state = INCORRECT_PIN_NUM;
           }else{if (val==HIGH){
               HW_WRITE_BIT(base+GPIO_DATA_OFFSET+GPIO_DATA_HW_MASK, pin, val);
           }else{
               if (val==LOW){
               HW_WRITE_BIT(base+GPIO_DATA_OFFSET+GPIO_DATA_HW_MASK, pin, val);
           }else {
               state = DIRECTION_ERROR;
           }
           }
         }
       }else{
           state= INCORRECT_PORT;
       }
    return state;
   }
//----------------------------------------------------------------------------------------------------------------
gGPIOError_t ReadPin(uint32 base, uint8 pin, uint8 *data){
    gGPIOError_t state = PASS;
           if (base == BASE_A || base == BASE_B ||base == BASE_C||
               base == BASE_D || base == BASE_E ||base == BASE_F){
               if (pin > MAX_PORT_PINS){
                  state = INCORRECT_PIN_NUM;
               }else{
                   *data=HW_READ_BIT(base+GPIO_DATA_OFFSET+GPIO_DATA_HW_MASK , pin);
               }
               }else{
                   state = INCORRECT_PORT;
               }
               return state;
 }
//------------------------------------------------------------------------------------------------------------------

gGPIOError_t SetPortDir(uint32 base,uint32 dir){
    gGPIOError_t state = PASS;
       if (base == BASE_A || base == BASE_B ||base == BASE_C||
           base == BASE_D || base == BASE_E ||base == BASE_F){
           HW_WRITE_REG_32BIT(base+GPIO_DIRECTION_OFFSET, dir);
           }else {
               state = DIRECTION_ERROR;
           }
    return state;
   }
//-------------------------------------------------------------------------------------------------------------------





