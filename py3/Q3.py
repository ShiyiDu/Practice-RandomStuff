import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# define three functions for each conditions
def f(x, n):
    return 50000*((20-n)/20) - (n/20)*x + x 

def g(x, m):
    return 35000*((50-m)/50) - (m/50)*x + x

#def h(x):
#    return -225000 + x

# define a function to find the values of each condition with responding condition                
def decision(a0, b0):
    num = 69
    m = 1
    n = 1
    a = np.zeros(num)
    b = np.zeros(num)
    v = np.zeros(num)
    c = np.zeros(num)
    a0 = f(100000, 1)
    b0 = g(100000, 1)
    a[0] = a0
    b[0] = b0
    v[0] = max(a[0], b[0])
    c[0] = -225000 + 100000
    r = []
    x = []
    y = []
    for i in range(0, num-1):
        if max(a[i],b[i],c[i]) == a[i]:
            r.append('hit')
            x.append(n)
            y.append(m)
            n = n+1
            v[i] = a[i]
            a[i+1] = f(v[i], n) 
            b[i+1] = g(v[i], m) 
            c[i+1] = c[i] + 50000*(n-1) + 35000*(m-1)
            v[i+1] = max(a[i+1], b[i+1], c[i+1]) 
        elif max(a[i],b[i],c[i]) == b[i]:
            r.append('snitch')
            x.append(n)
            y.append(m)
            m = m+1
            v[i] = b[i]
            a[i+1] = f(v[i], n) 
            b[i+1] = g(v[i], m) 
            c[i+1] = c[i] + 50000*(n-1) + 35000*(m-1)           
            v[i+1] = max(a[i+1], b[i+1], c[i+1]) 
        else:
            r.append('quit')
            a[i+1] = f(v[i], n) 
            b[i+1] = g(v[i], m) 
            c[i+1] = c[i] + 50000*(n-1) + 35000*(m-1)
            v[i+1] = max(a[i+1], b[i+1], c[i+1])
            break
    return a, b, v, c, r, x, y

a, b, v ,c, r, x, y = decision(0, 0)

# processing the data
#s = np.array(range(69,-1,-1))
yo = np.array([a, b, v, c])
#r.append('snitch')
#aha = np.array([1, 1, 1])
#x.append(1)
#x.append(1)
#x.append(1)
#y.append(1)
#y.append(1)
#y.append(1)

#print(x)

# built the dataframe
name = ['hit','snitch','value','quit']
df = pd.DataFrame(yo, index = name)
df = df.T
#df['action'] = r
#df['n'] = x
#df['m'] = y
#df = df.set_index(['S'])
#
print(df)
#
#plt.plot(s, v)


#df.to_excel('C:/Users/zhang/Desktop/data.xlsx', 'Sheet1')

#value = 173950
#f = f(value,2)
#g = g(value,2)
#h = h(value)
#print(f,g,h)






