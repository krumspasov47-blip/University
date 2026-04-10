class ClothesShop:
    def __init__(self, clothes_type, brand, price, quantity, size):
        self.clothes_type = clothes_type
        self.brand = brand
        self.price = price
        self.quantity = quantity
        self.size = size

    def sale(self, quantity):
        if quantity <= self.quantity:
            self.quantity -= quantity
        else:
            raise ValueError("Not enough quantity available")

    def discount(self):
        if 1 <= self.quantity <= 3:
            self.price *= 0.65
        elif 4 <= self.quantity <= 6:
            self.price *= 0.85

    def __repr__(self):
        return f"{self.brand} {self.clothes_type} ({self.size}) - {self.price:.2f}лв, qty:{self.quantity}"


# --- Functions --- #
def search_by_size_type(clothes_list, size, ctype):
    same = [c for c in clothes_list if c.size == size and c.clothes_type == ctype]
    if not same:
        return []
    avg_price = sum(c.price for c in same) / len(same)
    return [c for c in same if c.price < avg_price]


def cheapest_clothes(clothes_list, brand):
    items = [c for c in clothes_list if c.brand == brand]
    return min(items, key=lambda c: c.price) if items else None


def sort_clothes(clothes_list):
    return sorted(clothes_list, key=lambda c: c.price, reverse=True)


def delete_by_type(clothes_list, ctype):
    return [c for c in clothes_list if not (c.clothes_type == ctype and c.quantity <= 2)]


# --- Sample data --- #
clothes_list = [
    ClothesShop("T-shirt", "Nike", 40, 3, "M"),
    ClothesShop("T-shirt", "Adidas", 35, 5, "M"),
    ClothesShop("Jacket", "Puma", 90, 7, "L"),
    ClothesShop("T-shirt", "Nike", 25, 2, "M"),
    ClothesShop("Jeans", "Levi’s", 60, 1, "L"),
]

# Apply discounts
for c in clothes_list:
    c.discount()

print("After discounts:")
print(clothes_list)

# Search by size & type
print("\nSearch M-size T-shirts cheaper than average:")
print(search_by_size_type(clothes_list, "M", "T-shirt"))

# Cheapest by brand
print("\nCheapest Nike item:")
print(cheapest_clothes(clothes_list, "Nike"))

# Sort by price
print("\nSorted by price descending:")
print(sort_clothes(clothes_list))

# Delete by type
print("\nAfter deleting T-shirts with qty <= 2:")
print(delete_by_type(clothes_list, "T-shirt"))
