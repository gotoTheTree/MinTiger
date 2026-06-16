#include "Music.h"

const float Tone_c4_b4[]={
	261.63,//c4
	293.66,//d4
	329.63,//e4
	349.23,//f4
	392.00,//g4
	440.00,//a4
	493.88,//b4
	277.18,//c#4
	311.13,//d#4
	369.99,//f#4
	415.30,//g#4
	466.16//a#4
};

#define ChannelLth 108
const float ChannelBut[ChannelLth];


uint8_t Music_EN_Flag;//清除电机状态
uint8_t Music_Play_Flag;//配置定时器状态
uint8_t Music_SW_Flag;//换向
unsigned DC_COUNT;
float dc_f;
float Music_DC_MAX=0.5;
float Music_F;
unsigned Music_MOS_DC_SUM=0;

void Music_Start(float F_PWM){
	Music_EN_Flag = 1;
	Servo_Stop();
	DC_COUNT=0;
	dc_f=0;
	tmr_counter_enable(Music_Int_TIM, FALSE);
	tmr_counter_enable(HTIM, FALSE);
	//tmr_base_init(Music_Int_TIM, SW_US, Music_Int_DIV);
	Music_MOS_DC_SUM = MCU_Frequency_HZ/(F_PWM*(MCU_HTIM_DIV+1))-1;
	tmr_base_init(HTIM, Music_MOS_DC_SUM, MCU_HTIM_DIV);
	
	//SET H_CH DC = 0
	tmr_channel_value_set(HTIM,UH_CH,0);
	tmr_channel_value_set(HTIM,VH_CH,0);
	tmr_channel_value_set(HTIM,WH_CH,0);
	//SET L_CH DC = FALSE
	gpio_bits_reset(UL_G,UL_P);
	gpio_bits_reset(VL_G,VL_P);
	gpio_bits_reset(WL_G,WL_P);
	//tmr_counter_enable(HTIM, TRUE);
}

void Music_SetFrequency(float F){
	if(Music_EN_Flag){
		Music_F = F;
		if(Music_F<=1.0f)Music_F=1.0f;
		tmr_base_init(Music_Int_TIM, MCU_Frequency_HZ/(Music_F*(Music_DIV+1))-1, Music_DIV);
	}
}

void Music_SetVolume(float dc){
	if(Music_EN_Flag){
		if(dc<Music_DC_MAX){
			DC_COUNT = dc*Music_MOS_DC_SUM;
			dc_f = dc;
		}else{
			dc_f = Music_DC_MAX;
			DC_COUNT = dc_f*Music_MOS_DC_SUM;
		}
	}
}

void Music_Play(void){
	if(Music_EN_Flag){
		Music_Play_Flag = 1;
		Music_Int_TIM->cval = 0;
		HTIM->cval = 0;
		tmr_interrupt_enable(Music_Int_TIM,TMR_OVF_INT,TRUE);
		tmr_counter_enable(Music_Int_TIM,TRUE);
		tmr_counter_enable(HTIM, TRUE);
	}
}

void Music_Pause(void){
	if(Music_EN_Flag){
		Music_Play_Flag = 0;
		tmr_counter_enable(HTIM, FALSE);
		tmr_counter_enable(Music_Int_TIM,FALSE);
		tmr_interrupt_enable(Music_Int_TIM,TMR_OVF_INT,FALSE);
	}
}

void Music_Play_One(float dc,float F,unsigned us){
	if(Music_EN_Flag){
		float old_dc = dc_f;
		float old_F = Music_F;
		//en
		Music_SetFrequency(F);
		Music_SetVolume(dc);
		Music_Play();
		DELAY_TIM_US(us);
		Music_Pause();
		//end
		Music_SetFrequency(old_F);
		Music_SetVolume(old_dc);
	}
}

void Music_PlaySheetmusic(float Volume,uint8_t* SheetmusicArr,uint32_t Reference_time,uint16_t Pitch_multiplier){
	unsigned i=0;
	Music_Start(10000);
	Music_SetVolume(Volume);
	Music_Play();
	while(SheetmusicArr[i]!=255){
		if(SheetmusicArr[i]==0){
			//Music_Pause();
			//Music_SetFrequency(200);
			Music_SetVolume(0.f);
			DELAY_TIM_US(Reference_time);
			Music_SetVolume(Volume);
			//Music_Play();
		}else{
			Music_SetFrequency(Pitch_multiplier*Tone_c4_b4[SheetmusicArr[i]-1]);
			DELAY_TIM_US(Reference_time);
		}
		i++;
	}
	Music_End();
	return;
}

