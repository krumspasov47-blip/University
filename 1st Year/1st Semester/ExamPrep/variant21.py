import random

while True:
    try:
        n = int(input())
        if 10 < n < 50:
            break
        else:
            print("Please enter a number between 10 and 50")
    except ValueError:
        print("Please enter a number between 10 and 50")

a = random.randint(-2500, -1300)
b = random.randint(1111, 4444)

mylst_1 = []

while n !=0:
    x = int(input())
    if a <= x <= b:
        mylst_1.append(x)
        n-=1

counter = 0

for i in mylst_1:
    if (i//10) % 4 == 0 or (i//10) % 5 == 0:
        counter += 1

print(counter)

sum = 0
counter2 = 0

for i in mylst_1:
    if 10<= i <= 99 and i % 2 == 0:
        sum += i
        counter2 += 1

print(sum/counter2)

mylst_2 = []

for i in mylst_1:
    if 100 <= i <= 999 and i % 3 == 0:
        mylst_2.append(i)

counter3 = 0

for i in mylst_2:
    if mylst_2.index(i) % 2 == 0 and i % 2 != 0:
        counter3 += 1

print(counter3)

for i in mylst_2:
    if mylst_2.index(i) % 2 != 0:
        i = 13

if len(mylst_2) > len(mylst_1):
    mylst_2.pop(0)
    mylst_2.pop()

if len(mylst_1) > len(mylst_2):
    mylst_1.pop(0)
    mylst_1.pop()