# Prova intermedia di programmazione

#### *Segmentation Fault (core dumped)*

### 1. How to Compile:

**In main directory**

- Launch `cmake . -B <cmake-configuration-folder>`. This will create the cmake configuration folder. Note: this can't be
  named `bin`
- Run `cmake --build <cmake-configuration-folder>`. This will create a `bin` folder and will build the actual executable

At the end of the process you should be in a very similar situation

```
<Project Folder>
│   README.md
│   .gitignore
│   CMakeLists.txt    
│
└───include
│   │   ...
│
└───src
│   │   ...
│   
└───<cmake-configuration-folder>
│   │   ...
│
└───bin
│   │   <executable>
│   
```


### 2. Statement ToDo
##### Progettare e implementare la classe Book che rappresenta un libro in una biblioteca. Tale classe ha membri per contenere:
- [x] ISBN
- [x] Titolo
- [x] Nome e cognome autore (due membri diversi)
- [x] Data di copyright – la data è rappresentata usando una apposita classe Date simile a quella sviluppata a lezione;
- [x] Stato in prestito / disponibile

##### - [ ] Il codice ISBN può essere rappresentata mediante una std::string oppure una classe dedicata. In ogni caso, l’ISBN deve avere il formato n-n-n-x, con n intero e x una singola cifra o una lettera (i quattro campi sono separati da un carattere ‘-’).
- [x] Done
##### La classe Book deve essere dotata di:
- [x] Funzioni membro che ritornano i vari campi
- [ ] Costruttori
- [ ] Funzioni per registrare il prestito e la restituzione
- [x] Appositi strumenti (eventualmente implementati nella classe dedicata) per la validazione del formato ISBN e della data
- [x] `operator==` e `operator!=` che confrontano due libri basandosi sul codice ISBN
- [x] `operator<<` che stampa titolo, autore, ISBN e la data di copyright su righe separate in output

##### La classe Book (e le altre eventuali classi) devono essere correttamente separate nei file .h e .cpp e deve essere prevista la creazione di librerie dedicate.
- [x] Done
##### Un ulteriore file .cpp deve contenere il main, usato per i test.
- [x] Done
##### È apprezzato l’utilizzo di Cmake. 
- [x] Done

##### Oltre ai test necessari per lo sviluppo, devono essere compilabili le seguenti istruzioni:
- [x] `std::vector<Book> shelf(10)`;
- [x] `Book my_favourite_book(“David”, “Foster Wallace”, “Una cosa divertente
  che non farò mai più”, “887-521-837-4”)`;