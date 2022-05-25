//Receiver's code

byte highByte; //declaring highbyte
byte lowByte; //declaring lowbyte
int result; //declaring final result
int x;
int y;
int i;
byte arr[2]; //declaring receiving bytes

void setup()
{
  Serial.begin(9600); //begins the serial monitor at 9600 Baud rate
}


 void loop()
{
  result=0; //initialize the result to zero
  //int arr=Serial.read();
   for(i=0;i<2;i++)
   {
    arr[i]=Serial.read(); //get highByte and lowByte and store it in array
   }
   //Code for debugging purpose
   //arr[0,1]=Serial.read();
   //arr[1]=Serial.read();
   //result=highByte * 256 + lowByte;
   x = arr[0];
   y = arr[1];
   result = x* 256 + y; //Calculate final result
   i=0;
   //Serial.println(arr[1]);
   //Serial.println(arr[0]);
   //Serial.println(arr[1]);
   //result=Serial.read();
   Serial.println(result); //print the result
 }
