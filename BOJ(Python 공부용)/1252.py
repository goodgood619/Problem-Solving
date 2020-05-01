import sys

input = sys.stdin
x,y=[int(i,2)for i in input.readline().split()]
print(bin(x+y)[2:])