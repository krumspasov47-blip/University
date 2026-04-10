
# Exercise 1
# Sum and average of even and odd numbers

'''''''''
n = int(input("Exercise 1 - Enter number of values: "))

sum_even = 0
sum_odd = 0
count_even = 0
count_odd = 0

for _ in range(n):
    x = int(input("Enter number: "))
    if x % 2 == 0:
        sum_even += x
        count_even += 1
    else:
        sum_odd += x
        count_odd += 1

avg_even = sum_even / count_even if count_even > 0 else 0
avg_odd = sum_odd / count_odd if count_odd > 0 else 0

print("Even sum:", sum_even)
print("Even average:", avg_even)
print("Odd sum:", sum_odd)
print("Odd average:", avg_odd)
'''

'''
# Exercise 2
# Max even number, min odd number, and counts


n = int(input("\nExercise 2 - Enter number of values: "))

max_even = None
min_odd = None
count_even = 0
count_odd = 0

for _ in range(n):
    x = int(input("Enter number: "))
    if x % 2 == 0:
        count_even += 1
        if max_even is None or x > max_even:
            max_even = x
    else:
        count_odd += 1
        if min_odd is None or x < min_odd:
            min_odd = x

print("Maximum even number:", max_even)
print("Minimum odd number:", min_odd)
print("Even count:", count_even)
print("Odd count:", count_odd)
'''

'''
# Exercise 3
# Check if a number is in interval [n, m]


n = int(input("\nExercise 3 - Enter n: "))
m = int(input("Enter m: "))
x = int(input("Enter number to check: "))

if n <= x <= m:
    print("The number is in the interval.")
else:
    print("The number is NOT in the interval.")
'''

'''
# Exercise 4
# Count and sum numbers within a user-defined interval


count = int(input("\nExercise 4 - Enter number of values: "))
a = int(input("Enter lower bound: "))
b = int(input("Enter upper bound: "))

interval_count = 0
interval_sum = 0

for _ in range(count):
    x = int(input("Enter number: "))
    if a <= x <= b:
        interval_count += 1
        interval_sum += x

print("Count in interval:", interval_count)
print("Sum in interval:", interval_sum)
'''

'''
# Exercise 5
# Raise n integers to a chosen power


n = int(input("\nExercise 5 - Enter number of values: "))
power = int(input("Enter power: "))

for _ in range(n):
    x = int(input("Enter number: "))
    print(f"{x} raised to power {power} = {x ** power}")

'''

'''
# Exercise 6
# Sum and product of positive numbers
# End input with -99


sum_positive = 0
product_positive = 1
has_positive = False

while True:
    x = int(input("\nExercise 6 - Enter number (-99 to stop): "))
    if x == -99:
        break
    if x > 0:
        sum_positive += x
        product_positive *= x
        has_positive = True

print("Sum of positive numbers:", sum_positive)

if has_positive:
    print("Product of positive numbers:", product_positive)
else:
    print("No positive numbers were entered.")
'''

'''
# Exercise 7
# Input a five-digit number.
# Print each digit separated by ":".
# Print sum and product of digits.

num = int(input("Enter a five-digit number: "))


d1 = num // 10000
d2 = (num // 1000) % 10
d3 = (num // 100) % 10
d4 = (num // 10) % 10
d5 = num % 10


print(f"{d1}:{d2}:{d3}:{d4}:{d5}")


digit_sum = d1 + d2 + d3 + d4 + d5
digit_product = d1 * d2 * d3 * d4 * d5

print("Sum:", digit_sum)
print("Product:", digit_product)
'''

'''
# Exercise 8
# Input integer NUM (5 < NUM < 15)
# Then input NUM numbers in range [-100, 100]
# Find:
# - average of positive numbers
# - count of positive and negative numbers
# - count of numbers divisible by 3 and 5
# - count of positive numbers with remainder 3 when divided by 6

NUM = int(input("\nEnter NUM (5 < NUM < 15): "))

positive_sum = 0
positive_count = 0
negative_count = 0
div_3_5_count = 0
rem_3_mod_6_count = 0

for i in range(NUM):
    x = int(input(f"Enter number {i+1}: "))


    if x > 0:
        positive_sum += x
        positive_count += 1


        if x % 6 == 3:
            rem_3_mod_6_count += 1

    elif x < 0:
        negative_count += 1


    if x % 3 == 0 and x % 5 == 0:
        div_3_5_count += 1


if positive_count > 0:
    avg_positive = positive_sum / positive_count
else:
    avg_positive = 0

print("Average of positive numbers:", avg_positive)
print("Count of positive numbers:", positive_count)
print("Count of negative numbers:", negative_count)
print("Count divisible by 3 and 5:", div_3_5_count)
print("Positive numbers with remainder 3 (mod 6):", rem_3_mod_6_count)

'''

# Exercise 9
# Reverse digits of a six-digit number
# without using arrays or lists

num = int(input("\nEnter a six-digit number: "))

reversed_num = 0


while num > 0:
    digit = num % 10
    reversed_num = reversed_num * 10 + digit
    num //= 10

print("Reversed number:", reversed_num)