while True:
    try:
        n = int(input())
        if 15 < n < 35:
            break
        else:
            print()
    except ValueError:
        print()

lst1 = []

while n != 0:
    a = int(input())
    if 30 < a < 300:
        lst1.append(a)
        n -= 1
    else:
        print()

counter = 0

for i in lst1:
    if (i//10) % 10 % 2 == 0:
        counter += 1

print(counter)

minv = None

for i in lst1:
    if minv is None or minv > i:
        if i % 6 == 4:
            minv = i

print(lst1.index(minv))

lst2 = []

for i in lst1:
    if 10 <= abs(i) <= 99 and (i % 3 == 0 and i % 2 == 0):
        lst2.append(i)

counter2 = 0
suma = 0

for i in range(1, len(lst2), 2):
    suma += lst2[i]
    counter2 += 1

if counter2 > 0:
    avg = suma / counter2
else:
    avg = 0

print(avg)

minv2 = None
for i in lst2:
    if i % 2 == 0:
        if minv2 is None or minv2 > i:
            minv2 = i

lst2.remove(minv2)
print(lst2)
