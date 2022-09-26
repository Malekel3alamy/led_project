/* 
 * File:   ecu_led.h
 * Author: Mahmood_Adel
 *
 * Created on September 11, 2022, 8:18 AM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H
/*   section : includes */
#include"../../MCAL_LAYER/GPIO/hal_gpio.h"
#include"ecu_led_cfg.h"


/*   section : macro  declarations */

/*   section : macro function  declarations */


/*   section : datatype  declarations */

typedef enum{
    LED_OFF,
    LED_ON
}led_status_t;

typedef struct {
    uint8 port_name  : 4;
    uint8 pin        : 3;
    uint8 led_status : 1;
}led_t;
/*   section : function  declarations */

STD_RETURN_TYPE  led_initialize         (const led_t *led );
STD_RETURN_TYPE  led_turn_on            (const led_t *led );
STD_RETURN_TYPE  led_turn_off           (const led_t *led );
STD_RETURN_TYPE  led_turn_toggle        (const led_t *led );

#endif	/* ECU_LED_H */

