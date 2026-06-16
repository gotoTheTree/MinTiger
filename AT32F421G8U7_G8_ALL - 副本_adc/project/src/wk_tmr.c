/* add user code begin Header */
/**
  **************************************************************************
  * @file     wk_tmr.c
  * @brief    work bench config program
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
#include "wk_tmr.h"

/* add user code begin 0 */
#include "DefineFile.h"
/* add user code end 0 */

/**
  * @brief  init tmr1 function.
  * @param  none
  * @retval none
  */
void wk_tmr1_init(void)
{
  /* add user code begin tmr1_init 0 */

  /* add user code end tmr1_init 0 */

  gpio_init_type gpio_init_struct;
  tmr_output_config_type tmr_output_struct;
  tmr_brkdt_config_type tmr_brkdt_struct;

  gpio_default_para_init(&gpio_init_struct);

  /* add user code begin tmr1_init 1 */

  /* add user code end tmr1_init 1 */

  /* configure the tmr1 CH1 pin */
  gpio_pin_mux_config(WH_P_GPIO_PORT, GPIO_PINS_SOURCE8, GPIO_MUX_2);
  gpio_init_struct.gpio_pins = WH_P_PIN;
  gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
  gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_MODERATE;
  gpio_init(WH_P_GPIO_PORT, &gpio_init_struct);

  /* configure the tmr1 CH2 pin */
  gpio_pin_mux_config(VH_P_GPIO_PORT, GPIO_PINS_SOURCE9, GPIO_MUX_2);
  gpio_init_struct.gpio_pins = VH_P_PIN;
  gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
  gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_MODERATE;
  gpio_init(VH_P_GPIO_PORT, &gpio_init_struct);

  /* configure the tmr1 CH3 pin */
  gpio_pin_mux_config(UH_P_GPIO_PORT, GPIO_PINS_SOURCE10, GPIO_MUX_2);
  gpio_init_struct.gpio_pins = UH_P_PIN;
  gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
  gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_MODERATE;
  gpio_init(UH_P_GPIO_PORT, &gpio_init_struct);

  /* configure counter settings */
  tmr_cnt_dir_set(TMR1, TMR_COUNT_UP);
  tmr_clock_source_div_set(TMR1, TMR_CLOCK_DIV1);
  tmr_repetition_counter_set(TMR1, 0);
  tmr_period_buffer_enable(TMR1, FALSE);
  tmr_base_init(TMR1, 3999, 2);

  /* configure primary mode settings */
  tmr_sub_sync_mode_set(TMR1, FALSE);
  tmr_primary_mode_select(TMR1, TMR_PRIMARY_SEL_RESET);

  /* configure channel 1 output settings */
  tmr_output_struct.oc_mode = TMR_OUTPUT_CONTROL_PWM_MODE_A;
  tmr_output_struct.oc_output_state = TRUE;
  tmr_output_struct.occ_output_state = FALSE;
  tmr_output_struct.oc_polarity = TMR_OUTPUT_ACTIVE_HIGH;
  tmr_output_struct.occ_polarity = TMR_OUTPUT_ACTIVE_HIGH;
  tmr_output_struct.oc_idle_state = FALSE;
  tmr_output_struct.occ_idle_state = FALSE;
  tmr_output_channel_config(TMR1, TMR_SELECT_CHANNEL_1, &tmr_output_struct);
  tmr_channel_value_set(TMR1, TMR_SELECT_CHANNEL_1, 0);
  tmr_output_channel_buffer_enable(TMR1, TMR_SELECT_CHANNEL_1, FALSE);

  tmr_output_channel_immediately_set(TMR1, TMR_SELECT_CHANNEL_1, FALSE);

  /* configure channel 2 output settings */
  tmr_output_struct.oc_mode = TMR_OUTPUT_CONTROL_PWM_MODE_A;
  tmr_output_struct.oc_output_state = TRUE;
  tmr_output_struct.occ_output_state = FALSE;
  tmr_output_struct.oc_polarity = TMR_OUTPUT_ACTIVE_HIGH;
  tmr_output_struct.occ_polarity = TMR_OUTPUT_ACTIVE_HIGH;
  tmr_output_struct.oc_idle_state = FALSE;
  tmr_output_struct.occ_idle_state = FALSE;
  tmr_output_channel_config(TMR1, TMR_SELECT_CHANNEL_2, &tmr_output_struct);
  tmr_channel_value_set(TMR1, TMR_SELECT_CHANNEL_2, 0);
  tmr_output_channel_buffer_enable(TMR1, TMR_SELECT_CHANNEL_2, FALSE);

  tmr_output_channel_immediately_set(TMR1, TMR_SELECT_CHANNEL_2, FALSE);

  /* configure channel 3 output settings */
  tmr_output_struct.oc_mode = TMR_OUTPUT_CONTROL_PWM_MODE_A;
  tmr_output_struct.oc_output_state = TRUE;
  tmr_output_struct.occ_output_state = FALSE;
  tmr_output_struct.oc_polarity = TMR_OUTPUT_ACTIVE_HIGH;
  tmr_output_struct.occ_polarity = TMR_OUTPUT_ACTIVE_HIGH;
  tmr_output_struct.oc_idle_state = FALSE;
  tmr_output_struct.occ_idle_state = FALSE;
  tmr_output_channel_config(TMR1, TMR_SELECT_CHANNEL_3, &tmr_output_struct);
  tmr_channel_value_set(TMR1, TMR_SELECT_CHANNEL_3, 0);
  tmr_output_channel_buffer_enable(TMR1, TMR_SELECT_CHANNEL_3, FALSE);

  tmr_output_channel_immediately_set(TMR1, TMR_SELECT_CHANNEL_3, FALSE);

  /* configure break and dead-time settings */
  tmr_brkdt_struct.brk_enable = FALSE;
  tmr_brkdt_struct.auto_output_enable = FALSE;
  tmr_brkdt_struct.brk_polarity = TMR_BRK_INPUT_ACTIVE_LOW;
  tmr_brkdt_struct.fcsoen_state = FALSE;
  tmr_brkdt_struct.fcsodis_state = FALSE;
  tmr_brkdt_struct.wp_level = TMR_WP_OFF;
  tmr_brkdt_struct.deadtime = 0;
  tmr_brkdt_config(TMR1, &tmr_brkdt_struct);


  tmr_output_enable(TMR1, TRUE);

  tmr_counter_enable(TMR1, TRUE);

  /* add user code begin tmr1_init 2 */
	tmr_counter_enable(TMR1, FALSE);
	tmr_base_init(HTIM, MCU_Frequency_HZ/(MOS_PWM_Frequency_HZ*(MCU_HTIM_DIV+1))-1, MCU_HTIM_DIV);
	tmr_counter_enable(TMR1, TRUE);
  /* add user code end tmr1_init 2 */
}

