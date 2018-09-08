#include "GUI.h"
#include "math.h"
//extern DAC_WAVE_Typedef DAC_SETTING;


void GUI_draw_key_0(void)
{
//  LCD_Clear(WHITE);   //����
    LCD_Display_Dir(1);//����
    POINT_COLOR = RED;          //��������Ϊ��ɫ

    LCD_DrawRectangle(20, 20, 300, 220);

    LCD_DrawLine(90, 20, 90, 220);
    LCD_DrawLine(160, 20, 160, 220);
    LCD_DrawLine(230, 20, 230, 220);

    LCD_DrawLine(20, 70, 300, 70);
    LCD_DrawLine(20, 120, 300, 120);
    LCD_DrawLine(20, 170, 300, 170);

    Show_Str(140, 5, 200, 16, "�ź�Դ", 12, 1);

    Show_Str(35, 40, 200, 16, "���Ҳ�", 16, 1);
    Show_Str(35, 90, 200, 16, "��ݲ�", 16, 1);
    Show_Str(35, 140, 200, 16, "���ǲ�", 16, 1);
    Show_Str(35, 190, 200, 16, "��  ��", 16, 1);

    Show_Str(105, 40, 200, 16, "��  ��", 16, 1);
    Show_Str(105, 90, 200, 16, "��  ��", 16, 1);
    Show_Str(105, 140, 200, 16, "Ƶ��+1", 16, 1);
    Show_Str(105, 190, 200, 16, "Ƶ��-1", 16, 1);
//    LCD_ShowxNum(105, 172, DAC_SETTING.HZ, 4, 16, 0x00);    //��ʾƵ��

    Show_Str(175, 40, 200, 16, "��  ��", 16, 1);
    Show_Str(175, 90, 200, 16, "��  ��", 16, 1);
    Show_Str(175, 140, 200, 16, "����+1", 16, 1);
    Show_Str(175, 190, 200, 16, "����-1", 16, 1);

    Show_Str(245, 40, 200, 16, "ˮƽ��", 16, 1);
    Show_Str(245, 90, 200, 16, "��ֱ��", 16, 1);
    Show_Str(245, 140, 200, 16, "ֱ��+0", 16, 1);
    Show_Str(245, 190, 200, 16, "ֱ��-0", 16, 1);
}

void GUI_draw_key_1(void)
{
    LCD_Display_Dir(1);//����
    POINT_COLOR = RED;          //��������Ϊ��ɫ

    LCD_DrawRectangle(20, 20, 300, 220);

    LCD_DrawLine(90, 20, 90, 220);
    LCD_DrawLine(160, 20, 160, 220);
    LCD_DrawLine(230, 20, 230, 220);

    LCD_DrawLine(20, 70, 300, 70);
    LCD_DrawLine(20, 120, 300, 120);
    LCD_DrawLine(20, 170, 300, 170);

    Show_Str(140, 5, 200, 16, "ʾ����", 12, 1);

    Show_Str(35, 40, 200, 16, "��  ��", 16, 1);
    Show_Str(35, 90, 200, 16, "������", 16, 1);
    Show_Str(35, 140, 200, 16, "��ƽ��", 16, 1);
    Show_Str(35, 190, 200, 16, "��ƽ��", 16, 1);

    Show_Str(105, 40, 200, 16, "��  ��", 16, 1);
    Show_Str(105, 90, 200, 16, "��  ��", 16, 1);
    Show_Str(105, 140, 200, 16, "ʱ��+1", 16, 1);
    Show_Str(105, 190, 200, 16, "ʱ��-1", 16, 1);
    LCD_ShowxNum(105, 172, ADC_Fr, 7, 16, 0x00);    //��ʾ������

    Show_Str(175, 40, 200, 16, "��  ��", 16, 1);
    Show_Str(175, 90, 200, 16, "��  ��", 16, 1);
    Show_Str(175, 140, 200, 16, "����+1", 16, 1);
    Show_Str(175, 190, 200, 16, "����-1", 16, 1);

    Show_Str(245, 40, 200, 16, "��λ0", 16, 1);
    Show_Str(245, 90, 200, 16, "��λ1", 16, 1);
    Show_Str(245, 140, 200, 16, "��λ2", 16, 1);
    Show_Str(245, 190, 200, 16, "��λ3", 16, 1);
}

void GUI_draw_coordinate(void)  //������
{
//  LCD_Clear(WHITE);   //����
    LCD_Display_Dir(1);//����
    POINT_COLOR = RED;          //��������Ϊ��ɫ
//  Show_Str(105,90,200,16,"������",16,1);

    LCD_DrawRectangle(10, 10, 310, 230);
    LCD_DrawLine(40, 10, 40, 230);
    LCD_DrawLine(70, 10, 70, 230);
    LCD_DrawLine(100, 10, 100, 230);
    LCD_DrawLine(130, 10, 130, 230);
    LCD_DrawLine(159, 10, 159, 230);
    LCD_DrawLine(160, 10, 160, 230);
    LCD_DrawLine(161, 10, 161, 230);
    LCD_DrawLine(190, 10, 190, 230);
    LCD_DrawLine(220, 10, 220, 230);
    LCD_DrawLine(250, 10, 250, 230);
    LCD_DrawLine(280, 10, 280, 230);

    LCD_DrawLine(10, 30, 310, 30);
    LCD_DrawLine(10, 60, 310, 60);
    LCD_DrawLine(10, 90, 310, 90);
    LCD_DrawLine(10, 119, 310, 119);
    LCD_DrawLine(10, 120, 310, 120);
    LCD_DrawLine(10, 121, 310, 121);
    LCD_DrawLine(10, 150, 310, 150);
    LCD_DrawLine(10, 180, 310, 180);
    LCD_DrawLine(10, 210, 310, 210);
}

void GUI_draw_frame(void)   //����
{
//  LCD_Clear(WHITE);   //����
    LCD_Display_Dir(1);//����
    POINT_COLOR = RED;          //��������Ϊ��ɫ

    LCD_DrawRectangle(10, 10, 310, 230);
}

