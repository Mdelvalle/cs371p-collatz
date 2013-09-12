import random

f = open('RunCollatz.in', 'w')

for i in range(1000):
	r = str(random.randint(0, 999999)) + " " + str(random.randint(0, 999999)) + "\n"
	f.write(r)

f.close()
