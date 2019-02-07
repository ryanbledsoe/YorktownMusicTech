import time
import board
from digitalio import DigitalInOut, Direction, Pull
import neopixel

led = neopixel.NeoPixel(board.NEOPIXEL, 10)

buttonA = DigitalInOut(board.A1)
buttonA.direction = Direction.INPUT
buttonA.pull = Pull.UP

buttonB = DigitalInOut(board.A2)
buttonB.direction = Direction.INPUT
buttonB.pull = Pull.UP

led.brightness = 1


RED = (255, 0, 0)
GREEN = (127, 255, 0)
BLACK = (0, 0, 0)
PINK = (199, 21, 133)

on = False
pressed = False

while True:
    if not buttonA.value:  # button is pushed
        if not pressed:
            pressed = True
            if on:
                led.fill(BLACK)
                on = False
            else:
                led.fill(RED)
                on = True
    else:
        pressed = False

    time.sleep(0.1)