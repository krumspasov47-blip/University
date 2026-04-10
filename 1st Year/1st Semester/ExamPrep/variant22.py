class Market:
    def __init__(self, barcod, name, manufacturer, price, quantity):
        self.barcod = barcod
        self.name = name
        self.manufacturer = manufacturer
        self.price = price
        self.quantity = quantity

    def sale(self, quantity):
        if self.quantity >= quantity:
            self.quantity -= quantity
        else:
            print("Няма достатъчно количество")

    def discount(self):
        if 30 <= self.price <= 50:
            self.price *= 0.95
        elif 10 <= self.price <= 30:
            self.price *= 0.93

product_list = []

while True:
    try:
        n = int(input())

        if n > 0:
            break
        else:
            print()
    except ValueError:
        print()

for i in range(n):
    barcod = input()
    name = input()
    manufacturer = input()
    price = float(input())
    quantity = int(input())
    item = Market(barcod, name, manufacturer, price, quantity)
    product_list.append(item)

def search_by_barcod(product_list, barcod):
    for i in product_list:
        if i.barcod == barcod:
            print(i.barcod, i.name, i.manufacturer, i.price, i.quantity)
        else:
            print("Wrong barcode!!!")
            for i in product_list:
                print(i.barcod)

def search_by_manufacturer(product_list, manufacturer):
    result = []
    counter = 0
    sum = 0
    for i in product_list:
        if i.manufacturer == manufacturer:
            sum += i.price
            counter += 1

    if counter != 0:
        avg = sum / counter

    for i in product_list:
        if i.price <= avg and i.manufacturer == manufacturer:
            result.append(i)

    return result

def sort_by_quantity(product_list):
    return product_list.sort(key=lambda x: x.quantity)

def delete_by_name(product_list, name):
    for i in product_list:
        if i.name == name and i.quantity <= 3:
            product_list.remove(i)