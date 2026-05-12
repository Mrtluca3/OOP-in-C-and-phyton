class Sheep:
    members = []
    name = "Just another sheep"

    def __init__(self, name=name):
        """I construct Sheep instances"""
        self.name = name
        self.owners = []
        print(f'{self.name} speaking: I am constructed :-)')

    def flock(self):
        self.members.append(self.name)
        print(f'{self.name} flock count: {len(self.members)}')

    def __del__(self):
        print(f'{self.name} speaking: I am destructed :-(')

    def __str__(self):
        info = f'(members = {self.members}, name = {self.name})'
        return info

    def add_owner(self, shepard):
        self.owners.append(shepard)
        print(f'{self.name} owners count: {len(self.owners)}')

class Lamb(Sheep):
    siblings = 0

    def __str__(self):
        info = f'(members = {self.members}, name = {self.name}, siblings = {self.siblings})'
        return info

    def set_siblings(self, s):
        self.siblings = s
        print(f'{self.name} speaking: I have {self.siblings} siblings')
        for i in range(s):
            self.flock()


montauciel = Sheep("Montauciel")
montauciel.flock()
montauciel.add_owner("Montgolfier Bros.")
dolly = Lamb("Dolly")
dolly.flock()
dolly.add_owner("Mary")
dolly.set_siblings(3)
print(dolly.owners)
print(montauciel.owners)
