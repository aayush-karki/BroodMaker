# BroodMaker

This contains BroodMaker and BroodUI.

BroodMaker, and BroodUI is developed using C++ and SFML for graphics. The BroodMaker is application that uses the BroodUI library for all the UI elements and user interaction with them. The Brood UI library uses the Immediate-Mode Graphical User Interface API principle as opposed to the Retained-mode GUI. 

## Features
### BroodUI Library
When using the BroodUI library, the users should be able to create, and manipulate UI elements

- Button element: 
  - Clicking it will return true once.
  - Can set text or insert images.

- Text box element: 
  - Clicking it will set it as active and any keystroke user enters is recorded and application can fetch the recorded text until user again presses the mouse button outside of the textbox area
  - Cursor is represented by ‘_’ at the end of the text in the textbox
  - The cursor is displayed when the textbox is selected and is hidden when the textbox is not selected.
  - Pressing esc key deselects the textbox
  - Pressing enter key deselects the textbox 
  - Can display placeholder text when the user has not entered any texts in it.
  - Can set to be in-editable so that it can act as a label.

- Drop-down menu element:
  - It inherits the features of button element.
  - Clicking it will display the sub menus it contains and returns true and each sub menus acts as a button. The sub menus are displayed until one of the sub-menus is pressed on which the sub-menus return true or area outside of the drop-down menu element is pressed in which the sub-menus are hidden and the drop-down menu itself is set as inactive.
  - The length of the sub-menus does not depend on the main drop-down element, but the sub-menus all have same size.

- Drop-down input element:
  - It inherits the features of drop-down element.
  - Only way it differs from the drop-down element is that the main displayed text/background (which is displayed even when inactive) is set to the selected sub-menu. 
  - The drop-down input main body is same size as its sub-menus.

- Menu bar element
  - It is an element that groups drop-down elements horizontally. Thus, it has all the features of the drop-down menus.
  - Once one of the drop-down in the menu bar is clicked(activated) then hovering over other drop-down of the same menu bar expands the drop-down that was hovered over and closed the previously expanded drop-down menu.

### BroodMaker: card-based board game editor
BroodMaker: card-based board game editor, has the following features:
- A global menu-bar
  - File menu allows to create new, save, and load edits. It also has an option to quit the application
  -  Workspace menu allows to switch between the home workspace and editor workspace.
  - Debug menu toggles the UI debug option that helps in debugging the ui. This is only for developers.
- Home workspace
  - Allows to load previous edits.
  - Allows to create new edits
  - Quit the application
- Editor workspace
  - Has 7 different editor that allows to manipulate individual aspects of the board games.
  - It has the following editor
- Game editor: allows to manipulate the general game setting and rules.
- Board editor: allows to manipulate the board as a whole.
- Tile editor: allows to manipulate each tile in the board and set the path that the player will take and setup the tile rules.
- Player editor: allows to manipulate the each player character.
- Dice editor: allows to manipulate the dice
- Deck editor: allows to manipulate each deck in the game
- Card editor: allows to manipulate the display card and each individual card.
 
## Installation and Setup

### Installation
Currently the Brood UI library and BroodMaker Editor are connected to each other, and Brood UI library is not its stand-alone library. So, there is no button that only downloads the library and ignore the editor. But once whole application is downloaded, theoretically speaking, it is possible to extract and separate only the BroodUI library from the application, once the application’s source code is download. 

#### Installing Compiled BroodMaker Applications
Installing Compiled Applications is very easy. Go to [latest release page](https://github.com/aayush-karki/BroodMaker/releases/tag/alpha-v0.2) on GitHub.
Download all of the things in the release. Run the BroodMaker.exe application. This will create all the folder that the application before running the application. On the first run of the application, the text will not load as there is no font file in the newly created ~/Assets/Fonts/ directory. So you would need to close the application, download the all the font files from the main repository [link](https://github.com/aayush-karki/BroodMaker/tree/master/BroodMaker/Assets/Fonts) , and move it into the aforementioned fonts directory. Now running the BroodMaker.exe application, should run smoothly.

#### Installing and compiling the BroodMaker application from source code 
- Clone the repo to your local environment. By using the git clone command ```git@github.com:aayush-karki/BroodMaker.git```. Or download the zip file from the repository  from the GitHub and then unzipping it.
- Open visual studio and create a new c++ console  application project. 
- Move the Dependencies/Sfml-2.5.1 into your Current_Working_directory of your newly created project. 
- Then you can follow [this SFML getting started tutorial](https://www.sfml-dev.org/tutorials/2.5/start-vc.php) to setup the project to support a SFML project
  - Make sure to link the SFML library dynamically. 
- Then move all the content of the BroodMaker folder into your project. Make sure to move them in the folder when the visual studio generated the main.cpp file. 
- From the visual studio IDE delete the main.cpp permanently. 
- Finally, from the visual studio IDE add all the existing .h and .cpp file. Then you can compile the code.


## Images
### Home Workspace
![image](https://github.com/aayush-karki/BroodMaker/assets/68620206/5bffa1bd-f906-4fb3-8f87-7b4c254232a0)
![image](https://github.com/aayush-karki/BroodMaker/assets/68620206/f7534f38-9401-4fce-ad94-92371cd39056)
![image](https://github.com/aayush-karki/BroodMaker/assets/68620206/b0a79c30-5acd-419e-a62c-c48b08a4b62f)

### Main Menu
![image](https://github.com/aayush-karki/BroodMaker/assets/68620206/f506d901-3f57-417d-bb3f-3c682e05f2f20)

### Editors
![image](https://github.com/aayush-karki/BroodMaker/assets/68620206/5cd33672-dd39-4239-8b7e-3995976ba627)
![image](https://github.com/aayush-karki/BroodMaker/assets/68620206/67004752-ebaf-4647-b292-a34792186ddb)
![image](https://github.com/aayush-karki/BroodMaker/assets/68620206/88a16068-b004-4fe2-860b-dc84bd0ca6b0)
![image](https://github.com/aayush-karki/BroodMaker/assets/68620206/a3fba622-1a8b-4d97-9503-434b02f26e70)
![image](https://github.com/aayush-karki/BroodMaker/assets/68620206/78cb58c1-8800-4b8f-be43-fddc65c7d7fa)
![image](https://github.com/aayush-karki/BroodMaker/assets/68620206/9336b060-274e-4589-8254-46a8cc89e4b8)
![image](https://github.com/aayush-karki/BroodMaker/assets/68620206/b6fc6a97-96b2-4659-b9ce-95341e228c4f)
![image](https://github.com/aayush-karki/BroodMaker/assets/68620206/7dd75f55-a438-41fe-b468-dcea9ec362bb)



