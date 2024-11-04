## Kodestandarder

For at holde koden ensartet og let at læse, følg disse retningslinjer:

- **Indrykning**: Brug 4 mellemrum til indrykninger i stedet for tabulatorer.
- **Variabler**: Brug beskrivende og forståelige navne på engelsk
- **Kommentarer**: Kommentér koden, hvor det er nødvendigt, så andre kan forstå, hvad koden gør.
- **Funktioner**: Hold funktionerne korte og fokuserede på en enkelt opgave. Det gør koden lettere at teste og vedligeholde.
- **Navne**: Variabler skrives med underscore imellem og med små bogstaver, funktioner skrives i camelCase, symbolske konstanter i ALL-CAPS

## Pull Request-processen

1. **Opret en ny branch** for dit arbejde:
   - Branch navn: `navn-funktion`, f.eks. `jens-algoritme`.
  
2. **Lav din ændringer og test lokalt**
   - Foretag dine ændringer og sørg for at teste, at alt fungere korrekt inden du laver en Pull Request
   - Hvis der er test i projektet skal du sikre at de alle passerer uden fejl
  
3. **Commit og push til din branch**
   - Lav commits med meningsfulde beskeder(Se commit retningslinjer ovenfor)
   - Push dine ændringer til din branch
     git push origin navn-funktion

4. **Opret Pull Request på GitHub**
   - Gå til din repository på GitHub og du vil se en mulighed for at lave en Pull Request fra din nyligt pushede branch
   - Klik på NEW PULL REQUEST og vælg din branch

5. **Udfyld Pull Request beskrivelsen**
   -I beskriven indgår altid en kort beskriveelse af hvad ændringen opnår, giver et overblik over hvilke filer og funktioner er blevet påvirket
   -og en notering af hvordan ændringerne er blevet testet

6. **Anmod og review**
   - Når Pull Request er oprettet SKAL der anmodes om review fra mindst én af dine gruppemedlemmer
   - Gå til Pull Requesten og brug knappet REQUEST REVIEWERS for at vælge en person der kan gennemgå dine ændringer

7. **Merge din Pull Request når den er godkendt**
   - Når review er gennemgået kan du Merge din Pull Request og herefter slette din branch
     
## Andre Retningslinjer
**Fejl i programmet** 
- Opret issues, hvis du opdager fejl eller mangler funktioner, så vi kan holde styr på projektet.
  
**Test af programmet**
- Når man har lavet en ændring skal man teste at programmet stadigvæk fungerer inden man pusher til GitHub



