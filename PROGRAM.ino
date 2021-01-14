#include <VarSpeedServo.h> 
#define SENSOR_UTAMA    8
#define SENSOR_BILIK    7
#define SENSOR_JIRIGEN  4
#define BUZZER          2
#define RELAY_UV        12
#define RELAY_KERAN     13
#define RELAY_PROTEKSI  9 
int count;
int Switch = 'A'; 
VarSpeedServo myservo;

void setup() {
  // put your setup code here, to run once:
myservo.attach(5);
pinMode(SENSOR_UTAMA,INPUT);
pinMode(SENSOR_BILIK,INPUT);
pinMode(SENSOR_JIRIGEN,INPUT_PULLUP);
pinMode(BUZZER,OUTPUT); 
pinMode(RELAY_UV,OUTPUT);
pinMode(RELAY_KERAN,OUTPUT);
pinMode(RELAY_PROTEKSI,OUTPUT);
Serial.begin(9600);
digitalWrite(RELAY_UV,HIGH);
myservo.write(3);
}
void loop() { 
  while(digitalRead(SENSOR_JIRIGEN)==HIGH){
   digitalWrite(RELAY_PROTEKSI,HIGH);
  digitalWrite(BUZZER,LOW);
   Switch = 'A';
   int count = 0;
   while(digitalRead(SENSOR_UTAMA) == LOW && count < 110){
     count++;;
     Serial.println(count);
     if(count>=100){
       bizz();
       break;
      }
      if(digitalRead(SENSOR_UTAMA) == HIGH){
         count = 0; 
         myservo.write(3); 
         Serial.println(count);
         digitalWrite(BUZZER,LOW);
        }
    }
  while((digitalRead(SENSOR_BILIK)==HIGH)&&count >= 90){
        Serial.print(digitalRead(SENSOR_BILIK));
        Serial.print(",");
        Serial.println(digitalRead(SENSOR_UTAMA));
      digitalWrite(BUZZER,LOW);
      myservo.write(120,50,true);
     if(digitalRead(SENSOR_BILIK)==LOW){
      digitalWrite(BUZZER,HIGH);
      delay(1000);
      digitalWrite(BUZZER,LOW);
      delay(100);
      digitalWrite(BUZZER,HIGH);
      delay(100);
      digitalWrite(BUZZER,LOW);
      delay(100);
      digitalWrite(BUZZER,HIGH);
      delay(100);
      Switch = 'B';
      break;
       }
      if(digitalRead(SENSOR_UTAMA)==LOW){
      digitalWrite(BUZZER,HIGH);
      delay(1000);
      digitalWrite(BUZZER,LOW);
      delay(100);
      digitalWrite(BUZZER,HIGH);
      delay(100);
      digitalWrite(BUZZER,LOW);
      delay(100);
      digitalWrite(BUZZER,HIGH);
      delay(100);
      myservo.write(3,50,true);
        Switch = 'A';
        break;
        }
    } 
 while(Switch == 'B'){
  digitalWrite(BUZZER,LOW);
  myservo.write(120,50,true);
  delay(3000);
  bizz();
  digitalWrite(BUZZER,LOW);
  delay(300);
  digitalWrite(BUZZER,HIGH);
  delay(300);
  digitalWrite(BUZZER,LOW);
  myservo.write(3,50,true);
  digitalWrite(BUZZER,LOW);
  delay(1000);
  digitalWrite(RELAY_UV,LOW);
  delay(10000);
  digitalWrite(RELAY_UV,HIGH);
  myservo.write(120,50,true);
  tunggu();
  digitalWrite(BUZZER,LOW);
  myservo.write(3,50,true);
  Switch == 'A';
  break;
  } 
 }
 digitalWrite(BUZZER,HIGH);
 delay(700);
 digitalWrite(BUZZER,LOW);
 delay(700);
 digitalWrite(RELAY_PROTEKSI,LOW);
 }
void MONITOR(){
  Serial.print(digitalRead(SENSOR_UTAMA));
  Serial.print(",");
  Serial.print(digitalRead(SENSOR_BILIK));
  Serial.print(",");
  Serial.println(digitalRead(SENSOR_JIRIGEN));
  delay(100);
  }
void tesRelay(){
  digitalWrite(BUZZER,HIGH);
  digitalWrite(RELAY_UV,HIGH);
  digitalWrite(RELAY_KERAN,HIGH);
  delay(1000);
  digitalWrite(BUZZER,LOW);
  digitalWrite(RELAY_UV,LOW);
  digitalWrite(RELAY_KERAN,LOW);
  delay(1000);
 }
void tesServo() {
  int pos = 0;
  for (pos = 3; pos <= 120; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 120; pos >= 3; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
}
void bizz(){
  for(int i=0;i<15;i++){
    digitalWrite(BUZZER,LOW);
    delay(30);
    digitalWrite(BUZZER,HIGH);
    delay(30);
    }
  }

void tutupBilik(){
  int pos;
  for (pos = 120; pos >= 3; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
 }
void bukaBilik(){
  int pos;
  for (pos = 3; pos <= 120; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
 }
void waitToPass(){
  while(digitalRead(SENSOR_BILIK)==HIGH){
    myservo.write(70); 
    }
  }
void playSteril(){
  bizz();
  myservo.write(70); 
  delay(3000);
  tutupBilik();
  ON_UV();
  myservo.write(70);
  }
 void ON_UV(){
  myservo.write(7); 
  digitalWrite(RELAY_UV,HIGH);
  delay(5000);
  digitalWrite(RELAY_UV,HIGH);
  delay(1000);
  }
void fixHuman(){
 int count = 0;
 while(digitalRead(SENSOR_UTAMA) == LOW){
   count++;
   bizz();
   Serial.println(count);
   if(count>=10){
     digitalWrite(BUZZER,LOW);
     delay(300);
     digitalWrite(BUZZER,HIGH);
     delay(300);
     break;
    }
  }
  while(digitalRead(SENSOR_UTAMA) == HIGH){
    count = 0; 
    myservo.write(7); 
    }
}
void tunggu(){
    digitalWrite(BUZZER,LOW);
    delay(1000);
    digitalWrite(BUZZER,HIGH);
    delay(1000);
    digitalWrite(BUZZER,LOW);
    delay(1000);
    digitalWrite(BUZZER,HIGH);
    delay(1000);
    digitalWrite(BUZZER,LOW);
    delay(1000);
    digitalWrite(BUZZER,HIGH);
    delay(1000);
    digitalWrite(BUZZER,HIGH);
    delay(1000);
    digitalWrite(BUZZER,LOW);
    delay(1000);
    digitalWrite(BUZZER,HIGH);
    delay(1000);
    digitalWrite(BUZZER,LOW);
    delay(1000);
  }
