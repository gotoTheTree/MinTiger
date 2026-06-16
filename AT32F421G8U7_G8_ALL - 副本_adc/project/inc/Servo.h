#ifndef _Servo_H_
#define _Servo_H_
#include "at32f421.h"                   // Device header
#include "DefineFile.h"
#include "LED_INF.h"
#include "FlashDev.h"
#include "PWM_IN.h"

#define FLAH_DataBufferAddr 0x0800FC00
#define BufferLth 10
#define FLAH_CompleteByteAddr 0x0800FC00
#define FLAH_CompleteByteFlag 0x11
#define TurnByteAddr 0x0800FC01

extern uint8_t FlashBuffer[BufferLth];
extern unsigned Turn;


extern unsigned PWM_MOS_DC_SUM;
extern unsigned PWM_MOS_DC_T;

extern unsigned Servo_State;

extern unsigned Phase_SW;
extern float PWM_MOS_DC_FLOAT_EN;
extern float PWM_MOS_DC_MAX;
extern float PWM_MOS_DC_MIN;

extern unsigned Sart_Us_Sart_us;
extern unsigned Sart_Us_End_us;
extern unsigned Sart_Us_Differ_us;

extern unsigned SW_TIM_T_;
extern unsigned SW_TIM_;
extern unsigned SW_CMP_T_;
extern unsigned SW_CMP_;
extern unsigned SW_CMP_FLAG;
extern unsigned CMP_OverState;
extern double CMP_TIM_C;
extern unsigned CMP_TIM_Wit;


extern float CMP_TIM_K;
extern float CMP_DC_K;

extern float DC_D;

extern unsigned TEST_C;

extern unsigned H_CH_T;
extern unsigned gpio_L_pins_T;

extern unsigned CMP_M1;
extern unsigned CMP_M2;

float Servo_Vbat_Get(void);
float Servo_Val_0_1_Get(void);
void Servo_CloseALL(void);
void Servo_FLASH_Init(void);
void Servo_FLASH_UpdataToFlash(void);
void Servo_FLASH_UpdataToBuffer(void);
void Servo_Init(float SartDC,unsigned Sart_Us_Sart,unsigned Sart_Us_End,unsigned Sart_Us_Differ,float K_US,float K_DC);
void Servo_Start(void);
void Servo_Stop(void);
void Servo_Turn(unsigned turn);
void Servo_SET_DC(float	dc);
float Servo_Get_DC(void);
void Servo_BB_(float fhz,float dc,unsigned Tms);

#endif
