MAX = 1000000
D = [1]*(MAX+1)
S = [0]*(MAX+1)

for i in range (2, MAX+1):
    j=1
    while (i*j<=MAX):
        D[i*j]+=i
        j+=1

for i in range(1, MAX+1):
    S[i] = S[i-1]+D[i]

T = int(input())
ans = []
for i in range(T):
    N = int(input())
    ans.append(S[N])

print('\n'.join(map(str,ans))+'\n')



    