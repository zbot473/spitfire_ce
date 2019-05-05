# ----------------------------
# Set NAME to the program name
# Set ICON to the png icon file name
# Set DESCRIPTION to display within a compatible shell
# Set COMPRESSED to "YES" to create a compressed program
# ----------------------------

NAME        ?= GAME
COMPRESSED  ?= YES
DESCRIPTION ?= "Spitfire TI-84 game"

# ----------------------------

include $(CEDEV)/include/.makefile
