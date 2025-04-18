import cs50

while True:
    height = cs50.get_int("Height: ")
    if height in range(1, 9):
        break

y = height - 1
z = 1

for i in range(height):
    print(" " * y + "#" * z)
    y -= 1
    z += 1
