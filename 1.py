# import sys, os.path
# if(os.path.exists("in.txt")):
#     sys.stdin = open("in.txt","r")
#     sys.stdout = open("out.txt","w")
import math as m

t = int(input())
while t > 0:
    t -= 1
    x = input()
    y = x.split(' ')
    
    a = int(y[0])
    b = int(y[1])
    c = int(y[2])
    d = int(y[3])

    ans1 = m.pow(a, b)
    ans2 = m.pow(c, d)

    if ans1 == ans2:
        print("Lazy")
    elif ans1 > ans2:
        print("HaHa")
    else:
        print("Congrats")
