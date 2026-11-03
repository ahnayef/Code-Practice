# Compiler Construction Lab Examination — Model Question Sets

Twenty-one complete lab question sets, one hundred and fifteen questions. Each set is one exam sitting: read the instructions, write the programs, test them on the given samples. Attempt one set at a time with no notes. Every set gets harder as it goes: the first questions are short, the last ones need a design decision.

**General instructions for every set**

1. Write a complete **flex** program for each question. Compile with `flex q.l && gcc lex.yy.c -lm -o q`.
2. Unless a question says otherwise, input is read from **standard input**.
3. Marks are shown in brackets at the end of each question.
4. Where a sample is given, your output must match it exactly, including spacing.
5. Comments and unnecessary output will cost marks.
6. A question that names a regular-expression rule tells you what must be matched, not which syntax to type. If flex has no operator for it, write the pattern out or keep the state yourself.

---

## Set 1 — Fundamental scanning

*Time: 60 minutes · Answer all five questions · 50 marks*

**1.** Write a flex program that reads a sequence of words and integers and prints one line for each token, in the order in which it appears. A word must be printed as `Word: <text>` and an integer as `Integer: <number>`. Any other character must be ignored. **[10]**

```text
Sample Input
alpha 42 beta 7

Sample Output
Word: alpha
Integer: 42
Word: beta
Integer: 7
```

**2.** Write a flex program that reads the file `input.txt`, counts the number of words, the number of integers, and the number of characters that are neither letters, nor digits, nor white space, and prints the three counts at the end with the headings `Words`, `Integers` and `Others`. If the file cannot be opened, the program must print `File not found!` and terminate. **[10]**

```text
Sample Input (contents of input.txt)
a 1 b 2 ;

Sample Output
Words: 2
Integers: 2
Others: 1
```

**3.** Write a flex program that prints every word and every integer of the input together with its length, in the form `<token>(<length>)`, without any space between consecutive tokens. **[10]**

```text
Sample Input
int xy 12345

Sample Output
int(3)xy(2)12345(5)
```

**4.** Write a flex program that reads one word per line and prints, for each line, the word in reverse followed by its length in brackets. Line numbers must not appear in the output. **[10]**

```text
Sample Input
abc
hello

Sample Output
cba(3)
olleh(5)
```

**5.** Write a flex program that scans the input until the word `stop` is encountered as a complete word. It must print `Token: <text>` for every word and integer seen before it, followed by `Total: <n>` where `<n>` is the number of tokens printed. Any input after the word `stop` must be completely ignored. **[10]**

```text
Sample Input
a 1 b stop c 2

Sample Output
Token: a
Token: 1
Token: b
Total: 3
```

---

## Set 2 — Tokenizing a C program

*Time: 75 minutes · Answer all five questions · 60 marks*

**1.** Write a flex program that reads a C program and prints every token with its class, in the form `<token> --> <class>`. The classes are `KEYWORD`, `IDENTIFIER`, `INTEGER`, `FLOAT`, `OPERATOR`, `PUNCTUATION` and `STRING`. Treat `int`, `float`, `char`, `double`, `void`, `if`, `else`, `while`, `for`, `return` as keywords; `( ) { } [ ] ; , .` as punctuation; `+ - * / % = < > ! & |` and their two-character combinations as operators. White space and comments must produce no output. **[15]**

```text
Sample Input
int x = 3.5; // rate

Sample Output
int --> KEYWORD
x --> IDENTIFIER
= --> OPERATOR
3.5 --> FLOAT
; --> PUNCTUATION
```

**2.** Write a flex program that prints every token of the input as a pair, exactly in the form `(<TYPE>, <text>)`, where `<TYPE>` is one of `KW`, `ID`, `INT`, `FLT`, `OP`, `PUNCT`, `STR`, `CHR`. **[10]**

```text
Sample Input
x=a+1;

Sample Output
(ID, x)
(OP, =)
(ID, a)
(OP, +)
(INT, 1)
(PUNCT, ;)
```

**3.** Write a flex program that reports the position of every token. For each token print `line <L> col <C> <text>`, where the line and the column are both counted from 1 and the column is the position of the first character of the token. **[15]**

```text
Sample Input
int x
  y;

Sample Output
line 1 col 1 int
line 1 col 5 x
line 2 col 3 y
line 2 col 4 ;
```

**4.** Write a flex program that builds a frequency report of token classes. After scanning, it must print exactly six lines in this order: `Keywords`, `Identifiers`, `Integers`, `Floats`, `Operators`, `Punctuations`, each followed by a colon and the count. **[10]**

```text
Sample Input
int a = 1;

Sample Output
Keywords: 1
Identifiers: 1
Integers: 1
Floats: 0
Operators: 1
Punctuations: 1
```

**5.** Write a flex program that reports every character which cannot begin any token. For each such character it must print `Error: illegal character '<c>' at line <L>`, and then continue scanning the same line. Valid tokens must still be reported normally. **[10]**

```text
Sample Input
a = 1 @ b

Sample Output
a
=
1
Error: illegal character '@' at line 1
b
```

---

## Set 3 — Identifiers, keywords and declared names

*Time: 60 minutes · Answer all five questions · 55 marks*

**1.** Write a flex program that treats every line of the input as a single candidate and decides whether it is a valid C identifier. A valid identifier begins with a letter or an underscore and continues with letters, digits or underscores only. Print `Valid` or `Invalid`. **[10]**

```text
Sample Input
_x9
9x

Sample Output
Valid
Invalid
```

**2.** Write a flex program that classifies each word of the input as `Keyword`, `Identifier` or `Invalid`. The keywords are `auto break case char const continue default do double else enum extern float for goto if int long register return short signed sizeof static struct switch typedef union unsigned void volatile while`. A word that is not a valid identifier is `Invalid`. **[10]**

```text
Sample Input
int count 2x

Sample Output
Keyword
Identifier
Invalid
```

**3.** Write a flex program that recognises the keywords `int`, `float`, `if`, `else`, `while`, `for` and `return` in any combination of upper and lower case, and prints each one in its standard lower-case form preceded by `Keyword: `. Every other word must be printed as `Identifier: <word>` exactly as it was written. **[10]**

```text
Sample Input
INT Total WhIlE

Sample Output
Keyword: int
Identifier: Total
Keyword: while
```

