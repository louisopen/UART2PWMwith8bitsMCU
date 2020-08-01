### UARTtoPWMwith8bitsMCU
HT-IDE3000 V8.02  HT66F317/HT66F318 28ssop

Project Option�i���:HXT,HIRC8M,HIRC12M,HIRC16M,LXT,LIRC 

Useing HT66F318 UART access to GPIO, LED matrix, EEPROM, ADC, I2C...(Same RS-485 driver)
���M�קQ��PC�n��U�F���O�H�s��MCU������EEPROM(64bytes), PWM(10bits or 16bit) 
���z�LUART 9600,N,8,1 ��ĳ�榡�ѷ�RS-485�q�T��ĳ�榡.

PWM(HT66F317)�]�m�����z�LTP0, TP1��X, TM0/TM1(16bit), �̤j�]�mTM0/TM1(16bit)
PWM(HT66F318)�]�m�����z�LTP0, TP1, TP2��X, TM0(hi-16bit), �̤j�]�mTM1(10bit), TM2(hi-16bit)

* HT-IDE3000 V8.02
![Image](HT-IDE3000_version.jpg)
* HOLTEK C Compiler V3/Assembly
![Image](ProjectCompiler.jpg)
* HT66F318 Config, used 8Mhz X'tal external, VDD/VDDA binding
![Image](ProjectOption1.jpg)
![Image](ProjectOption2.jpg)
![Image](ProjectOption3.jpg)
![Image](ProjectOption4.jpg)
* HT66F318 28ssop Diagram
![Image](CircuitDiagram.jpg)


#### How to test or used:
�Q��PC�q�T�n�󰵬��D�ʤu��, ��ĳ(9600,n,8,1), �榡�ѷ�RS-485�榡(PC���OCRC�� A0 0A�N��CRC-16, MCU���X�����u��CRC-16)

* For Example: 
* UART Formate(Get from MCU): 44 03 00 00 00 04 A0 0A   #Ū��EEPROM��}0x0000,4��(�@�p8��bytes)
MCU return�]�p�̤j�C��Ū���|��(8byte) �ҥH���X��: 44 03 08 00 01 02 03 04 05 06 07 CRC CRC

* UART Formate(Write to MCU): 44 06 00 0A EE FF A0 0A   #�g�JEEPROM��}0x000A,��Ƭ�0xEEFF
MCU return: 44 06 00 0A EE FF CRC CRC

* UART Formate(Write to MCU): 44 06 06 00 3F FF A0 0A   #�g�JPWM�g��, 0x3FFF(TM1) is period (TM0,TM2 10bit)
MCU return PWM: 44 06 06 00 3F FF CRC CRC

* UART Formate(Write to MCU): 44 06 06 01 2F FF A0 0A   #�g�JPWM����, 0x2FFF(TM1) is duty (TM0,TM2 10bit)
MCU return PWM: 44 06 06 00 2F FF CRC CRC



#### Other applications:
* UART access to ADC converter(HY3118 24bit ADC) via I2C bus.
* UART access to OLED 16x2 display driver via SPI bus.