//�źŷ����� DAC
void GUI_scan_0(void)
{
    LCD_Display_Dir(1);//����
    tp_dev.scan(0); 	//����ͨ��ɨ��
    if ((tp_dev.sta & 0x80))	//������������
    {
//		TP_Draw_Big_Point(tp_dev.x[0],tp_dev.y[0],BLUE);		//��ͼ	   just for test
        if ((tp_dev.x[0] > x0) && (tp_dev.x[0] < x1) && (tp_dev.y[0] > y0) && (tp_dev.y[0] < y1))	//(1,1) ���Ҳ�
        {

        }
        if ((tp_dev.x[0] > x1) && (tp_dev.x[0] < x2) && (tp_dev.y[0] > y0) && (tp_dev.y[0] < y1))	//(1,2) ����
        {

        }
        if ((tp_dev.x[0] > x2) && (tp_dev.x[0] < x3) && (tp_dev.y[0] > y0) && (tp_dev.y[0] < y1))	//(1,3) ����
        {

        }
        if ((tp_dev.x[0] > x3) && (tp_dev.x[0] < x4) && (tp_dev.y[0] > y0) && (tp_dev.y[0] < y1))	//(1,4) ˮƽ��
        {

        }
        if ((tp_dev.x[0] > x0) && (tp_dev.x[0] < x1) && (tp_dev.y[0] > y1) && (tp_dev.y[0] < y2))	//(2,1) ��ݲ�
        {

        }
        if ((tp_dev.x[0] > x1) && (tp_dev.x[0] < x2) && (tp_dev.y[0] > y1) && (tp_dev.y[0] < y2))	//(2,2) ����
        {

        }
        if ((tp_dev.x[0] > x2) && (tp_dev.x[0] < x3) && (tp_dev.y[0] > y1) && (tp_dev.y[0] < y2))	//(2,3) ����
        {

        }
        if ((tp_dev.x[0] > x3) && (tp_dev.x[0] < x4) && (tp_dev.y[0] > y1) && (tp_dev.y[0] < y2))	//(2,4) ��ֱ��
        {

        }
        if ((tp_dev.x[0] > x0) && (tp_dev.x[0] < x1) && (tp_dev.y[0] > y2) && (tp_dev.y[0] < y3))	//(3,1) ���ǲ�
        {

        }
        if ((tp_dev.x[0] > x1) && (tp_dev.x[0] < x2) && (tp_dev.y[0] > y2) && (tp_dev.y[0] < y3))	//(3,2) Ƶ��+
        {

        }
        if ((tp_dev.x[0] > x2) && (tp_dev.x[0] < x3) && (tp_dev.y[0] > y2) && (tp_dev.y[0] < y3))	//(3,3) ����+
        {

        }
        if ((tp_dev.x[0] > x3) && (tp_dev.x[0] < x4) && (tp_dev.y[0] > y2) && (tp_dev.y[0] < y3))	//(3,4) ֱ��+
        {

        }
        if ((tp_dev.x[0] > x0) && (tp_dev.x[0] < x1) && (tp_dev.y[0] > y3) && (tp_dev.y[0] < y4))	//(4,1) ����
        {

        }
        if ((tp_dev.x[0] > x1) && (tp_dev.x[0] < x2) && (tp_dev.y[0] > y3) && (tp_dev.y[0] < y4))	//(4,2) Ƶ��-
        {

        }
        if ((tp_dev.x[0] > x2) && (tp_dev.x[0] < x3) && (tp_dev.y[0] > y3) && (tp_dev.y[0] < y4))	//(4,3) ����-
        {

        }
        if ((tp_dev.x[0] > x3) && (tp_dev.x[0] < x4) && (tp_dev.y[0] > y3) && (tp_dev.y[0] < y4))	//(4,4) ֱ��-
        {

        }
    }
}

//ʾ���� ADC
void GUI_scan_1(void)
{
    LCD_Display_Dir(1);//����
    tp_dev.scan(0); 	//����ͨ��ɨ��
    if ((tp_dev.sta & 0x80))	//������������
    {
//		TP_Draw_Big_Point(tp_dev.x[0],tp_dev.y[0],BLUE);		//��ͼ just for test
        if ((tp_dev.x[0] > x0) && (tp_dev.x[0] < x1) && (tp_dev.y[0] > y0) && (tp_dev.y[0] < y1))	//(1,1) ����
        {

        }
        if ((tp_dev.x[0] > x0) && (tp_dev.x[0] < x1) && (tp_dev.y[0] > y1) && (tp_dev.y[0] < y2))	//(1,2) ������
        {
            GUI_change_Lock_phase();
        }
        if ((tp_dev.x[0] > x0) && (tp_dev.x[0] < x1) && (tp_dev.y[0] > y2) && (tp_dev.y[0] < y3))	//(1,3) ��ƽ��
        {
            GUI_Lock_up();
        }
        if ((tp_dev.x[0] > x0) && (tp_dev.x[0] < x1) && (tp_dev.y[0] > y3) && (tp_dev.y[0] < y4))	//(1,4) ��ƽ��
        {
            GUI_Lock_down();
        }
        if ((tp_dev.x[0] > x1) && (tp_dev.x[0] < x2) && (tp_dev.y[0] > y0) && (tp_dev.y[0] < y1))	//(2,1) ����
        {
            Auto_set();
        }
        if ((tp_dev.x[0] > x1) && (tp_dev.x[0] < x2) && (tp_dev.y[0] > y1) && (tp_dev.y[0] < y2))	//(2,2) ����
        {
            Auto_set();
        }
        if ((tp_dev.x[0] > x1) && (tp_dev.x[0] < x2) && (tp_dev.y[0] > y2) && (tp_dev.y[0] < y3))	//(2,3) ʱ��+
        {
            ADC_Fr_dec();
        }
        if ((tp_dev.x[0] > x1) && (tp_dev.x[0] < x2) && (tp_dev.y[0] > y3) && (tp_dev.y[0] < y4))	//(2,4) ʱ��-
        {
            ADC_Fr_plus();
        }
        if ((tp_dev.x[0] > x2) && (tp_dev.x[0] < x3) && (tp_dev.y[0] > y0) && (tp_dev.y[0] < y1))	//(3,1) ����
        {

        }
        if ((tp_dev.x[0] > x2) && (tp_dev.x[0] < x3) && (tp_dev.y[0] > y1) && (tp_dev.y[0] < y2))	//(3,2) ����
        {

        }
        if ((tp_dev.x[0] > x2) && (tp_dev.x[0] < x3) && (tp_dev.y[0] > y2) && (tp_dev.y[0] < y3))	//(3,3) ����+
        {

        }
        if ((tp_dev.x[0] > x2) && (tp_dev.x[0] < x3) && (tp_dev.y[0] > y3) && (tp_dev.y[0] < y4))	//(3,4) ����-
        {

        }
        if ((tp_dev.x[0] > x3) && (tp_dev.x[0] < x4) && (tp_dev.y[0] > y0) && (tp_dev.y[0] < y1))	//(4,1) gear0
        {
            ADC_change_gear(0);
        }
        if ((tp_dev.x[0] > x3) && (tp_dev.x[0] < x4) && (tp_dev.y[0] > y1) && (tp_dev.y[0] < y2))	//(4,2) gear1
        {
            ADC_change_gear(1);
        }
        if ((tp_dev.x[0] > x3) && (tp_dev.x[0] < x4) && (tp_dev.y[0] > y2) && (tp_dev.y[0] < y3))	//(4,3) gear2
        {
            ADC_change_gear(2);
        }
        if ((tp_dev.x[0] > x3) && (tp_dev.x[0] < x4) && (tp_dev.y[0] > y3) && (tp_dev.y[0] < y4))	//(4,4) gear3
        {
            ADC_change_gear(3);
        }
    }
}

//u16 i = 0;
//u8 flag = 0;
//u8 LeftorRight_Val = 0;
int UporDown_Val = 0;
//u8 AnyWaveTab[256] = {0};
//double DisplayCoefficient = 0.6;    //ϵ������� = 240/255
u16 Displacement = 0;//λ��

