Inlämningsuppgift 2, 'N i rad'
==============================

Du skall implementera spelet 4 i rad, men med stöd för ett godtyckligt antal
pjäser i rad. Användaren ska vid spelets start få bestämma spelplanens storlek
samt antal pjäser i rad som krävs för att vinna.

Allmän beskrivning av det analoga spelet:
https://en.wikipedia.org/wiki/Connect_Four

Vad ska du göra?
----------------
I katalogen `include` finns filen `ConnectFour.hpp` . Med klassen i den filen som
bas skall du göra en implementation som gör det möjligt att spela spelet enligt
ovan. Du får själv skapa extra funktioner och klasser om du tycker att det behövs.

Klassen i filen `include/Position.hpp` används i `ConnectFour` i form av en
dubbelpekare. Dubbelpekaren ska peka på en tvådimensionell dynamiskt allokerad
array av objekt av typen `Position` . Den tvådimensionella arrayen är själva
spelbrädet. Klassen `GameStatus` i filen `include/GameStatus.hpp` används i
`ConnectFour` för att signalera status. Den används av testerna i
`test/test-main.cpp` för att köra ett antal testfall och kontrollera att du
stödjer spelets regler i din implementation.

Du får använda klassen `Visualizer` i `include/Visualizer.hpp` i ditt spel om
du vill. Den används av testerna för att visualisera körningen.

Exempelkörning:
```bash
Hello! Welcome to the Game "Connect n"!
What should "n" be?
> 4
How many columns?
> 7
How Many rows?
> 7
Choose color Red or Yellow!
> red
Red it is, do you want to start? (yes/no)
> no
Alright, player2 starts. Player2 has the color: yellow
Player2, Your turn! Which column do you want to play?
> 1
+-------+
|       |
|       |
|       |
|       |
|       |
|       |
|x      |
+-------+

Player1, Your turn! Which column do you want to play?
> 2

...
"A few minutes later"
...

Player2, Your turn! Which column do you want to play?
> 1
+-------+
|       |
|       |
|       |
|x      |
|xo     |
|xo     |
|xo     |
+-------+

Yellow is the winner!
The player2 has won! Player1 lost!
Play again? (y/n)
> n
```

***Glöm inte bort att se till att du har ett rent minne när programmet avslutats.
Dvs att du tagit bort alla grejer du allokerat med new***

***Glöm inte att se till att samtliga tester passerar. Är det ett testfall som
fallerar har du inte klarat uppgiften***

När samtliga testfall går igenom och du inte har några minnesläckor är du redo
att lämna in. Om du gör ändringar i sista minuten. Se till att köra igenom
testfallen igen och se till att samtliga testfall går igenom. Glöm inte heller
att kolla efter minnesläckor! Hur du kör tester står under rubriken "Tester".
Hur du kollar efter minnesläckor ser du under rubriken "Minnesläckor". Kör
gärna statisk kodanalys med jämna mellanrum med. Det hjälper dig hitta vanliga
buggar. Hur du gör det står under rubriken "Statisk kodanalys"

Hur kompilerar jag och kör mitt program?
----------------------------------------
I mappen du fått finns det en makefil för att bygga och testa ditt program.
Placera dina källfiler i katalogen `src/` och dina headerfiler i `include/` .
Bygg sedan ditt program genom att köra `make clean all` .

Om du vill köra ditt program, skriv då `./game` på linux/macOS. Använder du WSL
på windows är det en liten linuxmaskin du jobbar i och då gör du som på linux.

Tester
------
Ett antal tester som finns i katalogen `tests` kommer provköra din lösning för
att se att spelets regler är uppfyllda och att ett antal standardpartier går
rätt till.

För att testa ditt program med testerna finns det ett make-mål (eng. make 
target). Kör det genom skriva `make clean test` i terminalen när du står i
samma katalog som makefilen.

***Testerna används för att verifiera att din inlämning faktiskt fungerar.
Ändra därför inte i test-main.cpp utan skapa istället en egen .cpp om du vill
testa din inlämning***.

Hur man testar med `Catch` ligger utanför scopet för denna kurs. För den
nyfikne som vill prova kan man dock titta på Catchs dokumentation:
https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md

Inlämning och examination
-------------------------
När alla tester går igenom och du är redo att lämna in kör du kommandot `make
zip`, givet att du är projektets mapp. Du kommer då få en zipfil i
projektmappen. Det är denna zipfil du ska lämna in på CodeGrade i rutan
nedanför.

Notera att det kan ta flera minuter för CodeGrade att bygga och testa din kod.
Om det inte ser ut att hända något kan det vara att testmiljön installeras för
att bygga och testa din kod.

För betyget G ska följande kriterier vara uppfyllda:

