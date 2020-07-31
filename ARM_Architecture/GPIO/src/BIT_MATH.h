#ifndef MATH_H
#define MATH_H

#define SET_BIT(VAR,BITNUM) (VAR |=((uint32_t)(1<<BITNUM)))
#define CLR_BIT(VAR,BITNUM) (VAR &=((uint32_t)(~(1<<BITNUM))))
#define TOG_BIT(VAR,BITNUM) (VAR^=((uint32_t)(1<<BITNUM)))
#define GET_BIT(VAR,BITNUM) ((VAR & ((uint32_t)(1<<BITNUM)))>>BITNUM)

#define BIT_CONC(B7,B6,B5,B4,B3,B2,B1,B0) CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0)
#define CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0) 0b##B7##B6##B5##B4##B3##B2##B1##B0
#endif
