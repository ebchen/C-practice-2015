import easygui
print "Multi \tNumber \tProduct"
f= easygui.enterbox("Which times table would you like?")
h= easygui.enterbox("How high do you want the table to go?")
for looper in range(1,int(h)+1):
    print looper,'\t',f,'\t',looper * int(f)
    
