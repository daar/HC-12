//HC-12 Useful Functions and Operators Send
//Autor Tom Heylen tomtomheylen.com


#include <SoftwareSerial.h>

#define rxPin 2
#define txPin 3

SoftwareSerial HC12(rxPin, txPin); 
long baud = 9600;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  // define pin modes for tx, rx:
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);

  Serial.begin(baud);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Serial monitor available... OK");

  Serial.print("Serial link available... ");
  HC12.begin(9600);
  if (HC12.isListening()) {
    Serial.println("OK");
  } else {
    Serial.println("NOK");
  }

  //test HC-12
  Serial.print("HC-12 available... ");
  HC12.write("AT");
  delay(1000);
  while (HC12.available() > 0) {
    Serial.write(HC12.read());
  }
  Serial.println();
  Serial.println("initialization done.");
}

boolean state = false;

void loop() {

  digitalWrite(LED_BUILTIN, state);

  HC12.println("test123");
  delay(1000);

  state = not state;
}

