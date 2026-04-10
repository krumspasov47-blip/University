import random

mylst_15 = []

for i in range(15):
    mylst_15.append(random.randint(-10000, -1))


print(max(mylst_15))

suma = 0

for i in mylst_15:
    suma += i

print(suma)

mylst_dev3 = []

for i in mylst_15:
    if i % 3 == 0:
        mylst_dev3.append(i)


mylst_dev3.sort()

del mylst_dev3[1::2]