/*
//���Ҳ�
void GUI_draw_sin(void)
{
    POINT_COLOR = BLUE;         //��������Ϊ��ɫ
    Displacement = 120 - 128 * DisplayCoefficient;
    LCD_Display_Dir(1);//����
    for ( i = 0; i < 300; i++)
    {
        LCD_Fast_DrawPoint(i + 10, (AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val), WHITE); //����ϴβ���
        LCD_DrawPoint(i + 10, ((sin_wave[i % 256] >> 4) * DisplayCoefficient + Displacement)); //�����Ҳ������Ҳ����������0xff����С0x00,�м�ֵ0x80��Ҫ���м�ֵ��ͼ�����м�λ�ü�y����=570������128+442=570
    }
    LeftorRight_Val = 0;                     //����λ״̬��0
    UporDown_Val = 0;
    for (i = 0; i < 256; i++)                //�洢��ǰ�������ݵ�����AnyWaveTab[]��
    {
        AnyWaveTab[i] = (sin_wave[i] >> 4);
    }
//    LED0 = (!LED0);
}

//��ݲ�
void GUI_draw_triangle(void)
{
    POINT_COLOR = BLUE;         //��������Ϊ��ɫ
    Displacement = 120 - 128 * DisplayCoefficient;
    LCD_Display_Dir(1);//����
    for ( i = 0; i < 300; i++)
    {
        LCD_Fast_DrawPoint(i + 10, (AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val), WHITE); //����ϴβ���
        LCD_DrawPoint(i + 10, ((triangle_wave[i % 256] >> 4) * DisplayCoefficient + Displacement)); //�����Ҳ������Ҳ����������0xff����С0x00,�м�ֵ0x80��Ҫ���м�ֵ��ͼ�����м�λ�ü�y����=570������128+442=570
    }
    LeftorRight_Val = 0;                     //����λ״̬��0
    UporDown_Val = 0;
    for (i = 0; i < 256; i++)                //�洢��ǰ�������ݵ�����AnyWaveTab[]��
    {
        AnyWaveTab[i] = (triangle_wave[i] >> 4);
    }
//    LED0 = (!LED0);
}

//���ǲ�
void GUI_draw_sawtooth(void)
{
    POINT_COLOR = BLUE;         //��������Ϊ��ɫ
    Displacement = 120 - 128 * DisplayCoefficient;
    LCD_Display_Dir(1);//����
    for ( i = 0; i < 300; i++)
    {
        LCD_Fast_DrawPoint(i + 10, (AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val), WHITE); //����ϴβ���
        LCD_DrawPoint(i + 10, ((sawtooth_wave[i % 256] >> 4) * DisplayCoefficient + Displacement)); //�����Ҳ������Ҳ����������0xff����С0x00,�м�ֵ0x80��Ҫ���м�ֵ��ͼ�����м�λ�ü�y����=570������128+442=570
    }
    LeftorRight_Val = 0;                     //����λ״̬��0
    UporDown_Val = 0;
    for (i = 0; i < 256; i++)                //�洢��ǰ�������ݵ�����AnyWaveTab[]��
    {
        AnyWaveTab[i] = (sawtooth_wave[i] >> 4);
    }
//    LED0 = (!LED0);
}

//����
void GUI_draw_square(void)
{
    POINT_COLOR = BLUE;         //��������Ϊ��ɫ
    Displacement = 120 - 128 * DisplayCoefficient;
    LCD_Display_Dir(1);//����
    for ( i = 0; i < 300; i++)
    {
        LCD_Fast_DrawPoint(i + 10, (AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val), WHITE); //����ϴβ���
        LCD_DrawPoint(i + 10, ((rectangular_wave[i % 256] >> 4) * DisplayCoefficient + Displacement)); //�����Ҳ������Ҳ����������0xff����С0x00,�м�ֵ0x80��Ҫ���м�ֵ��ͼ�����м�λ�ü�y����=570������128+442=570
    }
    LeftorRight_Val = 0;                     //����λ״̬��0
    UporDown_Val = 0;
    for (i = 0; i < 256; i++)                //�洢��ǰ�������ݵ�����AnyWaveTab[]��
    {
        AnyWaveTab[i] = (rectangular_wave[i] >> 4);
    }
//    LED0 = (!LED0);
}

//����
void GUI_draw_left(void)
{
    POINT_COLOR = BLUE;         //��������Ϊ��ɫ
    Displacement = 120 - 128 * DisplayCoefficient;
    LCD_Display_Dir(1);//����
    for ( i = 0; i < 300; i++)
    {
        LCD_Fast_DrawPoint(i + 10, (AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val), WHITE); //����ϴβ���
        if (((AnyWaveTab[(i + LeftorRight_Val + LeftorRight_Num) % 256] * DisplayCoefficient + Displacement + UporDown_Val) > 10) && ((AnyWaveTab[(i + LeftorRight_Val + LeftorRight_Num) % 256] * DisplayCoefficient + Displacement + UporDown_Val) < 230))
        {
            LCD_DrawPoint(i + 10, (AnyWaveTab[(i + LeftorRight_Val + LeftorRight_Num) % 256] * DisplayCoefficient + Displacement + UporDown_Val)); //�����Ҳ������Ҳ����������0xff����С0x00,�м�ֵ0x80��Ҫ���м�ֵ��ͼ�����м�λ�ü�y����=570������128+442=570
        }
    }
    LeftorRight_Val = LeftorRight_Val + LeftorRight_Num;
//    LED0 = (!LED0);
}

//����
void GUI_draw_right(void)
{
    POINT_COLOR = BLUE;         //��������Ϊ��ɫ
    Displacement = 120 - 128 * DisplayCoefficient;
    LCD_Display_Dir(1);//����
    for ( i = 0; i < 300; i++)
    {
        LCD_Fast_DrawPoint(i + 10, (AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val), WHITE); //����ϴβ���
        if (((AnyWaveTab[(i + LeftorRight_Val - LeftorRight_Num) % 256] * DisplayCoefficient + Displacement + UporDown_Val) > 10) && ((AnyWaveTab[(i + LeftorRight_Val - LeftorRight_Num) % 256] * DisplayCoefficient + Displacement + UporDown_Val) < 230))
        {
            LCD_DrawPoint(i + 10, (AnyWaveTab[(i + LeftorRight_Val - LeftorRight_Num) % 256] * DisplayCoefficient + Displacement + UporDown_Val)); //�����Ҳ������Ҳ����������0xff����С0x00,�м�ֵ0x80��Ҫ���м�ֵ��ͼ�����м�λ�ü�y����=570������128+442=570
        }
    }
    LeftorRight_Val = LeftorRight_Val - LeftorRight_Num;
//    LED0 = (!LED0);
}

//����
void GUI_draw_up(void)
{
    POINT_COLOR = BLUE;         //��������Ϊ��ɫ
    Displacement = 120 - 128 * DisplayCoefficient;
    LCD_Display_Dir(1);//����
    for ( i = 0; i < 300; i++)
    {
        LCD_Fast_DrawPoint(i + 10, (AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val), WHITE); //����ϴβ���
        if (((AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val - UporDown_Num) > 10) && ((AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val - UporDown_Num) < 230))
        {
            LCD_DrawPoint(i + 10, (AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val - UporDown_Num)); //�����Ҳ������Ҳ����������0xff����С0x00,�м�ֵ0x80��Ҫ���м�ֵ��ͼ�����м�λ�ü�y����=570������128+442=570
            flag = 1;
        }
    }
    if (flag)
    {
        UporDown_Val = UporDown_Val - UporDown_Num;
        flag = 0;
    }
//    LED0 = (!LED0);
}

//����
void GUI_draw_down(void)
{
    POINT_COLOR = BLUE;         //��������Ϊ��ɫ
    Displacement = 120 - 128 * DisplayCoefficient;
    LCD_Display_Dir(1);//����
    for ( i = 0; i < 300; i++)
    {
        LCD_Fast_DrawPoint(i + 10, (AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val), WHITE); //����ϴβ���
        if (((AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val + UporDown_Num) > 10) && ((AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val + UporDown_Num) < 230))
        {
            LCD_DrawPoint(i + 10, (AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val + UporDown_Num)); //�����Ҳ������Ҳ����������0xff����С0x00,�м�ֵ0x80��Ҫ���м�ֵ��ͼ�����м�λ�ü�y����=570������128+442=570
            flag = 1;
        }
    }
    if (flag)
    {
        UporDown_Val = UporDown_Val + UporDown_Num;
        flag = 0;
    }
//    LED0 = (!LED0);
}

//����ǰ����
void GUI_draw_AnyWave(void)
{
    POINT_COLOR = BLUE;         //��������Ϊ��ɫ
    Displacement = 120 - 128 * DisplayCoefficient;
    LCD_Display_Dir(1);//����
    for ( i = 0; i < 300; i++)
    {
        LCD_Fast_DrawPoint(i + 10, (AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val), WHITE); //����ϴβ���
        if (((AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val + UporDown_Num) > 10) && ((AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val + UporDown_Num) < 230))
        {
            LCD_DrawPoint(i + 10, (AnyWaveTab[i % 256] * DisplayCoefficient + Displacement));
//          LCD_DrawPoint(i+10,(AnyWaveTab[(i + LeftorRight_Val)%256] * DisplayCoefficient + Displacement + UporDown_Val + UporDown_Num));  //�����Ҳ������Ҳ����������0xff����С0x00,�м�ֵ0x80��Ҫ���м�ֵ��ͼ�����м�λ�ü�y����=570������128+442=570
        }
    }
//    LED0 = (!LED0);
}
*/

