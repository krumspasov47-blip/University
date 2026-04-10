import math


# Exercise 1 Check if each number is greater than the sum of all previous numbers

def is_super_increasing(lst):
    total = 0
    for num in lst:
        if num <= total:
            return False
        total += num
    return True



# Exercise 2 Find median of a sorted list, round to nearest tenth if needed

def median_sorted(lst):
    n = len(lst)
    mid = n // 2

    if n % 2 == 1:
        return lst[mid]
    else:
        median = (lst[mid - 1] + lst[mid]) / 2
        return round(median, 1)



# Exercise 3 Return the name of the most valuable item

def most_valuable_item(d):
    return max(d, key=d.get)



# Exercise 4 Find two numbers with minimum difference, return them sorted

def min_difference_pair(lst):
    lst = sorted(lst)
    min_diff = float('inf')
    pair = []

    for i in range(len(lst) - 1):
        diff = abs(lst[i] - lst[i + 1])
        if diff < min_diff:
            min_diff = diff
            pair = [lst[i], lst[i + 1]]

    return pair



# Exercise 5 Check if rectangle fits in a circle


def rectangle_in_circle(width, height, radius):
    diagonal = math.sqrt(width**2 + height**2)
    return diagonal <= 2 * radius



# Exercise 6 Split words in half and sort alphabetically

def split_and_sort(words):
    result = []

    for word in words:
        mid = len(word) // 2
        result.append(word[:mid])
        result.append(word[mid:])

    return sorted(result)



# Exercise 7 Get all natural divisors of a number

def divisors(n):
    result = []
    for i in range(1, n + 1):
        if n % i == 0:
            result.append(i)
    return result


# Exercise 8 Return all non-unique elements

def non_unique(lst):
    result = []
    for x in lst:
        if lst.count(x) > 1:
            result.append(x)
    return result



# Exercise 9 Named tuple of students + function

from collections import namedtuple

Student = namedtuple("Student", ["name", "age", "grade", "city"])

def good_students(students):
    avg = sum(s.grade for s in students) / len(students)

    good = [s.name for s in students if s.grade >= avg]

    print(f"Students {', '.join(good)} are doing well this semester!")


students_data = (
    Student("Alice", 20, 5.5, "Sofia"),
    Student("Bob", 21, 4.0, "Plovdiv"),
    Student("Charlie", 19, 5.0, "Varna"),
    Student("Diana", 22, 5.8, "Burgas"),
    Student("Eve", 20, 4.5, "Ruse"),
    Student("Frank", 23, 6.0, "Sofia"),
    Student("Grace", 21, 5.2, "Varna"),
)



# Exercise 10 Sieve function: unique elements in reverse order (tuple)

def sieve(lst):
    unique = list(set(lst))
    unique.sort(reverse=True)
    return tuple(unique)


if __name__ == "__main__":
    print(is_super_increasing([1, 2, 4, 8]))
    print(median_sorted([1, 2, 3, 4]))
    print(most_valuable_item({"a": 10, "b": 20}))
    print(min_difference_pair([4, 2, 1, 3]))
    print(rectangle_in_circle(3, 4, 3))
    print(split_and_sort(["apple", "banana"]))
    print(divisors(12))
    print(non_unique([1,2,2,3,3,3,4]))
    good_students(students_data)
    print(sieve([1,2,2,3,4,4,5]))