# Objektinis-Programavimas-labarotiniai-darbai
VU MIF studento Beno Sakalausko objektinio programavimo labaratoriniai darbai ir jų versijos
VU MIF studento Beno Sakalausko objektinio programavimo laboratoriniai darbai ir jų versijos
V0.1:

Užduotis:
Parašykite programą, kuri nuskaito šiuos studentų duomenis:
1. Vardą ir pavardę.
2. n atliktų namų darbų (nd) rezultatus (10-balėje sistemoje), o taip pat egzamino (egz) rezultatą.
3. Tuomet iš šių duomenų, suskaičiuoja galutinį balą (galutinis): 0.4 * vidurkis + 0.6 * egzaminas.

Užduoties atlikimas:

1. Susikuriame naują "Header" failą, kuriame būtų surašytos visos mūsų naudojamos bibliotekos
2. "Header" failas yra include'inamas į main.cpp failą.
3. Aprašoma struktūrą iš vardo, pavardės, pažymių, pažymių skaičiaus, egzamino ir galutinio pažymio indekso tam, kad galima būtų atskirti ar išvedimo metu naudosime medianą ar vidurkį.
4. Pagrindinis programos tikslas vietoj masyvų naudoti vektorius, todėl yra naudojamas struktūrinis vektorius.
5. Iš pradžių užpildome savo vektorių. Parašoma nauja void tipo funkcija vektoriui užpildyti.
6. Pildymo funkcija vyksta tol, kol vartotojas nusprendžia pats ją sustabdyti parašęs "Stop".
7. Pildymo funkcijos metu yra užpildomas vektorius vardais ir pavardėms, taip pat pildymo metu vartotojas yra paklaustas ar nori pats įrašyti pažymius ar nori, kad programa jam sugeneruotų automatiškai tiek, kiek vartotojas pats įveda.
8. Automatiniam programos įvedimui yra aprašoma atskira void tipo funkcija "atsitiktinis" ir random principu nuo 1 iki 10 yra parenkamas skaičius. Taip pat automatiškai sugeneruojamas egzamino balas.
9. Tam tikri vartotojų įvedimai yra tikrinami pvz.: Jeigu vartotojas turi įrašyti skaičių yra žiūrima ar visų pirma jis įrašė skaičių (tam yra naudojama atskira bool tipo funkcija "numeris", kurios metu stoi(string pav.) principu yra žiūrima ar vartotojas įrašė skaičių), tada yra tikrinama ar tas skaičius yra rėžiuose (pažymys negali būti didesniu už 10 arba neigiamas skaičius). Jeigu įvesta klaidingai konsolėje yra parašoma: "Klaidingas įvedimas".
10. Pabaigus pildymui grįžtame į main fukncija ir klausiama ar vartotojas nori, kad galutinis balas būtų skaičiuojamas su vidurkiu ar mediana.
11. Atitinkamai vidurkiui ir medianai yra parašomos atskiros double tipo funkcijos "vidurkis" ir "mediana".
12. Galiausiai vykdomas spausdinimas, kuomet į konsolę yra išvedama: vardas, pavardė, galutinis balas (vidurkio ir medianos skaičiavimais).
