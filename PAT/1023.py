x=int(input())
xxx=xx=x*2

dic={0:0,1:0,2:0,3:0,4:0,5:0,6:0,7:0,8:0,9:0}
while x!=0:
	dic[x%10]+=1
	x//=10

xxx=xx
dic2={0:0,1:0,2:0,3:0,4:0,5:0,6:0,7:0,8:0,9:0}
while xx!=0:
	dic2[xx%10]+=1
	xx//=10

f=True

for i in range(10):
	if dic[i]!=dic2[i]:
		f=False
		print('No')
		break

if f:
	print('Yes')
print(xxx)