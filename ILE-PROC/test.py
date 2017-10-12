import itertools
max = 5
r = []
for i in [0,4,8]:
  for j in range(0,max): 
    r.append(i)

val = []
res = []
v = itertools.permutations(r,max)
for p in v:
  if not p in val:
    val.append(p)
    pattern = ""
    for e in p:
      pattern += str(e)
    res.append(pattern);

res.sort()
i = 0
for pattern in res:
  i += 1
  print str(i) + ' - ' + pattern
