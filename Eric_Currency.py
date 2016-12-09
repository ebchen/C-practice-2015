class Eric_Currency:
    __init__(self,amount=0,cc="USD",clarification):
        self.amount=amount
        self.cc=cc
        self.clarification=clarification
    __str__(self):
        return str(amount)+" "+cc
    convert_to(self,cc2):
