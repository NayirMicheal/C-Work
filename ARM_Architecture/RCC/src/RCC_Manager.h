/*
 * RCC_Manager.h
 *
 *  Created on: 23 Apr 2018
 *      Author: Nayir
 */

#ifndef RCC_MANAGER_H_
#define RCC_MANAGER_H_

#include "RCC_Manager_cfg.h"

return_status_t RCC_Manager_clockInit(void);
return_status_t RCC_Manager_switchToClock(uint32_t MHZ);

#endif /* RCC_MANAGER_H_ */
