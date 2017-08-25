/**************************************************************
 * Multiple Temperature Sendor Test
 * 
 *  2 x OneWire Sensor: DS18B20
 *  Connected to NodeMCU D4 (or Arduino Pin 2)
 * 
 * Developed by Marcelo Rovai - 25 August 2017
 **************************************************************/

#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2 // DS18B20 on NodeMCU pin D4 
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature DS18B20(&oneWire);

void setup() 
{
  Serial.begin(115200);
  DS18B20.begin();
  Serial.println("Testing Dual Sensor data");
}

void loop() {
  float temp_0;
  float temp_1;
  DS18B20.requestTemperatures(); 
  temp_0 = DS18B20.getTempCByIndex(0); // Sensor 0 will capture Temp in Celcius
  temp_1 = DS18B20.getTempFByIndex(1); // Sensor 0 will capture Temp in Fahrenheit

  Serial.print("Temp_0: ");
  Serial.print(temp_0);
  Serial.print(" oC . Temp_1: ");
  Serial.print(temp_1);
  Serial.println(" oF");
  delay(1000);
}

