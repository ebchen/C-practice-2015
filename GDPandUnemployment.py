"""this program uses user inputed file to calculate average gdp and unemployment"""
#this function opens gdp file and calculates average gdp
def agdp(gdpfile,year):
    #next 2 lines opens and reads the gdp file
    f=open(gdpfile,"r")
    d1=f.readline()
    #next 2 lines splits the correct line into a list
    s1=d1.split()
    q1=s1[0].split("q")
    #identifies the year
    datayear=q1[0]
    #identifies the first quarter
    gdp1=s1[1]
    year=str(year)
    #keeps on looping until it find the correct year
    while datayear<>year:
        #isolates gdp for quarter 2
        d1=f.readline()
        s1=d1.split()
        #print s1
        q1=s1[0].split("q")
        datayear=q1[0]
        gdp1=s1[1]
    #isolates gdp for quarter 2
    d2=f.readline()
    s2=d2.split()
    gdp2=s2[1]
    #isolates gdp for quarter 3
    d3=f.readline()
    s3=d3.split()
    gdp3=s3[1]
    #isolates gdp for quarter 4
    d4=f.readline()
    s4=d4.split()
    gdp4=s4[1]
    #calculates average gdp
    averagegdp = (float(gdp1)+float(gdp2)+float(gdp3)+float(gdp4))/4
    f.close()
    return averagegdp
    
#this function opens the unemployment file and the calculates average unemployment
def aup(unempfile,year):
    #opens and reads the file
    f=open(unempfile,"r")
    d1=f.readline()
    #splits the line to seperate months
    s1=d1.split(",")
    #identifies year
    datayear=s1[0]
    unemp1=s1[1]
    year=str(year)
    #the while loop keeps on looping reading until it finds the right year
    while datayear<>year:
        d1=f.readline()
        s1=d1.split(",")
        datayear=s1[0]
        unemp1=s1[1]
    f.close()
    #defines total for the next loop
    total=0
    #the for loop loops through the 12 months adding them together
    for i in range(1,13):
        #print s1[i]
        total=total+float(s1[i])
    #divides by 12 to find average
    average=total/12
    return average
      

#this function identifies the year as a valid year only allowing integers inbetween 1947 and 2009  

def goodyear(year):
    year=int(year)
    while year < 1948 or year > 2008 or type(year)!=int:
        print "this year is invalid dumbo, insert  valid one(1948-2008)."
        year=raw_input("What year do you want(1948-2008)?")
        year=int(year)
    return year
   
#takes inputs from user
a=raw_input("Year to examine(1948-2008):")
a=goodyear(a)
b=raw_input("GDP file name:")
c=raw_input("Unemployment file name:")

#calls functions
apgdp=agdp(b,a)
agup=aup(c,a)
print "For" ,a, "average GDP:",apgdp,"and average unemployment:", agup
gy=goodyear(a)

    
