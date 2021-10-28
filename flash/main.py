from machine import Pin
import time


led = Pin(25, Pin.OUT)
while True:
    for sleep_time in list(range(100, 600, 100)) + list(range(600, 100, -100)):
        led.toggle()
        time.sleep_ms(sleep_time)
