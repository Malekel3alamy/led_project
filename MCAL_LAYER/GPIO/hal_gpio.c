#include "hal_gpio.h"

/*  Reference to the data direction control registers  */
volatile uint8 *tris_register[] = {&TRISA ,&TRISB ,&TRISC ,&TRISD ,&TRISE };
/*  Reference to the data latch register ( read and write to data latch )  */
volatile uint8 *lat_register [] = {&LATA ,&LATB ,&LATC ,&LATD ,&LATE };
/*  Reference to the port status register  */
volatile uint8 *port_register[] = {&PORTA ,&PORTB ,&PORTC ,&PORTD ,&PORTE };

/**
 * @brief initialize the direction of a specific pin @ref direction_t
 * @param _pin_config  pointer to the configurations @ref pin_config_t
 * @return  status of the function
 *            (E_NOT_OK)  : The function has issue to perform this action 
 *            (E_OK)      : The function done successfully
 */
#if  PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
STD_RETURN_TYPE  gpio_pin_dirction_initialize   (const pin_config_t *_pin_config   ){
    STD_RETURN_TYPE ret = E_OK;
    if( _pin_config == NULL || _pin_config->pin > PORT_PIN_MAX_NUMBER-1 ){
        ret  = E_NOT_OK ;
    }
    else{
        switch(_pin_config->direction){
        case OUTPUT :
            CLEAR_BIT(*tris_register[_pin_config->port] ,_pin_config->pin);
            break;
        case INPUT :
            break;
        default:
            ;
    }
    }
    
    return ret ;
}
#endif

/**
 * 
 * @param _pin_config  pointer to the configurations @ref pin_config_t
 * @param direction_status
 * @return  status of the function
 *            (E_NOT_OK)  : The function has issue to perform this action 
 *            (E_OK)      : The function done successfully 
 */
#if  PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
STD_RETURN_TYPE  gpio_pin_get_direction_status      (const pin_config_t *_pin_config  , direction_t *direction_status){
     STD_RETURN_TYPE ret = E_OK;
if( _pin_config == NULL  ||  direction_status == NULL  || _pin_config->pin > PORT_PIN_MAX_NUMBER-1){
        ret  = E_NOT_OK ;
    }
    else{
    *direction_status = READ_BIT(*tris_register[_pin_config->port] ,_pin_config->pin);
        
    }
             return ret ;

}
#endif
/**
 * 
 * @param _pin_config  pointer to the configurations @ref pin_config_t
 * @return   status of the function
 *            (E_NOT_OK)  : The function has issue to perform this action 
 *            (E_OK)      : The function done successfully
 */
#if  PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
STD_RETURN_TYPE  gpio_pin_initialize      (const pin_config_t *_pin_config ){
    STD_RETURN_TYPE   ret  = E_OK ;
    if( NULL == _pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER-1 ){
          ret  = E_NOT_OK ;
    }
    else{
        ret = gpio_pin_dirction_initialize(_pin_config);
        ret = gpio_pin_write_logic(_pin_config , _pin_config->logic);
    }
    return ret ;
}

#endif
/**
 * 
 * @param _pin_config  pointer to the configurations @ref pin_config_t
 * @param logic
 * @return   status of the function
 *            (E_NOT_OK)  : The function has issue to perform this action 
 *            (E_OK)      : The function done successfully
 */
#if  PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
STD_RETURN_TYPE  gpio_pin_write_logic (const pin_config_t * _pin_config , logic_t logic ){
        STD_RETURN_TYPE ret = E_OK;
        if( _pin_config == NULL || _pin_config->pin > PORT_PIN_MAX_NUMBER-1){
        ret  = E_NOT_OK ;
    }
    else{
            switch(logic){
                case HIGH :
                    SET_BIT(*lat_register[_pin_config->port],_pin_config->pin);
                    break;
                case LOW :
                    CLEAR_BIT(*lat_register[_pin_config->port],_pin_config->pin);
                    break;
                default: ret = E_NOT_OK ;
            }
        
    }
        return ret ;

}
#endif

/**
 * 
 * @param _pin_config  pointer to the configurations @ref pin_config_t
 * @param logic
 * @return   status of the function
 *            (E_NOT_OK)  : The function has issue to perform this action 
 *            (E_OK)      : The function done successfully
 */
