import random
ts=0
rl=0
td=0
l1 = 'too simple'
l2 = 'right level'
l3 = 'too difficult'
for i in range (30):
    c = random.choice([l1,l2,l3])
    if c == l1:
        ts = ts + 1
    elif c == l2:
        rl = rl + 1
    else:
        td = td + 1
print ts , "people think it is too simple."
print rl , "people think it is the right level."
print td , "people think it is too difficult."

if ts>rl and ts>td:
    print "most of the students thought that the class was too simple"
elif rl>ts and rl>td:
    print "most of the class thought that the class was the right level"
elif td>rl and td>ts:
    print "most of the class thought that the class was too difficult."

print "it is random"
