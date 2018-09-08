#include "timer.h"
#include "led.h"
#include "key.h"
#include "db.h"
#include "gui.h"
#include "usart.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//Mini STM32������
//ͨ�ö�ʱ�� ��������			   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2010/12/03
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ����ԭ�� 2009-2019
//All rights reserved
////////////////////////////////////////////////////////////////////////////////// 	  
 

////ͨ�ö�ʱ���жϳ�ʼ��
////����ʱ��ѡ��ΪAPB1��2������APB1Ϊ36M
////arr���Զ���װֵ��
////psc��ʱ��Ԥ��Ƶ��
////����ʹ�õ��Ƕ�ʱ��3!

//extern u8 kk;
//void TIM2_Int_Init(u16 arr,u16 psc)
//{
//  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//	NVIC_InitTypeDef NVIC_InitStructure;

//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //ʱ��ʹ��
//	
//	//��ʱ��TIM3��ʼ��
//	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	
//	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
//	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
//	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //����ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
// 
//	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE ); //ʹ��ָ����TIM3�ж�,��������ж�

//	//�ж����ȼ�NVIC����
//	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;  //TIM3�ж�
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  //��ռ���ȼ�1��
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //�����ȼ�3��
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ��ʹ��
//	NVIC_Init(&NVIC_InitStructure);  //��ʼ��NVIC�Ĵ���
//	
//	TIM_Cmd(TIM2, ENABLE);  //ʹ��TIMx					 
//}
////u8 kk=0;
////��ʱ��3�жϷ�����:10ms��ʱһ��
//void TIM2_IRQHandler(void)
//{
//	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET) //����ж�
//	{ 
//		kk++;
//		if(kk>=10)kk=0;
//	}
//	TIM_ClearITPendingBit(TIM2,TIM_IT_Update);  //����жϱ�־λ
//}

//TIM6��ʼ��������DAC
void TIM6_Init(u16 arr, u16 psc)
{
    TIM_TimeBaseInitTypeDef    TIM_TimeBaseStructure;

    /* TIM6 ʱ��ʹ��*/
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);
    /* TIM6 ���� */
    /* Time6 ʱ����Ԫ���� */
    TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
    TIM_TimeBaseStructure.TIM_Period = arr;
    TIM_TimeBaseStructure.TIM_Prescaler = psc;
    TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);

    /* TIM6 TRGO selection */
    TIM_SelectOutputTrigger(TIM6, TIM_TRGOSource_Update);
    /* ʹ��TIM6 �������� */
    TIM_Cmd(TIM6, ENABLE);

}


///***************************************************************************************************
//1��ͨ�ö�ʱ��4��ʼ�� ��ʱ��4ʹ���ڲ�ʱ��72M  arr���Զ���װֵ0-65535�� psc��ʱ��Ԥ��Ƶ��0-65535
//2����ʱ��4��ͨ��4��PWM�����PB9 �����أ����ڴ���ADC,����ADCת��
//Tout= ((arr+1)*(psc+1))/Tclk (Tclk��TIM3 ������ʱ��Ƶ�ʣ���λΪ Mhz��,Tout��TIM3 ���ʱ�䣨��λΪ us��)
//****************************************************************************************************/
//void ADCTriggerByTIM4(u16 arr,u16 psc)
//{
//	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//	TIM_OCInitTypeDef  TIM_OCInitStructure; 
//	GPIO_InitTypeDef  GPIO_InitStructure;
// 	
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //ʹ��PB�˿�ʱ��
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE); //ʱ��ʹ��
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;				 //LED0-->PB.9 �˿�����
//    GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_AF_PP; 		 //�����������
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
//    GPIO_Init(GPIOB, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOB.9

//	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	
//	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  
//	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
//	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ	
//		
//	//��ʼ��TIM4 Channel4 �Ƚ����ģʽ	 
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
//	//TIM_OCInitStructure.TIM_OCMode =TIM_OCMode_Toggle; 
// 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //���ʹ��
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
//	TIM_OCInitStructure.TIM_Pulse=(uint16_t) (((uint32_t) 50 * (arr+1)) / 100);			//����
//	TIM_OC4Init(TIM4, &TIM_OCInitStructure);  //����ָ���Ĳ�����ʼ������TIM4 OC4

//	TIM_SelectOutputTrigger(TIM4,TIM_TRGOSource_OC4Ref);       //ʹ��TIM4 ͨ��4 PWM�����ΪADC����
//	TIM_Cmd(TIM4, ENABLE);  //ʹ��TIM4����
//	
//}