//
//������صı���
u16 Lock_start_num = 0; //������ ������ʼλ��
u16 Lock_value = 0x0800;        //����ֵ     //just for test
u8 Lock_phase = 0;      //��������λ��0Ϊ������1Ϊ�½�
u8 Lock_done = 0;       //�����ɹ�


//��ADC����
u16 AdcWaveTab[300] = {0};
u8 lastAdcWaveValue = 0;
u8 currcetAdcWaveValue = 0;
void GUI_draw_AdcWave(void)
{
    uint16_t draw_adc_i = 0;
    if (UpdatTrue == 0xff)
    {
        UpdatTrue = 0;

        GUI_signal_processing();    //AD���ݴ���

        GUI_Lock(); //��������

        LCD_Display_Dir(1);//����
        //������λ��
        POINT_COLOR = YELLOW;
        LCD_DrawLine(10, ((0xFFF - Lock_value) >> 4), 310, ((0xFFF - Lock_value) >> 4));

        POINT_COLOR = BLUE;         //��������Ϊ��ɫ
        Displacement = 120 - 64;
        for ( draw_adc_i = 0; draw_adc_i < 300; draw_adc_i++)
        {
            lastAdcWaveValue = ((0xFFF - AdcWaveTab[draw_adc_i]) >> 4) * 200 / 256 + 20; //�ϴε����
            currcetAdcWaveValue = ((0xFFF - ADCConvertedValue[draw_adc_i + Lock_start_num]) >> 4) * 200 / 256 + 20; //�ϴε����

            LCD_Fast_DrawPoint(draw_adc_i + 10, lastAdcWaveValue, WHITE); //����ϴβ���
            LCD_Fast_DrawPoint(draw_adc_i + 10, lastAdcWaveValue - 1, WHITE); //����ϴβ���
            LCD_Fast_DrawPoint(draw_adc_i + 10, lastAdcWaveValue + 1, WHITE); //����ϴβ���

            POINT_COLOR = BLUE;         //��������Ϊ��ɫ
            LCD_DrawPoint(draw_adc_i + 10, currcetAdcWaveValue); //����
            LCD_DrawPoint(draw_adc_i + 10, currcetAdcWaveValue - 1); //����
            LCD_DrawPoint(draw_adc_i + 10, currcetAdcWaveValue + 1); //����
            AdcWaveTab[draw_adc_i] = ADCConvertedValue[draw_adc_i + Lock_start_num];
        }

//        TIM_Cmd(TIM3, ENABLE);
//      for (draw_adc_i = 0; draw_adc_i < 256; draw_adc_i++)                //�洢��ǰ�������ݵ�����AdcWaveTab[]��
//      {
//          AdcWaveTab[draw_adc_i] = ADCConvertedValue[draw_adc_i];
//      }
        // LED0 = (!LED0);
    }
}

//��������
void GUI_Lock(void)
{
    uint16_t i = 0;
    Lock_done = 0;
    for ( i = 0; i < (SAMPDEPTH - 300); i++)
    {
        if (Lock_phase == 0)    //����
        {
            if ((ADCConvertedValue[i] <= (Lock_value + 1)) && (ADCConvertedValue[i + 1] <= (Lock_value + 1)))
            {
                if ((ADCConvertedValue[i + 2] >= (Lock_value - 1)) && (ADCConvertedValue[i + 3] >= (Lock_value - 1)))
                {
                    Lock_start_num = i + 1;
                    Lock_done = 1;
                    break;
                }
            }
        }
        else
        {
            if ((ADCConvertedValue[i] >= (Lock_value - 1)) && (ADCConvertedValue[i + 1] >= (Lock_value - 1)))
            {
                if ((ADCConvertedValue[i + 2] <= (Lock_value + 1)) && (ADCConvertedValue[i + 3] <= (Lock_value + 1)))
                {
                    Lock_start_num = i + 1;
                    Lock_done = 1;
                    break;
                }
            }
        }
    }
    if (Lock_done == 0)
    {
        Lock_start_num = 0;
    }
    // printf("%d\n", Lock_start_num);
    if (Lock_start_num == 0)
    {
        printf("lock failed!\n");
    }
    else if (Lock_start_num > 300)
    {
        printf("error!\n");
    }
}

void GUI_Lock_up(void)
{
    //�����λ��
    LCD_Display_Dir(1);//����
    POINT_COLOR = WHITE;
    LCD_DrawLine(10, ((0xFFF - Lock_value) >> 4), 310, ((0xFFF - Lock_value) >> 4));

    Lock_value += 10;
}

void GUI_Lock_down(void)
{
    //�����λ��
    LCD_Display_Dir(1);//����
    POINT_COLOR = WHITE;
    LCD_DrawLine(10, ((0xFFF - Lock_value) >> 4), 310, ((0xFFF - Lock_value) >> 4));

    Lock_value -= 10;
}

void GUI_change_Lock_phase(void)
{
    if (Lock_phase == 1)
    {
        Lock_phase = 0;
    }
    else if (Lock_phase == 0)
    {
        Lock_phase = 1;
    }
    else
    {
        Lock_phase = 0;
    }
}


extern u32 FreqExtCounter;
extern u32 FreqVal;
extern u32 FreqVal1;
extern u8 refresh_flag;	//������timer.h

u16 cYmax=0;  //���ֵ
u16 cYmin=3.3;  //��Сֵ
u16 cYavr;  //��ֵ
float ADmax;
float ADmin;
float ADmen;
float ADcycle;	//����
//u16 ADCConvertedValue_new[SAMPDEPTH];
float DCmV3 = 0, freq3 = 0, cycle3 = 0, phase3 = 0, scope3 = 0; //����

