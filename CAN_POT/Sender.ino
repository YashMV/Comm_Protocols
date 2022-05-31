//Sender

#include <SPI.h> //Including library for SPI
#include <mcp2515.h> //Including library for mcp2515
int sensor = 0; //Initializing the potentiometer input to 0
struct can_frame myMsg; //Initailize CAN message structure, it has ID, DLC and data
MCP2515 mcp2515(10); //Select Chip select as 10

void setup() {
  Serial.begin(9600); // Begin Serial monitor at 9600 Baud for debugging
  SPI.begin(); //Start SPI
  mcp2515.reset(); //Reset the mcp2515
  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ); //Set can Speed and clock for oscillator
  mcp2515.setNormalMode(); //Operate mcp2515 in normal mode
  myMsg.can_dlc=2; //The DLC of the message is 2
  myMsg.can_id=0xCF; //The ID of message is 207 (0xCF)
}

void loop() {
  sensor=analogRead(A0); //Read the potentiometer data
  myMsg.data[0]=sensor/256; //0th byte of data is the quotient
  myMsg.data[1]=sensor%256; //1st byte of data is the remainder
  mcp2515.sendMessage(&myMsg); //Send the CAN message
  delayMicroseconds(100); //Some delay for processing
}
