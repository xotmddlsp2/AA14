#include <Arduino_LSM9DS1.h>
#include <Arduino_LPS22HB.h>
#include <Arduino_HTS221.h>
#include <Arduino_APDS9960.h>
float ax, ay, az;
float gx, gy, gz;
float mx, my, mz;

void setup() {
  Serial.begin(9600);
  if (!IMU.begin()) { //LSM9DSI센서 시작
    Serial.println("LSM9DSI센서 오류!");
    while (1);
  }
  if (!BARO.begin()) { //LPS22HB센서 시작
    Serial.println("LPS22HB센서 오류!");
    while (1);
  }
  if (!HTS.begin()) { //HTS221센서 시작
    Serial.println("HTS221센서 오류!");
    while (1);
  }
  if (!APDS.begin()) { //APDS9960센서 시작
    Serial.println("APDS9960센서 오류!");
    while (1);
  }
}
void loop() {
  //가속도센서
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(ax, ay, az);
    Serial.print("aa18aa14, "); Serial.print(ax); Serial.print(", "); Serial.print(ay); Serial.print(", "); Serial.print(az);Serial.print(", ");
  }
  //자이로센서
  if (IMU.gyroscopeAvailable()) {
    IMU.readGyroscope(gx, gy, gz);
     Serial.print(gx); Serial.print(", "); Serial.print(gy); Serial.print(", "); Serial.print(gz);Serial.print(", ");
  }
  //지자계센서
  if (IMU.magneticFieldAvailable()) {
    IMU.readMagneticField(mx, my, mz);
     Serial.print(mx); Serial.print(", "); Serial.print(my); Serial.print(", "); Serial.println(mz);
   delay(2000);
  }


}