# Windows

Żeby plik makefile zadziałał, należy zainstalować program, który obsłuży plik makefile. Takim programem jest make.
Aby zainstalować make, potrzebny jest menedżer pakietów, który tego dokona. Tutaj użyję Chocolatey.

## Instalacja Chocolatey

Wejść na stronę [tutaj](https://chocolatey.org/install) i podążać za instrukcjami.

Alternatywnie, włączyć program PowerShell jako administrator. W Start wpisujemy PowerShell; pojawi się kilka opcji, zaznaczyć Windows PowerShell (będzie podświetlone na niebiesko). Na pasku po prawej pojawi się kilka opcji - wybrać Run as Administrator (włącz jako administrator).

W PowerShellu wpisać polecenie

``` powershell
Get-ExecutionPolicy
```

Jeżeli program odpowie "Restricted", wpisać

```powershell
Set-ExecutionPolicy AllSigned
```

Następnie wpisać

```powershell
Y
```

Dalej, wkleić podane polecenie:

```powershell
Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
```
  
Po kilku sekundach Chocolatey powinien być zainstalowany. Aby to sprawdzić, należy wpisać:

```powershell
choco -?
```

## Instalacja make

Skoro Chocolatey jest już zainstalowany, można zainstalować make.

Należy wpisać w PowerShell:

```powershell
choco install make
```
  
Make jest już zainstalowany.

Aby teraz odpalić program, zamknij sesję PowerShell (nie ma potrzeby, by dłużej używać go jako administrator) i włącz PowerShell (jako zwykły użytkownik - czyli domyślnie). Nawiguj do odpowiedniego folderu poleceniem cd, np.:

```powershell
cd "C:\Users\radek\Desktop\studia_cpp-main\projekt\"
```

Dalej, w PowerShell (upewnij się, że jesteś w folderze, w którym znajduje się plik makefile) wpisz

```powershell
make
```

## Instalacja g++

Podążaj za dowolnym tutorialem dostępnym w Internecie, np.: https://www.youtube.com/watch?v=8CNRX1Bk5sY lub jakimkolwiek innym.

# Linux, Mac

Użytkownik powinien wiedzieć, jak używać make.

# Używanie make

Dostępne są 3 warianty wykonania pliku makefile.

1. Tylko kompilacja programu:

```bash
make
```

lub

```bash
make all
```

2. Kompilacja i uruchomienie:

```bash
make run
```

3. Wyczyszczenie starych plików .d .o:

```bash
make clean
```

4. Polecenia można łączyć, np.:

```bash
clear && make clean run
```

Wywoła polecenia basha `clear`, a nastepnie usunie wszystkie stare pliki .d oraz .o, by skompilować program na nowo i go wywołać.