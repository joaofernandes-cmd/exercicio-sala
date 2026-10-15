// Lab 1 — LED de status + buzzer: pulso de 200 ms a cada 2 s

const int PINO_LED    = 8;   // LED com resistor de 220 Ω em série
const int PINO_BUZZER = 9;   // buzzer ativo

const unsigned long TEMPO_ACESO   = 200;
const unsigned long TEMPO_APAGADO = 1800;

void setup() {
  pinMode(PINO_LED, OUTPUT);
  pinMode(PINO_BUZZER, OUTPUT);
}

void loop() {
  digitalWrite(PINO_LED, HIGH);
  digitalWrite(PINO_BUZZER, HIGH);   // liga junto com o LED
  delay(TEMPO_ACESO);
  digitalWrite(PINO_LED, LOW);
  digitalWrite(PINO_BUZZER, LOW);    // desliga junto com o LED
  delay(TEMPO_APAGADO);
}