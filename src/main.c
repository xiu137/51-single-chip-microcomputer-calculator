#include <8052.h>
#include "delay.h"
#include "input.h"
#include "LCD1602.h"

/*
    * 数字对应位置
    * 7  8  9 *
    * 4  5  6 /
    * 1  2  3 +
    * . 0  = -
    * 数字对应位置
    * 7  8  9 12
    * 4  5  6 13
    * 1  2  3 14
    * 10 0  11 15
*/

void main(){
    unsigned char KeyNumber;
    double num1=0.0;
    double num2=0.0;
    unsigned char i=1;
    unsigned char method=0;
    double ans=0;
    unsigned char ansL=0;
    unsigned char ansH=0;
    unsigned char point=0;
    LCD_Init();
    while(1){
        KeyNumber=scanner();
        if(KeyNumber>=0&&KeyNumber<=9){
            LCD_ShowNum(0,0,KeyNumber,1);
            if (i==1)
                if (point==0)
                    num1=KeyNumber+num1*10;
                else {
                    num1=KeyNumber/10.0+num1;
                }
            else
                if (point==0)
                num2=KeyNumber+num2*10;
                else {
                    num2=KeyNumber/10.0+num2;
                }
        }
        else if(KeyNumber>=12&&KeyNumber<=15){
            i=2;
            point=0;
            switch(KeyNumber){
                case 12:
                    LCD_ShowChar(0,0,'/');method=1;break;
                case 13:
                    LCD_ShowChar(0,0,'*');method=2;break;
                case 14:
                    LCD_ShowChar(0,0,'-');method=3;break;
                case 15:
                    LCD_ShowChar(0,0,'+');method=4;break;
            }
        }
        else if(KeyNumber==10){//point
            point=1;
            LCD_ShowChar(0,0,'.');
        }
        else if(KeyNumber==11){//=
            LCD_ShowChar(2,1,'=');
            switch(method){
                case 2:
                    ans=num1*num2;break;
                case 1:
                    ans=num1/num2;break;
                case 3:
                    if(num1>=num2)
                        ans=num1-num2;
                    else{
                        LCD_ShowChar(2,2,'-');
                        ans=num2-num1;
                        }
                    break;
                case 4:
                    ans=num1+num2;break;
            }
            ansH=ans;
            ansL=(ans-ansH)*100;
            LCD_ShowNum(0,0,ansH,4);
            if(ansL!=0){
                LCD_ShowChar(0,4,'.');
                LCD_ShowNum(0,5,ansL,2);
            }
        }
    }
}