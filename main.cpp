```javascript
int PIR_pin = 0;
int PWM_pin = 2;

long time_delay = 10000; 
int dim_delay = 20; 

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
  if(digitalRead(PIR_pin) == 1) 
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
