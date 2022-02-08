import sys
import csv

def main():
	i=0
	j=0
	profile = []
	with open(f"{sys.argv[1]}") as csvfile :
		reader = csv.reader(csvfile)
		for x in reader:
			profile.append(x)
			i+=1
		j=len(x)
	
	with open(f"{sys.argv[2]}") as text :
		seq = text.read ()
	
	for a in range(1,i,1):
		for b in range(1,j,1):
			profile[a][b] = int(profile[a][b])
	sample = []	
	for b in range(1,j,1):
		sample.append(highest_STR(seq,profile[0][b]))
			
	for a in range(1,i,1):
		if sample == profile[a][1:j]:
			print (profile[a][0])
			
		

def highest_STR(seq,STR):
	highest_count = 0
	for i in range(len(seq)-len(STR)+1):
		j = i+len(STR)
		if STR == seq[i:j]:
			count = STR_count(seq,STR,i,j)
			if count > highest_count:
				highest_count = count
	return highest_count			

def STR_count(seq,STR,a,b):
	i = 0
	number = 0
	gain = len(STR)
	while STR == seq[a+i:b+i]:
		number +=1
		i = i + gain
	return number
			
	
main()	


