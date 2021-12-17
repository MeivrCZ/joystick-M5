#include <Arduino.h>
#include <M5StickCPlus.h>
#include "M5_JoyC.h"
#include <BluetoothSerial.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

//bluetooth
//name M5-7443
//UUID: 1bc68b2a

BluetoothSerial SerialBT;

M5_JOYC joyc;

String message = "0";

String engine1 = "8";
String engine2 = "8";
String engine3 = "8";
String engine4 = "8";

void setup()
{
    M5.begin();
    M5.Lcd.begin();
    joyc.begin();
    Serial.begin(38400);
    SerialBT.begin("JoyStick", true);
}

void loop()
{
  if(SerialBT.connected()){
    M5.Lcd.setCursor(5, 140);
    M5.Lcd.print("connected");

    /*engine1 = joyc.getX(0) / 22;
    engine2 = joyc.getX(0) / 22;
    engine3 = joyc.getX(0) / 22;
    engine4 = joyc.getX(0) / 22;
    
    message = "A" + engine1 + engine2 + engine3 + engine4 + "F";
    
    M5.Lcd.setCursor(5, 160);
    M5.Lcd.print(message);
    SerialBT.println(message);
    delay(20);*/

    engine1 = joyc.getX(1) / 22;
    engine2 = joyc.getX(1) / 22;
    engine3 = joyc.getX(1) / 22;
    engine4 = joyc.getX(1) / 22;
    
    message = "B" + engine1 + engine2 + engine3 + engine4 + "F";
    
    M5.Lcd.setCursor(5, 160);
    M5.Lcd.print(message);
    SerialBT.println(message);
    delay(20);

    /*engine1 = joyc.getX(1) / 22;
    engine2 = joyc.getX(1) / 22;
    engine3 = joyc.getX(1) / 22;
    engine4 = joyc.getX(1) / 22;
    
    message = "C" + engine1 + engine2 + engine3 + engine4 + "F";
    
    M5.Lcd.setCursor(5, 160);
    M5.Lcd.print(message);
    SerialBT.println(message);
    delay(20);*/
  }
  else{
    SerialBT.connect("Brouk");
    M5.Lcd.setCursor(5, 140);
    M5.Lcd.print("disconnected");
  }

  M5.Lcd.fillRect(0, 0, 135, 240, BLACK);

  M5.Lcd.setCursor(5, 5);
  M5.Lcd.print("x    y");
  M5.Lcd.setCursor(5, 20);
  M5.Lcd.print(joyc.getX(0));
  M5.Lcd.print(" ");
  M5.Lcd.print(joyc.getY(0));
  M5.Lcd.setCursor(5, 35);
  M5.Lcd.print(joyc.getX(1));
  M5.Lcd.print(" ");
  M5.Lcd.print(joyc.getY(1));

  M5.Lcd.setCursor(5, 50);
  M5.Lcd.print("angle");
  M5.Lcd.setCursor(5, 65);
  M5.Lcd.print(joyc.getAngle(0));
  M5.Lcd.print(" ");
  M5.Lcd.print(joyc.getAngle(1));

  M5.Lcd.setCursor(5, 80);
  M5.Lcd.print("distance");
  M5.Lcd.setCursor(5, 95);
  M5.Lcd.print(joyc.getDistance(0));
  M5.Lcd.print(" ");
  M5.Lcd.print(joyc.getDistance(1));

  M5.Lcd.setCursor(5, 110);
  M5.Lcd.print("press");
  M5.Lcd.setCursor(5, 125);
  M5.Lcd.print(joyc.getPress(0));
  M5.Lcd.print(" ");
  M5.Lcd.print(joyc.getPress(1));
  
  delay(10);
}