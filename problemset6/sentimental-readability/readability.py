text = input("Text: ")

wordArray = text.split()

wordCount = 0
for word in wordArray:
    wordCount += 1

letterCount = 0
for letter in text:
    if (ord(letter) >= 65 and ord(letter) <= 90) or (ord(letter) >= 97 and ord(letter) <= 122):
        letterCount += 1

sentenceCount = 0
for character in text:
    if character in [".", "?", "!"]:
        sentenceCount += 1

L = 100 * (letterCount / wordCount)
S = 100 * (sentenceCount / wordCount)

grade = 0.0588 * L - 0.296 * S - 15.8

if grade < 1:
    print("Before grade 1")
elif grade > 16:
    print("Grade 16+")
else:
    print(f"Grade {round(grade)}")