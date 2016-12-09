List = []
print "Enter 5 names enter after each name:"
for i in range(5):
    name = raw_input()
    List.append(name)

print "The names are:", List
print "The sorted names are:", sorted(List)
