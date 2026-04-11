---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-11-24 23:43::14 PM
tags:
  - Cpp
  - Linux
  - windows
---

### Database Layout
I am creating database for my music player.

database will contain

table 1: Local 
it will index all the known music in your pc on user defined path.

| `song_id`                            | `name of song`   | `path to song`       | `path to lyric`  | `date of creation`   |
| ------------------------------------ | ---------------- | -------------------- | ---------------- | -------------------- |
| use for identification               | name of the song | it could not be null | it could be null | it must contain date |
| use for linking with other data base | human readable   |                      |                  |                      |

what if user delete song:
	`song_id` will vanish along with it.

what if song not found/ missing song: 
	- use will get the option to re-link the song or delete it. 
	- this is the case of deletion.



table 2:


### Data Extraction
- iterate thorough all the files and folder find the songs and lyrics.
- It will give the duplicate song list.
- Store it in the database.
- Check weather it found new song or not.
- It will check for new song every once a day or in each opening.
#### file convention
how file name should look like which is easy to read by human and understand by program.
default:
`[Track Number] - [Artist Name] - [Song Title].[ext]'

- `[Track Number]` should start with 01, 02 so on.

-----
- [ ] The best lyrics synchronisation (Mi music player/Spotube) 
- [ ] Like list or playlist are available as folder or Playlist which supports shorting and playlist customisation 
- [ ] File supported 
	- [ ] .mp4 
	- [ ] .m4a 
	- [ ] .lic 
	- [ ] .flac 
- [ ] Backup option is available. 
- [ ] Export of our playlist and download list as text file of excel file 
----