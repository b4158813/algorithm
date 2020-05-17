def pal(x):
	res=0
	while x:
		res=res*10+x%10
		x//=10
	return res

def ispal(x):
	s=str(x)
	length=len(s)
	for i in range(length//2):
		if(s[i]!=s[length-i-1]):
			return False
	return True

n,k=map(int,input().split())

step=0
if(ispal(n)):
	print(n)
	print(0)
	exit()
while(1):
	n+=pal(n)
	step+=1
	if(ispal(n)):
		break
	elif step==k:
		break
print(n)
print(step)