u8 *lp; //�ַ���
u8 callbuf[33];
u8 max_flag=0;
void GUI_signal_processing(void)
{
    //AD�������ݴ���
    u16  k, cY1 = 0, cY2 = 0;
	u16 cYmax1, cYmax2, cYmax3;
	u16 cYmin1, cYmin2, cYmin3;
max_flag=1;
    for (k = 1; k < SAMPDEPTH; k++) {
        ADCConvertedValue[k] = (ADCConvertedValue[k] + ADCConvertedValue[k - 1]) / 2;   //ƽ���˲�
    }
    cYmax = ADCConvertedValue[0];
    cYmin = ADCConvertedValue[0];
    for (k = 0; k < SAMPDEPTH; k++) {
        if (cYmax <= ADCConvertedValue[k])	cYmax = ADCConvertedValue[k];  //�����ݵ����ֵ
        if (cYmin >= ADCConvertedValue[k])  cYmin = ADCConvertedValue[k];  //�����ݵ���Сֵ
    }
	
    cY2 = cY1;
    cY1 = cYmin + (cYmax - cYmin) / 2;
    cYavr = (cY1 + cY2) / 2;     		//������ݵ�ƽ��ֵ

    ADmax = (float)(cYmax * 3300.0) / (4096.0); //mVp ���ֵ
    ADmin = (float)(cYmin * 3300.0) / (4096.0); //mVp ��Сֵ
    ADmen = (float)(cYavr * 3300.0) / (4096.0); //mVp ƽ��ֵ
    ADcycle = (float)(1000000.0 / FreqVal);

//	printf("max = %6.2f, min = %6.1f, men = %6.1f\n", ADmax, ADmin, ADmen);	//just for test

	/*
///////////////////////////////////////////////////////////////////////////////
////�����ֵ����Сֵ�����ֵ
////һ������
///////////////////////////////////////////////////////////////////////////////
    cYmax1 = ADCConvertedValue[0];
    cYmin1 = ADCConvertedValue[0];
	for(k = 0; k < 512; k++){
        if (cYmax1 <= ADCConvertedValue[k])	cYmax1 = ADCConvertedValue[k];  //�����ݵ����ֵ
        if (cYmin1 >= ADCConvertedValue[k])  cYmin1 = ADCConvertedValue[k];  //�����ݵ���Сֵ
	}
	
///////////////////////////////////////////////////////////////////////////////
////�����ֵ����Сֵ�����ֵ
////��������
///////////////////////////////////////////////////////////////////////////////
    cYmax2 = ADCConvertedValue[256];
    cYmin2 = ADCConvertedValue[256];
	for(k = 256; k < 768; k++){
        if (cYmax2 <= ADCConvertedValue[k])	cYmax2 = ADCConvertedValue[k];  //�����ݵ����ֵ
        if (cYmin2 >= ADCConvertedValue[k])  cYmin2 = ADCConvertedValue[k];  //�����ݵ���Сֵ
	}	
	
///////////////////////////////////////////////////////////////////////////////
////�����ֵ����Сֵ�����ֵ
////��������
///////////////////////////////////////////////////////////////////////////////
    cYmax3 = ADCConvertedValue[512];
    cYmin3 = ADCConvertedValue[512];
	for(k = 512; k < 1024; k++){
        if (cYmax3 <= ADCConvertedValue[k])	cYmax3 = ADCConvertedValue[k];  //�����ݵ����ֵ
        if (cYmin3 >= ADCConvertedValue[k])  cYmin3 = ADCConvertedValue[k];  //�����ݵ���Сֵ
	}
	
///////////////////////////////////////////////////////////////////////////////
////�����ֵ����Сֵ�����ֵ
////���������ֵ���Ƚ�
///////////////////////////////////////////////////////////////////////////////
	if ((fabs(cYmax2 - cYmax1) / cYmax1) <= 0.002)	//2
    {
		cYmax = (cYmax1/2) + (cYmax2/2);
//		cYmax = cYmax1;
    } else if ((fabs(cYmax3 - cYmax2) / cYmax2) <= 0.002)	//1
    {
		cYmax = (cYmax3/2) + (cYmax2/2);
//		cYmax = cYmax2;
    } else if ((fabs(cYmax1 - cYmax3) / cYmax3) <= 0.002)	//2
    {
		cYmax = (cYmax1/2) + (cYmax3/2);
//		cYmax = cYmax3;
    }
	
	if ((fabs(cYmin2 - cYmin1) / cYmin1) <= 0.002)	//2
    {
		cYmin = (cYmin1/2) + (cYmin2/2);
    } else if ((fabs(cYmin3 - cYmin2) / cYmin2) <= 0.002)	//1
    {
		cYmin = (cYmin3/2) + (cYmin2/2);
    } else if ((fabs(cYmin1 - cYmin3) / cYmin3) <= 0.002)	//2
    {
		cYmin = (cYmin1/2) + (cYmin3/2);
    }
		
    cY2 = cY1;
    cY1 = cYmin + (cYmax - cYmin) / 2;
    cYavr = (cY1 + cY2) / 2;     		//������ݵ�ƽ��ֵ
	
	printf("max = %d, min = %6d, men = %d\r\n", cYmax, cYmin, cYavr);	//just for test
	
    ADmax = (float)(cYmax * 3300.0) / (4096.0); //mVp ���ֵ
    ADmin = (float)(cYmin * 3300.0) / (4096.0); //mVp ��Сֵ
    ADmen = (float)(cYavr * 3300.0) / (4096.0); //mVp ƽ��ֵ
    ADcycle = (float)(1000000.0 / FreqVal);

*/
//	printf("max = %6.2f, min = %6.1f, men = %6.1f\n", ADmax, ADmin, ADmen);	//just for test
	
//		LCD_ShowxNum(165, 34 + 28 * 0, cYmax, 6, 16, 0); //��ʾYmax
//		LCD_ShowxNum(165, 34 + 28 * 1, cYavr, 6, 16, 0); //��ʾYmid

///////////////////////////////////////////////////////////////////////////////
////������������ڡ�Ƶ�ʵȲ���
///////////////////////////////////////////////////////////////////////////////

//    //�޷��Ŵ󣬰����Ҳ��Ŵ�ɷ���
//    for (t = 0; t < SAMPDEPTH; t++)
//        if (ADCConvertedValue[t] >= cYavr) {
//            ADCConvertedValue_new[t] = 2048;
//        }
//        else {
//            ADCConvertedValue_new[t] = 1024;
//        }
//    //���źŵĹ�0��λ��
//    for (t = 0; t < SAMPDEPTH; t++) //��Ƶ��
//        if ((ADCConvertedValue_new[t] == 1024) & (ADCConvertedValue_new[t + 1] == 2048)) {
//            eK = t + 1;    //0��λ�㣨�����㣩
//            break;
//        }
//    for (t = eK + 1; t < SAMPDEPTH; t++)
//        if ((ADCConvertedValue_new[t] == 2048) & (ADCConvertedValue_new[t + 1] == 1024)) {
//            bK = t + 1;    //180�ȵ㣨�½��㣩
//            break;
//        }
//    for (t = bK + 1; t < SAMPDEPTH; t++)
//        if ((ADCConvertedValue_new[t] == 1024) & (ADCConvertedValue_new[t + 1] == 2048)) {
//            cK = t + 1;    //360�ȵ�=0�ȵ㣨�����㣩
//            break;
//        }
//    //�󴥷���λ�㣬��eK��������ƽ�����λ��
//    if ((Lock_value <= cYmax) & (Lock_value >= cYmin))
//    {
//        if (Lock_phase == 0) //��������
//        {
//            for (t = eK + 1; t < SAMPDEPTH; t++)
//                if ((ADCConvertedValue[t] <= Lock_value) & (ADCConvertedValue[t + 1] >= Lock_value)) {
//                    dK = t;
//                    break;
//                }
//        } else //�½�����
//            for (t = eK + 1; t < SAMPDEPTH; t++)
//                if ((ADCConvertedValue[t] >= Lock_value) & (ADCConvertedValue[t + 1] <= Lock_value)) {
//                    dK = t;
//                    break;
//                }
//    } else dK = eK;
///////////////////////////////////////////////////////////////////////////////////////
////�������㣬���ڡ�Ƶ�ʵȲ�������Ҫ���ø�������
//////////////////////////////////////////////////////////////////////////////////////
//    cycle = (float)(1000.0 * (float)(cK - eK) * (arr_ADC) * (psc_ADC) / (72 * 1000.0)); //T=(arr+1)(psc+1)/72 us
//    freq = (1000000 * 1000 / (float)cycle) / 1000; //Hz
//    phase = (float)(360 * (float)fabs((float)(dK - eK) * 1000 / (cK - eK))) / 1000;
//    scope = (float)((cYmax - cYmin) * 3300) / (2 * 4096); //mVp
//    DCmV = (float)((cYavr) * 3300) / (2 * 4096); //mVp

////�������

//    //���źŵĹ�0��λ��
//    for (t = 200; t < SAMPDEPTH; t++) //��Ƶ��
//        if ((ADCConvertedValue_new[t] == 1024) & (ADCConvertedValue_new[t + 1] == 2048)) {
//            eK = t + 1;    //0��λ�㣨�����㣩
//            break;
//        }
//    for (t = eK + 1; t < SAMPDEPTH; t++)
//        if ((ADCConvertedValue_new[t] == 2048) & (ADCConvertedValue_new[t + 1] == 1024)) {
//            bK = t + 1;    //180�ȵ㣨�½��㣩
//            break;
//        }
//    for (t = bK + 1; t < SAMPDEPTH; t++)
//        if ((ADCConvertedValue_new[t] == 1024) & (ADCConvertedValue_new[t + 1] == 2048)) {
//            cK = t + 1;    //360�ȵ�=0�ȵ㣨�����㣩
//            break;
//        }
//    //�󴥷���λ�㣬��eK��������ƽ�����λ��
//    if ((Lock_value <= cYmax) & (Lock_value >= cYmin))
//    {
//        if (Lock_phase == 0) //��������
//        {
//            for (t = eK + 1; t < SAMPDEPTH; t++)
//                if ((ADCConvertedValue[t] <= Lock_value) & (ADCConvertedValue[t + 1] >= Lock_value)) {
//                    dK = t;
//                    break;
//                }
//        } else //�½�����
//            for (t = eK + 1; t < SAMPDEPTH; t++)
//                if ((ADCConvertedValue[t] >= Lock_value) & (ADCConvertedValue[t + 1] <= Lock_value)) {
//                    dK = t;
//                    break;
//                }
//    } else dK = eK;
///////////////////////////////////////////////////////////////////////////////////////
////�������㣬���ڡ�Ƶ�ʵȲ�������Ҫ���ø�������
//////////////////////////////////////////////////////////////////////////////////////
//    cycle1 = (float)(1000.0 * (float)(cK - eK) * (arr_ADC) * (psc_ADC) / (72 * 1000.0)); //T=(arr+1)(psc+1)/72 us
//    freq1 = (1000000 * 1000 / (float)cycle1) / 1000.0; //Hz
//    phase1 = (float)(360 * (float)fabs((float)(dK - eK) * 1000 / (cK - eK))) / 1000;
//    scope1 = (float)((cYmax - cYmin) * 3300) / (4096); //mVp
//    DCmV1 = (float)((cYavr) * 3300) / (4096); //mVp

////�������

//    //���źŵĹ�0��λ��
//    for (t = 400; t < SAMPDEPTH; t++) //��Ƶ��
//        if ((ADCConvertedValue_new[t] == 1024) & (ADCConvertedValue_new[t + 1] == 2048)) {
//            eK = t + 1;    //0��λ�㣨�����㣩
//            break;
//        }
//    for (t = eK + 1; t < SAMPDEPTH; t++)
//        if ((ADCConvertedValue_new[t] == 2048) & (ADCConvertedValue_new[t + 1] == 1024)) {
//            bK = t + 1;    //180�ȵ㣨�½��㣩
//            break;
//        }
//    for (t = bK + 1; t < SAMPDEPTH; t++)
//        if ((ADCConvertedValue_new[t] == 1024) & (ADCConvertedValue_new[t + 1] == 2048)) {
//            cK = t + 1;    //360�ȵ�=0�ȵ㣨�����㣩
//            break;
//        }
//    //�󴥷���λ�㣬��eK��������ƽ�����λ��
//    if ((Lock_value <= cYmax) & (Lock_value >= cYmin))
//    {
//        if (Lock_phase == 0) //��������
//        {
//            for (t = eK + 1; t < SAMPDEPTH; t++)
//                if ((ADCConvertedValue[t] <= Lock_value) & (ADCConvertedValue[t + 1] >= Lock_value)) {
//                    dK = t;
//                    break;
//                }
//        } else //�½�����
//            for (t = eK + 1; t < SAMPDEPTH; t++)
//                if ((ADCConvertedValue[t] >= Lock_value) & (ADCConvertedValue[t + 1] <= Lock_value)) {
//                    dK = t;
//                    break;
//                }
//    } else dK = eK;
///////////////////////////////////////////////////////////////////////////////////////
////�������㣬���ڡ�Ƶ�ʵȲ�������Ҫ���ø������㣬�����ȶ�����
//////////////////////////////////////////////////////////////////////////////////////
//    cycle2 = (float)(1000 * (float)(cK - eK) * (arr_ADC) * (psc_ADC) / (72 * 1000)); //T=(arr+1)(psc+1)/72 us
//    freq2 = (1000000 * 1000 / (float)cycle2) / 1000; //Hz
//    phase2 = (float)(360 * (float)fabs((float)(dK - eK) * 1000 / (cK - eK))) / 1000;
//    scope2 = (float)((cYmax - cYmin) * 3300) / (2 * 4096); //mVp
//    DCmV2 = (float)((cYavr) * 3300) / (2 * 4096); //mVp

//    if ((fabs(cycle1 - cycle) / cycle) <= 0.002)
//    {
//        cycle3 = cycle; //us
//        freq3 = freq; //Hz
//    } else if ((fabs(cycle2 - cycle) / cycle2) <= 0.002)
//    {
//        cycle3 = cycle2; //us
//        freq3 = freq2; //Hz
//    } else if ((fabs(cycle2 - cycle1) / cycle1) <= 0.002)
//    {
//        cycle3 = cycle1; //us
//        freq3 = freq1; //Hz
//    }
//    if ((fabs(phase1 - phase) / phase) <= 0.002)
//    {
//        phase3 = phase; //��
//    } else if ((fabs(phase2 - phase) / phase2) <= 0.002)
//    {
//        phase3 = phase2; //��
//    } else if ((fabs(phase2 - phase1) / phase1) <= 0.002)
//    {
//        phase3 = phase1; //��
//    }
//    scope3 = scope1; //mVp
//    DCmV3 = DCmV1; //mVp
}

