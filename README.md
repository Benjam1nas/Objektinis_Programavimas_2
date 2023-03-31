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
8. Patobulinkite (jeigu reikia, v0.3 turimą realizaciją) ir sukurkite failų generatorių (turi generuoti failus pagal mano prikabintus PVZ. failus), po to sugeneruokite penkis atsitiktinius studentų sąrašų failus, sudarytus iš: 1 000, 10 000, 100 000, 1 000 000, 10 000 000 įrašų. Vardus ir Pavardes galite generuoti "šabloninius", kaip pvz. Vardas1 Pavarde1, Vardas2 Pavarde2 ir t.t. Su kiekvienu failu atskirai atlikite tokius veiksmus.
9. Surūšiuokite (padalinkite) studentus į dvi kategorijas:
      1) Studentai, kurių galutinis balas < 5.0 galėtume vadinti “vargšiukai”, “nuskriaustukai” ir pan.
      2) Studentai, kurių galutinis balas >= 5.0 galėtume vadinti "kietiakiai", "galvočiai" ir pan.
10. Surūšiuotus studentus išveskite į du naujus failus.
11. Atlikite programos veikimo greičio (spartos) analizę: t.y. išmatuokite programos spartą išskiriant kiek laiko užtruko kiekvienas iš žemiau išvardintų žingsnių:
1 matavimas failų kūrimą ir jo užtarimą (galima nenaudoti vektorių o tiesiog išvedinėti duomenys į failą - matuokite tik neturint pradinio failo); 
      1) duomenų nuskaitymą iš failo (paprastai matavimo pradžią, kadangi reikia skaityti tos pačius failus kad operacijų kiekis išliktu toks pat);
      2) studentų rūšiavimą į dvi grupes/kategorijas;
      3) surūšiuotų studentų išvedimą į du naujus failus.
      4) visos programos veikimo laiką.
12. Konteinerių testavimas: Išmatuokite patobulintos v0.4 realizacijos veikimo spartą priklausomai nuo naudojamų trijų skirtingų tipų konteinerių (t.y. tureti arba vieną programą su treis skirtingais konteineriais, arba tris skirtingas programas su atitinkamais konteineriais): 

std::vector
std::list
std::deque
T.y., jeigu Jūs turite susikurę struktūrą Studentai (ar kaip jūs ją pavadinote) ir iki v0.4 naudojote std::vector<Studentai>, tai turite ištirti: ar pasikeistų ir kaip pasikeistų programos sparta, jei vietoje std::vector<Studentai> naudotumėte std::list<Studentai> ir std::deque<Studentai>.

Užduoties atlikimas:

