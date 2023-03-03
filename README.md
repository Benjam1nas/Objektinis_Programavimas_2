# Objektinis-Programavimas-labarotiniai-darbai
VU MIF studento Beno Sakalausko objektinio programavimo laboratoriniai darbai ir jų versijos
V0.1:

Užduotis:
Parašykite programą, kuri nuskaito šiuos studentų duomenis:
1. Vardą ir pavardę.
2. n atliktų namų darbų (nd) rezultatus (10-balėje sistemoje), o taip pat egzamino (egz) rezultatą.
3. Tuomet iš šių duomenų, suskaičiuoja galutinį balą (galutinis): 0.4 * vidurkis + 0.6 * egzaminas.
4. Papildykite programos versiją (v0.1) taip, kad būtų galima duomenis ne tik įvesti bet ir nuskaityti iš failo. Todėl sukurkite ir užpildykite failą kursiokai.txt, kurio preliminari struktūra (tokius failus Jums reiks kurti kitose versijose patiems).
5. tlikite versijos (v0.2) kodo reorganizavimą (refactoring'ą): Kur tikslinga, programoje naudokite (jeigu dar nenaudojote) struct'ūras;
6. Funkcijas, naujus duomenų tipus (struct’ūras) perkelkite į antraštinius (angl. header (*.h)) failus, t.y. tokiu būdu turėtumete sukurtame projekte turėti kelis *.cpp failus, kaip ir kelis *.h failus.
7. Kur tikslinga, bent minimaliai panaudokite išimčių valdymą (angl. Exception Handling).

Užduoties atlikimas:

1. Susikuriame naują "Header" failą (MyLib.h), kuriame būtų surašytos visos mūsų naudojamos bibliotekos.
2. Susikuriame naują "Header" failą (header.h), kuriame bus surašytos funkcijos, bei nauji duomenų tipai.
3. Iš main programos perkeliame fukncijas į naują cpp failą (func.cpp).
4. Abu "Header" failai yra include'inami į main.cpp ir func.cpp failus.
5. Aprašoma struktūrą iš vardo, pavardės, pažymių, pažymių skaičiaus, egzamino ir galutinio pažymio indekso tam, kad galima būtų atskirti ar išvedimo metu naudosime medianą ar vidurkį.
6. Naudojamas struktūrinis vektorius.
7. Iš pradžių užpildome savo vektorių. Parašoma nauja void tipo funkcija vektoriui užpildyti. Galime pasirinkti ar vartotojas nori pats užpildyti ar būtų naudojama įvestis iš failo.
8. Parašoma išimtis jei programa nenuskaitytų duomenų failo. 
10. Pildymo funkcija vyksta tol, kol vartotojas nusprendžia pats ją sustabdyti parašęs "Stop".
11. Pildymo funkcijos metu yra užpildomas vektorius vardais ir pavardėms, taip pat pildymo metu vartotojas yra paklaustas ar nori pats įrašyti pažymius ar nori, kad programa jam sugeneruotų automatiškai tiek, kiek vartotojas pats įveda.
12. Automatiniam programos įvedimui yra aprašoma atskira void tipo funkcija "atsitiktinis" ir random principu nuo 1 iki 10 yra parenkamas skaičius. Taip pat automatiškai sugeneruojamas egzamino balas.
13. Tam tikri vartotojų įvedimai yra tikrinami pvz.: Jeigu vartotojas turi įrašyti skaičių yra žiūrima ar visų pirma jis įrašė skaičių (tam yra naudojama atskira bool tipo funkcija "numeris", kurios metu stoi(string pav.) principu yra žiūrima ar vartotojas įrašė skaičių), tada yra tikrinama ar tas skaičius yra rėžiuose (pažymys negali būti didesniu už 10 arba neigiamas skaičius). Jeigu įvesta klaidingai konsolėje yra parašoma: "Klaidingas įvedimas".
14. Pabaigus pildymui grįžtame į main fukncija ir klausiama ar vartotojas nori, kad galutinis balas būtų skaičiuojamas su vidurkiu ar mediana.
15. Atitinkamai vidurkiui ir medianai yra parašomos atskiros double tipo funkcijos "vidurkis" ir "mediana".
16. Vartotojo yra klausiama, kokiu būdu jis norėtų išrušiuoti savo įvestį( Pagal vardus, pavardes, galutini balą su vidurkiu arba galutinį balą su mediana).
17. Išrusiavimui yra naudojama sort funkcija kartu su lyginimo funkcijomis (4 atskiros funkcijos kiekvienam lyginimui).
18. Galiausiai vykdomas spausdinimas, kuomet į failą yra išvedama: vardas, pavardė, galutinis balas (vidurkio ir medianos skaičiavimais). 
