import csv
teams=[]
        
i=0
with open('2018m.csv') as csvfile:

    reader = csv.DictReader(csvfile)
    for row in reader:
        print(row)
        teams.append(row)
        teams[i]["rating"]=int(teams[i]["rating"])
        i=i+1

print (teams[1]["rating"]+teams[2]["rating"])


