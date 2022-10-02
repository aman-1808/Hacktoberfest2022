from cmath import *
from math import *
AB = int(raw_input())/2.0
BC = int(raw_input())/2.0
print str(int(round(degrees(phase(complex(BC,AB))))))+'°'