extern float av;
void GUI_show_signal(void)
{
	float vpp;
    u32 temp = 0;
    lp = callbuf;

    if(refresh_flag) {
        refresh_flag = 0;

        POINT_COLOR = BLACK;
//		LCD_ShowxNum(165, 34 + 28 * 0, cYmax, 6, 16, 0); //��ʾYmax
//		LCD_ShowxNum(165, 34 + 28 * 1, cYavr, 6, 16, 0); //��ʾYmid
//		LCD_ShowxNum(20, 34 + 28 * 2, cYmin, 6, 16, 0); //��ʾYmin

        Show_Str(15, 40 + 28 * 0, 60, 16, "Ƶ  ��", 16, 1);
        //Show_Str(15, 40 + 28 * 1, 60, 16, "��  ��", 16, 1);
        //Show_Str(15, 40 + 28 * 2, 60, 16, "���ֵ", 16, 1);
        //Show_Str(15, 40 + 28 * 3, 60, 16, "��Сֵ", 16, 1);
        Show_Str(15, 40 + 28 * 4, 60, 16, "�������ֵ", 16, 1);

        LCD_Fill(70, 40 + 28 * 0, 70 + 100, 40 + 28 * 0 + 24, WHITE); //��ʾƵ��
        sprintf((char*)lp, "%6.1f Hz", (float)FreqVal);
        Show_Str(70, 40 + 28 * 0, 100, 16, lp, 16, 1);

       /* LCD_Fill(70, 40 + 28 * 1, 70 + 100, 40 + 28 * 1 + 24, WHITE); //��ʾ����
        sprintf((char*)lp, "%6.1f us", ADcycle);
        Show_Str(70, 40 + 28 * 1, 100, 16, lp, 16, 1);

        LCD_Fill(70, 40 + 28 * 2, 70 + 100, 40 + 28 * 2 + 24, WHITE); //��ʾ���ֵ
        sprintf((char*)lp, "%6.1f mVp", ADmax);
        Show_Str(70, 40 + 28 * 2, 100, 16, lp, 16, 1);

        LCD_Fill(70, 40 + 28 * 3, 70 + 100, 40 + 28 * 3 + 24, WHITE); //��ʾ��Сֵ
        sprintf((char*)lp, "%6.1f mVp", ADmin);
        Show_Str(70, 40 + 28 * 3, 100, 16, lp, 16, 1);*/
vpp=ADmax-ADmin;
vpp=(2.93*0.002189*vpp-0.00421*FreqVal)*0.066;
        LCD_Fill(70, 40 + 28 * 4, 70 + 100, 40 + 28 * 4 + 24, WHITE); //��ʾ���ֵ
        sprintf((char*)lp, "%6.1f A", vpp);
        Show_Str(70, 40 + 28 * 4, 100, 16, lp, 16, 1);


        ////////////////////////////////////////////////////////////////////
        ////�����Ȳ������ߵ�ƽ����T5�������񣬴����������
        ////////////////////////////////////////////////////////////////////
        if(TIM5CH1_CAPTURE_STA & 0X80) //�ɹ�������һ��������
        {
            temp = TIM5CH1_CAPTURE_STA & 0X3F;
            temp *= 65536; //���ʱ���ܺ�
            temp += TIM5CH1_CAPTURE_VAL; //�õ��ܵĸߵ�ƽʱ��

            TIM5CH1_CAPTURE_STA = 0; //������һ�β���
        }
        /////////////////////////////////////////////////////////////////////
        ////������ʾ��Ƶ�ʣ������ڣ�β��������
        ////////////////////////////////////////////////////////////////////

//		LCD_Fill(150, 34 + 28 * 0, 150 + 200, 34 + 28 * 0 + 24, WHITE); //��ʾƵ��
//		sprintf((char*)lp, "Frequence%6dHz", FreqVal);
//		Show_Str(150, 34 + 28 * 0, 150, 16, lp, 16, 1);

//		LCD_ShowNum(180, 34 + 28 * 0, FreqVal, 9, 16);
//		LCD_ShowNum(180, 34 + 28 * 1, FreqExtCounter, 9, 16);
//		LCD_ShowNum(180, 34 + 28 * 2, FreqVal1, 9, 16);
//		LCD_ShowNum(180, 34 + 28 * 3, temp + 2, 9, 16);
    }
}


