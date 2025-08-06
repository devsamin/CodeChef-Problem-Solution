# preant class

class Parson:
    def __init__(self, name, roll):
        self.name = name
        self.roll = roll

    def showInfo(self):
        print(f"Name : {self.name} Roll {self.roll}")

class Student(Parson):
    def __init__(self, name, roll, age):
        super().__init__(name, roll)
        self.age = age
    
    def studentInfo(self):
        self.showInfo()
        print(f"Age : {self.age}")


s = Student("samin", 11, 30)
s.studentInfo()

    