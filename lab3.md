# การทดลองที่ 1 เรื่อง การเขียนโปรแกรมเอ้าพุทสัญญาณดิจิทัล

## วัตถุประสงค์
1. เพื่อทราบการเขียนโปรแกรมเพื่อรันบนไมโครคอนโทรเลอร์

## อุปกรณ์ที่ใช้
1. ไมโครคอนโทรเลอร์ (ESP-01)
2. อแดปเตอร์ที่ต่อสายพอร์ท 0 (สีขาว) กับ พอร์ท 1 (สีเหลือง)
3. อุปกรณ์ต่อ USB (USB to serial)
4. หลอดไฟ LED
5. CPU
6. เสาอากาศสำหรับไวไฟ

## ศึกษาข้อมูลเบื้องต้น
1. 03 run example 3 : https://www.youtube.com/watch?v=CCnN1WJsXQY
2. src code ของโปรแกรม 03_Output-Port : https://github.com/choompol-boonmee/lab63b/blob/master/examples/03_Output-Port/src/main.cpp

## วิธีการทำทดลอง
1. เอาอแดปเตอร์ต่อกับตัว USB to seria
2. นำตัวไมโครคอนโทรเลอร์ต่อกับพอร์ท
3. เข้าcommand prompt
4. เข้าตัวอย่างโปรแกรมจากโดยใช้พิมพ์คำสั่ง **cd pattani** ในหน้า command prompt
5. เลือกตัวอย่างโปรแกรมคำสั่ง **cd 03_Output-Port**
6. พิมพ์คำสั่ง **vi src/main.cpp** เมื่อกด Enter จะขึ้นโค้ดดังนี้
          
        #include <Arduino.h>
        #include <ESP8266WiFi.h>

        int cnt = 0;

        void setup()
        {
	            Serial.begin(115200);
	            pinMode(0, OUTPUT);
	            Serial.println("\n\n\n");
        }

        void loop()
        {
	            cnt++;
	            if(cnt % 2) {
		                Serial.println("========== ON ===========");
		                digitalWrite(0, HIGH);
	             } else {
		                Serial.println("========== OFF ===========");
		                digitalWrite(0, LOW);
	              }
	              delay(500);
         }
      
      
      
      
   
      
      


6. อัพโหลดโปรแกรมเข้าไมโครคอนโทรเลอร์ด้วยคำสั่ง **pio run -t upload** 
7. กดปุ่มอัพโหลดและกดปุ่มรีเซตที่ตัวไมโครคอนโทรเลอร์เพื่อให้ตัวโปรแกรมอัพโหลดเข้าไปในตัว่ไมโครคอนโทรเลอร์
8. **pio device monitor** เพื่อดูผลลัพท์









![image](https://user-images.githubusercontent.com/80879772/111914840-4f071300-8aa6-11eb-9d5b-8e20b52936ef.png)

9. สังเกตที่หลอดไฟ LED










![image](https://user-images.githubusercontent.com/80879772/111914895-7f4eb180-8aa6-11eb-9819-1f6e211e950a.png)   ![image](https://user-images.githubusercontent.com/80879772/111914938-a9a06f00-8aa6-11eb-9e0c-ba3749274b68.png)
	
off on











      



## การบันทึกผลการทดลอง


จากการใช้คำสั่ง vi platformio.ini ทำให้เราได้ทราบข้อมูลดังนี้
1. เป็น paltform ของ espressif8266                   
2. bord ชื่อ esp01_1m
3. ใช้วิธีการเขียนโปรแกรมแบบ arduino
4. port ใช้ของ windows เพราะขึ้นว่า com3

จากการใช้คำสั่ง pio device monitor 
1. จะเห็นว่าตัวแปร count จะเพิ่มขึ้นๆ ทุก 1 วินาที 
2. เมื่อกดปุ่มรีเซตที่ตัวไมโครคอนโทรเลอร์ ก็จะเริ่มนับหนึ่งใหม่
## อภิปรายผลการทดลอง
จากการใช้คำสั่ง vi src/main.cpp ทำให้เราทราบว่าโปรแกรม 01_Serial-Monitor มี2 ส่วน ดังนี้
1. ส่วน set up 
2. ส่วน loop
      ที่จะเพิ่มตัวแปร count และแสดงผลของตัวแปรโดยมีการหน่วงเวลา 1000 ms 
โดยจากการทดลองการเขียนโปรแกรมเพื่อรันบนไมโครคอนโทรเลอร์จะเห็นว่าเมื่อเราอัพโหลดโปรแกรม 01_Serial-Monitor ลงในตัวไมโครคอนโทรเลอร์เรียบร้อยแล้ว และใช้คำสั่ง **pio device monitor** เพื่อดูการทำงานของไมโครคอนโทรเลอร์ ซึ่งหน้าจอจะขึ้นว่ามีการเปลี่ยนตัวแปรทุกๆ 1 วินาที ตามโปรแกรมที่เราได้อัพโหลดลงไป 

## คำถามหลังการทดลอง
ถาม เราสามารถ