* Ditt program ska gå att kompilera.
* Ditt program ska passera alla testfall.
* Din kod ska hålla hålla god struktur.
* Du skall ha använt en dubbelpekare med dynamiskt allokerat minne.
* Minnet ska tas bort när det inte används. D.v.s Inga minnesläckor får förekomma.
* Ditt program ska gå att köra genom att starta det med ./game och vara spelbart.

Minnesläckor
------------
Tack vare att vi använder oss av kompilatorn clang kan vi enkelt kontrollera om
vi har minnesläckor i vårt program. När du kör ditt program kommer du, om du
har minnesläckor att få en utskrift i stil med:

```
mattias@Osborne1:/mnt/c/Users/matti/Documents/bth/dv1627-assignment2-n-i-rad$ ./game

=================================================================
==7112==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x4c429d in operator new[](unsigned long) (/mnt/c/Users/matti/Documents/bth/dv1627-assignment2-n-i-rad/game+0x4c429d)
    #1 0x4c6c46 in ConnectFour::ConnectFour(int, int, int) /mnt/c/Users/matti/Documents/bth/dv1627-assignment2-n-i-rad/src/ConnectFour.cpp:4:20
    #2 0x4c6b84 in main /mnt/c/Users/matti/Documents/bth/dv1627-assignment2-n-i-rad/main.cpp:11:15
    #3 0x7f56436770b2 in __libc_start_main /build/glibc-ZN95T4/glibc-2.31/csu/../csu/libc-start.c:308:16

SUMMARY: AddressSanitizer: 8 byte(s) leaked in 1 allocation(s).
```

* #0 Berättar att vi gör en `new[]`, alltså att vi skapar en ny array med `new`
  som läcker minne
* #1 Berättar att läckan finns i funktionen `ConnectFour::ConnectFour(int, int,
  int)` och på fjärde raden och 20e kolumnen i filen `src/ConnectFour.cpp`.
* #2 - #3 innehåller *call-stacken* till funktionen. Dvs vilka funktioner som
  programmet gått igenom för att komma till funktionen i #1 där läckan finns. I
  det här fallet anropar *operativsystemet* `__libc_start_main` som i sin tur
  anropar `main` i `main.cpp` som anropar `ConnectFour(int, int, int)` i
  `src/ConnectFour.cpp` (konstruktorn med tre parametrar) som är den funktion
  som läcker.

Minnesläckor i ditt program kan också hittas när man kör testerna. Du får då en
eller flera liknande utskrifter i din terminal beroende på hur många gånger
ditt program läckt under testkörningarna.

Statisk kodanalys
-----------------
Tack vare att vi använder oss av kompilatorn clang kan vi enkelt kolla efter
vanliga fel i vår källkod. Det kallas för `linting` eller statisk kodanalys.
Dvs analys av koden man kan göra utan att köra koden (analys som kräver att
koden körs kallas för dynamisk kodanalyas).

För att köra statisk kodanalys kör vi make-målet `static-code-analysis`. En
exempelkörning kan se ut såhär:

```
mattias@Osborne1:/mnt/c/Users/matti/Documents/bth/dv1627-assignment2-n-i-rad$ make static-code-analysis
clang-tidy  -header-filter=.* --checks="diagnostic-*, analyzer-*, readability-*, performance-*" src/ConnectFour.cpp main.cpp --  -Iinclude  -Itest/include
3 warnings generated.
3 warnings generated.
/mnt/c/Users/matti/Documents/bth/dv1627-assignment2-n-i-rad/src/ConnectFour.cpp:8:19: warning: method 'yellowPlays' can be made static [readability-convert-member-functions-to-static]
bool ConnectFour::yellowPlays(int col) {return true;}
                  ^
/mnt/c/Users/matti/Documents/bth/dv1627-assignment2-n-i-rad/src/ConnectFour.cpp:10:19: warning: method 'redPlays' can be made static [readability-convert-member-functions-to-static]
bool ConnectFour::redPlays(int col) {return true;}
                  ^
/mnt/c/Users/matti/Documents/bth/dv1627-assignment2-n-i-rad/src/ConnectFour.cpp:12:25: warning: method 'getCurrentStatus' can be made static [readability-convert-member-functions-to-static]
GameStatus ConnectFour::getCurrentStatus() const {
                        ^                  ~~~~~~
```

Här ser vi tre varningar med förbättringar som kan göras på vår kod. I det här
fallet så ger det oss tips om att någonting inte står rätt till.
Förbättringsförslagen som lämnas låter inte riktigt rimliga nämligen. Den här
metoden ska ju vara beroende av spelets läge, när `clang-tidy` säger att den
kan göras statisk, dvs så att den ej har tillgång till medlemsvariabler, har vi
nog missat något.

Med verktyg som `clang-tidy` hittas ofta många buggar som annars hade lett till
konstiga fel eller kompletteringar.
