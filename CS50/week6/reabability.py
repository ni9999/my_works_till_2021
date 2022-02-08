sentence = 0
word = 0
letter = 0
a = int("b")
print (a)
z = "z"
para = input ("text : ")
for i in range(len(para)) :
	if para[i] == "." or para[i] == "!" or para[i] == "?":
		sentence +=1
	if para[i] == " " :
		word +=1
	else :
		for j in range(a,z):
			if para[i] == j:
				letter +=1
				
# in a 3-word sentence there is 2 spaces
word +=1
print (f"{sentence} sentence(s)")
print (f"{word} word(s)")
print (f"{letter} letter(s)")
