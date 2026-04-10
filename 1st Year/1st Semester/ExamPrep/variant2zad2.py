class Market:
    def __init__(self, barcod, name, manufacturer, price, quantity):
        self.barcod = barcod
        self.name = name
        self.manufacturer = manufacturer
        self.price = price
        self.quantity = quantity
    def sale(self, quantity):
        if quantity <= self.quantity:
            self.quantity -= quantity
        else:
            print("Няма достъчно количество")
    def discount(self):
        if 30 <= self.price <= 50:
            self.price *= 0.95
        elif 10 <= self.price <= 30:
            self.price *= 0.93

product_list = []

n = int(input("Въведете брой на артикули: "))

for i in range(n):
    barcod = int(input("Въведете баркод:"))
    name = input("Въведете име:")
    manufacturer = input("Въведете производител:")
    price = float(input("Въведете цена:"))
    quantity = int(input("Въведете количество:"))
    item = Market(barcod, name, manufacturer, price, quantity)
    product_list.append(item)

def search_by_barcod(prduct_list, barcod):
    if barcod not in product_list:
        print("Wrong barcode !!!")
        print("Налични баркодове:", [i.barcod for i in product_list])
    else:
        for item in product_list:
            if item.barcod == barcod:
                print(item.name, item.manufacturer, item.price, item.quantity)

def search_by_manufacturer(product_list, manufacturer):
    manufacturer_list = [i for i in product_list if i.manufacturer == manufacturer]
    avg = sum(i.price for i in manufacturer_list) / len(manufacturer_list)
    result = [i for i in manufacturer_list if i.price <= avg]

    return result

def sort_by_quantity(product_list):
    result = sorted(product_list, key=lambda item: item.quantity)
    return result

def delete_by_name(product_list, name):
    for item in product_list:
        if item.name == name and item.quantity <=3:
            product_list.remove(item)

