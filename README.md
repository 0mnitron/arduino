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


<hr>


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
