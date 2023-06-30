exception_sentences = ['.', '!', '?']
total_sentences = 0

text = input("Text: ")

# count the number of letters, words and sentences
for i in range(int(len(text))):
    if text[i] in exception_sentences:
        total_sentences += 1

print(total_sentences)