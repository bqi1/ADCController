#include <Wire.h>
#include <Adafruit_ADS1015.h>
#include <String.h>

Adafruit_ADS1115 ads1115(0x48);
float Voltage = 0.0;

void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  ads1115.begin();
  Serial.println("Ready");
}

void loop() {
  char inByte = ' ';
  if (Serial.available()){
    char inByte = Serial.read();
    if (inByte=='1'){
      Serial.println(returnVoltage());
    }else if (strcmp(inByte,"String")==0){
      setVoltage(inByte);
      Serial.println(999);
    }else{
      Serial.println(888);
    }
  }
  delay(100);
}
float returnVoltage(){
  int16_t adc0;  // we read from the ADC, we have a sixteen bit integer as a result

  adc0 = ads1115.readADC_SingleEnded(0);
  Voltage = (adc0 * 0.1875)/1000;
  
  return Voltage;
}
void setVoltage(char inByte){
  
}
