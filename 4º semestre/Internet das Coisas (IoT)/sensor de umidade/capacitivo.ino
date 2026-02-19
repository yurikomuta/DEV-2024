// --- Configuração dos Pinos ---
const int PINO_SENSOR_UMIDADE = 34; // Entrada Analógica (ADC)
const int PINO_LED_SECO = 26;       // Saída Digital para o LED

// --- Calibração ---
// No ESP32, 12 bits variam de 0 (muito úmido) a 4095 (muito seco)
const int LIMIAR_SECO = 2000; 

void setup() {
  // Inicia a comunicação serial a 115200 bps
  Serial.begin(115200);

  // Configura o pino do LED como saída
  pinMode(PINO_LED_SECO, OUTPUT);

  // Nota: O ESP32 já configura o ADC34 como entrada por padrão
}

void loop() {
  // Ação: Ler o valor do sensor de umidade
  int valor_umidade = analogRead(PINO_SENSOR_UMIDADE);

  // Exibe a leitura no Monitor Serial
  Serial.print("Valor do sensor: ");
  Serial.println(valor_umidade);

  // Tomada de Decisão baseada nos dados
  if (valor_umidade > LIMIAR_SECO) {
    // Se o valor for alto, o solo está seco (maior resistência)
    Serial.println("ALERTA: Solo seco! É hora de regar.");
    digitalWrite(PINO_LED_SECO, HIGH); // Acende o LED
  } 
  else {
    // Solo com umidade suficiente
    Serial.println("Solo úmido. Tudo certo!");
    digitalWrite(PINO_LED_SECO, LOW); // Apaga o LED
  }

  // Aguarda 5 segundos antes da próxima leitura (conforme original)
  delay(5000);
}