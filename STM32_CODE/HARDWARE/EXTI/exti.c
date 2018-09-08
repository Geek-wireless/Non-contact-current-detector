#include "exti.h"
#include "led.h"
#include "key.h"
#include "delay.h"
#include "usart.h"

//////////////////////////////////////////////////////////////////////////////////
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//Mini STM32������
//�ⲿ�ж� ��������
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2010/12/01
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ����ԭ�� 2009-2019
//All rights reserved
//////////////////////////////////////////////////////////////////////////////////


//�ⲿ�жϳ�ʼ������
void EXTIX_Init(void)
{

  EXTI_InitTypeDef EXTI_InitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE); //�ⲿ�жϣ���Ҫʹ��AFIOʱ��

  KEY_Init();//��ʼ��������Ӧioģʽ

  //GPIOC.5 �ж����Լ��жϳ�ʼ������
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource5);

  EXTI_InitStructure.EXTI_Line = EXTI_Line5;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;//�½��ش���
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);   //����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���

  //GPIOA.15    �ж����Լ��жϳ�ʼ������
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource15);

  EXTI_InitStructure.EXTI_Line = EXTI_Line15;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);     //����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���

  //GPIOA.0   �ж����Լ��жϳ�ʼ������
//  GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);

//  EXTI_InitStructure.EXTI_Line = EXTI_Line0;
//  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
//  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
//  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
//  EXTI_Init(&EXTI_InitStructure);   //����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���



//  NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;      //ʹ�ܰ������ڵ��ⲿ�ж�ͨ��
//  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;  //��ռ���ȼ�2
//  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;         //�����ȼ�1
//  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;               //ʹ���ⲿ�ж�ͨ��
//  NVIC_Init(&NVIC_InitStructure);     //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���

  NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;      //ʹ�ܰ������ڵ��ⲿ�ж�ͨ��
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;  //��ռ���ȼ�2��
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;         //�����ȼ�1
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;               //ʹ���ⲿ�ж�ͨ��
  NVIC_Init(&NVIC_InitStructure);


  NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;      //ʹ�ܰ������ڵ��ⲿ�ж�ͨ��
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;  //��ռ���ȼ�2��
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;         //�����ȼ�1
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;               //ʹ���ⲿ�ж�ͨ��
  NVIC_Init(&NVIC_InitStructure);

}


//void EXTI0_IRQHandler(void) //key_up
//{
//  delay_ms(10);    //����
//  if (WK_UP == 1)
//  {
////    LED0 = !LED0;
////    clear_flag = 1;
////    if (state_flag == 0 || state_flag == 1) {
////      state_flag = 2;
////    }
////    else if (state_flag == 3) {
////      state_flag = 2;
////    }
////    else if (state_flag == 2)
////    {
////      state_flag = 3;
////    }
////    else
////    {
////      state_flag = 2;
////    }
//  }
//  EXTI_ClearITPendingBit(EXTI_Line0);  //���EXTI0��·����λ
//}

//u8 state_flag = 2;
//u8 clear_flag = 0;  //0��������1δ����
void EXTI9_5_IRQHandler(void) //key0
{
  delay_ms(20);   //����
  if (KEY0 == 0) {
////    LED1 = !LED1;
//    clear_flag = 1;
//    if (state_flag == 2 || state_flag == 3) {
//      state_flag = 0;
//    }
//    else if (state_flag == 0) {
//      state_flag = 1;
//    }
//    else if (state_flag == 1) {
//      state_flag = 0;
//    }
//    else
//    {
//      state_flag = 0;
//    }
  }
  printf("key0\n");
  EXTI_ClearITPendingBit(EXTI_Line5);    //���LINE5�ϵ��жϱ�־λ
}


void EXTI15_10_IRQHandler(void) //key1
{
  delay_ms(20);    //����
  if (KEY1 == 0) {
////    LED1 = !LED1;
//    clear_flag = 1;
//    if (state_flag == 0 || state_flag == 1) {
//      state_flag = 2;
//    }
//    else if (state_flag == 3) {
//      state_flag = 2;
//    }
//    else if (state_flag == 2)
//    {
//      state_flag = 3;
//    }
//    else
//    {
//      state_flag = 2;
//    }
  }
  printf("key1 state_flag\n");
  EXTI_ClearITPendingBit(EXTI_Line15);  //���LINE15��·����λ
}
