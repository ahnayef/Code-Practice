# %%
import math

# %%
def Es(n):
    return (0.5 * 10**(2-n) )
    

def Ea(current,prev): 
    return abs( ( (current-prev) / current ) * 100 )


def Et(trueValue, approximation):
    return abs( ((trueValue - approximation) / trueValue) * 100 )

# %%
ea = 1

es = 0.05

current_result = 1

x = 0.5

n = 1

while ea > es:
    prev_result = current_result
    current_result +=  (x ** n) / math.factorial(n)
    n+=1
    ea = Ea(current_result, prev_result)
    print([current_result,ea])



