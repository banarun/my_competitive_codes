ap = int(raw_input())

for i in range(0,ap):
	s=raw_input().split()
	a=int(s[0])
	b=int(s[1])
	c=int(s[2])
	if a > b:
		temp=a
		a=b
		b=temp
	if a > c:
		temp=a
		a=c
		c=temp
	if b > c:
		temp=b
		b=c
		c=temp
	total=(a*b*c-a*(b-1)-a*(c-1)-(b-a)*a-a*(a-1)-a)%(1000000000+7)
	print total
	s=raw_input().split()
