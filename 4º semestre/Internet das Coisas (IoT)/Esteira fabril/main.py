from machine import Pin, time_pulse_us
from time import sleep

# Definição dos pinos
trigger = Pin(5, Pin.OUT)
echo = Pin(18, Pin.IN)
esteira_led = Pin(2, Pin.OUT)

# Variável para contar os itens
contador_itens = 0

# Definição da função para medir a distância
def medir_distancia():
    # Envia pulso para o trigger
    trigger.off()
    sleep(0.01)  # Atraso antes de ativar o trigger
    trigger.on()
    sleep(0.00001)  # Pulso de 10 microsegundos
    trigger.off()

    # Medindo o tempo do eco
    try:
        tempo = time_pulse_us(echo, 1, 30000)  # Timeout de 30ms
        if tempo < 0:  # Caso o tempo seja negativo, erro na leitura
            return None
        distancia = (tempo * 0.0343) / 2  # Calcula a distância em cm
        return distancia
    except Exception as e:
        print("Erro no sensor:", e)
        return None

while True:
    distancia = medir_distancia()

    if distancia is None:
        print("Erro no sensor")  # Caso o sensor não retorne um valor válido
        esteira_led.off()  # Desliga o LED se houver erro
    elif distancia < 20:
        # Se um objeto for detectado e a esteira não estiver já contando
        print("Objeto detectado! Esteira ON")
        esteira_led.on()  # Liga o LED (simulando a esteira)

        # Incrementa o contador, se o item for novo
        contador_itens += 1
        print(f"Total de itens na esteira: {contador_itens}")
    else:
        print("Nada na esteira. Esteira OFF")
        esteira_led.off()  # Desliga o LED (simulando a esteira)

    sleep(1)  # Espera de 1 segundo entre as medições
