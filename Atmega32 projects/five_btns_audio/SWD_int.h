

#ifndef SWD_INT_H_
#define SWD_INT_H_
#include"SWD_config.h"

/*To indicate three different states of button Pushed or released
 * or if the user entered wrong swithc number it will return error state*/
#define SWD_u8PUSHED   2
#define SWD_u8RELEASED 1
#define SWD_u8ERROR    0
/*This Function used to return the */
/*switvh state pushed or released*/
u8 SWD_u8GetSwitchState(u8 u8SwIdxCpy);

#endif /* SWD_INT_H_ */
