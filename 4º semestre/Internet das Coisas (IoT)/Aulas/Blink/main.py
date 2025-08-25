from machine import Pin
from utime import sleep

print("Hello World, ESP32!")  # será exibido no terminal

led = Pin(15, Pin.OUT)  # configurando led com ESP32
while True:
    led.on()
    sleep(0.5)
    led.off()
    sleep(0.5)
