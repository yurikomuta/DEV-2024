// --- Configuração dos Pinos ---
// O pino GPIO4 será usado para leitura analógica (LDR)
const int PINO_LDR = 4;
// O pino GPIO23 será usado para controlar o LED
const int PINO_LED_ESCURO = 23;

// Habilidade: Tomada de Decisão baseada em dados
// A lógica do LDR: quanto menos luz, menor o valor lido
const int LIMIAR_ESCURO = 400;

void setup() {
  // Inicia a comunicação serial para exibir leituras no console
  Serial.begin(115200);

  // Configura o pino do LED como saída digital
  pinMode(PINO_LED_ESCURO, OUTPUT);
  
  // No ESP32, a resolução padrão do ADC já é 12 bits (0-4095)
  // e a atenuação padrão geralmente cobre até 3.3V.
}

void loop() {
  // Ação: Ler o valor do sensor LDR
  int valor_luminosidade = analogRead(PINO_LDR);

  // Exibe a leitura no console
  Serial.print("Valor de luminosidade: ");
  Serial.println(valor_luminosidade);

  // Lógica de decisão
  if (valor_luminosidade < LIMIAR_ESCURO) {
    // Se o valor for baixo (pouca luz), acende o LED
    Serial.println("Ambiente escuro! Acendendo o LED.");
    digitalWrite(PINO_LED_ESCURO, HIGH); // Acende o LED
  } 
  else {
    // Se houver luz, apaga o LED
    Serial.println("Ambiente claro. LED apagado.");
    digitalWrite(PINO_LED_ESCURO, LOW); // Apaga o LED
  }

  // Aguarda 1 segundo antes da próxima leitura
  delay(1000);
}