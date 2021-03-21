# การทดลองที่ 4 เรื่อง การเขียนโปรแกรมอินพุทสัญญาณดิจิทัล

## วัตถุประสงค์
1. เพื่อทราบการเขียนโปรแกรมอินพุทสัญญาณดิจิทัล
2. เพื่อนำไมโครคอนโทรเลอร์ที่เขียนโปรแกรมแล้วไปประยุกต์ใช้

## อุปกรณ์ที่ใช้
1. ไมโครคอนโทรเลอร์ (ESP-01)
2. อแดปเตอร์ที่ต่อสายพอร์ท 0 (สีขาว) กับ พอร์ท 2 (สีเหลือง)
3. อุปกรณ์ต่อ USB (USB to serial)
4. หลอดไฟ LED
5. CPU
6. ตัวโปรแกรมเอ้าพุทสัญญาณ (04_Input-Port)
7. ตัวเซนเซอร์แสง

## ศึกษาข้อมูลเบื้องต้น
1. 04 run example 4t : https://www.youtube.com/watch?v=nFqoZT26U5k
2. src code ของโปรแกรม 04_Input-Port : https://github.com/choompol-boonmee/lab63b/blob/master/examples/04_Input-Port/src/main.cpp
## วิธีการทำทดลอง
1. เอาอแดปเตอร์ต่อกับตัว USB to seria (หมายเหตุ ตัวอแดปเตอร์ที่ใช้ในการทดลองนี้มีการต่อกับ LED )
2. นำตัวไมโครคอนโทรเลอร์ต่อกับพอร์ท 
3. เข้าcommand prompt
4. เข้าตัวอย่างโปรแกรมจากโดยใช้พิมพ์คำสั่ง **cd pattani** ในหน้า command prompt
5. เลือกตัวอย่างโปรแกรมคำสั่ง **cd 04_Input-Port** 
6. พิมพ์คำสั่ง **vi src/main.cpp** เมื่อกด Enter จะขึ้นโค้ดดังนี้
```javascript
#include <Arduino.h>
#include <ESP8266WiFi.h>

int cnt = 0;

void setup()
{
	Serial.begin(115200);
	pinMode(0, INPUT);
	pinMode(2, OUTPUT);
	Serial.println("\n\n\n");
}

void loop()
{
	int val = digitalRead(0);
	Serial.printf("======= read %d\n", val);
	if(val==1) {
		digitalWrite(2, LOW);
	} else {
		digitalWrite(2, HIGH);
	}
	delay(100);
}

```        
โดยโค้ดของโปรแกรมนี้ได้เซตที่พอร์ท 0 คือ input พอร์ท 2 คือ output และ อ่านจะอ่านข้อมูลจากพอร์ท 0 โดยให้เป็นข้อมูลดิจิทัล(มีค่า 0 1) และแสดงผลว่าอ่านได้เท่าไหร่โดยถ้าเป็น 1 จะเป็นค่า low ที่พอร์ท 2 (ไฟดับ) และถ้าเป็น 0 จะเป็นค่า high ที่พอร์ท 2 (ไฟติด)  

6. อัพโหลดโปรแกรมเข้าไมโครคอนโทรเลอร์ด้วยคำสั่ง **pio run -t upload** 
7. กดปุ่มอัพโหลดและกดปุ่มรีเซตที่ตัวไมโครคอนโทรเลอร์เพื่อให้ตัวโปรแกรมอัพโหลดเข้าไปในตัว่ไมโครคอนโทรเลอร์
8. **pio device monitor** เพื่อดูผลลัพท์









