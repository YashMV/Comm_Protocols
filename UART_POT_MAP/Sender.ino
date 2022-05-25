//Sender's code

int sensor;

void setup()
{
	pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  sensor = analogRead(A0);
  sensor=map(sensor, 0, 1023, 0, 255);
  Serial.write(sensor);
}