//ͨ�ö�ʱ��3ʱ����Ԫ��ʼ��
//��ʱ��3ʹ���ڲ�ʱ��72M
//arr���Զ���װֵ��
//psc��ʱ��Ԥ��Ƶ��
void ADCTriggerByTIM3(u16 arr, u16 psc)
{
//	GPIO_InitTypeDef GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//	TIM_OCInitTypeDef  TIM_OCInitStructure;


    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);	//ʹ�ܶ�ʱ��3ʱ��
// 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB  | RCC_APB2Periph_AFIO, ENABLE);  //ʹ��GPIO�����AFIO���ù���ģ��ʱ��

//	GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE); //Timer3������ӳ��  TIM3_CH2->PB5

    //��ʼ��TIM3
    TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ
    TIM_TimeBaseStructure.TIM_Prescaler = psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ

    /* TIM3 ѡ������¼�Ϊ�ⲿ����Դ */
    TIM_SelectOutputTrigger(TIM3, TIM_TRGOSource_Update);

    TIM_Cmd(TIM3, ENABLE);  //ʹ��TIM3
}


//PWM�����ʼ��
//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��
void TIM1_PWM_Init(u16 arr, u16 psc)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    TIM_OCInitTypeDef  TIM_OCInitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);//
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);   //ʹ��GPIO����ʱ��ʹ��


    //���ø�����Ϊ�����������,���TIM1 CH1��PWM���岨��
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11; //TIM1_CH4
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //�����������
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);


    TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	 80K
    TIM_TimeBaseStructure.TIM_Prescaler = psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  ����Ƶ
    TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ


    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
    TIM_OCInitStructure.TIM_Pulse = 0; //���ô�װ�벶��ȽϼĴ���������ֵ
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
    TIM_OC4Init(TIM1, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx

    TIM_CtrlPWMOutputs(TIM1, ENABLE);	//MOE �����ʹ��

    TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable);  //CH1Ԥװ��ʹ��

    TIM_ARRPreloadConfig(TIM1, ENABLE); //ʹ��TIMx��ARR�ϵ�Ԥװ�ؼĴ���

    TIM_Cmd(TIM1, ENABLE);  //ʹ��TIM1
}


//ͨ�ö�ʱ��4ʱ����Ԫ��ʼ��
//��ʱ��1ʹ���ڲ�ʱ��72M������ʱ��Ϊ1S,�����ж�ʹ��
//arr���Զ���װֵ��psc��ʱ��Ԥ��Ƶ��
//TIM4����Ϊ��ģʽ������1s�����¼���Ϊ�Ӷ�ʱ���Ĵ�������

void TIM4_Int_Init(u16 arr, u16 psc)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE); //ʱ��ʹ��

    //TIM4ʱ����Ԫ��ʼ��
    TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	 ���ú���ʱarr=9999  ����ʱ��Ϊ1s
    TIM_TimeBaseStructure.TIM_Prescaler = psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ   ���ú���ʱpsc=7199 72M��ƵΪ10khz
    TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIM4��ʱ�������λ

    //TIM4����Ϊ��ģʽ����1S�����¼���Ϊ�Ӷ�ʱ���Ĵ�������
    TIM_SelectOutputTrigger(TIM4, TIM_TRGOSource_Update);

    TIM_Cmd(TIM4, ENABLE);  //TIM4ʹ�ܼ������ܣ���ʼ����

}


