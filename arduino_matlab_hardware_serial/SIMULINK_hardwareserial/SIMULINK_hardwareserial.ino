
int seq = 0;

struct data_format
{
  uint32_t tmicros;
  int32_t seq;
  float voltage;  
} data;   // 12 bytes

// the setup routine runs once when you press reset:
void setup() 
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  analogWriteResolution(8);
  data.seq = 0;
}


void loop() 
{
  // read the input on analog pin 0:

if (Serial.available())
  {
    float duty = Serial.parseFloat();
    int enablepwm = Serial.parseInt();
    Serial.read();
    
    analogWrite(13,duty * 256* (enablepwm > 0)); 
    
  }
static uint32_t t0 = micros();
if (micros()- t0 > 1000)
{
  t0 += 1000;
    data.seq++;
    data.tmicros = micros();
    data.voltage = analogRead(A8) *  3.3/ 1024;
    
  static int count = 0;
  if (count++ % 100 == 0) // % means remainder
  
    Serial.print("sop"); //start of packet
    Serial.write((char*) &data, sizeof(data));  
    //"&" is a pointer  //sizeof(data) in bytes
  // (data_format*

}
       
  
}