**4.** Write a flex program that prints every distinct identifier of the input exactly once, in the order of its first appearance, followed by the number of the line on which it first appeared. **[15]**

```text
Sample Input
a b
a c

Sample Output
a 1
b 1
c 2
```

**5.** Write a flex program that considers an identifier declared when it is immediately preceded by the keyword `int`. It must print `Declared: <name>` at the point of declaration and `Use before declaration: <name>` whenever an identifier appears that is not yet declared. Nothing is printed for keywords and numbers. **[10]**

```text
Sample Input
a = 1; int a; a = 2;

Sample Output
Use before declaration: a
Declared: a
```

---

## Set 4 — Numeric and character constants

*Time: 75 minutes · Answer all five questions · 60 marks*

**1.** Write a flex program that classifies every integer constant of the input as `Decimal`, `Octal` or `Hexadecimal`, printing the class followed by the constant. A constant beginning with `0x` or `0X` is hexadecimal, one beginning with `0` and containing further digits is octal, and everything else is decimal. **[10]**

```text
Sample Input
42 017 0x1F

Sample Output
Decimal 42
Octal 017
Hexadecimal 0x1F
```

**2.** Write a flex program that prints the decimal value of every integer constant in the input, interpreting octal and hexadecimal notation correctly. **[10]**

```text
Sample Input
42 052 0x2A

Sample Output
42
42
42
```

**3.** Write a flex program that rejects malformed numeric constants. For each malformed constant print `Invalid <text>: <reason>`, where the reason is `octal digit 8 or 9`, `hexadecimal constant without digits`, `more than one decimal point`, `invalid suffix` or `exponent without digits`. Well-formed constants must be printed as `Valid <text>`. **[15]**

```text
Sample Input
08 0x 1.2.3 42abc 1e

Sample Output
Invalid 08: octal digit 8 or 9
Invalid 0x: hexadecimal constant without digits
Invalid 1.2.3: more than one decimal point
Invalid 42abc: invalid suffix
Invalid 1e: exponent without digits
```

**4.** Write a flex program that recognises floating-point constants. It must accept a constant with a decimal point, a constant with an exponent, and a constant with a trailing `f` or `F`, and must reject a constant with two decimal points. Print `Float: <text>` for a valid one and `Invalid: <text>` otherwise. **[10]**

```text
Sample Input
3.14 1e10 1.5f 1.2.3

Sample Output
Float: 3.14
Float: 1e10
Float: 1.5f
Invalid: 1.2.3
```

**5.** Write a flex program that prints the integer value of every character constant in the input. A plain character has its ASCII value, `\n` is 10, `\t` is 9, `\0` is 0, `\xHH` is a hexadecimal escape and `\NNN` is an octal escape. **[15]**

```text
Sample Input
'A' '\101' '\x41' '\n'

Sample Output
65
65
65
10
```

---

## Set 5 — String and character literals

*Time: 90 minutes · Answer all six questions · 75 marks*

**1.** Write a flex program that accepts a string literal only if it is opened and closed on the same line and every escape sequence in it is one of `\n`, `\t`, `\r`, `\\`, `\"`, `\'`, `\a`, `\b`, `\f`, `\v`, `\?`. Print `Valid <text>` for an acceptable literal and `Invalid <text>: <reason>` otherwise, where the reason is `illegal escape` or `unterminated`. **[15]**

```text
Sample Input
"ok"
"Test \1"
"Hello \y"

Sample Output
Valid "ok"
Invalid "Test \1": illegal escape
Invalid "Hello \y": illegal escape
```

**2.** Write a flex program that accepts a character constant only if it contains exactly one character or exactly one escape sequence between the quotes. Print `Valid <text>` or `Invalid <text>: <reason>`, with the reason `empty`, `too many characters` or `unterminated`. **[10]**

```text
Sample Input
'a' '\n' '' 'ab'

Sample Output
Valid 'a'
Valid '\n'
Invalid '': empty
Invalid 'ab': too many characters
```

**3.** Write a flex program that examines the string literals of the input and reports every format specification found inside them. A `%%` is a literal percent sign and must be reported as `Percent`. Any other `%` followed by optional flags, an optional field width, an optional precision and one of the conversion characters `d i u o x X c s f e g p n` must be reported as `Specifier: <sequence>`. A `%` followed by anything else must be reported as `Bad specifier: <sequence>`. **[15]**

```text
Sample Input
printf("%d items, %.2f%% done", n, p);
printf("%q", x);

Sample Output
Specifier: %d
Specifier: %.2f
Percent: %%
Bad specifier: %q
```

**4.** Write a flex program that prints the length in memory of every string literal in the input — that is, the number of characters the compiled program would store, counted after escape sequences have been interpreted, excluding the quotes and excluding the terminating null character. A tab counts as one character, `\x41` counts as one, `\101` counts as one and `\"` counts as one. **[15]**

```text
Sample Input
"a\tb\x41\101"
"abc"
"a\"b"

Sample Output
Length: 5
Length: 3
Length: 3
```

**5.** Write a flex program that concatenates adjacent string literals. Two or more string literals separated only by white space form a single literal; print `Concatenated: <content>` with the content decoded, followed by the total number of characters in brackets. **[10]**

```text
Sample Input
"ab" "cd"

Sample Output
Concatenated: abcd (4 characters)
```

**6.** Write a flex program that distinguishes string literals from character constants when each contains the other sort of quote. A single quote inside a string literal is ordinary text and needs no escape; an unescaped double quote inside a character constant is legal. Print `String <text>` or `Char <text>` for each literal. **[10]**

```text
Sample Input
"it's" '"' "a\"b"

Sample Output
String "it's"
Char '"'
String "a\"b"
```

---

## Set 6 — Comments, line continuation and preprocessing

*Time: 75 minutes · Answer all five questions · 60 marks*

**1.** Write a flex program that counts single-line comments and block comments separately and prints `Line comments: <n>` and `Block comments: <n>` at the end. **[10]**

```text
Sample Input
// one
/* two */ x;
/* three
   four */

Sample Output
Line comments: 1
Block comments: 2
```

**2.** Write a flex program that prints the input with all comments removed, so that the number of output lines equals the number of input lines. A line that contained only a comment must appear as an empty line, and any blanks left at the end of a line by the removal must be deleted. **[10]**

```text
Sample Input
a /* one
     two */
b

Sample Output
a

b
```

