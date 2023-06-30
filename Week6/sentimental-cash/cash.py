from cs50 import get_float


# Ask how many cents the customer is owed
# function that prompt the user the change is owed
while True:
    try:
        cents = get_float("Change owed: ")
        if cents > 0:
            break
    except ValueError:
        pass

cents = cents * 100

coins = 0

while cents >= 25:
    cents = cents - 25
    coins += 1

# or in this order:
# coins = cents // 25
# cents %= 25


while cents >= 10:
    cents = cents - 10
    coins += 1

while cents >= 5:
    cents = cents - 5
    coins += 1

while cents >= 1:
    cents = cents - 1
    coins += 1

print (coins)
