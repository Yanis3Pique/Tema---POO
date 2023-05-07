# Echipa de fotbal - Proiect, POO
<hr>

![Aici trebuia sa fie un GIF cu Pique](https://github.com/Yanis3Pique/Tema1---POO/blob/master/bar%C3%A7a-pique.gif?raw=true)
![Aici trebuia sa fie un GIF cu Messi](https://github.com/Yanis3Pique/Tema1---POO/blob/d074ce28b29489f7752b12f39a1915f9bec9f8e9/ezgif.com-resize.gif?raw=true)
<hr>

## Scurta descriere a temei
Am dezvoltat o aplicație interactivă care gestionează o echipă de fotbal într-o manieră simplă, folosind ideile fundamentale, de bază, ale programării orientate pe obiecte.

Programul este construit folosind zece clase: InvalidAgeException, InvalidNumberException, Angajat, Antrenor, Building, Stadion, Contract, Echipa, Jucator si Meci:

### Am proiectat aceste clase folosind compunerea si mostenirea, astfel:

#### Compunere:
- Echipa are un obiect de tip Antrenor (reprezentând antrenorul echipei)
- Echipa are un obiect de tip Stadion (reprezentând stadionul pe care joaca echipa)
- Meci are două obiecte de tip Echipa (reprezentând cele două echipe care au jucat un meci) și un obiect de tip Stadion(rerezentând stadionul pe care se desfasoara meciul)

#### Mostenire:
- InvalidAgeException și InvalidNumberException moștenesc public clasa exception
- Antrenor și Jucător moștenesc clasa Angajat
- Stadion moștenește public clasa Building
- Jucător moștenește privat clasa Contract

<hr>

### Aici este o listă cu funcționalitățile disponibile în aplicația actuală:

#### Clasa "InvalidAgeException":
- O excepție custom ce extinde clasa exception din biblioteca standard
- Folosită pentru gestionarea corectitudinii vârstei jucătorilor
<hr>

#### Clasa "InvalidNumberException":
- O excepție custom ce extinde clasa exception din biblioteca standard
- Folosită pentru gestionarea corectitudinii numărului de pe tricou al jucătorilor
<hr>

#### Clasa "Angajat":
- Reține informații despre un angajat, precum nume, vârstă și salariu
- Suprascrierea operatorului de afișare pentru afișarea informațiilor despre un angajat
<hr>

#### Clasa "Antrenor":
- Reține numărul de titluri pe care le are un antrenor în palmares
- Setarea/obținerea numelui antrenorului
- Setarea/obținerea vârstei antrenorului
- Setarea/obținerea salariului antrenorului
- Setarea/obținerea numarului de titluri ale antrenorului
- Suprascrierea operatorului de afișare pentru afișarea informațiilor despre antrenor
<hr>

#### Clasa "Building":
- O interfață. 
- Nu are date membre, ci doar două metode virtuale pure(descriere si marimeCladire) si un constructor virtual
<hr>

#### Clasa "Stadion":
- Reține numele și capacitatea unui stadion
- Setarea/obținerea numelui stadionului
- Setarea/obținerea capacității stadionului
- Metoda descriere suprascrisă - scrie un mesaj despre capacitatea stadionului
- Metoda marimeCladire suprascrisă - scrie un mesaj despre dimensiunea stadionului
- Suprascrierea operatorului de afișare pentru afișarea informațiilor despre stadion
<hr>

#### Clasa "Contract":
- Reține valoarea unui jucător
- Metodă virtuala protected getValue care modifică valoarea jucătorului în funcție de durata contractului său
- Destructor virtual
<hr>

#### Clasa "Echipa":
- Reține o lista statică de echipe, numele, antrenorul și stadionul unei echipe
- Setarea/obținerea numelui echipei
- Setarea/obținerea antrenorului echipei
- Setarea/obținerea stadionului echipei
- Obținerea adresei numelui echipei
- Suprascrierea operatorului de afișare pentru afișarea informațiilor despre echipa
<hr>

#### Clasa "Jucator":
- Reține o listă statică de pointeri de jucători, un contor static care se incrementează la fiecare nou jucător, un id constant, numărul de pe tricoul jucătorului, durata contractului, un pointer către echipa de care aparține jucătorul
- Setarea/obținerea numelui jucătorului
- Setarea/obținerea vârstei jucătorului
- Setarea/obținerea salariului jucătorului
- Setarea/obținerea numărului jucătorului
- Setarea/obținerea duratei contractului jucătorului
- Obținerea ID-ului jucătorului
- Conține o metodă protected care verifică dacă jucătorul a intrat în ultimele 6 luni de contract cu clubul său
- Suprascrierea operatorului de afișare "<<" pentru afișarea informațiilor despre jucător
- Suprascrierea operatorului de citire ">>" pentru citirea de la tastatură a informațiilor despre jucător
<hr>

#### Clasa "Meci":
- Setarea/obținerea echipei gazdă
- Setarea/obținerea echipei oaspete
- Setarea/obținerea stadionului
- Setarea/obținerea scorului gazdelor
- Setarea/obținerea scorului oaspeților
- Suprascrierea operatorului de afișare pentru afișarea informațiilor despre meci
<hr>

#### Descrierea "funcțiilor de business":
- Calculul salariului mediu al jucătorilor dintr-o echipă
- Calculul valorii totale dintr-o echipă
- Calculul vârstei medii dintr-o echipă
<hr>

#### Meniu interactiv ce permite:
- Introducerea unui jucător nou in lista cu jucători
- Afișarea tuturor jucătorilor din listă
- Afișarea unui jucător dupa ID-ul său
- Ștergerea unui jucător din listă dupa ID-ul său
<hr>

În plus, fiecare clasă oferă posibilitatea de a crea obiecte noi folosind constructori sau de a copia informațiile din alte obiecte folosind constructori de copiere și operatorul de atribuire. De asemenea, fiecare clasă gestionează memoria alocată pentru atributele dinamice folosind constructori și destructori.

Programul aruncă excepții specifice în cazul în care nu se respectă corectitudinea input-ului.