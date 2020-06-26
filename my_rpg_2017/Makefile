#
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

.SUFFIXES: .c .o

CC=		gcc

AR=	ar rc

FLAGS=	-I./include -I./extern_libs

EXTERN_LIBS=	./extern_libs/

LFLAGS=	-L./ -L./lib -lmy -lclist -lconfig

ifeq ($(shell cat /etc/*-release | grep "Fedora"), )
LFLAGS+=	-lcsfml-window -lcsfml-graphics -lcsfml-audio -lcsfml-system
else
LFLAGS+=	-lc_graph_prog
endif
ifeq ($(debug),1)
FLAGS+= -g3
endif

NAME=	my_rpg

SRC_DIR=	./srcs/

MENU_DIR=	$(SRC_DIR)menu/

INTERFACE_DIR=	$(SRC_DIR)interface/

SRC=	$(SRC_DIR)main.c\
	$(SRC_DIR)init.c\
	$(MENU_DIR)menu.c\
	$(MENU_DIR)pause_menu.c\
	$(MENU_DIR)main_menu.c\
	$(MENU_DIR)stat_menu.c\
	$(SRC_DIR)game/game.c\
	$(SRC_DIR)map/map.c\
	$(SRC_DIR)map/alloc.c\
	$(SRC_DIR)test/test.c\
	$(SRC_DIR)money/shop.c\
	$(SRC_DIR)money/shop_config.c\
	$(SRC_DIR)display/display.c\
	$(SRC_DIR)texture/get_size.c\
	$(SRC_DIR)texture/colidable.c\
	$(SRC_DIR)rand/rand.c\
	$(SRC_DIR)texture/background.c\
	$(SRC_DIR)texture/surface.c\
	$(SRC_DIR)texture/tree.c\
	$(SRC_DIR)texture/dirt.c\
	$(SRC_DIR)texture/map.c\
	$(SRC_DIR)texture/building.c\
	$(SRC_DIR)texture/grass.c\
	$(SRC_DIR)texture/tree_snow.c\
	$(SRC_DIR)character/movement.c\
	$(SRC_DIR)character/player_interaction.c\
	$(SRC_DIR)character/character.c\
	$(SRC_DIR)animations/animate.c\
	$(SRC_DIR)inventory/inventory.c\
	$(SRC_DIR)inventory/fill_inventory.c\
	$(SRC_DIR)pokemon/pokemon.c\
	$(SRC_DIR)destroyer.c\
	$(SRC_DIR)fight/start_fight.c\
	$(SRC_DIR)fight/animation_ally.c\
	$(SRC_DIR)fight/animation_pokeball.c\
	$(SRC_DIR)fight/names.c\
	$(SRC_DIR)fight/particles_buffer.c\
	$(SRC_DIR)fight/particles_pokeball.c\
	$(SRC_DIR)fight/get_user_click.c\
	$(SRC_DIR)fight/create_struct.c\
	$(SRC_DIR)fight/display_msg.c\
	$(SRC_DIR)fight/display_pokemon.c\
	$(SRC_DIR)fight/button_attack.c\
	$(INTERFACE_DIR)buttons.c\
	$(INTERFACE_DIR)display_button.c\
	$(INTERFACE_DIR)handle_gui.c\
	$(INTERFACE_DIR)config_buttons.c\
	$(INTERFACE_DIR)config_gui.c\
	$(INTERFACE_DIR)menu_button.c\
	$(INTERFACE_DIR)pause_menu.c\
	$(INTERFACE_DIR)config_multi_gui.c\
	$(INTERFACE_DIR)selector.c\
	$(INTERFACE_DIR)item_selector.c\
	$(INTERFACE_DIR)handle_bar.c\
	$(INTERFACE_DIR)pokemon_buttons.c\

	#$(INTERFACE_DIR)handle_bar.c
OBJ=		$(SRC:.c=.o)

LIBCONF	=	libconfig.a

LIBCONF_SRC=	$(EXTERN_LIBS)grammar.c\
		$(EXTERN_LIBS)libconfig.c\
		$(EXTERN_LIBS)scanctx.c\
		$(EXTERN_LIBS)scanner.c\
		$(EXTERN_LIBS)strbuf.c\
		$(EXTERN_LIBS)strvec.c\
		$(EXTERN_LIBS)util.c\
		$(EXTERN_LIBS)wincompat.c\

LIBCONF_OBJ=	$(LIBCONF_SRC:.c=.o)

all:		$(NAME)

$(LIBCONF):	$(LIBCONF_OBJ)
		$(AR) $(LIBCONF) $(LIBCONF_OBJ)

$(NAME):	$(LIBCONF) $(OBJ) $(INCLUDE)
	make -C lib/my
	make -C lib/clist
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	make -C lib/my clean
	make -C lib/clist clean
	@rm -rf $(OBJ)
	@rm -f $(LIBCONF_OBJ)

fclean:		clean
	make -C lib/my fclean
	make -C lib/clist fclean
	@rm -rf $(NAME)
	@rm -rf $(LIBCONF)
	@rm -rf lib/*.a

re: fclean all
	make -C lib/my re

.PHONY:
	clean fclean re all $(NAME) .c.o $(LIBCONF)
