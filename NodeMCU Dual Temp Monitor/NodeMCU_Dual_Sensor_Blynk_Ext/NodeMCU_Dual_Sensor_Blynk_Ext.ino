/**************************************************************
 * IoT Multiple Temperature Monitor with Blynk
 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 * 
 * Multiple OneWire Sensor: DS18B20
 * Developed by Marcelo Rovai - 25 August 2017
 **************************************************************/

/* ESP & Blynk */
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
char auth[] = "YOUR AUTH CODE HERE";

/* WiFi credentials */
char ssid[] = "YOUR SSID";
char pass[] = "YOUR PASSWORD";

/* TIMER */
#include <SimpleTimer.h>
SimpleTimer timer;

/* DS18B20 Temperature Sensor */
#include <OneWire.h>
#include<DallasTemperature.h> 
#define ONE_WIRE_BUS 2 // DS18B20 on arduino pin2 corresponds to D4 on physical board
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature DS18B20(&oneWire);
int temp_0;
int temp_1;

void setup() 
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  DS18B20.begin();
  timer.setInterval(1000L, getSendData);
  Serial.println(" ");
  Serial.println("Testing Dual Sensor data");
}

void loop() 
{
  timer.run(); // Initiates SimpleTimer
  Blynk.run();
}

/***************************************************
 * Send Sensor data to Blynk
 **************************************************/
void getSendData()
{
  DS18B20.requestTemperatures(); 
  temp_0 = DS18B20.getTempCByIndex(0); // Sensor 0 will capture Temp in Celcius
  temp_1 = DS18B20.getTempFByIndex(1); // Sensor 0 will capture Temp in Fahrenheit

  Serial.print("Temp_0: ");
  Serial.print(temp_0);
  Serial.print(" oC . Temp_1: ");
  Serial.print(temp_1);
  Serial.println(" oF");
   
  Blynk.virtualWrite(10, temp_0); //virtual pin V10
  Blynk.virtualWrite(11, temp_1); //virtual pin V11
}


