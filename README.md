## ※UARTtoPWMwith8bitsMCU
* Useing HT66F318 UART port access internal resource GPIO, LED matrix, EEPROM, ADC, I2C...(Same RS-485 driver)<br>
此專案利用PC軟件通過UART port下達指令以存取MCU內部的EEPROM(64bytes), PWM(10bits or 16bit) 都透過UART port<br>

* Project Option:<br>
HXT (External 8MHz X'tal); 可選項有:HXT(400K~16Mhz),HIRC8M,HIRC12M,HIRC16M<br>
LICR (Low speed internal RC for TB0/TB1); 可選項有:LXT(32.768Khz),LIRC(32Khz)<br>

* UART Baudrate: 9600,n,8,1 (協議格式參照RS-485通訊協議格式)<br>

* TB0,1 enable LIRC interrupt for 0.514sec, 0.514sec<br>

* TM0 enable HXT interrupt for 200us<br>

* PWM輸出
PWM(HT66F317)設置直接透過TP0, TP1輸出, TM0/TM1(16bit), 最大設置TM0/TM1(16bit)<br>
PWM(HT66F318)設置直接透過TP0, TP1, TP2輸出, TM0(hi-16bit), 最大設置TM1(10bit), TM2(hi-16bit)<br>

* HT-IDE3000 HT66F317/HT66F318 28ssop with HT-IDE3000 & e-Link & e-WriterPro<br>
文件[HT66F318 Document](https://www.holtek.com.tw/search?key=ht66F318)<br>
模擬&除錯Development & Debug[IDE3000 & ICE](https://www.holtek.com.tw/web/guest/ice)<br>
燒入器Progrmming & writer[HOPE3000 & e-WriterPro](https://www.holtek.com.tw/web/guest/programmer)<br>

### Relevant information
* HT-IDE3000 V8.02
![Image](HT-IDE3000_version.jpg)
* HOLTEK C Compiler V3/Assembly
![Image](ProjectCompiler.jpg)
* HT66F318 Config, used 8Mhz X'tal external, VDD/VDDA binding
![Image](ProjectOption1.jpg)
![Image](ProjectOption2.jpg)
![Image](ProjectOption3.jpg)
![Image](ProjectOption4.jpg)
* HT66F318 28ssop Schematic Diagram
![Image](CircuitDiagram.jpg)
![Image](MCUdiagram.jpg)

### How to test or used
利用PC通訊軟件做為主動工具, 協議(9600,n,8,1), 格式參照RS-485格式(PC指令CRC用 A0 0A代替CRC-16, MCU反饋的為真實CRC-16)

* For Example: 
* UART Formate(Get from MCU): 44 03 00 00 00 04 A0 0A   #讀取EEPROM位址0x0000,4組(共計8個bytes)
MCU return設計最大每次讀取四組(8byte) 所以反饋時: 44 03 08 00 01 02 03 04 05 06 07 CRC CRC

* UART Formate(Write to MCU): 44 06 00 0A EE FF A0 0A   #寫入EEPROM位址0x000A,資料為0xEEFF
MCU return: 44 06 00 0A EE FF CRC CRC

* UART Formate(Write to MCU): 44 06 06 00 3F FF A0 0A   #寫入PWM週期, 0x3FFF(TM1) is period (TM0,TM2 10bit)
MCU return PWM: 44 06 06 00 3F FF CRC CRC

* UART Formate(Write to MCU): 44 06 06 01 2F FF A0 0A   #寫入PWM佔比, 0x2FFF(TM1) is duty (TM0,TM2 10bit)
MCU return PWM: 44 06 06 00 2F FF CRC CRC

### Other applications
* UART access to ADC converter(HY3118 24bit ADC) via I2C bus.
* UART access to OLED 16x2 display driver via SPI bus.