u16 LCDout_sta = 0, LCD_data = 0;
u16 LCDout1[300];//�������������1
u16 LCDout2[300];//�������������2
u16 aX = 9, bX = 128, aY = 5, bY = 0, cY = 110; //XΪˮƽ���ƣ�YΪ��ֱ����,aΪ���ȿ��ƣ��Ŵ�ϵ������bΪ��λ���ƣ�1�����ƣ�0�����ƣ�,c�Ƿ���ƽ��ֵ
//u8 LCD_n = 0; //��ʾ����ѡ��
float fstep_pixel = 0; 	//ÿ��������֮���Ƶ�ʲ�	����Ƶ��/1024
u16 fstep_grid = 0;		//ÿ����֮���Ƶ�ʲ�        fstep_pixel * 30
//FFT�������������ݵ�usart1,
void GUI_show_FFT(void) {

    uint16_t show_fft_i = 0;
    if (UpdatTrue == 0xff)
    {
		UpdatTrue = 0;
        GUI_signal_processing();    //AD���ݴ���
		GUI_fft_harmonic();			//����г��
        for(show_fft_i = 0; show_fft_i < 1024; show_fft_i++)
        {
            input[2 * show_fft_i] = ADCConvertedValue[show_fft_i]; //���������ź�ʵ��
            input[2 * show_fft_i + 1] = 0; //�鲿ȫ��Ϊ0
        }
        cr4_fft_1024_stm32(output, input, 1024);

        /* ���ֵ */
        PowerMag(1024);
//			arm_cfft_radix4_f32(&scfft,fft_inputbuf);	//FFT���㣨��4��
//			arm_cmplx_mag_f32(fft_inputbuf,fft_outputbuf,FFT_LENGTH);	//��������������ģ�÷�ֵ
        /* ��ӡ������ */
//        printf("FFT Result:\r\n");
//        for (show_fft_i = 0; show_fft_i < 1024; show_fft_i++)
//        {
//            printf("fft_outputbuf[%d]:%6.2f\r\n", show_fft_i, Mag[show_fft_i]);
//        }
		
		
		GUI_fft_harmonic();			//����г��

        for(show_fft_i = 0; show_fft_i < 300; show_fft_i++) //װ��һ��LCD����
        {
            LCD_data = Mag[show_fft_i];
            LCD_data = (LCD_data >> 2); // + bY
            if((LCD_data) >= 224 - 28) LCD_data = 224 - 28; //�ܷ��Ȳ���>224,bYÿ��=8
            LCDout1[show_fft_i] = LCD_data;
            //        if((LCDout_sta + 1) % 2 == 0)LCDout1[show_fft_i] = LCD_data; //ż����LCDout1
            //        else LCDout2[show_fft_i] = LCD_data;
            /*
            	t++;
            	if(aX!=1)//��ֵ����
            		{
            		for(show_fft_i=1;show_fft_i<aX;show_fft_i++)
            			{
            			if(ADCin2[k+1]>=ADCin2[k]){LCD_data=ADCin2[k]+((ADCin2[k+1]-ADCin2[k])*show_fft_i/aX);}  //A[K+1]>A[K]
            			else                      {LCD_data=ADCin2[k]-((ADCin2[k]-ADCin2[k+1])*show_fft_i/aX);}   //A[K+1]<A[K]
            			LCD_data=LCD_data+bY;
            			if((LCD_data)>=360)LCD_data=359;  //�ܷ��Ȳ���>360,bYÿ��=10
            			if((LCDout_sta+1)%2==0)LCDout1[t]=LCD_data;  //ż����LCDout1
            			else LCDout2[t]=LCD_data;
            			t++;
            			}
            		}
            	k++;
            */
        }

        //    LCD_Clear(WHITE);
        //    LCDout_sta++;//�ڴ����齻��

            for(show_fft_i = 0; show_fft_i < 300; ++show_fft_i) //��ʾLCD����
            {
                //���ǰһ�β���
                POINT_COLOR = WHITE;
                LCD_DrawLine(10 + show_fft_i, (230 - 20) - LCDout2[show_fft_i], 10 + show_fft_i, 230 - 20); //��780������
                //����ǰ����
                POINT_COLOR = BLUE;
                LCD_DrawLine(10 + show_fft_i, (230 - 20) - LCDout1[show_fft_i], 10 + show_fft_i, 230 - 20); //��780������
                //����ǰ���δ���LCDout2
                LCDout2[show_fft_i] = LCDout1[show_fft_i];
            }


    }
}

