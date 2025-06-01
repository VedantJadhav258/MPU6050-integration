#include <Wire.h>
#include <MPU6050.h>
#include <math.h>

MPU6050 mpu;

float gyroX, gyroY, gyroZ;
float angleX = 0, angleY = 0;
unsigned long lastTime = 0;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  mpu.initialize();
  lastTime = millis();
}

void loop() {
  unsigned long currentTime = millis();
  float elapsedTime = (currentTime - lastTime) / 1000.0;
  lastTime = currentTime;

  mpu.getRotation(&gyroX, &gyroY, &gyroZ);

  float gyroRateX = gyroX / 131.0;
  float gyroRateY = gyroY / 131.0;

  angleX += gyroRateX * elapsedTime;
  angleY += gyroRateY * elapsedTime;

  Serial.print("Yaw: ");
  Serial.print(gyroZ / 131.0);
  Serial.print(" | Pitch: ");
  Serial.print(angleX);
  Serial.print(" | Roll: ");
  Serial.println(angleY);

  delay(100);
}
