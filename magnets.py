import functools
 
l = [int(input()) for i in range(int(input()))]
l.insert(0, (1, l[0]))
print(functools.reduce(lambda x, y: (x[0] + 1, y) if y != x[1] else x, l)[0])