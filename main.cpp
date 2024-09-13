#include <SoftwareSerial.h>


int motor1_in1 = 2; // Rotor principal AD
int motor1_in2 = 3;
int motor1_pwm = 9;

int motor2_in1 = 4; // Motor principal de horientacion vertical WS
int motor2_in2 = 5;
int motor2_pwm = 10;

int motor3_in1 = 6; // motor de antebrazo UJ
int motor3_in2 = 7;
int motor3_pwm = 11;

int motor4_in1 = 8; // motor de muñeca(izquierdo) IK
int motor4_in2 = 9;
int motor4_pwm = 3;

int motor5_in1 = 10; // motor de muñeca(derecho) OL
int motor5_in2 = 11;
int motor5_pwm = 5;

int motor6_in1 = 12; // motor de garra TG
int motor6_in2 = 13;
int motor6_pwm = 6;

unsigned long lastInputTime = 0;
unsigned long motorStopDelay = 100;

void setup()
{
  // Configurar los pines de los motores como salidas
  pinMode(motor1_in1, OUTPUT);
  pinMode(motor1_in2, OUTPUT);
  pinMode(motor1_pwm, OUTPUT);

  pinMode(motor2_in1, OUTPUT);
  pinMode(motor2_in2, OUTPUT);
  pinMode(motor2_pwm, OUTPUT);

  pinMode(motor3_in1, OUTPUT);
  pinMode(motor3_in2, OUTPUT);
  pinMode(motor3_pwm, OUTPUT);

  pinMode(motor4_in1, OUTPUT);
  pinMode(motor4_in2, OUTPUT);
  pinMode(motor4_pwm, OUTPUT);

  pinMode(motor5_in1, OUTPUT);
  pinMode(motor5_in2, OUTPUT);
  pinMode(motor5_pwm, OUTPUT);

  pinMode(motor6_in1, OUTPUT);
  pinMode(motor6_in2, OUTPUT);
  pinMode(motor6_pwm, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  if (Serial.available() > 0)
  {
    // Leer el carácter ingresado
    char input = Serial.read();

    if (input == 'a')
    {
      digitalWrite(motor1_in1, LOW);
      digitalWrite(motor1_in2, HIGH);
      analogWrite(motor1_pwm, 255);
    }
    else if (input == 'd')
    {
      digitalWrite(motor1_in1, HIGH);
      digitalWrite(motor1_in2, LOW);
      analogWrite(motor1_pwm, 255);
    }
    else if (input == 'w')
    {
      digitalWrite(motor2_in1, HIGH);
      digitalWrite(motor2_in2, LOW);
      analogWrite(motor2_pwm, 255);
    }
    else if (input == 's')
    {
      digitalWrite(motor2_in1, LOW);
      digitalWrite(motor2_in2, HIGH);
      analogWrite(motor2_pwm, 255);
    }
    else if (input == 'u')
    {
      digitalWrite(motor3_in1, HIGH);
      digitalWrite(motor3_in2, LOW);
      analogWrite(motor3_pwm, 255);
    }
    else if (input == 'j')
    {
      digitalWrite(motor3_in1, LOW);
      digitalWrite(motor3_in2, HIGH);
      analogWrite(motor3_pwm, 255);
    }
        else if (input == 'i')
    {
      digitalWrite(motor4_in1, HIGH);
      digitalWrite(motor4_in2, LOW);
      analogWrite(motor4_pwm, 255);
    }
    else if (input == 'k')
    {
      digitalWrite(motor4_in1, LOW);
      digitalWrite(motor4_in2, HIGH);
      analogWrite(motor4_pwm, 255);
    }
    else if (input == 'o')
    {
      digitalWrite(motor5_in1, HIGH);
      digitalWrite(motor5_in2, LOW);
      analogWrite(motor5_pwm, 255);
    }
    else if (input == 'l')
    {
      digitalWrite(motor5_in1, LOW);
      digitalWrite(motor5_in2, HIGH);
      analogWrite(motor5_pwm, 255);
    }
    else if (input == 't')
    {
      digitalWrite(motor6_in1, HIGH);
      digitalWrite(motor6_in2, LOW);
      analogWrite(motor6_pwm, 255);
    }
    else if (input == 'g')
    {
      digitalWrite(motor6_in1, LOW);
      digitalWrite(motor6_in2, HIGH);
      analogWrite(motor6_pwm, 255);
    }

    // Actualizar el tiempo de la última entrada
    lastInputTime = millis();
  }

  // Si ha pasado un tiempo sin recibir ningún comando, detener el motor
  if (millis() - lastInputTime > motorStopDelay)
  {
    stopAll();
  }
}

void stopAll()
{
  digitalWrite(motor1_in1, LOW);
  digitalWrite(motor1_in2, LOW);
  analogWrite(motor1_pwm, 0);

  digitalWrite(motor2_in1, LOW);
  digitalWrite(motor2_in2, LOW);
  analogWrite(motor2_pwm, 0);

  digitalWrite(motor3_in1, LOW);
  digitalWrite(motor3_in2, LOW);
  analogWrite(motor3_pwm, 0);

  digitalWrite(motor4_in1, LOW);
  digitalWrite(motor4_in2, LOW);
  analogWrite(motor4_pwm, 0);

  digitalWrite(motor5_in1, LOW);
  digitalWrite(motor5_in2, LOW);
  analogWrite(motor5_pwm, 0);

  digitalWrite(motor6_in1, LOW);
  digitalWrite(motor6_in2, LOW);
  analogWrite(motor6_pwm, 0);
}