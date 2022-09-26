/* 
 * File:   main_application.c
 * Author: Mahmood_Adel
 *
 * Created on September 11, 2022, 6:49 AM
 */
/*#define HWREG8(_X)                           (*(( volatile unsigned char *)(_X))) 
#define AHMED_LATC                          (HWREG8(0Xf8B))
#define AHMED_TRISC                         (HWREG8(0XF94))
#define CLEAR_BIT(REG_POS,BIT_POS)          (REG_POS &= ~(1 << BIT_POS))    */  
 
#include "application.h"

uint8 portc_direction_status,portc_logic_status;


STD_RETURN_TYPE ret = E_OK;
pin_config_t led_1 = {
    .port      = PORTC_INDEX ,
    .pin       = PIN0 ,
    .direction = OUTPUT  ,
    .logic     = LOW ,
};

pin_config_t led_2 = {
    .port      = PORTC_INDEX ,
    .pin       = PIN1 ,
    .direction = OUTPUT  ,
    .logic     = LOW ,
};

pin_config_t led_3 = {
    .port      = PORTC_INDEX ,
    .pin       = PIN2 ,
    .direction = OUTPUT  ,
    .logic     = LOW ,
};

pin_config_t btn_1 = {
    .port      = PORTD_INDEX ,
    .pin       = PIN0 ,
    .direction = INPUT  ,
    .logic     = LOW ,
};
led_t led1 = {.port_name = PORTC_INDEX , .pin = PIN0 , .led_status = LOW};
led_t led2 = {.port_name = PORTC_INDEX , .pin = PIN1 , .led_status = LOW};
led_t led3 = {.port_name = PORTC_INDEX , .pin = PIN2 , .led_status = LOW};
led_t led4 = {.port_name = PORTC_INDEX , .pin = PIN3 , .led_status = LOW};
                    

direction_t led_1st;
logic_t btn1_status;
int main() {
    
    application_initialize();
    while (1){
       led_turn_on(&led1);
       led_turn_on(&led2);
       led_turn_on(&led3);
       led_turn_on(&led4);
       __delay_ms(250);
       led_turn_off(&led1);
       led_turn_off(&led2);
       led_turn_off(&led3);
       led_turn_off(&led4);
        __delay_ms(250);
    }
    
    return (EXIT_SUCCESS);
}

void application_initialize (void){
   STD_RETURN_TYPE ret = E_NOT_OK;
   ret= led_initialize(&led1);
   ret= led_initialize(&led2);
   ret= led_initialize(&led3);
   ret= led_initialize(&led4);
   
}