/**
  * @brief  init tmr3 function.
  * @param  none
  * @retval none
  */
void wk_tmr3_init(void)
{
  /* add user code begin tmr3_init 0 */

  /* add user code end tmr3_init 0 */


  /* add user code begin tmr3_init 1 */

  /* add user code end tmr3_init 1 */

  /* configure counter settings */
  tmr_cnt_dir_set(TMR3, TMR_COUNT_UP);
  tmr_clock_source_div_set(TMR3, TMR_CLOCK_DIV1);
  tmr_period_buffer_enable(TMR3, FALSE);
  tmr_base_init(TMR3, 65535, 119);

  /* configure primary mode settings */
  tmr_sub_sync_mode_set(TMR3, FALSE);
  tmr_primary_mode_select(TMR3, TMR_PRIMARY_SEL_RESET);

  tmr_counter_enable(TMR3, TRUE);

  /**
   * Users need to configure TMR3 interrupt functions according to the actual application.
   * 1. Call the below function to enable the corresponding TMR3 interrupt.
   *     --tmr_interrupt_enable(...)
   * 2. Add the user's interrupt handler code into the below function in the at32f421_int.c file.
   *     --void TMR3_GLOBAL_IRQHandler(void)
   */

  /* add user code begin tmr3_init 2 */
		
  /* add user code end tmr3_init 2 */
}

