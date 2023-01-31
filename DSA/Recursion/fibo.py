# def fibo(n):
#     if n==1 or n==2:
#         return 1
#     else:
#         return fibo(n-1)+fibo(n-2)

# n= int(input("Enter n: "))
# print("The",n,"th fibonacci term is ",fibo(n))
table = dict()
def mfibo(n):
    if n==1 or n==2:
        return 1
    else:
        if n not in table:
            table[n] = mfibo(n-1) + mfibo(n-2)
        return table[n]
n = int(input("Enter n: "))
print("The",n,"th Fibonacci term is ",mfibo(n))
