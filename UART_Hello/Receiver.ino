//Receiver's code

char Mymessage[10]; //Initialized variable to store recieved data

void setup() {
    Serial.begin(9600); //Begin the Serial at 9600 Baud
  }

void loop() {
    Serial.readBytes(Mymessage,5); //Read the data and store in Mymessage string
    Serial.println(Mymessage); //Print data on Serial Monitor
    delay(1000);
  }
