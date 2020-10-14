# ReShade
DOTA 2 Helper

How to use:

1. Create a shortcut on your desktop for x64 bit Dota
2. Add -console to the shortcut (e.g., "C:\Program Files (x86)\Steam\steamapps\common\dota 2 beta\game\bin\win64\dota2.exe" -console)
3. Start game and inject DLL (Tested with the GH Injector 3.3 from  https://guidedhacking.com/ using the manual mapping option).

Features:

1) Enemy particle rendering in the fog of war, shows tps, smoke, spells, blood splatter from attacking creeps/roshan, etc.:

![enemyparticles](https://user-images.githubusercontent.com/65406898/96032843-e47de700-0e24-11eb-8571-899f4ce527b1.jpg)

2) A bounding box is drawn on your hero if your hero is seen (e.g., there is an enemy ward nearby):

![truesight](https://user-images.githubusercontent.com/65406898/96032848-e5167d80-0e24-11eb-9534-aa033af3c9cb.jpg)

3) Bounding boxes are drawn on non-illusion enemies:

![illusiondetection](https://user-images.githubusercontent.com/65406898/96032846-e5167d80-0e24-11eb-9419-00294616349f.jpg)

Credits: Based on code from https://github.com/LWSS/McDota, https://github.com/shekeru/dotka-cheats, and the coders over at https://guidedhacking.com/
