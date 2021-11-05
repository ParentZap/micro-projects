import board
import digitalio
import neopixel
import time

led = digitalio.DigitalInOut(board.LED)
led.direction = digitalio.Direction.OUTPUT
button_a = digitalio.DigitalInOut(board.BUTTON_A)
# dist = digitalio.DigitalInOut(board.IR_PROXIMITY)
neo = neopixel.NeoPixel(board.NEOPIXEL, 10)
print(f"button a direction: {button_a.direction}")

while True:
    neo[0] = (200, 10, 200)
    if button_a.value == True:
        print("A is pressed!")
    # print(dist.)
    led.value = True
    print("ON!")
    time.sleep(0.5)
    led.value = False
    print("OFF!")
    time.sleep(0.5)