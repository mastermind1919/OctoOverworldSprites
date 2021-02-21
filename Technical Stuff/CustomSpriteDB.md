### Custom Sprite DB

In order to fix the cutoff issues associated with the more advanced jobs and capes, we have to edit this file, located under
```
Content\Flipbook\Database\CustomSpriteDB.uexp
```
(Flipbook being a unreal engine way of animating 2D sprites). In this file lies how the game calculates from the sprite in the files to the sprite in game,
using the name in the uasset file, and the parameters set in the uexp file. In this mod, we only need to modify the uexp file.
Below is an example code block from the uexp file (This one being the idle foward animation for normal Ophilia, to find a particular sprite search for the le byte value from the CustomSpriteDBDecoded file):

```
59 C3 00 00 00 00 00 00 34 BF 00 00 00 00 00 00 60 C3 00 00 00 00 00 00 5E C3 00 00 00 00 00 00 0C 00 00 00 00 00 00 00 00 99 0B 00 00 00 00 00 00 00 00 00 00 61 C3 00 00 00 00 00 00 62 C3 00 00 00 00 00 00 08 00 00 00 00 00 00 00 63 C3 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 40 43 00 00 80 42 5F C3 00 00 00 00 00 00 62 C3 00 00 00 00 00 00 08 00 00 00 00 00 00 00 63 C3 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 80 42 00 00 80 42 F8 0B 00 00 00 00 00 00 F9 0B 00 00 00 00 00 00 10 00 00 00 00 00 00 00 5E C3 00 00 00 00 00 00 00 01 00 00 00 9B 0B 00 00 00 00 00 00 00 00 00 00 65 C3 00 00 00 00 00 00 F9 0B 00 00 00 00 00 00 95 00 00 00 00 00 00 00 62 C3 00 00 00 00 00 00 00 06 00 00 00 65 C3 00 00 00 00 00 00 62 C3 00 00 00 00 00 00 60 00 00 00 00 00 00 00 64 C3 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 E9 A2 23 42 D1 45 63 43 FC FF E8 3E 11 00 1C 3E E9 A2 23 C2 D1 45 63 43 04 00 D7 3E 11 00 1C 3E E9 A2 23 C2 E9 A2 A3 42 04 00 D7 3E 11 00 5C 3E E9 A2 23 42 E9 A2 A3 42 FC FF E8 3E 11 00 5C 3E E9 A2 23 42 D1 45 63 43 FC FF E8 3E 11 00 1C 3E E9 A2 23 C2 E9 A2 A3 42 04 00 D7 3E 11 00 5C 3E
```
The first half of the block we do not need to change, it just specifies what the sprite is, and how it interacts with the world. What we are interested in is the string of hex blocks starting from E9 A2 23 42 ... to the end.
These strings of hex blocks specify both how the sprite will look ingame and where the sprite is pulled from in the file. 
You will see that certain characters repeat themselves in blocks of 4 bytes, with a 16 byte long string for each. These are the indecies of the two triangles needed to make the rectangular sprite appear in game.
Each of these is a quaternon hex value float, with values for X, Y, Z, and W. Unlike in 3D space, the X and Y components determine the size in game of the sprite, and the Z and W component determine where in the file to pull from.
In order to get the Z and W values, the pixel position of the corner for the triangle is divided by the pixel size of the dimension, and converted to hex. In most cases, the size of the file is 512x512, so we divide by that.
The X and Y values are a bit trickier to get right. Certain sprites use different offsets for the X and Y components, and it is a bit of trial and error to get them right.
In the CustomSpriteDB folder of this github is a C++ program that will generate the string of hex values given the coordinates of the pixel in the file, and the "offsets", assuming a size of 512x512.
Generally, the offset will be based on the differences between the normal sprite and the new sprite.
Just play around with it until you get a feel for the right offsets, or don't. After all, you shouldn't need to modify this file unless you are also making custom sprites.
One final note is that lantern sprites do have a longer code block to include a reference to the mask for the actual light block of the lantern. The position that the mask pulls from is the same as the normal sprite however.

Special Thanks to Rossy on the Octopath Modding Discord for helping me figure this one out, and realizing that these are float values.
