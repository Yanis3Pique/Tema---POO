# Echipa de fotbal - Tema 1, POO
<hr>

![Aici trebuia sa fie un GIF cu Pique](https://media.tenor.com/OPVgBaJsXUgAAAAd/barça-pique.gif)
![Aici trebuia sa fie un GIF cu Messi](https://media.tenor.com/N8LDDGZsyzgAAAAd/barca-messi.gif)
<hr>

## Scurta descriere a temei
Am dezvoltat o aplicație interactivă care gestionează o echipă de fotbal într-o manieră simplă, folosind ideile fundamentale, de bază, ale programării orientate pe obiecte.

Programul este construit folosind cinci clase: Jucator, Stadion, Antrenor, Echipa si Meci:

### Am proiectat aceste clase folosind compunerea, astfel:

- Echipa are un obiect de tip Antrenor (reprezentând antrenorul echipei)
- Echipa are un obiect de tip Stadion (reprezentând stadionul pe care joaca echipa)
- Echipa are un vector cu obiecte de tip Jucator (reprezentând jucătorii dintr-o echipă)
- Meci are două obiecte de tip Echipa (reprezentând cele două echipe care au jucat un meci)

<hr>

### Aici este o listă cu funcționalitățile disponibile în aplicația actuală:

#### Clasa "Jucator":

- Setarea/obținerea numelui jucătorului
- Setarea/obținerea poziției jucătorului
- Setarea/obținerea vârstei jucătorului
- Setarea/obținerea salariului jucătorului
- Setarea/obținerea valorii jucătorului
- Suprascrierea operatorului de afișare pentru afișarea informațiilor despre jucător
<hr>

#### Clasa "Antrenor":

- Setarea/obținerea numelui antrenorului
- Setarea/obținerea vârstei antrenorului
- Setarea/obținerea salariului antrenorului
- Setarea/obținerea experienței antrenorului
- Suprascrierea operatorului de afișare pentru afișarea informațiilor despre antrenor
<hr>

#### Clasa "Echipa":

- Setarea/obținerea numelui echipei
- Adăugarea/ștergerea jucătorilor din echipă
- Adăugarea/ștergerea antrenorilor din echipă
- Setarea/obținerea numărului de jucători din echipă
- Setarea/obținerea bugetului echipei
- Suprascrierea operatorului de afișare pentru afișarea informațiilor despre echipă
<hr>

#### Clasa "Stadion":

- Setarea/obținerea numelui stadionului
- Setarea/obținerea locației stadionului
- Setarea/obținerea capacității stadionului
- Suprascrierea operatorului de afișare pentru afișarea informațiilor despre stadion
<hr>

#### Clasa "Meci":

- Setarea/obținerea echipei gazdă
- Setarea/obținerea echipei oaspete
- Setarea/obținerea scorului final al meciului
- Suprascrierea operatorului de afișare pentru afișarea informațiilor despre meci.
<hr>

#### Descrierea "funcțiilor de business":
- Calculul salariului mediu al jucătorilor dintr-o echipă
- Calculul valorii totale dintr-o echipă
- Calculul vârstei medii dintr-o echipă
<hr>

În plus, fiecare clasă oferă posibilitatea de a crea obiecte noi folosind constructori sau de a copia informațiile din alte obiecte folosind constructori de copiere și operatorul de atribuire. De asemenea, fiecare clasă gestionează memoria alocată pentru atributele de tip șir de caractere folosind constructori și destructori.