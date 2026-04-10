class ClothesShop:
    def __init__(self, clothes_type, brand, price, quantity, size):
        self.clothes_type = clothes_type
        self.brand = brand
        self.price = price
        self.quantity = quantity
        self.size = size

    def sale(self, quantity):
        if quantity > 0 and quantity <= self.quantity:
            self.quantity -= quantity

    def discount(self):
        if 1 <= self.quantity <= 3:
            self.price *= 0.65
        elif 4 <= self.quantity <= 6:
            self.price *= 0.85

clothes_list = []

while True:
    try:
        k = int(input())
        if k > 0:
            break
        else:
            print()
    except ValueError:
        print()

for i in range(k):
    clothes_type = input()
    brand = input()
    price = float(input())
    quantity = int(input())
    size = int(input())
    item = ClothesShop(clothes_type, brand, price, quantity, size)
    clothes_list.append(item)

def search_by_size_type(clothes_list, size, clothes_type):
    count = 0
    suma = 0
    for i in clothes_list:
        suma += i.price
        count += 1

    if count > 0:
        avg = suma / count
    else:
        avg = 0

    result = [i for i in clothes_list if i.size == size and i.clothes_type == clothes_type and i.price < avg]
    return result

def cheapest_clothes(clothes_list, brand):
    brand_products = [i for i in clothes_list if i.brand == brand]
    if brand_products:
        brand_products.sort(key=lambda x: x.price)
        print(brand_products[0])
    else:
        print("brand is not available")
        print({i.brand for i in clothes_list})


def sort_clothes(clothes_list):
    clothes_list.sort(key=lambda x: x.price, reverse=True)
    for i in clothes_list:
        print(i)

def delete_by_type(clothes_list, clothes_type):
    for i in range(len(clothes_list)-1, -1, -1):
        if clothes_list[i].clothes_type == type and clothes_list[i].quantity < 2:
            del clothes_list[i]