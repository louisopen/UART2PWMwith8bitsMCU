//___________________________________________________________________
//___________________________________________________________________
// Description: �t�Ϊ�l�Ƭ����{��
//  Copyright@: 2019 BY Louis Huang / https://github.com/louisopen/
//   File Name: Sys_Init.c
//Targer Board: MK8002D
//    MCU Body: HT66F317 HT66F318-28ssop
//      Author: Louis Huang
//        Date: 2019/05/18
//     Version: V00 on Hardware V10
//     History:
//___________________________________________________________________
//___________________________________________________________________
#include "common.h"

unsigned int    wPWMPeriod,wPWMDuty;

void PWM_output(unsigned int period, unsigned int duty);
void PWM_output_test();

//-----------------------------------
//  Initial Freq = 166.67KHz TM1
//  Initual Freq.= 31.25KHz TM0 TM2
//-----------------------------------
void PWM_output( unsigned int period, unsigned int duty)
{	
	/*
	//set PWM duty for CCRA
	if(duty > 1023) 
	{
 		_tm1al  = 0xff;     
 		_tm1ah  = 0x03; 		
	}else if(duty < 1)
	{  
		_tm1al  = 0x00;     
 		_tm1ah  = 0x00; 		 
	}else
	{
 		_tm1al  = (duty & 0xff);     
 		_tm1ah  = (duty & 0xff00) >> 8; 
	}
 	//set PWM period for CCRP
 	if(period > 1023) //TM1
 	{   //max period = 1024 clocks
 		_tm1rpl  = 0x00;  
 		_tm1rph  = 0x00; 
 	}
 	else if(period < 1)
 	{
 		_tm1rpl  = 0x01;  
 		_tm1rph  = 0x00;  	
 	}
 	else 
 	{
 		_tm1rpl  = (period & 0xff);   
 		_tm1rph  = (period & 0xff00) >> 8;  
 	} 	
	*/
	//set PWM duty for CCRA
	//if(duty > 65535) //TM1
	if(duty > 65535-256) //TM0,TM2
	{
		//_tm2al  = 0xff;
 		_tm2al  = 0x00;     
 		_tm2ah  = 0xff; 		
	}else if(duty < 1)
	{  
		_tm2al  = 0x00;     
 		_tm2ah  = 0x00; 		 
	}else
	{
 		_tm2al  = (duty & 0xff);     
 		_tm2ah  = (duty & 0xff00) >> 8; 
	}	
 	//set PWM period for CCRP
 	//if(period > 65535) //TM1
	if(period > 65535-256) //TM0,TM2
 	{   //max period = 65536 clocks
 		_tm2rp = 0xff;	
 	}
 	//else if(period < 1)
 	else if(period < 256)
 	{
 		_tm2rp = 0x01;
 	}
 	else 
 	{
 		//_tm2rp = period & 0xff; 
 		_tm2rp = (period & 0xff00) >> 8;  
 	} 	
}
//___________________________________________________________________
//Function: MCU PWM ��l��
//   INPUT: PWM , duty
//  OUTPUT: 166.67Khz 100%
//	  NOTE: 
//___________________________________________________________________
void PWM_init()
{	/*
	//Multifunction 0 interrupt
	//Timer1 can using STM 16bits (ht66f318)
	_tm0c0 = 0B00010000;  	//0001 0000	Pause, TM Clock = fsys, T0ON=Off state
	_tm0c1 = 0B10101000;	//1010 1000 PWM_Mode, Active high, Non-invert,counter clear when comparator P match
	_tm0al = 0x0C;				//CCRA����ȳ]�m16bits
	_tm0ah = 0x00;
	_tm0rp = 0x00;				//CCRP��16bit ht66f317/ht66f318
	//_t0ae = 1;					//interrupt for CCRA
	//_t0pe = 1;					//interrupt for CCRP
	//_mf0e = 1;					//Multifunction 0 interrupt enable
	_t0on = 1;
	_t0cp = 1;				//enable PA0 TP0(TMPC.0=1) binding TM0 
	*/
	//Multifunction 1 interrupt
	//Timer1 can using PTM 10bits (ht66f317,ht66f318)
	_tm1c0 = 0B00010000;  	//0001 0000	Pause, TM Clock = fsys, T1ON=Off state
	_tm1c1 = 0B10101000;	//1010 1000 PWM_Mode, Active high, Non-invert,counter clear when comparator P match
	_tm1al = 0x0C;				//CCRA����ȳ]�m10bits
	_tm1ah = 0x00;
	_tm1rpl = 0x30;				//CCRP��10bit ht66f317/ht66f318
	_tm1rph = 0x00;				//CCRPH�u��2bit ht66f317/ht66f318
	//_t1ae = 1;					//interrupt for CCRA
	//_t1pe = 1;					//interrupt for CCRP
	//_mf1e = 1;					//Multifunction 1 interrupt enable
	_t1on = 1;
	_t1cp = 1;				//enable PA7 TP1(TMPC.1=1) binding TM1 output
	/*
	//Multifunction 1 interrupt
	//Timer2 can using CTM 16bits (ht66f318)
	_tm2c0 = 0B00010000;  	//0001 0000	Pause, TM Clock = fsys, T2ON=Off state
	_tm2c1 = 0B10101000;	//1010 1000 PWM_Mode, Active high, Non-invert,counter clear when comparator P match
	_tm2al = 0x0C;				//CCRA����ȳ]�m16bits
	_tm2ah = 0x00;
	_tm2rp = 0x03;				//CCRP��16bit ht66f317/ht66f318
	//_t2ae = 1;					//interrupt for CCRA
	//_t2pe = 1;					//interrupt for CCRP
	//_mf1e = 1;					//Multifunction 1 interrupt enable
	_t2on = 1;
	_t2cp = 1;				//enable PB3 TP2(TMPC.2=1) binding TM2 output
	*/
}
//___________________________________________________________________
//Function: MCU PWM test sample
//   INPUT: PWM (period, duty)
//  OUTPUT: 166.67Khz with duty cycle on TM1
//	  NOTE: 
//___________________________________________________________________
void PWM_output_test()
{	
	PWM_init();
	//�A�XTM1 PWM output
	//wPWMPeriod = 20;	//400KHz at 8MHzOSC
	//wPWMDuty = 10;		//Low Duty 10 = 50%  1.24us 
	
	//wPWMPeriod = 48;	//166.67KHz at 8MHzOSC
    //wPWMDuty = 12;		//Low Duty 12 = 25%  1.5us
    //wPWMDuty = 24;	//Low Duty 24 = 50%  2.98us
    
    wPWMPeriod = 244;	//32.787KHz at 8MHzOSC
    wPWMDuty = 122;		//Low Duty 127 = 50%  15.2us
    PWM_output( wPWMPeriod, wPWMDuty);
    
    /*
    //�A�XTM0 TM2 PWM outpu period*256, duty 50% (31.25K�H�U���W�v)
    //wPWMPeriod = 3*256;	//	10.4KHz
    //wPWMDuty = 3*256/2;	//
    wPWMPeriod = 1*256;	//	31.25K
    wPWMDuty = 1*256/2;	//
    PWM_output( wPWMPeriod, wPWMDuty);
    */
}