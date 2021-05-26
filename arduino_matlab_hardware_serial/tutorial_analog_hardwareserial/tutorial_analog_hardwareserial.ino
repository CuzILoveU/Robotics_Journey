

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}
int seq = 0;
// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:

  seq++;
  uint32_t tmicros = micros();
  float voltage = analogRead(A8) *  3.3/ 1024;
  
  char msg[1000];
  
  //int sensorValue = analogRead(A8);
  // print out the value you read:
  //Serial.print(sensorValue);
  
sprintf(msg, "%lu %d %.5f\n", tmicros, seq, voltage);
Serial.print(msg);
  delay(1000);      
  
}