//108 c1_c7 109_119 delay/(1_10)
void Music_PlaySheetmusic_C1_C7(float Volume,uint8_t* SheetmusicArr,uint32_t Reference_time,float Pitch_multiplier,float f_offset){
	unsigned i=0;
	Music_Start(10000);
	Music_SetVolume(Volume);
	Music_Play();
	while(SheetmusicArr[i]!=255){
		if(SheetmusicArr[i]==0){
			//Music_Pause();
			//Music_SetFrequency(200);
			Music_SetVolume(0.f);
			DELAY_TIM_US(Reference_time);
			Music_SetVolume(Volume);
			//Music_Play();
		}else if(SheetmusicArr[i]<109){
			unsigned t_i = (SheetmusicArr[i]-1)/12;
			float f;
			f = Tone_c4_b4[SheetmusicArr[i]-1-(12*t_i)]*pow(2,(int)t_i-3);
//			if(t_i==3){
//				f = Tone_c4_b4[SheetmusicArr[i]-1-36]*pow(2,t_i-3);
//			}else if(t_i<3){
//				f = Tone_c4_b4[SheetmusicArr[i]-1-(12*t_i)]/pow(2,3-t_i);
//			}else if(t_i>3){
//				f = Tone_c4_b4[SheetmusicArr[i]-1-(12*t_i)]*pow(2,t_i-3);
//			}
			Music_SetFrequency(f_offset+Pitch_multiplier*f);
			DELAY_TIM_US(Reference_time);
		}else if(SheetmusicArr[i]<120){
			Music_SetVolume(0.f);
			DELAY_TIM_US(Reference_time/(SheetmusicArr[i]-108));
			Music_SetVolume(Volume);
		}
		i++;
	}
	Music_End();
	return;
}

void Music_End(void){
	Music_EN_Flag = 0;
	Music_Play_Flag=0;
	
	tmr_counter_enable(HTIM, FALSE);
	tmr_base_init(HTIM, MCU_Frequency_HZ/(MOS_PWM_Frequency_HZ*(MCU_HTIM_DIV+1))-1, MCU_HTIM_DIV);
	tmr_interrupt_enable(Music_Int_TIM,TMR_OVF_INT,FALSE);
	tmr_counter_enable(Music_Int_TIM, FALSE);
	
	//SET H_CH DC = 0
	tmr_channel_value_set(HTIM,UH_CH,0);
	tmr_channel_value_set(HTIM,VH_CH,0);
	tmr_channel_value_set(HTIM,WH_CH,0);
	
	//SET L_CH DC = FALSE
	gpio_bits_reset(UL_G,UL_P);
	gpio_bits_reset(VL_G,VL_P);
	gpio_bits_reset(WL_G,WL_P);
}

void TMR3_GLOBAL_IRQHandler(void)
{
  /* add user code begin TMR3_GLOBAL_IRQ 0 */	
	if(tmr_flag_get(TMR3,TMR_OVF_FLAG)!=RESET){
		if(Music_EN_Flag){
			switch (Music_SW_Flag){
				case 0:
					gpio_bits_reset(VL_G,VL_P);
					//UH_WL
					tmr_channel_value_set(HTIM,UH_CH,DC_COUNT);
					gpio_bits_set(WL_G,WL_P);
					break;
				case 1:
					tmr_channel_value_set(HTIM,UH_CH,0);
					//VH_WL
					tmr_channel_value_set(HTIM,VH_CH,DC_COUNT);
					gpio_bits_set(WL_G,WL_P);
					break;
				case 2:
					gpio_bits_reset(WL_G,WL_P);
					//VH_UL
					tmr_channel_value_set(HTIM,VH_CH,DC_COUNT);
					gpio_bits_set(UL_G,UL_P);
					break;
				case 3:
					tmr_channel_value_set(HTIM,VH_CH,0);
					//WH_UL
					tmr_channel_value_set(HTIM,WH_CH,DC_COUNT);
					gpio_bits_set(UL_G,UL_P);
					break;
				case 4:
					gpio_bits_reset(UL_G,UL_P);
					//WH_VL
					tmr_channel_value_set(HTIM,WH_CH,DC_COUNT);
					gpio_bits_set(VL_G,VL_P);
					break;
				case 5:
					tmr_channel_value_set(HTIM,WH_CH,0);
					//UH_VL
					tmr_channel_value_set(HTIM,UH_CH,DC_COUNT);
					gpio_bits_set(VL_G,VL_P);
					break;
				}
				Music_SW_Flag = Music_SW_Flag==6?0:Music_SW_Flag+1;
		}
	}
  /* add user code end TMR3_GLOBAL_IRQ 0 */


  /* add user code begin TMR3_GLOBAL_IRQ 1 */
	tmr_flag_clear(TMR3,TMR_OVF_FLAG);
  /* add user code end TMR3_GLOBAL_IRQ 1 */
}

