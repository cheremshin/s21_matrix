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
								  s21_calc_complements.c \
								  s21_determinant.c \
								  s21_determinant_support.c \
								  s21_inverse_matrix.c)

## Make array of all test files
TEST_SRCS = $(addprefix $(TEST_DIR),s21_tests.c \
									s21_calc_complements_tests.c \
									s21_combined_tests.c \
									s21_create_matrix_tests.c \
									s21_determinant_tests.c \
									s21_eq_matrix_tests.c \
									s21_inverse_matrix_tests.c \
									s21_mult_matrix_tests.c \
									s21_mult_number_tests.c \
									s21_sub_matrix_tests.c \
									s21_sum_matrix_tests.c \
									s21_transpose_tests.c \
									common.c)

LIB_OBJS = $(patsubst %.c, $(OBJ_DIR)%.o, $(LIB_SRCS))
COV_OBJS = $(patsubst %.c, $(COV_OBJ_DIR)%.o, $(LIB_SRCS))

TEST_EXEC = test
COV_EXEC = $(COV_DIR)test_cov
COV_INFO = $(COV_DIR)s21_matrix.info
COV_REPORT = $(COV_DIR)/lib/index.html

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

test: $(LIB)
	$(CC) $(FLAGS) $(INC_DIR) $(TEST_SRCS) $(LIB) $(CHECK_LIB) -o $(TEST_EXEC)

gcov_report: $(LIB) $(TEST_SRCS) $(COV_OBJS)
	$(CC) $(FLAGS) $(INC_DIR) $(CCOV) $(LIB) $^ $(CHECK_LIB) -o $(COV_EXEC)
	@-./$(COV_EXEC)
	@lcov -q -c -d $(COV_DIR) -o $(COV_INFO) --exclude "$(TEST_DIR)*"
	@genhtml -q $(COV_INFO) -o $(COV_DIR)
	@open $(COV_REPORT)
	@rm -rf *.gc*

style:
	clang-format -n $(LIB_HEADER) lib/* tests/coverage_test/* tests/cpp_part/*

leaks: test
	valgrind ./test

clean:
	rm -rf $(OBJ_DIR) \
		   $(LIB) \
		   $(TEST_EXEC) \
		   $(TEST_EXEC).dSYM \
		   test.log  \
		   $(COV_DIR) \
		   *.gc* \

rebuild: clean all