extern u32 FreqExtCounter;
extern u32 FreqVal;
extern u32 FreqVal1;
//ͨ�ö�ʱ��2��ʼ��  ��ʱ��2ʹ���ڲ�ʱ��72M
//arr���Զ���װֵ�� psc��ʱ��Ԥ��Ƶ��
//��ʱ��2ʹ���ⲿʱ��Դģʽ2��������Ƶ���źżӵ�PA0��TIM2_CH1_ETR����
void TIM2_Int_Init(u16 arr, u16 psc)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    //��ʱ��2ͨ��1���벶������
    TIM_ICInitTypeDef  TIM2_ICInitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;


    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //ʱ��ʹ��
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  //ʹ��GPIOAʱ��

    //�˿�PA0������
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;  //PA0
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING; //
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    //GPIO_ResetBits(GPIOA,GPIO_Pin_0);  //PA0������ݱ���Ϊ0

    //TIM2ʱ����Ԫ��ʼ��
    TIM_TimeBaseStructure.TIM_Period = arr; //	arr=0xffff  �������Ĵ���=arrʱ����TIM2�����ж�
    TIM_TimeBaseStructure.TIM_Prescaler = psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  psc=0,����Ƶ  72M����ʱ��
    TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ

    //��ʼ��TIM2���벶�����
    TIM2_ICInitStructure.TIM_Channel = TIM_Channel_1; // ����ͨ��1
    TIM2_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_BothEdge;//TIM_ICPolarity_Rising;	//�����ز���
    TIM2_ICInitStructure.TIM_ICSelection = TIM_ICSelection_TRC; //CC1S=11 	ѡ������� IC1ӳ�䵽TRC��//������ʱ����������TRC
    TIM2_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	 //���������Ƶ,����Ƶ
    TIM2_ICInitStructure.TIM_ICFilter = 0x00;//IC1F=0000 ���������˲��� ���˲�
    TIM_ICInit(TIM2, &TIM2_ICInitStructure);


    /* Slave Mode selection: TIM2 */
    //ѡ��TIM2Ϊ��ģʽ�еĸ�λģʽ
    TIM_SelectSlaveMode(TIM2, TIM_SlaveMode_Reset); //������ʱ����λ,��0

    //TIM2ѡ��TIM4�ĸ����¼���Ϊ�������룬TIM4���������¼���TIM2�ļ����Ĵ�����0
    TIM_SelectInputTrigger(TIM2, TIM_TS_ITR3);//�����Ĳο��ֲ�14.3.14 �ڣ���78 //ѡ��T4ΪT2��TRC

    //TIM2ѡ���ⲿʱ��Դģʽ2�������ⲿETR�������źţ���ΪTIM2�ļ������壬����Ƶ����ETR�����ؼ�������ʹ���ⲿ�����˲�
    //TIM_ETRClockMode2Config(TIM2, TIM_ExtTRGPSC_DIV4,TIM_ExtTRGPolarity_NonInverted, 0x00);

    TIM_ETRClockMode2Config(TIM2, TIM_ExtTRGPSC_OFF, TIM_ExtTRGPolarity_NonInverted, 0x00); //

    //�жϷ����ʼ��
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;  //TIM2�ж�
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;  //��ռ���ȼ�2��
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //�����ȼ�0��
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
    NVIC_Init(&NVIC_InitStructure);  //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���

    TIM_ClearITPendingBit(TIM2, TIM_IT_Update | TIM_IT_Trigger  ); //


    TIM_ITConfig(TIM2, TIM_IT_Update | TIM_IT_Trigger, ENABLE); //��������ж�,����ͨ��1�Ĳ����ж�

    //TIM_ClearITPendingBit(TIM2, TIM_IT_Update| TIM_IT_CC1 );

    //TIM_ITConfig(TIM2,TIM_IT_Update| TIM_IT_CC1,ENABLE);//��������ж�,����ͨ��1�Ĳ����ж�


    TIM_Cmd(TIM2, ENABLE);  //ʹ��TIM2����


}

u8  TIM5CH1_CAPTURE_STA;	//���벶��״̬
u16	TIM5CH1_CAPTURE_VAL;	//���벶��ֵ
u8  plus_sta = 1; //��������/���������л�
u16 Cycle_Val;//����ֵ

void TIM2_IRQHandler(void)
{
    if(TIM_GetITStatus(TIM2, TIM_IT_Trigger) != RESET)
    {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Trigger | TIM_IT_Update ); //���TIM2ͨ��1�����벶���жϱ�־
        FreqVal = FreqExtCounter + TIM_GetCapture1(TIM2);
        FreqExtCounter = 0;
        if(FreqVal >= 500) //����500Hz�ر��������
        {
            TIM_ITConfig(TIM5, TIM_IT_Update | TIM_IT_CC1, DISABLE); //��������ж� ,����CC1IE�����ж�
            TIM_OC1PolarityConfig(TIM5, TIM_ICPolarity_Rising); //CC1P=0 ����Ϊ�����ز���
            TIM_Cmd(TIM5, DISABLE ); 	//ʹ�ܶ�ʱ��5
            TIM5CH1_CAPTURE_STA = 0;			//��� ��׼��
            TIM5CH1_CAPTURE_VAL = 0;
            TIM_SetCounter(TIM5, 0);
        } else
        {
            TIM_ITConfig(TIM5, TIM_IT_Update | TIM_IT_CC1, ENABLE); //��������ж� ,����CC1IE�����ж�
            TIM_OC1PolarityConfig(TIM5, TIM_ICPolarity_Rising); //CC1P=0 ����Ϊ�����ز���
            TIM_Cmd(TIM5, ENABLE ); 	//ʹ�ܶ�ʱ��5
        }
//				LED1=0;
    }
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)  //���TIM2�����жϷ������
    {
//		    LED0=0;
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
        FreqExtCounter = FreqExtCounter + 0x10000; //�Ѽ���0x10000=65536�������ź������أ����ڣ�
    }



}