![image](https://user-images.githubusercontent.com/80879772/111918801-71eef280-8ab9-11eb-8984-aabf8b9fdfc2.png)

9. ดูที่สายไฟเส้นสีขาว (พอร์ท 0) โดยจิ้มที่เส้นสีดำ (0 V)










![image](https://user-images.githubusercontent.com/80879772/111918970-25f07d80-8aba-11eb-801a-21906df54b40.png)

10. ดูที่สายไฟเส้นสีขาว (พอร์ท 0) โดยจิ้มที่เส้นสีแดง (5 V)










![image](https://user-images.githubusercontent.com/80879772/111919091-bc24a380-8aba-11eb-8851-4e1b0eaa4363.png)

11. กดปุ่มสีดำ (เป็น0 ไฟติด) และปล่อยปุ่มสีดำ







![image](https://user-images.githubusercontent.com/80879772/111919198-4f5dd900-8abb-11eb-9539-e2264f79ed54.png)![image](https://user-images.githubusercontent.com/80879772/111919180-32c1a100-8abb-11eb-900e-264a6fbd1baa.png)
    
    กดปุ่ม                                  ปล่อยปุ่ม

12. ต่อตัวเซนเซอร์กับ cpu ตามภาพ





![image](https://user-images.githubusercontent.com/80879772/111919464-ad3ef080-8abc-11eb-92ea-01f03f10e347.png)
โดยสัญญาณจาก censor (ตัวกลาง) คือถ้ามีแสงสว่างเข้ามาจะเป็น 0 มืดแรงต้านทานสูง เป็น 1

13. นำinput (เส้นสีขาว) ต่อกับสัญญาณจาก censor 
13. ลองเอานิ้วไปเปิดหน้า censor กับ ไม่เอานิ้วปิดหน้า censor และสังเกตหลอด LED

## การบันทึกผลการทดลอง
1. เขียนโปรแกรมไมโครคอนโทรเลอร์ด้วยโปรแกรม 04_Input-Port
	
	จะเห็นว่าจากคำสั่ง **pio device monitor** ได้ขึ้นคำว่า read 1 ซึ่งหมายความว่า input คือ 1 ทำให้เป็น low ที่พอร์ท 2 จะทำให้ไฟดับนั้นเอง 
	
	เมื่อจิ้มเส้นอินพุทไปที่สีดำซึ่งจะได้ค่า  input คือ 0 ทำให้เป็น high ไฟติด 
	
	เมื่อจิ้มเส้นอินพุทไปที่สีแดงซึ่งจะได้ค่า input คือ 1 ทำให้เป็น low  ไฟดับ
	
	กดปุ่มสีดำ                     input คือ 0 ทำให้เป็น high ไฟติด 
	
	ปล่อยปุ่ม		       input คือ 1 ทำให้เป็น low  ไฟดับ

2. การนำตัวไมโครคอนโทรเลอร์ที่่ได้ลงโปรแกรมแล้วมาประยุุกต์ใช้ต่อกับตัวเซนเซอร์แสง

	จะเห็นว่าเห็นว่า  เมื่อเอานิ้วบังแสง    ไฟดับ
		     เมื่อเอาไม่เอานิ้วบังแสง  ไฟติด
	
## อภิปรายผลการทดลอง
จากการทดลองเขียนโปรแกรมสามารถสรุปจากการโค้ดที่เขียนโปรแกรมได้ว่า สัญญาณอินพุทจากพอร์ท 0 คือตัวควบคุมให้ไฟเปิดหรือปิด ถ้า 1 ไฟดับ ถ้า 0 ไฟติด โดยดูไฟที่พอร์ท 2 

และในส่วนของการมาประยุกต์ใช้ต่อกับตัวเซนเซอร์แสง โดยเมื่อเอานิ้วบังแสง ทำให้แรงต้านสูงทำให้ค่า input 1 ไฟดับ และเมื่อสว่างทำให้แรงต้านทานน้อย input เป็น 0 ไฟติด

## คำถามหลังการทดลอง
ถาม ในชีวิตประจำวันเราได้ใช้เซนเซอร์แสงหรือไม่ พร้อมยกตัวอย่าง

ตอบ ได้ใช้ เช่นไฟข้างทาง 