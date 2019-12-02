DATA_FILE = "../data/day_01_1.txt"


def read_values(fin):
    with open(fin) as f:
        return [int(v) for v in f.readlines() if v]


def calc_fuel(weight):
    fuel = weight // 3 - 2
    if fuel <= 0:
        return 0

    return fuel + calc_fuel(fuel)


def main():
    values = read_values(DATA_FILE)
    fuel = sum([calc_fuel(value) for value in values])

    print(fuel)


if __name__ == "__main__":
    main()
