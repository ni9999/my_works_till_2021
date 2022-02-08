t = int(input())
for i in range(t):
    math = int(input())
    prog = int(input())
    maxteams = int((math + prog)/4)
    if maxteams > math:
        print(math)
    elif maxteams > prog:
        print(prog)
    else:
        print(maxteams)