from machine import Pin
from utime import sleep

print("Hello World!")

led = Pin(15, Pin.OUT)
while True:
  led.on()
  print("Led ON!")
  sleep(0.5)
  led.off()
  print("Led OFF!")
  sleep(0.5)