/**
  * @brief  init tmr6 function.
  * @param  none
  * @retval none
  */
void wk_tmr6_init(void)
{
  /* add user code begin tmr6_init 0 */

  /* add user code end tmr6_init 0 */

  /* add user code begin tmr6_init 1 */

  /* add user code end tmr6_init 1 */

  /* configure counter settings */
  tmr_cnt_dir_set(TMR6, TMR_COUNT_UP);
  tmr_period_buffer_enable(TMR6, FALSE);
  tmr_base_init(TMR6, 65535, 29);

  /* configure primary mode settings */
  tmr_primary_mode_select(TMR6, TMR_PRIMARY_SEL_RESET);

  tmr_counter_enable(TMR6, TRUE);

  /**
   * Users need to configure TMR6 interrupt functions according to the actual application.
   * 1. Call the below function to enable the corresponding TMR6 interrupt.
   *     --tmr_interrupt_enable(...)
   * 2. Add the user's interrupt handler code into the below function in the at32f421_int.c file.
   *     --void TMR6_GLOBAL_IRQHandler(void)
   */

  /* add user code begin tmr6_init 2 */
	
  /* add user code end tmr6_init 2 */
}

/**
  * @brief  init tmr14 function.
  * @param  none
  * @retval none
  */
void wk_tmr14_init(void)
{
  /* add user code begin tmr14_init 0 */

  /* add user code end tmr14_init 0 */


  /* add user code begin tmr14_init 1 */

  /* add user code end tmr14_init 1 */

  /* configure counter settings */
  tmr_cnt_dir_set(TMR14, TMR_COUNT_UP);
  tmr_clock_source_div_set(TMR14, TMR_CLOCK_DIV1);
  tmr_period_buffer_enable(TMR14, FALSE);
  tmr_base_init(TMR14, 65535, 29);

  tmr_counter_enable(TMR14, TRUE);

  /**
   * Users need to configure TMR14 interrupt functions according to the actual application.
   * 1. Call the below function to enable the corresponding TMR14 interrupt.
   *     --tmr_interrupt_enable(...)
   * 2. Add the user's interrupt handler code into the below function in the at32f421_int.c file.
   *     --void TMR14_GLOBAL_IRQHandler(void)
   */

  /* add user code begin tmr14_init 2 */

  /* add user code end tmr14_init 2 */
}

/**
  * @brief  init tmr15 function.
  * @param  none
  * @retval none
  */
