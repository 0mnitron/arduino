## Laboratorijske vježbe - zadatci
  
* [LV01 - Upravljanje svjetlećim elementima](https://github.com/0mnitron/arduino#lv01---upravljanje-svjetle%C4%87im-elementima)

* [LV02 - Digitalni ulazi i izlazi - tipkala i LED](https://github.com/0mnitron/arduino#lv02---digitalni-ulazi-i-izlazi---tipkala-i-led)
  
* [LV03 - Očitanje s analognog ulaza i upravljanje zvukom](https://github.com/0mnitron/arduino#lv03---o%C4%8Ditanje-s-analognog-ulaza-i-upravljanje-zvukom)

* [LV04 - Ispis na alfanumerički LCD zaslon](https://github.com/0mnitron/arduino#lv04---ispis-na-alfanumeri%C4%8Dki-lcd-zaslon)

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
**tone(** pin, frekvencija, trajanje tona **)** - funkcija šalje signal na pin, određene frekvencije i određenog vremenskog trajanja

**tone(** pin, frekvencija **)** - funkcija šalje signal na pin, određene frekvencije, ali neodređenog vremenskog trajanja -> potrebno je koristiti i funkciju **noTone(** pin **)** s kojom prekidamo zvučni signal
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