**3.** Write a flex program that detects a block comment which is never closed. It must print `Unterminated comment opened at line <L>` giving the line on which the `/*` appeared, and `All comments closed` when every block comment is properly terminated. **[15]**

```text
Sample Input
x; /* oops
y;

Sample Output
Unterminated comment opened at line 1
```

**4.** Write a flex program that demonstrates that block comments do not nest. For an input containing `/* a /* b */ c */`, the comment must be reported as ending at the first `*/`, and the remaining `*/` must be reported as a stray token in the code. Print `Comment ends at line <L>` and `Stray */ at line <L>`. **[15]**

```text
Sample Input
/* a /* b */ c */

Sample Output
Comment ends at line 1
Stray */ at line 1
```

**5.** Write a flex program that reports every `#define` directive. It must print `Object macro: <name>` when the macro name is not followed by a parenthesis, and `Function macro: <name> (<n> parameters)` when it is. **[10]**

```text
Sample Input
#define N 10
#define SQ(x) ((x)*(x))
#define ADD(a,b) (a+b)

Sample Output
Object macro: N
Function macro: SQ (1 parameters)
Function macro: ADD (2 parameters)
```

---

## Set 7 — Operators and the longest-match rule

*Time: 60 minutes · Answer all five questions · 55 marks*

**1.** Write a flex program that prints every token of the input on its own line. The input line is `a+++b` and the program must demonstrate how the longest-match rule divides it. **[10]**

```text
Sample Input
a+++b

Sample Output
a
++
+
b
```

**2.** Write a flex program that prints every token of the input on its own line, where the input contains both a compound assignment operator and an assignment followed by a minus sign. **[10]**

```text
Sample Input
a>>=2
x=-1

Sample Output
a
>>=
2
x
=
-
1
```

**3.** Write a flex program that prints the number of occurrences of each of these operators, in exactly this order, one per line as `<operator>: <count>`: `+`, `-`, `*`, `/`, `%`, `=`, `==`, `<`, `>`, `<=`, `>=`, `!`, `!=`, `&&`, `||`. A two-character operator is counted only as itself. **[15]**

```text
Sample Input
a+b*c>=d && e!=f

Sample Output
+: 1
-: 0
*: 1
/: 0
%: 0
=: 0
==: 0
<: 0
>: 0
<=: 0
>=: 1
!: 0
!=: 1
&&: 1
||: 0
```

**4.** Write a flex program that scans the line `x----y // z----w` and prints every token belonging to the code, one per line, followed by the rest of the line as a single comment line beginning with `Comment: `. **[10]**

```text
Sample Input
x----y // z----w

Sample Output
x
--
--
y
Comment: // z----w
```

**5.** Write a flex program that prints every distinct operator appearing in the input exactly once, in order of first appearance. Operators of two characters, such as `*=`, count as one operator. **[10]**

```text
Sample Input
b=a+1; a*=2+3;

Sample Output
=
+
*=
```

---

## Set 8 — Counting and reporting

*Time: 75 minutes · Answer all five questions · 60 marks*

**1.** Write a flex program that prints the number of characters, words and lines of the input, using the headings `Characters`, `Words` and `Lines`. Every character, including the newline, is counted. **[10]**

```text
Sample Input
hi there
bye

Sample Output
Characters: 13
Words: 3
Lines: 2
```

**2.** Write a flex program that prints a frequency table of the words of the input. Each distinct word must appear once as `<word>: <count>`, sorted by count from largest to smallest and alphabetically among equal counts. At the end print `Total: <n>` and `Distinct: <n>`. **[15]**

```text
Sample Input
a b a c b a

Sample Output
a: 3
b: 2
c: 1
Total: 6
Distinct: 3
```

**3.** Write a flex program that reports how many times each keyword of the input occurs. The keywords are `int`, `char`, `float`, `double`, `if`, `else`, `while`, `for`, `return`, `void`. Print only those that occur, one per line as `<keyword>: <count>`, in the order in which they first appeared. **[10]**

```text
Sample Input
int a; int b; if (a) return; int c;

Sample Output
int: 3
if: 1
return: 1
```

**4.** Write a flex program that reports the greatest number of parentheses open at the same time on each line, printing `Line <L>: depth <d>` for every line. A line without parentheses has depth 0. **[15]**

```text
Sample Input
((a+b))
(a+(b*c))
a

Sample Output
Line 1: depth 2
Line 2: depth 2
Line 3: depth 0
```

**5.** Write a flex program that reports every line longer than 40 characters, printing `Line <L> is <n> characters long`, in increasing order of line number. If there is no such line print `No long lines`. **[10]**

```text
Sample Input
short
this line is quite long and contains many words

Sample Output
Line 2 is 47 characters long
```

---

## Set 9 — Source transformation and style checking

*Time: 60 minutes · Answer all five questions · 55 marks*

**1.** Write a flex program that prints the input with every occurrence of the keywords `int`, `char`, `float`, `double`, `if`, `else`, `while`, `for`, `return` and `void` converted to upper case. Identifiers, string literals and comments must be left exactly as they are. At the end print `Keywords converted: <n>`. **[15]**

```text
Sample Input
int total; if (total) return;

Sample Output
INT total; IF (total) RETURN;
Keywords converted: 3
```

**2.** Write a flex program that prints the input with every run of one or more spaces or tab characters replaced by a single space. The contents of string literals must not be altered. **[10]**

```text
Sample Input
a   =    "x    y";

Sample Output
a = "x    y";
```

**3.** Write a flex program that prints the input as a numbered listing. Every line must be printed with its line number, right-aligned in a field of three characters, followed by a vertical bar and a space, and then the line itself with all comments removed. Blanks left at the end of a line by the removal must be deleted. **[15]**

```text
Sample Input
int a; // note
/* whole line */
int b;

Sample Output
  1 | int a;
  2 | 
  3 | int b;
```

**4.** Write a flex program that prints the input with every integer constant replaced by twice its value. Floating-point constants, identifiers and all other text must be unchanged. **[10]**

```text
Sample Input
x = 21; y = 3.5;

Sample Output
x = 42; y = 3.5;
```

**5.** Write a flex program that finds every identifier written in camelCase — that is, beginning with a lower-case letter and containing at least one upper-case letter — and prints its conversion to snake_case as `<original> -> <converted>`, where an underscore is inserted before every upper-case letter and that letter is made lower case. Identifiers that are already all lower case must not be reported. **[15]**

