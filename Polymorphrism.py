class Animal:
    def sound(self):
        print("some sound")

class Cat(Animal):
    def sound(self):
        print("Meow")

class Dog(Animal):
    def sound(self):
        print("goeow")

def make_sound(animal):
    animal.sound()

make_sound(Dog())