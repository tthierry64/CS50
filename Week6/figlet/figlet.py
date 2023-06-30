import sys
import random
from pyfiglet import Figlet

figlet = Figlet()
figlet_list = figlet.getFonts()

if (len(sys.argv) == 1):
    font_set = random.choice(figlet_list)


elif (len(sys.argv) == 3 and sys.argv[1] in ["-f","--font"]):
        font_set = sys.argv[2]

if (len(sys.argv) not in [1, 3]):
    sys.exit("Invalid usage")
if (len(sys.argv) == 3 and sys.argv[1] not in ["-f","--font"]):
    sys.exit("Invalid usage")
if (len(sys.argv) == 3 and sys.argv[1] in ["-f","--font"] and sys.argv[2] not in figlet_list):
    sys.exit("Invalid usage")

txt = input("Input: ")

figlet.setFont(font=font_set)
print(figlet.renderText(txt))
