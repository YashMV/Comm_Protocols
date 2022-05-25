//Master

#include <Wire.h>
#define slave_addr 2
int sensor;
byte val;

void setup()
{
  Wire.begin();
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  sensor=analogRead(A0);
  val=map(sensor, 1, 1023, 0, 255);
  Wire.beginTransmission(slave_addr);
  Wire.write(val);
  Wire.endTransmission();
  Serial.println(val);
}
