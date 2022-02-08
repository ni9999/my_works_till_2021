n=0
i = 0
j=0
n = int(input("Height: "))
while True:
	if n<1 or n>8 :
		n = int(input("Height: "))
	else:
		for i in range(n):
			for j in range(n-i):
				print (" ",end = "")
			for j in range(i+1):
				print("#",end = "")
			print ()
		break