#if  PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
STD_RETURN_TYPE  gpio_pin_read_logic            (const pin_config_t *_pin_config , logic_t *logic){
        STD_RETURN_TYPE ret = E_OK;
        if( _pin_config == NULL || logic == NULL || _pin_config->pin > PORT_PIN_MAX_NUMBER-1 ){
        ret  = E_NOT_OK ;
    }
    else{
        *logic = READ_BIT(*port_register[_pin_config->port],_pin_config->pin);
    }
        return ret ;

}
#endif

/**
 * 
 * @param _pin_config  pointer to the configurations @ref pin_config_t
 * @return   status of the function
 *            (E_NOT_OK)  : The function has issue to perform this action 
 *            (E_OK)      : The function done successfully
 */
#if  PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
STD_RETURN_TYPE  gpio_pin_toggle_logic          (const pin_config_t * _pin_config  ){
        STD_RETURN_TYPE ret = E_OK;
if( _pin_config == NULL || _pin_config->pin > PORT_PIN_MAX_NUMBER-1){
        ret  = E_NOT_OK ;
    }
    else{
    TOGGLE_BIT(*lat_register[_pin_config->port],_pin_config->pin);
        
    }
                return ret ;

}
#endif

/**
 * 
 * @param port
 * @param direction
 * @return   status of the function
 *            (E_NOT_OK)  : The function has issue to perform this action 
 *            (E_OK)      : The function done successfully
 */
#if PORT_CONFIGURATIONS == CONFIG_ENABLE
STD_RETURN_TYPE  gpio_port_diection_initialize  (port_index_t port , uint8 direction){
        STD_RETURN_TYPE ret = E_OK;
        if(port > port_max_number-1){
            ret= E_NOT_OK;
        }
        else{
            *tris_register[port] = direction;
        }

    
            return ret ;

}
#endif

/**
 * 
 * @param port
 * @param direction_status
 * @return   status of the function
 *            (E_NOT_OK)  : The function has issue to perform this action 
 *            (E_OK)      : The function done successfully
 */
#if PORT_CONFIGURATIONS == CONFIG_ENABLE
STD_RETURN_TYPE  gpio_port_get_direction_status (port_index_t port , uint8 * direction_status  ){
        STD_RETURN_TYPE ret = E_OK;
if( direction_status == NULL && port > port_max_number-1 ){
        ret  = E_NOT_OK ;
    }
    else{
        *direction_status = *tris_register[port] ;
    }
                return ret ;

}
#endif

/**
 * 
 * @param port
 * @param logic
 * @return   status of the function
 *            (E_NOT_OK)  : The function has issue to perform this action 
 *            (E_OK)      : The function done successfully
 */
#if PORT_CONFIGURATIONS == CONFIG_ENABLE
STD_RETURN_TYPE  gpio_port_write_logic          (port_index_t port , uint8 logic){
        STD_RETURN_TYPE ret = E_OK;
        if(port > port_max_number-1){
            ret= E_NOT_OK;
        }
        else{
            *lat_register[port] = logic;
        }

        return ret ;

}
#endif

/**
 * 
 * @param port
 * @param logic
 * @return   status of the function
 *            (E_NOT_OK)  : The function has issue to perform this action 
 *            (E_OK)      : The function done successfully
 */
#if PORT_CONFIGURATIONS == CONFIG_ENABLE
STD_RETURN_TYPE  gpio_port_read_logic           (port_index_t port , uint8 *logic){
        STD_RETURN_TYPE ret = E_OK;
        if( logic == NULL && port > port_max_number-1 ){
        ret  = E_NOT_OK ;
    }
    else{
        *logic = *lat_register[port];
    }
        return ret ;

}
#endif

/**
 * 
 * @param port
 * @return   status of the function
 *            (E_NOT_OK)  : The function has issue to perform this action 
 *            (E_OK)      : The function done successfully
 */
#if PORT_CONFIGURATIONS == CONFIG_ENABLE
STD_RETURN_TYPE  gpio_port_toggle_logic         (port_index_t port ){
        STD_RETURN_TYPE ret = E_OK;
        if(  port > port_max_number-1 ){
        ret  = E_NOT_OK ;
    }
    else{
         *lat_register[port] ^=  PORTC_MASK ;
    }
        return ret ;
}
#endif
