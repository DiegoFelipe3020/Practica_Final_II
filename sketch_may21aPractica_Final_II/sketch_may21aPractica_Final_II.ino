/*
   Fundacion Kinal
   Centro educativo tecnico laboral kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AV
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Proyecto Final II
   Dev: Diego Alejandro Felipe Chis
   Profesor: Alejandro Navas
   Fecha: 24 de mayo de 2024
*/
#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
LiquidCrystal_I2C lcd(0x27,16,2);

const byte Row = 4;
const byte Col = 4;
char keys[Row][Col] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};
const byte RowPin[Row] = {13,12,11,10};
const byte ColPin[Col] = {9,8,2,A3};
Keypad keypad = Keypad(makeKeymap(keys), RowPin, ColPin, Row, Col);

int pin7 = 7;
int pin6 = 6;
int pin5 = 5;
int pin4 = 4;
int a0 = A0;
int a1 = A1;
int a2 = A2;
int a3 = A3;
Servo motor;
int giro = 1;

int contador = 0;
char contador1[] = "1";
char contador2[] = "2";
char autof[] = "3";
char display[] = "4";
char servomotor[] = "5";
char teclado[1];
int teclado2 = 0;

void setup() {
  lcd.init( );
  lcd.backlight();
  Serial.begin(9600);
  pinMode(pin7, OUTPUT);
  pinMode(pin6, OUTPUT);
  motor.attach(3);
  pinMode(pin5, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(a3, OUTPUT);
  motor.write(0);
}
void loop() {
  lcd.setCursor(5,0);
  lcd.print("Diego");
  lcd.setCursor(1,1);
  lcd.print("Proyecto Final");
  char key = keypad.getKey();
  if(key != NO_KEY){
    teclado[teclado2] = key;

    if(teclado[0]==contador1[0]){
      for(contador = 0; contador < 100; contador++){
        Serial.println(contador);
        delay(25);
      }
    }
    if(teclado[0]==contador2[0]){
      for(contador = 99; contador > -1; contador--){
        Serial.println(contador);
        delay(25);
      }
    }
    if(teclado[0]==autof[0]){
      for(int i = 0; i < 4; i++){
        for(int i1 = 4; i1 <= 7; i1++){
          digitalWrite(i1, HIGH);
          delay(350);
          digitalWrite(i1, LOW);
        }
        for(int i2 = 8; i2 >= 4; i2--){
          digitalWrite(i2, HIGH);
          delay(350);
          digitalWrite(i2, LOW);
        }
      }
      for(int i3 = 0; i3 < 4; i3++){
        digitalWrite(pin7, HIGH);
        digitalWrite(pin6, HIGH);
        digitalWrite(pin5, HIGH);
        digitalWrite(pin4, HIGH);
        delay(250);
        digitalWrite(pin7, LOW);
        digitalWrite(pin6, LOW);
        digitalWrite(pin5, LOW);
        digitalWrite(pin4, LOW);
        delay(250);
      }
    }
    if(teclado[0]==display[0]){
      int a = pin7;
      int b = pin6;
      int c = pin5;
      int d = pin4;
      int e = a2;
      int f = a1;
      int g = a0;
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e ,HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      delay(750);
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e ,HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, LOW);
      delay(750);
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, HIGH);
      digitalWrite(e ,HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, LOW);
      delay(750);
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e ,HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      delay(750);
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      digitalWrite(e ,LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
    }
    if(teclado[0]==servomotor[0]){
      if(giro == 1){
        for(int giro1 = 0; giro1 < 180; giro1++){
          motor.write(giro1);
          delay(10);
        }
        giro = -1;
      }else{
        for(int giro2 = 180; giro2 > 0; giro2--){
          motor.write(giro2);
          delay(10);
        }
        giro = 1;
      }
    }
  }
}