from cs50 import get_float


def main():

    while True:
        change = get_float("Change owed: ")
        if change >= 0:
            break

    cents = round(change * 100)

    coins = 0

    coins += cents // 25  # Quarters
    cents %= 25

    coins += cents // 10  # Dimes
    cents %= 10

    coins += cents // 5   # Nickels
    cents %= 5

    coins += cents // 1   # Pennies

    print(coins)


if __name__ == "__main__":
    main()
