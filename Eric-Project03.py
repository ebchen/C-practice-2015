"""
The program will compute and display information for a utility company
which supplies water to its customers. For a specified customer, the program will compute and
display the amount of money which the customer will be billed for water usage during the
current billing period.
"""
#imports and easygui
import easygui
#finds customer code and meter marks and puts them into a list
def inputfromuser():
    code=easygui.choicebox("Which class are you?",
                           choices=['industrial','residential','commercial','z-END PROCESS'])
    if code=="z-END PROCESS":
        return [code,0,0]
    beginning=float(raw_input("what was your beginning meter reading?"))
    end = float(raw_input("what was your end meter reading?"))
    if beginning > 999999999 or end > 999999999:
        print "you should only have 9 digits in your meter"
    b=beginning/10
    e=end/10
    data=[code,b,e]
   
    return data

#uses the list data to calculate gallons and price and puts them into list price and gallons
def calculate(data):
    b=data[1]
    e=data[2]
    code=data[0]
        
    if b>e:
        gallons=99999999.9-b+e
    else:
        gallons=e-b

    if code=="residential":
        price=5+(0.0005*gallons)
        
    elif code=="commercial":
        if gallons <= 4000000:
            price= 1000
        else:
            price= 1000+(gallons-4000000)*0.00025
    elif code=="industrial":
        if gallons <= 4000000:
            price= 1000
        
        elif gallons > 4000000 and gallons<=10000000:
            price= 2000
            
        elif price>10000000:
            price=2000+(gallons-10000000)*0.00025
    priceandgallons=[gallons,price]
    return priceandgallons
#gathers information and prints it
def printdata(priceandgallons,data):
    code=data[0]
    b=data[1]
    e=data[2]
    gallons=priceandgallons[0]
    price=priceandgallons[1]
    print code
    print "beginning meter:",b*10
    print "end meter:",e*10
    print "gallons used:",gallons
    print '''price: $''',price
    print "*******************************************************************"
#tests to see if the customer code is z-END PROCESS and loops the code if it isnt.
d=inputfromuser()
code= d[0]
while code == "residential" or code == "commercial" or code == "industrial":
    r=calculate(d)
    printdata(r,d)
    code=inputfromuser()[0]
print "process ended."

    
            

