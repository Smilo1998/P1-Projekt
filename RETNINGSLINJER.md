## Kodestandarder

For at holde koden ensartet og let at læse, følg disse retningslinjer:

- **Indrykning**: Brug 4 mellemrum til indrykninger i stedet for tabulatorer.
- **Variabelnavne**: Brug beskrivende og forståelige navne på engelsk (f.eks. `userInput`, `recommendationList`).
- **Kommentarer**: Kommentér koden, hvor det er nødvendigt, så andre kan forstå, hvad koden gør.
- **Funktioner**: Hold funktionerne korte og fokuserede på en enkelt opgave. Det gør koden lettere at teste og vedligeholde.

## Commit-beskeder

Når du laver commits, brug følgende format:

### Eksempler på Commit-beskeder:

- `[Feature] Tilføj algoritme til anbefaling`
- `[Fix] Ret fejl i brugerinput`
- `[Docs] Opdater README med installationsvejledning`

### Commit typer**:
- **[Feature]**: Bruges, når du tilføjer en ny funktionalitet eller større forbedringer til programmet.
- **[Fix]**: Bruges, når du retter en fejl i koden.
- **[Docs]**: Bruges, når du opdaterer dokumentation, f.eks. README eller kommenterer koden.
- **[Refactor]**: Bruges, når du omstrukturerer eller optimerer kode uden at ændre programmets funktionalitet.
- **[Style]**: Bruges, når du ændrer noget i koden, der ikke påvirker funktionaliteten, f.eks. formatering eller kode-stil.
- **[Test]**: Bruges, når du tilføjer eller opdaterer tests.
- **[Chore]**: Bruges til opgaver, der ikke ændrer programmets funktionalitet, som f.eks. opdatering af afhængigheder eller opsætning af CI/CD.

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
   - Når Pull Request er oprettet SKAL du anmode og review fra mindst én af dine gruppemedlemmer
   - Gå til Pull Requesten og brug knappet REQUEST REVIEWERS for at vælge en person der kan gennemgå dine ændringer

7. **Merge din Pull Request når den er godkendt**
   - Når review er gennemgået kan du Merge din Pull Request og herefter slette din branch
## Andre Retningslinjer
Opret issues, hvis du opdager fejl eller mangler funktioner, så vi kan holde styr på projektet.
Husk at opdatere dokumentationen, hvis dine ændringer påvirker brugerens oplevelse eller installationsprocessen.



