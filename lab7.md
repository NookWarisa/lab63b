# การทดลองที่ 7 เรื่อง การเขียนโปรแกรมเพื่อรันบนไมโครคอนโทรเลอร์

## วัตถุประสงค์
1. เพื่อนำความรู้จากการทดลองที่ 1 - 6 มาประยุกต์ใช้
2. เพื่อเขียนโปรแกรมเพื่อรันบนไมโครโทรเลอร์ด้วยตนเอง

## อุปกรณ์ที่ใช้
1. ไมโครคอนโทรเลอร์ (ESP-01)
2. อแดปเตอร์ที่ต่อสายพอร์ท 0 (สีขาว) กับ พอร์ท 2 (สีเหลือง)
3. อุปกรณ์ต่อ USB (USB to serial)
4. หลอดไฟ LED
5. CPU
6. ตัวโปรแกรมสำหรับที่จะรันโปรแกรม
7. ตัวเซนเซอร์จับควาามเคลื่อนไหว


## ศึกษาข้อมูลเบื้องต้น
1. ตัวอย่าง src code ของโปรแกรมในการทดลองที่ 1 - 6 : https://github.com/choompol-boonmee/lab63b/tree/master/examples
2. ตัวเซนเซอร์จับการเคลื่อนไหว : https://www.myarduino.net/product/28/pir-%E0%B9%80%E0%B8%8B%E0%B9%87%E0%B8%99%E0%B9%80%E0%B8%8B%E0%B8%AD%E0%B8%A3%E0%B9%8C%E0%B8%95%E0%B8%A3%E0%B8%A7%E0%B8%88%E0%B8%88%E0%B8%B1%E0%B8%9A%E0%B8%84%E0%B8%A7%E0%B8%B2%E0%B8%A1%E0%B9%80%E0%B8%84%E0%B8%A5%E0%B8%B7%E0%B9%88%E0%B8%AD%E0%B8%99%E0%B9%84%E0%B8%AB%E0%B8%A7-motion-sensor-detector-module-hc-sr501-2

 
## วิธีการทำทดลอง
1. เขียนโปรแกรมสำหรับที่จะใช้รันบนโปรแกรมในไมโครคอนโทรเลอร์แล้วตั้งชื่อไฟล์ว่า 07_Lab7 
ซึ่งโค้ดที่เราเขียนมีรายละเอียดดังนี้
```javascript
int PIR_pin = 0;
int PWM_pin = 2;

long time_delay = 10000;  // lamp on time (ms) 1 mimute = 60000ms
int dim_delay = 20; // dim speed adjust ระยะในการรี่ไฟ

long time_old = 0; 
bool on_state = 0;  
int inc_val = 0; 

void setup() 
{
  Serial.begin(9600);
  pinMode(PIR_pin,INPUT);  
  pinMode(PWM_pin,OUTPUT);
  digitalWrite(PIR_pin,LOW); 
}

void loop() 
{
  if(digitalRead(PIR_pin) == 1) // check movement; move = 1, no move = 0
  {
    on_state = 1;
    time_old = millis(); 
  }
  
  if(on_state == 1)
  {
    if(millis()-time_old<time_delay)
    {
      inc_val = inc_val +1;
      if(inc_val > 255)
      {
        inc_val = 255;
      }
      delay(dim_delay);
    }
    else
    {
      inc_val = inc_val -1;
      if(inc_val<0)
      {
        inc_val = 0;
        on_state = 0;
      }
      delay(dim_delay);
    }
  }  
  else
  {
    time_old = millis(); 
  }
  
  analogWrite(PWM_pin,inc_val);
  Serial.println(inc_val);
}
```
2. เอาอแดปเตอร์ต่อกับตัว USB to serial
3. นำตัวไมโครคอนโทรเลอร์ต่อกับพอร์ท
4. เข้าcommand prompt
5. เข้าโปรแกรมทีจะรันโดยใช้พิมพ์คำสั่ง ***cd 07_Lab7*** ในหน้า command prompt
6. อัพโหลดโปรแกรมเข้าไมโครคอนโทรเลอร์ด้วยคำสั่ง ***pio run -t upload***
7. กดปุ่มอัพโหลดและกดปุ่มรีเซตที่ตัวไมโครคอนโทรเลอร์เพื่อให้ตัวโปรแกรมอัพโหลดเข้าไปในตัว่ไมโครคอนโทรเลอร์
8. ทดลองเอามือผ่านและไม่ผ่านตัวเซนเซอร์ แล้วบันทึกผล 

## การบันทึกผลการทดลอง
1. จากโค้ดของโปรแกรมที่จะใช้ในการรันบนไมโครคอนโทรเลอร์สามารถอธิบายคำสั่งได้ดังนี้
2. จากการสังเกตุเมื่อมีการเคลื่อนไหวผ่านหน้าเซนเซอร์จะพบว่า

## อภิปรายผลการทดลอง
จากการทดลองนี้

## คำถามหลังการทดลอง


