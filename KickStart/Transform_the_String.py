def solution():
    S = input()
    F = input()
    S = set(S)
    F = set(F)
    print(S,F)

T = input()
for i in range(int(T)):
    print("Case #{0}: {1}".format(i+1, solution()))

