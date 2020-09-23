<h1>LV01 - Upravljanje svjetlećim elementima</h1>

<strong>Zadatak 1.</strong> Spoji jednu LED diodu i napiši program koji će uključivati i isključivati LED diodu u intervalima od 1 sekunde.

<strong>Zadatak 2.</strong> Spoji 3 LED diode na izvode 9, 10 i 11 Arduina i napiši program koji će uključivati i isključivati sve LED diode istovremeno u intervalima od 1 sekunde.

<strong>Zadatak 3.</strong> Modificiraj program iz prethodnog zadatka tako da se uključuje jedna po jedna LED diodu, a potom istim redoslijedom gasi. Interval svijetljenja treba biti 1 sekunda.

<strong>Zadatak 4.</strong> Napiši program koji oponaša semafor. Prvo neka se upali crvena LED dioda i neka sama svijetli 10 sekundi. Nakon toga neka joj se priključi žuta LED dioda i neka zajedno svijetle 2 sekunde. Zatim se obje gase i upali se zelena LED dioda koja svijetli 10 sekundi. Nakon toga se gasi zelena i pali žuta koja gori 2 sekunde. Konačno se gasi i žuta LED dioda i postupak se ponavlja.

<strong>Zadatak 5.</strong> Doradi program tako da dodaš 3 globalne varijable ispred funkcije setup() kojima ćeš moći mijenjati trajanje svakog svjetla u njihovoj delay() funkciji! Npr. delayR; delayY; delayG

<strong>Zadatak 6.</strong> Bez promjene spoja iz zadatka 4, napiši program tako da samo jednoj od dioda mijenjaš intenzitet svijetljenja na način da umjesto naredbe digitalWrite(), koristiš naredbu analogWrite(pin, intenzitet). Vrijednost intenzitet mijenjati od 0 do 255 (0, 32, 64, 96, 128, 160, 192, 224, 255). Ostale dvije diode treba softverski isključiti.

<strong>Zadatak 7.</strong> Spoji RGB LED i napiši program koji će svaku sekundu promijeniti boju. Boje mijenjati slijedećim redoslijedom: crvena (255, 0, 0), zelena (0, 255, 0), plava (0, 0, 255), žuta (255, 255, 0), svijetlo plava (0, 255, 255), smeđa (139, 69, 19) i na koncu bijela. Koje su RGB vrijednosti za bijelu boju? Boju treba definirati u korisnički definiranoj funkciji setColor() u koju se prenose parametri za R, G i B koji mogu biti u granicama 0 – 255 (8 bitova za svaku boju).

<strong>Zadatak 8.</strong> Doradite program iz prethodnog zadatka tako da se boje na LED diodama mijenjaju nasumično. Koristiti funkciju random().
