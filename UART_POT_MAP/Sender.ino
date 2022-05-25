//Sender's code

int sensor; //declaring the potentiometer reading variable

void setup()
{
	pinMode(A0, INPUT); //Input pin of potentiometer
  Serial.begin(9600); //begins the serial monitor at 9600 Baud rate
}

void loop()
{
  sensor = analogRead(A0); //reading the value of potentiometer
  sensor=map(sensor, 0, 1023, 0, 255); //mapping the sensor variable from 0-255, converting into 8 bits
  Serial.write(sensor);  //Sending the data
}
