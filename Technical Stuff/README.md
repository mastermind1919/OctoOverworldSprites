How I Managed This Mod:

Since this game uses the unreal engine (Version 4.18.2 to be percise), I first checked for a pak file to unpack and read.
The relevent file was found under %Gamepath%/Octopath_Traveler/Content/Paks, with a name of Octopath_traveler-WindowsNoEditor.pak. No encryption is used, and is easily unpacked.
Unpacking this yields the relevent assets of which the game uses to load everything, but of import to us is under Content/Character/Resource/{Player Name Encoded}/Textures.
Player Name Encoded is a six letter name which corresponds to the playable characters in the following list:
PlyAli - Tressa
PlyBal - Alfyn
PlyGil - Therion
PlyMar - H'annit
PlyRud - Olbric
PlySha - Primrose
PlyThe - Cyrus
PlyUlr - Ophilia

I used umodel to extract the editable sprite layout for each character, and then apply them to the base job which is used in the overworld. To apply them, I first got the version of unreal used
for the game, and first added the base sprites in the same file structure as the unpacked pak file. I then applied settings in the unreal import menu until the files which were cooked matched those
from the unpacking, or at least close enough. After this, I modified the base job sprite with that of the job I want in the overworld, and cooked the files to get usable asset file, which I then
packed into a patch file, and moved to the same directory as the original .pak file. The end result, the overworld sprite replaced with that of the secondary job that I wanted.

Secondary Job Sprite Limitations:

For most, if not all, of the secondary jobs, the sprites that are used are larger than that of the base job sprite. This leads to a problem, as with this method, the base job sprite sizes can not be
changed, and will be cut off if not properly adjusted for. This lead to a predicament with the jobs that have capes, as they will not flutter when running like they should.

Secondary Job Sprite Findings:

Unsurprisingly, the secondary jobs do not have most of the sprites needed to make a full sprite list of all possible sprites in the game. What I find intreresting is that there is quite a bit more sprites than
those only used in battle. Such sprites include sprites when doing quests, and a back sprite. In the case of Primrose, about 7 of the 12 secondary jobs have full running animations for moving up and down, which leads
me to believe that at one point they intended to have secondary sprites in the overworld, but backed off, likely due to the time it would take to make that work (I can't blame them for this decision, it takes quite a
bit of time not only making said sprites, but also verifying that they work properly in game). That, or there was a reason in game that it was required, but was removed at some point.

Base Job Sprite Findings:

Even in the base sprites, quite a few are unused in game. First off, all characters have a shocked sprite and an angry sprite, even though most of the characters don't use said sprites. Secondly, some characters, 
like Primrose, have sprites for using weapons that they can not use normally, and can
never use. This makes me wounder if they at one point early in development intended to do something like the freelancer in FFV, where after mastering a job you would get their weapons in the base job. It would have given
a purpose to the base job once you get the secondary jobs, but that isn't the game we got, and can only speculate as to the purpose. I originally thought that the sprites for the left-right movement were flipped in engine,
but the sprites for left and right movement are different sprites in the file. This means that it is possible to fix the ambidextrous error in the sprites, but I have choosen not to to be more authentic to the base game.

Unreal Engine Settings for Sprites:
