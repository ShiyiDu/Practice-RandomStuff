def f(v,n):
    return min(25000 * (1+0.1)**(101-n-1) + v, 6000000 - 3000000*(1-0.05)**(101-n-1) + 25000 + v)
    
v = 6025000

for n in range(100,-1,-1):
    print ("s=",n)
    print("v(s)=",f(v,n))
    if f(v,n)==25000*(1+0.1)**(101-n - 1)+v:
        print("action = keep for an additional year")
    else: 
        print ("action = sell the old one and purchase a new one")
        break
    v = f(v,n)

  

