// Arduino - Send HEX value to Serial
 char serialPacket[14] = {0,};

 
void setup() {
  Serial.begin(115200);

  serialPacket[0] = 0x02;  // STX
  serialPacket[1] = 0x30;  // OP CODE
  serialPacket[2] = 0x04;
  serialPacket[3] = 0x00;  
  serialPacket[4] = 0x00;
  serialPacket[5] = 0x00;
  serialPacket[6] = 0x00;
  serialPacket[7] = 0x10;
  serialPacket[8] = 0x00;  
  serialPacket[9] = 0x00; 
  serialPacket[10] = 0x00; 
  serialPacket[11] = 0xDC; 
  serialPacket[12] = 0x00; // ETX
  serialPacket[13] = 0x03;

   unsigned char  sum=0;
 for(int i=3;i<=11;i++){
      sum += serialPacket[i];
 }
  unsigned char  x = 0xFF - sum ;
  serialPacket[12]=x;

}

void loop() {
  // 패킷준비
  
 // Serial.println("Sending");

 
  Serial.write(serialPacket, sizeof(serialPacket));
 
  //Serial.println();
  delay(1000);
/*
  // 비교해보기
  // print 와 write 비교, char, int8_t, uint8_t 비교
  int8_t testData = 0x43;
  Serial.println(testData);
  Serial.println((uint8_t)testData);
  Serial.println((char)testData);

  Serial.write(testData);
  Serial.println();
  Serial.write((uint8_t)testData);
  Serial.println();
  Serial.write((char)testData);
  Serial.println();  
  */
  

}
