-main-Pregatim pachetul de joc, initializandu-l, citim datele si executam task-ul cerut.

-struct-Creez o structura pentru cartile de joc si o structura ce ma va ajuta la rollingstone,
 pentru lista ciclica de culori.

-functia initializare_culori- Creeaza lista circulara de culori.

-functia create- Creeaza o noua carte de joc, alocandu-i memorie si asociidu-i datele corespunzatoare.

-functia isEmpty- Verifica daca un anumit pachet de carti este gol sau nu.

-functia insert- Adauga o noua carte la sfarsitul pachetului.

-functia front_insert- Adauga o noua carte la inceputul pachetului.

-functia Top- Returneaza si elimina ultima carte din pachet.

-functia initializare_pachet- Pregateste pachetul de joc, initializandu-l, ca in cerinta.

-functia inversare- Realizeaza amestecarea pachetului, cu algoritmul de inversare.

-functia npiles- Realizeaza amestecarea pachetului, cu algoritmul de npiles.

-functia intercalare- Realizeaza amestecarea pachetului, cu algoritmul de intercalare.

-functia mongean- Realizeaza amestecarea pachetului, cu algoritmul de mongean.

-functia rs_carte_noua- Pentru rollingstone: returneaza prima carte de o culoare data a unui jucator
 specificat si o elimina din pachet, sau NULL, in cazul in care nu este gasita o asemnea carte.

-functia rs_terminat- Pentru rollingstone: verifica daca jocul a luat sfarsit sau nu.

-functia rollingstone- Distribuie cartile jucatorilor
                     - Gaseste cartea pe care o da jos cel care incepe jocul
                     - Gaseste cartile pe care le dau jos jucatorii, de culoarea cartii jucate de cel
                       ce a inceput
                     - Cand un jucator nu mai are carte de culoarea celei jucate de cel ce a inceput 
                       runda, ia toate cartile jucate in aceasta runda
                     - Verificam dupa fiecare carte pusa jos daca vreun jucator a ramas fara carti, 
                       adica daca jocul a luat sfarsit.

 