class Person:
    def __init__(self, last_name, age, salary):
        self.last_name = last_name
        self.age = age
        self.salary = salary


class Employee(Person):
    def __init__(self, last_name, age, salary, position):
        super().__init__(last_name, age, salary)
        self.position = position


# Function to input multiple people
def input_people():
    people = []
    try:
        n = int(input("Enter number of people: "))
        for _ in range(n):
            people.append(add_person())
    except ValueError:
        print("Invalid input! Please enter a number.")
    return people


# Function to add one person
def add_person():
    try:
        last_name = input("Last name: ")
        age = int(input("Age: "))
        salary = float(input("Salary: "))
        position = input("Position: ")
        return Employee(last_name, age, salary, position)
    except ValueError:
        print("Invalid data! Try again.")
        return add_person() # retry


# Print only basic data
def print_basic(people):
    for p in people:
        print(f"{p.last_name}, Age: {p.age}, Salary: {p.salary}")


# Find person with lowest salary
def lowest_salary(people):
    if people:
        p = min(people, key=lambda x: x.salary)
        print(f"Lowest salary: {p.last_name} -> {p.salary}")


# Find oldest person
def oldest_person(people):
    if people:
        p = max(people, key=lambda x: x.age)
        print(f"Oldest: {p.last_name} -> {p.age}")


# Delete one person by last name
def delete_person(people):
    name = input("Enter last name to delete: ")
    people[:] = [p for p in people if p.last_name != name]


# Delete all people
def delete_all(people):
    people.clear()
    print("All people deleted.")


# Sort by age
def sort_by_age(people):
    people.sort(key=lambda x: x.age)


# Print positions
def print_positions(people):
    for p in people:
        print(f"{p.last_name} -> {p.position}")


# Average salary of people under 35
def avg_salary_under_35(people):
    try:
        filtered = [p.salary for p in people if p.age < 35]
        avg = sum(filtered) / len(filtered) # may cause division by 0
        print(f"Average salary (under 35): {avg:.2f}")
    except ZeroDivisionError:
        print("No people under 35!")


# Menu-driven program
def menu():
    people = []

    while True:
        print("\n--- MENU ---")
        print("1. Input people")
        print("2. Add one person")
        print("3. Print basic data")
        print("4. Lowest salary")
        print("5. Oldest person")
        print("6. Delete person")
        print("7. Delete all")
        print("8. Sort by age")
        print("9. Print positions")
        print("10. Average salary under 35")
        print("0. Exit")

        choice = input("Choose: ")

        if choice == "1":
            people = input_people()
        elif choice == "2":
            people.append(add_person())
        elif choice == "3":
            print_basic(people)
        elif choice == "4":
            lowest_salary(people)
        elif choice == "5":
            oldest_person(people)
        elif choice == "6":
            delete_person(people)
        elif choice == "7":
            delete_all(people)
        elif choice == "8":
            sort_by_age(people)
        elif choice == "9":
            print_positions(people)
        elif choice == "10":
            avg_salary_under_35(people)
        elif choice == "0":
            break
        else:
            print("Invalid choice!")


# Run program
if __name__ == "__main__":
    menu()