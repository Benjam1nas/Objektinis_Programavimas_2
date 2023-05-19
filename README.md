# Objektinis-Programavimas-labarotiniai-darbai
VU MIF studento Beno Sakalausko objektinio programavimo laboratoriniai darbai ir jų versijos

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

1 Strategijos rūšiavimo trukmė:
      
|Konteinerio tipas|1000     |10000  |100000 |1000000|10000000|
|-----------------|---------|-------|-------|-------|--------|
|Vector           |0.0015s  |0.0026s|0.048s |0.61s  |13s     |
|List             |0.002s   |0.027s |0.29s  |0.82s  |17s     |
|Deque            |0.002s   |0.018s |0.19s  |2s     |49s     |
      
2 Strategijos rūšiavimo trukmė:
      
|Konteinerio tipas                |1000     |10000  |100000 |1000000|10000000|
|---------------------------------|---------|-------|-------|-------|--------|
|Vector                           |0.012s   |0.24s  |49s    |...    |...     |
|Vector(su remove_if)             |0.00043s |0.0038s|0.021s |0.24s  |7.3s    |
|Vector(su remove_if ir copy_if)  |0.0003s  |0.0012s|0.018s |0.21s  |3.1s    |
|List                             |0.00026s |0.0017s|0.02s  |0.25s  |23s     |
|Deque                            |0.00027s |0.0028s|0.048s |0.58s  |19s     |

Vektoriaus erase funkcija vėl pereina per masyva, dirbant su dideliais duomenimis tai užtrunka labai ilgai, gaunasi praktiškai cikclas cikle, su remove_if gaunasi lyg pereiti per cikla 2 kartus. Sujungiant kartu su copy_if sparta dar labiau padidėja.

      
Kompiuterio parametrai:
RAM: 8.00 GB (7.73 GB usable)
CPU: 11th Gen Intel(R) Core(TM) i5-1135G7 @ 2.40GHz   1.38 GHz
SSD: <img width="349" alt="Screenshot 2023-03-31 132646" src="https://user-images.githubusercontent.com/116347949/229095849-771d1740-bfc4-4cba-b6a3-a5552336cbd9.png">
      
# Objektinis-Programavimas-labarotiniai-darbai-2

Užduotis:
1. Pratęskite (tuo pačiu ir patobulinkite) 2-osios užduoties Jūsų turimą programos realizaciją (versiją v1.0) taip, kad vietoje Jūsų sukurtos Studentas (StudentoInfo) ar dar kitaip pavadintos Studentų structūros jos pagrindu sukurkite class'ę, vadovaujantis per teorijos paskaitas nurodomomis "geromis praktikomis".
2. Realizuokite visus reikiamus (realizuokitė "Rule of  five") ir labiausiai tinkančius Jūsų programos veikimui pagerinti (mažiausiai vieną, turintį prasmę - t.y. cout ar cin) ir tik šiuos operatorius Jūsų turimai Studentas klasei. Pažymiu, kad nebūtinai visi realizuoti operatoriai turi būti panaudoti Jūsų programose - atminkite, kad Jūs kuriate/kursite programas ne tik sau, todėl įvertinkite ko gali prireikti ateities vartotojams naudojantiems Jūsų Studentas klasę!
3. Vietoje Jūsų turimos vienos Studentas (ar kažkaip kitaip pavadintos) klasės sukurkite dvi: bazinę klasę, skirtą bendrai aprašyti žmogų ir tuomet iš jos išvestinę (derived) klasę - Studentas.
4. Padarykite, kad žmogui skirta bazinė klasė būtų abstrakčioji klasė, t.y. nebūtų galima sukurti žmogaus tipo objektų, o tik objektus gautus iš jos išvestinių klasių
5. Sukurkite dokumentaciją panaudojant Doxygen 1.5 projekto pagrindu. Įkelkite dokumentaciją (kaip atskirą doxygen katalogą) į repoziciją.
6. Realizuokite Unit Testus naudodami Jums labiausiai patinkantį C++ Unit testų framework'ą. Užtenka pademonstruoti, kad supratote, kam jie reikalingi, t.y. užtenka kelių testų. 
7. Sukurkite 1.5 versijai automatinį įdiegimo failą (setup.msi arba setup.exe).
8. Įsitikinkite, kad Jūsų Vector konteineris veikia (funkcionalumo prasme) lygiai taip pat, kaip ir std::vector , t.y. atkartokite visus pavyzdžius pateiktus visoms std::vector konteinerio funkcijoms ir įsitikinkite, kad gaunate tuos pačius rezultatus naudojant Vector objektus. Ataskaitai README faile reiktų aprašyti bent 5 skirtingų funkcijų (operatoriai irgi yra funkcijos) pavyzdžius. P.s. Kol kas leidžiu patiems pasirinkti tas funkcijas, vėliau bus sukonkretintos ir jos tikrai bus tos, kurios yra sudėtingesnės - todėl, kas stengiatės nelaukti "deadline" pabaigos, teoriškai gali pasirinkti paprastesnes funkcijas.
9. Atlikite efektyvumo/spartos analizę: originalusis std::vector vs Jūsų Vector. Palyginkite (pateikite ir pakomentuokite README faile lentėles) kiek vidutiniškai laiko užtrunka  std::vector tipo ir Jūsų Vector tipo tuščius vektorius užpildyti: 10000, 100000, 1000000, 10000000 ir 100000000 int elementų naudojant push_back() funkciją:
// Pradėti v1 užpildymo laiko matavimą
unsigned int sz = 10000;  // 100000, 1000000, 10000000, 100000000
std::vector<int> v1;
for (int i = 1; i <= sz; ++i)
  v1.push_back(i);
