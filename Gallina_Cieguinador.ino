#define trigPin 2
#define echoPin 3
#define motorPin 5

int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // Envía un pulso de trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Lee el tiempo de duración del pulso de echo
  int duration = pulseIn(echoPin, HIGH);

  // Calcula la distancia en cm
  distance = duration / 58.2;

  // Controla la velocidad del motor DC
  if (distance > 20) {
    // Si la distancia es mayor a 20 cm, el motor se detiene
    digitalWrite(motorPin, LOW);
  }
  else {
    // Si la distancia es menor a 20 cm, el motor se activa
    analogWrite(motorPin, map(distance, 0, 20, 255, 0));
  }

  delay(50);
}

