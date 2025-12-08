a=int(input())
s=[]
for i in range(a):
	n,m=map(int,input().split())
	if(n//2)>=m:
		s.append(1)
	else:
	    s.append(0)
for i in range(a):
	if s[i]==0:
		print('No')
	else:
		print('Yes')