// Baigti v1 užpildymo laiko matavimą

// Pradėti v2 užpildymo laiko matavimą
Vector<int> v2;
for (int i = 1; i <= sz; ++i)
  v2.push_back(i);
// Baigti v2 užpildymo laiko matavimą
10. Palyginkite kiek kartų 2 užduotyje (V2.0) įvyksta konteinerių (Vector ir std::vector) atminties perskirstymai užpildant 100000000 elementų. Perskirstymas įvyksta tada, kai yra patenkinama sąlyga: capacity() == size(), t.y. kai nelieka vietos capacity()`naujiems elementams.
11. Jūsų trečiojo darbo programoje vietoje std::vector panaudokite sukurtą Vector ir įsitikinkite, kad naudojant Vector Jūsų trečiojo darbo programa veikia teisingai.
12. Atlikite spartos analizę, t.y. naudojant duomenų failą su 100000 studentų įrašų, palyginkite kiek laiko užtrunka programos veikimas naudojant std::vector ir Vector realizacijas (matuokite visas std::vector ir Vector operacijas).

Failo veikimo sparta:

|Tipas  |1000     |10000  |100000 |1000000|10000000|
|-------|---------|-------|-------|-------|--------|
|Class  |0.0089s  |0.054s |0.33s  |3s     |39s     |
|Struct |0.066s   |0.068s |0.53s  |3.5s   |48s     |

V1.2 versijoje pakeistas header failas. Sukurtas destruktorius nebereikalingai atminčiai naikinti, kopijavimo konstruktorius, kuris kuria kopijas kito objekto taip taupant atmintį, kopijavimo priskirimo konstruktorius, kuris priskiria reikšmes. 

<img width="287" alt="Header update 1 2" src="https://user-images.githubusercontent.com/116347949/236667414-314829a4-d63f-4040-a215-4e82ceda6494.png">

V1.5 versijoje sukurta bazinė klasė zmogus ir padarytą išvestinė studentas.
      
<img width="353" alt="base" src="https://github.com/Benjam1nas/Objektinis_Programavimas_2/assets/116347949/26a93314-2eef-4727-9d1a-e4b3b6b49195">

V2.0 Versijoje sukurta dokumentacija doxygen html principu. Aprašyti komentarai matomi programos kode. Taip pat padaryti Unit Testai keletai funkciju. Padaryti Test_Case numeris funkcijai. Tikrinama ar funkcija grąžina true, kai vartotojas įvedė numerį, funkcija grąžina false, kai vartotojas įvedė ne numeri ir ar funkcija grąžina false, kai vartotojas įveda numerį kartu su raidėmis. Taip pat padaryti Test_Case, kurie tikrina ar yra tinkamas liudnuku ir linksmuku skirstymas. Principas panašus tikrinama, kai vidurkis yra daugiau už penkis ar tam tikrų vektorių dydžiai yra teisingi. Taip pat V2.0 yra sukurtas įdiegimo failas dll principu.