```text
Sample Input
myVarName x totalCount

Sample Output
myVarName -> my_var_name
totalCount -> total_count
```

---

## Set 10 — Arithmetic expressions

*Time: 75 minutes · Answer all five questions · 60 marks*

**1.** Each line of the input contains two integers separated by a plus sign. Write a flex program that prints their sum for every line in the form `Sum: <n>`. **[10]**

```text
Sample Input
12 + 30
1+1

Sample Output
Sum: 42
Sum: 2
```

**2.** Each line of the input contains two numbers separated by one of the four operators `+`, `-`, `*`, `/`. Write a flex program that applies the operator and prints the line in the form `<a> <op> <b> = <result>`. **[10]**

```text
Sample Input
7 * 6
9 - 4

Sample Output
7 * 6 = 42
9 - 4 = 5
```

**3.** Write a flex program that evaluates `a / b` for each line of the input. When the divisor is zero the program must print `Error: division by zero` for that line and continue with the next line. **[15]**

```text
Sample Input
8 / 2
1 / 0
9 / 3

Sample Output
4
Error: division by zero
3
```

**4.** Write a flex program that evaluates a division and follows the rules of C: when both operands are written without a decimal point the division is integer division, and when either operand contains a decimal point the result is a floating-point value printed with `%g`. **[15]**

```text
Sample Input
10 / 4
10.0 / 4

Sample Output
2
2.5
```

**5.** Write a flex program that evaluates expressions containing `+`, `-`, `*`, `/` and nested parentheses, with the usual precedence and left associativity, and prints the value of each line. **[10]**

```text
Sample Input
2+3*4
(2+3)*4
((2+3)*(4-1))/2.0

Sample Output
14
20
7.5
```

---

## Set 11 — Expressions with state

*Time: 90 minutes · Answer all five questions · 70 marks*

**1.** Write a flex program that supports variables. A line of the form `name = expression` computes the expression, stores it under that name and prints `name = value`. A line containing only a name prints the stored value. A name that has never been assigned must produce `Error: undefined variable 'name'`. Expressions may contain `+ - * /` and parentheses. **[15]**

```text
Sample Input
x = 5
y = x * 2.5
y
q

Sample Output
x = 5
y = 12.5
12.5
Error: undefined variable 'q'
```

**2.** Write a flex program that supports the function calls `floor(x)`, `ceil(x)`, `round(x)`, `sqrt(x)` and `pow(a,b)` inside expressions, and prints the value of each line with `%g`. **[15]**

```text
Sample Input
floor(3.7)+ceil(3.2)
sqrt(16)
pow(2,10)

Sample Output
7
4
1024
```

**3.** Write a flex program that evaluates comparisons and the conditional operator. The comparison operators `<`, `>`, `<=`, `>=`, `==` and `!=` produce 1 or 0, and `condition ? a : b` yields `a` when the condition is non-zero and `b` otherwise. **[15]**

```text
Sample Input
5 > 3 ? 10 : 20
2 == 3

Sample Output
10
0
```

**4.** Write a flex program that supports the increment and decrement operators on variables. `x++` yields the value before incrementing, `++x` yields the value after incrementing, and the same applies to `--`. For each statement print the value it produces, and at the end print every variable as `name = value`. **[15]**

```text
Sample Input
x = 5; a = x++; b = ++x;

Sample Output
a = 5
b = 7
x = 7
```

**5.** Write a flex program that evaluates division and modulo when the operands are negative, following C's rule that the result is truncated towards zero. Print the value of each line. **[10]**

```text
Sample Input
-7 / 2
-7 % 2

Sample Output
-3
-1
```

---

## Set 12 — From expression to intermediate code

*Time: 90 minutes · Answer all five questions · 70 marks*

**1.** Write a flex program that reads one infix expression per line and prints its postfix form, with a single space between symbols. Expressions contain integers, `+`, `-`, `*`, `/` and parentheses, with `*` and `/` binding more tightly than `+` and `-`. **[15]**

```text
Sample Input
2+3*4
(2+3)*4

Sample Output
2 3 4 * +
2 3 + 4 *
```

**2.** Write a flex program that reads one postfix expression per line, evaluates it using a stack with integer arithmetic, and prints the result. When a line contains too few operands, print `Error: stack underflow` and continue with the next line. **[15]**

```text
Sample Input
3 4 + 5 *
7 +

Sample Output
35
Error: stack underflow
```

**3.** Write a flex program that reads assignments of the form `name = expression`, where the expression uses names, integers, `+ - * /` and parentheses, and prints three-address code for each one: one instruction per binary operation using the temporaries `t1`, `t2`, … in execution order, followed by the assignment to the target name. **[15]**

```text
Sample Input
x = a + b * c

Sample Output
t1 = b * c
t2 = a + t1
x = t2
```

**4.** Write a flex program that performs constant folding. Whenever both operands of an operation are numeric constants, the operation must be evaluated during scanning and replaced by its result. Print the folded expression in the form `Folded: <text>`, then `Value: <number>` with the value of the whole right-hand side after folding, then `Folded operations: <n>`. **[15]**

```text
Sample Input
x = 2*3 + 4

Sample Output
Folded: x = 6 + 4
Value: x = 10
Folded operations: 1
```

**5.** Write a flex program that counts three kinds of error in the input and prints the totals. A character that cannot begin any token is a lexical error; an operator with a missing operand or an unbalanced bracket is a syntax error; a division by the literal `0` or the use of a name that was never declared with `int` is a semantic error. **[10]**

```text
Sample Input
int a = 1 @ 2;
int b = 1 + ;
int c = 1 / 0;

Sample Output
Lexical errors: 1
Syntax errors: 1
Semantic errors: 1
```

---

## Set 13 — Scanning without a scanner generator

*Time: 60 minutes · Answer all four questions · 50 marks. Write these in plain C. Flex must not be used.*

**1.** Write a C program that reads a C statement from standard input character by character and prints every token with its class: `KEYWORD`, `IDENTIFIER`, `INTEGER`, `FLOAT`, `OPERATOR` or `PUNCTUATION`. Use `getchar` and `ungetc`, a keyword table, and a lookup function based on `strcmp`. Keywords: `int char float double if else while for return void`. **[15]**

