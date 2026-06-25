class Sheep:
    members = []

    def __init__(self, name="Just another sheep"):
        """I construct Sheep instances"""
        self.name = name
        self.flock(self.name)

    def flock(self, name):
        self.members.append(name)
        print(f'{name} flock count: {len(self.members)}')

    def __str__(self):
        info = f'(members = {self.members}, name = {self.name})'
        return info


class Lamb(Sheep):
    siblings = 0

    def __str__(self):
        info = f'(members = {self.members}, name = {self.name}, siblings = {self.siblings})'
        return info

    def set_siblings(self, s):
        self.siblings = s
        [self.flock(self.name+str(i+1)) for i in range(s)]


class FlockNames(Sheep):
    """Iterator for looping over a flock of Sheep instances."""
    def __init__(self):
        self.data = Sheep.members
        self.index = -1

    # Return the iterator object itself
    def __iter__(self):
        return self

    # Return the next value from the sequence
    def __next__(self):
        # Raise StopIteration when the sequence ends
        if self.index == len(self.data)-1:
            raise StopIteration
        self.index = self.index + 1
        return self.data[self.index]

    def __str__(self):
        info = f'Flock iterator with members = {self.data}'
        return info 



dolly = Lamb("Dolly")
dolly.set_siblings(3)

it = iter(FlockNames())
print("print it: ", it) 

print(type(it), type(dolly))
[print(next(it)) for i in range(len(Sheep.members))]
print("Using instead: [print(i) for i in it] IT DOES NOT WORK!")
[print(i) for i in it]

print("------------------creating flocknames varible ----------")
flocknames = FlockNames()
print(flocknames)
[print(f) for f in flocknames]
print("----------Montaciel created now-----------")


montauciel = Sheep("Montauciel")
print(flocknames)
print("note: only missing arguments iterable are printed! !!")
[print(f) for f in flocknames]

print("----try with a list--")
it= iter(['a', 'b', 'c'])
print(type(it))
[print(next(it)) for i in range(3)]
