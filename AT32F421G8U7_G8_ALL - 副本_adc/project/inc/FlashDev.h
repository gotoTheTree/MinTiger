#ifndef _FLASHDEV_H_
#define _FLASHDEV_H_

#define FLASH_DEV_START_ADDR_ 0x0800FC00
#define FLASH_DEV_SIZE_ 10

#include "at32f421.h"                   // Device header
#include "LED_INF.h"

flag_status FLASH_WriteByte(uint32_t addr,uint8_t Data);
flag_status FLASH_WriteSWord(uint32_t addr,uint16_t Data);
flag_status FLASH_WriteWord(uint32_t addr,uint32_t Data);
flag_status FLASH_WriteDatas(uint32_t Faddr,uint8_t* Data,unsigned Lth);
uint32_t FLASH_ReadWord(uint32_t addr);
uint16_t FLASH_ReadSWord(uint32_t addr);
uint8_t FLASH_ReadByte(uint32_t addr);
flag_status FLASH_WriteDatas(uint32_t Faddr,uint8_t* Data,unsigned Lth);
void FLASH_ReadDatas(uint32_t addr,uint8_t* dataBuffer,unsigned lth);
flag_status FLASH_ErasePage(void);
#endif

