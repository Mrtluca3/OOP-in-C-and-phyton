class Sheep:
    name = "Just another sheep"

    def __init__(self, name=name):
        """I construct Sheep instances"""
        self.name = name
        self.owners = []
        self.flock()
        print(f'{self.name} speaking: I am constructed :-)')

    def flock(self):
        global flock
        flock += 1
        print(f'{self.name} flock count: {flock}')

    def __del__(self):
        print(f'{self.name} speaking: I am destructed :-(')

    def __str__(self):
        info = f'(name = {self.name})'
        return info

    def add_owner(self, shepard):
        self.owners.append(shepard)
        print(f'{self.name} owners count: {len(self.owners)}')

    @staticmethod
    def try_to_talk():
        print("Baaaahhh!")

class Lamb(Sheep):
    siblings = 0

    def __str__(self):
        info = f'(name = {self.name}, siblings = {self.siblings})'
        return info

    def set_siblings(self, s):
        self.siblings = s
        print(f'{self.name} speaking: I have {self.siblings} siblings')
        for i in range(s):
            self.flock()

flock = 0
montauciel = Sheep("Montauciel")
montauciel.add_owner("The big bad wolf")
dolly = Lamb("Dolly")
dolly.add_owner("Mary")
dolly.set_siblings(3)
print(dolly.owners)
print(montauciel.owners)
print(flock)
flock += 1
print(flock)

# Class Sheep can talk
Sheep.try_to_talk()

# As can Sheep instances
dolly = Sheep()
dolly.try_to_talk()
