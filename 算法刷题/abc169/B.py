n=int(input())
a=map(int,input().split())

ans=1

for i in a:
	if(i==0):
		print("-1")
		exit()
	ans*=i
	if(ans>1000000000000000000):
		print("-1")
		exit()

print(ans)