void wk_tmr15_init(void)
{
  /* add user code begin tmr15_init 0 */

  /* add user code end tmr15_init 0 */

  gpio_init_type gpio_init_struct;
  tmr_input_config_type  tmr_input_struct;

  gpio_default_para_init(&gpio_init_struct);

  /* add user code begin tmr15_init 1 */

  /* add user code end tmr15_init 1 */

  /* configure the tmr15 CH1 pin */
  gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE2, GPIO_MUX_0);
  gpio_init_struct.gpio_pins = GPIO_PINS_2;
  gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
  gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_MODERATE;
  gpio_init(GPIOA, &gpio_init_struct);

  /* configure counter settings */
  tmr_cnt_dir_set(TMR15, TMR_COUNT_UP);
  tmr_clock_source_div_set(TMR15, TMR_CLOCK_DIV1);
  tmr_repetition_counter_set(TMR15, 0);
  tmr_period_buffer_enable(TMR15, FALSE);
  tmr_base_init(TMR15, 65535, 119);

  /* configure primary mode settings */
  tmr_sub_sync_mode_set(TMR15, FALSE);
  tmr_primary_mode_select(TMR15, TMR_PRIMARY_SEL_RESET);

  /* configure sub-mode */
  tmr_sub_mode_select(TMR15, TMR_SUB_RESET_MODE);
	
	 /* configure overflow event */
  tmr_overflow_request_source_set(TMR15, TRUE);

  /* configure sub-mode input */
  tmr_trigger_input_select(TMR15, TMR_SUB_INPUT_SEL_C1DF1);

  /* configure channel 1 input settings */
  tmr_input_struct.input_channel_select = TMR_SELECT_CHANNEL_1;
  tmr_input_struct.input_mapped_select = TMR_CC_CHANNEL_MAPPED_DIRECT;
  tmr_input_struct.input_polarity_select = TMR_INPUT_RISING_EDGE;
  tmr_input_struct.input_filter_value = 1;
  tmr_input_channel_init(TMR15, &tmr_input_struct, TMR_CHANNEL_INPUT_DIV_1);

  /* configure channel 2 input settings */
  tmr_input_struct.input_channel_select = TMR_SELECT_CHANNEL_2;
  tmr_input_struct.input_mapped_select = TMR_CC_CHANNEL_MAPPED_INDIRECT;
  tmr_input_struct.input_polarity_select = TMR_INPUT_FALLING_EDGE;
  tmr_input_struct.input_filter_value = 0;
  tmr_input_channel_init(TMR15, &tmr_input_struct, TMR_CHANNEL_INPUT_DIV_1);

  /* configure dma ch2 */
  tmr_dma_request_enable(TMR15, TMR_C2_DMA_REQUEST, TRUE);
  tmr_counter_enable(TMR15, TRUE);

  /**
   * Users need to configure TMR15 interrupt functions according to the actual application.
   * 1. Call the below function to enable the corresponding TMR15 interrupt.
   *     --tmr_interrupt_enable(...)
   * 2. Add the user's interrupt handler code into the below function in the at32f421_int.c file.
   *     --void TMR15_GLOBAL_IRQHandler(void)
   */

  /* add user code begin tmr15_init 2 */
	//tmr_interrupt_enable(TMR15,TMR_OVF_INT,TRUE);
	#ifdef INPUT_DSHOT600
		tmr_counter_enable(TMR15, FALSE);
		tmr_base_init(TMR15,600,0);//2+dmadelay usÒç³öÖÐ¶Ï
	#endif
  /* add user code end tmr15_init 2 */
}

/**
  * @brief  init tmr16 function.
  * @param  none
  * @retval none
  */
void wk_tmr16_init(void)
{
  /* add user code begin tmr16_init 0 */

  /* add user code end tmr16_init 0 */


  /* add user code begin tmr16_init 1 */

  /* add user code end tmr16_init 1 */

  /* configure counter settings */
  tmr_cnt_dir_set(TMR16, TMR_COUNT_UP);
  tmr_clock_source_div_set(TMR16, TMR_CLOCK_DIV1);
  tmr_repetition_counter_set(TMR16, 0);
  tmr_period_buffer_enable(TMR16, FALSE);
  tmr_base_init(TMR16, 65535, 119);

  tmr_counter_enable(TMR16, TRUE);

  /**
   * Users need to configure TMR16 interrupt functions according to the actual application.
   * 1. Call the below function to enable the corresponding TMR16 interrupt.
   *     --tmr_interrupt_enable(...)
   * 2. Add the user's interrupt handler code into the below function in the at32f421_int.c file.
   *     --void TMR16_GLOBAL_IRQHandler(void)
   */

  /* add user code begin tmr16_init 2 */
	tmr_counter_enable(TMR16, FALSE);
	tmr_interrupt_enable(TMR16,TMR_OVF_INT,TRUE);
  /* add user code end tmr16_init 2 */
}

/* add user code begin 1 */
unsigned char TMR16_INT_FLAG=0;
void	wk_tmr16_Delay(unsigned us){
	while(us!=0){
		if(us>65535){
			us -= 65535;
			TMR16_INT_FLAG = 0;
			TMR16->cval = 0;
			tmr_counter_enable(TMR16, TRUE);
			while(TMR16_INT_FLAG==0);
		}else{
			TMR16->cval = 65535-us;
			us=0;
			TMR16_INT_FLAG=0;
			tmr_counter_enable(TMR16, TRUE);
			while(TMR16_INT_FLAG==0);
		}
	}
	return;
}
/* add user code end 1 */