1. Susikuriame naują "Header" failą (MyLib.h), kuriame būtų surašytos visos mūsų naudojamos bibliotekos.
2. Susikuriame naują "Header" failą (header.h), kuriame bus surašytos funkcijos, bei nauji duomenų tipai.
3. Iš main programos perkeliame fukncijas į naują cpp failą (func.cpp).
4. Abu "Header" failai yra include'inami į main.cpp ir func.cpp failus.
5. Aprašoma struktūrą iš vardo, pavardės, pažymių, pažymių skaičiaus, egzamino ir galutinio pažymio indekso tam, kad galima būtų atskirti ar išvedimo metu naudosime medianą ar vidurkį.
6. Naudojamas struktūrinis vektorius, listas ir dequeas. Visi jie naudojami skirtingose failuose.
7. Sukuriamas atskiras cpp failas "generatorius.cpp", kuriame bus kuriamas failų generatorius.
8. Sukuriama fukncija void "generavimas". Į ją yra perduodamas vartotojo įvestas failo pavadinimas. 
9. Iš pradžių yra prašoma įvesti studentų ir jų pažymių kiekį. Po to yra generuojamas failas su šabloniniais vardais (Vardas0, Pavardė0, Vardas1, Pavardė2).
10. Kodui paspartinti string tipo kintamuosius surašome į eilutę ir tada išspausdiname į failą. 
11. Užpildome savo vektorių. Parašoma nauja void tipo funkcija vektoriui užpildyti. Galime pasirinkti ar vartotojas nori pats užpildyti ar būtų naudojama įvestis iš failo, ar vartotojas nori sugeneruoti savo failą ir iš jo užpildyti vektorių.
12. Parašoma išimtis jei programa nenuskaitytų duomenų failo. 
13. Pildymo funkcija vyksta tol, kol vartotojas nusprendžia pats ją sustabdyti parašęs "Stop".
14. Pildymo funkcijos metu yra užpildomas vektorius vardais ir pavardėms, taip pat pildymo metu vartotojas yra paklaustas ar nori pats įrašyti pažymius ar nori, kad programa jam sugeneruotų automatiškai tiek, kiek vartotojas pats įveda.
15. Automatiniam programos įvedimui yra aprašoma atskira void tipo funkcija "atsitiktinis" ir random principu nuo 1 iki 10 yra parenkamas skaičius. Taip pat automatiškai sugeneruojamas egzamino balas.
16. Tam tikri vartotojų įvedimai yra tikrinami pvz.: Jeigu vartotojas turi įrašyti skaičių yra žiūrima ar visų pirma jis įrašė skaičių (tam yra naudojama atskira bool tipo funkcija "numeris", kurios metu stoi(string pav.) principu yra žiūrima ar vartotojas įrašė skaičių), tada yra tikrinama ar tas skaičius yra rėžiuose (pažymys negali būti didesniu už 10 arba neigiamas skaičius). Jeigu įvesta klaidingai konsolėje yra parašoma: "Klaidingas įvedimas".
17. Pabaigus pildymui grįžtame į main funkciją ir klausiama ar vartotojas nori, kad galutinis balas būtų skaičiuojamas su vidurkiu ar mediana.
18. Atitinkamai vidurkiui ir medianai yra parašomos atskiros double tipo funkcijos "vidurkis" ir "mediana".
19. Vartotojo yra klausiama, kokiu būdu jis norėtų išrušiuoti savo įvestį( Pagal vardus, pavardes, galutini balą su vidurkiu arba galutinį balą su mediana).
20. Išrusiavimui yra naudojama sort funkcija kartu su lyginimo funkcijomis (4 atskiros funkcijos kiekvienam lyginimui).
21. Išrušiuotas vektorius yra perošomas į du atskirus vektorius. Tų mokinių, kurių galutinis balas yra mažesnis už penkis yra atskirti į liudnukus, o tų kurių yra penki arba daugiau atskiriami į linksmukus.
22. Galiausiai vykdomas spausdinimas, kuomet į du failus (Liudnuku ir linksmuku) yra išvedama: vardas, pavardė, galutinis balas (vidurkio ir medianos skaičiavimais).
23. Generavimo, failo nuskaitymo, išskirstymo (į liudnukus ir linksmukus), spausdinimo fukncijų vykdymo laikai yra matuojami naudojant high_resolution_clock (chrono bilblioteka) taip pat matuojamas visas failo atlikimo laikas ir visi laikai yra išvedami pasibaigus programai. 

Failas su vektoriais yra vector_main kataloge, listais - list_main kataloge, dequeais - deque_main.

Vektoriai:

|Failo dydis|Nuskaitymo trukmė|Rusiavimo trukmė|Skirstymo trukmė|
|-----------|-----------------|----------------|----------------|
|1000       |0.015s           |0.00091s        |0.0015s         |
|10000      |0.053s           |0.0018s         |0.0026s         |
|100000     |0.49s            |0.019s          |0.048s          |
|1000000    |3.5s             |0.38s           |0.61s           |
|10000000   |39s              |6.6s            |13s             |

Listai:

|Failo dydis|Nuskaitymo trukmė|Rusiavimo trukmė|Skirstymo trukmė|
|-----------|-----------------|----------------|----------------|
|1000       |0.0088s          |0.00014s        |0.002s          |
|10000      |0.32s            |0.0029s         |0.027s          |
|100000     |1.3s             |0.075s          |0.29s           |
|1000000    |24s              |1.3s            |0.82s           |
|10000000   |71s              |19s             |17s             |
      
Dequeai:

|Failo dydis|Nuskaitymo trukmė|Rusiavimo trukmė|Skirstymo trukmė|
|-----------|-----------------|----------------|----------------|
|1000       |0.022s           |0.0022s         |0.002s          |
|10000      |0.14s            |0.014s          |0.018s          |
|100000     |1s               |0.19s           |0.19s           |
|1000000    |11s              |1.9s            |2s              |
|10000000   |80s              |24s             |49s             |
      
Kompiuterio parametrai: \n.
RAM: 8.00 GB (7.73 GB usable)
CPU: 11th Gen Intel(R) Core(TM) i5-1135G7 @ 2.40GHz   1.38 GHz
SSD: <img width="349" alt="Screenshot 2023-03-31 132646" src="https://user-images.githubusercontent.com/116347949/229095849-771d1740-bfc4-4cba-b6a3-a5552336cbd9.png">

