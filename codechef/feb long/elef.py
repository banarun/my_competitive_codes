
ap = int(raw_input())
for ite in range(0,ap):
	n=int(raw_input())
	dummy=raw_input().split()
	p=1
	for i in range(0,n):
		p=p*2
	if n%2 == 1:
		print (p/2)%1000000007
	if n%2 == 0:
		dif=1
		for i in range(0,n/2):
			dif=(dif*n)/(i+1)
			n=n-1
		p=((p-dif)/2)%1000000007
		print p
