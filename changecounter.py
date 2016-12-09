quarters=float(raw_input("quarters: "))
dimes=float(raw_input("dimes: "))
nickels=float(raw_input("nickels: "))
pennies=float(raw_input("pennies: "))
def change(quarters,dimes,nickels,pennies):
    return(quarters*0.25+dimes*0.1+nickels*0.05+pennies*0.01)

total=change(quarters,dimes,nickels,pennies)

print "quarters:",quarters
print "dimes:",dimes
print "nickels:",nickels
print "pennies:",pennies
print "total is:",total