//��ʱ��5ͨ��1���벶������
//u8  TIM5CH1_CAPTURE_STA = 0;	//���벶��״̬
//u16	TIM5CH1_CAPTURE_VAL;		//���벶��ֵ
//u8  plus_sta = 1; 				//��������/���������л�

TIM_ICInitTypeDef  TIM5_ICInitStructure;

void TIM5_Cap_Init(u16 arr, u16 psc)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);	//ʹ��TIM5ʱ��
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  //ʹ��GPIOAʱ��

    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;  //PA0 ���֮ǰ����
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PA0 ����
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_ResetBits(GPIOA, GPIO_Pin_0);						 //PA0 ����

    //��ʼ����ʱ��5 TIM5
    TIM_TimeBaseStructure.TIM_Period = arr; //�趨�������Զ���װֵ
    TIM_TimeBaseStructure.TIM_Prescaler = psc; 	//Ԥ��Ƶ��
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
    TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ

    //��ʼ��TIM5���벶�����
    TIM5_ICInitStructure.TIM_Channel = TIM_Channel_1; //CC1S=01 	ѡ������� IC1ӳ�䵽TI1��
    TIM5_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	//�����ز���
    TIM5_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //ӳ�䵽TI1��
    TIM5_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	 //���������Ƶ,����Ƶ
    TIM5_ICInitStructure.TIM_ICFilter = 0x00;//IC1F=0000 ���������˲��� ���˲�
    TIM_ICInit(TIM5, &TIM5_ICInitStructure);

    //�жϷ����ʼ��
    NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;  //TIM3�ж�
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  //��ռ���ȼ�2��
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  //�����ȼ�0��
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
    NVIC_Init(&NVIC_InitStructure);  //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���

    TIM_ITConfig(TIM5, TIM_IT_Update | TIM_IT_CC1, ENABLE); //��������ж� ,����CC1IE�����ж�
    TIM_OC1PolarityConfig(TIM5, TIM_ICPolarity_Rising); //CC1P=0 ����Ϊ�����ز���
    TIM_Cmd(TIM5, ENABLE ); 	//ʹ�ܶ�ʱ��5



}

//��ʱ��5�жϷ������
void TIM5_IRQHandler(void)
{
    if((TIM5CH1_CAPTURE_STA & 0X80) == 0) //��δ�ɹ�����
    {
        if (TIM_GetITStatus(TIM5, TIM_IT_Update) != RESET)//�жϱ�־=1 ���洦�ж�
        {
            if(TIM5CH1_CAPTURE_STA & 0X40) //�Ѿ����񵽸ߵ�ƽ��
            {
                if((TIM5CH1_CAPTURE_STA & 0X3F) == 0X3F) //�ߵ�ƽ̫����
                {
                    TIM5CH1_CAPTURE_STA |= 0X80; //��ǳɹ�������һ��
                    TIM5CH1_CAPTURE_VAL = 0XFFFF; //�������޷���������ǿ�ƽ���
                } else TIM5CH1_CAPTURE_STA++;//ÿ����ж�һ�μ�һ����
            }
        }
        if (TIM_GetITStatus(TIM5, TIM_IT_CC1) != RESET)//�иߵ�ƽ,����1���������¼�
        {
            if(TIM5CH1_CAPTURE_STA & 0X40)		//����һ���½���
            {
                TIM5CH1_CAPTURE_STA |= 0X80;		//��ǳɹ�����һ�θߵ�ƽ���� �������
                TIM5CH1_CAPTURE_VAL = TIM_GetCapture1(TIM5); //β��ֵ
                TIM_OC1PolarityConfig(TIM5, TIM_ICPolarity_Rising); //CC1P=0 ����Ϊ�����ز���
            } else  								//��δ��ʼ,��һ�β���������
            {
                TIM5CH1_CAPTURE_STA = 0;			//��� ��׼��
                TIM5CH1_CAPTURE_VAL = 0;
                TIM_SetCounter(TIM5, 0);
                TIM5CH1_CAPTURE_STA |= 0X40;		//��ǲ�����������
                if(plus_sta == 0) //���=1,���ǲ������������������,Ϊ����
                {   //�������
                    TIM_OC1PolarityConfig(TIM5, TIM_ICPolarity_Falling);		//CC1P=1 ����Ϊ�½��ز���
                }
            }
        }
    }
    TIM_ClearITPendingBit(TIM5, TIM_IT_CC1 | TIM_IT_Update); //����жϱ�־λ
}


