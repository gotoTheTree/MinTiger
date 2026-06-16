/* add user code begin Header */
/**
  **************************************************************************
  * @file     main.c
  * @brief    main program
  **************************************************************************
  *                       Copyright notice & Disclaimer
  *
  * The software Board Support Package (BSP) that is made available to
  * download from Artery official website is the copyrighted work of Artery.
  * Artery authorizes customers to use, copy, and distribute the BSP
  * software and its related documentation for the purpose of design and
  * development in conjunction with Artery microcontrollers. Use of the
  * software is governed by this copyright notice and the following disclaimer.
  *
  * THIS SOFTWARE IS PROVIDED ON "AS IS" BASIS WITHOUT WARRANTIES,
  * GUARANTEES OR REPRESENTATIONS OF ANY KIND. ARTERY EXPRESSLY DISCLAIMS,
  * TO THE FULLEST EXTENT PERMITTED BY LAW, ALL EXPRESS, IMPLIED OR
  * STATUTORY OR OTHER WARRANTIES, GUARANTEES OR REPRESENTATIONS,
  * INCLUDING BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.
  *
  **************************************************************************
  */
/* add user code end Header */

/* Includes ------------------------------------------------------------------*/
#include "at32f421_wk_config.h"
#include "wk_adc.h"
#include "wk_cmp.h"
#include "wk_tmr.h"
#include "wk_usart.h"
#include "wk_dma.h"
#include "wk_gpio.h"
#include "wk_system.h"

/* private includes ----------------------------------------------------------*/
/* add user code begin private includes */
#include "Servo.h"
#include "PWM_IN.h"
#include "at32f421_int.h"
#include "Music.h"
#include <stdio.h>
#include <string.h>
/* add user code end private includes */

/* private typedef -----------------------------------------------------------*/
/* add user code begin private typedef */

/* add user code end private typedef */

/* private define ------------------------------------------------------------*/
/* add user code begin private define */

/* add user code end private define */

/* private macro -------------------------------------------------------------*/
/* add user code begin private macro */

/* add user code end private macro */

/* private variables ---------------------------------------------------------*/
/* add user code begin private variables */

/* add user code end private variables */

/* private function prototypes --------------------------------------------*/
/* add user code begin function prototypes */

/* add user code end function prototypes */

/* private user code ---------------------------------------------------------*/
/* add user code begin 0 */
/*
----work_bench--ChangeLog----
--Delete config dma channel transfer parameter 
--wk_tmr.c in wk_tmr3_init init-gpio Replace As follows
	//	#ifdef PWM_PIN_4_
	//	gpio_pin_mux_config(GPIOB, GPIO_PINS_SOURCE4, GPIO_MUX_1);
	//  gpio_init_struct.gpio_pins = GPIO_PINS_4;
	//  gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
	//  gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
	//  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
	//  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_MODERATE;
	//  gpio_init(GPIOB, &gpio_init_struct);
	//	#endif
	//	
	//	#ifdef PWM_PIN_6_
	//	gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE6, GPIO_MUX_1);
	//  gpio_init_struct.gpio_pins = GPIO_PINS_6;
	//  gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
	//  gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
	//  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
	//  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_MODERATE;
	//  gpio_init(GPIOA, &gpio_init_struct);
	//	#endif
*/

const uint8_t Sheetmusic[]={
5+12,119,
3+12,119,
2+12,119,
3+12,119,
2+12,119,
1+12,119,
6,119,
1+12,119,
5+12,119,
3+12,119,
2+12,119,
3+12,119,
2+12,2+12,
119,
5+12,119,
3+12,119,
2+12,119,
3+12,119,
2+12,119,
1+12,119,
6,119,
1+12,119,
2+12,119,
2+12,119,
2+12,119,
3+12,119,
3+12,
3+12,119,
1+12,119,

5+12,119,
3+12,119,
2+12,119,
3+12,119,
2+12,119,
1+12,119,
6,119,
1+12,119,
5+12,119,
3+12,119,
2+12,119,
3+12,119,
2+12,2+12,
119,
5+12,119,
2+12,119,
2+12,119,
2+12,119,
3+12,119,
3+12,119,
6,119,
1+12,119,
6,119,
2+12,119,
2+12,119,
3+12,119,
6,119,
1+12,119,
0,119,
255
};

