//Receiver

#include <SPI.h>
#include <mcp2515.h>
byte recdata[2]; //Received data of 2 bytes

struct can_frame recMsg; //Received CAN message structure
MCP2515 mcp2515(10); //SPI chip select 10
int result; //Declaring the result variable to store the result

void setup() {
  SPI.begin(); //Start SPI
  Serial.begin(9600); //begin Serial monitor at 9600 Baud for displaying the result
  mcp2515.reset(); //Reset the mcp2515
  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ); //Set CAN speed and clock
  mcp2515.setNormalMode(); //Operate in normal mode
}

void loop() {
  if (mcp2515.readMessage(&recMsg) == MCP2515::ERROR_OK) { //Read the message
        if(recMsg.can_id==0xCF) //Read the message if the ID matches
        {
          recdata[0]=recMsg.data[0]; //Take in 0th byte of data
          recdata[1]=recMsg.data[1]; //Take in 1st byte of data
          result = recdata[0]*256 + recdata[1]; //Calculate result
          Serial.println(result); //Print the result
          delayMicroseconds(100); //Some delay for processing
        }
    }
}
