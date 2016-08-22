#include <SoftwareSerial.h>
#include <Servo.h>

#define RxD 2     // Pin Connected to the BT_TX jumper
#define TxD 3     // Pin Connected to the BT_RX jumper
#define led 13    // Led to flicker when there's incoming data



SoftwareSerial mySerial(RxD, TxD);    // Create a SoftwareSerialInstance called mySerial
Servo myServo;


int red = 8, green = 10, blue = 11;   // Declare RGB Led pins

char eat = "";    // Create an empty char
int pos = 0;
bool mode = false;
void setup()
{
  myServo.attach(6);
  pinMode(RxD, INPUT);    // Receive
  pinMode(TxD, OUTPUT);   // Transmit
  pinMode(led, OUTPUT);   // Panic not, LED!
  for (int i = 8; i < 12; i++)pinMode(i, OUTPUT);   // Declare all pins output
  digitalWrite(9, HIGH);
  mySerial.begin(9600);               // the ble4.0 baud rate
  Serial.begin(9600);                 // the terminal baud rate
  killLed();

  myServo.write(0);
}

void loop()
{
  bts();
  seqSerial();

  //if

}



