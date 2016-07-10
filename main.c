//ʹ��12MHz����һ��ʱ��������1/12us������STC89C52RC��Ƭ����һ������������12��ʱ�����ڣ���1us��
#include "STC89C51RC.H"

sbit P10 = P1^0;
sbit P12 = P1^2;
int i;
int j;

void timer0() interrupt 1
{
    //50ms�ж�һ�Σ���50000��ʱ�����ڣ�T0��ʼֵΪ65535 - 50000 = 15535 = 0x3CAF;
    TH0 = 0x3C;
    TL0 = 0xAF;
    if(i == 20)
    {
        j++;
        i = 1;
        P10 = !P10; 
    }
    else
    {
        i++;
    }
}
int main()
{
    P1 = 0xFF;
    P12 = 0;
    i = 1;
    j = 0;
    TMOD = 0x01;
    TH0 = 0x3C;
    TL0 = 0xAF;
    TR0 = 1;
    EA = 1;
    ET0 = 1;
    for (;;)
    {
        if (j == 15300)
        {
             EA = 0;
             ET0 = 0;
             P12 = 1;
             P10 = 0;
             while(1)
             {
             }
        }
    }
    return 0;
}