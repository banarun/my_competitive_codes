import random, sys

def passm(a, s, d, n):
    apow = pow(a, d, n)
    if apow == 1:
        return True
    for i in xrange(s-1):
        if apow == n - 1:
            return True
        apow = (apow * apow) % n
    return apow == n - 1

def miller_rabin(n):
    d = n - 1
    s = 0
    while d % 2 == 0:
        d >>= 1
        s += 1
    for repeat in xrange(20):
        a = 0
        while a == 0:
            a = random.randrange(n)
        if not passm(a, s, d, n):
            return False
    return True
if __name__ == "__main__":
	ap = int(raw_input())
	for tes in range(0,ap):
		n = long(raw_input())
		while miller_rabin(n)==False:
			n=n-1
		print n 
    
