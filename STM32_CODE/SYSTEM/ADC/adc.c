#include "adc.h"
#include "delay.h"
#include "stm32f10x_adc.h"
#include "stm32f10x_dma.h"
#include "timer.h"
// #include "Data_manage.h"

//volatile u16 ADCConvertedValue[SAMPDEPTH] = {0}; //ADת��������
u8 UpdatTrue = 0;        //�жϱ�� ADת�����20�μ����ñ�־��Ϊ0xff ���������н�ת�������������0

//��ʼ��ADC
//�������ǽ��Թ���ͨ��Ϊ��
void  Adc_Init(void)
{
	ADC_InitTypeDef ADC_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	DMA_InitTypeDef   DMA_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;  //�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_ADC1	, ENABLE );	 //ʹ��ADC1ͨ��ʱ��
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);         //ADC1ʹ��DMA1��ͨ��1


	RCC_ADCCLKConfig(RCC_PCLK2_Div6);   //����ADC��Ƶ����6 72M/6=12,ADC���ʱ�䲻�ܳ���14M

	//ADC1 ͨ��1ʹ��PA1 ��Ϊģ��ͨ����������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		//ģ����������
	GPIO_Init(GPIOA, &GPIO_InitStructure);


	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&ADC1->DR;
	DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)ADCConvertedValue;
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
	DMA_InitStructure.DMA_BufferSize = SAMPDEPTH;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord ;
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	DMA_Init(DMA1_Channel1, &DMA_InitStructure);
	DMA_Cmd(DMA1_Channel1, ENABLE);
	
	DMA_Cmd( DMA1_Channel1, ENABLE);
	DMA_ITConfig(DMA1_Channel1, DMA_IT_TC, ENABLE);


	ADC_DeInit(ADC1);  //��λADC1
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;	//ADC����ģʽ:ADC1��ADC2�����ڶ���ģʽ
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;	//ģ��ת�������ڵ�ͨ��ģʽ
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;	//ģ��ת�������ڵ���ת��ģʽ
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T3_TRGO; 	//ת����TIM4ͨ��4�������������Ҳ����TIM4 CH4ͨ�����벶׽���� ���ݶ�ʱ���ĳ�ʼ�����þ�����//��ʱ��3�����¼�Ϊ�ⲿ����Դ
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;	//ADC�����Ҷ���
	ADC_InitStructure.ADC_NbrOfChannel = 1;	//˳����й���ת����ADCͨ������Ŀ
	ADC_Init(ADC1, &ADC_InitStructure);	//����ADC_InitStruct��ָ���Ĳ�����ʼ������ADCx�ļĴ���

	ADC_ExternalTrigConvCmd(ADC1, ENABLE);
//  	ADC_ITConfig(ADC1,ADC_IT_EOC,ENABLE);  //����ADC1ת�������ж�
	ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_1Cycles5 );	//ADC1,ADCͨ��1,����ʱ��Ϊ13.5����
	ADC_DMACmd(ADC1, ENABLE);

	ADC_Cmd(ADC1, ENABLE);	//ʹ��ָ����ADC1
	ADC_ResetCalibration(ADC1);	//ʹ�ܸ�λУ׼
	while (ADC_GetResetCalibrationStatus(ADC1));	//�ȴ���λУ׼����
	ADC_StartCalibration(ADC1);	 //����ADУ׼
	while (ADC_GetCalibrationStatus(ADC1));	 //�ȴ�У׼����

//	ADC_SoftwareStartConvCmd(ADC1, ENABLE);		//ʹ��ָ����ADC1�����ת����������

	NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel1_IRQn ;	//�ж�����
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	//��ռ���ȼ�2��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;			//�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;		//ʹ���ⲿ�ж�ͨ��
	NVIC_Init(&NVIC_InitStructure);

}

//DMA���һ�����ݴ��ݺ���ж�
void DMA1_Channel1_IRQHandler(void)
{
	if (DMA_GetITStatus(DMA1_IT_TC1) != RESET)
	{
		DMA_ClearITPendingBit(DMA1_IT_TC1);
		UpdatTrue = 0xff;            //�����жϱ�ǣ������������жϲ���0
		TIM_Cmd(TIM3, DISABLE);	   //���������д��������ݺ��ٴ�
	}
}

u32 ADC_Fr = 100000;
//�ı������
void ADC_Change_Fr(u32 Fr)//16-1000001HZ
{
	u16 temp;
	if ((Fr > 15) && (Fr < 1000002))
	{
		temp = 1000000 / Fr;
	}
	else
	{
		temp = 1;
	}
	arr_ADC = temp - 1;
	psc_ADC = 72 - 1;
	ADCTriggerByTIM3(arr_ADC, psc_ADC);
	ADC_Fr = Fr;
}

void ADC_Fr_plus(void)
{
	ADC_Fr = ADC_Fr << 1;
	ADC_Change_Fr(ADC_Fr);
}

void ADC_Fr_dec(void)
{
	ADC_Fr = ADC_Fr >> 1;
	ADC_Change_Fr(ADC_Fr);
}

//�������ı�����
void ADC_change_gear (u8 gear) {
	switch(gear){
		case 0 : {
			LED0 = 0;
			LED1 = 0;
			Dac1_Set_Vol(GEAR_CTRL_VALUE[0]);//����VGA
			break;
		}
		case 1 : {
			LED0 = 1;
			LED1 = 0;
			Dac1_Set_Vol(GEAR_CTRL_VALUE[1]);//����VGA
			break;
		}
		case 2 : {
			LED0 = 0;
			LED1 = 1;
			Dac1_Set_Vol(GEAR_CTRL_VALUE[2]);//����VGA
			break;
		}
		case 3 : {
			LED0 = 1;
			LED1 = 1;
			Dac1_Set_Vol(GEAR_CTRL_VALUE[3]);//����VGA
			break;
		}
		default : {
			LED0 = 0;
			LED1 = 0;
			Dac1_Set_Vol(GEAR_CTRL_VALUE[0]);//����VGA
			break;
		}
	}
}























