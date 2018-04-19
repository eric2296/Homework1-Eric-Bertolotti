# Homework1-Eric-Bertolotti

La soluzione adottata si struttura in:

# 3 Nodi:
* **Menu:** Nodo funzionale all'interazione con l'utente. Permette di selezionare quale parte del messaggio visualizzare.
            Questo nodo fa da client inviando  un messaggio con la scelta dell'utente al noodo listener(il quale funge da Service).
            Il menu continua a comparire permettendo nuove scelte sino a quando si preme 'q' per uscire.
* **Listener:** Nodo che comunica con entrambi gli altri nodi. In sostanza fa da service per il nodo menu prendendo la scelta inviata dal                 menu e attiva il talker filtrando i dati che arrivano da questo in base alla scelta dell'utente 
            
