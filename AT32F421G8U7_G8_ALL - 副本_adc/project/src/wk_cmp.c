/* add user code begin Header */
/**
  **************************************************************************
  * @file     wk_cmp.c
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
#include "wk_cmp.h"

/* add user code begin 0 */

/* add user code end 0 */

/**
  * @brief  init cmp function.
  * @param  none
  * @retval none
  */
void wk_cmp_init(void)
{
  /* add user code begin cmp_init 0 */

  /* add user code end cmp_init 0 */

  gpio_init_type gpio_init_struct;
  cmp_init_type cmp_init_struct;

  gpio_default_para_init(&gpio_init_struct);

  /* add user code begin cmp_init 1 */

  /* add user code end cmp_init 1 */

  /* configure the INP1pin */
  gpio_init_struct.gpio_pins = MV_PIN;
  gpio_init_struct.gpio_mode = GPIO_MODE_ANALOG;
  gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
  gpio_init(MV_GPIO_PORT, &gpio_init_struct);

  /* configure the INM6 pin */
  gpio_init_struct.gpio_pins = UV_PIN;
  gpio_init_struct.gpio_mode = GPIO_MODE_ANALOG;
  gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
  gpio_init(UV_GPIO_PORT, &gpio_init_struct);

  cmp_default_para_init(&cmp_init_struct);
  cmp_init_struct.cmp_non_inverting = CMP_NON_INVERTING_PA1;
  cmp_init_struct.cmp_inverting = CMP_INVERTING_PA0;
  cmp_init_struct.cmp_output = CMP_OUTPUT_NONE;
  cmp_init_struct.cmp_polarity = CMP_POL_INVERTING;
  cmp_init_struct.cmp_speed = CMP_SPEED_FAST;
  cmp_init_struct.cmp_hysteresis = CMP_HYSTERESIS_NONE;
  cmp_init(CMP1_SELECTION, &cmp_init_struct);

  cmp_enable(CMP1_SELECTION, TRUE);

  cmp_scal_brg_config(CMP_SCAL_BRG_11);

  /* add user code begin cmp_init 2 */

  /* add user code end cmp_init 2 */
}

/* add user code begin 1 */

/* add user code end 1 */
