//Receiver's Code

int result; //declaring incoming data variable

void setup()
{
	Serial.begin(9600); //begins the serial monitor at 9600 Baud rate
}

void loop()
{
  result=Serial.read(); //read the incoming data
  Serial.println(result); //Print the result in Serial monitor
}
