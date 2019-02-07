import time
import board
from digitalio import DigitalInOut, Direction, Pull
import neopixel

led = neopixel.NeoPixel(board.NEOPIXEL, 10)

buttonA = DigitalInOut(board.BUTTON_A)
buttonA.direction = Direction.INPUT
buttonA.pull = Pull.DOWN

buttonB = DigitalInOut(board.BUTTON_B)
buttonB.direction = Direction.INPUT
buttonB.pull = Pull.DOWN

led.brightness = 1

RED = (255, 0, 0)
GREEN = (127, 255, 0)
BLACK = (0 ,0, 0)
PINK = (199, 21, 133)


while True:
    if buttonA.value:  # button is pushed
        led.fill(PINK)
        time.sleep(0.1)
        led.fill(BLACK)
        time.sleep(0.1)
        led.fill(PINK)
        time.sleep(0.5)
        led.fill(BLACK)
    elif buttonB.value:
        led.fill(RED)
    else:
        led.fill(BLACK)

    time.sleep(0.01)
