import sys

sys.path = ["../../lib/python/site-packages"] + sys.path

import computorv1
from computorv1 import Equation

eq1 = computorv1.Equation()
# eq2 = computorv1.Equation("x = x")
eq2 = computorv1.Equation("-S^3 - 1 = 0.0")

print (eq2.reduced_form())
# print (eq2.variable())
print (eq2.degree())
# print (eq2.solutions())

exit()

print (eq1.solutions()) # []
print (eq2.solutions()) # [1]

exit()

obj = mymodule.simpleObject()

print (obj.someFunction())

import computorv1

p1 = computorv1.parse("X^0 - 1 = 0");

print (computorv1.solutions())
