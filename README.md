# Homework1-Eric-Bertolotti

La soluzione adottata si struttura in:

# 3 Nodi:
* **Menu:** Nodo funzionale all'interazione con l'utente. Permette di selezionare quale parte del messaggio visualizzare.
            Questo nodo fa da client inviando  un messaggio con la scelta dell'utente al noodo listener(il quale funge da Service).
            Il menu continua a comparire permettendo nuove scelte sino a quando si preme 'q' per uscire.
* **Listener:** Nodo che comunica con entrambi gli altri nodi. In sostanza fa da service per il nodo menu, prendendo la scelta inviata da                 quest'ultimo e attivando il talker, filtra poi i dati che arrivano da questo in base alla scelta dell'utente. Riceve i dati dal talker tramite il topic chatter_pub,
* **Talker:** Nodo attivato dal listener nel momento in cui arriva la scelta dell'utente. Questo nodo legge i dati da un file(data.txt) e li trasmette al listener tramite il topic " **chatter_pub** ".

# Topic:
  **chatter_pub:** Permette la comunicazione tra talker e listener.
# Srv:
  **menu.srv:** File che descrive il service tra Menu e Listener. E' composto da due parti request e response. La request è la scelta fatta dall'utente, mentre la response è la risposta del listener.
# Launch:
E' stato creato un file launch, il quale avvia il Menu e il Listener, dopodichè in base alla scelta effettuata dall'utente, il listener attiva il talker e si mette in ascolto dei dati provenienti da questo. Prima di avviare il file launch è necessario modificare correttamente il percorso del file di input **data.txt** nel **talker.cpp**.  
