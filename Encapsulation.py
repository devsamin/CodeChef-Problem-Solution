class Bankaccount:
    def __init__(self):
        self.__blance = 0
    
    def deposit(self, amount):
        if(amount > 0):
            self.__blance+=amount
    def get_blance(self):
        return self.__blance
acc = Bankaccount()
acc.deposit(4000)
# print(acc.__blance) not access
print(acc.get_blance())