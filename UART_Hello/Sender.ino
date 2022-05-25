//Sender's Code

char Mymessage[5] = "Hello"; //Initialize String

void setup() {
  Serial.begin(9600); //begins the serial monitor at 9600 Baud rate
}

void loop() {
  Serial.write(Mymessage,5); //Write the string
  delay(1000);
}
