import sys, os

print("Running " + __file__)

print("Running " + os.path.basename(__file__))

print(f"Program called with {len(sys.argv)} arguments. Here they are")

for a in sys.argv:
    print(a)
