## Laboratorijske vježbe - zadatci
  
* [LV01 - Upravljanje svjetlećim elementima](https://github.com/0mnitron/arduino#lv01---upravljanje-svjetle%C4%87im-elementima)

* [LV02 - Digitalni ulazi i izlazi - tipkala i LED](https://github.com/0mnitron/arduino#lv02---digitalni-ulazi-i-izlazi---tipkala-i-led)
  
* [LV03 - Očitanje s analognog ulaza i upravljanje zvukom](https://github.com/0mnitron/arduino#lv03---o%C4%8Ditanje-s-analognog-ulaza-i-upravljanje-zvukom)

* [LV04 - Ispis na alfanumerički LCD zaslon](https://github.com/0mnitron/arduino#lv04---ispis-na-alfanumeri%C4%8Dki-lcd-zaslon)

* [LV05 - Uvježbavanje zadataka](https://github.com/0mnitron/arduino#lv05---uvje%C5%BEbavanje-zadataka)

* [LV06 - Ispitna vježba](https://github.com/0mnitron/arduino#lv06---ispitna-vje%C5%BEba)

* [LV07 - Sedam segmentni LED indikator](https://github.com/0mnitron/arduino#lv07---sedam-segmentni-led-indikator)

* [LV08 - 4x7 segmentni LED indikator](https://github.com/0mnitron/arduino#lv08---4x7-segmentni-led-indikator)

* [LV09 - DC i Servo motori]()

* [LV10 - 4x4 matrična tipkovnica i relej]()

<hr>

<br>

<h1>Naredbe</h1>

<strong>setup()</strong> - izvršava se samo jednom, na početku pokretanja programa i u njoj se postavljaju početni uvjeti - određuje koji će pinovi biti ulazni ili izlazni, inicijalizira se serijska komunikacija, stvaraju objekti za pojedini senzor ...

<strong>loop()</strong> - izvršava se kontinuirano, u petlji. Na ovaj način, program (sve dok se izvršava) ima stalnu mogućnost reakcije na vanjske senzore.

<br>

<strong>pinMode(</strong>{pin}, {INPUT/OUTPUT}<strong>)</strong> - postavljamo određeni pin kao ulazno/izlazni pin.

<strong>pinMode(</strong>{pin}, {INPUT_PULLUP}<strong>)</strong> - definira određeni pin kao ulazni s uključenim internim Pull-Up otpornikom

<br>

<strong>digitalWrite(</strong>{pin}, {HIGH/LOW}<strong>)</strong> - na željeni pin šaljemo 5v ili 0v.

<strong>digitalRead(</strong>{pin}<strong>)</strong> - očitavamo digitalno stanje na pinu (0 ili 1).

<strong>analogWrite(</strong>{pin}, {intenzitet}<strong>)</strong> - mijenjamo napon na određenom pinu (intenzitet - od 0 do 255 ; 0=0v, 255=5v).

<strong>delay()</strong> - odgađamo sljedeću naredbu za određeno vrijeme (u milisekundama - 1000=1s).

<strong>random()</strong> - funkcija odabire nasumično vrijednost od 0 do zadanog broja.

<br>

<strong>Serial.begin(9600)</strong> - inicijalizacija serijske komunikacije za ispis na Serial monitor.

<strong>Serial.print()</strong> - ispis teksta na Serial monitoru.

<br>

**map(** value, fromLow, fromHigh, toLow, toHigh **)** - funkcija linearno translatira neki broj iz jednog opsega vrijednosti (0-1023) u novi opseg vrijednosti (0-255), (0-100%),...
```
value: broj koji se mapira, tj. ulazna varijabla
fromLow: donja granica sadašnjeg opsega vrijednosti
fromHigh: gornja granica sadašnjeg opsega vrijednosti
toLow: donja granica novog opsega vrijednosti
toHigh: gornja granica novog opsega vrijednosti
```
### Buzzer

**tone(** pin, frekvencija, trajanje tona **)** - funkcija šalje signal na pin, određene frekvencije i određenog vremenskog trajanja

**tone(** pin, frekvencija **)** - funkcija šalje signal na pin, određene frekvencije, ali neodređenog vremenskog trajanja -> potrebno je koristiti i funkciju **noTone(** pin **)** s kojom prekidamo zvučni signal

### LCD

[Određivanje I2C adrese LCD zaslona](https://github.com/0mnitron/arduino/blob/master/LV04_ZAD01.ino)

libraries
```C
<Wire.h> - sadrži funkcije za I2C komunikaciju
<LiquidCrystal_I2C.h> - sadrži funkcije za LCD s I2C komunikacijom
```
**LiquidCrystal_I2C lcd(** 0x27, 16, 2 **);**  - definiranje I2C adrese LCD‐a (0x27) **{** ili 0x3F **}** i veličine LCD‐a 16 znakova u 2 retka

**lcd.begin()** - inicijaliziranje LCD‐a

**lcd.backlight()** - uključivanje pozadinskog osvjetljenja LCD‐a

**lcd.noBacklight()** - isključivanje pozadinskog osvjetljenja LCD‐a

**lcd.setCursor(** 0, 0 **)** - postavljanje kursora na lokaciju 0,0 (**stupac**, **redak**)

**lcd.print()** - ispisivanje poruke
```C
int br = 1023;
lcd.print(br, BIN);  // Ispisivanje broja u binarnom obliku 
lcd.print(br, HEX);  // Ispisivanje broja u heksadekadskom obliku
```

**lcd.clear()** - brisanje zaslona

_simboli_  ->

  * uint8_t heart[8] = { 0x0, 0xa, 0x1f, 0x1f, 0xe, 0x4, 0x0 }; - kreiranje simbola
  
    * [uint8_t](https://en.cppreference.com/w/c/types/integer)  - unsigned integer type with width of exactly 8 bits

  * **lcd.createChar(** 1, heart **);** - pozivanje simbola

  * **lcd.home();**

  * **lcd.write(** 1 **);** - ispisivanje simbola

<hr>

<br>

<h1>LV01 - Upravljanje svjetlećim elementima</h1>

<strong>Zadatak 1.</strong> Spoji jednu LED diodu i napiši program koji će uključivati i isključivati LED diodu u intervalima od 1 sekunde.

<strong>Zadatak 2.</strong> Spoji 3 LED diode na izvode 9, 10 i 11 Arduina i napiši program koji će uključivati i isključivati sve LED diode istovremeno u intervalima od 1 sekunde.

<strong>Zadatak 3.</strong> Modificiraj program iz prethodnog zadatka tako da se uključuje jedna po jedna LED diodu, a potom istim redoslijedom gasi. Interval svijetljenja treba biti 1 sekunda.

<strong>Zadatak 4.</strong> Napiši program koji oponaša semafor. Prvo neka se upali crvena LED dioda i neka sama svijetli 10 sekundi. Nakon toga neka joj se priključi žuta LED dioda i neka zajedno svijetle 2 sekunde. Zatim se obje gase i upali se zelena LED dioda koja svijetli 10 sekundi. Nakon toga se gasi zelena i pali žuta koja gori 2 sekunde. Konačno se gasi i žuta LED dioda i postupak se ponavlja.

<strong>Zadatak 5.</strong> Doradi program tako da dodaš 3 globalne varijable ispred funkcije setup() kojima ćeš moći mijenjati trajanje svakog svjetla u njihovoj delay() funkciji! Npr. delayR; delayY; delayG

<strong>Zadatak 6.</strong> Bez promjene spoja iz zadatka 4, napiši program tako da samo jednoj od dioda mijenjaš intenzitet svijetljenja na način da umjesto naredbe digitalWrite(), koristiš naredbu analogWrite(pin, intenzitet). Vrijednost intenzitet mijenjati od 0 do 255 (0, 32, 64, 96, 128, 160, 192, 224, 255). Ostale dvije diode treba softverski isključiti.

<strong>Zadatak 7.</strong> Spoji RGB LED i napiši program koji će svaku sekundu promijeniti boju. Boje mijenjati slijedećim redoslijedom: crvena (255, 0, 0), zelena (0, 255, 0), plava (0, 0, 255), žuta (255, 255, 0), svijetlo plava (0, 255, 255), smeđa (139, 69, 19) i na koncu bijela. Koje su RGB vrijednosti za bijelu boju? Boju treba definirati u korisnički definiranoj funkciji setColor() u koju se prenose parametri za R, G i B koji mogu biti u granicama 0 – 255 (8 bitova za svaku boju).

<strong>Zadatak 8.</strong> Doradite program iz prethodnog zadatka tako da se boje na LED diodama mijenjaju nasumično. Koristiti funkciju random().

<hr>

<br>

<h1>LV02 - Digitalni ulazi i izlazi - tipkala i LED</h1>

<strong>Zadatak 1.</strong> Napiši program koji će provjeravati stanje na pinu 2 i ispisivati ga na Serial monitor. Na pin 2 treba dovoditi različite napone i promatrati na Serial monitoru kako mikroupravljač očitava pojedino stanje.

<strong>Zadatak 2.</strong> Složiti serijsku bravu koja će se otključati samo kada su oba ključa u bravi. Ključeve simuliraj tipkalima, a otključana vrata LED diodom koja će svijetliti. Stanje tipkala treba pratiti na Serial monitoru!

<strong>Zadatak 3.</strong> Modificiraj spoj iz prethodnog zadatka tako da diodu preko otpornika umjesto na GND spojiš na Vcc. Prilagodi kòd zadatka tako da i dalje LED dioda svijetli samo kad su pritisnute obje tipke.

<strong>Zadatak 4.</strong> Modificiraj spoj i kòd iz prethodnog zadatka tako sa simuliraš infracrveni senzor i senzor temperature pomoću tipkala. U slučaju da bilo koji od senzora reagira (funkcija OR), treba se uključiti alarm. Alarm simuliraj LED diodom.

<strong>Zadatak 5.</strong> Proširi spoj iz prethodnog zadatka s 4 dodatne diode i izvedi trčeće svijetlo. Diode se trebaju uključivati jedna iza druge, bez pauze. Za LED diode koristiti pinove 2 - 6. Predvidjeti da se trajanje svijetljenja svih dioda može podesiti jednom varijablom int nDelay = 200, pa umjesto delay(200), koristiti naredbu delay(nDelay); Promjenom varijable nDelay na početku programa moguće je mijenjati brzinu trčećeg svjetla.

<strong>Zadatak 6.</strong> Riješi prethodni zadatak koristeći for petlju pomoću koje ćeš skratiti duljinu kòda u slučaju da treba upravljati sa više LED dioda.

<strong>Zadatak 7.</strong> Modificiraj spoj i kòd zadatka tako da:
  
    a) pritiskom na tipkalo SW1 LED diode trče slijeva nadesno
    b) pritiskom na tipkalo SW2 LED diode trče zdesna nalijevo
    c) kad su oba tipkala pritisnuta, svijetle sve diode
    d) kad nije pritisnuto niti jedno tipkalo svijetli samo središnja dioda

<strong>Zadatak 8.</strong> Modificiraj prethodni program tako da pomoću dva tipkala reguliraš svjetlinu jedne LED diode, npr. LED na pinu 3. Jednim tipkalom treba povećavati svjetlinu diode „+“ u, a drugim smanjivati „-“. Kad dioda dođe do maksimalne svjetline, pritiskom na tipku „+“, svjetlina diode se više ne mijenja. Isto tako i kad se dioda ugasi, pritiskom na „-“ ostaje ugašena. Predvidjeti da se svjetlina mijenja u koracima ± 10 ili 20.

<hr>

<br>

<h1>LV03 - Očitanje s analognog ulaza i upravljanje zvukom</h1>

**Zadatak 1.** Spoji potenciometar i na Serial monitoru prikazuj očitanu A/D vrijednost.

**Zadatak 2.** Proširi spoj iz prethodnog zadatka dodavanjem LED. Modificiraj program tako da pomoću potenciometra reguliraš svjetlinu LED.

**Zadatak 3.** Proširi spoj iz prethodnog zadatka tako da dodaš tipkalo. Modificiraj program tako da LED svijetli samo kad je pritisnuto tipkalo. Svjetlina LED se i dalje podešava pomoću potenciometra. Stanje tipkala također ispisuj na Serial monitor u istom retku.

**Zadatak 4.** Proširi spoj iz prethodnog zadatka tako da dodaš zujalicu (buzzer). Doradi program tako da se tipkalom osim LED uključuje i zujalica. Frekvencija emitiranog tona treba biti 175 Hz. Svjetlina LED se i dalje podešava pomoću potenciometra.

**Zadatak 5.** Proširi spoj iz prethodnog zadatka dodavanjem još jednog potenciometra na analogni ulaz A1. Doradi program iz prethodnog zadatka tako da novim potenciometrom, mijenjaš frekvenciju zujalice u rasponu od 750 Hz do 2000 Hz. Tipkalom uključuješ samo zujalicu, a LED svijetli cijelo vrijeme. Kad je podešena frekvencija veća od 1500 Hz, potrebno je uključiti crvenu LED. Svjetlinu LED i dalje podešavaš potenciometrom na ulazu A0.

**Zadatak 6.** Na sve pinove s analognim izlazom osim pinova 3 i 11 spoji LED diode. Buzzer iz prethodnog
zadataka treba odspojiti.
Napiši program pomoću kojeg ćeš ostvariti trčeće svjetlo. Pomoću potenciometra priključenog na pin A0 reguliraj brzinu 'trčanja' svjetla u intervalu 100 ms do 1000 ms. Pomoću potenciometra priključenog na A1 treba regulirati svjetlinu svih LED dioda koje koristiš, od potpuno ugašene LED diode do maksimalnog osvjetljenja. Pritiskom na tipkalo, trčeće svjetlo ide u suprotnom smjeru.

**Zadatak 7.** Modificiraj program tako da potenciometrom na ulazu A0 simuliraš analogni ulaz u intervalu od 0V do 5V. Koristeći LED diode iz prethodnog zadatke kreirati VU metar. VU metar je instrument koji uključuje određeni broj LED dioda u ovisnosti o ulaznom naponu.

    a) Za ulazni napon od 0,0 – 1,0V ne svijetli niti jedna LED
    b) Za ulazni napon od 1,0 – 2,0V svijetli LED1
    c) Za ulazni napon od 2,0 – 3,0V svijetli LED1 i LED2
    d) Za ulazni napon od 3,0 – 4,0V svijetle LED1, LED2 i LED3
    e) Za ulazni napon od 4,0 – 5,0V svijetle LED1 – LED4

Potenciometrom na analognom ulazu A1 i dalje i dalje treba regulirati svjetlinu svih LED dioda koje koristiš, od potpuno ugašene LED diode do maksimalnog osvjetljenja. Pritiskom na tipkalo uključuješ sve LED, neovisno o položaju potenciometra. A/D vrijednost, stanje tipkala i izlazne logičke nivoe napone pojedinih dioda prikazati pomoću Serial monitora.

**Zadatak 8.** Koristeći spoj iz prethodnog zadatka, ali koristeći samo jedan potenciometar, doradi program tako da potenciometrom simuliraš temperaturu u granicama 0°C do 60°C. Temperaturu ispisuj na Serial monitoru svake sekunde. Prilikom mjerenja, uređaj treba svake sekunde oglasiti zvučni signal trajanja 20 ms frekvencije 1 kHz. Kad temperatura prijeđe granicu iznad 40°C, uključuje se alarm i crvena LED dioda. U tom slučaju uređaj treba oglasiti zvučni alarm trajanja 500 ms, frekvencije 3 kHz. Na Serial monitor ispisati poruku „Opasnost!“ Zvučni alarm isključiti pritiskom na tipku SW1. Na Serial monitor se i dalje ispisuje poruka „Opasnost!“ sve dok temperatura ne padne u dozvoljeni interval.

**Zadatak 9.** Spoji piezo zujalicu i dva tipkala na Arduino te napiši program kojim će se pritiskom na prvo tipkalo odsvirati glazbena ljestvica. Pronađi na internetu tablicu svih tonova i njihove frekvencije. Pritiskom na drugo tipkalo, Arduino treba odsvirati note tvoje omiljene pjesme. Note također pronađi na internetu. Omogući da se pomoću potenciometra podešava brzina izvođenja melodije.

<hr>

<br>

<h1>LV04 - Ispis na alfanumerički LCD zaslon</h1>

**Zadatak 1.** Spoji LCD zaslon preko I2C sabirnice na Arduino (VCC-5V, SDA-A4, SCL-A5, GND-GND). S adrese https://playground.arduino.cc/Main/I2cScanner preuzmi I2C Scanner. Pomoću njega odredi I2C adresu spojenog LCD zaslona.

**Zadatak 2.** Ne mijenjajući prethodni spoj, na LCD zaslonu ispiši „Hello world“.

**Zadatak 3.** Proširi kod iz prethodnog zadatka tako da na LCD i u drugi red ispišeš „Hello world“.

**Zadatak 4.** Proširi program iz prethodnog zadatka tako da poruke „Hello world“ trepću svake sekunde.

**Zadatak 5.** Testiraj kako bi na LCD zaslonu, u prvom retku ispisao dekadski broj 1023 u binarnom obliku, a u drugom retku u heksadecimalnom obliku.

**Zadatak 6.** Na LCD zaslonu ispiši „Mi ♥ Arduino“. Riječ „Arduino“ ispiši u drugom retku. Simbol srca treba kreirati kao posebni znak budući da ne postoji u tablici znakova LCD zaslona. Kodove za kreiranje simbola srca moguće je provjeriti na http://maxpromer.github.io/LCD- Character-Creator/ ili sličnoj.

**Zadatak 7.** Na LCD zaslonu, u prvom retku, ispiši: "šareno lišće".

**Zadatak 8.** Proširi spoj dodavanjem potenciometra na pin A0. Napiši program koji će u prvom retku, u lijevom kutu ispisivati očitanu A/D vrijednost.

**Zadatak 9.** Proširi program tako da izračunatu vrijednost napona ispisuješ u gornjem redu u desnom kutu. A/D vrijednost 0 odgovara 0V, a 1023 odgovara naponu 5V. Za računanje vrijednosti napona koristiti funkciju map().

**Zadatak 10.** Proširi program tako da stanje baterije vizualno prikazuješ pomoću simbola napunjenosti baterije. U tu svrhu potrebno je kreirati 7 simbola za bateriju. U donjem retku ispisati tekst BATTERY i na temelju A/D vrijednosti iz potenciometra, tj. ulaznog napona, simulirati stanje napunjenosti baterije (punu bateriju prikazat sa svih sedam simbola).

<hr>

<br>

<h1>LV05 - Uvježbavanje zadataka</h1>

**Zadatak 1.** Pomoću Arduina simuliraj 3 ulazni AND sklop. Za ulaze A, B i C koristi tipkala spojena na slijedeće pinove: 2, 3, 4. Za izlaz Y spojiti LED diodu na pin 8. Na pin 9 spojiti LED diodu koja će pokazivati invertirani izlaz -Y.

**Zadatak 2.** Za svaki ulaz A, B i C dodati LED diodu kao indikator da je tipka pritisnuta (npr. zelenu LED). Koristiti pinove 5, 6 i 7. Izlaze Y i –Y prikazati LED diodama druge boje (npr. crvena LED).

**Zadatak 3.** Doradi program tako da na Serial monitoru ispisuješ sve ulazne i izlazne varijable u tablici u obliku: A=0 B=0 C=1 Y=1 –Y=0. Potrebno je koristiti tabulator za odjeljivanje stupaca. Za prikaz na Serial monitor koristiti pozitivnu logiku: pritisnuta tipka = 1!

**Zadatak 4.** Doradi spoj iz prethodnog zadatka dodavanjem LCD-a. Adresa LCD-a je ili 0x27 ili 0x3F. Doradi program tako da u prvom redu LCD-a ispisuje zaglavlje tablice: A B C Y -Y, na pozicijama 0, 3, 6, 11, 15. U drugom retku ispisuj vrijednosti izlaznih i ulaznih varijabli. Koristiti biblioteke „Wire.h“ i „LiquidCrystal_I2C.h“. Za prikaz na LCD, kao i kod Serial monitora, treba koristiti pozitivnu logiku: pritisnuta tipka = 1!

**Zadatak 5.** Doradi spoj dodavanjem potenciometra. Doradi program tako da pomoću potenciometra reguliraš svjetlinu svih LED dioda! Po potrebi, zamijeni pinove na koju su spojene LED diode. Ne koristiti pin 3 koji treba ostati slobodan.

**Zadatak 6.** Doradi spoj iz prethodnog zadatka dodavanjem piezo zujalice na pin 10. Program doradi tako da se kod svake promjene izlazne varijable Y oglasi zvučni signal frekvencije 3 kHz trajanja 500 ms. Dodatno, doradi program tako da se prilikom pritiska ili otpuštanja tipke, oglasi kratki zvučni signal frekvencije 1 kHz, trajanja 20 ms.

<hr>

<br>

<h1>LV06 - Ispitna vježba</h1>

**Zadatak 1.** Spoji 3 LED diode na izlazne portove Arduino pločice. Napiši program kojim ćeš simulirati trčeće svjetlo. Trajanje svijetljenja diode je 500 ms. Dodaj jedno tipkalo tako da dok je pritisnuto, diode trče u suprotnom smjeru.

**Zadatak 2.** Doradi spoj i program tako da brzinu treptanja reguliraš potenciometrom i to tako da je najkraće vrijeme 100 ms, a najdulje 1 sekunda. Doradi program tako da na Serial monitoru ispisuješ: "Ocitana A/D vrijednost: AAAA   Trajanje intervala: BBBB ms".

**Zadatak 3.** Doradi spoj iz prethodnog zadatka dodavanjem LCD-a. Doradi program tako da u prvom redu LCD-a ispisuje tvoje prezime i trajanje intervala u ms. Koristiti biblioteke "Wire.h" i "LiquidCrystal_I2C.h".

**Zadatak 4.** Doradi program tako da u drugom redu LCD-a ispisuje ukupni broj pajenja svih dioda u jednom i u drugom smjeru.

<hr>

<br>

<h1>LV07 - Sedam segmentni LED indikator</h1>

**Zadatak 1.** Spoji 7-segmentni LED indikator i napiši program kojim će se na indikatoru odbrojavati od 0 do 9.

**Zadatak 2.** Doradi program iz prethodnog zadatka tako da slijedno prikazuje slova od A do F.

**Zadatak 3.** Napisati program kojim će na 7-segmentni LED indikator ispisivati „PULA“.

**Zadatak 5.** Modificiraj program iz 1. zadatka gdje 7-segmentni LED indikator odbrojava od 0 do 9 tako da umjesto naredbi digitalWrite() i pinMode(), koristiš direktno adresiranje porta D. Potrebno je modificirati spoj tako da signalne vodiče za segmente A – H premjestiš za dva pina udesno tako da kreću od pina 0, umjesto pina 2 Arduina.

**Zadatak 6.** Doradi program iz prethodnog zadatka tako da slijedno prikazuje slova od A do F.

**Zadatak 7.** Napisati program kojim će na 7-segmentnom LED indikatoru ispisivati „PULA“.

<hr>

<br>

<h1>LV08 - 4x7 segmentni LED indikator</h1>

*Budući da prilikom učitavanja programa na Arduino UNO pločicu pin 0 koristi kao RX i pin 1 kao TX, potrebno je privremeno odspojiti vodič RX sa Arduina. U suprotnom program se neće moći učitati na Arduino.*

**Zadatak 1.** Spoji 4 X 7 segmentni LED indikator. Napiši program koji će napisati slovo P na poziciji prve znamenke s lijeve strane (D1). Pinovi 0 – 7 upravljaju pojedinim segmentom kao i u prethodnoj vježbi, a pinovi 8-11 upravljaju zajedničkim katodama, tj. koja od 4 znamenke svijetli.

**Zadatak 2.** Doradi program tako da slovo P trepće na poziciji D1 s intervalom 500 ms.

**Zadatak 3.** Doradi program tako da se slovo P ispisuje na poziciju D1 kao i do sada, a zatim isto slovo P na poziciji D2. Obje znamenke se trebaju ispisivati naizmjence u intervalu 500 ms.
Umjesto 8 naredbi pinMode(), koristiti direktno adresiranje registara naredbom DDRD=b111111111 i DDRB = B11111111.

**Zadatak 4.** Doradi prethodni program tako da na poziciji znamenke D2 umjesto slova P ispisuješ slovo U. Sada bi se trebale naizmjence ispisivati slovo P na poziciju D1 i slovo U na poziciji D2.

**Zadatak 5.** Doradi prethodni program tako da na poziciju D3 pišeš slovo „L“ i na poziciju D4 slovo „A“. Sada bi se trebala naizmjence ispisivati slova P U L A.

**Zadatak 6.** Prethodni zadatak modificiraj tako da dodaš potenciometar na ulaz A0 Arduina pomoću kojeg ćeš regulirati brzinu ispisa slova. Brzinu ispisa treba regulirati u granicama 1 ms do 250 ms.

**Zadatak 7.** Modificiraj kod iz prethodnog zadatka tako da u potpunosti izbaciš ugrađene Arduno naredbe: pinMode() i digitalWrite(). Odnosi se i na pinove 8, 9, 10 i 11 Arduina kojima se upravlja pojedinom znamenkom. Koristiti naredbu PORTB = bxxxxxxxxx.

**Zadatak 8.** Modificiraj program iz prethodnog zadatka tako da na 4x7 segmentnom zaslonu ispisuješ očitanu A/D vrijednost potenciometra priključenog na A0 ulaz. Prati stanje znamenki na Serial monitoru.

**Zadatak 9.** Modificiraj spoj iz prethodnog zadatka tako da dodaš dva tipkala. Modificiraj program tako da pritiskom na jednu tipku povećavaš broj prikazan na 4x7 segmentnom indikatoru, a pritiskom na drugu tipku smanjuješ. Inicijalno, na indikatoru treba napisati broj 500.

**Zadatak 10.** Modificiraj kod tako da se brojanje povećava ili smanjuje samo na pritisak tipke i da ne broji dalje dok je tipka pritisnuta. Dakle samo na promjenu.

<hr>

<br>

<h1>LV09 - DC i Servo motori</h1>

**Zadatak 2.** Za spoj prema prethodnom zadatku, napiši program pomoću kojeg će se DC motor okretati od najmanje do najveće brzine i obratno.

**Zadatak 3.** Proširi spoj dodavanjem još jednog tipkala i doradi program tako da se držanjem tipkala SW1 brzina povećava, a držanjem tipke SW2 smanjuje. Kad nije pritisnuto niti jedno tipkalo, brzina se ne mijenja. Varijablu koja se koristi za određivanje brzine (npr. int nSpeed) ograničiti u granicama minimalno 0 i maksimalno 255.

**Zadatak 4.** Napiši program koji će upravljati brzinom vrtnje motora u ovisnosti o položaju potenciometra. Motor se treba okretati samo kad su pritisnuta oba tipkala.

**Zadatak 6.** Umjesto DC motora spoji servo motor. Napiši program koji će zakretati servo motor od 0 do 180 stupnjeva. 

**Zadatak 7.** Doradi program iz prethodnog zadatka tako da položaj servo motora podešavaš pomoću potenciometra. Koristiti već poznatu funkciju map().

**Zadatak 8.** Napiši program za pokretanje servo motora:

    a) pritiskom na SW1, motor se treba okretati ulijevo i na LCD-u ispisati poruku "<--Moving Left". 
       Kad se tipkalo otpusti, motor treba stati.
    b) Pritiskom na SW2 motor se treba okretati udesno i na LCD-u ispisati poruku "Moving Right-->>". 
       Kad se tipkalo otpusti, motor treba stati.
    c) Kad nije pritisnuta niti jedna tipka, na LCD-u treba ispisati poruku: „Ready“, a servo ne mijenja položaj
    
**Zadatak 9.** Doradi program sa slijedećim:

    a) Na LCD-u u drugom retku treba ispisati kut u stupnjevima. I dok se motor pozicionira, i kad motor stoji, i 
       kad je u krajnjem položaju.
    b) Kad dosegne krajnji položaj, treba ispisati poruku „Left limit“ ili „Right limit“ na LCD-u.
    c) Pritiskom na obje tipke istovremeno, treba ispisati poruku „Resetting pos.“, a servo motor se treba 
       pozicionirati u središnji položaj. U središnjem položaju treba pisati„Ready“.

<hr>

<br>

<h1>LV10 - 4x4 matrična tipkovnica i relej</h1>


<hr>

<br>

<h1>LV15 - Mjerenje temperature i vlage</h1>

**Zadatak 1.** Spoji senzor (A0, 3.3V, GND) i ispisuj temperaturu i vlagu na Serial monitor svake 2 sekunde.

<br>

<br>

<br>

* [TOP](https://github.com/0mnitron/arduino#laboratorijske-vje%C5%BEbe---zadatci)

<hr>

Vježbe osmislio: 

Zoran Dumančić, mag. ing. el.

<hr>
