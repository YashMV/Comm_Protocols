//Master

#include <SPI.h>
byte arr [3] = {1, 2, 3};

void setup (void)
{
  Serial.begin (9600);
  Serial.println ("Master");

  digitalWrite(SS, HIGH);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
}

void loop (void)
{
  byte b;
  digitalWrite(SS, LOW);
  delayMicroseconds (200);
  byte z = SPI.transfer (0xCD);
  delayMicroseconds(20);
  byte x = SPI.transfer(0);
  delayMicroseconds(20);
  //Serial.println(x);
  if (x == 0xEF)
  {
    for (byte i = 0 ; i < 3 ; i++)
    {
        b = (arr[i]);
        byte y = SPI.transfer (b);
        delayMicroseconds(20);
       Serial.print(arr[i]);
    }
  }
  digitalWrite(SS, HIGH);
  delay(2000);
  Serial.println( );
  Serial.println("=================");

}
