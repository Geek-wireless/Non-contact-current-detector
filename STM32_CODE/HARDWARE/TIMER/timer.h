#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK Mini STM32������
//ͨ�ö�ʱ�� ��������
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2010/12/03
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ����ԭ�� 2009-2019
//All rights reserved
//////////////////////////////////////////////////////////////////////////////////

extern u8  TIM5CH1_CAPTURE_STA;	//���벶��״̬
extern u16	TIM5CH1_CAPTURE_VAL;	//���벶��ֵ
extern u8 key_timer_scan;
//extern u8 kk;
//void TIM2_Int_Init(u16 arr, u16 psc);
void TIM6_Init(u16 arr, u16 psc);		//DAC����
//void ADCTriggerByTIM4(u16 arr,u16 psc);
void ADCTriggerByTIM3(u16 arr, u16 psc);	//ADC����
void TIM1_PWM_Init(u16 arr,u16 psc);	//PWM�����PA11S

void TIM2_Int_Init(u16 arr,u16 psc);	//TIM2,4,5��Ƶ��
void TIM5_Cap_Init(u16 arr,u16 psc);
void TIM4_Int_Init(u16 arr,u16 psc);

void TIM7_Int_Init(u16 arr, u16 psc);	//����1s����ˢ�¿���

#endif
