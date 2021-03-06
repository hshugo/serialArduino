const byte DATA_MAX_SIZE = 32;
char data[DATA_MAX_SIZE]; 
String incoming = "";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("hello from arduino!");  

  static char endMarker = '\n'; // message separator
  char receivedChar;     // read char from serial port
  int ndx = 0;          // current index of data buffer
  // clean data buffer
  

  //memset(data, 10, sizeof(data));
  // read while we have data available and we are
  // still receiving the same message.
  //while(Serial.available() > 0) {
     incoming = Serial.readString();
    Serial.println(incoming);
    /*
    receivedChar = Serial.read();
     //Serial.println("DEV"+receivedChar );
    if (receivedChar == endMarker) {
      data[ndx] = '\0'; // end current message
      return;
    }
    // looks like a valid message char, so append it and
    // increment our index
    data[ndx] = receivedChar;
    ndx++;
    // if the message is larger than our max size then
    // stop receiving and clear the data buffer. this will
    // most likely cause the next part of the message
    // to be truncated as well, but hopefully when you
    // parse the message, you'll be able to tell that it's
    // not a valid message.
    if (ndx >= DATA_MAX_SIZE) {
      break;
    }
    */
  //}
  // no more available bytes to read from serial and we
  // did not receive the separato. it's an incomplete message!
  //Serial.println("error: incomplete message");
 // memset(data, 10, sizeof(data));
  
  
  //receiveData();
  delay(1000);
}


void receiveData() {
  static char endMarker = '\n'; // message separator
  char receivedChar;     // read char from serial port
  int ndx = 0;          // current index of data buffer
  // clean data buffer
  

  memset(data, 32, sizeof(data));
  // read while we have data available and we are
  // still receiving the same message.
  while(Serial.available() > 0) {
   
    
    receivedChar = Serial.read();
     Serial.println(receivedChar);
    if (receivedChar == endMarker) {
      data[ndx] = '\0'; // end current message
      return;
    }
    // looks like a valid message char, so append it and
    // increment our index
    data[ndx] = receivedChar;
    ndx++;
    // if the message is larger than our max size then
    // stop receiving and clear the data buffer. this will
    // most likely cause the next part of the message
    // to be truncated as well, but hopefully when you
    // parse the message, you'll be able to tell that it's
    // not a valid message.
    if (ndx >= DATA_MAX_SIZE) {
      break;
    }
  }
  // no more available bytes to read from serial and we
  // did not receive the separato. it's an incomplete message!
  Serial.println("error: incomplete message");
  memset(data, 32, sizeof(data));
}
