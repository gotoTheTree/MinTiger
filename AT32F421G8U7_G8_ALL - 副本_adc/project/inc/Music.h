#ifndef MUSIC_H
#define MUSIC_H

#include "at32f421.h"                   // Device header
#include "Servo.h"
#include "math.h"

#define Music_DIV 119
#define Music_Int_DIV 119
#define Music_Int_TIM TMR3

extern uint8_t Music_EN_Flag;//清除电机状态
extern uint8_t Music_Play_Flag;//配置定时器状态

void TMR3_GLOBAL_IRQHandler(void);
void Music_Start(float F_PWM);
void Music_SetFrequency(float F);
void Music_SetVolume(float dc);
void Music_Play(void);
void Music_Pause(void);
void Music_Play_One(float dc,float F,unsigned us);
void Music_End(void);
void Music_PlaySheetmusic(float Volume,uint8_t* SheetmusicArr,uint32_t Reference_time_us,uint16_t Pitch_multiplier_toC4);
void Music_PlaySheetmusic_C1_C7(float Volume,uint8_t* SheetmusicArr,uint32_t Reference_time,float Pitch_multiplier,float f_offset);
extern const float Tone_c4_b4[];
#endif