```text
Sample Input
int a = 3.5;

Sample Output
int --> KEYWORD
a --> IDENTIFIER
= --> OPERATOR
3.5 --> FLOAT
; --> PUNCTUATION
```

**2.** Write a C program that prints the number of characters, words and lines of the input using a single pass over the input and a flag that records whether the program is currently inside a word. **[10]**

```text
Sample Input
hi there
bye

Sample Output
Characters: 13
Words: 3
Lines: 2
```

**3.** Write a C program that prints the input with all single-line and block comments removed, deletes any blanks left at the end of a line by the removal, and prints `Unterminated comment` if a block comment is never closed. **[15]**

```text
Sample Input
a; // x
b; /* y */ c;

Sample Output
a;
b;  c;
```

**4.** Write a C program that reads one line and decides whether it is a valid C string literal, using a helper function that validates one escape sequence at a time. Print `Valid` or `Invalid: <reason>`, where the reason is `unterminated` or `illegal escape`. **[10]**

```text
Sample Input
"a\tb"
"a\9"

Sample Output
Valid
Invalid: illegal escape
```

---

## Set 14 — Literals, character sets and ranges

*Time: 90 minutes · Answer all six questions · 80 marks*

**1.** Write a flex program that reads the input line by line. For every line that contains the exact text `hello` anywhere in it, print `Match: ` followed by the whole line; for every other line print `No match`. **[10]**

```text
Sample Input
hello world
unit test
say hello again

Sample Output
Match: hello world
No match
Match: say hello again
```

**2.** Write a flex program that prints every line of the input with each lower-case vowel — `a`, `e`, `i`, `o`, `u` — replaced by a single `*`. Every other character, including `y` and all upper-case letters, must be printed unchanged. **[10]**

```text
Sample Input
hello world
rhythm
Out Of Office

Sample Output
h*ll* w*rld
rhythm
O*t Of Off*c*
```

**3.** Write a flex program that reads the whole input and prints, at the end, the number of upper-case letters and the number of lower-case letters in it, as `Upper: <n>` and `Lower: <n>`. Digits, punctuation, white space and newlines are not letters and must not be counted. **[10]**

```text
Sample Input
Regex and JavaScript

Sample Output
Upper: 3
Lower: 15
```

**4.** Write a flex program that prints, for every line of the input, the number of digit characters and the number of characters that are not digits, as `Digits: <n>` and `Non-digits: <n>`. Every character of the line counts, including spaces, but the newline at the end of the line does not. **[15]**

```text
Sample Input
a1b2c3 45
x

Sample Output
Digits: 5
Non-digits: 4
Digits: 0
Non-digits: 1
```

**5.** A password is accepted only when it contains at least one upper-case letter, at least one lower-case letter and at least one digit. Write a flex program that reads one password per line and prints `Valid` for an accepted password, or `Invalid: <reason>` otherwise, where the reason is `no uppercase`, `no lowercase` or `no digit`, checked in that order and only the first failing reason reported. **[15]**

```text
Sample Input
Abc123
abcdef
ABC123
Abcdefg

Sample Output
Valid
Invalid: no uppercase
Invalid: no lowercase
Invalid: no digit
```

**6.** Write a flex program that prints every word of the input that contains no vowel at all, using only the letters `a`, `e`, `i`, `o`, `u` as vowels, together with its length in the form `<word> (<length>)`, one per line. Words containing a vowel must produce no output. **[20]**

```text
Sample Input
rhythm hello sky try a

Sample Output
rhythm (6)
sky (3)
try (3)
```

---

## Set 15 — Matching an exact number of repetitions

*Time: 90 minutes · Answer all six questions · 85 marks*

**1.** Write a flex program that reads every run of digits in the input. A run of exactly three digits must be printed as `Three: <digits>`; every other run must be printed as `Other: <digits>`. **[10]**

```text
Sample Input
12 345 6789

Sample Output
Other: 12
Three: 345
Other: 6789
```

**2.** Write a flex program that prints `Four: <word>` for every word of the input that consists of exactly four letters, and prints nothing for other words. **[10]**

```text
Sample Input
this is a test of four

Sample Output
Four: this
Four: test
Four: four
```

**3.** Write a flex program that prints `Number: <digits>` for every run of two or more digits and prints nothing for a single digit. At the end print `Count: <n>` with the number of such runs. **[10]**

```text
Sample Input
7 42 3 100

Sample Output
Number: 42
Number: 100
Count: 2
```

**4.** Write a flex program that reads the input and replaces every run of two or more consecutive `a` characters by a single `a`, printing the resulting text, then printing `Runs: <n>` with the number of runs that were shortened. **[15]**

```text
Sample Input
baaaad a aa

Sample Output
bad a a
Runs: 2
```

**5.** Write a flex program that accepts a floating-point token only when it has a decimal point and at least two digits after that point. Print `Float: <token>` for an accepted token and `Invalid: <token>` for a token with a decimal point but fewer than two digits after it. Integer tokens without a decimal point must produce no output. **[15]**

```text
Sample Input
3.1 3.14 12.345 7

Sample Output
Invalid: 3.1
Float: 3.14
Float: 12.345
```

**6.** A date is written as four digits, a hyphen, two digits, a hyphen, two digits. Write a flex program that reads one date per line, printing `Valid date` when the format is right, the month is between 01 and 12 and the day is between 01 and 31, and `Invalid date: <reason>` otherwise, where the reason is `bad format`, `bad month` or `bad day`, checked in that order. **[25]**

```text
Sample Input
2026-11-03
2026-13-01
2026-1-3
2026-11-32

Sample Output
Valid date
Invalid date: bad month
Invalid date: bad format
Invalid date: bad day
```

---

## Set 16 — Anchors and the wildcard

*Time: 85 minutes · Answer all six questions · 80 marks*

**1.** Write a flex program that prints every line of the input that begins with the character `#`, in the form `Line <L>: <line>`, where `<L>` is the line number counted from 1. Other lines produce no output. **[10]**

```text
Sample Input
#include <stdio.h>
int main;
#define N 10

Sample Output
Line 1: #include <stdio.h>
Line 3: #define N 10
```

**2.** Write a flex program that prints every line of the input that ends with a semicolon, in the form `Line <L>: <line>`. A line whose last character before the newline is anything else must produce no output. **[10]**

```text
Sample Input
int a;
if (x)
{
b = 2;

Sample Output
Line 1: int a;
Line 4: b = 2;
```

