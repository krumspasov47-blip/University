
# TASK 1 - Operations with a list of integers
'''''''''
n = int(input("Enter number of elements: "))
lst = []


for i in range(n):
    lst.append(int(input(f"Element {i}: ")))

print("Original list:", lst)


print("Elements one by one:")
for x in lst:
    print(x)

value = int(input("Enter value to search: "))
print("Found!" if value in lst else "Not found!")


lst.sort()
print("Sorted list:", lst)


print("Max element:", max(lst))


index = int(input("Enter index to remove: "))
if 0 <= index < len(lst):
    lst.pop(index)


index = int(input("Enter index to modify: "))
if 0 <= index < len(lst):
    lst[index] = int(input("Enter new value: "))

print("Final list:", lst)

'''



# TASK 2 - Operations with list of strings
'''''''''
n = int(input("Enter number of strings: "))
lst = []


for i in range(n):
    lst.append(input(f"String {i}: "))


longest = max(lst, key=len)
print("Longest string:", longest)


target = input("Enter string to replace: ")
replacement = input("Enter new string: ")
lst = [replacement if x == target else x for x in lst]


to_delete = input("Enter string to delete: ")
if to_delete in lst:
        lst.remove(to_delete)

   
pos = int(input("Enter position to insert: "))
new_str = input("Enter new string: ")
lst.insert(pos, new_str)

print("Final list:", lst)

'''



# TASK 3 - Dictionary - operations with keys and values
'''''''''

m = int(input("Enter number of elements: "))
d = {}

for i in range(m):
    key = input("Key: ")
    value = int(input("Value: "))
    d[key] = value

key = input("Enter key to search: ")
print("Found!" if key in d else "Not found!")

key = input("Enter key to modify: ")
if key in d:
    d[key] = int(input("New value: "))

key = input("Enter key to delete: ")
if key in d:
    del d[key]

print("Keys:", list(d.keys()))
print("Values:", list(d.values()))

sorted_d = dict(sorted(d.items()))
print("Sorted dictionary:", sorted_d)

'''



# TASK 4 - Sets

'''''''''

n = int(input("Enter number of elements for set 1: "))
set1 = set(int(input() ) for _ in range(n))

m = int(input("Enter number of elements for set 2: "))
set2 = set(int(input() ) for _ in range(m))

print("Size of set1:", len(set1))
print("Size of set2:", len(set2))

print("Union:", set1 | set2)

print("Difference:", set1 - set2)

print("Intersection:", set1 & set2)

x = int(input("Enter element to remove from set1: "))
set1.discard(x)

set1.clear()
set2.clear()
'''