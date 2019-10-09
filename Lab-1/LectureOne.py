# Fix point iteration
# use actual cube root
x = -1.4
for i in range(0, 20):
    x = ((30*x + 36)**float(1./3))
    print(x)
