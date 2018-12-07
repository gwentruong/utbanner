# UT banner

```
UU   UU TTTTTTT BBBBB     AAA   NN   NN NN   NN EEEEEEE RRRRRR
UU   UU   TTT   BB   B   AAAAA  NNN  NN NNN  NN EE      RR   RR
UU   UU   TTT   BBBBBB  AA   AA NN N NN NN N NN EEEEE   RRRRRR
UU   UU   TTT   BB   BB AAAAAAA NN  NNN NN  NNN EE      RR  RR
 UUUUU    TTT   BBBBBB  AA   AA NN   NN NN   NN EEEEEEE RR   RR
```

A simple C programming exercise.

Current font styles available:

**Index 0 (default):  "letters"**
```
LL      EEEEEEE TTTTTTT TTTTTTT EEEEEEE RRRRRR   SSSSS
LL      EE        TTT     TTT   EE      RR   RR SS
LL      EEEEE     TTT     TTT   EEEEE   RRRRRR   SSSSS
LL      EE        TTT     TTT   EE      RR  RR       SS
LLLLLLL EEEEEEE   TTT     TTT   EEEEEEE RR   RR  SSSSS
```

**Index 1:  "alpha"**
```
          _____                    _____  
         /\    \                  /\    \
        /::\    \                /::\____\
       /::::\    \              /:::/    /
      /::::::\    \            /:::/    /
     /:::/\:::\    \          /:::/    /  
    /:::/__\:::\    \        /:::/    /   
   /::::\   \:::\    \      /:::/    /    
  /::::::\   \:::\    \    /:::/    /     
 /:::/\:::\   \:::\    \  /:::/    /      
/:::/  \:::\   \:::\____\/:::/____/       
\::/    \:::\  /:::/    /\:::\    \       
 \/____/ \:::\/:::/    /  \:::\    \      
          \::::::/    /    \:::\    \     
           \::::/    /      \:::\    \    
           /:::/    /        \:::\    \   
          /:::/    /          \:::\    \  
         /:::/    /            \:::\    \
        /:::/    /              \:::\____\
        \::/    /                \::/    /
         \/____/                  \/____/
```
# Compilation

```
$ make
```

# Run

```
$ utbanner -f letters wankers
$ utbanner wankers

WW      WW   AAA   NN   NN KK  KK EEEEEEE RRRRRR   SSSSS
WW      WW  AAAAA  NNN  NN KK KK  EE      RR   RR SS
WW   W  WW AA   AA NN N NN KKKK   EEEEE   RRRRRR   SSSSS
 WW WWW WW AAAAAAA NN  NNN KK KK  EE      RR  RR       SS
  WW   WW  AA   AA NN   NN KK  KK EEEEEEE RR   RR  SSSSS
```
# Options
```
$ utbanner [option] [font] [words]

$ utbanner [word] // Print in default style
```
--help          Show the help menu
--version       Show the latest version
-f              Choose font by font name
-i              Choose font by font index
# Add more fonts

The source which I got font styles is [here](http://patorjk.com/software/taag-v1/).

* Choose the style you like and create a new font directory in /fonts directory.

* Here you might have to do a bit of manual work, copy and paste the alphabet of each word from your favourite styles and but each of them in each text files.

* Check the maximum number of line that font style has.

* Add your font style name in the font_list array in utbanner.c , add the number of lines of that font to font_row_length array.

Voila! You inserted a new font style.
