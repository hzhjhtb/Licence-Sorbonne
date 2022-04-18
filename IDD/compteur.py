def compteur(chaine):
    nb = 0
    
    for c in chaine:
        if (ord(c) > ord('A')) and (ord(c) < ord('Z')):
            nb += 1
        if (ord(c) > ord('a')) and (ord(c) < ord('z')):
            nb += 1
    
    return nb

print(compteur('Semi-annuel'))
