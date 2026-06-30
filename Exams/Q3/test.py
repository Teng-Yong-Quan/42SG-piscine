import random
import subprocess

for _ in range(10000):
    a = random.randint(-10**50, 10**50)
    b = random.randint(-10**50, 10**50)

    expected = str(a * b)
    actual = subprocess.check_output(
        ["/home/42sg-piscine/Exams/Q3/inf_multi", str(a), str(b)],
        text=True
    ).strip()

    if expected != actual:
        print("Mismatch!")
        print(a)
        print('\n')
        print(b)
        print('\n')
        print(expected)
        print('\n')
        print(actual)
        print('\n')
        break
else:
    print("Passed 10000 tests!")