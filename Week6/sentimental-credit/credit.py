# TODO

from cs50 import get_string

# Ask the card number
while True:
    try:
        num_card = get_string("Number: ")
        if int(num_card) > 0:
            break
    except ValueError:
        pass

# starting from the end of the card number,  multiply each even numbers by 2 and make the sum = sum 1
# make the sum of every odd numbers and make sum 2
# the total sum = sum1 + sum2 . If its last digit is 0 -> valid
# to make it easier compared with C, we can converte the num card wich is a string into a list of integer,
# sorted by reverse
num_card = num_card[::-1]

sum_even = 0
sum_odd = 0

# we can now easily make the sum of every even digits
# if the digit has 2 digits ex: 23. The result is i %10 = 3  + i // 10 = 2     total = 3 + 2 = 5
for i in num_card[1::2]:
    i = int(i) * 2
    if i >= 10:
        sum_even += i % 10 + i // 10
    else:
        sum_even += i

# we can now easily make the sum of every odd digits
for j in num_card[::2]:
    sum_odd += int(j)

total = sum_even + sum_odd

num_cardb = num_card[::-1]
print(num_cardb[0:2])

L = int(len(num_card))

if total % 10 != 0:
    print("INVALID")
elif L == 15 and ((num_cardb[0:2] == "34") or num_cardb[0:2] == "37"):
    print("AMEX")
elif L == 13 or L == 16 and (num_cardb[0:1] == "4"):
    print("VISA")
elif L == 16 and (int(num_cardb[0:2]) >= 51 and int(num_cardb[0:2]) <= 55):
    print("MASTERCARD")
else:
    print("INVALID")