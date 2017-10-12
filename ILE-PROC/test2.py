import itertools
max = 4
r = []
for i in range(0,9):
  for j in range(0,max): 
    r.append(i)
v = itertools.permutations(r)
for a in v:
  print a
  pattern = ""
  for e in p:
    pattern += str(e)
  if not pattern in res:
    res.append(pattern)

res.sort()
for r in res:
  print r
