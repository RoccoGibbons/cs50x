def integerInput():
    while True:
        try:
            return int(input("Height: "))
        except ValueError:
            pass


height = integerInput()
for i in range(height):
    print(" " * (height - (i+1)) + "#" * i + " " + "#" * i)
