t = int(input())
for i in range(t):
    n = input()
    impossible = 0
    for j in range(len(n)):
        if int(n[j]) % 2 == 0:
            impossible = 1
    if int(n[len(n)-1]) % 2 == 0:
        print(0)
    elif int(n[0]) % 2 == 0:
        print(1)
    elif impossible == 0:
        print(-1)
    else:
        print(2)
