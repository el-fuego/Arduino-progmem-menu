# Arduino-progmem-menu
Small arduino menu, what used program memory to store data.

* Supersmall RAM usage (for behaviour only)
* Intuitive menu configs
* Nested submenus
* Number and text fields editing
* Number formatting
* Custom actions
* Input and output devices
* Base classes to create your own behaviour

### Demo
[![How it works](https://img.youtube.com/vi/LEFyBbD5ogw/0.jpg)](https://www.youtube.com/watch?v=LEFyBbD5ogw)


Or 16x2 display:<br/>

<img src="http://joxi.ru/DrlK1XkH461gWA.jpg" /><br />
<img src="http://joxi.ru/1A5LOB6CKxPj92.jpg" /><br />
<img src="http://joxi.ru/brRgk9bcQGblLm.jpg" /><br />

### Start coding
```cpp
int firstAreaSqure = 124;
int secondAreaSqure = 546;
char text[] = "abc324";

void turnLedOn() {
  digitalWrite(LED_BUILTIN, HIGH);
}

MENU(squareArea, "Area sett.", (Menu::MENU_STYLE::NAME_HIDDEN_FOR_CHILD_LIST | Menu::MENU_STYLE::HORIZONTAL_CHILD_LIST)
  ,NUMBER_FIELD(firstAreaSqureMenu, "from ", firstAreaSqure, Menu::to3Digits, " m^2", 0, 1000, 10)
  ,NUMBER_FIELD(secondAreaSqureMenu, "to ", secondAreaSqure, Menu::to3Digits, " m^2", 0, 1000, 1)
);

MENU(test, "My Settings", (0 | Menu::MENU_STYLE::NAME_HIDDEN_FOR_CHILD_LIST)
  ,SUBMENU(squareArea)
  ,TEXT_FIELD(testField, "Text Field '", text, "'")
  ,ACTION(turnLedOn, "Turn LED ON", turnLedOn)
);
```

Ready to start? see full [examples](https://github.com/el-fuego/Arduino-progmem-menu/tree/master/examples)
