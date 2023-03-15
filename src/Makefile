CC = gcc
FLAGS = -g -std=c11
INC_DIR = -L. -I.
CHECK_LIB = -lcheck
OS:=$(shell uname -s)
CCOV = -lgcov --coverage

LIB_HEADER = s21_matrix.h
LIB = s21_matrix.a

LIB_DIR = lib/
OBJ_DIR = obj/
COV_DIR = coverage_info/
TEST_DIR = tests/
LIB_OBJ_DIR = $(OBJ_DIR)$(LIB_DIR)
COV_OBJ_DIR = $(COV_DIR)$(OBJ_DIR)

ifeq ($(OS), Linux)
	CHECK_LIB += -lrt -lpthread -lm -lsubunit
endif

LIB_SRCS = $(addprefix $(LIB_DIR),s21_common.c \
								  s21_create_matrix.c \
								  s21_remove_matrix.c \
								  s21_eq_matrix.c \
								  s21_sum_matrix.c \
								  s21_sub_matrix.c \
								  s21_mult_number.c \
								  s21_mult_matrix.c \
								  s21_transpose.c \
								  s21_determinant.c \
								  s21_determinant_support.c \
								  s21_inverse_matrix.c)

LIB_OBJS = $(patsubst %.c, $(OBJ_DIR)%.o, $(LIB_SRCS))
COV_OBJS = $(patsubst %.c, $(COV_OBJ_DIR)%.o, $(LIB_SRCS))

vpath %.c $(LIB_DIR)

all: clean $(LIB)

$(LIB): $(LIB_OBJS)
	ar rc $@ $^
	ranlib $@

$(LIB_OBJ_DIR)%.o: %.c $(LIB_HEADER)
	@mkdir -p $(LIB_OBJ_DIR)
	$(CC) $(FLAGS) $(INC_DIR) -c $< -o $@

$(COV_OBJ_DIR)%.o: %.c $(LIB_HEADER)
	@mkdir -p $(COV_OBJ_DIR)$(LIB_DIR)
	@$(CC) $(FLAGS) $(INC_DIR) $(CCOV) -c $< -o $@

style:
	clang-format -n $(LIB_HEADER) lib/*

clean:
	rm -rf $(OBJ_DIR) \
		   $(LIB) \
		   $(TEST_EXEC) \
		   $(TEST_EXEC).dSYM \
		   test.log  \
		   $(COV_DIR) \
		   *.gc* \

rebuild: clean all