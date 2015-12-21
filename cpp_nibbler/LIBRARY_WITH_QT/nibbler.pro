TEMPLATE = subdirs
CONFIG += ordered
SUBDIRS = core
SUBDIRS += app
app.depends = core

sfml.target = sfml
sfml.commands = make -C ./plugin/SFML/

QMAKE_EXTRA_TARGETS += sfml

opengl.target = opengl
opengl.commands = make -C ./plugin/OpenGL/

QMAKE_EXTRA_TARGETS += opengl

ncurse.target = ncurse
ncurse.commands = make -C ./plugin/NCurse/

QMAKE_EXTRA_TARGETS += ncurse

libs.target = libs
libs.commands = make $$opengl.target
libs.commands += $$sfml.target
libs.commands += $$ncurse.target

QMAKE_EXTRA_TARGETS += libs

clean.target = clean
clean.commands = rm -f */*.o
clean.commands += rm -f */*/*.o
clean.commands += rm -f *~
clean.commands += rm -f */*~
clean.commands += rm -f */*/*~
clean.commands += rm -f */moc_*
clean.commands += rm -f */*/moc_*

QMAKE_EXTRA_TARGETS += clean

fclean.target = fclean
fclean.commands = rm -f */*.o
fclean.commands += rm -f */*/*.o
fclean.commands += rm -f */*~
fclean.commands += rm -f */*/*~
fclean.commands += rm -f */moc_*
fclean.commands += rm -f */*/moc_*
fclean.commands += rm -f *.o
fclean.commands += rm -f moc_*
fclean.commands += rm -f plugin/*/*.so

QMAKE_EXTRA_TARGETS += fclean

re.target = re
re.commands = make clean
re.commands += all

QMAKE_EXTRA_TARGETS += re
