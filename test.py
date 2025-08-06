# list miutable mining change able
list = [1,2,3,];
list[0] = 1000;
print(list)

tuple = (1,3,4,)
# tuple[0] = 11 no change able
print(tuple)

# Dictionary
dist = {'name' : "samin", 'roll' : 11}
print(dist['name'])

class Car:
    def drive(self):
        print("car is moving")

c = Car()
c.drive()
