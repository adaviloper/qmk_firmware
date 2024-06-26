# adaviloper Keymap for [Lulu](https://boardsource.xyz/store/61d0b772319a1f3cc53ba2fb)

## Keymap
This keymap is designed around leveraging several layers for a single desk setup.

### Layers
- MAC: Used for work and programming.
- WINDOWS: Used for Windows/Linux computers. The majority of this layer remains transparent except for the home row modifiers that swaps Control and Gui on each hand.
- GAMING: This layer is the bog standard keyboard with no home row mods to make quick registering of keys easier. Caps Lock is changed to Control since Caps Lock is never used in gaming.
- GIT: Used for sending quick Git macros based on the [Oh-My-Zsh Git aliases](https://kapeli.com/cheat_sheets/Oh-My-Zsh_Git.docset/Contents/Resources/Documents/index). We only want to create macros incrementally for frequently used git commands or combinations of commands.
- SYMBOL: A slightly modified version of [Pascal Getreuer's Symbol Layer](https://getreuer.info/posts/keyboards/symbol-layer/index.html#my-symbol-layer). This comfortably adds common bigrams to be quick to type with inward or outward rolls as well as a few macros for other common combinations.
- RAISE: This is just a number and F* key layer that combines a number row and numpad design across the second row and right under the right hand. Surrounding keys are also used for making math, currency and time inputs easily.
- ART: This layer is used for drawing in a way that lets me access every letter key on the keyboard on the left half by flipping the keymap over when holding the 1.5u thumb key on the left half to access ART2. The top row has F13-F22 for adding custom keybindings that won't conflict with Clip Studio Paint
- ART2: See above.
- SYSTEM: Used for any system level commands that are designed to work on any system/application (select all, copy, cut, paste, find, etc...)
- FUNC: This layer will hold any Vim-style movement keys for navigating by word, hjkl, and moving around the page.
- ADJUST: This layer is used for modifying the keyboard state in terms of lights or base layers (_MAC, _WINDOWS, _GAMING)

Information about custom user macros and tap dances can be found [here](../../../../users/adaviloper).

### QWERTY
```c
/* MAC
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | BSPC |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | DEL  |SHFT_A|GUI_S |CTRL_D|ALT_F |GIT_G |-------.    ,-------|GIT_H |ALT_J |CTRL_K|GUI_L |SHFT_;|  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * | MEH  |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | HYPR |
 * `-----------------------------------------/ LT    /     \ LT   \-----------------------------------------'
 *                   |SCREEN|      | ESC  | /ENTER  /       \SPACE \  |RAISE | NONE |ADJUST|
 *                   |SHOT  |      |SYMBOL|/ SYSTEM/         \ FUNC \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
```

```c
/* WINDOWS
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | BSPC |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | DEL  |SHFT_A|CTRL_S|GUI_D |ALT_F |   G  |-------.    ,-------|   H  |ALT_J |GUI_K |CTRL_L|SHFT_;|  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * | MEH  |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | HYPR |
 * `-----------------------------------------/ LT    /     \ LT   \-----------------------------------------'
 *                   |SCREEN|      | ESC  | /ENTER  /       \SPACE \  |RAISE | NONE |ADJUST|
 *                   |SHOT  |      |SYMBOL|/ OS    /         \ FUNC \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
```

```c
/* GAMING
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | BSPC |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | DEL  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * | MEH  |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | HYPR |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |  GUI |ENTER | ALT  | /SPACE  /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
```

### GIT
```c
/* GIT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      | RESET|      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | SOFT |      | ACP  | GACP |-------.    ,-------| HARD |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      | BACK |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
```

### SYMBOL
```c
/* SYMBOL
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   `  |   <  |   >  |   "  |   %  |                    |   &  |   _  |   [  |   ]  |   .  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   #  |   -  |   +  |   =  |   ^  |-------.    ,-------|   $  |   :  |   (  |   )  |   |  |  === |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   !  |   /  |   *  |   \  |   ~  |-------|    |-------|   :: |   @  |   {  |   }  |   ?  |  ==  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
```

### RAISE
```c
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |  2   |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   -  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|   $  |   4  |   5  |   6  |   +  |   *  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |-------|    |-------|   0  |   1  |   2  |   3  |   .  |   /  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |   :  |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
```

### ART
```c
/* ART
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  | F13  | F14  | F15  | F16  | F17  |                    |   6  |   7  |   8  |   9  |   0  | BSPC |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ALT  |   Q  |   W  |   F  |   P  |   G  |                    |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | SHIFT|   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * | CTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      | SPACE| / ART2  /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
```

### ART2
```c
/* ART2
 * ,-----------------------------------------.                    ,------------------------------------------.
 * | F11  |  F18 |  F19 |  F20 |  F21 |  F22 |                    |  F6  |  F7  |  F8  |  F9  |  F10  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+-------+------|
 * |      |   P  |   O  |   I  |   U  |  Y   |                    |   T  |   R  |   E  |   W  |   Q   | ALT  |
 * |------+------+------+------+------+------|                    |------+------+------+------+-------+------|
 * |      |   ;  |   L  |   K  |   J  |  H   |-------.    ,-------|   G  |   F  |   D  |   S  |   A   | SHIFT|
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+-------+------|
 * |      |   /  |   .  |   ,  |   M  |  N   |-------|    |-------|   B  |   V  |   C  |   X  |   Z   | CTRL |
 * `-----------------------------------------/       /     \      \------------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
```

### SYSTEM
```c
/* SYSTEM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | CLOSE|INSPCT|RELOAD| TAB  |                    | REDO |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | ALL  | SAVE | URL  | FIND | TITLE|-------.    ,-------| LEFT | DOWN | UP   | RIGHT|      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      | UNDO | CUT  | COPY | PASTE| CASE |-------|    |-------| MOCK | CAPS | CAMEL| SNAKE| KEBAB|      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
```

### FUNC
```c
/* FUNC
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |VI_BSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | WORD |      |      |      |                    |      | PgUp |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |VI_DEL|      |      | PgDn |      |      |-------.    ,-------| LEFT | DOWN | UP   | RIGHT|      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      | BWORD|-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | BOOT |      |      | /       /       \      \  |      | MAKE | BOOT |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
```

### ADJUST
```c
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      | MAC  |WINDOW|GAMING| ART  |      |                    | BOOT |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB_TG|RGB_HI|RGB_SI|RGB_VI|
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |RGB_MD|RGB_HD|RGB_SD|RGB_VD|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */```

<!--
### TEMPLATE
```c
/* TEMPLATE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
```
-->
