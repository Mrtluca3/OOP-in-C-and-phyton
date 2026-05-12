import example11

print('===== Running example12.py ===== ')

x = float(input("Insert x:"))
y = example11.line(x)
print(y)

# A much shorter way
print(example11.line(float(input("Insert x:"))))
