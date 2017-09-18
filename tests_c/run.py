# command:     python run.py
import glob
import os
# *.json and *.exp
test_jsons = glob.glob("*.json")
test_jsons.sort()
tests_json = []
for name in test_jsons:
  p = os.path.splitext(name);
  tests_json.append(p[0])
# test*32
test_pgms = glob.glob("test*32")
test_pgms.sort()
for name in test_pgms:
  print("=============================")
  print(name)
  print("=============================")
  if 'sql400json' in name:
    for jname in tests_json:
      print("=============================")
      print(name + " " + jname)
      print("=============================")
      os.system("./" + name + " " + jname);
  else:
    os.system("./" + name);
# test*64
test_pgms = glob.glob("test*64")
test_pgms.sort()
for name in test_pgms:
  print("=============================")
  print(name)
  print("=============================")
  os.system("./" + name);
  if 'sql400json' in name:
    for jname in tests_json:
      print("=============================")
      print(name + " " + jname)
      print("=============================")
      os.system("./" + name + " " + jname);
  else:
    os.system("./" + name);

