import random

while True:
    try:
        n = int(input("Въдеди число между 10 и 50: "))
        assert n >= 10 and n <= 50
        break
    except AssertionError:
        print("Числото трябва да е между 1 и 50:")

mylst1 = [0] * n

a = random.randint(-2500, -1300)
b = random.randint(1111, 4444)

counter = 0
for i in range(n):
    mylst1[i] = int(input(f"Въведете число в интервала [{a}] [{b}]"))
    if mylst1[i] < 0 and ((abs(mylst1[i]) // 10) % 10 % 4 == 0 or (abs(mylst1[i]) // 10) % 10 % 5 == 0):
        counter += 1

print(f"Броят на отрицателните числа, чиято цифра от десетиците е кратна на 4 или 5 е: {counter} ")

counter2 = 0
sum = 0
for i in range(n):
    if abs(mylst1[i] % 2 == 0) and abs(mylst1[i]) > 9 and abs(mylst1[i]) < 100:
        sum += mylst1[i]
        counter2 += 1

print(f"Средно аритметичното от числта от елементите, чиято стойност е двуцифрена и четна е {sum/counter2:.2f}")

mylst2 = []

for i in range(n):
    if abs(mylst1[i] % 3 == 0) and abs(mylst1[i]) > 99:
        mylst2.append(mylst1[i])

counter3 = 0
for i in range(len(mylst2)):
    if mylst2[i] % 2 !=0 and mylst2[i].index % 2 == 0:
        counter3 += 1

for i in range(len(mylst2)):
    if i % 2 != 0:
        mylst2[i] = 13

if len(mylst1) != len(mylst2):
    if len(mylst1) < len(mylst2):
        del mylst2[0]
        del mylst2[-1]
    else:
       del mylst1[0]
       del mylst1[-1]