**3.** Write a flex program that decides, for every line, whether the line contains the character `c`, then any single character other than a newline, and then the character `t`, in that order and with no other character between them. Print `FOUND: <line>` or `No match: <line>`. **[10]**

```text
Sample Input
cat
cot
ct
coat

Sample Output
FOUND: cat
FOUND: cot
No match: ct
No match: coat
```

**4.** Write a flex program that prints `Number: <L>` for every line that consists of an optional minus sign followed by one or more digits and nothing else, and `Not a number: <L>` for every other line. **[15]**

```text
Sample Input
42
-7
4x
 9

Sample Output
Number: 1
Number: 2
Not a number: 3
Not a number: 4
```

**5.** Write a flex program that prints `Line <L> has <n> characters` for every line of the input, where `<n>` counts every character of the line except the newline that ends it. An empty line has 0 characters and must still be reported. **[15]**

```text
Sample Input
abc

xy

Sample Output
Line 1 has 3 characters
Line 2 has 0 characters
Line 3 has 2 characters
```

**6.** Write a flex program that finds the longest line of the input and prints `Longest line: <L> (<n> characters)` at the end, where the newline is not counted. When two or more lines are equally longest, the first of them is reported. **[20]**

```text
Sample Input
abc
hello world
xy

Sample Output
Longest line: 2 (11 characters)
```

---

## Set 17 — Optional, star and plus

*Time: 85 minutes · Answer all six questions · 80 marks*

**1.** Write a flex program that prints `Match` for every line whose text contains a `g`, then zero or more `o` characters, then a `d`, and `No match` for every other line. **[10]**

```text
Sample Input
gd
god
good
gud

Sample Output
Match
Match
Match
No match
```

**2.** Write a flex program that reads all the integers in the input and prints their sum as `Sum: <n>` at the end. An integer is a run of one or more digits. **[10]**

```text
Sample Input
3 40 7

Sample Output
Sum: 50
```

**3.** Write a flex program that prints the input with every occurrence of `colour` or `color` replaced by `COLOR`, and then prints `Colours: <n>` with the number of replacements. Every other character must be printed unchanged. **[10]**

```text
Sample Input
the colour and the color

Sample Output
the COLOR and the COLOR
Colours: 2
```

**4.** A number token may begin with an optional minus sign, may have a fraction made of a decimal point followed by one or more digits, and may have an exponent made of `e` or `E`, an optional sign and one or more digits. Write a flex program that prints `Number: <token>` for a well-formed number, `Invalid: <token>` for a token that starts with a digit or a minus sign but is not well formed, and nothing for words. **[15]**

```text
Sample Input
-12 3.5 2e10 2e x

Sample Output
Number: -12
Number: 3.5
Number: 2e10
Invalid: 2e
```

**5.** Write a flex program that prints the input with every floating-point token reduced by deleting its trailing zeros, and deleting the decimal point when no digit is left after it. Integer tokens must be printed unchanged. **[15]**

```text
Sample Input
12.500 3.000 7.0 4

Sample Output
12.5 3 7 4
```

**6.** Write a flex program that replaces every comment of the form `/*` ... `*/` by the four characters `[C]`, where the comment ends at the first `*/` that follows its `/*` and may not extend past the end of its line, then prints `Comments removed: <n>`. Everything outside comments must be printed unchanged. **[20]**

```text
Sample Input
a /* x */ b /* y */ c

Sample Output
a [C] b [C] c
Comments removed: 2
```

---

## Set 18 — Alternation, grouping and escaping

*Time: 90 minutes · Answer all six questions · 85 marks*

**1.** Write a flex program that counts how many times the word `cat` and how many times the word `dog` occur in the input and prints `cat: <n>` and `dog: <n>` at the end. Whole words only count: `cats` and `dogs` must not be counted. **[10]**

```text
Sample Input
cat dog cat bird

Sample Output
cat: 2
dog: 1
```

**2.** Write a flex program that finds every run of the two characters `ab` repeated one or more times, prints the run and the number of repetitions as `<run>: <n>`, and prints nothing for a lone `a` or a lone `b`. **[10]**

```text
Sample Input
ababab x ab

Sample Output
ababab: 3
ab: 1
```

**3.** Write a flex program that prints `Dot` for every literal `.` character in the input and `Star` for every literal `*` character, one per line, in the order in which they appear. These characters must be treated as ordinary text and not as pattern operators. **[10]**

```text
Sample Input
file.txt data*

Sample Output
Dot
Star
```

**4.** A declaration is a type name, one or more spaces, and an identifier. Write a flex program that prints `Declared <type>: <name>` for every declaration whose type is `int`, `float` or `double`, and prints nothing for declarations of any other type. **[15]**

```text
Sample Input
int a; float b; char c;

Sample Output
Declared int: a
Declared float: b
```

**5.** A file name is made of letters, digits, underscores and dots, contains at least one dot, and ends with one or more letters after its last dot. Write a flex program that prints `File: <name>` and `Extension: <ext>` for every file name in the input, and `Invalid: <token>` for a token that looks like a file name but has no letters after its last dot. **[15]**

```text
Sample Input
report.final.pdf data. main.c

Sample Output
File: report.final.pdf
Extension: pdf
Invalid: data.
File: main.c
Extension: c
```

**6.** Write a flex program that finds every compound operator of the input — one of `+=`, `-=`, `*=`, `/=`, `==`, `!=`, `<=`, `>=`, `&&`, `||`, `++`, `--` — and prints each occurrence on its own line, in the order it appears, followed by `Total: <n>`. Single characters such as `+` on its own must not be printed. **[25]**

```text
Sample Input
a += b == c && d++ x != y

Sample Output
+=
==
&&
++
!=
Total: 5
```

---

## Set 19 — Capture groups and back-references

*Time: 90 minutes · Answer all six questions · 85 marks*

**1.** Write a flex program that reads lines of the form `left = right`, splits each line at the first `=` and prints two lines, `Left: <left>` and `Right: <right>`, with the spaces around the `=` removed and the rest of each side kept exactly. A line without `=` must print `No assignment`. **[10]**

```text
Sample Input
total = count + 1
just a line

Sample Output
Left: total
Right: count + 1
No assignment
```

**2.** Write a flex program that prints `Repeated: <word>` whenever the same word occurs twice in a row, separated only by white space, and prints nothing otherwise. Comparison is case sensitive. **[10]**

