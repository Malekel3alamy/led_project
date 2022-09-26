/* 
 * File:   hal_gpio.h
 * Author: Mahmood_Adel
 *
 * Created on September 11, 2022, 7:16 AM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/*   section : includes */
#include "../proc/pic18f4620.h"
#include "../mcal_std_types.h"
#include"../device_config.h"
#include"hal_gpio_cfg.h"
/*   section : macro  declarations */
#define BIT_MASK (uint8)1
#define PORT_PIN_MAX_NUMBER  8
#define port_max_number      5

#define PORTC_MASK 0XFF

#define PORT_PIN_CONFIGURATIONS  CONFIG_ENABLE
#define PORT_CONFIGURATIONS  CONFIG_ENABLE



/*   section : macro function  declarations */
#define HWREG8(_X)                       (*((volatile uint8 *(_x)))

#define SET_BIT(REG, BIT_POSN)            (REG |= (BIT_MASK << BIT_POSN)) 
#define CLEAR_BIT(REG, BIT_POSN)          (REG &= ~(BIT_MASK << BIT_POSN)) 
#define TOGGLE_BIT(REG, BIT_POSN)         (REG ^= (BIT_MASK << BIT_POSN)) 
#define READ_BIT(REG, BIT_POSN)           ((REG >> BIT_POSN) &BIT_MASK  ) 

/*   section : datatype  declarations */
typedef enum{
    LOW,
    HIGH
}logic_t;

typedef enum{
    OUTPUT,
    INPUT
}direction_t;


typedef enum {
    PIN0 = 0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}pin_index_t;

typedef enum {
    PARTA_INDEX = 0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
}port_index_t;

typedef struct {
    uint8 port         :3 ;  /* @ref  port_index_t*/
    uint8 pin          :3 ;  /* @ref  pin_index_t*/
    uint8 direction    :1;   /* @ref  direction_t*/
    uint8 logic        :1;   /* @ref  logic_t*/
}pin_config_t;

/*   section : function  declarations */
STD_RETURN_TYPE  gpio_pin_dirction_initialize   (const pin_config_t *_pin_config   );
STD_RETURN_TYPE  gpio_pin_direction_status      (const pin_config_t *_pin_config  , direction_t ic_status);
STD_RETURN_TYPE  gpio_pin_write_logic           (const pin_config_t *_pin_config , logic_t logic );
STD_RETURN_TYPE  gpio_pin_read_logic            (const pin_config_t *_pin_config , logic_t * logic);
STD_RETURN_TYPE  gpio_pin_toggle_logic          (const pin_config_t *_pin_config  );
STD_RETURN_TYPE  gpio_pin_initialize            (const pin_config_t *_pin_config   );


STD_RETURN_TYPE  gpio_port_diection_initialize  (port_index_t port , uint8 direction);
STD_RETURN_TYPE  gpio_port_get_direction_status (port_index_t port , uint8 * direction_status  );
STD_RETURN_TYPE  gpio_port_write_logic          (port_index_t port , uint8 logic);
STD_RETURN_TYPE  gpio_port_read_logic           (port_index_t port , uint8 *logic);
STD_RETURN_TYPE  gpio_port_toggle_logic         (port_index_t port );

#endif	/* HAL_GPIO_H */

