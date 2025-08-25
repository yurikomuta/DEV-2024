from machine import Pin, time_pulse_us
import time

# Configura os pinos
TRIG = Pin(5, Pin.OUT)
ECHO = Pin(18, Pin.IN)

def medir_distancia():
    # Garante que o trigger está baixo
    TRIG.off()
    time.sleep_us(2)
    
    # Envia pulso de 10us
    TRIG.on()
    time.sleep_us(10)
    TRIG.off()
    
    # Mede duração do pulso no pino ECHO
    duracao = time_pulse_us(ECHO, 1, 30000)  # timeout: 30ms
    
    # Converte para distância (em cm)
    distancia = duracao / 58.0
    return distancia

# Loop principal
while True:
    dist = medir_distancia()
    print("Distância: {:.2f} cm".format(dist))
    time.sleep(1)
