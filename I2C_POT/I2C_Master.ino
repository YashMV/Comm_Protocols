//Master

#include <Wire.h>
#define slave_addr 2
int sensor; //Variable to read the incoming data
byte val; //8 bit data to be sent

void setup()
{
  Wire.begin(); //starts the I2C communication
  pinMode(A0, INPUT); //Input pin to read potentiometer
  Serial.begin(9600); //begins the serial monitor at 9600 Baud rate
}

void loop()
{
  sensor=analogRead(A0); //gets he value of the potentiometer
  val=map(sensor, 1, 1023, 0, 255); //changing to 8 bits
  Wire.beginTransmission(slave_addr); //I2C begin transmission
  Wire.write(val); //Send data to slave
  Wire.endTransmission(); //end transmission
  Serial.println(val); //print the value which is sent to the slave
}
