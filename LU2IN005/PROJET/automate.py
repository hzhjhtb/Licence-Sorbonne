# -*- coding: utf-8 -*-
from transition import *
from state import *
import os
import copy
from sp import *
from parser import *
from itertools import product
from automateBase import AutomateBase



class Automate(AutomateBase):
        
    def succElem(self, state, lettre):
        """State x str -> list[State]
        rend la liste des états accessibles à partir d'un état
        state par l'étiquette lettre
        """
        successeurs = []
        # t: Transitions
        for t in self.getListTransitionsFrom(state):
            if t.etiquette == lettre and t.stateDest not in successeurs:
                successeurs.append(t.stateDest)
        return successeurs


    def succ (self, listStates, lettre):
        """list[State] x str -> list[State]
        rend la liste des états accessibles à partir de la liste d'états
        listStates par l'étiquette lettre
        """
        # states: set[State]
        states = set()
        ## on ajoute chque état successeur de chaque état de la liste 
        for i in listStates:
        	states = states | set(self.succElem(i,lettre))
        return list(states)




    """ Définition d'une fonction déterminant si un mot est accepté par un automate.
    Exemple :
            a=Automate.creationAutomate("monAutomate.txt")
            if Automate.accepte(a,"abc"):
                print "L'automate accepte le mot abc"
            else:
                print "L'automate n'accepte pas le mot abc"
    """
    @staticmethod
    def accepte(auto,mot) :
        """ Automate x str -> bool
        rend True si auto accepte mot, False sinon
        """
        listStates = auto.getListInitialStates()
        # l: char
        for l in mot:
        	listStates = auto.succ(listStates,l)
        # state: State
        for state in listStates:
        	if state in auto.getListFinalStates():
        		return True 	
        return False	
        


    @staticmethod
    def estComplet(auto,alphabet) :
        """ Automate x str -> bool
         rend True si auto est complet pour alphabet, False sinon
        """
        # l: char
        for l in alphabet:
        	# state: State
        	for state in auto.listStates:
        		if auto.succElem(state,l) == []:
        			return False
        return True


        
    @staticmethod
    def estDeterministe(auto) :
        """ Automate  -> bool
        rend True si auto est déterministe, False sinon
        """
        if len(auto.getListInitialStates()) != 1:
        	return False
        else:
        	# l: char
        	for l in auto.getAlphabetFromTransitions():
        		# state: State
        		for state in auto.listStates:
        			if len(auto.succElem(state,l)) > 1 :
        				return False
        return True
        

       
    @staticmethod
    def completeAutomate(auto,alphabet) :
        """ Automate x str -> Automate
        rend l'automate complété d'auto, par rapport à alphabet
        """
        if Automate.estComplet(auto,alphabet):
        	return auto
        auto_complet = copy.deepcopy(auto)
        ## on cherche un indice libre pour state_plus
        indice_libre = 0;
        indices = set()
        for state in auto.listStates:
        	indices = indices | {state.id}
        while (indice_libre in indices):
        	indice_libre = indice_libre-1
        # state_plus: State
        state_plus = State(indice_libre, False, False, "état +")
        auto_complet.addState(state_plus)
       	## on complete l'automate 
       	# state: State
        for state in auto_complet.listStates:
       		# l: char
       		for l in alphabet:
        		if auto.succElem(state,l) == []:
        			# t: Transition
        			t = Transition(state,l,state_plus)
        			auto_complet.addTransition(t)
        return auto_complet

       

    @staticmethod
    def determinisation(auto) :
        """ Automate  -> Automate
       	rend l'automate déterminisé d'auto
        """       
        if Automate.estDeterministe(auto):
        	return auto
        ## on crée le P(X) 
        # P_states : List[set(State.id)]
        P_states = [[]]
        # on argumente les elelments dans P_states par état  
        for state in auto.listStates:
        	# on crée P_temp pour le boucle suivant
        	P_temp = [m for m in P_states]
        	for p_state in P_temp:
        		# on ajoute un nouveau sous-ensemble de listStates qui contient 				  state dans P_states
        		p_ajoute = [n for n in p_state]
        		p_ajoute.append(state)
        		P_states.append(p_ajoute)
        # on retire [] dans P_states donc card(P_states) est bien (2**N)-1
        P_states.pop(0);
        # I : set[State.id]
        I = set()
        for initial in auto.getListInitialStates():
        	I.add(initial.id)
        # F : set[State.id]
        F = set()
        for final in auto.getListFinalStates():
        	F.add(final.id)		
        ##on crée tous les états et un dictionnaire
        # dico : dictionnaire
        dico1 = {}
        # dico : dictionnaire
        dico2 = {}
        # cpt : int 
        cpt = 0
        for p_state in P_states:
        	state_set = set()
        	for state in p_state:
        		state_set.add(state.id)
        	cpt = cpt + 1	
        	# il faut évaluer si le depart est initial ou final
        	if state_set == I:
        		if state_set.isdisjoint(F):
        			state_deter = State(cpt,True,False,state_set)
        		else: 
        			state_deter = State(cpt,True,True,state_set)	
        	else:
        		if state_set.isdisjoint(F):
        			state_deter = State(cpt,False,False,state_set)
        		else:
        			state_deter = State(cpt,False,True,state_set)
        	dico1[cpt] = state_set
        	dico2[cpt] = state_deter
        ## on crée tous les transitions au fur et à mesure  
        # liste_transitions : List[transition]
        liste_transitions = []
        # l : char
        for l in auto.getAlphabetFromTransitions():
        	for p_state in P_states:
        		depart_set = set()
        		for state in p_state:
        			depart_set.add(state.id)
        		dest_set = set()
        		for state in auto.succ(p_state,l):
        			dest_set.add(state.id)
        		if (depart_set == set()) or (dest_set == set()):
        			continue	
        		# on connect les deux dico
        		for k in dico1.keys():
        			if dico1[k] == depart_set:
        				indice1 = k
        			if dico1[k] == dest_set:
        				indice2 = k	
				# on crée la transition
        		t = Transition(dico2[indice1],l,dico2[indice2])
        		liste_transitions.append(t)
        ### on crée l'automate par la liste des transitions du nouveau automate
        return Automate(liste_transitions) 
        
    @staticmethod
    def complementaire(auto,alphabet):
        """ Automate -> Automate
        rend  l'automate acceptant pour langage le complémentaire du langage de a
        """
              
   
    @staticmethod
    def intersection (auto0, auto1):
        """ Automate x Automate -> Automate
        rend l'automate acceptant pour langage l'intersection des langages des deux automates
        """
        return

    @staticmethod
    def union (auto0, auto1):
        """ Automate x Automate -> Automate
        rend l'automate acceptant pour langage l'union des langages des deux automates
        """
        return
        

   
       

    @staticmethod
    def concatenation (auto1, auto2):
        """ Automate x Automate -> Automate
        rend l'automate acceptant pour langage la concaténation des langages des deux automates
        """
        return
        
       
    @staticmethod
    def etoile (auto):
        """ Automate  -> Automate
        rend l'automate acceptant pour langage l'étoile du langage de a
        """
        return