```text
Sample Input
the the cat sat sat down

Sample Output
Repeated: the
Repeated: sat
```

**3.** Write a flex program that prints `Repeated: <token>` whenever the same word or the same integer occurs twice in a row, ignoring the difference between upper-case and lower-case letters, and prints the two occurrences exactly as they were written. **[15]**

```text
Sample Input
The the cat Cat 12 12 7

Sample Output
Repeated: The the
Repeated: cat Cat
Repeated: 12 12
```

**4.** Write a flex program that prints every word of the input that has at least two letters, whose first letter and last letter are the same, ignoring case, in the form `<word> (<first letter>)`, where the letter is printed exactly as the word begins. **[15]**

```text
Sample Input
level cat stats x Radar

Sample Output
level (l)
stats (s)
Radar (R)
```

**5.** Write a flex program that prints every word of the input that reads the same forwards and backwards, ignoring case, with the words given in the order they appear and `Palindromes: <n>` printed at the end. **[15]**

```text
Sample Input
level madam noon cat Level

Sample Output
level
madam
noon
Level
Palindromes: 4
```

**6.** A date is written as two digits, a slash, two digits, a slash, four digits. Write a flex program that prints the same date in the form `YYYY-MM-DD` when the month is between 01 and 12 and the day is between 01 and 31, and `Invalid: <reason>` otherwise, where the reason is `bad format`, `bad month` or `bad day`, checked in that order. **[25]**

```text
Sample Input
03/11/2026
32/01/2026
3/11/2026

Sample Output
2026-11-03
Invalid: bad day
Invalid: bad format
```

---

## Set 20 — Word, non-word, space and non-space classes

*Time: 110 minutes · Answer all eight questions · 105 marks*

**1.** Write a flex program that prints every maximal run of letters, digits and underscores as `Word: <text>`, and then prints `Words: <n>`. Nothing else may be printed. **[10]**

```text
Sample Input
hi_there, ok

Sample Output
Word: hi_there
Word: ok
Words: 2
```

**2.** Write a flex program that prints `Punct: '<c>'` for every character of the input that is neither a letter, nor a digit, nor an underscore, nor a white-space character, one per line, in the order it appears. **[10]**

```text
Sample Input
hi, there!

Sample Output
Punct: ','
Punct: '!'
```

**3.** Write a flex program that counts the white-space characters of the input — spaces, tabs and newlines — and prints `Whitespace characters: <n>` at the end. **[10]**

```text
Sample Input
a  b c

Sample Output
Whitespace characters: 4
```

**4.** Write a flex program that prints `Three: <token>` for every token of exactly three characters that contains no white space, and prints nothing for tokens of any other length. **[10]**

```text
Sample Input
abc defg hi jkl

Sample Output
Three: abc
Three: jkl
```

**5.** Write a flex program that reads the whole input and prints three counts, in this order: `Word characters: <n>`, `Non-word characters: <n>` and `Whitespace characters: <n>`. Word characters are letters, digits and underscores; non-word characters are everything that is neither a word character nor white space; whitespace is spaces, tabs and newlines. **[15]**

```text
Sample Input
ab, c!

Sample Output
Word characters: 3
Non-word characters: 2
Whitespace characters: 2
```

**6.** Write a flex program that reads a line of comma-separated fields, removes every space from the beginning and the end of each field, and prints `Field <i>: <value>` for each one, numbered from 1. A field that is empty after trimming must be printed as `Field <i>:` with nothing after the colon and no trailing space. **[15]**

```text
Sample Input
 a , b c ,  d ,

Sample Output
Field 1: a
Field 2: b c
Field 3: d
Field 4:
```

**7.** Write a flex program that prints every token of the input that contains no white space and no punctuation, that is, every token made only of letters, digits and underscores, preceded by its position among the tokens of its own line, in the form `<line>.<position>: <token>`. Positions are counted from 1 on each line. **[20]**

```text
Sample Input
int a = 5;
b = a + 1;

Sample Output
1.1: int
1.2: a
1.4: 5
2.1: b
2.3: a
2.5: 1
```

**8.** Write a flex program that prints the input with every run of white space outside a string literal replaced by a single space, and with every trailing space at the end of a line removed. The contents of string literals must be left exactly as they are. **[20]**

```text
Sample Input
int   a  =  "x   y"  ;

Sample Output
int a = "x   y" ;
```

---

## Set 21 — The reference tables applied to C source

*Time: 90 minutes · Answer all six questions · 100 marks*

**1.** Write a flex program that reads a C source file and prints every preprocessor line as `Preprocessor: #include`, followed by the header name as `Header: stdio.h`. A `#include` line whose header is not of the form `<` letters, digits, underscores and dots `.h>` must print `Invalid header: <text>` instead of the header line. **[15]**

```text
Sample Input
#include <stdio.h>
#include <my_lib.h>
#include <stdio>

Sample Output
Preprocessor: #include
Header: stdio.h
Preprocessor: #include
Header: my_lib.h
Preprocessor: #include
Invalid header: <stdio>
```

**2.** Write a flex program that tokenises a C source file into the classes `KEYWORD`, `IDENTIFIER`, `NUMBER`, `OPERATOR` and `SPECIAL SYMBOL`, printing one line per token in the form `<token> --> <class>`. The keywords are `int`, `float`, `char`, `double`, `void`, `if`, `else`, `while`, `for` and `return`; the special symbols are `(`, `)`, `{`, `}`, `;` and `,`; every other punctuation character is an operator. White space and comments must produce no output. **[15]**

```text
Sample Input
int a = 10;
int sum = a + 20;

Sample Output
int --> KEYWORD
a --> IDENTIFIER
= --> OPERATOR
10 --> NUMBER
; --> SPECIAL SYMBOL
int --> KEYWORD
sum --> IDENTIFIER
= --> OPERATOR
a --> IDENTIFIER
+ --> OPERATOR
20 --> NUMBER
; --> SPECIAL SYMBOL
```

**3.** Write a flex program that prints every floating-point literal of a C source file as `FLOAT: <text>` — a run of digits, a decimal point and a run of digits — and every string literal as `STRING: <text>` including its quotes and escape sequences exactly as written. `printf` must be printed as `FUNCTION: printf`. **[15]**

