##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CP=				cp -r

SRC_DIR=		.
SRC=			$(SRC_DIR)/hex_to_base64.py \
				$(SRC_DIR)/xor.py \
				$(SRC_DIR)/single_byte_xor_cipher.py \
				$(SRC_DIR)/detect_xor_cipher/py

BINS_DIR=		.
BINS=			$(BINS_DIR)/challenge01 \
				$(BINS_DIR)/challenge02 \
				$(BINS_DIR)/challenge03 \
				$(BINS_DIR)/challenge04

all:
	$(CP) hex_to_base64.py challenge01
	$(CP) xor.py challenge02
	$(CP) single_byte_xor_cipher.py challenge03
	$(CP) detect_xor_cipher.py challenge04
	$(foreach var, $(BINS), chmod +x $(var);)

clean:
	@rm -rf $(BINS) $(BINS1)

fclean:			clean

re: fclean all

.PHONY: clean fclean re
