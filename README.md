# IGEditor
The inGame Editor for SpaceStory (french lua + auto completion ...) made with WxWidget\

To import this project in eclipse :\
create new c++ project,\
For the location, just look up for the path where the project folder is,\
and for the project name, named it with the project folder name.

For wxwidget, use the following commands to get the cppFlags (and then add it to eclipse project properties > C/C++ Build > Settings) :
- wx-config --libs
- wx-config --cppflags
<p>
Also add -pthread to use pthread (linker > Miscellaneous > linker Flags)
</p>
