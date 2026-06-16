#ifndef _PWM_IN_H_
#define _PWM_IN_H_
#include "at32f421.h"                   // Device header
#include "DefineFile.h"
#include "wk_dma.h"
#define PWM_IN_TIM TMR15
#define DSHOT_BUF_SIZE 32
#define DSHOT_CAPTURE_COUNT 16//´«Êä´ÎÊý
#define DMA_ALIGN_COUNT 10//uint16_t
extern float PWM_DSHOT_DC;
extern float INPUT_ADC_VAL;
extern unsigned PWM_DSHOT_Command;
extern unsigned DshotFlag;
extern unsigned PWM_Sate;
extern unsigned PWM_Data;
extern unsigned PWM_IN_UPT;
extern unsigned PWM_IN_Cycle;
extern unsigned Tdata;
extern volatile uint16_t g_dshot_capture_buf[DSHOT_BUF_SIZE];
extern volatile uint8_t g_dshot_dma_ready;
extern volatile uint16_t* Frame_Buf;
extern volatile uint16_t* Dma_Buf;
extern volatile uint16_t Dma_Count;
void PWM_IN_Init(void);
float GetDC(void);
float GetDC_PWM(void);
void PWM_DshotAnalysis(unsigned data);
void wk_dma1_channel5_init_end(void);
unsigned dshot_getdata(void);
#endif
