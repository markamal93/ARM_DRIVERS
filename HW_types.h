/*
 * HW_types.h
 *
 *  Created on: Jun 25, 2018
 *      Author: Mark
 */

#ifndef HW_TYPES_H_
#define HW_TYPES_H_

#include "types.h"

//AUTOSAR--->MCAL

#define HIGH 1
#define LOW  0


//--------------------------------MACROS------------------------------------------------------------------------------------------
//brief macro to read 32 bit register
#define HW_READ_REG_32BIT(address) (*(volatile uint32*)(address))
//brief macro to wirte 32 bit register
#define HW_WRITE_REG_32BIT(address,value) ((*(volatile uint32*)(address)) = value )
//set bit in 32 bit register
#define HW_SET_BIT(addr,bit) (HW_READ_REG_32BIT(addr) |=(1<<bit))
//reset bit in 32 bit register
#define HW_RESET_BIT(addr,bit) (HW_READ_REG_32BIT(addr) &=~(1<<bit))

//-------------------------FUNCTIONS PROTOTYPES----------------------------------------------------------------------------
//function to write bit in 32 bit register
static inline void HW_WRITE_BIT(uint32 reg, uint8 pin , uint8 val);
//function to Read bit in 32 bit register
static inline uint8 HW_READ_BIT(uint32 reg,uint8 pin);
//------------------------FUNCTIONS DEFINITIONS---------------------------------------------------------------------------

static inline void HW_WRITE_BIT(uint32 reg, uint8 pin , uint8 val){
    if (val==HIGH)
    {
        HW_READ_REG_32BIT(reg) |=(1<<pin);
    }else if (val==LOW){
        HW_READ_REG_32BIT(reg) &=~(1<<pin);
        }
}
static inline uint8 HW_READ_BIT(uint32 reg,uint8 pin){
    return (HW_READ_REG_32BIT(reg)&(1<<pin)>>pin);
}


#endif /* HW_TYPES_H_ */
