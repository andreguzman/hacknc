#include <Servo.h>

#define UP 50
#define DOWN 40
#define SENTENCE "the quick brown fox jumped over the lazy dog"

Servo servo9;
Servo servo10;
Servo servo11;
Servo servo6;
Servo servo5;
Servo servo3;

Servo topLeft;
Servo topRight;
Servo midLeft;
Servo midRight;
Servo botLeft;
Servo botRight;

char incomingByte;

void setup(){ 
  servo9.attach(9);
  servo10.attach(10);
  servo11.attach(11);
  servo6.attach(6);
  servo5.attach(5);
  servo3.attach(3);

  topLeft = servo9;
  topRight = servo10;
  midLeft = servo11;
  midRight = servo6;
  botLeft = servo5;
  botRight = servo3;

  Serial.begin(9600);
  reset();
  
}

void loop(){
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    //servo10.write(incomingByte - '0');
    //delay(100);
    printBraille(incomingByte);
    Serial.println(incomingByte);
  }
}

void printBraille(char printChar){
  if(printChar >= 'A'){
    printChar += 'a' - 'A';
  }
  switch(printChar){
    case 'a': writeA(); break;
    case 'b': writeB(); break;
    case 'c': writeC(); break;
    case 'd': writeD(); break;
    case 'e': writeE(); break;
    case 'f': writeF(); break;
    case 'g': writeG(); break;
    case 'h': writeH(); break;
    case 'i': writeI(); break;
    case 'j': writeJ(); break;
    case 'k': writeK(); break;
    case 'l': writeL(); break;
    case 'm': writeM(); break;
    case 'n': writeN(); break;
    case 'o': writeO(); break;
    case 'p': writeP(); break;
    case 'q': writeQ(); break;
    case 'r': writeR(); break;
    case 's': writeT(); break;
    case 't': writeT(); break;
    case 'u': writeU(); break;
    case 'v': writeV(); break;
    case 'w': writeW(); break;
    case 'x': writeX(); break;
    case 'y': writeY(); break;
    case 'z': writeZ(); break;
    default: writeSpace();
  }
}

void writeA(){
  writeLetter(UP, DOWN, DOWN, DOWN);
}

void writeB(){
  writeLetter(UP, DOWN, UP, DOWN);
}

void writeC(){
  writeLetter(UP, UP, DOWN, DOWN);
}

void writeD(){
  writeLetter(UP, UP, DOWN, UP);
}

void writeE(){
  writeLetter(UP, DOWN, DOWN, UP); 
}

void writeF(){
  writeLetter(UP, UP, UP, DOWN);  
}

void writeG(){
  writeLetter(UP, UP, UP, UP);
}

void writeH(){
  writeLetter(UP, DOWN, UP, UP); 
}

void writeI(){
  writeLetter(DOWN, UP, UP, DOWN);
}

void writeJ(){
  writeLetter(DOWN, UP, UP, UP);
}

void writeK(){
  writeLetter(UP, DOWN, DOWN, DOWN, UP, DOWN);
}

void writeL(){
  writeLetter(UP, DOWN, UP, DOWN, UP, DOWN);
}

void writeM(){
  writeLetter(UP, UP, DOWN, DOWN, UP, DOWN);
}

void writeN(){
  writeLetter(UP, UP, DOWN, UP, UP, DOWN);
}

void writeO(){
  writeLetter(UP, DOWN, DOWN, UP, UP, DOWN); 
}

void writeP(){
  writeLetter(UP, UP, UP, DOWN, UP, DOWN);  
}

void writeQ(){
  writeLetter(UP, UP, UP, UP, UP, DOWN);
}

void writeR(){
  writeLetter(UP, DOWN, UP, UP, UP, DOWN); 
}

void writeS(){
  writeLetter(DOWN, UP, UP, DOWN, UP, DOWN);
}

void writeT(){
  writeLetter(DOWN, UP, UP, UP, UP, DOWN);
}

void writeU(){
  writeLetter(UP, DOWN, DOWN, DOWN, UP, UP);
}

void writeV(){
  writeLetter(UP, DOWN, UP, DOWN, UP, UP);
}

void writeX(){
  writeLetter(UP, UP, DOWN, DOWN, UP, UP);
}

void writeY(){
  writeLetter(UP, UP, DOWN, UP, UP, UP);
}

void writeZ(){
  writeLetter(UP, DOWN, DOWN, UP, UP, UP); 
}

void writeW(){
  writeLetter(DOWN, UP, UP, UP, DOWN, UP);
}

void writeSpace(){
  writeLetter(DOWN, DOWN, DOWN, DOWN);
}

void writeLetter(int tL, int tR, int mL, int mR){
  topLeft.write(tL);
  delay(100);
  topRight.write(tR);
  delay(100);
  midLeft.write(mL);
  delay(100);
  midRight.write(mR);
  delay(100);
  botLeft.write(DOWN);
  delay(200);
  botRight.write(DOWN);
  delay(1000);
  reset();
}

void writeLetter(int tL, int tR, int mL, int mR, int bL, int bR){
  topLeft.write(tL);
  delay(100);
  topRight.write(tR);
  delay(100);
  midLeft.write(mL);
  delay(100);
  midRight.write(mR);
  delay(100);
  botLeft.write(bL);
  delay(200);
  botRight.write(bR);
  delay(1000);
  reset();
}

void reset(){
  topLeft.write(DOWN);
  delay(100);
  topRight.write(DOWN);
  delay(100);
  midLeft.write(DOWN);
  delay(100);
  midRight.write(DOWN);
  delay(100);
  botLeft.write(DOWN);
  delay(200);
  botRight.write(DOWN);
  delay(1000);
}
