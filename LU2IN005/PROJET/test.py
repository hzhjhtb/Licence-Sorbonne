# -*- coding: utf-8 -*-
"""
Code modifiable.
"""

from automate import Automate
from state import State
from transition import Transition
from parser import *

#automate = Automate.creationAutomate("exempleAutomate.txt")
#automate.show("exempleAutomate")

## création d'états
# s0 : State
s0 = State(0, True, False, "état 0")
# s1 : State
s1 = State(1, False, False, "état 1")
# s2 : State
s2 = State(2, False, True, "état 2")

## création de transitions
# t1 : Transition
t1 = Transition(s0,"a",s0)
# t2 : Transition
t2 = Transition(s0,"b",s1)
# t3 : Transition 
t3 = Transition(s1,"a",s2)
# t4 : Transition
t4 = Transition(s1,"b",s2)
# t5 : Transition
t5 = Transition(s2,"a",s0)
# t6 : Transition
t6 = Transition(s2,"b",s1)

## création de l'automate
# auto,auto1 : Automate
auto = Automate([t1,t2,t3,t4,t5,t6])
auto1 = Automate([t1,t2,t3,t4,t5,t6],[s0,s1,s2])

print(auto)
auto.show("A_ListeTrans")
print(auto1)
auto1.show("A1_ListeTrans")
## auto est bien indentique à auto1

# auto2 : Automate
auto2 = Automate.creationAutomate("auto2.txt")
print(auto2)
auto2.show("A2_listeTrans")

# t : Transition
t = Transition(s0,"a",s1)
auto.removeTransition(t)
print(auto)
auto.removeTransition(t1)
print(auto)
auto.addTransition(t1)
print(auto)
## la fonction "addTransition" ajoute t1 dans la dernière de la queue

auto.removeState(s1)
print(auto)
auto.addState(s1)
# s3 : State
s3 = State(0, True, False, "état 3")
auto.addState(s3)
print(auto)  

print(auto1.getListTransitionsFrom(s1))

print(auto2.succElem(s1,"b"))
print(auto2.succ([s0,s1,s2],"a"),"\n")


if Automate.accepte(auto1,"abb"):
	print("L'automate accepte le mot abb\n")
else:
   	print("L'automate n'accepte pas le mot abb\n")


if Automate.estComplet(auto,{"a","b"}):
	print("L'automate est complet\n")
	print(auto)
else:
	print("L'automate n'est pas complet\n")
	print(Automate.completeAutomate(auto,{"a","b"}))


if Automate.estDeterministe(auto1):
	print("L'automate est déterministe\n")
else:
	print("L'automate n'est pas déterministe\n")


auto3 = Automate.creationAutomate("auto3.txt")
print(auto3)
if Automate.estDeterministe(auto3):
	print("L'automate est déterministe\n")
else:
	print("L'automate n'est pas déterministe\n")
	print(Automate.determinisation(auto3))
	Automate.determinisation(auto3).show("A3_listeTrans")
	

print(Automate.complementaire(auto,{"a","b"}))

auto4_1 = Automate.creationAutomate("testInter1.txt")
print(auto4_1)
auto4_2 = Automate.creationAutomate("testInter2.txt")
print(auto4_2)
auto4 = Automate.intersection(auto4_1,auto4_2)
print(auto4)
auto4.show("A4_listeTrans")
Automate.union(auto4_1,auto4_2).show("A5_listeTrans")


auto5_1 = Automate.creationAutomate("testConca1.txt")
print(auto5_1)
auto5_2 = Automate.creationAutomate("testConca2.txt")
print(auto5_2)
Automate.concatenation(auto5_1,auto5_2).show("A6_listeTrans")

