# TODO

# First in a loop, prompt the user for a correct integer for height
while True:
    try:
        height = int(input("Height: "))
        if height > 0 and height < 9:
            break
    except ValueError:
        pass

for i in range(height):
    print(" " * (height - i - 1), end="")
    print("#" * ((i + 1)), end="")
    print("  ", end="")
    print("#" * ((i + 1)))