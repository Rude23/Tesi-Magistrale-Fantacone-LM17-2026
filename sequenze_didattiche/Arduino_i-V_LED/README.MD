# LABORATORIO SUI LED CON ARDUINO 

Questo repository contiene l'interfaccia per Arduino sviluppata in LabVIEW per misurare la caratteristica i-V, non lineare,  di un LED e osservare come sia radicalmente diversa da quella di un resistore ohmico, lineare.

L'archivio [LED_R.zip](./LED_R.zip) contiene sia il codice sorgente sia l'eseguibile compilato. Inoltre è presente una simulazione, compilata dallo stesso codice sorgente, che può essere utilizzata per svolgere l'attività come laboratorio virtuale senza utilizzare Arduino.

Per eseguire i programmi (`.exe`) su un PC dove non è installato l'ambiente LabVIEW completo, è **tassativo** installare due componenti forniti da National Instruments: la runtime e i driver VISA.

---

## ⚙️ Guida all'Installazione LabVIEW

### Passo A: Installazione del LabVIEW 2009 Run-Time Engine (RTE)
Il Run-Time Engine permette al PC di eseguire gli eseguibili compilati con LabVIEW 2009.
1. Scaricare dal [sito ufficiale di National Instruments (NI)](https://www.ni.com/en/support/downloads/software-products/download.labview-runtime.html) la versione 2009SP1 per il sistema operativo usato.
2. Eseguire l'installer eguendo la procedura guidata.

**Nota bene:** Su Windows 10/11, potrebbe essere necessario avviare l'installer con i privilegi di Amministratore o in Modalità Compatibilità (Windows 7).

### Passo B: Installazione dei driver NI-VISA
**Fondamentale:** Senza questo pacchetto, i nodi *VISA Read* e *VISA Write* andranno in errore, poiché il PC non saprà come gestire le porte COM virtuali.
1. Scaricare dal [sito NI l'installer **NI-VISA**](https://www.ni.com/en/support/downloads/drivers/download.ni-visa.html) l'installer della versione supportata per il sistema operativo usato.
2. Eseguire l'installer selezionando il supporto per **Serial/COM**.
3. **Riavviar il computer**.

## 📥 Guida all'Installazione di Arduino IDE

Per caricare il codice sulla scheda, è necessario l'ambiente di sviluppo ufficiale.

1. Scaricare dal sito ufficial [arduino.cc/en/software](https://www.arduino.cc/en/software) versione per il tuo sistema operativo utilizzato.
2. Avviare l'installer scaricato (`.exe`) 
3. Accettare i termini di licenza e procedere  con l'installazione standard.

**Importante:** Se durante l'installazione Windows chiede il permesso di installare "Driver di dispositivo" da Arduino srl o Adafruit, cliccare sempre su **Installa**.

---

## 🔧 Risoluzione dei Problemi (Troubleshooting)

### ❌ Errore LabVIEW: "VISA Resource Not Found" (o errore -1073807202)
* **Sintomo:** Il menu a tendina della porta seriale è vuoto o il programma crasha all'avvio.
* **Causa:** I driver NI-VISA non sono installati o il servizio è interrotto.
* **Soluzione:** 
  1. Assicurati di aver installato **NI-VISA Runtime**.
  2. Controlla in "Gestione Dispositivi" (Windows) che Arduino sia elencato sotto la voce "Porte (COM e LPT)".
  3. Se Arduino non appare, prova a cambiare porta USB o cavo.

### ❌ Arduino non viene riconosciuto dal PC
* **Sintomo:** "Dispositivo USB non riconosciuto" o errore driver in Gestione Dispositivi.
* **Causa:** Mancanza del driver del chip seriale (spesso il chip CH340 per gli Arduino compatibili).
* **Soluzione:** Scarica e installa i **driver CH340** se la tua scheda non è una versione originale "Made in Italy".