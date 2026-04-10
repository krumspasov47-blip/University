import random
while True:
    try:
        n = int(input("Enter a number: "))
        if 25 <= n <= 45:
            break
        else:
            print("wrong number")
    except ValueError:
        print("enter a whole number")

p = random.randint(-3700,-1600)
q = random.randint(2222,3333)

lst_1 = []

while n != 0:
    a = int(input("Enter a number: "))
    if p < a < q:
        lst_1.append(a)
        n -=1
    else:
        print()

counter = 0

for i in lst_1:
    if i > 0 and (i // 100) % 10 % 2 == 0:
        counter += 1

print(counter)

minv = None

for i in lst_1:
    if i % 6 == 3:
        if minv is None or i < minv:
            minv = i

if minv is None:
    print()
else:
    print(lst_1.index(minv))

lst_2 = []

for i in lst_1:
    if 10 <= abs(i) <= 99 and i % 5 == 0:
        lst_2.append(i)

print(lst_2)

result = 1

for i in range(1, len(lst_2), 2):
    result *= lst_2[i]

print(result)

for i in range(len(lst_2) -1 , -1, -1):
    if i % 2 != 0 and lst_2[i] % 2 == 0:
        del lst_2[i]

if len(lst_2) > len(lst_1):
    lst_1.insert(len(lst_1)//2, lst_1[0] + lst_1[-1])
elif len(lst_1) > len(lst_2):
    lst_2.insert(len(lst_2)//2, lst_2[0] + lst_2[-1])