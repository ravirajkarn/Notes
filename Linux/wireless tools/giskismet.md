---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-10-08 08:52::46 AM
tags:
  - Linux
  - hacking
  - wireless
  - command
  - wifi
  - network
---
# [GISKismet](https://github.com/xtr4nge/giskismet.git)
giskismet is a companion utility that processes the data. It visualises and analyses the data in a geographic context. 

- **Primary Function:** 
	A visualization tool that processes Kismet's .netxml files.
	 
- **Data Processing:** 
    Takes the raw data from Kismet's .netxml files and stores it in a [SQLite database](https://www.google.com/search?sca_esv=d142667dee937287&cs=1&sxsrf=AE3TifPgsG_l_qkuWtLePjj7XQQebWEjnA%3A1759893513604&q=SQLite+database&sa=X&ved=2ahUKEwiqvsWd0pOQAxUVR2wGHUs5Cy8QxccNegQIMBAB&mstk=AUtExfBCBIXto9B33o8kMWuPTYGGcga45eAxgjpD54yug21V4Q7cWaUAZTGjAPYi5v2_qreHXFHz0DCpEd9mXXdRk9dXBP5xmnlec8w_vbHWy0QHF6o-3nn7aMG6lH5RRQ65rI08yJkMEghSKGbVkWVJJhcHx4cQGyAnHpuSpIgIK1Qliv4tQAWBhQ2FtT2aV1k7Q_Vtwo12R8hBVQPGk8Sm6rEJhDYykSVG18u9TyD943cA3xxFn96Dkek97-riqjxKIbtOI1ge4i5X4V5QdtPD6aa6&csui=3). 
    
- **Data Visualization:** 
    Converts the database information into [Keyhole Markup Language (KML)](https://www.google.com/search?sca_esv=d142667dee937287&cs=1&sxsrf=AE3TifPgsG_l_qkuWtLePjj7XQQebWEjnA%3A1759893513604&q=Keyhole+Markup+Language+%28KML%29&sa=X&ved=2ahUKEwiqvsWd0pOQAxUVR2wGHUs5Cy8QxccNegQIKRAB&mstk=AUtExfBCBIXto9B33o8kMWuPTYGGcga45eAxgjpD54yug21V4Q7cWaUAZTGjAPYi5v2_qreHXFHz0DCpEd9mXXdRk9dXBP5xmnlec8w_vbHWy0QHF6o-3nn7aMG6lH5RRQ65rI08yJkMEghSKGbVkWVJJhcHx4cQGyAnHpuSpIgIK1Qliv4tQAWBhQ2FtT2aV1k7Q_Vtwo12R8hBVQPGk8Sm6rEJhDYykSVG18u9TyD943cA3xxFn96Dkek97-riqjxKIbtOI1ge4i5X4V5QdtPD6aa6&csui=3) files, which can be opened in mapping services like Google Earth to visualize the geographical locations of discovered networks. 
    
- **Other Uses:** 
    Can export data in other formats like [Comma Separated Values (CSV)](https://www.google.com/search?sca_esv=d142667dee937287&cs=1&sxsrf=AE3TifPgsG_l_qkuWtLePjj7XQQebWEjnA%3A1759893513604&q=Comma+Separated+Values+%28CSV%29&sa=X&ved=2ahUKEwiqvsWd0pOQAxUVR2wGHUs5Cy8QxccNegQIJxAB&mstk=AUtExfBCBIXto9B33o8kMWuPTYGGcga45eAxgjpD54yug21V4Q7cWaUAZTGjAPYi5v2_qreHXFHz0DCpEd9mXXdRk9dXBP5xmnlec8w_vbHWy0QHF6o-3nn7aMG6lH5RRQ65rI08yJkMEghSKGbVkWVJJhcHx4cQGyAnHpuSpIgIK1Qliv4tQAWBhQ2FtT2aV1k7Q_Vtwo12R8hBVQPGk8Sm6rEJhDYykSVG18u9TyD943cA3xxFn96Dkek97-riqjxKIbtOI1ge4i5X4V5QdtPD6aa6&csui=3) for spreadsheet analysis.

## Command
- convert .csv file into sql database.
```bash
giskismet -csv location/of/dat.kismet.csv
```




------
## My installation info
```bash
┌──(ravirajkarn㉿sumit)-[~/Documents/linux/linux-tool/giskismet]
└─$ sudo make install
[sudo] password for ravirajkarn:
cp giskismet blib/script/giskismet
"/usr/bin/perl" -MExtUtils::MY -e 'MY->fixin(shift)' -- blib/script/giskismet
Manifying 1 pod document
Installing /usr/local/man/man1/giskismet.1p
Installing /usr/local/bin/giskismet
Appending installation info to /usr/local/lib/x86_64-linux-gnu/perl/5.40.1/perllocal.pod
```