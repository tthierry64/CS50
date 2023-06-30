# TODO
from cs50 import get_string

# initialize variables
total_letters = 0
total_words = 1
total_sentences = 0
exception_sentences = ['.', '!', '?']

text = input("Text: ")

# count the number of letters, words and sentences
for i in range(int(len(text))):
    if text[i].isalpha():
        total_letters += 1
    elif text[i] == ' ':
        total_words += 1
    elif text[i] in exception_sentences:
        total_sentences += 1

print(total_letters)
print(total_words)
print(total_sentences)

# apply algorithm
L = total_letters / total_words * 100
S = total_sentences / total_words * 100
index = round(0.0588 * L - 0.296 * S - 15.8)

# Print results
if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print("Grade", index)