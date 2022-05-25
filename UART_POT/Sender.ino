//Sender's code
int i; //declaring the counter variable
void setup() {

  Serial.begin(9600); //begins the serial monitor at 9600 Baud rate
}
 
void loop() {
  
  int sensor = analogRead(A0); //Reading value from potentiometer


  //dividing into bytes
  byte highByte = sensor / 256; //2 MSB
  byte lowByte = sensor % 256; //8 LSB
  
  byte  arr[]={highByte,lowByte}; //forming an array of divided bytes
  for(i=0;i<2;i++){
  Serial.write(arr[i]); //Sending the Array
  //Serial.write(arr[1]); //just a line for debugging
  }
}