const uint8_t Sheetmusic_text[]={5+12,5+12,5+12,5+12,5+12,0,0,255};

const uint8_t Sheetmusic_Start[]={
1,2,3,5,1,2,3,255
};

/* add user code end 0 */

/**
  * @brief main function.
  * @param  none
  * @retval none
  */
int main(void)
{
  /* add user code begin 1 */
	//char start_s=1;
	//char str[50];
	//unsigned i,t;
	//float adc;
	uint8_t flag_t=0;
	float k=0.f;
	float StartDC=0.05,StopDC=0.03;
	#ifdef LED_DEBUG
	float led_dc;
	unsigned led_t=1000;
	#endif
	__pwm_irq_link_force();
  /* add user code end 1 */
	
  /* system clock config. */
  wk_system_clock_config();

  /* config periph clock. */
  wk_periph_clock_config();

  /* nvic config. */
  wk_nvic_config();

  /* timebase config. */
  wk_timebase_init();

  /* init dma1 channel5 */
  wk_dma1_channel5_init();
  /* config dma channel transfer parameter */
  /* user need to modify define values DMAx_CHANNELy_XXX_BASE_ADDR and DMAx_CHANNELy_BUFFER_SIZE in at32xxx_wk_config.h */
  /* init usart1 function. */
  wk_usart1_init();

  /* init cmp function. */
  wk_cmp_init();

  /* init adc1 function. */
  wk_adc1_init();

  /* init gpio function. */
  wk_gpio_config();

  /* init tmr1 function. */
  wk_tmr1_init();

  /* init tmr3 function. */
  wk_tmr3_init();

  /* init tmr6 function. */
  wk_tmr6_init();
	
  /* init tmr14 function. */
  wk_tmr14_init();

  /* init tmr15 function. */
  wk_tmr15_init();
	
  /* init tmr16 function. */
  wk_tmr16_init();
	
  /* add user code begin 2 */
	//LED_SET_S(1,0);
	wk_delay_ms(1000);
//	adc = Servo_Vbat_Get();
//	for(i=0;i<10;i++){
//		adc = (Servo_Vbat_Get()+adc)/2.0;
//	}
//	StartDC = -0.0054413*adc+0.19331318;

	StartDC=0.1;
	//Servo_Init(StartDC,/*5000*/27500,/*4800*/26400,100,/*0.01*/0.01,/*0.07*/0.05);	
	Servo_Init(0.1,20000,18000,100,0.01,0.05);	
	wk_delay_ms(300);
	
#ifdef INPUT_PWM
	Music_PlaySheetmusic(0.1f,(uint8_t*)Sheetmusic_Start,350000,4);
//	while(Sheetmusic_Start[i]!=255){
//		if(Sheetmusic_Start[i]==0){
//			//Music_Pause();
//			//Music_SetFrequency(200);
//			Music_SetVolume(0.f);
//			DELAY_TIM_US(350000);
//			Music_SetVolume(0.1f);
//			//Music_Play();
//		}else{
//			Music_SetFrequency(4*Tone_c4_b4[Sheetmusic_Start[i]-1]);
//			DELAY_TIM_US(350000);
//		}
//		i++;
//	}
#endif
	LED_SET_S(1,1);
	while(1){
#ifdef INPUT_PWM
			k=GetDC_PWM();
#elif defined(INPUT_DSHOT600)
			k = GetDC();
			if(k>=48.0f){
				k -= 48.0f;
				k = StartDC+((PWM_MOS_DC_MAX-StartDC)/1999*k);
			}else{
				k=0.f;
			}
#elif defined(INPUT_ADC)
			Servo_Val_0_1_Get();
			k = GetDC();
#endif
			wk_delay_ms(10);
			if(k<=StopDC)break;
		}		
	
	/* add user code end 2 */

  while(1)
  {
    /* add user code begin 3 */
		
#ifdef INPUT_PWM
			k=GetDC_PWM();
			if(k>=StartDC){
			k = StartDC+((PWM_MOS_DC_MAX-StartDC)*k);
			}else{
				k=0.f;
			}
#elif defined(INPUT_DSHOT600)
			//48--2047->StartDC--PWM_MOS_DC_MAX
			if(g_dshot_dma_ready){
				dshot_getdata();
				g_dshot_dma_ready=0;
			}
			k = GetDC();
			if(k>=48.0f){
				k -= 48.0f;
				k = StartDC+((PWM_MOS_DC_MAX-StartDC)/1999*k);
			}else{
				k=0.f;
			}
			if(DshotFlag==1){
				switch (PWM_DSHOT_Command)          
        {
        	case 0:
						if(Music_EN_Flag==0){
							Servo_Stop();
						}
							PWM_DSHOT_DC=0;
							k=0.f;
        		break;
        	case 1:
						Servo_Stop();
						Servo_BB_(500,0.025,500);
        		break;
					case 2:
						Servo_Stop();
						Servo_BB_(1000,0.025,500);
        		break;
        	case 3:
						Servo_Stop();
						Servo_BB_(1500,0.025,500);
        		break;
					case 4:
						Servo_Stop();
						Servo_BB_(2000,0.025,500);
        		break;
        	case 5:
						Servo_Stop();
						Servo_BB_(2500,0.025,500);
        		break;
        	case 7:
						Servo_Stop();
						Turn = 1;
						FlashBuffer[1] = 1;
						Servo_FLASH_UpdataToFlash();
        		break;
					case 8:
						Servo_Stop();
						Turn = 0;
						FlashBuffer[1] = 0;
						Servo_FLASH_UpdataToFlash();
        		break;
					case 20:
						Servo_Stop();
						Turn = 0;
        		break;
					case 21:
						Servo_Stop();
						Turn = 1;
        		break;
        	default:
						//error;
        		break;
        }
				DshotFlag=0;
			}
#elif defined(INPUT_ADC)
			Servo_Val_0_1_Get();
			k = GetDC();
#endif

#ifdef LED_DEBUG
//		led_dc = k;
//		if(led_dc>=StartDC){
//			gpio_bits_set(LED_1_GPIO_PORT,LED_1_PIN);
//		}
//		DELAY_TIM_US(led_dc*led_t);
//		gpio_bits_reset(LED_1_GPIO_PORT,LED_1_PIN);
//		DELAY_TIM_US((1-led_dc)*led_t);
			
		Music_PlaySheetmusic_C1_C7(0.1f,(uint8_t*)Sheetmusic,250000,64+5,0);
		//Music_PlaySheetmusic_C1_C7(0.1f,(uint8_t*)Sheetmusic_text,250000,64,0);
//		if(flag_t){
//			flag_t=0;
//			gpio_bits_reset(LED_1_GPIO_PORT,LED_1_PIN);
//		}else{
//			flag_t=1;
//			gpio_bits_set(LED_1_GPIO_PORT,LED_1_PIN);
//		}
//		DELAY_TIM_US(500);
		//DELAY_TIM_US((1-led_dc)*led_t);

//		Music_Play_One(0.1,10000,1000000);
//		Music_Play_One(0.1,1000,1000000);
//		Music_Play_One(0.1,400,1000000);
			
#else
		Servo_SET_DC(k);
		if(k>StopDC){
			if(Servo_State==0&&k>=StartDC){
				if(Music_EN_Flag==0){
					Servo_Start();
				}
			}
		}else{
			if(Servo_State!=0&Music_EN_Flag==0){
				Servo_Stop();
			}
		}
		//DELAY_TIM_US(10000);
#endif
		
/*----LOG_TO_UART----*/		
//		adc = Servo_Vbat_Get();
//		
//		sprintf(str,"SW=%f\r\n",adc);
//		t=strlen(str);
//		for(i=0;i<t;i++){
//			while(usart_flag_get(USART1,USART_TDBE_FLAG)==RESET);
//			usart_data_transmit(USART1,str[i]);
//			while(usart_flag_get(USART1,USART_TDC_FLAG)==RESET);
//		}
#ifdef INPUT_PWM
		wk_delay_ms(2);
#endif
    /* add user code end 3 */
  }
}

  /* add user code begin 4 */

  /* add user code end 4 */
