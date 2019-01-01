pi=2
last=2
n=int(input("请输入n:"))
for i in range(1,n):
    last=float(last)*i/(2*i+1)
    pi=float(pi)+last
print (pi)
n= int(input("按任意键结束..."))