void bts() {

  if (Serial.available())
  {
    mySerial.print((char)Serial.read());
  }

  if (mySerial.available())
  {
    digitalWrite(led, HIGH);
    Serial.print((char)mySerial.read());
  }
  else {
    digitalWrite(led, LOW);
  }

}



