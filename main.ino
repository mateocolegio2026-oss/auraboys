#include <Servo.h>

// --------------------
// Pines
// --------------------
const int TRIG_PIN = 7;
const int ECHO_PIN = 6;
const int SERVO_PIN = 9;
const int LED_VERDE = 4;
const int LED_ROJO = 5;

// --------------------
// Configuración
// --------------------
const float DISTANCIA_MINIMA = 20.0;
const unsigned long TIEMPO_ABIERTO = 3000;
const unsigned long TIEMPO_ESPERA = 30UL * 60UL * 1000UL;

// --------------------
// Variables
// --------------------
Servo servo;

unsigned long inicioEspera = 0;
bool enEspera = false;

// --------------------
// Configuración inicial
// --------------------
void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);

  servo.attach(SERVO_PIN);

  // Compuerta cerrada
  servo.write(0);

  // Sistema listo
  digitalWrite(LED_VERDE, HIGH);
  digitalWrite(LED_ROJO, LOW);

  Serial.println("Sistema listo para dispensar.");
}

// --------------------
// Medir distancia
// --------------------
float medirDistancia() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duracion = pulseIn(ECHO_PIN, HIGH);

  float distancia = duracion * 0.0343 / 2;

  return distancia;
}

// --------------------
// Abrir y cerrar compuerta
// --------------------
void dispensarAlimento() {

  Serial.println("Animal detectado.");
  Serial.println("Abriendo compuerta...");

  // Apagar LED verde
  digitalWrite(LED_VERDE, LOW);

  // Abrir compuerta
  servo.write(90);

  // Mantener abierta 3 segundos
  delay(TIEMPO_ABIERTO);

  // Cerrar compuerta
  servo.write(0);

  Serial.println("Compuerta cerrada.");

  // Encender LED rojo
  digitalWrite(LED_ROJO, HIGH);

  // Comenzar período de espera
  inicioEspera = millis();
  enEspera = true;

  Serial.println("Comienza espera de 30 minutos.");
}

// --------------------
// Programa principal
// --------------------
void loop() {

  // Si está en período de espera
  if (enEspera) {

    unsigned long tiempoActual = millis();

    if (tiempoActual - inicioEspera >= TIEMPO_ESPERA) {

      // Finalizó el período de espera
      enEspera = false;

      digitalWrite(LED_ROJO, LOW);
      digitalWrite(LED_VERDE, HIGH);

      Serial.println("Fin del período de espera.");
      Serial.println("Sistema listo nuevamente.");
    }

    return;
  }

  // Medir distancia
  float distancia = medirDistancia();

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Comprobar si hay un animal
  if (distancia > 0 && distancia < DISTANCIA_MINIMA) {
    dispensarAlimento();
  }

  delay(200);
}