```text
Sample Input
float x = 3.14;
printf("The result is: %f\n", x);

Sample Output
FLOAT: 3.14
FUNCTION: printf
STRING: "The result is: %f\n"
```

**4.** Write a flex program that reports every call of the function `printf` with the number of arguments in it, printing `printf with <n> argument(s)`, where the arguments are the comma-separated items between the parentheses of the call. No other token may produce output. **[15]**

```text
Sample Input
printf("a %d\n", x);
printf("hi");

Sample Output
printf with 2 argument(s)
printf with 1 argument(s)
```

**5.** Write a flex program that reads a C source file and prints exactly six lines at the end, in this order: `Keywords: <n>`, `Identifiers: <n>`, `Numbers: <n>`, `Operators: <n>`, `Special symbols: <n>`, `Strings: <n>`. Use the keyword list `int`, `float`, `char`, `double`, `void`, `if`, `else`, `while`, `for`, `return`, an identifier is a letter or underscore followed by letters, digits or underscores, and a number is a run of digits. **[20]**

```text
Sample Input
int a = 10;

Sample Output
Keywords: 1
Identifiers: 1
Numbers: 1
Operators: 1
Special symbols: 1
Strings: 0
```

**6.** Write a flex program that gives a full report on one C function body. For every token it must print `<token> --> <class>`, and at the end it must print `Tokens: <n>` and `Distinct identifiers: <n>`, where an identifier is counted once however often it appears. **[20]**

```text
Sample Input
int main() {
    int a = 10;
    int b = 20;
    int sum = a + b;
    return sum;
}

Sample Output
int --> KEYWORD
main --> IDENTIFIER
( --> SPECIAL SYMBOL
) --> SPECIAL SYMBOL
{ --> SPECIAL SYMBOL
int --> KEYWORD
a --> IDENTIFIER
= --> OPERATOR
10 --> NUMBER
; --> SPECIAL SYMBOL
int --> KEYWORD
b --> IDENTIFIER
= --> OPERATOR
20 --> NUMBER
; --> SPECIAL SYMBOL
int --> KEYWORD
sum --> IDENTIFIER
= --> OPERATOR
a --> IDENTIFIER
+ --> OPERATOR
b --> IDENTIFIER
; --> SPECIAL SYMBOL
return --> KEYWORD
sum --> IDENTIFIER
; --> SPECIAL SYMBOL
} --> SPECIAL SYMBOL
Tokens: 26
Distinct identifiers: 4
```

---

## Coverage map — where every rule of the reference sheet is examined

The reference sheet lists twenty-two rules. Each one is examined at least twice, and the two worked token tables at the end of the sheet are examined as Set 21. Questions marked *easy* are short bookkeeping; the later questions in a set are the ones that need a design decision.

| # | Rule | Examined in | Count |
|---|---|---|---|
| 1 | Literal string | 14.1, 17.3, 18.3 | 3 |
| 2 | Character set `[set]` | 14.2, 14.5, 18.3 | 3 |
| 3 | Character range `[a-z]` | 14.3, 14.5, 18.5 | 3 |
| 4 | Negated set `[^abc]` | 14.4, 14.6, 20.2 | 3 |
| 5 | Exactly *n* times `{n}` | 15.1, 15.2, 15.6 | 3 |
| 6 | At least *n* times `{n,}` | 15.3, 15.5, 15.6 | 3 |
| 7 | Range of times `{n,m}` | 15.4, 15.6, 21.1 | 3 |
| 8 | Start of line `^` | 16.1, 16.4, 20.8 | 3 |
| 9 | End of line `$` | 16.2, 16.4, 20.8 | 3 |
| 10 | Any character `.` | 16.3, 16.5, 16.6 | 3 |
| 11 | Zero or more `*` | 17.1, 17.5, 19.1 | 3 |
| 12 | One or more `+` | 17.2, 17.4, 18.2 | 3 |
| 13 | Optional `?` | 17.3, 17.4, 16.4 | 3 |
| 14 | Alternation `\|` | 18.1, 18.4, 18.6 | 3 |
| 15 | Escape `\` | 18.3, 18.5, 18.6 | 3 |
| 16 | Grouping `( )` | 18.2, 19.1, 19.6 | 3 |
| 17 | Named capture group | 19.1, 19.6, 21.4 | 3 |
| 18 | Back-reference `\1` | 19.2, 19.3, 19.4, 19.5 | 4 |
| 19 | Word character `\w` | 20.1, 20.5, 20.7 | 3 |
| 20 | Non-word character `\W` | 20.2, 20.5, 20.6 | 3 |
| 21 | Whitespace `\s` | 20.3, 20.5, 20.8 | 3 |
| 22 | Non-whitespace `\S` | 20.4, 20.6, 20.8 | 3 |
| — | Example One — token table for a C program | 21.1, 21.2, 21.5, 21.6 | 4 |
| — | Example Two — floats, strings and `printf` | 21.3, 21.4, 21.6 | 3 |

### Difficulty spread and suggested routes

Every set starts with 10-mark questions and ends with 15- to 25-mark ones, so an easy question, a medium question and a hard question on each rule are always in the same place.

- **Easy only (about 25 minutes):** 14.1, 14.2, 14.3, 15.1, 15.2, 16.1, 16.2, 16.3, 17.1, 17.2, 17.3, 18.1, 18.2, 18.3, 19.1, 20.1, 20.2, 20.3, 20.4.
- **Medium (about an hour):** 14.4, 14.5, 15.3, 15.5, 16.4, 16.5, 17.4, 17.5, 18.4, 18.5, 19.3, 19.4, 20.5, 20.6, 21.1, 21.2.
- **Hard (one sitting each):** 14.6, 15.6, 16.6, 17.6, 18.6, 19.5, 19.6, 20.7, 20.8, 21.6.
- **Full mock paper:** Set 21 straight through, then 15.6 and 19.6 with it.

### A note on the way these rules are worded

flex supports `*`, `+`, `?`, `[...]`, `[^...]`, alternation, grouping, `^`, `$` and escaped literals directly. It does **not** support counted repetition `{n,m}`, named capture groups or back-references. Sets 15, 19 and parts of 21 therefore describe the matching *behaviour* rather than a pattern to type: you either write the pattern out in full — `[0-9][0-9][0-9]` for exactly three digits — or keep the state yourself in `yytext` and compare words as you go. Choosing which of the two to do is part of the question, and full marks need the choice justified only by the program working on the samples.
