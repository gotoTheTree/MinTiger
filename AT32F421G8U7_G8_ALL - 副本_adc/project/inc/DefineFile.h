#ifndef _DefineFile_H_
#define _DefineFile_H_
#include "wk_tmr.h"
//DEBUG
#define LED_DEBUG

//F
#define MCU_Frequency_HZ 120000000.0 
#define MCU_HTIM_DIV 2
#define MOS_PWM_Frequency_HZ  10000.0

#define SW_MIN_T 20/*TIM_F*/
#define SW_MAX_T 320000/*TIM_F*/

//#define INPUT_DSHOT600 INPUT_ADC INPUT_PWM
#define INPUT_PWM

//MOTO_START
#define Phase_locked_us 20000 //20ms

//Vbat_CH
#define VBAT_CH ADC_CHANNEL_3
#define VBAT_K 11.0
#define VMCU 3.28

//MOS_OUT_PIN
//H_TIM_SET_F
//tmr_base_init(HTIM, 1.0/((double)MOS_PWM_Frequency_HZ*(MCU_HTIM_DIV+1)/(double)MCU_Frequency_HZ)-1, MCU_HTIM_DIV);

//PWM_PIN
#define PWM_PIN_4_

//H_PIN
#define HTIM TMR1
#define UH_CH TMR_SELECT_CHANNEL_3
#define VH_CH TMR_SELECT_CHANNEL_2
#define WH_CH	TMR_SELECT_CHANNEL_1
//L_PIN
#define UL_G GPIOB
#define VL_G GPIOB
#define WL_G GPIOA
#define UL_P GPIO_PINS_1
#define VL_P GPIO_PINS_0
#define WL_P GPIO_PINS_7

//MOS_START_DC
#define MOS_START_DC 0.2

//DELAY_TIM
#define DELAY_TIM_US wk_tmr16_Delay
#define DELAY_TIM TMR16

//SW_US_TIM
#define SW_US_TIM TMR6
//SW_US_K
#define SW_US_K 1.0

//CMP_US_TIM
#define CMP_US_TIM TMR14
//CMP_US_K
#define CMP_US_K 1.0
//CMP_US_DELAY
#define CMP_DELAY 8/*TIM_F*/
#endif
