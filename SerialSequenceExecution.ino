
void seqSerial() {
  eat = (char)mySerial.read();

  if (eat == '0')blinK(red, 1000);
  else if (eat == '1')blinK(green, 1000);
  else if (eat == '2')blinK(blue, 1000);
  else if (eat == 'S' || eat == 's') {
    mode = true;
    myServo.attach(6);
    myServo.write(0);
  }


  while (mode) {
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(green, LOW);


    eat = (char)mySerial.read();

    if (eat == '0')pos = 0;
    else if (eat == '1')pos = 90;
    else if (eat == '2')pos = 180;
    else if (eat == 's' || eat == 'S') {
      killLed();
      mode = false;
    }
    else if (eat == 'A' || eat == 'a'){
      for(pos = 0; pos<= 180; pos++){
        myServo.write(pos);
        delay(15);
      }
      for(pos = 180; pos >= 0;pos--){
        myServo.write(pos);
        delay(15);
      }
    }



    myServo.write(pos);



  }
  myServo.detach();

}
