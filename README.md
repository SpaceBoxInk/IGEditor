# IGEditor
The inGame Editor for SpaceStory (french lua + auto completion ...) made with WxWidget\

To import this project in eclipse :\
DO NOT CREATE new project,\
file > Open Projects from file system\

For wxwidget, use the following commands to get the cppFlags (and then add it to eclipse project properties > C/C++ Build > Settings) :
- wx-config --libs
- wx-config --cppflags
<p>
Also add -pthread to use pthread (linker > Miscellaneous > linker Flags)
</p>
