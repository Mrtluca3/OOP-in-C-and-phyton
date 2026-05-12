import example11

print("++++ executing file: "+ __file__)

print("Calling example11.line(2.34, q=0.5): ", example11.line(2.34, q=0.5))

# Any object in mymodule can be used and there is no confusion with local a
a = 'a string!'
print("example11.a: ", example11.a)
print("local a: ", a)
