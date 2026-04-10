import random

while True:
    try:
        n = int(input("Enter a number: "))
        if 20 < n < 40:
            break
        else:
            print("Sorry, the number must be between 20 and 40.")
    except ValueError:
        print("Sorry, the input should be a whole number between 20 and 40.")


lst_1 = []

for i in range(n):
    lst_1.append(random.randint(2, 200))

x = min(lst_1)

lst_1.remove(x)

suma = 0

for i in range(0, len(lst_1), 2):
    suma += lst_1[i]


print(suma)

counter = 0

for i in lst_1:
    if i%10 == 0 :
        counter += 1

print(counter)

lst_2 = []

for i in lst_1:
    if i % 3 == 0 or i % 4 == 0:
        if not (i % 3 == 0 and i % 4 == 0):
            lst_2.append(i)

sum2 = 0
counter2 = 0

for i in lst_2:
    if i % 2 !=0 :
        sum2 += i
        counter2 += 1

if counter2 > 0:
    average = sum2 / counter2
else:
    average = 0

print(average)

if lst_2:
    y = max(lst_2)
    ind = lst_2.index(y)
    print(ind)