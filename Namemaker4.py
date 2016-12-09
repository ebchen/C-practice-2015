List = []
print "Enter 5 names (press the Enter key after each name):"
for i in range(5):
    name = raw_input()
    List.append(name)

print "The names are:", List
print "Replace one name.  Which one? (1-5):",
replace = int(raw_input())
new = raw_input("New name: ")
List[replace - 1] = new
print "The names are:", List


