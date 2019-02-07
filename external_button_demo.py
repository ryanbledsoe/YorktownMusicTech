# CircuitPlaygroundExpress_DigitalIO

import time

import board
from digitalio import DigitalInOut, Direction, Pull

led = DigitalInOut(board.D13)
led.direction = Direction.OUTPUT

button = DigitalInOut(board.A1)
button.direction = Direction.INPUT
button.pull = Pull.UP

while True:
    if button.value:  # button is pushed
        led.value = False
    else:
        led.value = True

    time.sleep(0.01)
