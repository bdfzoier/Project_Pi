pi=2
last=2
n= int(input())
for i in range(1,n):
    last=float(last)*i/(2*i+1)
    pi=float(pi)+last
print (pi)
