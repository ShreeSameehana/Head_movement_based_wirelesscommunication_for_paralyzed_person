#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;
unsigned long previousMillis = 0;        
const long interval = 2000;  
void setup(void) {
  Serial.begin(9600);
unsigned long currentMillis = millis();
  // Try to initialize! 
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("Device Initialized");

  // set accelerometer range to +-8G
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

  // set gyro range to +- 500 deg/s
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);

  // set filter bandwidth to 21 Hz
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  delay(100);
}

void loop() {
  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  /* Print out the values */

  unsigned long currentMillis = millis();
if (currentMillis - previousMillis >= interval) {
   previousMillis = currentMillis;
if(a.acceleration.y<-6)
{
  Serial.println("I want water");
}
if(a.acceleration.y>6)
{
  Serial.println("I want food");
}
if(a.acceleration.x<-6)
{
  Serial.println("I need medicine");
}
if(a.acceleration.x>6)
{
  Serial.println("I am not feeling well");
}
}

  delay(1000);
}
