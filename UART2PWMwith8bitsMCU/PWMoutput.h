//___________________________________________________________________
//___________________________________________________________________
// Description: 系統初始化相關程序
//  Copyright@: 2019 BY Louis Huang / https://github.com/louisopen/
//   File Name: PWMoutput.h
//Targer Board: MK8002D
//    MCU Body: HT66F317 HT66F318-28ssop
//      Author: Louis Huang
//        Date: 2019/05/18
//     Version: V00 on Hardware V10
//     History:
//___________________________________________________________________
//___________________________________________________________________
#ifndef _PWMOUTPUT_H_
#define _PWMOUTPUT_H_

extern unsigned int    wPWMPeriod,wPWMDuty;

extern void PWM_output(unsigned int period, unsigned int duty);
extern void PWM_output_test();

#endif
