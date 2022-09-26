#include "../LED/ecu_led.h"



/**
 * @brief       initialize the assigned pin to be OUTPUT and turn the led off .
 * @param led : pointer to the led module configurations
 * @return      status of the function
 *              (E_NOT_OK)  : The function has issue to perform this action 
 *              (E_OK)      : The function done successfully
 */
STD_RETURN_TYPE  led_initialize         (const led_t *led ){
        STD_RETURN_TYPE ret = E_OK;
        if(NULL == led){
            ret  = E_NOT_OK ;
        }
        else{
            pin_config_t pin_obj = {
                .port = led->port_name,
                .pin =  led->pin ,
                .logic = led->led_status
            };
            gpio_pin_initialize(&pin_obj);
        }
        return ret ;
}
/**
 * @brief      turn the led on 
 * @param led: pointer to the led module configurations
 * @return     status of the function
 *            (E_NOT_OK)  : The function has issue to perform this action 
 *            (E_OK)      : The function done successfully
 */
STD_RETURN_TYPE  led_turn_on            (const led_t *led ){
    STD_RETURN_TYPE ret = E_OK;
        if(NULL == led){
            ret  = E_NOT_OK ;
        }
        else{
            pin_config_t pin_obj = {
                .port = led->port_name,
                .pin =  led->pin ,
                .logic = led->led_status,
                .direction = OUTPUT,
                
            };
            gpio_pin_write_logic(&pin_obj , HIGH);
        }
        return ret ;
}
/**
 * @brief
 * @param led : pointer to the led module configurations
 * @return      status of the function
 *             (E_NOT_OK)  : The function has issue to perform this action 
 *             (E_OK)      : The function done successfully
 */
STD_RETURN_TYPE  led_turn_off           (const led_t *led ){
    STD_RETURN_TYPE ret = E_OK;
        if(NULL == led){
            ret  = E_NOT_OK ;
        }
        else{
            pin_config_t pin_obj = {
                .port = led->port_name,
                .pin =  led->pin ,
                .logic = led->led_status,
                .direction = OUTPUT,
                
            };
            gpio_pin_write_logic(&pin_obj , LOW);
        }
        return ret ;
}
/**
 * @brief
 * @param led: pointer to the led module configurations
 * @return     status of the function
 *             (E_NOT_OK)  : The function has issue to perform this action 
 *             (E_OK)      : The function done successfully
 */
STD_RETURN_TYPE  led_turn_toggle        (const led_t *led ){
    STD_RETURN_TYPE ret = E_OK;
        if(NULL == led){
            ret  = E_NOT_OK ;
        }
        else{
            pin_config_t pin_obj = {
                .port = led->port_name,
                .pin =  led->pin ,
                .logic = led->led_status,
                .direction = OUTPUT,
                
            };
            gpio_pin_toggle_logic(&pin_obj );
        }
        return ret ;
}
