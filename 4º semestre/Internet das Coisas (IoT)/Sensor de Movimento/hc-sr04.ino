// --- Configuração dos Pinos ---
const int PINO_TRIG = 25;        // Pino de disparo (Trigger)
const int PINO_ECHO = 27;        // Pino de retorno (Echo)
const int PINO_LED_INTRUSO = 26; // LED indicador

// --- Protótipo da Função ---
float obter_distancia();

void setup() {
  Serial.begin(115200);

  // Configuração dos modos dos pinos
  pinMode(PINO_TRIG, OUTPUT);       // Trig envia o pulso
  pinMode(PINO_ECHO, INPUT);        // Echo recebe o pulso
  pinMode(PINO_LED_INTRUSO, OUTPUT); // LED como saída

  // Garante que o Trig comece em nível baixo
  digitalWrite(PINO_TRIG, LOW);
}

void loop() {
  float dist = obter_distancia();

  Serial.print("Distancia: ");
  Serial.print(dist);
  Serial.println(" cm");

  // --- Ação de Atuação: Controle do LED ---
  if (dist > 0 && dist <= 10) { 
    // Se a distância for menor ou igual a 10 cm, acende o LED
    Serial.println("INTRUSO DETECTADO!");
    digitalWrite(PINO_LED_INTRUSO, HIGH);
    delay(1000); // Mantém aceso por 1 segundo (conforme original)
  } 
  else {
    // Se não houver intruso, apaga o LED
    Serial.println("Ambiente seguro.");
    digitalWrite(PINO_LED_INTRUSO, LOW);
  }

  delay(3000); // Aguarda 3 segundos para a próxima leitura
}

// --- Função de Medição de Distância ---
float obter_distancia() {
  // Gera um pulso limpo de 10 microssegundos no Trig
  digitalWrite(PINO_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PINO_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PINO_TRIG, LOW);

  // Mede o tempo que o pino Echo leva para ir de LOW a HIGH (em microssegundos)
  // O timeout de 30000ms evita que o código trave se não houver retorno
  long duracao = pulseIn(PINO_ECHO, HIGH, 30000);

  // Cálculo da distância: (tempo / 2) * velocidade do som (0.0343 cm/us)
  float distancia = (duracao / 2.0) * 0.0343;

  return distancia;
}