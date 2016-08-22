void blinK(int i, int val) {
  digitalWrite(i, LOW);
  delay(val);
  digitalWrite(i, HIGH);
  delay(val);
}
void killLed() {
  digitalWrite(red, HIGH);
  digitalWrite(blue, HIGH);
  digitalWrite(green, HIGH);
}
