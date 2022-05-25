//Slave

#include <Wire.h> //Arduino Wire file for I2C
int recdata; //initialize the variable for reading received data

void setup()
{
  Serial.begin(9600); //begins the serial monitor at 9600 Baud rate
  Wire.begin(2); //Address of the slave and start of I2c
  Wire.onReceive(myFunc); //Function to handle the incoming data
}

void myFunc(int something) //something is the size of incoming data
{
  recdata=Wire.read(); //reading the data
  //Serial.println(recdata);
}
void loop()
{
  Serial.println(recdata); //printing the received data
}
