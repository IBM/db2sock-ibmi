# description: Generate xlcmakefile
# command:     python genmake.py
import glob
import os
test_pgms = glob.glob("test*_32")
test_pgms.sort()
for name in test_pgms:
  print("=============================")
  print(name)
  print("=============================")
  os.system("./" + name);

test_pgms = glob.glob("test*_64")
test_pgms.sort()
for name in test_pgms:
  print("=============================")
  print(name)
  print("=============================")
  os.system("./" + name);

