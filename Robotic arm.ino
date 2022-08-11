#include <Servo.h>
#include <SoftwareSerial.h>
#include <ArduinoBlue.h>
const int BLUETOOTH_TX = 8;
const int BLUETOOTH_RX = 7;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
int angle;
int sliderVal;
int sliderId;
SoftwareSerial bluetooth(BLUETOOTH_TX, BLUETOOTH_RX);
ArduinoBlue phone(bluetooth);
void setup() {
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  servo5.attach(10);
  Serial.begin(9600);
  bluetooth.begin(9600);
  delay(100);
  Serial.println("setup complete");

}

void loop() {
  sliderId = phone.getSliderId();
  sliderVal = phone.getSliderVal();
  if(sliderId == 1){
    Serial.println(sliderVal);
    angle = map(sliderVal, 0, 200, 0, 180);
    servo1.write(angle);
  }
  if(sliderId == 2){
    Serial.println(sliderVal);
    angle = map(sliderVal, 0, 200, 0, 95);
    servo2.write(angle);
  }

 if(sliderId == 3){
    Serial.println(sliderVal);
    angle = map(sliderVal, 0, 200, 0, 180 );
    servo3.write(angle);
  }

  if(sliderId == 4){
    Serial.println(sliderVal);
    angle = map(sliderVal, 0, 200, 0, 180);
    servo4.write(angle);
  }

if(sliderId == 5){
    Serial.println(sliderVal);
    angle = map(sliderVal, 0, 200, 0, 180);
    servo5.write(angle);
  }
  

}
