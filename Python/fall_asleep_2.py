class Sheep:
    x = 0
    name = "Just another sheep"

    def __init__(self, name=name):
        """I construct Sheep instances"""
        self.name = name
        print(f'{self.name} speaking: I am constructed :-)')

    def flock(self):
        self.x = self.x + 1
        print(f'{self.name} flock count: {self.x}')

    def __del__(self):
        print(f'{self.name} speaking: I am destructed :-(')

    def __str__(self):
        info = f'(x = {self.x}, name = {self.name})'
        return info

class Lamb(Sheep):
    siblings = 0

    def __str__(self):
        info = f'(x = {self.x}, name = {self.name}, siblings = {self.siblings})'
        return info

    def set_siblings(self, s):
        self.siblings = s
        print(f'{self.name} speaking: I have {self.siblings} siblings')
        for i in range(s):
            self.flock()
        
montauciel = Sheep("Montauciel")
montauciel.flock()
dolly = Lamb("Dolly")
dolly.flock()
dolly.set_siblings(3)
print(dolly)
print(montauciel)
