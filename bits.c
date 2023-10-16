/* 
 * CS:APP Data Lab 
 * 
 * <Tuna Onal>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2020 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {

    /* Xor is equivalent to negation of biconditional and by rearranging we get :~[~(p&~q)&~(~p&q)] is equivalent to Xor*/
 
	int r1 = x & ~y;
	int r2 = ~x & y;
	int r3 = ~r1 & ~r2;
  return ~r3;
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {

	/* First extract nth and mth bytes from x then create the mask by 0xFF then flip the bits by using 0xFFFFFFFF(created by using 0xFF and | operation) and finally carry nth byte to mth bytes place and vice versa and complete rest of the x*/
 
	int x1 = x >> (n << 3);
	int x2 = x >> (m << 3);
	int a = 0xFF;
	int mas = (a << (m << 3)) | (a << (n << 3));
	int mas2 = (0xFF | (0xFF << 8) | (0xFF << 16) | (0xFF << 24)) ^ mas;
	x1 = x1 & 0xFF;
	x2 = x2 & 0xFF;
	return (x1 << (m << 3)) | (x2 << (n << 3)) | (mas2 & x);
}
/* 
 * isLowerCaseLetter - return 1 if 0x61 <= x <= 0x7A (ASCII codes for characters 'a' to 'z')
 *   Example: isLowerCaseLetter(0x65) = 1.
 *            isLowerCaseLetter(0x60) = 0.
 *            isLowerCaseLetter(0x81) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isLowerCaseLetter(int x) {
  	/* in this function d1 is the distance between letter 'z' and 255(11111111) and d2 is the distance between letter 'a' and 0(all 0s).Every input which exceeds the limits will cause 1s in the first 24 bits.Thus if res1 or res2 contains 1 in first 24 bits it means input exceeds the limits*/

	int d1 = 133;
	int d2 = 97;
	int mas = (0xff << 8) | (0xff << 16) | (0xff << 24);
	int res1 = (d1 + x) & mas;
	int res2 = (x + (~d2 + 1)) & mas;
	return !(res1 | res2);
	
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
	/* mask1 is created in a way that when & operation is applied to x with mask1 we will get the first bit of every 4 bytes. Then by >>,&,+ operations(8 times) we add up every bit of x in r1.Then finally by using mask2 we gather every byte of r1 one by one and add up the values of the bytes which repsents the number of 1's.*/
 
	int mask1 = (0x1 << 24) | (0x1 << 16) | (0x1 << 8) | (0x1);
	int r1 = (x & mask1) + ((x >> 1) & mask1) + ((x >> 2) & mask1) + ((x >> 3) & mask1) + ((x >> 4) &  mask1) + ((x >> 5) & mask1) + ((x >> 6) & mask1) + ((x >> 7) & mask1);
	int mask2 = 0xFF;
	return (r1 & mask2) + ((r1 >> 8) & mask2) + ((r1 >> 16) & mask2) + ((r1 >> 24) & mask2); 

}
/* 
 * divpwr4 - Compute x/(4^n), for 0 <= n <= 15
 *  Round toward zero
 *   Examples: divpwr4(15,1) = 3, divpwr4(-33,2) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 17
 *   Rating: 2
 */
int divpwr4(int x, int n) {
	/*in this function we calculate 2^2n so n2 equals to 2n. In order to solve the problem with the negative x values(when we divide by 4^n directly we get the result 1 less) we added 2^2n -1 to the x if it is negative then finnally divide the new x to 4^n*/

	int n2 = n << 1;
	int rs = (1 << n2) + (~1 + 1);
	int rs2 = rs & (x >> 31);
	x = x + rs2;
	return x >> n2;
    
}
/*
 * ezThreeFourths - multiplies by 3/4 rounding toward 0,
 *   Should exactly duplicate effect of C expression (x*3/4),
 *   including overflow behavior.
 *   Examples: ezThreeFourths(11) = 8
 *             ezThreeFourths(-9) = -6
 *             ezThreeFourths(1073741824) = -268435456 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int ezThreeFourths(int x) {

	/* in the first line 3x is calculated and in the second line sign of the x is decided and finally in the return line decided that negative numbe	r is used or not and dividing by 4 operations are performed */

	int r1 = (x << 1) + x;
	int sig = r1 >> 31;
	return (r1 + (sig & (4 + (1 + ~1)))) >> 2;	
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  return 0;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
 return 2;
}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
  return 2;
}
