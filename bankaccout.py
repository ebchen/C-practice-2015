import random
class bank:
    def __init__(self, name, accountnumber, balance):
        self.name = name
        self.accountnumber = accountnumber
        self.balance = balance
    def __init__(self):
        self.name = ""
        self.accountnumber = 0
        self.balance = 0
        
    def makeaccount(self):
        self.name=raw_input("what is your name?")
        self.balance=float(raw_input("how much money do you want to initially depost?"))
        if self.balance < 250:
            print "sorry you have to deposit $250 or more"
        else:
            self.accountnumber = random.randint(100000,1000000000000)
            print "your account number is",self.accountnumber
        
    def getbalance(self):
        return self.balance

    def deposit(self):
        self.balance=self.balance+float(raw_input("How much money you want to deposit?"))
        return self.balance
    def getname(self):
        return self.name

stranger=bank()
stranger.makeaccount()
                                  
name=stranger.name
print name
print stranger.balance
stranger.deposit()
print stranger.getbalance()
