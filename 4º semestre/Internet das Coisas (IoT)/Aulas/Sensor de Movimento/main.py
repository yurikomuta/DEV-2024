import machine
import time

# Configura o pino do sensor PIR como entrada
pir_pin = machine.Pin(15, machine.Pin.IN)

# Configura o pino do LED como saída
led_pin = machine.Pin(18, machine.Pin.OUT)

print("Sistema de detecção de movimento iniciado.")

# Loop principal do programa
while True:
    # Lê o estado do pino do sensor PIR
    # Se o valor for 1 (HIGH), há movimento. Se for 0 (LOW), não há.
    movimento_detectado = pir_pin.value()
    
    if movimento_detectado:
        # Se houver movimento, liga o LED
        led_pin.value(1) # HIGH
        print("Movimento detectado! Ligando o LED.")
    else:
        # Se não houver movimento, desliga o LED
        led_pin.value(0) # LOW
        print("Nenhum movimento detectado. Desligando o LED.")
        
    time.sleep_ms(500) # Pequeno atraso para não sobrecarregar o processador