//����г��
u8 FrcErrorValue = 5;
//u32 wave_value_0 = 0;	//
u32 wave_value_1 = 0;	//����
u32 wave_value_2 = 0;	//����г��
u32 wave_value_3 = 0;	//����г��
u32 wave_value_4 = 0;	//�Ĵ�г��
u32 wave_value_5 = 0;	//���г��
u32 wave_value_6 = 0;	//����г��
u32 wave_value_7 = 0;	//�ߴ�г��
u32 wave_value_8 = 0;	//�˴�г��
u32 wave_value_9 = 0;	//�Ŵ�г��
float V_value_1 = 0;	//����
float V_value_2 = 0;	//����г��
float V_value_3 = 0;	//����г��
float V_value_4 = 0;	//�Ĵ�г��
float V_value_5 = 0;	//���г��
float V_value_6 = 0;	//����г��
float V_value_7 = 0;	//�ߴ�г��
float V_value_8 = 0;	//�˴�г��
float V_value_9 = 0;	//�Ŵ�г��
void GUI_fft_harmonic(void){
//	uint32_t Mag[] ��ֵ
//	u32 FreqVal		Ƶ��
    //����̶�
    fstep_pixel = ADC_Fr / 512.0;	//ÿ��������֮���Ƶ�ʲ� ADC_Fr / 1024
    fstep_grid = fstep_pixel * 30; //ÿ����֮���Ƶ�ʲ�
//    printf("fstep_pixel = %f, fstep_grid = %d\n", fstep_pixel, fstep_grid);	//just for test
	wave_value_1 = FFT_FindMax(FreqVal,FrcErrorValue);
	wave_value_2 = FFT_FindMax(FreqVal*2,FrcErrorValue);
	wave_value_3 = FFT_FindMax(FreqVal*3,FrcErrorValue);
	wave_value_4 = FFT_FindMax(FreqVal*4,FrcErrorValue);
	wave_value_5 = FFT_FindMax(FreqVal*5,FrcErrorValue);
	wave_value_6 = FFT_FindMax(FreqVal*6,FrcErrorValue);
	wave_value_7 = FFT_FindMax(FreqVal*7,FrcErrorValue);
	wave_value_8 = FFT_FindMax(FreqVal*8,FrcErrorValue);
	wave_value_9 = FFT_FindMax(FreqVal*9,FrcErrorValue);
	V_value_1 = wave_value_1 * 3300.0 / 1024.0;
	V_value_2 = wave_value_2 * 3300.0 / 1024.0;
	V_value_3 = wave_value_3 * 3300.0 / 1024.0;
	V_value_4 = wave_value_4 * 3300.0 / 1024.0;
	V_value_5 = wave_value_5 * 3300.0 / 1024.0;
	V_value_6 = wave_value_6 * 3300.0 / 1024.0;
	V_value_7 = wave_value_7 * 3300.0 / 1024.0;
	V_value_8 = wave_value_8 * 3300.0 / 1024.0;
	V_value_9 = wave_value_9 * 3300.0 / 1024.0;
//	printf("value_1 = %d,value_2 = %d,value_3 = %d,value_4 = %d\r\n",wave_value_1,wave_value_2,wave_value_3,wave_value_4);
}

//����һ����Χ�ڵ����ֵ
uint32_t FFT_FindMax(u32 Frc, u8 error){
	uint32_t max_value = 0;
	u16 loop_i = 0;
	u16 frc_value = 0;
	u16 start_num = 0;
	u16 end_num = 0;
	
	frc_value = Frc * 512.0/ ADC_Fr;
	
	
	
	start_num = frc_value - error;
	end_num = frc_value + error;
	for(loop_i = start_num; loop_i <= end_num; loop_i++){
		if(Mag[loop_i] > max_value){
			max_value = Mag[loop_i];
		}
	}
	return max_value;
}

void GUI_show_fft_value(void) {
//    u32 temp = 0;
    lp = callbuf;

	
    if(refresh_flag) {
        refresh_flag = 0;

        POINT_COLOR = BLACK;


//        Show_Str(10, 32 + 30 * 0, 80, 16, "��    ��", 16, 1);
//        LCD_Fill(75, 32 + 30 * 0, 75 + 100, 32 + 30 * 0 + 24, WHITE); //��ʾ��    ��
//        sprintf((char*)lp, "%6d mVp", wave_value_1);
//        Show_Str(75, 32 + 30 * 0, 100, 16, lp, 16, 1);

        Show_Str(10, 32 + 30 * 1, 80, 16, "����г��", 16, 1);
        LCD_Fill(75, 32 + 30 * 1, 75 + 100, 32 + 30 * 1 + 24, WHITE); //��ʾ����г��
        sprintf((char*)lp, "%6.1f mVp", V_value_2);
        Show_Str(75, 32 + 30 * 1, 100, 16, lp, 16, 1);

        Show_Str(10, 32 + 30 * 2, 80, 16, "�Ĵ�г��", 16, 1);
        LCD_Fill(75, 32 + 30 * 2, 75 + 100, 32 + 30 * 2 + 24, WHITE); //��ʾ�Ĵ�г��
        sprintf((char*)lp, "%6.1f mVp", V_value_4);
        Show_Str(75, 32 + 30 * 2, 100, 16, lp, 16, 1);

        Show_Str(10, 32 + 30 * 3, 80, 16, "�Ĵ�г��", 16, 1);
        LCD_Fill(75, 32 + 30 * 3, 75 + 100, 32 + 30 * 3 + 24, WHITE); //��ʾ����г��
        sprintf((char*)lp, "%6.1f mVp", V_value_6);
        Show_Str(75, 32 + 30 * 3, 100, 16, lp, 16, 1);

        Show_Str(10, 32 + 30 * 4, 80, 16, "����г��", 16, 1);
        LCD_Fill(75, 32 + 30 * 4, 75 + 100, 32 + 30 * 4 + 24, WHITE); //��ʾ�˴�г��
        sprintf((char*)lp, "%6.1f mVp", V_value_8);
        Show_Str(75, 32 + 30 * 4, 100, 16, lp, 16, 1);
		
		
        Show_Str(165, 32 + 30 * 0, 80, 16, "��    ��", 16, 1);
        LCD_Fill(230, 32 + 30 * 0, 230 + 100, 32 + 30 * 0 + 24, WHITE); //��ʾ��    ��
        sprintf((char*)lp, "%6.1f mVp", V_value_1);
        Show_Str(230, 32 + 30 * 0, 100, 16, lp, 16, 1);

        Show_Str(165, 32 + 30 * 1, 80, 16, "����г��", 16, 1);
        LCD_Fill(230, 32 + 30 * 1, 230 + 100, 32 + 30 * 1 + 24, WHITE); //��ʾ����г��
        sprintf((char*)lp, "%6.1f mVp", V_value_3);
        Show_Str(230, 32 + 30 * 1, 100, 16, lp, 16, 1);

        Show_Str(165, 32 + 30 * 2, 80, 16, "���г��", 16, 1);
        LCD_Fill(230, 32 + 30 * 2, 230 + 100, 32 + 30 * 2 + 24, WHITE); //��ʾ���г��
        sprintf((char*)lp, "%6.1f mVp", V_value_5);
        Show_Str(230, 32 + 30 * 2, 100, 16, lp, 16, 1);

        Show_Str(165, 32 + 30 * 3, 80, 16, "�ߴ�г��", 16, 1);
        LCD_Fill(230, 32 + 30 * 3, 230 + 100, 32 + 30 * 3 + 24, WHITE); //��ʾ�ߴ�г��
        sprintf((char*)lp, "%6.1f mVp", V_value_7);
        Show_Str(230, 32 + 30 * 3, 100, 16, lp, 16, 1);

        Show_Str(165, 32 + 30 * 4, 80, 16, "�Ŵ�г��", 16, 1);
        LCD_Fill(230, 32 + 30 * 4, 230 + 100, 32 + 30 * 4 + 24, WHITE); //��ʾ�Ŵ�г��
        sprintf((char*)lp, "%6.1f mVp", V_value_9);
        Show_Str(230, 32 + 30 * 4, 100, 16, lp, 16, 1);
		
		//��ʾ�̶�
        LCD_Fill(10, 210, 10 + 120, 210 + 24, WHITE);
        sprintf((char*)lp, "%6d Hz/div", fstep_grid);
        Show_Str(10, 210, 120, 16, lp, 16, 1);
    }


}

void Auto_set (void) {

    //�Զ�����
    LCD_Display_Dir(1);//����
    POINT_COLOR = WHITE;
    LCD_DrawLine(10, ((0xFFF - Lock_value) >> 4), 310, ((0xFFF - Lock_value) >> 4));
    Lock_value = cYmin/2 + cYmax/2;// + cYmin

    if(state_flag == 0 || state_flag == 1) {
        ADC_Fr = FreqVal * 16;
        ADC_Change_Fr(ADC_Fr);
    }
    else if(state_flag == 2 || state_flag == 3) {
        ADC_Fr = FreqVal * 200;
        ADC_Change_Fr(ADC_Fr);
    }
}
