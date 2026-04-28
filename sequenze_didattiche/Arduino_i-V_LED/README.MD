# 🖥️ Interfaccia LabVIEW 2009 - Arduino via Seriale (VISA)

**Guida per l'attività di laboratorio didattico**

Questo documento contiene le istruzioni per configurare, installare e utilizzare l'interfaccia sviluppata in LabVIEW 2009 per comunicare con una scheda Arduino tramite porta seriale, utilizzando i protocolli standard **VISA Read** e **VISA Write**.


---

## ⚙️ Guida all'Installazione (Software e Runtime)

Per eseguire il programma (`.exe` o il file `.vi` sorgente) su un PC dove non è installato l'ambiente di sviluppo completo di LabVIEW, è **tassativo** installare due componenti forniti da National Instruments.

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

## 📥 2. Guida all'Installazione di Arduino IDE

Per caricare il codice sulla scheda, è necessario l'ambiente di sviluppo ufficiale.

### Passo 1: Download
1. Scaricare dal sito ufficial [arduino.cc/en/software](https://www.arduino.cc/en/software) versione per il tuo sistema operativo utilizzato.
1. Avviare l'installer scaricato (`.exe`) 
2. Accettare i termini di licenza e procedere  con l'installazione standard.
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