//ͨ�ö�ʱ��7�жϳ�ʼ��
//����ʱ��ѡ��ΪAPB1��2������APB1Ϊ36M
//arr���Զ���װֵ��
//psc��ʱ��Ԥ��Ƶ��
//����ʹ�õ��Ƕ�ʱ��4
void TIM7_Int_Init(u16 arr, u16 psc)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE); //ʱ��ʹ��

    //��ʱ��TIM4��ʼ��
    TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ
    TIM_TimeBaseStructure.TIM_Prescaler = psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
    TIM_TimeBaseInit(TIM7, &TIM_TimeBaseStructure); //����ָ���Ĳ�����ʼ��TIMx��ʱ�������λ


    //�ж����ȼ�NVIC����
    NVIC_InitStructure.NVIC_IRQChannel = TIM7_IRQn;  //TIM7�ж�
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;  //��ռ���ȼ�0��
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //�����ȼ�3��
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
    NVIC_Init(&NVIC_InitStructure);  //��ʼ��NVIC�Ĵ���

    TIM_UpdateRequestConfig(TIM7, TIM_UpdateSource_Regular);  //ֻ�м��������������ſ��Բ��������жϣ�����UGλ��ͨ����ģʽ���������ܲ�������
    TIM_ClearITPendingBit(TIM7, TIM_IT_Update);   //�������ʹ�ܵ��жϱ�־����ֹ������������ж�
    TIM_ITConfig(TIM7, TIM_IT_Update, ENABLE ); //ʹ��ָ����TIM4�ж�,��������ж�

    TIM_Cmd(TIM7, ENABLE);  //ʹ��TIM7
}


//DDS_RAM ʹ��ʱ��Ҫ��main.c���涨��
//extern u32 FreqCH0S0Val;
//extern u32 FreqCH0Val;
//extern u32 FreqCH0E0Val;
//extern u32 FreqCH0step;
//extern u32 FreqCH1S0Val;
//extern u32 FreqCH1Val;
//extern u32 FreqCH1E0Val;
//extern u32 FreqCH1step;
//��ʱ��7�жϷ������
u8 refresh_flag;
u8 key_timer_scan = 0;
extern u8 max_flag;
static u8 time_1s = 0;
void TIM7_IRQHandler(void)   //TIM7�ж�
{
    if (TIM_GetITStatus(TIM7, TIM_IT_Update) != RESET)  //���TIM7�����жϷ������
    {
        TIM_ClearITPendingBit(TIM7, TIM_IT_Update  );  //���TIMx�����жϱ�־
        key_timer_scan = KEY_Scan(0);	//�õ���ֵ
				if	(max_flag==1)
				{
			//AD603();
					max_flag=0;
				}
		
        //ͨ��0 ɨƵ����
//        FreqCH0Val = FreqCH0Val + FreqCH0step;
//        if(FreqCH0Val >= FreqCH0E0Val) {
//            FreqCH0Val = FreqCH0S0Val;
//        }
//        AD9958_W_Freq(0, FreqCH0Val);  //AD9958_W_Freq(1,10000000);
//        AD9958_IO_Update();

////    AD9958_W_Amp(0,256);         //AD9958_W_Amp(1,512);
////    AD9958_W_Phase(0,15);        // AD9958_W_Phase(1,90);

//        //ͨ��1 ɨƵ����
//        FreqCH1Val = FreqCH1Val + FreqCH1step;
//        if(FreqCH1Val >= FreqCH1E0Val) {
//            FreqCH1Val = FreqCH1S0Val;
//        }
//        AD9958_W_Freq(1, FreqCH1Val);  //AD9958_W_Freq(1,10000000);
//        AD9958_IO_Update();

        time_1s++;
        if(time_1s == 20) {
            time_1s = 0;
            refresh_flag = 1;
        }
    }
}








